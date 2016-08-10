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
function itg_widget_home_page_feature_data($info) {
  if (is_array($info)) {
    // watchdog('Widget', 'inside Home page feature query');
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    if (!empty($view_name) && !empty($page)) {
      $query = db_select('draggableviews_structure', 'dv_s');
      $query->leftJoin('node', 'n', 'n.nid=dv_s.entity_id');
      $query->fields('dv_s', array('entity_id'));
      $query->fields('n', array('title'));
      $query->condition('dv_s.view_name', $view_name);
      $query->condition('n.status', '1');
      //$query->condition('dv_s.args', '%' . db_like($args_like) . '%', 'LIKE');
      $query->condition('dv_s.view_display', $page);
      $query->orderBy('dv_s.weight', 'ASC');
      // only top 3 nodes are required as per requirement
      $query->range(0, 3);
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
      $entity_data = array();
      foreach ($result as $entity_data_node) {
        $entity_info = get_required_data_from_entity_id($entity_data_node['entity_id']);
        $entity_data[] = $entity_info[$entity_data_node['entity_id']];
      }
      return $entity_data;
    }
  }
}
