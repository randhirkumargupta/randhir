<?php

/**
 * @file
 * File for storing supplement and primary category according issue date.
 *
 */

/**
 * Implement function for save order data (primary category) according issue
 * @param array $form_state
 */
function save_primary_category_acccording_issue_magazine($form_state) {
  foreach ($form_state['selection'] as $selection_id) {
    $primary_category = itg_widget_get_primary_cat($selection_id);
    $widget = 'issue_primary_category_magazin_widget';
    $issue_date = $_GET['field_story_issue_date_value']['value']['date'];
    $min_weight = get_min_weight_for_special($widget, 0, $issue_date);
    // Update and insert section tid and user uid.
    db_merge('itg_widget_order')
        ->key(array('cat_id' => $primary_category, 'widget' => $widget))
        ->fields(array(
          'nid' => $selection_id,
          'cat_id' => $primary_category,
          'widget' => $widget,
          'extra' => $issue_date,
          'weight' => --$min_weight,
        ))
        ->execute();
  }
}

/**
 * Implement function for save order data (primary category) according issue
 * @param array $form_state
 */
function save_supplement_acccording_issue_magazine($form_state) {
  foreach ($form_state['selection'] as $selection_id) {
    $widget = 'issue_supplement_magazin_widget';
    $issue_date = $_GET['field_story_issue_date_value']['value']['date'];
    $min_weight = get_min_weight_for_special($widget, 0, $issue_date);

    // Update and insert section tid and user uid.
    db_merge('itg_widget_order')
        ->key(array('nid' => $selection_id, 'widget' => $widget))
        ->fields(array(
          'nid' => $selection_id,
          'widget' => $widget,
          'extra' => $issue_date,
          'content_type' => 'supplement',
          'weight' => --$min_weight,
        ))
        ->execute();
  }
}
