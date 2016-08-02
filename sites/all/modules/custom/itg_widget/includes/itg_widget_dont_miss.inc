<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Function to use insert data into custom table.
 *
 * @param array $dont_miss_content
 */
function save_dont_miss_widget_data($dont_miss_content) {
  $selected_node = $dont_miss_content['selection'];
  $widget_name = _get_widget_name(' ', "dont_miss_content");
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      $node_load_data = node_load($node);
      db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $node,
          'widget' => $widget_name,
          'content_type' => $node_load_data->type,
          //'extra' => $field_names[$node],
          'weight' => 0,
        ))
        ->execute();
    }
    drupal_set_message(t("Nodes has been saved"));
  }
}

/**
 * Funtion to get block data.
 *
 * @param array $info
 * @return array
 */
function itg_widget_dont_miss_ordering_data($info) {
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
    $result = db_select('itg_widget_order', 'iwo')
      ->fields('iwo', array('nid', 'extra', 'weight'))
      ->condition('iwo.widget', $widget_name)
      ->orderBy('iwo.weight', 'ASC')
      ->range(0, 4)
      ->execute()->fetchAll(PDO::FETCH_ASSOC);
    $data = $result;
  }
  else {
    // watchdog("Widget", "Data array is not in proper format");
  }
  return $data;
}
