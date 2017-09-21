<?php
/**
 * Implement itg_sso_reg_password_form
 * @param array $form
 * @param array $form_state
 */
function itg_sso_reg_password_form($form, &$form_state) {
  global $user, $base_url;

  if (user_is_anonymous()) {
    return drupal_access_denied();
  }  
  
  $form['#account'] = $GLOBALS['user'];
  $form['#prefix'] = '<div id="sso_password_form"><h3>'.drupal_set_title('Change Password').'</h3>';
  $form['#suffix'] = '</div>';
  $form['#attributes'] = array('autocomplete' => 'off');  
  
  
  $form['domain_info_url'] = array(
    '#type' => 'hidden',
    '#title' => t(''),
    '#value' => arg(2),
  );

  $form['current_pass'] = array(
    '#type' => 'password',
    '#title' => t('Current password'),
    '#attributes' => array('autocomplete' => 'off'),
    '#size' => 25,
    '#required' => TRUE
  );
  
  $form['account']['pass'] = array(
    '#type' => 'password_confirm',
    '#size' => 25,
    '#attributes' => array('autocomplete' => 'off'),
    '#title' => t(''),
    '#required' => TRUE
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

/**
 * Validate handler for change_password_form().
 */
function itg_sso_reg_password_form_validate(&$form, &$form_state) {  
  // Make sure the password functions are present.
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');

  // Make sure the provided current password is valid for this account.
  if (!user_check_password($form_state['values']['current_pass'], $form['#account'])) {
    form_set_error('current_pass', t('The current password you provided is incorrect.'));
  }
  if(!preg_match('/^(?=.*\d)(?=.*[A-Za-z])[0-9A-Za-z!@#$%]{6,15}$/', trim($form_state['values']['pass']))) {
    form_set_error('current_pass', t('Password must be minimum 6 and maximum 15 digit alphanumeric and It must contain minimum 1 special character.'));
  } else if(!preg_match("/\W/", trim($form_state['values']['pass']))) {
    form_set_error('current_pass', t(' must be minimum 6 and maximum 15 digit alphanumeric and It must contain minimum 1 special character.'));
  }
}


/**
 * Implement itg_sso_reg_password_form_submit
 * @param array $form
 * @param array $form_state
 */
function itg_sso_reg_password_form_submit($form, &$form_state) {
  global $user;
  $edit = array('pass' => $form_state['values']['pass']);
  $domain_info_url = $form_state['values']['domain_info_url'];
  user_save($form['#account'], $edit);
  
  if (function_exists('itg_sso_get_mail_content')) {
    $mail_content = itg_sso_get_mail_content('Password Changed', $user->mail);
  }
  drupal_goto('password-success/'.$domain_info_url);
}