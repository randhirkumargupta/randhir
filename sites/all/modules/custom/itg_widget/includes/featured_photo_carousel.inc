<?php
/**
 * @file
 * home page feature ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 * @param string $slider_type
 * @return array
 */
function itg_widget_featured_photo_carousel_data($info, $slider_type) {
  $data = '';
  if (is_array($info)) {
    watchdog('Widget', 'inside Home page feature query');
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    // condition to validate
    if (!empty($view_name) && !empty($page)) {
      $query = db_select('draggableviews_structure', 'dv_s');
      $query->fields('dv_s', array('entity_id'));
      $query->condition('dv_s.view_name', $view_name);
      $query->condition('dv_s.view_display', $page);
      $query->orderBy('dv_s.weight', 'ASC');
      // only top 5 nodes are required as per requirement
      // TODO: Add values to Variables and create config file. Widget settings.
      $query->range(0, 5);
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
      $actual_result = itg_widget_featured_photo_carousel_data_fetch($result, $slider_type);
      return $actual_result;
    }
    else {
      watchdog('Widget', 'Either section or content type is empty');
    }
  }
  else {
    watchdog('Widget', 'view_name and page name is empty');
  }
  return $data;
}


/**
 * @param array $result
 * @param string $slider_type
 * @return array
 */
function itg_widget_featured_photo_carousel_data_fetch($result, $slider_type) {
  $data_render = array();
  global $base_url;
  $style = '';
  if ($slider_type == 'flexslider') {
    $style = 'photo_carousel_flexslider';
  }
  if ($slider_type == 'rolling') {
    $style = 'photo_carousel_rollingslider';
  }

  foreach ($result as $key => $data) {
    $node = node_load($data['entity_id']);
    $data_render[$data['entity_id']]['file_url'] = theme('image_style', array('style_name' => $style, 'path' => $node->field_story_extra_large_image[$node->language][0]['uri']));
    $data_render[$data['entity_id']]['count'] = count($node->field_gallery_image[$node->language]);
    $data_render[$data['entity_id']]['caption'] = $node->field_story_extra_large_image[$node->language][0]['title'];
    $data_render[$data['entity_id']]['node_url'] = $base_url . '/' . drupal_get_path_alias('node/' . $data['entity_id']);
  }
  return $data_render;
}