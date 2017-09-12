<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.




function final_database_testing_with_xml_new_photo() {
  $path = 'sites/default/files/migrate/xml_file/photos-2009-2016/';
  $tcount = 0;
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path)) as $filename) {
    $file_name = $filename->getFilename();
    echo '"' . $file_name . '", ';
    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $array_issue_based[] = $file_name;
  }

  foreach ($array_issue_based as $photo_value) {
    $xml = simplexml_load_file($path . $photo_value, 'SimpleXMLElement');
    foreach ($xml->photogallery as $xml_data) {
      $source_id = (int) $xml_data->id;
      echo $source_id . ', ';
      $result = get_data_from_photolist_table($source_id);
      if (empty($result)) {
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'photo_match',
            ))
            ->execute();
      }elseif(!empty($result)){
        db_insert('itg_migrate_data_test') // Table name no longer needs {}
            ->fields(array(
              'source_id1' => $source_id,
              'destid1' => $source_id,
              'xml_name' => $file_name,
              'type' => 'photo_notmatch',
            ))
            ->execute();
      }
      $count ++;
    }
    $tcount = $tcount + $count;
  }
  echo $tcount;
}


function get_data_from_photolist_table($source_id) {
  $query = db_select('migrate_map_itgphotogallery', 'mm_story');
  $query->fields('mm_story', array('sourceid1', 'destid1'));
  $query->condition('sourceid1', $source_id, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $value_rel['source_id'] = $rel->sourceid1;
    $value_rel['destid'] = $rel->destid1;
  }
  return $value_rel;
}
?>
