<?php

/**
 * File provide poll widget funtionality.
 *
 * @param array $poll_data
 */
function save_issue_magazin_widget_data($issue_data) {

    $selected_node = $issue_data['selection'];
    $widget_name = 'issue_magazin_widget';
   
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            $node_load_data = node_load($node);
            $num_deleted = db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->condition('nid', $node)
            ->execute();
            db_insert('itg_widget_order')
                    ->fields(array(
                        'nid' => $node,
                        'widget' => $widget_name,
                        'content_type' => $node_load_data->type,
                        'extra' => $_GET['field_story_issue_date_value']['value']['date'],
                        'weight' => 0,
                    ))
                    ->execute();
        }
        drupal_set_message(t("Nodes has been saved"));
        drupal_goto('issue-magazin-widget-list');
    }
}
