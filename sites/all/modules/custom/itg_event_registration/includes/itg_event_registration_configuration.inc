<?php

/**
 * @file: itg_event_registration_configuration.inc
 */

/**
 * Render event registration form
 * @return string|bool
 */

function itg_event_registration_fields_configuration_form($form, &$form_state) {
  $query = db_select('taxonomy_term_data', 'ttd');
  $query->fields('ttd', array('name', 'description'));
  $query->condition('ttd.vid', 41, '=');
  $result = $query->execute();
  foreach($result as $rel) {
    $value[$rel->name] = $rel->description;
      
  }
  $form["display"] = array(
      '#type' => 'checkboxes',
      '#title' => 'Display',
      '#options' => $value
    );
      $form["requied_field"] = array(
        '#type' => 'checkboxes',
        '#title' => 'Required', 
        '#options' => $value
      );
      $form['event_nid'] = array(
        '#type' => 'hidden',
        '#value' => 2770,
      );
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'submit'
      );
  return $form;
}