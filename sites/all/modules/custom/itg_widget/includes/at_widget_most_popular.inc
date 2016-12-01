<?php

/**
 * File provide poll widget funtionality.
 *
 * @param array $poll_data
 */
function save_at_widget_most_popular_widget_data($popular_data) {

    $selected_node = $popular_data['selection'];
    $widget_name = 'at_widget_most_popular_widget';
    
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            $node_load_data = node_load($node);
            $already_nodes = db_select('itg_widget_order', 'iwo')
                            ->fields('iwo')
                            ->condition('widget', 'at_widget_most_popular_widget')
                            ->condition('nid', $node)
                            ->execute()->fetchAll(PDO::FETCH_ASSOC);
            if (empty($already_nodes)) {
                $insert=db_insert('itg_widget_order')
                        ->fields(array(
                            'nid' => $node,
                            'widget' => $widget_name,
                            'cat_id' => $_GET['category_tid'],
                             'content_type' => $node_load_data->type,
                            'extra' => $_GET['field_story_issue_date_value']['value']['date'],
                            'weight' => 0,
                        ))
                        ->execute();
            }
        }
        if($insert)
        {
        drupal_set_message(t("Nodes has been saved"));
        } else {
     drupal_set_message(t("Nodes has not saved"), 'error');
        }
        // drupal_goto('issue-magazin-widget-list');
    }
}
