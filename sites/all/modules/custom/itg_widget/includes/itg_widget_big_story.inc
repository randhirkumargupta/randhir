<?php

/**
 * File provide big sotry funtionality.
 *
 * @param array $big_story_data
 */
function save_big_story_widget_data($big_story_data) {
  $widget = 'big_story_format_widget';
  $content_type = isset($_GET['type']) ? $_GET['type'] : "breaking_news";
  $selected_node = $big_story_data['selection'][0];
  $related_nodes_json = '[]';
  // Delete entry first.
  $num_deleted = db_delete('itg_widget_order')
    ->condition('widget', $widget)
    ->execute();
  if ($num_deleted) {
    watchdog("widget", "Delete action has been performed");
  }
  // Get related nodes then convert into json.
  if ($_GET['type'] == 'story') {
    $select_node_load = node_load($selected_node);
    $related_content_string = $select_node_load->field_common_related_content['und'][0]['value'];
    $relates_content_array_with_prefix = explode(",", $related_content_string);
    $temp_related_content_array = array();
    foreach ($relates_content_array_with_prefix as $key => $value) {
      $temp_related_exploded_array = explode('_', $value);
      $temp_related_content_array[] = $temp_related_exploded_array[1];
    }
    $related_nodes_json = json_encode($temp_related_content_array);
  }
  // Get related nodes then convert into json.
  if ($_GET['type'] == 'breaking_news') {
    $related_content = $big_story_data['values']['related_content'];
    $related_nodes = explode(',', $related_content);
    $related_nodes_json = json_encode($related_nodes);
  }
  // Insert into table.
  $query = db_insert('itg_widget_order')
    ->fields(array(
      'nid' => $selected_node,
      'widget' => $widget,
      'content_type' => $content_type,
      'cat_id' => 0,
      'weight' => 0,
      'extra' => $related_nodes_json,
    ))
    ->execute();
}

/**
 * Function to get block data into array.
 * @param array $info
 * @return array
 */
function itg_widget_big_story_block_data($info) {
  $widget_name = isset($info['widget']) ? $info['widget'] : "";
  $data = array();
  if (!empty($widget_name)) {
    $query = db_select('itg_widget_order', 'iwo')
      ->condition('iwo.widget', $widget_name)
      ->fields('iwo', array('nid', 'extra'))
      ->execute()->fetchAll(PDO::FETCH_ASSOC);
    $data = $query;
  }
  return $data;
}