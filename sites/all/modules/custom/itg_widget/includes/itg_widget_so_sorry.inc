<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Function to use insert data into custom table.
 *
 * @param array $dont_miss_content
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
      else if (is_null($nodes['weight']) || $nodes['weight'] == "") {
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

/**
 * function to sent block data for politoons for sosorry page.
 * @return array
 */
function itg_widget_so_sorry_politoons_ordering_data() {
  $block_data = array();

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('itg_category_manager', 'icm', 'icm.tid=iwo.nid');
  $query->addField('iwo', 'nid');
  $query->condition('iwo.widget', 'politoons_widget');
  $query->condition('icm.status', 1);
  $query->range(0, 6);
  $query->orderBy('iwo.weight');

  $result = $query->execute()->fetchAll();

  foreach ($result as $taxonomy) {
    $term_data = array();
    $term_data = taxonomy_term_load($taxonomy->nid);
    $block_data[] = array(
        'title' => $term_data->name,
        'uri' => $term_data->field_sponser_logo['und'][0]['uri'],
        'term_id' => $term_data->tid,
    );
  }

  return $block_data;
}

?>
