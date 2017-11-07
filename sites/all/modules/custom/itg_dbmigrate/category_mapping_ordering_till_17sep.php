<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

video_field_update_sub_category_map_13();

function video_field_update_sub_category_map_13() {
  $path_xml = 'sites/default/files/migrate/xml_file/video_2017_till17sep/';
  //$photo_array_val = category_mapping_script();
  foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($path_xml)) as $filename) {
    $file_name = $filename->getFilename();

    if ($file_name == '.' || $file_name == '..') {
      continue;
    }
    $xml_data = simplexml_load_file($path_xml . $file_name, 'SimpleXMLElement');
    foreach ($xml_data->videogallery as $xml) {
      $nid = '';
      $node = '';
      $nid = _return_nid_by_xml_id_photo((int) $xml->id);
      if (!empty($nid)) {
        $node = node_load($nid);
        ordering_set_of_content_cat_map($node, (string) $xml->ordering);
        echo $xml->id . ' nid ' . $nid . ', ';
      }
    }
    if (copy($path_xml . $file_name, "sites/default/files/migrate/xml_file/videos_complete/" . $file_name)) {
      unlink($path_xml . $file_name);
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


/**
 * Ordering save in widget order table
 */
function ordering_set_of_content_cat_map($node, $count) {
  $nid = $node->nid;
         if (function_exists('__itg_widget_helper_data_insert')) {
                            __itg_widget_helper_data_insert($node->nid);
                        }
  if (isset($node->field_story_category['und'])) {
    $cat_id = $node->field_story_category['und'];
      foreach ($cat_id as $category) {
        $exist_cat_id = '';
        $exist_cat_section_id = '';
        $exist_cat_id = check_ordering_cat_id($nid, $category['tid']);
        $exist_cat_section_id = check_ordering_cat_id_section($nid, $category['tid']);
        if (empty($exist_cat_section_id)) {       
         $query = db_insert('itg_widget_order_section')
        ->fields(array(
          'nid' => $nid,
          'widget' => 'section_wise_widget',
          'content_type' => $node->type,
          'cat_id' => $category['tid'],
          'weight' => $count,
          'extra' => "",
        ))
        ->execute();
         _delete_old_data_from_section_widget('itg_widget_order_section', $category['tid'], $node->type);
        }
if (empty($exist_cat_id)) {
        $query = db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $nid,
            'widget' => 'section_wise_widget',
            'content_type' => 'All',
            'cat_id' => $category['tid'],
            'weight' => $count,
            'extra' => '',
        ))
        ->execute();  
       _delete_old_data_from_section_widget('itg_widget_order', $category['tid'], "all");
      }
    }
  }
}

/**
 * Implement function for check category id for order
 */
function check_ordering_cat_id($nid, $cat_id) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->fields('iwo', array('cat_id'));
  $query->condition('cat_id', $cat_id, '=');
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}
/**
 * Implement function for check category id for order
 */
function check_ordering_cat_id_section($nid, $cat_id) {
  $query = db_select('itg_widget_order_section', 'iwos');
  $query->fields('iwos', array('cat_id'));
  $query->condition('cat_id', $cat_id, '=');
  $query->condition('nid', $nid, '=');
  $result = $query->execute()->fetchField();
  return $result;
}


?>
