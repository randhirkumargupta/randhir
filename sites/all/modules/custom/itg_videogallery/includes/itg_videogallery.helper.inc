<?php
/**
 * Implements function for validate image
 * @param array $field
 * @return array
 */
function itg_custom_field_validate($field) {
  $val = itg_video_check_exist_file($field->filename);
  $field->destination = $val;
  $errors = array();
  return $errors;
}

/**
 * This function use for if file exist or not in file_manage
 * * Implements function for validate image
 * @param int $fid
 * @return array
 */
function itg_videogallery_check_file_manage_fid($fid) {
  $query = db_select('file_managed', 'fm');
  $query->fields('fm');
  $query->condition('fid', $fid, '=');
  $results = $query->execute()->fetchAll();
  return $results;
}

/**
 * Implements function check exist filename
 * @param array $form
 * @param array $form_state
 * @return string
 */
function itg_video_check_exist_file($filename) {
  $query = db_select('file_managed', 'fm');
  $query->condition('filename', $filename, '=');
  $query->fields('fm');
  $query->orderBy('fm.fid', 'DESC');
  $query->range(0, 1);
  $results = $query->execute()->fetchAll();
  if (!isset($results[0])) {
    $res = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . $filename;
    return $res;
  }
  else {
    $result = explode('public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/', $results[0]->uri);
    $path_info = pathinfo($results[0]->filename);
    $extension = $path_info['extension'];
    $file_name = $path_info['filename'];
    $result_num = explode($file_name . '_', $result[1]);
    $num_file_id = explode('.' . $extension, $result_num[1]);
    if (is_numeric($num_file_id[0]) && isset($num_file_id[0])) {
      $value = $num_file_id[0] + 1;
      $value = '_' . $value;
    }
    else {
      $value = '_0';
    }
    $file_info = pathinfo($filename);
    $res = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . $file_info['filename'] . $value . '.' . $extension;
    return $res;
  }
}

/**
 * This function use for mark node remove video unpublish
 */
function itg_videogallery_node_publish_to_unpublish($nid) {
  $unp_videos = array();
// delete deleted video info form itg_solr_video_info
  $query = db_select('itg_solr_video_info', 'drd')
      ->fields('drd', array('solr_video_id', 'property', 'fid' , 'video_repo_type'));
  $query->condition('nid', $nid);
  $result = $query->execute()->fetchAll();

  $query = db_delete('itg_solr_video_info');
  $query->condition('nid', $nid);
  $query->condition('content_type', 'video_gallery', '=');
  $query->execute();
  $node = node_load($nid);
  foreach ($node->field_video_upload[LANGUAGE_NONE] as $key => $value) {
    // Build array of field collection values.
    $field_collection_item_values[] = $value['value'];
    // Unset them.  
    unset($node->field_video_upload[LANGUAGE_NONE][$key]);
  }
  entity_delete_multiple('field_collection_item', $field_collection_item_values);
  field_attach_update('node', $node);

  foreach ($result as $un_video) {
    if ($un_video->property == VIDEO_PROPERTY && $un_video->video_repo_type != 'INTERNAL') {
      $api = itg_videogallery_dailymotion_api();
      $api->post('/video/' . $un_video->solr_video_id . '?private=true');
    }
    $unp_videos[] = $un_video->solr_video_id;

    $deleted = db_delete('file_managed')
        ->condition('fid', $un_video->fid)
        ->execute();
  }
  if (!empty($unp_videos)) {

    try {
      db_update('dailymotion_response_details') // Table name no longer needs {}
          ->fields(array(
            'dailymotion_published' => 0,
            'is_draft' => 0,
            'is_replace' => 1,
            'nid' => 0,
          ))
          ->condition('video_id', $unp_videos, 'IN')
          ->execute();
    }
    catch (Exception $e) {
      watchdog_exception('video fid delete', $e);
    }
  }
  foreach ($result as $un_video) {
    if ($un_video->property == VIDEO_PROPERTY) {
      itg_videogallery_update_video_info_solr($un_video->solr_video_id);
    }
  }
}

/**
 * This function use for mark node remove video unpublish
 */
function itg_videogallery_node_publish_video_to_unpublish($nid, $main_fids) {
  $unp_videos = array();
// delete deleted video info form itg_solr_video_info
  $query = db_update('itg_solr_video_info')
      ->fields(array('is_delete' => 1));
  $query->condition('fid', $main_fids, 'NOT IN');
  $query->condition('nid', $nid);
  $query->condition('content_type', 'video_gallery', '=');
  $query->execute();
  $query = db_select('itg_solr_video_info', 'drd')
      ->fields('drd', array('solr_video_id', 'property'));
  $query->condition('fid', $main_fids, 'NOT IN');
  $query->condition('nid', $nid);
  $result = $query->execute()->fetchAll();

  foreach ($result as $un_video) {
    if ($un_video->property == VIDEO_PROPERTY) {
      $api = itg_videogallery_dailymotion_api();
      $api->post('/video/' . $un_video->solr_video_id . '?private=true');
    }
    $unp_videos[] = $un_video->solr_video_id;
  }
  if (!empty($unp_videos)) {

    try {
      db_update('dailymotion_response_details') // Table name no longer needs {}
          ->fields(array(
            'dailymotion_published' => 0,
            'is_replace' => 1,
          ))
          ->condition('video_id', $unp_videos, 'IN')
          ->execute();
    }
    catch (Exception $e) {
      watchdog_exception('video fid delete', $e);
    }
  }
  foreach ($result as $un_video) {
    if ($un_video->property == VIDEO_PROPERTY) {
      itg_videogallery_update_video_info_solr($un_video->solr_video_id);
    }
  }
}

/**
 * This function use for upadet node id in itg_solr_video_info table after by fid when node is update and insert
 */
function itg_videogallery_update_node_id_for_video_fid($node_id, $fids, $is_node_draft) {
  $num_updated = db_update('itg_solr_video_info') // Table name no longer needs {}
      ->fields(array(
        'nid' => $node_id,
        'is_node_draft' => $is_node_draft,
      ))
      ->condition('fid', $fids, '=')
      ->execute();
}

/**
 * Get Primary category Tid using nid without node load
 * @param int $nid
 * @return int
 */
function get_tid_using_nid_custom($nid) {
  if (isset($nid)) {
    $query = db_select('field_data_field_primary_category', 'ttd');
    $query->fields('ttd', array('field_primary_category_value'));
    $query->condition('ttd.entity_id', $nid, '=');
    $result = $query->execute()->fetchField();
    return $result;
  }
  return 0;
}

/**
 * function for video assign to widget
 * @param $nid
 * @param array $video_widget
 * @param $cat_id
 * @param $previous_video_assign
 */
function itg_video_assign_to_widget($nid, array $video_widget, $cat_id, $previous_video_assign) {
  if (!empty($video_widget) && count($video_widget)) {
    $result = array();
    foreach ($video_widget as $widget_name) {
      if (!empty($widget_name) && $widget_name != '_none') {
        $result[$widget_name] = $widget_name;
        $is_node_in_widget = itg_widget_check_node_in_widget($nid, $widget_name);
        if (!$is_node_in_widget) {
          itg_widget_insert_widget_data($nid, $widget_name, 0);
        }
      }
    }
    itg_widget_delete_old_data_by_limit($widget_name);
    foreach ($previous_video_assign as $row) {
      $widget_value = $row['value'];
      if ($widget_value != $result[$row['value']]) {
        if (!empty($widget_value)) {
          itg_widget_delete_data_from_widget($widget_value, $nid);
        }
      }
    }
  }
}

/**
 * Function to show Other video gallery from node primary category
 * @return array or empty
 */
function _get_other_videos_from_primary_category() {
  if (arg(0) == 'node' && is_numeric(arg(1)) && !arg(2)) {
    $tid = get_tid_using_nid_custom(arg(1));
    return views_embed_view('video_list_of_category', 'block_4', $tid);
  }
  else {
    return '';
  }
}

/**
 * This function check video id insert in solr video content
 */
function itg_videogallery_get_video_solrcontent($video_id = NULL) {

  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->Join('field_data_field_video_id', 'fvd', 'n.nid = fvd.entity_id');
  $query->condition('fvd.field_video_id_value', $video_id, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * This function check video id insert in solr video content
 */
function itg_videogallery_get_node_by_title($title = NULL) {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('title', $title, '=');
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Implements function for dailymotion api
 * @return object
 */
function itg_videogallery_dailymotion_api() {
  require_once 'Dailymotion.php';
  $user_name = variable_get('dailymotion_username', '');
  $password = variable_get('dailymotion_password', '');
  $api_key = variable_get('dailymotion_apikey', '');
  $api_secret = variable_get('dailymotion_secretkey', '');

  try {
    $api = new Dailymotion();
    $scopes = array(
      'userinfo',
      'feed',
      'manage_videos',
      'manage_subtitles',
      'read',
      'write',
      'delete',
    );
    $api->setGrantType(
        Dailymotion::GRANT_TYPE_PASSWORD, $api_key, $api_secret, $scopes, array(
      'username' => $user_name,
      'password' => $password,
        )
    );
  }
  catch (Exception $e) {
    if ($e->getMessage() == "Missing API key") {
      if (isset($_GET['destination'])) {
        unset($_GET['destination']);
      }
      drupal_set_message(t('Please enter API Key.'), 'error');
      drupal_goto('dailymotion/config');
    }
    else {
      drupal_set_message($e->getMessage(), 'error');
    }
  }
  return $api;
}

/**
 * This function use for get node status
 */
function itg_videogallery_get_node_status($nid) {
  $query = db_select('node', 'n')
      ->fields('n', array('status'))
      ->condition('n.nid', $nid)
      ->execute();
  $result = $query->fetchObject();
  $is_published = $result ? $result->status : FALSE;
  return $is_published;
}

/* * solr action on node updaet and insert
 * 
 * 
 */

function itg_videogallery_update_video_info_solr($videoid) {
  global $user;
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('video_id', $videoid, '=');
  $result_new = $query->execute()->fetchAll();
  foreach ($result_new as $val) {
     if ($val->is_draft != 1) {
      $video_status_used = $val->dailymotion_published;
      $video_is_draft = 0;
     }else {
      $video_status_used = 0;
      $video_is_draft = 1;
     }
    
      $node = new stdClass();
      $node->title = $val->title;
      $node->type = "itg_solr_video";
      node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
      $node->language = LANGUAGE_NONE;
      $node->field_video_id[LANGUAGE_NONE][0]['value'] = $val->video_id;
      $node->field_property [LANGUAGE_NONE][0]['value'] = VIDEO_PROPERTY;
      $node->field_video_duration [LANGUAGE_NONE][0]['value'] = $val->video_duration;
      $node->field_video_used [LANGUAGE_NONE][0]['value'] = $video_status_used;
      $node->field_video_thumb_url[LANGUAGE_NONE][0]['value'] = $val->dailymotion_thumb_url;
      $node->field_video_size[LANGUAGE_NONE][0]['value'] = $val->video_size;
      $node->field_is_replace[LANGUAGE_NONE][0]['value'] = $val->is_replace;
      $node->uid = 1;
      $node->field_video_is_draft[LANGUAGE_NONE][0]['value'] = $video_is_draft;
      $node->field_video_date_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
      $node->field_video_time[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $val->upload_time);
      $node->field_video_type[LANGUAGE_NONE][0]['value'] = $val->video_type;
      $node->status = 1; //(1 or 0): Published or not
      $node->promote = 0; //(1 or 0): Promoted to front page
      $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
      $video_exist_innode = itg_videogallery_get_video_solrcontent($val->video_id);
      if (!empty($video_exist_innode)) {
        $node->nid = $video_exist_innode[0]->nid;
        node_save($node);
      }
      // need to chane with solr
      node_save($node);
    
  }
}

/**
 * This function use for update embed url
 */
function itg_videogallery_update_embedcode_url($video_id) {
  $api = itg_videogallery_dailymotion_api();
  $thumb_url = $api->get(
      '/video/' . $video_id, array('fields' => array('embed_url'))
  );
  $embed_id = "";
  if ($thumb_url['embed_url']) {
    $embed_id = end(explode('/', $thumb_url['embed_url']));
  }
  $query = db_update('itg_solr_video_info')
      ->fields(array('video_embedded_url' => $embed_id));
  $query->condition('solr_video_id', $video_id);
  $query->execute();
}

/**
 * This method is used to add the video for daily motion from FTP
 * @return array
 */
function itg_videogallery_dailymotion_send_video($real_path) {

  $api = itg_videogallery_dailymotion_api();

  $url = $real_path;
  $file_name = basename($real_path);
  $chek_alredy_insert = itg_videogallery_dailymotion_check_alredy_send($file_name);
  if (empty($chek_alredy_insert)) {

    try {

      $ftp_file = explode('public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/', $real_path);
      $uri = 'public://dailymotion-ftp/' . $realfilename;
      $url = $real_path;

      $result = $api->post(
          '/me/videos', array(
        'url' => $url,
        'title' => $file_name,
        'channel' => 'tv',
        'private' => 'true',
        'published' => TRUE,
          )
      );
      $dur = $api->get(
          '/video/' . $result['id'], array('fields' => array('duration', 'embed_url', 'encoding_progress', 'publishing_progress'))
      );
      $playlist_id = variable_get('dailymotion_playlist_id');
      $result['duration'] = $dur['duration'];
      $result['name'] = $file_name;

      $result['encoding_progress'] = $dur['encoding_progress'];
      $result['publishing_progress'] = $dur['publishing_progress'];

      $a = new Dailymotion();
      $a->logout();
    }
    catch (Exception $e) {
      if ($e->getMessage() == "This `client_id' doesn't exist.") {
        if (isset($_GET['destination'])) {
          unset($_GET['destination']);
        }
        drupal_set_message(t('API Key is wrong.'), 'error');
      }
      elseif ($e->getMessage() == "Invalid `client_secret'") {
        if (isset($_GET['destination'])) {
          unset($_GET['destination']);
        }
        drupal_set_message(t('Secret Key is wrong.'), 'error');
      }
      elseif ($e->getCode() == 6) {
        if (isset($_GET['destination'])) {
          unset($_GET['destination']);
        }
        drupal_set_message(t('There is some issue with internet connection.'), 'error');
      }
      elseif ($e->getCode() == 400) {
        if (isset($_GET['destination'])) {
          unset($_GET['destination']);
        }
        drupal_get_messages();
        drupal_set_message(t('Do not use space in FTP filename. Please remove and again upload file without space in file name.'), 'error');
      }
      else {
        drupal_set_message($e->getMessage(), 'error');
      }
    }
  }

  return $result;
}

/**
 * This function use for get video info from  itg_solr_video_info table by fid
 */
function itg_videogallery_get_video_info_by_fid($fid) {
   $video_data = "";
   $query = db_select('itg_solr_video_info', 'isvi');
   $query->leftJoin('dailymotion_response_details', 'drd', 'isvi.solr_video_id = drd.video_id');
   $query->fields('isvi');
   $query->fields('drd', array('is_draft'));
   $query->condition('isvi.fid', $fid, '=');
   $video_data = $query->execute()->fetchAll();
   return $video_data;
}

/**
 * itg_videogallery_dailymotion_check_alredy_send() .
 */
function itg_videogallery_dailymotion_check_alredy_send($id) {
  $query = db_select('dailymotion_response_details', 'drd');
  $query->fields('drd');
  $query->condition('title', $id, '=');
  $query->condition('type', 'S3', '=');
  $result_new = $query->execute()->fetchAll();
  return $result_new;
}

/**
 * Function for show related content in block
 * @return boolean|string
 */
function get_header_tab_related_video_block_content() {
  global $base_url;
  $arg = arg();
  if ($arg[1] == null)
    return false;
  $related_content = itg_get_related_content($arg[1]);

  if (!empty($related_content)) {
    if (function_exists('itg_get_related_story_id')) {
      $related_result = itg_get_related_story_id($related_content);
    }
    $related_video .= "<div id='related-video-tab'><ul class='video-list'>";
    foreach ($related_result as $site_hash_key) {
      $current_entity_id = $site_hash_key;
      $related_data = itg_get_related_story_content($current_entity_id);
      $display_title = get_related_display_title($arg[1], $current_entity_id);
      if (!empty($display_title)) {
        $display_title = $display_title;
      }
      else {
        $display_title = $related_data->label;
      }
      // $related_title = html_entity_decode(htmlentities($display_title)); //mb_strimwidth($display_title, 0, 80, "..");
      $related_title = html_entity_decode($display_title);
      if (empty($related_data->sm_field_custom_story_small_large_url[0])) {
        $related_image_url = $base_url . '/sites/all/themes/itg/images/itg_image170x127.jpg';
      }
      else {
        $related_image_url = $related_data->sm_field_custom_story_small_large_url[0];
      }
        
      $related_video_duration = $related_data->sm_field_video_duration[0];

      $img_alt = str_replace(array('\'', '"'), '', $related_title); 
      $rel_title = str_replace(array('\'', '"'), '', $related_title);
      $url = $base_url ."/" . drupal_get_path_alias('node/' . $current_entity_id);
      $options = array(
        'html' => TRUE,
        "attributes" => array("target" => '_blank')
      );
      $output = l(htmlspecialchars_decode($rel_title, ENT_COMPAT), $url, $options);
           
      $related_image = '<img class="related-default" alt="' . $img_alt . '" title="'. $img_alt .'" src="' . $related_image_url . '">';
      if (!empty($related_title)) {
        $related_video .= '<li class="related_content_tabs"><figure><a href="'.$url.'" target="_blank" class="pic">'. $related_image .'<figcaption><i class="fa fa-play-circle"></i>'. $related_video_duration .'</figcaption>';
        $related_video .= '</figure></a><p class="title">' . $output . '</p></li>';
      }
    }
    $related_video .= "</ul></div>";
    return $related_video;
  }
  else {
    return false;
  }
}

/*
 * This function use for itg_delete_solr_video node delete
 */

function itg_videogallery_get_video_setting_by_bucket_name($bucket_name) {
   $query = db_select('node', 'n');
   $query->join('field_data_field_hls_domain', 'fdfhd', 'fdfhd.entity_id = n.nid');
   $query->join('field_data_field_progressive_domain', 'fdfpd', 'fdfpd.entity_id = n.nid');
   $query->fields('fdfhd', array('field_hls_domain_value'));
   $query->fields('fdfpd', array('field_progressive_domain_value'));
   $query->condition('title', $bucket_name, ' = ');
   $query->condition('type', 'video_setting_by_bucket_name', ' = ');
   $video_data = $query->execute()->fetchAll();
 
  return $video_data;
}

/**
 * Implements itg_videogallery_make_url_for_jwpalyer
 * @parm array $video_data
 */
function itg_videogallery_make_parm_for_jwpalyer($video_data, $used_on, $external) {
  global $base_url;
  $retrun_array = array();
  if (!empty($video_data)) {
    $bucket_output = $video_data['out']['properties']['bucket_output'];
    $getbucket_setting = itg_videogallery_get_video_setting_by_bucket_name($bucket_output);
    $get_all_bitrate = array_column($video_data['out']['videos']['video'], 'bitrate');
    asort($get_all_bitrate);
    $get_play_video_info = itg_videogallery_get_play_video_in_video_info($video_data['out']['videos']['video']);
    $retrun_array['file_url'] = $getbucket_setting[0]->field_progressive_domain_value . '/' . $get_play_video_info['output_path'];
    $bitrate_url = itg_videogallery_make_bitrate_url($video_data['in']['input_path'], $get_all_bitrate, $getbucket_setting[0]->field_hls_domain_value);
    $retrun_array['bitrate_url'] = $bitrate_url;
    $retrun_array['player_image'] = $base_url . "/" . drupal_get_path('theme', 'itg') . '/images/itg_image370x208.jpg';
  }
  $dfp_data = itg_videogallery_get_dfp_tags($video_data['in']['website'], $video_data['in']['client']);
  $retrun_array['dfp_tags'] = JWPLAYER_DFP_TAG;
  if (!empty($dfp_data) && !empty($dfp_data[0]->dfp_tags)) {

    if ($used_on == 'embed') {
      if ($external == 1) {
        $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags_external;
      }
      else {
        $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags_internal;
      }
    }
    else {
      $retrun_array['dfp_tags'] = $dfp_data[0]->dfp_tags;
    }
  }
  

  if (!empty($dfp_data)) {
    if ($used_on == 'embed' && !empty($dfp_data[0]->ga_tag_extarnal)) {
      $retrun_array['ga_code'] = $dfp_data[0]->ga_tag_extarnal;
    }
    else {
      $retrun_array['ga_code'] = ITG_GA_CODE;
    }
    if ($used_on != 'embed' && !empty($dfp_data[0]->ga_tag_internal)) {
      $retrun_array['ga_code'] = $dfp_data[0]->ga_tag_internal;
    }
    else {
      $retrun_array['ga_code'] = ITG_GA_CODE;
    }
  }

  return $retrun_array;
}

/**
 * Implements itg_videogallery_make_url_for_jwpalyer
 * @parm array $video_data
 */

function itg_videogallery_get_play_video_in_video_info($video_data) {
  if(is_array($video_data) && !empty($video_data)) {
    $return_data = $video_data[0];
    foreach ($video_data as $key=> $data) {
      if($data['bitrate'] == 512) {
        $return_data = $data;
      }
    }
  }
  return $return_data;
}

/**
 * This function use for make video bitrate url:
 */
function itg_videogallery_make_bitrate_url($video_url, $bitrates,$hls) {
  $withoutExt = substr($video_url, 0 , (strrpos($video_url, ".")));
  $find = array("/processing/");
  $replace = array("/video/");
  $withoutExt = (str_replace($find,$replace,$withoutExt));
  $with_hls_url = $hls.'/i'.'/'.$withoutExt.'_';
  $returnstring = $with_hls_url . ',' . implode(',', $bitrates) . ',.mp4.csmil/master.m3u8';
  return $returnstring;
}

/**
 * 
 */
function itg_videogallery_get_dfp_tags($website , $client) {
  $query = db_select('itg_dfp_tags_setting', 'idts');
  $query->fields('idts');
  $query->condition('wesbite', strtolower($website), '=');
  $query->condition('client', strtolower($client), '=');
  $video_data = $query->execute()->fetchAll();
  return $video_data;
}

/**
 * Function use for get all draft video 
 */
function itg_videogallery_get_all_draft_video_of_video_content() {
  $video_data = "";
  $all_video_id = array();
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('solr_video_id'));
  $query->isNotNull('nid')->condition('content_type', 'video_gallery', '=');
  $query->condition('is_node_draft', '1', '=');
  $video_data = $query->execute()->fetchAll();
  foreach ($video_data as $vid_data) {
    $all_video_id[] = $vid_data->solr_video_id;
  }
  return $all_video_id;
}

/**
 * Function use for get all used video 
 */
function itg_videogallery_get_all_publish_video_of_video_content() {
  $video_data = "";
  $all_video_id = array();
  $query = db_select('itg_solr_video_info', 'drd');
  $query->fields('drd', array('solr_video_id'));
  $query->isNotNull('nid')->condition('content_type', 'video_gallery', '=');
  $video_data = $query->execute()->fetchAll();
  foreach ($video_data as $vid_data) {
    $all_video_id[] = $vid_data->solr_video_id;
  }
  return $all_video_id;
}

/**
 *  This function use for get video info from  itg_solr_video_info table by fid
 */
function itg_videogallery_get_video_xml_data_by_fid($fid) {
   $video_data = "";
   $query = db_select('itg_solr_video_info', 'isvi');
   $query->fields('isvi');
   $query->condition('isvi.fid', $fid, '=');
   $video_data = $query->execute()->fetchAll();
   return $video_data;
}

/**
 * Checking whether file is already exist or not
 * @return string
 */
function check_file_already_exist_or_not($filename) {

  $query = db_select('file_managed', 'fm');
  $query->condition('filename', $filename, '=');
  $query->fields('fm');
  $query->orderBy('fm.fid', 'DESC');
  $query->range(0, 1);
  $results = $query->execute()->fetchAll();
  if (!isset($results[0])) {
    return $filename;
  }
  else {
    $result = explode('public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/', $results[0]->uri);
    $path_info = pathinfo($results[0]->filename);
    $extension = $path_info['extension'];
    $file_name = $path_info['filename'];
    $result_num = explode($file_name . '_', $result[1]);
    $num_file_id = explode('.' . $extension, $result_num[1]);
    if (is_numeric($num_file_id[0]) && isset($num_file_id[0])) {
      $value = $num_file_id[0] + time();
      $value = '_' . $value;
    }
    else {
      $value = '_' . time();
    }
    $file_info = pathinfo($filename);
    $res = $file_info['filename'] . $value . '.' . $extension;
    return $res;
  }
}

/**
 * Checking whether file is already exist or not
 * @return string
 */
function check_file_already_exist_or_not_by_ftp($filename) {
  $query = db_select('dailymotion_response_details', 'drd');
  $query->condition('name', $filename, '=');
  $query->fields('drd');
  $query->range(0, 1);
  $results = $query->execute()->fetchAll();
  return$results[0];
}

/**
 * Implements function for remove video from playlist
 */
function itg_videogallery_update_tags_video_private($tags_value, $video_id, $private, $video_desc = "", $video_title = "", $video_thumb_fid = "", $exclue_ads = "") {
  if ($video_thumb_fid) {
    $image_load = file_load($video_thumb_fid);
    $image_url = file_create_url($image_load->uri);
  }
  if ($private == 'Yes') {
    $private = 'true';
  }
  else {
    $private = 'false';
  }
  if (strtolower($exclue_ads) == 'yes') {
    $exclude_ads_flag = 'true';
  }
  else {
    $exclude_ads_flag = 'false';
  }

  $video_desc = itg_videogallery_clean_string($video_desc);
  $video_title = itg_videogallery_clean_string($video_title);
  $api = itg_videogallery_dailymotion_api();
  if($video_title != "") {
    $update_field = array('title' => $video_title);
    itg_videogallery_update_dailymotion_table_by_videoid($update_field , $video_id );
  }
// Tags assign to node and thumbnail
  if (!empty($tags_value) && !empty($video_title)) {
    $api->post('/video/' . $video_id . '?tags=' . $tags_value . '&private=' . $private . '&title=' . $video_title . '&description=' . $video_desc . '&advertising_instream_blocked=' . $exclude_ads_flag);
  }
  elseif (empty($tags_value) && !empty($video_title)) {
    $api->post('/video/' . $video_id . '?private=' . $private . '&title=' . $video_title . '&description=' . $video_desc . '&advertising_instream_blocked=' . $exclude_ads_flag);
  }
  elseif (!empty($tags_value) && empty($video_title)) {
    $api->post('/video/' . $video_id . '?tags=' . $tags_value . '&private=' . $private . '&description=' . $video_desc);
  }
  else {
    $api->post('/video/' . $video_id . '?private=' . $private);
  }
  if ($image_url != "") {
    $api->post('/video/' . $video_id . '?thumbnail_url=' . $image_url);
  }
  $thumb_url = $api->get(
      '/video/' . $video_id, array('fields' => array('thumbnail_720_url'))
  );

  $image_url = $thumb_url['thumbnail_720_url'];
  $num_updated = db_update('itg_solr_video_info') // Table name no longer needs {}
      ->fields(array(
        'solr_video_thumb' => $image_url
      ))
      ->condition('solr_video_id', $video_id, '=')
      ->execute();
}

/**
 * Implements function for ftp connection.
 */
function itg_videogallery_ftp_video_list() {
  $ftp_server = variable_get('dailymotion_ftp_host', '');
  $ftp_user_name = variable_get('dailymotion_ftp_username', '');
  $ftp_user_pass = variable_get('dailymotion_ftp_password', '');
  $conn_id = ftp_connect($ftp_server);
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);
  if ((!$conn_id) || (!$login_result)) {
    watchdog("WATCHDOG_INFO_video", "FTP connection has failed");
  }
  return $conn_id;
}
