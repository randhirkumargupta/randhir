<?php
/**
 * Inc file contains the functions
 */

/**
 * main function for generate videoCategoryPage array
 *
 * @return array
 */


function videocategoryPageRerourceValue($tid = 0, $pageno = 0) {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();      
    $updated_datetime = "";
    
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;  
    if(!$tid){
        $term_name = "Latest";
    }
    
    // list array building
    $data = generateVideoCategoryList($tid, $pageno);
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    
    //data array building
    
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "0";
    //$data_array['subcategory_id'] = "$tid";
    //$data_array['subcategory_title'] = "$term_name";
    $data_array['video_count'] = "$datacount";
    $data_array['video_display_count'] = "10";
    $data_array['video_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";
    
    $data_array['video'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for generate videoCategoryPage list
 *
 * @return array
 */
function generateVideoCategoryList($tid, $pageno) {
  // variable declaration
  global $base_url;  
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = "videogallery";
  $photo_list_array = array();
  $loop_count = 0;


{
    $listcount = 0;


    // select node belong from current term id or child term id

    $query = db_select('taxonomy_index', 'ti');
    $query->leftJoin('node', 'n', 'n.nid=ti.nid');
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_upload', 'fvu', 'fvu.entity_id=n.nid');
    //field_data_field_primary_category
    $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fss', array('field_story_syndication_value'));
    $query->fields('fsr', array('field_story_reporter_target_id'));
    $query->fields('fvu', array('field_video_upload_value'));
    $query->fields('fpc', array('field_primary_category_value'));


    //end
    
    if($tid > 0){
        $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {

      // node feed tag
      
      
      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $changed = $resvalue['changed'];
      $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
      $field_primary_category_value = $resvalue['field_primary_category_value'];
      $term = taxonomy_term_load($tid);
      $term_name = $term->name;
      //$weburl = $base_url . "/node/" . $nid;
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      $field_video_duration_value = $resvalue['field_video_duration_value'];
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
      
      $field_story_reporter_target_id = $resvalue['field_story_reporter_target_id'];
      $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
      //video url start
      $field_video_upload = $resvalue['field_video_upload_value'];
      $file_id = file_usage($field_video_upload);
      //to get the video of all the other formats
      $video_formats = all_video_format($file_id);
      $video_path_info = videoCheckExistFile($file_id, $nid, $field_video_upload);
      $video_path_mp4 = $video_path_info['video_path_mp4'];
      $filesize = $video_path_info['filesize'];
      $stream_h264_hd_url = $video_formats['stream_h264_hd_url'];
      //video url end

      // create date formating
      $firebase_url = get_node_firebase_weburl($nid);
      //$create_date = date("F d, Y", $created);
      //$create_datetime = date("Y-m-d H:i:s", $created);
      //$changed_datetime = date("Y-m-d H:i:s", $changed);
      if($created){
        $create_datetime = date("Y-m-d H:i:s", $created);
        $create_date = date("Y-m-d H:i:s", $created);
      }
      else{
          $create_datetime = "";
          $create_date = "";
      }
      if($changed){
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else{
          $changed_datetime = "";
      }
      
        $photo_list_array[$listcount]['v_id'] = "$nid";
        $photo_list_array[$listcount]['v_title'] = "$title";
        $photo_list_array[$listcount]['v_credit'] = "$reporter_node";
        $photo_list_array[$listcount]['v_byline'] = "$reporter_node";
        $photo_list_array[$listcount]['v_short_desc'] = "$field_story_kicker_text_value";
        $photo_list_array[$listcount]['v_small_image'] = "$file_small_img_url";
        $photo_list_array[$listcount]['v_large_image'] = "$file_medium_img_url";
        $photo_list_array[$listcount]['v_is_default_player'] = "0";
        $photo_list_array[$listcount]['v_url'] = "$stream_h264_hd_url";
        $photo_list_array[$listcount]['v_download_url'] = "$video_path_mp4";
        $photo_list_array[$listcount]['v_view_count'] = "0";
        $photo_list_array[$listcount]['v_comment_count'] = "10";
        $photo_list_array[$listcount]['v_share_url'] = "$firebase_url";
        $photo_list_array[$listcount]['v_updated_datetime'] = "$changed_datetime";
        $photo_list_array[$listcount]['v_duration'] = "$field_video_duration_value";
        $photo_list_array[$listcount]['v_show_ad'] = "0";
        $photo_list_array[$listcount]['v_video_size'] = "300";
        $photo_list_array[$listcount]['v_subcategory_id'] = "$field_primary_category_value";
        $photo_list_array[$listcount]['v_subcategory_title'] = "$term_name";
        
        $listcount++;
    }
  }
  
  
  
  $data['lcount'] = $listcount;
  $data['data'] = $photo_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}


/**
 * main function for generate programCategoryPage array
 *
 * @return array
 */


function programcategoryPageRerourceValue($tid = 0, $pageno = 0) {
    
  
    // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();      
    $updated_datetime = "";
    
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;   
    if(!$tid){
        $term_name = "Latest";
    }
    
    // list array building
    $data = generateProgramCategoryList($tid, $pageno);
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
 else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    
    //data array building
    
    $data_array['id'] = "$tid";
    $data_array['title'] = "$term_name";
    $data_array['layout_id'] = "0";
    $data_array['subcategory_id'] = "$tid";
    $data_array['subcategory_title'] = "$term_name";
    $data_array['program_count'] = "$datacount";
    $data_array['program_display_count'] = "10";
    $data_array['program_pagination_cap'] = "7";
    $data_array['updated_datetime'] = "$data_up_time";
    
    $data_array['program'] = $data['data'];
    $output_array['data'] = $data_array;
    
    return $output_array;
}


/**
 * function for  generateProgramCategoryList list
 *
 * @return array
 */
function generateProgramCategoryList($tid, $pageno) {
  // variable declaration
  global $base_url;  
  $node_count = "";
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  $term = taxonomy_term_load($tid);
  $term_name = $term->name; 
  if(!$pageno == 0){
      $range_min = $pageno * $range_max;
  }
  else{
    $range_min = 0;
  }
  $order_by = 'ASC';
  $type = "videogallery";
  $photo_list_array = array();
  $loop_count = 0;


{
    $listcount = 0;


    // select node belong from current term id or child term id

    $query = db_select('taxonomy_index', 'ti');
    $query->leftJoin('node', 'n', 'n.nid=ti.nid');
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->leftJoin('field_data_field_video_upload', 'fvu', 'fvu.entity_id=n.nid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_syndication', 'fss', 'fss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_reporter', 'fsr', 'fsr.entity_id=n.nid');

    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));

    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fss', array('field_story_syndication_value'));
    $query->fields('fsr', array('field_story_reporter_target_id'));
    $query->fields('fvu', array('field_video_upload_value'));


    //end
    
    if($tid > 0){
        $query->condition('ti.tid', $tid_list, 'IN');
    }
    $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {

      // node feed tag
      
      
      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $changed = $resvalue['changed'];
      $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
      //$weburl = $base_url . "/node/" . $nid;
      $alias = drupal_get_path_alias('node/'.$nid.'');
      $weburl = $base_url ."/". $alias;
      $field_video_duration_value = $resvalue['field_video_duration_value'];
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
      $field_story_reporter_target_id = $resvalue['field_story_reporter_target_id'];
      $reporter_node = itg_common_get_node_title($field_story_reporter_target_id);
      //video url start
      $field_video_upload = $resvalue['field_video_upload_value'];
      $file_id = file_usage($field_video_upload);
      //to get the video of all the other formats
      $video_formats = all_video_format($file_id);
      $video_path_info = videoCheckExistFile($file_id, $nid, $field_video_upload);
      $video_path_mp4 = $video_path_info['video_path_mp4'];
      $filesize = $video_path_info['filesize'];
      $stream_h264_hd_url = $video_formats['stream_h264_hd_url'];
      //video url end

      // create date formating
      $firebase_url = get_node_firebase_weburl($nid);
      //$create_date = date("Y-m-d H:i:s", $created);
      //$create_datetime = date("Y-m-d H:i:s", $created);
      //$changed_datetime = date("Y-m-d H:i:s", $changed);
      
      if($created){
        $create_datetime = date("Y-m-d H:i:s", $created);
        $create_date = date("Y-m-d H:i:s", $created);
      }
      else{
          $create_datetime = "";
          $create_date = "";
      }
      if($changed){
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else{
          $changed_datetime = "";
      }
      
        $photo_list_array[$listcount]['p_id'] = "$nid";
        $photo_list_array[$listcount]['p_title'] = "$title";
        $photo_list_array[$listcount]['p_credit'] = "$reporter_node";
        $photo_list_array[$listcount]['p_byline'] = "$reporter_node";
        $photo_list_array[$listcount]['p_short_desc'] = "$field_story_kicker_text_value";
        $photo_list_array[$listcount]['p_small_image'] = "$file_small_img_url";
        $photo_list_array[$listcount]['p_large_image'] = "$file_medium_img_url";
        $photo_list_array[$listcount]['p_is_default_player'] = "1";
        $photo_list_array[$listcount]['p_url'] = "$stream_h264_hd_url";
        $photo_list_array[$listcount]['p_download_url'] = "$video_path_mp4";
        $photo_list_array[$listcount]['p_view_count'] = "0";
        $photo_list_array[$listcount]['p_comment_count'] = "10";
        $photo_list_array[$listcount]['p_share_url'] = "$firebase_url";
        $photo_list_array[$listcount]['p_updated_datetime'] = "$changed_datetime";
        $photo_list_array[$listcount]['p_duration'] = "$field_video_duration_value";
        $photo_list_array[$listcount]['p_show_ad'] = "0";
        $photo_list_array[$listcount]['p_subcategory_id'] = "$tid";
        $photo_list_array[$listcount]['p_subcategory_title'] = "$term_name";
        $photo_list_array[$listcount]['p_program_size'] = "$filesize";
        $photo_list_array[$listcount]['p_anchor_id'] = "1";
        
        $listcount++;
    }
  }
  
  
  
  $data['lcount'] = $listcount;
  $data['data'] = $photo_list_array;
  $data['updated_datetime'] = $changed_datetime;
  
  
  return $data;
}


/**
 * function for  programCategoryListlPageRerourceValue 
 *
 * @return array
 */

function programCategoryListlPageRerourceValue($token) {
    
     
     // variable decalartion
    
    $output_array = array();
    $data_array = array();
    $program_list_array = array();      
    $updated_datetime = "";
    $conf_array = tidConfig(); 
    $Program_section_list = $conf_array['program_sec_tid'];
    
    // list array building
    $data = generateProgramSectionList($Program_section_list);
    if($data['lcount'] > 0){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
    else {
           $output_array['status_code'] = "0";
           $output_array['status_message'] = "customised_message";  
    }
    
    $datacount = $data['lcount'];
    $data_up_time = $data['updated_datetime'];
    //$changed_datetime = date("Y-m-d H:i:s", $data_up_time);
    if($data_up_time){
        $changed_datetime = date("Y-m-d H:i:s", $data_up_time);
      }
      else{
          $changed_datetime = "";
      }
    
    //data array building
    $output_array['data']['updated_datetime'] = $changed_datetime;
    $output_array['data']['program'] = $data['data'];
    
    return $output_array;
   
}

/**
 * function for  generateProgramSectionList 
 *
 * @return array
 */


function generateProgramSectionList($Program_section_list){
    //echo "<pre>"; print_r($Program_section_list);echo "</pre>";exit();
    $data = array();
    $output_ar = array();
    $listcount = 0;
    foreach ($Program_section_list as $key => $value){
        $term = taxonomy_term_load($value);
        //echo "<pre>"; print_r($term); echo "</pre>";exit();
        $update_time = getLatestNodeTime($term->tid);
        $term_name = $term->name;
        $term_url = nodeCategoryFrontUrl($value, 'term');
        $child_term_url = nodeCategoryFrontUrl($value, 'term');
        $p_short_description = $term->description;
        $p_schedule = $term->field_program_timing_in_days['und'][0]['value'];

        $term_name = drupal_strtolower(str_replace(" ", "-", $term_name));
        $term_name = drupal_strtolower(str_replace("&", "and", $term_name));
        $cat_icon_img = sectionCategoryIconImg($value);
        
        $data[$listcount]['p_id'] = "$value";
        $data[$listcount]['p_title'] = "$term->name";
        $data[$listcount]['p_image'] = "$cat_icon_img";
        $data[$listcount]['p_type'] = "programlist";
        $data[$listcount]['p_short_description'] = "$p_short_description";
        $data[$listcount]['p_schedule'] = "$p_schedule";
        $listcount++; 
    }
    
    $output_ar['data'] = $data;
    $output_ar['lcount'] = $listcount;
    $output_ar['updated_datetime'] = $update_time;
    
    return $output_ar;
}

function getLatestNodeTime($tid){
    
    $query = db_select('taxonomy_index', 'txi');
    $query->fields('txi', array('created'));
    $query->condition('txi.tid', $tid);   
    $query->orderBy('txi.created', 'DESC');
    $query->range(0, 1);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $published_statp = $result[0]['created'];
    return $published_statp;
}