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

/**
 * Remove empty elements from an array
 */
function remove_empty($fieldNameType) {
  if (empty($fieldNameType['fieldName'])) {
    return false;
  }
  return TRUE;
}

/**
 * Callback function for autosave node form
 */
function itg_autosave_nodefrom() {
  global $user;

  $node = new stdClass();  
  $node->title = check_plain($_POST['title']);
  $nodeType = explode('_node_form', check_plain($_POST['form_id']));  
  $node->type = $nodeType[0];
  node_object_prepare($node);
  global $language;  
  $node->language = $language->language; // Or e.g. 'en' if locale is enabled
  $node->uid = $user->uid; 
  $node->status = 0; //(1 or 0): published or not
  $node->promote = 0; //(1 or 0): promoted to front page
  $node->comment = check_plain($_POST['comment']); // 0 = comments disabled, 1 = read only, 2 = read/write
  
  //get field_name and type
  $fieldNameType = array();
  $fieldNameType = IndiaTodayGroup::itg_autosave_extract_fieldtype($_POST);
  $fieldNameType = array_filter($fieldNameType, 'remove_empty');
  foreach ($fieldNameType as $value) {
    switch ($value['fieldType']) {
      case 'text_with_summary':        
        break;
      case 'image':
        break;
      case 'taxonomy_term_reference':
        break;

      default:
        break;
    }
  }
  
  print_r($fieldNameType);
  // Term reference (taxonomy) field
  $node->field_product_tid[$node->language][]['tid'] = $form_state['values']['a taxonomy term id'];

  // Entity reference field
  $node->field_customer_nid[$node->language][] = array(
    'target_id' => $form_state['values']['entity id'],
    'target_type' => 'node',
  );
  // 'node' is default,
  // Other possible values are "user" and  "taxonomy_term" 

  //$node = node_submit($node); // Prepare node for saving
  //node_save($node);
  //print_r(field_info_field('field_category'));
  //print_r($_POST);
  
  exit();
}