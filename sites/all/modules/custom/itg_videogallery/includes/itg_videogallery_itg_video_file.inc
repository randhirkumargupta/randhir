<?php

/**
 * @file
 * ITG Videogallery ITG Video File inc.
 */

/**
 * Impelements itg_videogallery_push_itg_video.
 */
function itg_videogallery_push_itg_video() {

  $data = file_get_contents('php://input');
  $xml_data = simplexml_load_string($data);
  $response_xml = '<transcodes><transcode>';
  foreach ($xml_data->transcode as $xml) {
    $video_info = (array) $xml->in;
    $client_name = $video_info['client'];
    $query = db_select('dailymotion_response_details', 'drd');
    $query->condition('transcode_id', $video_info['trans_id'], '=');
    $query->fields('drd', array('title', 'path', 'bitrate', 'aspect_ratio', 'video_id'));
    $query->range(0, 1);
    $results = $query->execute()->fetchAll();
    if (empty($results)) {
      $video_output = (array) $xml->out;
      $video_properties = (array) $video_output['properties'];
      $video_bitrate = "";
      $video_ratio = "";
      $get_video_bitrate_info = itg_videogallery_get_video_bitrate_in_xml((array) $video_output['videos']);
      if (isset($get_video_bitrate_info['bitrate']) && !empty($get_video_bitrate_info['bitrate'])) {
        $video_bitrate = implode($get_video_bitrate_info['bitrate'], '@');
        $video_ratio = implode($get_video_bitrate_info['ratio'], '@');
      }
      $node = new stdClass();
      $node->title = $video_info['filename'];
      $node->type = "itg_solr_video";
      node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().
      $node->language = LANGUAGE_NONE;
      $video_id = itg_videogallery_make_internal_video_id($video_info['trans_id']);
      // get duration here
      $duration_in_second = (int) $video_properties['duration_ms'];
      if ($duration_in_second < 3600) {
        $duration = gmdate("i:s", $duration_in_second);
      }
      else {
        $duration = gmdate("H:i:s", $duration_in_second);
      }
      $node->field_video_id[LANGUAGE_NONE][0]['value'] = $video_id;
      $node->field_property [LANGUAGE_NONE][0]['value'] = VIDEO_PROPERTY;
      $upload_time = date('Y-m-d H:i:s');
      $node->field_video_duration [LANGUAGE_NONE][0]['value'] = $duration;
      $node->field_video_used [LANGUAGE_NONE][0]['value'] = 0;
      $node->field_video_thumb_url[LANGUAGE_NONE][0]['value'] = "";
      $node->field_video_size[LANGUAGE_NONE][0]['value'] = $get_video_bitrate_info['size'];
      $node->field_is_replace[LANGUAGE_NONE][0]['value'] = 0;
      $node->uid = 1;
      $node->field_video_is_draft[LANGUAGE_NONE][0]['value'] = 0;
      $node->field_video_date_time[LANGUAGE_NONE][0]['value'] = $upload_time;
      $node->field_video_time[LANGUAGE_NONE][0]['value'] = $upload_time;
      $node->field_video_bucket_output[LANGUAGE_NONE][0]['value'] = $video_properties['bucket_output'];
      $node->field_primary_ratio[LANGUAGE_NONE][0]['value'] = $video_properties['primary_ratio'];
      $node->field_complete_date[LANGUAGE_NONE][0]['value'] = $video_properties['completion_datetime'];
      $node->field_video_path[LANGUAGE_NONE][0]['value'] = $video_info['input_path'];
      $node->field_video_bitrates[LANGUAGE_NONE][0]['value'] = $video_bitrate;
      $node->field_aspect_ratio[LANGUAGE_NONE][0]['value'] = $video_ratio;
      $node->field_transcode_id[LANGUAGE_NONE][0]['value'] = $video_info['trans_id'];
      $node->field_video_type[LANGUAGE_NONE][0]['value'] = 'INTERNAL';
      $conver_to_array = json_decode(json_encode($xml), true);
      $node->field_all_xml_content[LANGUAGE_NONE][0]['value'] = json_encode($conver_to_array);
      $node->status = 1; //(1 or 0): Published or not
      $node->promote = 0; //(1 or 0): Promoted to front page
      $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
      node_save($node);

      if ($node->nid != "") {
        // insert in DM table.
        try {

          $data_insert = array(
            'title' => $video_info['filename'],
            'name' => $video_info['filename'],
            'channel' => $client_name,
            'video_type' => 'INTERNAL',
            'tags' => "",
            'video_id' => $video_id,
            'nid' => $node->nid,
            'upload_time' => REQUEST_TIME,
            'video_duration' => $duration,
            'dailymotion_published' => 0,
            'video_size' => $get_video_bitrate_info['size'],
            'transcode_id' => $video_info['trans_id'],
            'path' => $video_info['input_path'],
            'bucket_oputput' => $video_properties['bucket_output'],
            'bitrate' => $video_bitrate,
            'aspect_ratio' => $video_ratio,
            'is_draft' => 0,
            'type' => 'INTERNAL',
          );

          $insert_id = db_insert('dailymotion_response_details')
              ->fields($data_insert)
              ->execute();
          if ($insert_id) {
            $ratio_exp = explode('@', $video_ratio);
            $bitrates_exp = explode('@', $video_bitrate);
            foreach ($bitrates_exp as $bitr) {
              $response_xml .= '<item><transcoding_id>' . $video_info['trans_id'] . '</transcoding_id><file_path>' . $results[0]->path . '</file_path><bitrate>' . $bitr . '</bitrate><aspect_ratio>' . $ratio_exp[0] . '</aspect_ratio><id>' . str_replace("PROD","", $video_id) . '</id><action>INSERT</action></item>';
            }
            //$rtn = array('code=>200', 'video_id' => $video_id,'msg' => 'This video pushed successfully');
            //http_response_code(200);
            //print json_encode($rtn);
          }
          else {
            $response_xml .= '<item><transcoding_id>' . $video_info['trans_id'] . '</transcoding_id></item>';
            //$rtn = array('code=>500', 'video_id' => $video_id, 'msg' => 'something wrong happened');
            //http_response_code(500);
            //print json_encode($rtn);
          }
          // rename($path_xml . $file_name, $path_xml_old . $file_name);
        }
        catch (Exception $e) {
          # TODO can search $e for 'Integrity constraint violation' or 'Duplicate entry'
          # to verify the user tried to use the same name twice.
          watchdog_exception('Xml Data not insert in DM responce Table', $e);
        }
      }
    }
    else {
      $ratio_exp = explode('@', $results[0]->aspect_ratio);
      $bitrates_exp = explode('@', $results[0]->bitrate);
      foreach ($bitrates_exp as $bitr) {
        $response_xml .= '<item><transcoding_id>' . $video_info['trans_id'] . '</transcoding_id><file_path>' . $results[0]->path . '</file_path><bitrate>' . $bitr . '</bitrate><aspect_ratio>' . $ratio_exp[0] . '</aspect_ratio><id>' . str_replace("PROD","",$results[0]->video_id) . '</id><action>UPDATE</action></item>';
      }
      //$rtn = array('code=>422', 'msg' => 'This video Already pushed');
      //http_response_code(422);
      //print json_encode($rtn);
    }
  }
  $response_xml .= '</transcode></transcodes>';
  header('Content-Type: application/xml; charset=utf-8');
  print $response_xml;
  drupal_exit();
}

/**
 * Impelements itg_videogallery_make_internal_video_id.
 */
function itg_videogallery_make_internal_video_id($trancode_id) {

  return VIDEO_PROPERTY . $trancode_id;
}

function itg_videogallery_get_video_bitrate_in_xml(array $data) {
  if (is_array($data)) {
    $data_return = array();
    $conver_to_array = json_decode(json_encode($data), true);
    $data_return['bitrate'] = array_column($conver_to_array['video'], 'bitrate');
    $data_return['ratio'] = array_column($conver_to_array['video'], 'ratio');
    $data_return['size'] = $conver_to_array['video'][0]['file_size'];
  }
  return $data_return;
}
