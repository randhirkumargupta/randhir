<?php
/* code for Global comment configuration */

/**
 * Implement comment_global_config
 * @param array $form
 * @param array $form_state
 */
function comment_global_config($form, &$form_state) {
  global $user, $base_url;
  
   // get last selected comment value
  if (function_exists(global_comment_last_record)) {
    $last_record = global_comment_last_record();
    
  }

  if($last_record[0]->config_name == 'other') {
    $nm = 'ITG Custom';
  } else {
    $nm = $last_record[0]->config_name;
  }
  
  $form['#prefix'] = '<div id="comment_global_config">';
  $form['#suffix'] = $ext_div . '</div>';
  $active = array('vukkul' => t('Vukkul'), 'other' => t('ITG Custom'));
  $form['choice'] = array(
    '#type' => 'radios',
    '#title' => t('Select Configuration'),
    '#description' => t(''),
    '#default_value' => $last_record[0]->config_name,
    '#options' => $active
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
//    '#ajax' => array(
//      'wrapper' => 'comment_global_config',
//      'callback' => 'comment_form_ajax_handler',
//    ),
  );
 
  $form['pre-record'] = array(
        '#markup' => '<div id="pre-record">'.t('Last selected configuration value : ').$nm.' : Date : '.$last_record[0]->created.'</div>',
      );
  return $form;
}

/**
 * Implement comment_global_config_validate
 * @param array $form
 * @param array $form_state
 */
function comment_global_config_validate($form, &$form_state) {
  $config_val = $form_state['values']['choice'];
  if (empty($config_val)) {
    form_set_error('choice', t('Please select option!'));
  }
}

/**
 * Implement comment_global_config_submit
 * @param array $form
 * @param array $form_state
 */
function comment_global_config_submit($form, &$form_state) {
  $config_val = $form_state['values']['choice'];
  $created = date('Y-m-d H:i:s');
  db_insert('itg_global_comment_config')// Table to store file and node info
  ->fields(array(
    'ctype' => 'comment',
    'config_name' => $config_val,
    'created' => $created
  ))
    ->execute();
  drupal_set_message(t('Comment configuration saved sucessfully !'));
}

/**
 * Implement comment_form_ajax_handler
 * @param array $form
 * @param array $form_state
 */
function comment_form_ajax_handler(&$form, &$form_state) {
  return $form;
}

/**
 * Implement global_comment_last_record
 */
function global_comment_last_record() {
  $query = db_select('itg_global_comment_config', 'ir')
      ->fields('ir', array('config_name','created'))
      ->orderBy('id', 'DESC')//ORDER BY created
      ->range(0,1);
  $result = $query->execute()->fetchAll();
  return $result;
}