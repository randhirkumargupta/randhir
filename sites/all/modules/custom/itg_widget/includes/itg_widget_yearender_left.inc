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
 * @param array $auto_review_content
 */
function save_yearender_left_widget_data($yearender_left) {
  $selected_node = $yearender_left['selection'];
  $widget_name = "yearender_left_news_video";
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      $node_load_data = node_load($node);
      $num_deleted = db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->condition('nid', $node)
            ->execute();
                   $max_weight=get_max_weight_for_special($widget_name);

      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $node,
                  'widget' => $widget_name,
                  'content_type' => $node_load_data->type,
                  //'extra' => $field_names[$node],
                  'weight' => ++$max_weight,
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
function itg_widget_yearend_top_news_ordering_data($info) {
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
    $result = get_view_nodes_form_custom_table_for_yearend_widgets($widget_name,'story', 5, DONT_MISS_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = array("node_load_data" => node_load($entity_data_node['nid']), "custom_label" => $entity_data_node['extra']);
    }
    return $entity_data;
  }
}

/**
 * Funtion to get block data.
 *
 * @param array $info
 * @return array
 */
function itg_widget_yearend_top_videos_ordering_data($info) {
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
    $result = get_view_nodes_form_custom_table_for_yearend_widgets($widget_name,'videogallery', DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = array("node_load_data" => node_load($entity_data_node['nid']), "custom_label" => $entity_data_node['extra']);
    }
    return $entity_data;
  }
}
