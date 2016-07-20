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
    $data = '';
    if (!empty($info)) {
        $content_type = $info['content_type'];
        $cat_id = $info['section'];
        $view_name = $info['view_name'];
        $widget_name = _get_widget_name($view_name);
        $result = db_select('itg_widget_order','iwo')
                ->fields('iwo',array('nid'))
                ->condition('iwo.cat_id',$cat_id)
                ->condition('iwo.content_type', $content_type)
                ->condition('iwo.widget', $widget_name)
                ->orderBy('iwo.weight')
                ->range(0,3)
                ->execute()->fetchAll(PDO::FETCH_ASSOC);
        $data = $result;
    }
    else {
        watchdog("Widget", "Data array is not in proper format");
    }
    return $data;
}
