<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

video_field_update_bitrate_map();

function video_field_update_bitrate_map() {
  $path_xml = 'sites/default/files/migrate/xml_file/videos-2008-2016/';
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();

    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->videogallery as $xml) {
      $nid = '';
      $node = '';
      $final_array = '';
      $published_date = '';
      $published_date_ist = '';
      $published_dates = '';
      $node_sef = '';
      $node_sef_value = '';
      $node_new_sefurl = '';
      $path = '';
      $check_updated = '';
      $nid = _return_nid_by_xml_id_for_video((int) $xml->id);
      if (!empty($nid)) {
        $check_nid = _check_nid_exist_in_bitrate($nid);
        if (empty($check_nid)) {
          if (isset($xml->videoparts) && !empty($xml->videoparts)) {
            $key = 0;
            foreach ($xml->videoparts->part as $value) {
              $new_value = (string) $value->part_url;
              $video_url = (string) $value->part_url;
              // multi bitrate save in custom table
              if (!empty($value->multi_bitrates)) {
                $chk_variable = '';
                foreach ($value->multi_bitrates->bitrate as $bitrate) {
                  $chk_variable = (string) $bitrate;
                  if (!empty($chk_variable)) {
                    db_insert('itg_video_transcoding')
                        ->fields(array(
                          'nid' => $nid,
                          'bitrate' => ((int) $bitrate ? (int) $bitrate : NULL),
                          'bitrate_type' => ((string) $bitrate->attributes()->type ? (string) $bitrate->attributes()->type : NULL),
                          'bitrate_status' => ((string) $bitrate->attributes()->status ? (string) $bitrate->attributes()->status : NULL),
                          'file_size' => ((int) $bitrate->attributes()->file_size ? (int) $bitrate->attributes()->file_size : NULL),
                          'completion_datetime' => ((string) $bitrate->attributes()->completion_datetime ? (string) $bitrate->attributes()->completion_datetime : NULL),
                          'bitrate_ordering' => ((int) $bitrate->attributes()->ordering ? (int) $bitrate->attributes()->ordering : NULL),
                          'video_duration' => ((int) $value->part_duration ? (int) $value->part_duration : NULL),
                          'website' => ((string) $xml->website ? (string) $xml->website : NULL),
                          'transcoding_id' => ((int) $xml->transcoding_id ? (int) $xml->transcoding_id : NULL),
                          'transcoding_source' => ((string) $xml->transcoding_source ? (string) $xml->transcoding_source : NULL),
                          'bucket_output' => ((string) $xml->bucket_output ? (string) $xml->bucket_output : NULL),
                          'hls_domain' => ((string) $xml->hls_domain ? (string) $xml->hls_domain : NULL),
                          'video_url' => ($video_url ? $video_url : NULL),
                        ))
                        ->execute();
                  }
                }
              }
            }
          }

        }
        print $nid.',';
      }
    }
  }
}

function _check_nid_exist_in_bitrate($nid) {
  $query = db_select('itg_video_transcoding', 'ivt');
  $query->fields('ivt', array('id'));
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

function _return_nid_by_xml_id_for_video($xml_id) {
  $query = db_select('migrate_map_itgvideogallery', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}

?>