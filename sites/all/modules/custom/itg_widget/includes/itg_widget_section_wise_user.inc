<?php

/**
 * @file
 * Widget maine function to save user data.
 *
 */

/**
 * File for storing default user for specific section.
 *
 * @param array $form_state
 */
function save_default_user_for_every_section($form_state) {

  $widget = 'user_selection_for_section_widget';
  $default_user_id = $form_state['selection'][0];
  $section_tid = $form_state['build_info']['args'][0]->exposed_data['field_user_section_tid'];

  // Update and insert section tid and user uid.
  db_merge('itg_widget_order')
      ->key(array('cat_id' => $section_tid, 'widget' => $widget))
      ->fields(array(
        'nid' => $default_user_id,
        'cat_id' => $section_tid,
        'widget' => $widget,
      ))
      ->execute();
}
