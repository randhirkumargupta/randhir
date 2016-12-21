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
function save_special_how_i_made_it_widget_data($auto_review_content) {
    $selected_node = $auto_review_content['selection'];
    $widget_name = "special_how_made_it_content";
    if (count($selected_node)) {
        foreach ($selected_node as $node) {
            try {
              $node_load_data = itg_widget_get_required_node_data_for_widget($node);
              $num_deleted = db_delete('itg_widget_order')
                      ->condition('widget', $widget_name)
                      ->condition('nid', $node)
                      ->execute();
            } catch (Exception $ex) {
              drupal_set_message($ex->getMessage());
            }
            $max_weight=get_max_weight_for_special($widget_name);

            try {
              db_insert('itg_widget_order')
                    ->fields(array(
                        'nid' => $node,
                        'widget' => $widget_name,
                        'cat_id' => itg_widget_get_category_for_db_insert($_GET['category_tid']),
                        'content_type' => $node_load_data->type,
                        //'extra' => $field_names[$node],
                        'weight' => ++$max_weight,
                    ))
                    ->execute();
            } catch (Exception $ex) {
              drupal_set_message($ex->getMessage());
            }
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
function itg_widget_how_made_it_ordering_data($info) {
    global $theme;
  $data = '';
  if (!empty($info)) {
    $widget_name = $info['widget_name'];
     if(isset($_GET['section']) && !empty($_GET['section']))
        {
            $selction_name='section';
        }else{
            $selction_name='section_name';
        }
       $cat_id = $_GET[$selction_name];
        if ($theme == FRONT_THEME_NAME) {
          $cat_id = arg(2);
         }
    $result = get_view_nodes_form_custom_table_for_widgets_special($widget_name,$cat_id, HOW_MADE_MAX_RANGE, HOW_MADE_MIN_RANGE);

    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = array("node_load_data" => node_load($entity_data_node['nid']), "custom_label" => $entity_data_node['extra']);
    }
    return $entity_data;
  }
}