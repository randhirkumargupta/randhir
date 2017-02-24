<?php

/**
 * @file: itg_event_registration_configuration.inc
 */

/**
 * Render event registration form
 * @return string|bool
 */
function itg_event_registration_fields_configuration_form($form, &$form_state) {
  $arg = arg();
  $vid = itg_event_registration_vocab_id('event_registration_configuration');
  $query = db_select('taxonomy_term_data', 'ttd');
  $query->fields('ttd', array('name', 'description'));
  $query->condition('ttd.vid', $vid, '=');
  $result = $query->execute();
  foreach ($result as $rel) {
    $value[$rel->name . '@' . $rel->description] = 'Required';
    $display_array[$rel->name] = $rel->description;
  }
  $form["display"] = array(
    '#type' => 'checkboxes',
    //'#title' => 'Display',
    '#options' => $display_array,
    '#default_value' => itg_event_registration_default_value($arg[1], 'display')
  );
  $form["requied_field"] = array(
    '#type' => 'checkboxes',
    //'#title' => 'Required', 
    '#options' => $value,
    '#default_value' => itg_event_registration_default_value($arg[1], 'require')
  );
  $form['event_nid'] = array(
    '#type' => 'hidden',
    '#value' => $arg[1],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'submit'
  );
  return $form;
}

/**
 * Implement function for options for configuration
 * @param int $e_nid
 * @param str $type
 * @return
 */
function itg_event_registration_default_value($e_nid, $type) {
  $query = db_select('itg_event_registration_field_config', 'itg_event_config');
  $query->fields('itg_event_config', array('visiblity', 'required', 'field_label', 'field_machine_name'));
  $query->condition('event_nid', $e_nid, '=');
  $result = $query->execute();
  $rel = '';
  if ($type == 'display') {
    foreach ($result as $val) {
      $rel[$val->field_machine_name] = $val->visiblity;
    }
  }
  elseif ($type == 'require') {
    foreach ($result as $val) {
      $rel[$val->field_machine_name . '@' . $val->field_label] = $val->required;
    }
  }
  return $rel;
}
