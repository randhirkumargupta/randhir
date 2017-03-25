<?php

/**
 * @file
 * Provide save function for dont miss widget.
 *
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
