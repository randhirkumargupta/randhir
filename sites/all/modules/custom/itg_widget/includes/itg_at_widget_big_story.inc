<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Function to get block data into array.
 * @param array $info
 * @return array
 */
function itg_at_widget_big_story_block_data($info) {
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

/**
 * File provide big sotry funtionality.
 *
 * @param array $big_story_data
 */
function save_at_big_story_widget_data($big_story_data) {
  module_load_include('inc', 'itg_widget', 'includes/itg_widget_big_story');
  $widget = 'at_big_story_format_widget';
  $content_type = isset($_GET['type']) ? $_GET['type'] : "breaking_news";
  $selected_node = $big_story_data['selection'][0];
  $related_nodes_json = '[]';
  // Delete entry first.
  db_delete('itg_widget_order')
      ->condition('widget', $widget)
      ->execute();
  // watchdog("widget", "Delete action has been performed");
  // Get related nodes then convert into json.
  if ($_GET['type'] == 'story' || $_GET['type'] == 'photogallery' || $_GET['type'] == 'videogallery') {
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
  db_insert('itg_widget_order')
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
