<?php

/**
 * @file
 * Provide feature content section.
 *
 */
module_load_include('inc' , 'itg_widget' , 'itg_widget.helper');

/**
 * Function to use insert data into custom table.
 * @param array $feature_content
 */
function save_feature_content_section_widget_data($feature_content) {
  $selected_node = $feature_content['selection'];
  $widget_name = "feature_content_by_section";
  if ( count($selected_node) ) {
    foreach ($selected_node as $node) {
      itg_widget_delete_data_from_widget($widget_name , $node);
      itg_widget_insert_widget_data($node , $widget_name , $_GET['category_tid']);
    }
    drupal_set_message(t("Nodes has been saved"));
  }
}
