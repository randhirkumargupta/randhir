<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');

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
      // Get node count and skip to insert.
      $is_node_in_widget = itg_widget_check_node_in_widget($node, 'dont_miss_content_widget');
      if (!$is_node_in_widget) {
        itg_widget_insert_widget_data($node, $widget_name, 0);
      }
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
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE, 'ASC');
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
  }
}
