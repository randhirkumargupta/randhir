<?php

/**
 * @file
 * Provide functionality for most read widget.
 *
 */
module_load_include('inc' , 'itg_widget' , 'itg_widget.helper');

/**
 * Function to use insert data into custom table.
 *
 * @param array $most_read_content
 */
function save_most_read_widget_data($most_read_content) {
  $selected_node = $most_read_content['selection'];
  $widget_name = "most_read_content";
  if ( count($selected_node) ) {
    foreach ($selected_node as $node) {
      itg_widget_delete_data_from_widget($widget_name , $node);
      itg_widget_insert_widget_data($node , $widget_name , $_GET['category_tid']);
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
function itg_widget_tech_most_read_ordering_data($info) {
  $data = '';
  global $theme;
  if ( !empty($info) ) {
    $widget_name = $info['widget_name'];
    $var_name = $info['query_var_name'];
    if ( isset($_GET['section']) && !empty($_GET['section']) ) {
      $selction_name = 'section';
    }
    else {
      $selction_name = 'section_name';
    }
    $cat_id = $_GET[$selction_name];
    if ( $theme == FRONT_THEME_NAME ) {
      $cat_id = arg(2);
    }

    $result = get_view_nodes_form_custom_table_for_spacila_auto_widgets($widget_name , $cat_id , 3 , 0);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
  }
}
