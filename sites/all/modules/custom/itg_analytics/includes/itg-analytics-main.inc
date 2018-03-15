<?php

/**
 * Implements itg_update_analytics_node_count_data().
 *  Function is responsible to updating analytics data into table.
 */
function itg_update_analytics_node_count_data() {

  $most_popular_nodes = _get_most_popular_nodes_based_on_analytics();
  // Frist delete all the data from table.
  try {
    db_delete('itg_node_analytics_count_data')
        ->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage(), 'error');
  }
  // Insert node and analytics data into table.
  foreach ($most_popular_nodes as $node => $weight) {
    try {
      db_insert('itg_node_analytics_count_data')
          ->fields(array(
            'nid' => $node,
            'count' => $weight,
          ))
          ->execute();
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage());
    }
  }
}