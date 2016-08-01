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
function itg_widget_most_popular_ordering_data($info) {
  if (is_array($info)) {
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    if (!empty($view_name) && !empty($page)) {
      //$args_like = '{"nid":"","title":""}'; // this is for only top story widget
      $query = db_select('draggableviews_structure', 'dv_s');
      $query->fields('dv_s', array('entity_id'));
      $query->condition('dv_s.view_name', $view_name);
      //$query->condition('dv_s.args', '%' . db_like($args_like) . '%', 'LIKE');
      $query->condition('dv_s.view_display', $page);
      $query->orderBy('dv_s.weight', 'ASC');
      $query->groupBy('dv_s.entity_id');
      // only top 15 nodes are required as per requirement
      $query->range(0, 15);
      return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    }
  }
}
