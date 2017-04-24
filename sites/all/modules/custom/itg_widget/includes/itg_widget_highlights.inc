<?php

/**
 * @file
 * Provide functionality highlight widget.
 *
 */

/**
 *function used to save widget data.
 * 
 * @param array $poll_data
 */
function save_highlights_widget_data($highlights_data) {
  if ( empty($_GET['shs_term_node_tid_depth']) ) {
    drupal_set_message(t('Please select section') , 'error');
  }
  else {
    $selected_node = $highlights_data['selection'];
    $widget_name = 'highlights_widget';
    // Delete entry first.

    $num_deleted = db_delete('itg_widget_order')
        ->condition('widget' , $widget_name)
        ->condition('cat_id' , $_GET['shs_term_node_tid_depth'])
        ->execute();

    if ( count($selected_node) ) {
      foreach ($selected_node as $node) {
        try {
          $node_load_data = itg_widget_get_required_node_data_for_widget($node);
          db_insert('itg_widget_order')
              ->fields(array(
                'nid' => $node ,
                'widget' => $widget_name ,
                'content_type' => $node_load_data->type ,
                'cat_id' => itg_widget_get_category_for_db_insert($_GET['shs_term_node_tid_depth']) ,
                'weight' => 0 ,
              ))
              ->execute();
        }
        catch (Exception $ex) {
          drupal_set_message($ex->getMessage());
        }
      }
      drupal_set_message(t("Nodes has been saved"));
    }
  }
}
