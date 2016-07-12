<?php

/**
 * @file
 *      Section and top stories widegt ordering and reordering
 */

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * 
 * @param array $info
 *      section is tid of category and content type machine name will be use for making the unique combination
 * 
 * @return array
 */
function itg_widget_section_ordering_data($info) {
    $data = '';
    if (!empty($info)) {
        watchdog('section ordering', 'inside section ordering');
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
            $query->range(0, 3);
            $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
            $data = $result;
        }
        else {
            watchdog('section ordering', 'Either section or content type is empty');
        }
    }
    else {
        
    }
    return $data;
}

/**
 * function to get data of nodes in sequence which is saved in draggableviews_structure table
 * @param array $info
 *      section is tid of category and content type machine name will be use
 * 
 * @return array
 */
function itg_widget_top_stories_ordering_data($info) {
    $data = '';
    if (!empty($info)) {
        watchdog('Top Stories ordering', 'inside top stories ordering');
        $view_name = isset($info['view_name']) ? $info['view_name'] : "";
        $page = isset($info['page']) ? $info['page'] : "";
        // condition to validate
        if (!empty($view_name) && !empty($page)) {
            $arg_like = '{"nid":"","title":""}'; // this is for only top story widget
            $query = db_select('draggableviews_structure', 'dv_s');
            $query->fields('dv_s', array('entity_id'));
            $query->condition('dv_s.view_name', $view_name);
            $query->condition('dv_s.args', '%' . db_like($args_like) . '%', 'LIKE');
            $query->condition('dv_s.view_display', $page);
            $query->orderBy('dv_s.weight', 'ASC');
            $query->groupBy('dv_s.entity_id');
            // only top 15 nodes are required as per requirement
            $query->range(0, 15);
            $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
            $data = $result;
        }
        else {
            watchdog('Top Stories ordering', 'Either section or content type is empty');
        }
    }
    else {
        watchdog('Top Stories ordering', 'view_name and page name is empty');
    }
    return $data;
}
