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
  // watchdog("widget", "Delete action has been performed");
  // Get related nodes then convert into json.
  if ($_GET['type'] == 'story') {
    $select_node_load = node_load($selected_node);
    $related_content_string = $select_node_load->field_common_related_content['und'][0]['value'];
    $related_nodes_json = get_related_content_with_server_prefix($related_content_string);
  }
  // Get related nodes then convert into json.
  if ($_GET['type'] == 'breaking_news' || isset($big_story_data['values']['related_content'])) {
    $related_content_string = $big_story_data['values']['related_content'];
    $related_nodes_json = get_related_content_with_server_prefix($related_content_string);
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
 * Function to get nodeid's server.
 * 
 * @param string $related_content_string
 * @return json
 */
function get_related_content_with_server_prefix($related_content_string) {
  $relates_content_array_with_prefix = explode(",", $related_content_string);
  $temp_related_content_array = array();
  foreach ($relates_content_array_with_prefix as $key => $value) {
    $temp_related_exploded_array = explode('_', $value);
    $temp_related_content_array[] = array($temp_related_exploded_array[0] => $temp_related_exploded_array[1]);
  }
  return json_encode($temp_related_content_array);
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
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, 1, 0);
    foreach ($result as $entity_data_node) {
      $entity_data = array("node_data" => node_load($entity_data_node['nid']), "related" => $entity_data_node['extra']);
    }
    return $entity_data;
  }
}
