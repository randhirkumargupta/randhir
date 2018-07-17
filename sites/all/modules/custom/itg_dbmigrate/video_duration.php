<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

video_field_update_cat_map();

function video_field_update_cat_map() {
  $path_xml = 'sites/default/files/migrate/xml_file/videos-2008-2016/';
  $photo_array_val = category_mapping_script_video();
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

      $nid = _return_nid_by_xml_id_photo((int) $xml->id);


      if (!empty($nid)) {
          $node = node_load($nid);
          $new_photo_cat = '';
          $term = '';
          $primary_category = '';
          // video duration time
          $duration = "";
          if ((string) $xml->video_duration < 3600) {
            $duration = gmdate("i:s", (string) $xml->video_duration);
          }
          else {
            $duration = gmdate("H:i:s", (string) $xml->video_duration);
          }
          if(!empty($duration)) {
            $node->field_video_duration['und'][0]['value'] = $duration;
          }
          field_attach_update('node', $node);
        
      }
      echo $xml->id . ' nid ' . $nid . ', ';
    }
  }
}

function _return_nid_by_xml_id_photo($xml_id) {
  $query = db_select('migrate_map_itgvideogallery', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->condition('sourceid1', $xml_id, '=');
  $result = $query->execute()->fetchField();
  return $result;
}


?>