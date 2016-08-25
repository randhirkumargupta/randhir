<?php

/**
 * @file
 *      Section and top stories widegt ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 *      section is tid of category and content type machine name will be use
 *
 * @return array
 */
function itg_widget_top_stories_ordering_data($info) {
  if (is_array($info)) {
    // watchdog('Top Stories ordering', 'inside top stories ordering');
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    $today = date('Y-m-d 00:00:00');
    if (!empty($view_name) && !empty($page)) {
      $result = draggable_views_nodes_for_widgets($view_name, $page, $today, 0, TOP_STORIES_LIMIT);
      if (empty($result)) {
        $nodequeue_name = isset($info['nodequeue']) ? $info['nodequeue'] : "";
        $result = itg_widget_nodes_from_nodequeue($nodequeue_name);
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
