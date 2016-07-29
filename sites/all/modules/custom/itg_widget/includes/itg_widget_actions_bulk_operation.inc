<?php

/**
 * @file
 * itg_widget_actions_bulk_operation.inc
 *
 * This file provide an extra action bulk operation to add nodes into our custom table.
 *
 */

/**
 * {@inheritdoc}
 */
function itg_widget_action_info() {
    return array(
        'itg_widget_categories_wise_node_group' => array(
            'type' => 'entity',
            'label' => t('Add nodes by category wise'),
            'configurable' => TRUE,
            'vbo_configurable' => FALSE,
            'triggers' => array('any'),
        ),
    );
}

/**
 * {@inheritdoc}
 */
function itg_widget_categories_wise_node_group_form($form, &$form_state) {
    $form = array();
    $view_name = $form_state['build_info']['args'][0]->name;
    $current_display = $form_state['build_info']['args'][0]->current_display;
    $widget = _get_widget_name("views_form_" . $view_name . "_page", $current_display);
    $form['widget_name'] = array(
        '#type' => 'select',
        '#title' => t("Widget"),
        '#options' => array("$widget" => "widget"),
        '#weight' => -1,
    );
    // Adding extra field for realted content.
    if ($current_display == 'big_story_format' && $_GET['type'] == 'breaking_news') {
        $form['related_content'] = array(
            '#type' => 'textfield',
            '#title' => t("Related content."),
            '#attributes' => array("placeholder" => t("Enter node id 123,1024,777")),
            '#description' => t("Node ids must be comma seperated values ex 123,1024,777."),
        );
    }
    return $form;
}

function itg_widget_categories_wise_node_group_validate($form, &$form_state) {
    if (isset($form_state['values']['related_content']) && !empty($form_state['values']['related_content'])) {
        $regex = "/^[0-9,]+$/";
        $related_content = $form_state['values']['related_content'];
        if (!preg_match($regex, $related_content)) {
            form_set_error('related_content', "Only numbers and commas are allowed on 'Related content' ");
        }
    }
}

/**
 * {@inheritdoc}
 */
function itg_widget_categories_wise_node_group_submit($form, &$form_state) {
    $view_name = $form['#form_id'];
    $current_display = $form_state['build_info']['args'][0]->current_display;
    $vals = array();
    $node_to_be_insert = array();
    // Unique combination using below four.
    $widget_name = $form_state['input']['widget_name'];
    // Get selected nodes ids
    $selected_node_data = $form_state['selection'];
    $cat_id = $_GET['category_tid'];
    $content_type = $_GET['type'];
    if ($current_display == 'big_story_format') {
        // All Code for big sotry.
        module_load_include('inc', 'itg_widget', 'includes/itg_widget_big_story');
        $big_story_data = array();
        $big_story_data = $form_state;
        save_big_story_widget_data($big_story_data);
    }
    elseif ($current_display == 'dont_miss_content') {
        module_load_include('inc', 'itg_widget', 'includes/itg_widget_dont_miss');
        $dont_miss_content = array();
        $dont_miss_content = $form_state;
        save_dont_miss_widget_data($dont_miss_content);

    }
    else {
        // Logic to skip nodes which are already in itg_widget_order table
        $nodes_already = db_select('itg_widget_order', 'iwo')
                ->condition('iwo.content_type', $content_type)
                ->condition('iwo.widget', $widget_name)
                ->condition('iwo.cat_id', $cat_id)
                ->fields('iwo', array('nid'))
                ->execute();
        foreach ($nodes_already as $val) {
            $vals[] = $val->nid;
        }
        // Remove nodes which are already in itg_widget_order table with combination of content type , widget name , cat_id , nid.
        foreach ($selected_node_data as $key => $node_data) {
            if (in_array($node_data, $vals)) {
                unset($selected_node_data[$key]);
            }
        }

        if (count($selected_node_data)) {
            foreach ($selected_node_data as $node) {
                $nid = db_insert('itg_widget_order')
                        ->fields(array(
                            'nid' => $node,
                            'widget' => $widget_name,
                            'content_type' => ($content_type) ? $content_type : " ",
                            'cat_id' => ($cat_id) ? $cat_id : "0",
                            'weight' => 0,
                        ))
                        ->execute();
            }
            drupal_set_message(t("Nodes has been saved"));
        }
        else {
            drupal_set_message(t("Selected nodes allready in ordering section"));
        }
    }
    return array(
        'form_values' => $form_state['values'],
    );
}
