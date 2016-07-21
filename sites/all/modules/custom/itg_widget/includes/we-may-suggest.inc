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
function itg_widget_we_may_suggest_data($info) {
    $data = '';
    if (!empty($info)) {
        watchdog('Widget', 'we may suggest widget query');
        $section_tid = isset($info['section']) ? $info['section'] : "";
        $content_type = isset($info['content_type']) ? $info['content_type'] : "";
        $view_name = isset($info['view_name']) ? $info['view_name'] : "";
        $section_field_name = isset($info['section_field_name']) ? $info['section_field_name'] : "";
        if (!empty($section_tid) && !empty($content_type) && !empty($view_name)) {
            $args_like = '"field_story_category_tid":"' . $section_tid . '","type":"' . $content_type . '"';
            $query = db_select('draggableviews_structure', 'dv_s');
            $query->fields('dv_s', array('entity_id'));
            $query->condition('dv_s.view_name', $view_name);
            $query->condition('dv_s.args', '%' . db_like($args_like) . '%', 'LIKE');
            $query->orderBy('dv_s.weight', 'ASC');
            // only top 3 nodes are required as per requirement
            $query->range(0, 10);
            $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
            $data = $result;
        }
        else {
            watchdog('Widget', 'Content type or section empty we may suggest');
        }
    }
    else {
        watchdog("Widget", "Data array is not in proper format");
    }
    return $data;
}
