<?php

/**
 * @file
 * home page feature ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_we_may_suggest_ordering_from_custom_table($info) {
  if (is_array($info)) {
    $widget_name = _get_widget_name(NULL, 'we_may_suggest_widget');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid'));
    $query->condition('iwo.widget', $widget_name);
    $query->condition('n.status', '1');
    $query->orderBy('iwo.weight');
    $query->range(0, 4);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
    return $entity_data;
  }
}

/**
 * Function to use insert data into custom table.
 *
 * @param array $dont_miss_content
 */
function save_we_may_suggest_widget_data($we_may_suggest_content) {
  $selected_node = $we_may_suggest_content['selection'];

  $already_nodes = db_select('itg_widget_order', 'iwo')
                  ->fields('iwo')
                  ->condition('widget', 'we_may_suggest_widget')
                  ->execute()->fetchAll(PDO::FETCH_ASSOC);
  $new_data_to_insert = array();
  // Check if there is any data in custom table
  if (count($already_nodes)) {

    foreach ($already_nodes as $table_nodes) {
      $new_data_to_insert[$table_nodes['nid']] = $table_nodes;
    }
    //pr($selected_node);

    foreach ($selected_node as $new_selected_node) {
      $new_data_to_insert[$new_selected_node]['nid'] = $new_selected_node;
    }

    $num = db_delete('itg_widget_order')
            ->condition('widget', 'we_may_suggest_widget')
            ->execute();

    foreach ($new_data_to_insert as $key => $nodes) {
      $node_data = node_load($nodes);
      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nodes['nid'],
                  'widget' => 'we_may_suggest_widget',
                  'content_type' => " ",
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
                  'nid' => $nodes,
                  'widget' => 'we_may_suggest_widget',
                  'content_type' => $node_data->type,
                  'cat_id' => 0,
                  'weight' => 0,
              ))->execute();
    }
  }
}
