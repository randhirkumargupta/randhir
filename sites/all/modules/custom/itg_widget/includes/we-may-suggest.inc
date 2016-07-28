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
function itg_widget_we_may_suggest_ordering_from_custom_table($info) {
    $data = '';
    if (!empty($info)) {
        $widget_name = _get_widget_name(NULL, 'we_may_suggest_widget');
        $result = db_select('itg_widget_order', 'iwo')
                        ->fields('iwo', array('nid'))
                        ->condition('iwo.widget', $widget_name)
                        ->orderBy('iwo.weight')
                        ->range(0, 4)
                        ->execute()->fetchAll(PDO::FETCH_ASSOC);
        $data = $result;
    }
    else {
        watchdog("Widget", "Data array is not in proper format");
    }
    return $data;
}
