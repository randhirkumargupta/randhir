<?php

/**
 * @file
 * Main file yearend widget.
 *
 */
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
      
      //itg_widget_delete_data_from_widget($widget_name, $node,"",$_GET['tid']);
     // itg_widget_insert_widget_data($node, $widget_name, $_GET['tid']);
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
    $result = get_view_nodes_form_custom_table_for_yearend_widgets($widget_name , 'story' , 5 , DONT_MISS_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
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
    $result = get_view_nodes_form_custom_table_for_yearend_widgets($widget_name , 'videogallery' , DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
  }
}
