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
function itg_widget_home_page_feature_data($info) {
  if (is_array($info)) {
    // watchdog('Widget', 'inside Home page feature query');
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    if (!empty($view_name) && !empty($page)) {
      $result = draggable_views_nodes_for_widgets($view_name, $page, "NOT", HOME_PAGE_FEATURE_MIN_RANGE, HOME_PAGE_FEATURE_MAX_RANGE);
      if (empty($result)) {
        $nodequeue_name = isset($info['nodequeue']) ? $info['nodequeue'] : "";
        $result = itg_widget_nodes_from_nodequeue($nodequeue_name, TRUE, HOME_PAGE_FEATURE_MIN_RANGE, HOME_PAGE_FEATURE_MAX_RANGE);
      }
      $entity_data = array();
      foreach ($result as $entity_data_node) {
        //$entity_info = get_required_data_from_entity_id($entity_data_node['entity_id']);
        $entity_data[] = $entity_data_node;
      }
      return $entity_data;
    }
  }
}
