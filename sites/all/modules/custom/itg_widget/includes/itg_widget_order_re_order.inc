<?php

/**
 * @file
 * itg_widget_order_re_order.inc
 *
 * Provide functionality to order reorder page.
 *
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_page_alter(&$form, &$form_state, $form_id) {
    $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_we_may_suggest_widget_alter(&$form, &$form_state, $form_id) {
    $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data";
}

/**
 * Function for save new order in custom table itg_widget_order
 * 
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data($form, &$form_state) {
    // Current display for indentifing the view page (Widget name).
    $current_display = $form_state['build_info']['args'][0]->current_display;
    // Below view_name will use to get widget name.
    $view_name = $form['form_id']['#value'];
    $widget = _get_widget_name($view_name, $current_display);
    // Take draggable view input value after submit the form.
    $draggable_view_data = $form_state['input']['draggableviews'];
    // Content type from url.
    $content_type = $_GET['type'];
    // Category tid from url.
    $cat_id = $_GET['category_tid'];
    // If user dont make changes in draggable view then all the weights remain zero.
    // So check is required here. If al weight are 0 then do not execute query w.r.t. into itg_widget_order table.
    $weight_track_flag = FALSE;
    foreach ($draggable_view_data as $key => $node_data) {
        if ($node_data['weight'] > 0) {
            // Found changes in draggable view content
            $weight_track_flag = TRUE;
        }
    }
    // IF we got there is changes made in draggable view order.
    if ($weight_track_flag) {
        watchdog("widget", "Change made in order");
        // Frist delete all the data from itg_widget_order table of combination
        foreach ($draggable_view_data as $key => $node_data) {
            if (!empty($node_data['id']) && !empty($content_type) && !empty($widget) && !empty($cat_id)) {
                $num_deleted = db_delete('itg_widget_order')
                        ->condition('nid', $node_data['id'])
                        ->condition('content_type', $content_type)
                        ->condition('widget', $widget)
                        ->condition('cat_id', $cat_id)
                        ->execute();
                if ($num_deleted) {
                    watchdog("widget", "Delete action has been performed");
                }
            }
        }

        // Now insert new entry in itg_widget_order table of combination
        foreach ($draggable_view_data as $key => $node_data) {
            if (!empty($node_data['id']) && !empty($content_type) && !empty($widget) && !empty($cat_id)) {
                $is_inserted = db_insert('itg_widget_order')
                        ->fields(array(
                            'nid' => $node_data['id'],
                            'widget' => $widget,
                            'content_type' => $content_type,
                            'cat_id' => $cat_id,
                            'weight' => $node_data['weight'],
                        ))
                        ->execute();
                if ($is_inserted) {
                    watchdog("widget", "Insert action has been performed");
                    drupal_set_message(t("Ordering has been saved."));
                }
            }
        }
    }
    // If there is not chnages found in draggable view order then simply give an message.
    else {
        drupal_set_message(t("This ordering is already saved."));
    }
}
