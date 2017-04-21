<?php

/**
 * @file: itg_event_tab_permission.inc
 */

/**
 * Implements function for event tabwise permission form.
 */
function itg_event_registration_tabwise_form($form) {
  $event_tabs = array('1__step_first' => 'Basic Details', '2__step_second' => 'Registration Fees', '3__step_program_schedule' => 'Program Schedule', '4__step_sponsor' => 'Sponsor', '5__step_highlights' => 'Highlights', '6__step_media' => 'Media', '7__step_configuration' => 'Configuration');
  $roles = array(10 => 'Site Admin', 5 => 'Copy Editor', 6 => 'Editor', 24 => 'Marketing Manager');
  foreach ($roles as $rid => $role) {
    //foreach($event_tabs as $tab_key => $tab) {
    $form[$rid . '-tabwise'] = array(
      '#type' => 'checkboxes',
      '#title' => t($role),
      '#options' => $event_tabs,
      '#default_value' => variable_get($rid . '-tabwise'),
    );
    drupal_add_js('jQuery(document).ready(function(){ jQuery(".form-item-'.$rid.'-tabwise-1--step-first").hide(); jQuery("#edit-' . $rid . '-tabwise-1-step-first").attr("checked", true);});', array('type' => 'inline', 'scope' => 'footer'));
    //}
  }
  $form['array_filter'] = array(
    '#type' => 'value',
    '#value' => TRUE,
  );

    return system_settings_form($form);
}
