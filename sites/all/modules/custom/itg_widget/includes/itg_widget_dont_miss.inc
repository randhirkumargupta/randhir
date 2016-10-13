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
      //$node_load_data = node_load($node);
      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $node,
                  'widget' => $widget_name,
                  'content_type' => " ",
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
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE,'ASC');
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = array("node_load_data" => node_load($entity_data_node['nid']), "custom_label" => $entity_data_node['extra']);
    }
    return $entity_data;
  }
}
