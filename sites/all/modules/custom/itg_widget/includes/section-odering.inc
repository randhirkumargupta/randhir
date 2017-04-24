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
function itg_widget_top_stories_ordering_data($info) {
  if (is_array($info)) {
    if (is_array($info)) {
      $widget_name = $info['widget'];
      $max_limit = $info['max_limit'];
      $min_limit = $info['min_limit'];
      $result = get_view_nodes_form_custom_table_for_widgets($widget_name, TOP_STORIES_LIMIT, TOP_STORIES_MIN_RANGE, 'ASC');
      $entity_data = array();
      foreach ($result as $entity_data_node) {
        //$entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
        $entity_data[] = $entity_data_node;
      }
      return $entity_data;
    }
  }
}
