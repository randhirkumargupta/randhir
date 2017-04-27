<?php

/**
 * @file
 * Widget file for specialauto review.
 *
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');

/**
 * Function to use insert data into custom table.
 *
 * @param array $auto_review_content
 */
function save_special_auto_review_widget_data($auto_review_content) {
  $selected_node = $auto_review_content['selection'];
  $widget_name = "special_auto_review_content";
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      itg_widget_delete_data_from_widget($widget_name, $node);
      itg_widget_insert_widget_data($node, $widget_name, $_GET['category_tid']);
    }
    drupal_set_message(t("Nodes has been saved."));
  }
}

/**
 * Funtion to get block data.
 *
 * @param array $info
 * @return array
 */
function itg_widget_auto_reviews_ordering_data($info) {
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
    $result = get_view_nodes_form_custom_table_for_spacila_auto_widgets($widget_name, 'auto_for_widget', DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE);
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
function itg_widget_tech_reviews_ordering_data($info) {
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
    global $theme;

    if (isset($_GET['section']) && !empty($_GET['section'])) {
      $selction_name = 'section';
    }
    else {
      $selction_name = 'section_name';
    }
    if (isset($_GET[$selction_name])) {
      $cat_id = $_GET[$selction_name];
    }
    if ($theme == FRONT_THEME_NAME) {
      $cat_id = arg(2);
    }
    $result = get_view_nodes_form_custom_table_review_widgets($widget_name, $cat_id, DONT_MISS_MAX_RANGE, DONT_MISS_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
  }
}
