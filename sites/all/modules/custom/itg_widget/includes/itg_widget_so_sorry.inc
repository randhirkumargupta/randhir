<?php

/**
 * @file
 * Widget file for sosorry.
 *
 */

/**
 * function to sent block data for politoons for sosorry page.
 * @return array
 */
function itg_widget_so_sorry_politoons_ordering_data() {
  $block_data = array();
  $result = views_get_view_result('so_sorry_politoons', 'so_sorry_politoons');
  foreach ($result as $taxonomy) {
    $uri = itg_widget_get_logo_from_tid($taxonomy->taxonomy_term_data_itg_category_manager_tid);
    $block_data[] = array(
      'title' => $taxonomy->taxonomy_term_data_itg_category_manager_name,
      'uri' => $uri[0],
      'term_id' => $taxonomy->taxonomy_term_data_itg_category_manager_tid,
    );
  }
  return $block_data;
}

/**
 * Function to get uri from tid of logo field.
 * @param int $tid
 * @return array
 */
function itg_widget_get_logo_from_tid($tid) {
  $query = db_select('field_data_field_sponser_logo', 'logo');
  $query->leftJoin('file_managed', 'fm', 'fm.fid = logo.field_sponser_logo_fid');
  $query->fields('fm', array('uri'));
  $query->condition('logo.entity_id', $tid);
  $uri = $query->execute()->fetchCol();
  return $uri;
}

/**
 * Function to save sosorry widget data in custom table.
 * 
 * @param array $so_sorry_selected_content
 */
function save_so_sorry_widget_data($so_sorry_selected_content) {
  $selected_node = $so_sorry_selected_content['selection'];
  $already_nodes = db_select('itg_widget_order', 'iwo')
          ->fields('iwo')
          ->condition('widget', 'so_sorry_widget')
          ->execute()->fetchAll(PDO::FETCH_ASSOC);
  $new_data_to_insert = array();
  // Check if there is any data in custom table
  if (count($already_nodes)) {

    foreach ($already_nodes as $table_nodes) {
      $new_data_to_insert[$table_nodes['nid']] = $table_nodes;
    }

    foreach ($selected_node as $new_selected_node) {
      $new_data_to_insert[$new_selected_node]['nid'] = $new_selected_node;
    }

    $num = db_delete('itg_widget_order')
        ->condition('widget', 'so_sorry_widget')
        ->execute();

    foreach ($new_data_to_insert as $key => $nodes) {

      $node_weight = $nodes['nid'];
      if ($nodes['weight'] == 0 && isset($nodes['weight'])) {
        $node_weight = 0;
      }
      elseif (is_null($nodes['weight']) || $nodes['weight'] == "") {
        $node_weight = $nodes['nid'];
      }
      else {
        $node_weight = $nodes['weight'];
      }

      db_insert('itg_widget_order')
          ->fields(array(
            'nid' => $nodes['nid'],
            'widget' => 'so_sorry_widget',
            'content_type' => " ",
            'cat_id' => 0,
            'weight' => $node_weight,
            'extra' => ($nodes['extra']) ? $nodes['extra'] : "",
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
            'widget' => 'so_sorry_widget',
            'content_type' => $node_data->type,
            'cat_id' => 0,
            'weight' => $node_data->nid,
            'extra' => "",
          ))->execute();
    }
  }
}
