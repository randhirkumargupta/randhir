<?php

set_time_limit(0);
ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

photo_enable_checkbox();
$i = 1;

function photo_enable_checkbox() {
  $all_photo_array = _return_nid_by_xml_id_photo();
  $photo_nid = '';
  $node = '';
    foreach ($all_photo_array as $photo_node) {
      $photo_nid = $photo_node->destid1;
      $node = node_load($photo_nid);
      $field_collection = '';
      $collection_id = '';
      $item = '';
      foreach ($node->field_gallery_image['und'] as $key => $field_collection) {
        $collection_id = $field_collection['value'];
        $item = field_collection_item_load($collection_id);
        $item->field_photo_enable['und'][0]['value'] = 1;
        $item->save(TRUE);
      }
      echo $node->nid.', ';
    }
  $i++;
}

function _return_nid_by_xml_id_photo() {
  $query = db_select('migrate_map_itgphotogallery', 'm_map_i');
  $query->fields('m_map_i', array('destid1'));
  $query->isNotNull('destid1');
  $query->orderBy("destid1", "ASC");
  $query->range(0, 5);
  $result = $query->execute()->fetchAll();
  return $result;
}

?>