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
function itg_widget_watch_right_now_videos_widget_ordering_data($info) {
  if (is_array($info)) {
    $result = array();
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    if (!empty($view_name) && !empty($page)) {
      $query = db_select('draggableviews_structure', 'dv_s');
      $query->fields('dv_s', array('entity_id'));
      $query->condition('dv_s.view_name', $view_name);
      $query->condition('dv_s.view_display', $page);
      $query->orderBy('dv_s.weight', 'ASC');
      $query->groupBy('dv_s.entity_id');
      $query->range(0, 4);
      $watch_right_now_videos =  $query->execute()->fetchAll(PDO::FETCH_ASSOC);
      foreach($watch_right_now_videos as $video) {
        $video_entity_id = $video['entity_id'];
        $temp_result = array();
        $temp_result = get_required_data_from_entity_id($video_entity_id);
        $result[] = $temp_result[$video_entity_id];
      }
      return $result;
    }
  }
}
