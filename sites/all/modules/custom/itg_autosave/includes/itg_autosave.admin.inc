<?php

/**
 * Implement module setting form 
 */
function itg_autosave_form() { 
  // Add js into form
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_autosave') . '/js/itg_autosave.js',    
    drupal_get_path('module', 'itg_astro') . '/js/jquery.validate.min.js',
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
  if(!preg_match('/^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*$/',$form_state['values']['itg_form_id'])) {
     form_set_error('itg_form_id', t('Please enter valid form id!'));
  }
  
  if(!is_numeric($form_state['values']['time_interval'])) {
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
  $itg_auto_save = new ItgAutoSave();
  $itg_result = $itg_auto_save->itg_save_form_id($pre_save);  
}

/**
 * Implement delete callback for autosaved form
 * @param int $form_id Form id of the form.
 */
function itg_autosave_form_delete($form_id) {
  $itgQuery = db_delete('itg_autosave_forms');
  $itgQuery->condition('id', $form_id)
      ->execute();
  if ($itgQuery) {
    drupal_goto('admin/config/administration/itg_autosave');
  }
}