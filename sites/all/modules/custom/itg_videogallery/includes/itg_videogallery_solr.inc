<?php
/**
 * function use for insert solr video in file_manage for fid
 * @global object $user
 * 
 */
function itg_videogallery_solr_video_insert_in_for_fid() {
  global $user;
  $videos_data = $_POST['checkvalue'];
  $return_fid = array();

  if (!empty($videos_data)) {
    foreach ($videos_data as $video_info) {
      $expode_video_info = explode('#', $video_info);
      $videourl = 'public://' . LOCAL_VIDEO_DIR . '/' . date('Ym') . '/' . rand(111,9999) . '/' . time() . '/' . $expode_video_info[0] . '.mp4';
      $fid = db_insert('file_managed')
          ->fields(array(
            'uid' => $user->uid,
            'filename' => $expode_video_info[2],
            'uri' => $videourl,
            'filemime' => 'video/mp4',
            'filesize' => $expode_video_info[1],
            'status' => 1,
            'timestamp' => REQUEST_TIME,
          ))
          ->execute();
      $file = file_load($fid);
      file_usage_add($file, 'itg_videogallery', 'file', $file->fid);
      $is_used = 0;
     
      if (isset($expode_video_info[7]) && !empty($expode_video_info[7])) {
        $is_used = 1;
      }
      if($expode_video_info[8] == "") {
        $expode_video_info[8] = 'DM';
      }
      $fid = db_insert('itg_solr_video_info')
          ->fields(array(
            'fid' => $file->fid,
            'solr_video_id' => $expode_video_info[0],
            'solr_video_duration' => $expode_video_info[4],
            'solr_video_size' => $expode_video_info[1],
            'property' => $expode_video_info[5],
            'content_type' => $expode_video_info[6],
            'video_repo_type' => $expode_video_info[8],
            'video_xml_data' => $expode_video_info[9],
            'is_alredy_used' => $is_used,
            'solr_video_thumb' => $expode_video_info[3],
          ))
          ->execute();
      $return_fid[] = $file->fid;
    }
  }
  exit(json_encode($return_fid));
}

/**
 * Implements function for get options for Local FTP file list and used
 * @return array
 */
function itg_videogallery_s3_file_to_dm() {
  global $user;
  module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
  $data_video = itg_video_get_s3_video();

  foreach ($data_video['video'] as $key => $s3_video_url) {


    $response = itg_videogallery_dailymotion_send_video($s3_video_url);

// Perform playlist and tags when new video create.
    if (!empty($response)) {
      $response_result['video_id'] = $response['id'];
      $response_result['fid'] = 0;

      try {

        $nid = db_insert('dailymotion_response_details')
            ->fields(array(
              'title' => $response['title'],
              'channel' => $response['channel'],
              'fid' => $response['fid'],
              'video_type' => 'DM',
              'tags' => ' ',
              'video_id' => $response['id'],
              'nid' => 0,
              'video_size' => $data_video['size'][$key],
              'encoding_progress' => $response['encoding_progress'],
              'publishing_progress' => $response['publishing_progress'],
              'upload_time' => REQUEST_TIME,
              'video_duration' => $response['duration'],
              'dailymotion_published' => 0,
              'type' => 'S3',
              'name' => $response['name'],
            ))
            ->execute();

// data insert into node
      }
      catch (Exception $e) {
        die($e->getMessage());
      }
// Code start for Adding  video in daily motion 
    }
  }
// Use the high-level iterators (returns ALL of your objects).
}

/**
 * Implements function for get options for Local FTP file list and used
 * @return array
 */
function itg_videogallery_dm_to_s3() {
  module_load_include('inc', 'itg_videogallery', 'includes/itg_videogallery_aws_s3');
  global $user;
  $query = db_select('itg_video_bitrates_data', 'ivbd');
  $query->fields('ivbd');
  $query->condition('is_download', '0', '=');
  $result = $query->execute()->fetchall();
  foreach ($result as $key => $value) {
    if (!empty($value->bitate_url)) {
      $video_urlsdata = $value->video_id . '_' . $value->bitrate . '.mp4';
      $senddata = itg_video_send_dm_to_s3($value->bitate_url, $video_urlsdata);
      if (!empty($senddata)) {
        $node = new stdClass();
        $node->title = $value->video_name;
        $node->type = "itg_bitrates_video";
        node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
        $node->language = LANGUAGE_NONE;
        $node->field_bitrate_video_id[LANGUAGE_NONE][0]['value'] = $value->video_id;
        $node->field_video_url [LANGUAGE_NONE][0]['value'] = $senddata;
        $node->field_video_bitrate [LANGUAGE_NONE][0]['value'] = $value->bitrate;
        $node->field_resolution [LANGUAGE_NONE][0]['value'] = $value->framesize;
        $node->field_bitrate_video_duration [LANGUAGE_NONE][0]['value'] = $value->duration;
        $node->uid = $user->uid;
        $node->status = 1; //(1 or 0): Published or not
        $node->promote = 0; //(1 or 0): Promoted to front page
        node_save($node);
        $query = db_update('itg_video_bitrates_data');
        $query->fields(array('is_download' => 1));
        $query->condition('id', $value->id, '=');
        $query->execute();
      }
    }
  }

// Use the high-level iterators (returns ALL of your objects).
}