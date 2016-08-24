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
      $query = db_select('draggableviews_structure', 'dv_s');
      $query->leftJoin('node', 'n', 'n.nid=dv_s.entity_id');
      $query->leftJoin('field_data_field_story_expiry_date', 'fsed', 'fsed.entity_id=n.nid');
      $query->fields('dv_s', array('entity_id'));
      $query->fields('fsed', array('field_story_expiry_date_value'));
      $query->condition('dv_s.view_name', $view_name);
      $query->condition('dv_s.view_display', $page);
      $query->condition('n.status', '1');
      $query->condition('fsed.field_story_expiry_date_value', $today, '>=');
      //$query->condition('fsed.') //DATE_FORMAT(field_data_field_story_expiry_date.field_story_expiry_date_value, '%Y-%m-%d') = '') )
      $query->orderBy('dv_s.weight', 'ASC');
      $query->groupBy('dv_s.entity_id');
      // only top 15 nodes are required as per requirement
      $query->range(0, 15);
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
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
