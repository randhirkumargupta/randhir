<?php

/**
 * @file
 * Admin setting code for auto save module.
 */

/**
 * Implement module setting form.
 *
 * {@inheritdoc}.
 */
function itg_autosave_form() {
  // Add js into form.
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_autosave') . '/js/itg_autosave.js',
  );

  // Node form id field.
  $form['itg_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Form ID'),
    '#description' => t('Form ID of the content type form.'),
    '#required' => TRUE,
  );
  // Time interval field.
  $form['time_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Tiem interval'),
    '#description' => t('Tiem interval in seconds. eg 30'),
    '#required' => TRUE,
  );
  // Submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implements hook_validate().
 *
 * {@inheritdoc}.
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
 * Implements hook_form_submit().
 *
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

  // Save data into database.
  $itg_auto_save = new itg_auto_save();
  $itg_result = $itg_auto_save->itg_save_form_id($pre_save);
}

/**
 * Implement delete callback for autosaved form.
 *
 * @param int $form_id
 *   Form id of the form.
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
 * Autosave ajax callback function.
 *
 * @param int $nid
 *   Node id of the node.
 * @param string $ctype
 *   Name of the content type.
 */
function itg_autosave_nodeform($nid, $ctype) {    
  global $user;
  // Store submitted values into variable.
  $inputs = $_POST;    
  // Create object for itg_auto_save class.
  $itg_auto_save = new itg_auto_save();
  // Remove empty field collections fields from submitted array.
  if ($ctype == 'astro') {
    $itg_auto_save->itg_save_remove_fcollection($ctype, $inputs);
  }  
  // Extract field type from submited values array.
  $data = $itg_auto_save->itg_save_extract_fieldtype($inputs);
  $data = array_filter($data, 'itg_autosave_remove_empty');  
  //Get unique id for node from inputs.  
  $node_identity = $inputs['field_story_node_identity']['und'][0]['value'];
  // Fetch node id and field collections ids from database.
  $itg_nid = itg_autosave_get_unique_id($ctype, $node_identity); 
  
  // Prepare values for new node.
  if ($itg_nid->nid == '') {    
    $node = new stdClass();
    // Set title value 
    $node->type = $ctype;
    // Prepare node object
    node_object_prepare($node); 
    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid;
    $node->status = 0;
    $node->promote = 0;
    $node->comment = 1;
  }
  else {       
    // Load node if it case of node edit.  
    $node = node_load($itg_nid->nid);  
  }      
  $title = isset($inputs['title']) ? $inputs['title'] != '' ? check_plain($inputs['title']) : '' : '';  
  // If title is empty then exit the process.
  
  if (empty($title)) {
    print t('Title is empty');
    exit();
  }
  
  // Assign title to tile field.
  $node->title = $title;
  // Find field type and prepare array for foelds.
  $f_collection = $itg_auto_save->itg_autosave_prepare_presave($data, $inputs, $node);
  
  // Check if field collection is available.
  /******************************* Hide field collection code ***************** 
  if (count($f_collection) > 0) {
    // Find how many field collection are present.
    foreach ($f_collection as $field) {      
      // Delete old field collection fields and create fresh collections.
      $itg_auto_save->itg_save_field_field_collection($inputs[$field], $node, $field, $itg_nid->field_collection);      
    }    
  }
   
  *********** End of code field collection ***********************************/  
  
  // Submit the node before save.        
  $node = node_submit($node); 
  // Save node to save all values into node.    
  node_save($node);  
  // Store unique id associated with node in array.
  $pre_save['unique_id'] = $node_identity;
  // Store all field collections ids into array.
  $pre_save['field_collection'] = itg_autosave_get_fcollection_ids($f_collection, $node);
  // Save data into database.
  $itg_auto_save->itg_save_form_data($pre_save, $node->nid, $ctype);
}

/**
 * 
 * @param type $f_collection
 * @param type $node
 * @return type
 */
function itg_autosave_get_fcollection_ids($f_collection, $node) {
  $itg_result = array();
  if (count($f_collection) > 0) {    
    foreach ($f_collection as $value) {
      // Find multi value of field collection
      foreach ($node->{$value}['und'] as $delta) {
        $itg_result[$value][] = $delta['value'];
      }
    }
  }
  
  return $itg_result;
}

/**
   * Get unique id associated with node.
   *
   * @param type $c_type
   *   name of the content type.
   * @param type $unique_id
   *   Unique id of the form.
   *
   * @return int
   *   Node id of the node.
   */
  function itg_autosave_get_unique_id($c_type, $unique_id) {    
    $itg_query = db_select('itg_autosave_node_data', 'itg');
    $itg_query->fields('itg', array('nid', 'field_collection'))
      ->condition('node_type', $c_type)
      ->condition('itg_identity', $unique_id);
    $itg_result = $itg_query->execute()->fetchObject();    
    
    return $itg_result;
  }

/**
 * Remove empty elements from an array.
 *
 * @param string $field_name_type
 *   Type of the field.
 *
 * @return bool
 *   Return boolean value.
 */
function itg_autosave_remove_empty($field_name_type) {
  if (empty($field_name_type['fieldName'])) {
    return FALSE;
  }
  return TRUE;
}
