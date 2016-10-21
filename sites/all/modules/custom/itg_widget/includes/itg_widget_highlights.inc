<?php

/**
 * File provide poll widget funtionality.
 *
 * @param array $poll_data
 */
function save_highlights_widget_data($highlights_data) {
 if(empty($_GET['shs_term_node_tid_depth']))
 {
     drupal_set_message('Please select section');
 }else{
    $selected_node = $highlights_data['selection'];
    $widget_name = 'highlights_widget';
    // Delete entry first.
    
    $num_deleted = db_delete('itg_widget_order')
            ->condition('widget', $widget_name)
            ->condition('cat_id', $_GET['shs_term_node_tid_depth'])
            ->execute();
    
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            $node_load_data = node_load($node);
            db_insert('itg_widget_order')
                    ->fields(array(
                        'nid' => $node,
                        'widget' => $widget_name,
                        'content_type' => $node_load_data->type,
                         'cat_id' => $_GET['shs_term_node_tid_depth'],
                        'weight' => 0,
                    ))
                    ->execute();
        }
        drupal_set_message(t("Nodes has been saved"));
    }
 }
}

