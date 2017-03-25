<?php

/**
 * @file
 * File provide poll widget functionality.
 *
 */

/**
 *function to save poll data.
 * 
 * @param array $poll_data
 */
function save_poll_widget_data($poll_data) {
    $selected_node = $poll_data['selection'];
    $widget_name = 'poll_widget';
    itg_widget_delete_data_from_widget($widget_name);
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            itg_widget_insert_widget_data($node , $widget_name , 0);
        }
        drupal_set_message(t("Nodes has been saved"));
    }
}
