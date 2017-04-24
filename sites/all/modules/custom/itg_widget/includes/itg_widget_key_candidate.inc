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
 * @param array $auto_review_content
 */
function save_key_candidate_data($auto_review_content) {

  $selected_node = $auto_review_content['selection'];
  if ( $_GET['cat_id'] == 'all' ) {
    drupal_set_message(t('Node not added Select state') , 'error');
  }
  else {
    $widget_name = "key_candidate";
    $cat_id = $_GET['cat_id'];
    if ( count($selected_node) ) {
      foreach ($_GET['state_val'] as $key => $val) {
        foreach ($selected_node as $node) {
          $node_load_data = itg_widget_get_required_node_data_for_widget($node);
          itg_widget_delete_data_from_widget($widget_name , $node , $val , $cat_id);
          itg_widget_insert_widget_data($node , $widget_name , $cat_id , NULL , $val);
        }
      }
      drupal_set_message(t("Nodes has been saved"));
    }
  }
}
