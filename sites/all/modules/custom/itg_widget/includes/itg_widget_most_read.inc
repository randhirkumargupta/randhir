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
 * @param array $most_read_content
 */
function save_most_read_widget_data($most_read_content) {
    $selected_node = $most_read_content['selection'];
    $widget_name = "most_read_content";
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
                        'cat_id' => $_GET['category_tid'],
                        'content_type' => $node_load_data->type,
                        //'extra' => $field_names[$node],
                        'weight' => 0,
                    ))
                    ->execute();
        }
        drupal_set_message(t("Nodes has been saved"));
    }
}

/**
 * Funtion to get block data.
 *
 * @param array $info
 * @return array
 */
function itg_widget_tech_most_read_ordering_data($info) {
    $data = '';
    if (!empty($info)) {
        $widget_name = $info['widget_name'];
        $var_name = $info['query_var_name'];
        $result = get_view_nodes_form_custom_table_for_spacila_auto_widgets($widget_name, $var_name, 2, 0);
        $entity_data = array();
        foreach ($result as $entity_data_node) {
            $entity_data[] = array("node_load_data" => node_load($entity_data_node['nid']), "custom_label" => $entity_data_node['extra']);
        }
        return $entity_data;
    }
}
