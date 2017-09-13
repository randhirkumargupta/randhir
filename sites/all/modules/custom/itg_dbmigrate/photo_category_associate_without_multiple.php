<?php

set_time_limit(0);
//ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.
associate_category_video();

function associate_category_photo() {
  $photo_array_val = category_mapping_script_photo('photo');
  foreach ($photo_array_val as $key => $photo_array) {
    
    if (!empty($photo_array['photo_category_id']) && $photo_array['photo_category_id'] != 'NA') {
      $term = taxonomy_term_load($photo_array['section']);
      if (!empty($term)) {
        if (!in_array('photogallery', array_column($term->field_cm_select_type['und'], 'value'))) { // search value in the array
          //echo "NOT FOUND Content";
          //p($term->field_cm_select_type['und']);
          //$term->field_cm_select_type['und'][]['value'] = 'photogallery'; //videogallery
          //field_attach_update('taxonomy_term', $term);
          echo $key .'Source id '.$photo_array['orignal_section'].' tid '.$term->tid. ', ';
        }
      }
    }
  }
}



// Total value : 375
// Total remove : 'na' and text:237
// Total value for use : 138 // confirm with santosh // 4 multiple in photo
function category_mapping_script_photo() {
  //$file_path = 'sites/default/files/cat_mapping/';
  $file_path = 'sites/default/files/migrate/xml_file/cat_map_photo_without_multiple/';
  //$file_name = 'section_mapping_csv_updated.csv';
  $file_name = 'section_mapping_csv_multiplecat_remove_photo.csv';

  $row = 1;
  $count = 0;
  if (($handle = fopen($file_path . $file_name, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
      $num = count($data);
      $row++;
      $count++;
      for ($c = 0; $c < $num; $c++) {
        $value_photo[$count]['photo_category_id'] = (!empty($data[2] && is_numeric($data[2])) ? get_itg_destination_id('migrate_map_itgphoto', $data[2]) : 'NA');
        $value_photo[$count]['section'] = (!empty($data[0] && is_numeric($data[0])) ? get_itg_destination_id('migrate_map_itgsection', $data[0]) : 'NA');
        $value_photo[$count]['photo_orig_category_id'] = (!empty($data[2] && is_numeric($data[2])) ? $data[2] : 'NA');
        $value_photo[$count]['orignal_section'] = (!empty($data[0]) ? $data[0] : 'NA');
      }
    }
  }
  $photo_csv_array = array_slice($value_photo, 1);
  return $photo_csv_array;
  fclose($handle);
}




/**
 * Associate category with video
 */
function associate_category_video() {
  $video_array_val = category_mapping_script_video();
  foreach ($video_array_val as $key => $video_array) {
    
    if (!empty($video_array['video_category_id']) && $video_array['video_category_id'] != 'NA') {
      $term = taxonomy_term_load($video_array['section']);
      if (!empty($term)) {
        if (!in_array('videogallery', array_column($term->field_cm_select_type['und'], 'value'))) { // search value in the array
          //echo "NOT FOUND Content";
          //p($term->field_cm_select_type['und']);
          $term->field_cm_select_type['und'][]['value'] = 'videogallery'; //videogallery
          field_attach_update('taxonomy_term', $term);
          echo $key .'Source id '.$video_array['orignal_section'].' tid '.$term->tid. ', ';
        }
      }
    }
  }
}


// Total value : 375
// Total remove : 'na' and text:237
// Total value for use : 138 // confirm with santosh // 4 multiple in photo
function category_mapping_script_video() {
  //$file_path = 'sites/default/files/cat_mapping/';
  $file_path = 'sites/default/files/migrate/xml_file/cat_map_photo_without_multiple/';
  $file_name = 'section_mapping_video.csv';
  //$file_name = 'section_mapping_video.csv';

  $row = 1;
  $count = 0;
  if (($handle = fopen($file_path . $file_name, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
      $num = count($data);
      $row++;
      $count++;
      for ($c = 0; $c < $num; $c++) {
        $value_photo[$count]['video_category_id'] = (!empty($data[4] && is_numeric($data[4])) ? get_itg_destination_id('migrate_map_itgcategory', $data[4]) : 'NA');
        $value_photo[$count]['section'] = (!empty($data[0] && is_numeric($data[0])) ? get_itg_destination_id('migrate_map_itgsection', $data[0]) : 'NA');
        $value_photo[$count]['video_orig_category_id'] = (!empty($data[4] && is_numeric($data[4])) ? $data[4] : 'NA');
        $value_photo[$count]['orignal_section'] = (!empty($data[0]) ? $data[0] : 'NA');
      }
    }
  }
  $photo_csv_array = array_slice($value_photo, 1);
  return $photo_csv_array;
  fclose($handle);
}
?>
