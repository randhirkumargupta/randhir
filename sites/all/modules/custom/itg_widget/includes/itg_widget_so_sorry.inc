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
  $widget_name = 'so_sorry_widget';
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      // Get node count and skip to insert.
      $is_node_in_widget = itg_widget_check_node_in_widget($node, 'so_sorry_widget');
      if (!$is_node_in_widget) {
        itg_widget_insert_widget_data($node, $widget_name, 0);
      }
    }
    drupal_set_message(t("Nodes has been saved"));
  }
}
