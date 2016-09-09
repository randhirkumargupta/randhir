<?php

/**
 * @file
 *      Section and top stories widegt ordering and reordering
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');
/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 *      section is tid of category and content type machine name will be use
 *
 * @return array
 */
function itg_widget_most_popular_ordering_data($info) {
  if (is_array($info)) {
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    if (!empty($view_name) && !empty($page)) {
      $result = draggable_views_nodes_for_widgets($view_name, $page, "NOT", MOST_POPULAR_MIN_RANGE, MOST_POPULAR_MAX_RANGE);
      if (empty($result)) {
        $nodequeue_name = isset($info['nodequeue']) ? $info['nodequeue'] : "";
        $result = itg_widget_nodes_from_nodequeue($nodequeue_name , FALSE , MOST_POPULAR_MIN_RANGE, MOST_POPULAR_MAX_RANGE);
      }
      $entity_data = array();
      foreach ($result as $entity_data_node) {
        $entity_info = get_required_data_from_entity_id($entity_data_node['entity_id']);
        $entity_data[] = $entity_info[$entity_data_node['entity_id']];
      }
      return $entity_data;
    }
  }
}
