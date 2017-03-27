<?php

/**
 * @file
 * Main file for magazin widget.
 */

/**
 *Function for save magazine widget.
 * @param array $poll_data
 */
function save_issue_magazin_widget_data($issue_data) {

    $selected_node = $issue_data['selection'];
    $widget_name = 'issue_magazin_widget';
   
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
          itg_widget_delete_data_from_widget($widget_name, $node);
          itg_widget_insert_widget_data($node, $widget_name, $category_tid , $_GET['field_story_issue_date_value']['value']['date']);
        }
        drupal_set_message(t("Nodes has been saved"));
    }
}
