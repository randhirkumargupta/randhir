<?php

/**
 * File provide poll widget funtionality.
 *
 * @param array $poll_data
 */
function save_poll_widget_data($poll_data) {
    $selected_node = $poll_data['selection'];
    $widget_name = 'poll_widget';
    // Delete entry first.
    
    $num_deleted = db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->execute();
    
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            $node_load_data = node_load($node);
            db_insert('itg_widget_order')
                    ->fields(array(
                        'nid' => $node,
                        'widget' => $widget_name,
                        'content_type' => $node_load_data->type,
                        //'extra' => $field_names[$node],
                        'weight' => 0,
                    ))
                    ->execute();
        }
        drupal_set_message(t("Nodes has been saved"));
    }
}
