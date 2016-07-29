<?php

/**
 * @file
 * home page feature ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_from_custom_table($info) {
  if (is_array($info)) {
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    return db_select('itg_widget_order', 'iwo')
      ->fields('iwo', array('nid'))
      ->condition('iwo.cat_id', $cat_id)
      // fix for getting all content type
      ->condition('iwo.widget', $widget_name)
      ->orderBy('iwo.weight')
      ->range(0, 3)
      ->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
  else {
    watchdog("Widget", "Data array is not in proper format");
  }
}
