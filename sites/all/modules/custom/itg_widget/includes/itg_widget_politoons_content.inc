<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function save_polittons_widget_data($politoons_form_state) {

  $selected_node = $politoons_form_state['selection'];
  $already_nodes = db_select('itg_widget_order', 'iwo')
                  ->fields('iwo')
                  ->condition('widget', 'politoons_widget')
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
            ->condition('widget', 'politoons_widget')
            ->execute();

    foreach ($new_data_to_insert as $key => $nodes) {
      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nodes['nid'],
                  'widget' => 'politoons_widget',
                  'content_type' => " ",
                  'cat_id' => 0,
                  'weight' => $nodes['nid'],
              ))->execute();
    }
  }
  else {
    foreach ($selected_node as $nodes) {
      // watchdog('widget', $nodes);
      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nodes,
                  'widget' => 'politoons_widget',
                  'content_type' => " ",
                  'cat_id' => 0,
                  'weight' => $nodes['nid'],
              ))->execute();
    }
  }
}
