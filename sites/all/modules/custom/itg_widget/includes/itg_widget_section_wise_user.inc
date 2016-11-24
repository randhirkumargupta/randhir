<?php

/**
 * File for storing default user for specific section.
 *
 * @param array $form_state
 */
function save_default_user_for_every_section($form_state) {

  $widget = 'user_selection_for_section_widget';
  $defaultUserUid = $form_state['selection'][0];
  $sectionTid = $form_state['build_info']['args'][0]->exposed_data['field_user_section_tid'];
  
  // Update and insert section tid and user uid.
  db_merge('itg_widget_order')
      ->key(array('cat_id' => $sectionTid, 'widget' => $widget))
      ->fields(array(
        'nid' => $defaultUserUid,
        'cat_id' => $sectionTid,
        'widget' => $widget,
      ))
      ->execute();
}
