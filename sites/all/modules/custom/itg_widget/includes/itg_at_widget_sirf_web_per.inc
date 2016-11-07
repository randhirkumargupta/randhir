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
 * @param array $feature_content
 */
function save_sirf_web_per_widget_content($feature_content) {
  $selected_node = $feature_content['selection'];
  $already_nodes = db_select('itg_widget_order', 'iwo')
          ->fields('iwo')
          ->condition('widget', 'at_sirf_web_per_widget')
          ->execute()->fetchAll(PDO::FETCH_ASSOC);
  $new_data_to_insert = array();
  // Check if there is any data in custom table
  if (count($already_nodes)) {

    foreach ($already_nodes as $table_nodes) {
      $new_data_to_insert[$table_nodes['nid']] = $table_nodes;
    }

    foreach ($selected_node as $new_selected_node) {
      $new_data_to_insert[$new_selected_node]['nid'] = $new_selected_node;
    }

    db_delete('itg_widget_order')
        ->condition('widget', 'at_sirf_web_per_widget')
        ->execute();

    foreach ($new_data_to_insert as $key => $nodes) {
      $node_data = node_load($nodes['nid']);
      db_insert('itg_widget_order')
          ->fields(array(
            'nid' => $node_data->nid,
            'widget' => 'at_sirf_web_per_widget',
            'content_type' => $node_data->type,
            'cat_id' => 0,
            'weight' => 0,
          ))->execute();
    }
  }
  else {
    foreach ($selected_node as $nodes) {
      $node_data = node_load($nodes);
      // watchdog('widget', $nodes);
      db_insert('itg_widget_order')
          ->fields(array(
            'nid' => $node_data->nid,
            'widget' => 'at_sirf_web_per_widget',
            'content_type' => $node_data->type,
            'cat_id' => 0,
            'weight' => 0,
          ))->execute();
    }
  }
}

function itg_widget_sirf_web_per_data($info) {
  if (is_array($info)) {
    $widget_name = $info['widget'];
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, SIRF_WEB_PER_MAX_RANGE, SIRF_WEB_PER_MIN_RANGE, 'ASC');
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
  }
  return $entity_data;
}
