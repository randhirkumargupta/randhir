<?php

/**
 * @file
 * Admin setting code for auto save module.
 */

/**
 * Implement module setting form 
 * {@inheritdoc}
 */
function itg_autosave_form() {
  // Add js into form
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_autosave') . '/js/itg_autosave.js',
  );

  // Node form id field
  $form['itg_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Form ID'),
    '#description' => t('Form ID of the content type form.'),
    '#required' => TRUE,
  );
  // Time interval field
  $form['time_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Tiem interval'),
    '#description' => t('Tiem interval in seconds. eg 30'),
    '#required' => TRUE,
  );
  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implement hook_validate(&$form, &$form_sate)
 * {@inheritdoc}
 */
function itg_autosave_form_validate($form, &$form_state) {
  if (!preg_match('/^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*$/', $form_state['values']['itg_form_id'])) {
    form_set_error('itg_form_id', t('Please enter valid form id!'));
  }

  if (!is_numeric($form_state['values']['time_interval'])) {
    form_set_error('time_interval', t('Please enter valid time interval!'));
  }
}

/**
 * Implements hook_form_submit($form, &$form-state)
 * {@inheritdoc}
 */
function itg_autosave_form_submit($form, &$form_state) {
  $form_id = check_plain($form_state['values']['itg_form_id']);
  $time_interval = check_plain($form_state['values']['time_interval']);

  // Prepare presave array.
  $pre_save = array(
    'form_name' => $form_id,
    'autosave_time' => $time_interval,
  );

  // Save data into database
  $itg_auto_save = new itg_auto_save();
  $itg_result = $itg_auto_save->itg_save_form_id($pre_save);
}

/**
 * Implement delete callback for autosaved form
 * @param int $form_id Form id of the form.
 */
function itg_autosave_form_delete($form_id) {
  $itg_query = db_delete('itg_autosave_forms');
  $itg_query->condition('id', $form_id)
      ->execute();
  if ($itg_query) {
    drupal_goto('admin/config/administration/itg_autosave');
  }
}

/**
 * Autosave ajax callback function
 * 
 * @param int $nid
 * @param string $ctype
 */
function itg_autosave_nodeform($nid, $ctype) {
  $inputs = $_POST;    
  $itg_auto_save = new itg_auto_save();
  $data = $itg_auto_save->itg_save_extract_fieldtype($inputs);  
  $data = array_filter($data, 'itg_autosave_remove_empty');  
  // Find field type and prepare array for foelds.  
  $pre_save = $itg_auto_save->itg_autosave_prepare_presave($data , $inputs);
  $pre_save['title'] = check_plain($inputs['title']);
  if (isset($pre_save['fieldCollection'])) {
    foreach ($pre_save['fieldCollection'] as $field) {
      $field_collection[$field] = $itg_auto_save->itg_save_field_field_collection($inputs[$field]);
    }
    $pre_save = array_merge($pre_save, $field_collection);
  }

  // Save data into database
  $itg_auto_save->itg_save_form_data($pre_save, $nid, $ctype);  
}

/**
 * Remove empty elements from an array
 * 
 * @param string $field_name_type
 * @return boolean
 */
function itg_autosave_remove_empty($field_name_type) {
  if (empty($field_name_type['fieldName'])) {
    return FALSE;
  }
  return TRUE;
}
