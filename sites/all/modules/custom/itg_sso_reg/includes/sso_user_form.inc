<?php

/**
 * Implements hook_form().
 * {@inheritdoc}
 */
function itg_sso_reg_multistep_form($form, &$form_state) {
  $arg = arg();
  if(!empty($arg[1]) && $arg[1] == 'domain_info') {
    $appnd_to_lnk = '/'.$arg[1];
    $domain_arg = $arg[1];
  }
  if(!empty($arg[1]) && $arg[1] != 'domain_info') {
    $url_arg = $arg[1];
  }
// If $form_state['step'] is not set, we set it to 1
  $form_state['step'] = isset($form_state['step']) ? $form_state['step'] : 1;
  global $user, $base_url;
  $settings = array();
  $settings['base_url'] = $base_url;
  $settings['uid'] = $user->uid;

  drupal_add_js(array('itg_sso_reg' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_sso_reg') . '/js/itg_sso_reg.js');
  
  $step_ext_div = '';
  
  if (isset($form_state['step']) && ($form_state['step'] == '1')) {
    $fn_link = 'saml_login/other'.$appnd_to_lnk;
    $step_ext_div = '<div class="sign-in-link">' . l('Already Register ? Sign in', $fn_link , array('attributes' => array('class' => array('sso-sign-in')))) . '</div>';
  }
  // Add a wrapper div that will be used by the Form API to update the form using AJAX
  $form['#prefix'] = '<div id="itg_sso_reg_multistep_form">';
  $form['#suffix'] = $step_ext_div . '</div>';
  $form['#attributes'] = array('autocomplete' => 'off');

  // Depending on which step of the form we are on, we output different form fields
  switch ($form_state['step']) {
    // Step 1
    case 1:
      $default_value = '';
      if (isset($form_state['values']['step_1'])) {
        $default_value = $form_state['values']['step_1'];
      }
      elseif (isset($form_state['storage']['step_1'])) {
        $default_value = $form_state['storage']['step_1'];
      }

      $form['domain_info'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => '',
        '#type' => 'hidden',
        '#value' => $domain_arg,
        '#attributes' => array('placeholder' => t('')),
        
      );
      
      $form['url_info'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => '',
        '#type' => 'hidden',
        '#value' => $url_arg,
        '#attributes' => array('placeholder' => t('')),
        
      );

      $form['fname'] = array(
        '#title' => 'First Name',
        '#description' => '',
        '#type' => 'textfield',
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('*First Name'), 'autocomplete' => 'off'),
        '#prefix' => '<div class="form-row"><div id="ufname" class="col-xs-6">',
        '#suffix' => '</div>',
      );

      $form['lname'] = array(
        '#title' => 'Last Name',
        '#description' => '',
        '#type' => 'textfield',
        '#attributes' => array('placeholder' => t('Last Name'), 'autocomplete' => 'off'),
        '#prefix' => '<div id="ulname" class="col-xs-6">',
        '#suffix' => '</div></div>',
      );

      $form['mail'] = array(
        '#title' => 'Email',
        '#description' => '',
        '#type' => 'textfield',
        '#attributes' => array('placeholder' => t('Email'), 'autocomplete' => 'off'),
        '#prefix' => '<div class="form-row email-or-mobile"><div id="umail" class="col-xs-6">',
        '#suffix' => '</div>',
      );
      
      $form['mobile'] = array(
        '#title' => 'Mobile',
        '#description' => '',
        '#maxlength' => 10,
        '#type' => 'textfield',
        '#attributes' => array('placeholder' => t('Mobile'), 'autocomplete' => 'off'),
        '#prefix' => '<div id="umobile" class="col-xs-6">',
        '#suffix' => '</div></div>',
      );

      $form['password'] = array(
        '#title' => 'Password',
        '#description' => '',
        '#id' => 'password',
        '#type' => 'password',
        '#attributes' => array('placeholder' => t('*Password'), 'autocomplete' => 'off'),
        '#required' => TRUE,
        '#prefix' => '<div class="form-row""><div id="upass" class="col-xs-6">',
        '#suffix' => '</div>',
      );

      $form['password_again'] = array(
        '#title' => 'Re type Password',
        '#description' => '',
        '#id' => 'password_again',
        '#type' => 'password',
        '#attributes' => array('placeholder' => t('*Re type Password'), 'autocomplete' => 'off'),
        '#required' => TRUE,
        '#prefix' => '<div id="unpass" class="col-xs-6">',
        '#suffix' => '</div></div>',
      );

      break;

    // Step 2
    case 2:
      $default_value = '';
      if (isset($form_state['values']['step_2'])) {
        $default_value = $form_state['values']['step_2'];
      }
      elseif (isset($form_state['storage']['step_2'])) {
        $default_value = $form_state['storage']['step_2'];
      }
      
      // if mail value is blank assign dummy mail
      if (isset($form_state['values']['mail']) && !empty($form_state['values']['mail'])) {
        $mail = $form_state['values']['mail'];
      }
      else {
        $mail = $form_state['values']['fname'] . '@' . 'nowhere.com';
      }

      $form['domain_info'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => '',
        '#type' => 'hidden',
        '#value' => $form_state['values']['domain_info'],
        '#attributes' => array('placeholder' => t('')),
        
      );
      
      $form['step2mail'] = array(
        '#title' => '',
        '#description' => '',
        '#type' => 'hidden',
        '#value' => $mail,
      );

      $form['step2mobile'] = array(
        '#title' => '',
        '#description' => '',
        '#value' => isset($form_state['values']['mobile']) ? $form_state['values']['mobile'] : '',
        '#maxlength' => 10,
        '#type' => 'hidden',
      );


      $form['otp'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => 'otp',
        '#type' => 'textfield',
        '#attributes' => array('placeholder' => t('OTP'), 'autocomplete' => 'off'),
        '#maxlength' => 4,
        '#prefix' => '<div id="uotp" class="form-row"><div class="col-xs-6">',
        '#suffix' => '</div>',
      );



      $form['otp_links'] = array(
        '#prefix' => '<div class="col-xs-6">',
        '#markup' => '<div id="otpclickme" class="btn-resend">Resend OTP</div>',
      );
      $form['loader'] = array(
        '#markup' => '<div id="ajax-loader" style="display:none"><img src="' . base_path() . path_to_theme() . '/images/loader.svg" alt=""/></div>',
        '#suffix' => '</div>',
      );


      $form['otp_success'] = array(
        '#markup' => '<div id="otp_success"></div>',
        '#suffix' => '</div>',
      );

      

      break;

    // Step 3
    case 3:
      $default_value = '';
      if (isset($form_state['values']['step_3'])) {
        $default_value = $form_state['values']['step_3'];
      }
      elseif (isset($form_state['storage']['step_3'])) {
        $default_value = $form_state['storage']['step_3'];
      }
      
      if (!empty($form_state['values']['domain_info'])) {
        $append_lnk = '/'.$form_state['values']['domain_info'];
      }
      else
      {
        $append_lnk = '';
      }
        $fn_link = 'saml_login/other' . $append_lnk;
        $ext_div = '<div class="sign-in-link">' . l('Click here to sign in', $fn_link, array('attributes' => array('class' => array('sso-sign-in')))) . '</div>';
      
      $form['domain_info'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => '',
        '#type' => 'hidden',
        '#value' => $form_state['values']['domain_info'],
        '#attributes' => array('placeholder' => t('')),
        
      );
      
      $form['thank-you'] = array(
        '#markup' => '<div id="email-sucess">Your account has been successfully created.Please check your email for further information!</div>',
      );

      $form['sgn-link'] = array(
        '#markup' => $ext_div,
      );
      
      
      break;

    // Step 4
    case 4:
      $default_value = '';
      if (isset($form_state['values']['step_4'])) {
        $default_value = $form_state['values']['step_4'];
      }
      elseif (isset($form_state['storage']['step_4'])) {
        $default_value = $form_state['storage']['step_4'];
      }
      
      if (!empty($form_state['values']['domain_info'])) {
        $append_lnk = '/'.$form_state['values']['domain_info'];
      }
      else
      {
        $append_lnk = '';
      }
        $fn_link = 'saml_login/other' . $append_lnk;
        $ext_div = '<div class="sign-in-link">' . l('Click here to sign in', $fn_link, array('attributes' => array('class' => array('sso-sign-in')))) . '</div>';
      
      $form['domain_info'] = array(
        '#title' => '',
        '#description' => '',
        '#id' => '',
        '#type' => 'hidden',
        '#value' => $form_state['values']['domain_info'],
        '#attributes' => array('placeholder' => t('')),
        
      );
      
      $form['thank-you'] = array(
        '#markup' => '<div id="mobile-success">You are registered sucessfully!</div>',
      );
      
      $form['sgn-link'] = array(
        '#markup' => $ext_div,
      );
      
      break;
  }

  // Create a container for our buttons
  $form['buttons'] = array
    (
    '#type' => 'container',
  );

  // We only want a forward button if we are not on the last step of the form
  // change butoon value based on step
  if ($form_state['step'] == 1) {

    $button = 'Sign Up';
  }

  if ($form_state['step'] == 1) {
    $form['buttons']['forward'] = array
      (
      '#type' => 'submit',
      '#value' => $button,
      '#ajax' => array
        (
        // We pass in the wrapper we created at the start of the form
        'wrapper' => 'itg_sso_reg_multistep_form',
        // We pass a callback function we will use later to render the form for the user
        'callback' => 'itg_sso_reg_multistep_form_ajax_callback',
      ),
    );
  }
  // We only want a submit button if we are on the last step of the form
  if ($form_state['step'] == 2) {

    $form['buttons']['submit'] = array
      (
      '#type' => 'submit',
      '#value' => t('submit'),
      '#suffix' => '',
      '#ajax' => array
        (
        // We pass in the wrapper we created at the start of the form
        'wrapper' => 'itg_sso_reg_multistep_form',
        // We pass a callback function we will use later to render the form for the user
        'callback' => 'itg_sso_reg_multistep_form_ajax_callback',
      ),
    );
  }
  
  return $form;
}

/**
 * Implements hook_validate().
 * {@inheritdoc}
 */
function itg_sso_reg_multistep_form_validate($form, &$form_state) {
  // First we set up a switch for each of our three steps
  if (empty($form_state['values']['mobile'])) {
    $mobile = $form_state['values']['mail'];
  }
  else {
    $mobile = $form_state['values']['mobile'];
  }

  $mail = $form_state['values']['mail'];
  switch ($form_state['step']) {

    case "1":
      // Check that the first value is alphabetic
      if (function_exists('itg_sso_user_email_check')) {
        $get_user_check_email = itg_sso_user_email_check($mail);
      }
      if (function_exists('itg_sso_user_mobile_check')) {
        $get_user_check_mobile = itg_sso_user_mobile_check($mobile);
      }

      if (!empty($get_user_check_email)) {
        form_set_error('mail', t("Email Id Already Exist!"));
      }

      if (!empty($get_user_check_mobile) && !empty($form_state['values']['mobile'])) {
        form_set_error('mobile', t("Mobile Number Already Exist!"));
      }

      $u_mobile = $form_state['values']['mobile'];
      if (!empty($u_mobile)) {
        if (!preg_match('/^\d{10}$/', $u_mobile)) {
          form_set_error('mobile', t("Enter valid Mobile Number!"));
        }
      }

      if (empty($mail) && empty($form_state['values']['mobile'])) {

        form_set_error('mail', t("Please Enter Email/Mobile !"));
      }

      $first_name = trim($form_state['values']['fname']);
      if ($first_name) {
        if (!preg_match("/^[a-zA-Z. ]*$/", $first_name)) {
          form_set_error('fname', t('First name accept only letters, dot and white space.'));
        }
      }
      $last_name = trim($form_state['values']['lname']);
      if ($last_name) {
        if (!preg_match("/^[a-zA-Z. ]*$/", $last_name)) {
          form_set_error('lname', t('Last name accept only letters, dot and white space.'));
        }
      }

      if (!empty($form_state['values']['mail'])) {

        if (!filter_var($form_state['values']['mail'], FILTER_VALIDATE_EMAIL)) {
          form_set_error('mail', t('Please enter valid email address.'));
        }
      }

      $pass = $form_state['values']['password'];
      $cpass = $form_state['values']['password_again'];
      
      $min_length = 3;
      $max_length = 10;
      
      if (strlen($pass) < $min_length) {
        form_set_error('pass', t('password is too short, minimum is '. $min_length. ' characters '));
      }
      elseif (strlen($pass) > $max_length) {
        form_set_error('pass', t('password is too long, maximum is '. $max_length. ' characters '));
      }
      
      if ($pass != $cpass) {
        form_set_error('pass', t('Password do not match.'));
      }

      break;

    case "2":
      // Check that the second value is numeric
      if (function_exists('itg_sso_reg_get_otp')) {
        $otp_match = itg_sso_reg_get_otp($form_state['values']['step2mobile'], $mail, 'register');
      }

      if (!empty($form_state['values']['step2mobile'])) {
        
        if ($otp_match != $form_state['values']['otp']) {
          form_set_error('otp', t("Enter valid OTP!"));
        }
      }
      break;

    case "3":
      // Check that the third value is alphanumeric

      break;
  }
}

/**
 * Implements hook_form_submit().
 * {@inheritdoc}
 */
function itg_sso_reg_multistep_form_submit($form, &$form_state) {
  // First we determine which step we are on, and save the
  // submitted values to $form_state['storage']. This will
  // allow our submitted values to persist.
  $step = $form_state['step'];
 
  $form_state['storage']['step_' . $step] = $form_state['values']['step_' . $step];

  // Check to see if the next/forward button was clicked
  if (isset($form_state['values']['forward']) && $form_state['values']['op'] == $form_state['values']['forward']) {
    // Increase the step by one, to move on to the next step
    if ($step == '1') {

      if (empty($form_state['values']['mobile'])) {
        $mobile = $form_state['values']['mail'];
      }
      else {
        $mobile = $form_state['values']['mobile'];
      }

      // if email field empty fill firstname@nowhere.com as dummy name
      if (empty($form_state['values']['mail'])) {
        $mail = $form_state['values']['fname'] . '@' . 'nowhere.com';
      }
      else {
        $mail = $form_state['values']['mail'];
      }
      
      // prepare array for user
      $edit = array(
        'name' => $mobile,
        'pass' => $form_state['values']['password'],
        'mail' => $mail,
        'init' => $mail,
        'status' => 1,
        'access' => REQUEST_TIME,
        'field_first_name' => array(
          LANGUAGE_NONE => array(
            0 => array(
              'value' => $form_state['values']['fname']
            )
          )
        ),
        'field_last_name' => array(
          LANGUAGE_NONE => array(
            0 => array(
              'value' => $form_state['values']['lname']
            )
          )
        ),
        'roles' => array(
          2 => 'authenticated',
          FRONT_USER => 'Front User',
        ),
      );
      
      if (is_numeric($mobile)) {
        $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
            0 => array(
              'value' => $mobile
            )
          )
        );
      }


      try {

        $account = user_save(NULL, $edit);

        if(function_exists('itg_personalization_reddem_referfriend')) {
          itg_personalization_reddem_referfriend($_SESSION['referral_key']);
          unset($_SESSION['referral_key']);
        }
        // Set operation.
        $op = 'register_no_approval_required';
        // Send an email.
        if (empty($form_state['values']['mobile'])) {
          // _user_mail_notify($op, $account);
          if (function_exists('itg_sso_get_mail_content')) {
            if(!empty($form_state['values']['url_info'])) {
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
            itg_sso_sms_send($rand_otp, $mobile);
          }
          if(!empty($form_state['values']['mail'])) {
            itg_sso_otp_mail_content($rand_otp, $mail);
          }
        }

        $mobile = isset($form_state['values']['mobile']) ? $form_state['values']['mobile'] : '';
        if (!empty($mail) && empty($mobile)) {
          $form_state['step'] = 3;
        }
        else {
          $form_state['step'] ++;
        }
      }
      catch (Exception $e) {
        watchdog('error on user save', $e->getMessage());
        drupal_set_message('Error:' . $e->getMessage(), 'error');
      }
    }
  }
  
  // Check to see if the final step has been submitted
  elseif (isset($form_state['values']['submit']) && $form_state['values']['op'] == $form_state['values']['submit']) {
    // Here we will collect the data and show the submitted values to the user in a message.
    // In a real-world application of this form, you would use the submitted values to complete the
    // purpose of the form - save them to the database and/or send an email and/or display something
    // to the user etc. The following is just s simple example to show how the values can be used.
    //$items = array($form_state['storage']['step_1'], $form_state['storage']['step_2'], $form_state['storage']['step_3']);
    //drupal_set_message(t('You submitted the following values:!values', array('!values' => theme('item_list', array('items' => $items)))));
    $multstep_values = $form_state['multistep_values'];
    itg_sso_otp_delete($form_state['values']['step2mail'], $form_state['values']['step2mobile'], 'register');
    // The form has been completed, so we want to return the user to step 1
    // as well as clear any saved values.
    $form_state['step'] = 4;
    $form_state['storage'] = array();
  }
  

  // As in ajax_form_multistep_form_back_submit(), we need to set
  // $form_state['rebuild'] to TRUE, in able to ensure that our
  // our form is rebuilt, allowing for the multi-step process
  $form_state['rebuild'] = TRUE;
}

function itg_sso_reg_multistep_form_ajax_callback($form, &$form_state) {
  return $form;
}