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
function itg_widget_section_wise_ordering_from_custom_table($info) {
  if (is_array($info)) {
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid'))
            ->condition('iwo.cat_id', $cat_id)
            // fix for getting all content type
            ->condition('iwo.widget', $widget_name)
            ->condition('n.status', '1')
            ->orderBy('iwo.weight')
            ->range(0, 3);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
    return $entity_data;
  }
}
/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @return array
 */
function itg_widget_section_wise_ordering_for_rhs_from_custom_table($info) {
  if (is_array($info)) {
    $cat_id = $info['section'];
    $view_name = $info['view_name'];
    $widget_name = _get_widget_name($view_name, 'page');
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->fields('iwo', array('nid'))
            ->condition('iwo.cat_id', $cat_id)
            // fix for getting all content type
            ->condition('iwo.widget', $widget_name)
            ->condition('n.status', '1')
            ->orderBy('iwo.weight')
            ->range(0, 5);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
    return $entity_data;
  }
}
