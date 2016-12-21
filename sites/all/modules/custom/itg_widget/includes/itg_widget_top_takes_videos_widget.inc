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
function itg_widget_top_takes_videos_widget_ordering_data($info) {
  if (is_array($info)) {
    $result = array();
    $view_name = isset($info['view_name']) ? $info['view_name'] : "";
    $page = isset($info['page']) ? $info['page'] : "";
    if (!empty($view_name) && !empty($page)) {
      $top_takes_videos = draggable_views_nodes_for_widgets($view_name, $page, "NOT", TOP_TAKES_MIN_RANGE, TOP_TAKES_MAX_RANGE);
      if (empty($top_takes_videos)) {
        $nodequeue_name = isset($info['nodequeue']) ? $info['nodequeue'] : "";
        $top_takes_videos = itg_widget_nodes_from_nodequeue($nodequeue_name , TRUE , TOP_TAKES_MIN_RANGE, TOP_TAKES_MAX_RANGE);
      }
      foreach ($top_takes_videos as $video) {
        /*$video_entity_id = $video['entity_id'];
        $temp_result = array();
        $temp_result = get_required_data_from_entity_id($video_entity_id);*/
        $result[] = $video;
      }
      return $result;
    }
  }
}
