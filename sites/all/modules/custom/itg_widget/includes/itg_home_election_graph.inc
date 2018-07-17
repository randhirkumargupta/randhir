<?php

/**
 * @file
 * Provide functionality for most read widget.
 *
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');

/**
 * Function to use insert data into custom table.
 *
 * @param array $most_read_content
 */
function save_home_election_widget_data($home_election_content) {
  $selected_node = $home_election_content['selection'];
  $widget_name = "election_graph_content";
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      itg_widget_delete_data_from_widget($widget_name, $node);
      itg_widget_insert_widget_data($node, $widget_name, 0);
    }
    itg_widget_delete_old_data_by_limit($widget_name);
  }
}
