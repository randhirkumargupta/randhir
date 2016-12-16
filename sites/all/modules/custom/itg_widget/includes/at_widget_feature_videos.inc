<?php

module_load_include('inc', 'itg_widget', 'itg_widget.helper');
/**
 * File provide aaj tak featured video funtionality.
 *
 * @param array $featured_videos
 */
function save_at_home_page_featured_videos_widget_data($featured_videos) {
  $selected_node = $featured_videos['selection'];
  $widget_name = "at_home_page_featured_videos_widget";
  if (!empty($selected_node)) {
    foreach ($selected_node as $node) {
      // Check if node exist then do nothing. else make entry.
      $is_node_exist = itg_widget_check_node_is_in_widget($node, $widget_name);
      if (!$is_node_exist) {
        $node_load_data = itg_widget_get_required_node_data_for_widget($node);
        // Delete node.
        db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->condition('nid', $node)
            ->execute();
        // Function to return maximum weight for widget.
        $max_weight = get_max_weight_for_special($widget_name);
        // Insert node in custom table
        db_insert('itg_widget_order')
            ->fields(array(
              'nid' => $node_load_data->nid,
              'widget' => $widget_name,
              //'cat_id' => $_GET['category_tid'],
              'content_type' => $node_load_data->type,
              //'extra' => $field_names[$node],
              'weight' => ++$max_weight,
            ))
            ->execute();
      }
    }
    drupal_set_message(t("Nodes has been saved"));
  }
}


function itg_widget_home_page_feature_vide_data($info) {
  if (is_array($info)) {
    $widget_name = $info['widget'];
    $result = get_view_nodes_form_custom_table_for_widgets($widget_name, AT_HOME_PAGE_FEATURE_VIDEO_MAX_RANGE, AT_HOME_PAGE_FEATURE_VIDEO_MIN_RANGE);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_info = get_required_data_from_entity_id($entity_data_node['nid']);
      $entity_data[] = $entity_info[$entity_data_node['nid']];
    }
  }
  return $entity_data;
}