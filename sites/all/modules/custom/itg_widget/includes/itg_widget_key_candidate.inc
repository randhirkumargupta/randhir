<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
module_load_include('inc', 'itg_widget', 'itg_widget.helper');

/**
 * Function to use insert data into custom table.
 *
 * @param array $auto_review_content
 */
function save_key_candidate_data($auto_review_content) {

    $selected_node = $auto_review_content['selection'];
    if($_GET['cat_id']=='all')
    {
         drupal_set_message(t('Node not added Select state'), 'error');
    } else {
    $widget_name = "key_candidate";
    $cat_id=$_GET['cat_id'];
    if (count($selected_node)) {
        foreach ($_GET['state_val'] as $key=>$val)
        {
        foreach ($selected_node as $node) {
            $node_load_data = node_load($node);
            $num_deleted = db_delete('itg_widget_order')
                    ->condition('widget', $widget_name)
                    ->condition('nid', $node)
                    ->condition('cat_id',$cat_id)
                    ->condition('state',$key)
                    ->execute();
                        $max_weight=get_max_weight_for_special($widget_name);

            db_insert('itg_widget_order')
                    ->fields(array(
                        'nid' => $node,
                        'widget' => $widget_name,
                        'cat_id' => $cat_id,
                        'content_type' => $node_load_data->type,
                        'state' => $key,
                        'weight' => ++$max_weight,
                    ))
                    ->execute();
        }
        }
        drupal_set_message(t("Nodes has been saved"));
    }
    }
}

