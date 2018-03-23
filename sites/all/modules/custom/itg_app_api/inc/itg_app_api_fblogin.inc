<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate fblogin array
 * @pram  array
 *
 * @return array
 */
function fblogin($data) {

  $token = $data['token'];
  $app_id_social = $data['app_id'];
  $uname_social = $data['uname'];
  $uid_social = $data['uid'];
  $issued_at_social = $data['issued_at'];
  $expires_at_social = $data['expires_at'];
  $password = $data['password'];
  //check user name is exist in db..
  $user_load = user_load_by_name($uname_social);

  if ($user_load->uid) {
    // user exist, next is step for login
    return userloginFB($uname_social, $user_load->uid, $password);
  }
  else {
    // user not exist, next is step for signup
    return userSignupFB($uname_social, $uid_social, $password);
  }
}

/**
 * main function for userloginFB
 * @pram string $uname, $uidget, $password
 *
 * @return array
 */
function userloginFB($uname, $uidget, $password) {
  global $user;
  $username = $uname;

  if ($user->uid) {
    // user is already logged in
    return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
  }
  // Check if account is active.
  if (user_is_blocked($username)) {
    return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
  }

  // Emulate drupal native flood control: check for flood condition.
  $flood_state = array();
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state = _user_resource_flood_control_precheck($username);
  }

  // Only authenticate if a flood condition was not detected.
  if (empty($flood_state['flood_control_triggered'])) {

    $uid = $uidget;
  }
  else {
    $uid = FALSE;
  }

  // Emulate drupal native flood control: register flood event, and throw error
  // if a flood condition was previously detected
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state['uid'] = $uid;
    _user_resource_flood_control_postcheck($flood_state);
  }

  if ($uid) {
    $user = user_load($uid);
    if ($user->uid) {
      user_login_finalize();

      $return = new stdClass();
      $return->sessid = session_id();
      $return->session_name = session_name();
      $return->token = drupal_get_token('services');

      $account = clone$user;

      services_remove_user_data($account);

      $return->user = $account;

      return $return;
    }
  }
  watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
  return services_error(t('Wrong username or password.'), 401);
}

/**
 * main function for userSignupFB
 * @pram string $uname_social, $uid_social, $password
 *
 * @return array
 */
function userSignupFB($uname_social, $uid_social, $password) {
  $mail = $uid_social;
  $username = $uname_social;
  $first_name = "";
  $last_name = "";
  $mobile = "";

  // signup method
  $form_state = array();

  // check user_id is mail or mobile
  $url_info = substr(uniqid('', TRUE), -5);

  $form_state['values']['mobile'] = "";
  $form_state['values']['url_info'] = $url_info;
  $form_state['values']['mail'] = $mail;
  // prepare array for user
  $edit = array(
    'name' => $username,
    'pass' => $password,
    'mail' => $mail,
    'init' => $mail,
    'status' => 1,
    'access' => REQUEST_TIME,
    'field_first_name' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $first_name,
        ),
      ),
    ),
    'field_last_name' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $last_name,
        ),
      ),
    ),
    'roles' => array(
      2 => 'authenticated',
      25 => 'Front User',
    ),
  );

  if (is_numeric($mobile)) {
    $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
        0 => array(
          'value' => $mobile,
        ),
      ),
    );
  }


  try {

    $account = user_save(NULL, $edit);

    if (function_exists('itg_personalization_reddem_referfriend')) {
      itg_personalization_reddem_referfriend($_SESSION['referral_key']);
      unset($_SESSION['referral_key']);
    }
    // Set operation.

    $op = 'register_no_approval_required';
    // Send an email.
    if (empty($form_state['values']['mobile'])) {
      // _user_mail_notify($op, $account);
      if (function_exists('itg_sso_get_mail_content')) {
        if (!empty($form_state['values']['url_info'])) {
          $url_info = $form_state['values']['url_info'];
        }
        $mail_content = itg_sso_get_mail_content($account, $mail, $url_info);
      }
      itg_user_mapping_activate($account->uid);
    }
    else {
      $rand_otp = rand(0, 9999);
      if (function_exists('itg_sso_first_time_otp_insert')) {
        itg_sso_first_time_otp_insert($mobile, $mail, $rand_otp, 'register');
      }
    }
  }
  catch(Exception$e) {
    watchdog('error on user save', $e->getMessage());
    drupal_set_message('Error:' . $e->getMessage(), 'error');
    $account = $e;
  }
  if ($account->uid) {
    return userloginFB($uname_social, $account->uid, $password);
  }
  else {
    return $account;
  }
}

/**
 * function for signup on local
 * @pram array
 *
 * @return array
 */
function localSignup($data) {
  global $user;
  $first_name = $data['first_name'];
  $last_name = $data['last_name'];
  $user_id = $data['user_id'];
  $password = $data['password'];
  $login_type = $data['login_type'];
  $token_id = $data['token_id'];
  $local_user = user_load_by_name($user_id);
  if (!$local_user->uid) {
    $form_state = array();
    // check user_id is mail or mobile
    $url_info = "";
    $mail_flag = 1;
    if (preg_match('/^\d{10}$/', $user_id)) {
      $mail_flag = 0;
      $mobile = $user_id;
      // reference from sso module.
      $mail = $first_name . '@' . 'nowhere.com';
    }
    else {
      $mobile = "";
      $mail = $user_id;
    }
    $form_state['values']['mobile'] = $mobile;
    $form_state['values']['url_info'] = $url_info;
    if ($mail_flag) {
      $form_state['values']['mail'] = $mail;
    }
    else {
      $form_state['values']['mail'] = "";
    }
    if ($data['email_id'] != "" && filter_var($data['email_id'], FILTER_VALIDATE_EMAIL)) {
      $mail = $data['email_id'];
    }
    // prepare array for user
    $edit = array(
      'name' => $user_id,
      'pass' => $password,
      'mail' => $mail,
      'init' => $mail,
      'status' => 1,
      'access' => REQUEST_TIME,
      'field_first_name' => array(
        LANGUAGE_NONE => array(
          0 => array(
            'value' => $first_name,
          ),
        ),
      ),
      'field_last_name' => array(
        LANGUAGE_NONE => array(
          0 => array(
            'value' => $last_name,
          ),
        ),
      ),
      'roles' => array(
        2 => 'authenticated',
        25 => 'Front User',
      ),
    );

    if (is_numeric($mobile)) {
      $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
          0 => array(
            'value' => $mobile,
          ),
        ),
      );
    }


    try {

      $account = user_save(NULL, $edit);

      $user = updateUsedrProfileAtSignup_rapid($data, 1);

      if (function_exists('itg_personalization_reddem_referfriend')) {
        itg_personalization_reddem_referfriend($_SESSION['referral_key']);
        unset($_SESSION['referral_key']);
      }
      // Set operation.

      $op = 'register_no_approval_required';
      // Send an email.
      if (empty($form_state['values']['mobile'])) {
        if (function_exists('itg_sso_get_mail_content')) {
          if (!empty($form_state['values']['url_info'])) {
            $url_info = $form_state['values']['url_info'];
          }
          $mail_content = itg_sso_get_mail_content($account, $mail, $url_info);
        }
        itg_user_mapping_activate($account->uid);
      }
    }
    catch(Exception$e) {
      watchdog('error on user save', $e->getMessage());
      drupal_set_message('Error:' . $e->getMessage(), 'error');
      $account = $e;
    }
  }
  if ($user->uid) {
    user_login_finalize();

    $return = new stdClass();
    $return->sessid = session_id();
    $return->session_name = session_name();
    $return->token = drupal_get_token('services');

    $account = clone$user;

    services_remove_user_data($account);

    $return->user = $account;

    return $return;
  }
}

/**
 * function for login on local
 * @pram array
 *
 * @return array
 */
function localLogin($data) {
  global $user;
  $user_id = $username = $data['user_id'];
  $password = $password = $data['password'];

  if ($user->uid) {
    // user is already logged in
    return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
  }

  // Check if account is active.
  if (user_is_blocked($username)) {
    return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
  }

  // Emulate drupal native flood control: check for flood condition.
  $flood_state = array();
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state = _user_resource_flood_control_precheck($username);
  }

  // Only authenticate if a flood condition was not detected.
  if (empty($flood_state['flood_control_triggered'])) {

    $uid = user_authenticate($username, $password);
  }
  else {
    $uid = FALSE;
  }

  // Emulate drupal native flood control: register flood event, and throw error
  // if a flood condition was previously detected
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state['uid'] = $uid;
    _user_resource_flood_control_postcheck($flood_state);
  }

  if ($uid) {
    $user = user_load($uid);
    if ($user->uid) {
      user_login_finalize();

      $return = new stdClass();
      $return->sessid = session_id();
      $return->session_name = session_name();
      $return->token = drupal_get_token('services');

      $account = clone$user;

      services_remove_user_data($account);

      $return->user = $account;

      return $return;
    }
  }
}

/**
 * function for password change on local
 * @pram array
 * @pram int
 *
 * @return array
 */
function localChangePass($get_data, $uid) {
  $uname = $user_id = $get_data['user_id'];
  $pass = $get_data['new_password'];
  $pass2 = $get_data['confirm_password'];
  $msg = "";
  $data = array();
  if (is_numeric($uname)) {
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($uname);
    }
    if (!empty($get_user_check_mobile)) {
      $account = user_load($get_user_check_mobile);
    }
  }
  else {
    if (function_exists(itg_sso_user_email_check)) {
      $get_user_check_email = itg_sso_user_email_check($uname);
    }
    if (!empty($get_user_check_email)) {
      $account = user_load($get_user_check_email);
    }
  }


  $edit = array('pass' => $pass2);

  // Save the account with the new password.
  $flag = user_save($account, $edit);



  return $flag;
}

/**
 * function for reset password change on local
 * @pram array
 * @pram int
 *
 * @return array
 */
function localResetPass($get_data, $uid) {
  $uname = $user_id = $get_data['user_id'];
  $pass = $get_data['new_password'];
  $pass2 = $get_data['confirm_password'];
  $msg = "";
  //$data = array();
  $data = array();
  if (is_numeric($uname)) {
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($uname);
    }
    if (!empty($get_user_check_mobile)) {
      $account = user_load($get_user_check_mobile);
    }
  }
  else {
    if (function_exists(itg_sso_user_email_check)) {
      $get_user_check_email = itg_sso_user_email_check($uname);
    }
    if (!empty($get_user_check_email)) {
      $account = user_load($get_user_check_email);
    }
  }

  $edit = array('pass' => $pass2);
  // Save the account with the new password.
  $flag = user_save($account, $edit);
  return $flag;
}

