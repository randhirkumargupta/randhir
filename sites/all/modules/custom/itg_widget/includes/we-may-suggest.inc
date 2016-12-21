<?php

/**
 * @file
 * home page feature ordering and reordering
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');
/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_we_may_suggest_ordering_from_custom_table($info) {
  if (is_array($info)) {
    $widget_name = _get_widget_name(NULL, 'we_may_suggest_widget');
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, MAY_WE_SUGGEST_MAX_RANGE, MAY_WE_SUGGEST_MIN_RANGE , 'ASC');
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      //$entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_data_node;
    }
    return $entity_data;
  }
}

/**
 * Function to use insert data into custom table.
 *
 * @param array $dont_miss_content
 */
function  save_we_may_suggest_widget_data($we_may_suggest_content) {
  $selected_node = $we_may_suggest_content['selection'];
  $widget_name = 'we_may_suggest_widget';
  itg_widget_delete_data_from_widget($widget_name);
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
          itg_widget_insert_widget_data($node, $widget_name, 0);
        }
        drupal_set_message(t("Nodes has been saved"));
    }
}
