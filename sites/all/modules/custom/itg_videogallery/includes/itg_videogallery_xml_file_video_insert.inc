<?php
/**
 * Implements function for insert video from xml
 * @return array
 */
/**
 * Call back function for video insert API
 * @pram $_POST in XML formate
 *
 * @return array - The processed information array.
 */
function itg_videogallery_xml_file_video_insert($data) {
    //$data = file_get_contents('php://input');
//    $xml_data = simplexml_load_string($data);
    $xml_data = $data;
    $xml_resp = "<?xml version='1.0' encoding='utf-8'?><Root> ";
    foreach ($xml_data->article as $xml) {
        $long_headline = $xml->long_headline;
        $short_headline = $xml->short_headline;
        $description = $xml->description;
        $anchor = (int) $xml->anchor;
        $video_kicker = $xml->video_kicker;
        $section_id = (int) $xml->section_id;
        $cat_id = (int) $xml->cat_id;
        $extra_large_img = $xml->extra_large_img;
        $large_img = $xml->large_img;
        $medium_img = $xml->medium_img;
        $small_img = $xml->small_img;
        $extra_small_img = $xml->extra_small_img;
        $video_file_name = $xml->video_file_name;
        //prepare node object
        $node = new stdClass();
        $node->title = trim(html_entity_decode($long_headline));
        $node->type = "videogallery";
        node_object_prepare($node);
        $node->language = LANGUAGE_NONE;
        $node->uid = 1522; //itgsiteadmin
        $node->promote = 0;
        $node->comment = 0;
        $node->status = 0;
        if (!empty($description)){
          $node->body[$node->language][0]['value'] = $description; 
          $node->body[$node->language][0]['format'] = 'full_html';
        }
       
        //$node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($long_headline));                    
        if (!empty($short_headline)) {
          $node->field_story_short_headline[LANGUAGE_NONE][0]['value'] = trim(html_entity_decode($short_headline)); 
        }

        $node->field_story_source_type[LANGUAGE_NONE][0]['value'] = 'videogallery';
        if (!empty($cat_id)) {
            $node->field_story_category[LANGUAGE_NONE][0]['tid'] = $cat_id;
        }
        if (!empty($section_id)) {
          $node->field_primary_category[LANGUAGE_NONE][0]['value'] = $section_id;
        }
        if (!empty($anchor)) {
          $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'] = trim($anchor); 
        }
        $node->field_story_expert_description[LANGUAGE_NONE][0]['value'] = empty($video_kicker) ? '' : $video_kicker;
        $node->field_video_file_name[LANGUAGE_NONE][0]['value'] = $video_file_name;

        $node = node_submit($node); // Prepare node for saving
        $node->created = $publish_date_timestamp;
        if (!empty($extra_large_img)) {
          $fid_extra_large_image = itg_videogallery_rap_upload_img($extra_large_img);
          $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid_extra_large_image; 
        }
        if (!empty($large_img)) {
          $fid_large_img = itg_videogallery_rap_upload_img($large_img);
          $node->field_story_large_image[LANGUAGE_NONE][0]['fid'] = $fid_large_img;
        }
        if (!empty($medium_img)) {
          $fid_medium_img = itg_videogallery_rap_upload_img($medium_img);
          $node->field_story_medium_image[LANGUAGE_NONE][0]['fid'] = $fid_medium_img;
        }
        if (!empty($small_img)) {
          $fid_small_img = itg_videogallery_rap_upload_img($small_img);
          $node->field_story_small_image[LANGUAGE_NONE][0]['fid'] = $fid_small_img;
        }
        if (!empty($extra_small_img)) {
          $fid_extra_small_img = itg_videogallery_rap_upload_img($extra_small_img);
          $node->field_story_extra_small_image[LANGUAGE_NONE][0]['fid'] = $fid_extra_small_img;
        }
        $node->field_transcode_flag[LANGUAGE_NONE][0]['value'] = 1;
        try {
            node_save((object) $node);
            $success = TRUE;
        } catch (Exception $e) {           
            $success = FALSE;
        }
        if ($success) {
            $data['status_code'] = "1";
            $data['status_message'] = "";
            $xml_resp .= "<item>";
            $xml_resp .= "<sucess_code>1</sucess_code>";
            $xml_resp .= "<video_file_name>".$video_file_name."</video_file_name>";
            $xml_resp .= "</item>";
        }
        else{
            $data['status_code'] = "1";
            $data['status_message'] = "";
            $xml_resp .= "<item>";
            $xml_resp .= "<sucess_code>0</sucess_code>";
            $xml_resp .= "<video_file_name>".$video_file_name."</video_file_name>";
            $xml_resp .= "</item>";
        }
    }
    $xml_resp .= "</Root> ";
    print $xml_resp;
    drupal_exit();
}
/**
 * itg_videogallery_rap_upload_img
 * @param type $url
 * @return type
 */

function itg_videogallery_rap_upload_img($url){
    $fid = 0;
    if($url){
        $extra_large_image_url = file_get_contents($url);
        $extra_large_image = base64_encode($extra_large_image_url);
        $fid = $fid_extra_large_image = uplodaProfileImg_Rapid($extra_large_image);
    }
    return $fid;
}

function itg_anchor_associate_video_cron(){
  $query = db_select('field_data_field_transcode_flag', 'ftf');
  $query->join('field_data_field_video_file_name', 'fvfn', 'fvfn.entity_id=ftf.entity_id');
  $query->fields('fvfn', array('field_video_file_name_value', 'entity_id'));
  $query->condition('ftf.field_transcode_flag_value', 1, '=');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $value) {
    associate_video_to_node($value->field_video_file_name_value, $value->entity_id);
  }
}

function associate_video_to_node($filename, $nid){
  if (!empty($filename)) {
    $video_info_arr = get_video_info($filename);
    if ($video_info_arr) {
      $video_fid = itg_associate_video_id_to_pcontent($video_info_arr);
      if (!empty($video_fid)) {
        $node = node_load($nid);
        $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_video_upload'));
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->field_videogallery_video_upload[LANGUAGE_NONE][0]['fid'] = $video_fid;
        $field_collection_item->field_videogallery_video_upload[LANGUAGE_NONE][0]['display'] = 1;
        $field_collection_item->save();
        db_update('node') // Table name no longer needs {}
          ->fields(array(
            'status' => 1
          ))
          ->condition('nid', $node->nid, '=')
          ->execute();
        db_update('workbench_moderation_node_history') // Table name no longer needs {}
          ->fields(array(
            'state' => workbench_moderation_state_published(),
            'published' => 1,
            'uid' => ADMINISTRATOR,
          ))
          ->condition('nid', $node->nid, '=')
          ->condition('is_current', 1, '=')
          ->execute(); 
      }
    }
  }
  return FALSE;
}

function itg_associate_video_id_to_pcontent($video_info_arr){
  if(empty($video_info) || count($video_info) == 0){
    return FALSE;
  }  
  $video_info = $video_info[0];  
  $videourl = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . rand(111,9999) . '/' . time() . '/' . $video_info->video_id . '.mp4';

  $fid = db_insert('file_managed')
      ->fields(array(
        'uid' => 1522, //itgsiteadmin,
        'filename' => $video_info->name,
        'uri' => $videourl,
        'filemime' => 'video/mp4',
        'filesize' => $video_info->video_size,
        'status' => 1,
        'timestamp' => REQUEST_TIME,
      ))
      ->execute();
  $file = file_load($fid);
//  var_dump($file);die;
  if (empty($file->fid)){
    return FALSE;
  }
  file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
  $is_used = 0;

  if (FALSE && isset($video_info->video_type) && !empty($video_info->video_type)) {
    $is_used = 1;
  }
  if($video_info->video_type == "") {
    $video_info->video_type = 'DM';
  }
  $fid = db_insert('itg_solr_video_info')
      ->fields(array(
        'fid' => $file->fid,
        'solr_video_id' => $video_info->video_id,
        'solr_video_duration' => $video_info->video_duration,
        'solr_video_size' => $video_info->video_size,
        'property' => 'PROD',
        'content_type' => 'video_gallery',
        'video_repo_type' => $video_info->video_type,
        'video_xml_data' => $video_info->field_all_xml_content_value,
        'is_alredy_used' => $is_used,
        'solr_video_thumb' => '',
      ))
      ->execute();
  return $file->fid;
}

function itg_get_video_info($filename){
  if (!empty($filename)) {
    $query = db_select('dailymotion_response_details', 'drd');
    $query->leftJoin('field_data_field_video_id', 'fdfvi', 'fdfvi.field_video_id_value = drd.video_id');
    $query->leftJoin('field_data_field_all_xml_content', 'faxc', 'faxc.entity_id = fdfvi.entity_id');
    $query->condition('drd.title', $filename, '=');
    $query->condition('drd.dailymotion_published', 0, '=');
    $query->fields('drd');
    $query->fields('faxc', array('field_all_xml_content_value'));
    $video_data = $query->execute()->fetchAll();
    return $video_data;
  }
  return FALSE;
}