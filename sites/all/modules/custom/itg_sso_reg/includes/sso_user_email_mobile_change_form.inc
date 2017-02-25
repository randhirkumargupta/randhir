<?php

/**
 * Master form which calls an individual form for each step.
 * 
 * @see itg_sso_user_email_form_validate().
 * @see itg_sso_user_email_form_submit().
 * 
 * @param type $form
 * @param string $form_state
 * @return type 
 */
function itg_sso_user_email_form($form, &$form_state) {

  if (!isset($form_state['stage']))
    $form_state['stage'] = 'step_1';
  $form = array();
  //  if (user_is_anonymous()) {
//    return drupal_access_denied();
//  }
  

  // get unique id form argument
  $unique_id = base64_decode(arg(2));
  // make configuration for js file
  global $user, $base_url;
  $settings = array();
  $settings['base_url'] = $base_url;
  $settings['uid'] = $user->uid;
  drupal_add_js(array('itg_sso_reg' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_sso_reg') . '/js/itg_sso_change_email.js');

  // check form stage
  switch ($form_state['stage']) {

    case 'step_1':
      return itg_sso_user_email_step_1_form($form, $form_state, $unique_id);
      break;

    case 'step_2':
      return itg_sso_user_email_step_2_form($form, $form_state);
      break;

    case 'step_3':
      return itg_sso_user_email_step_3_form($form, $form_state);
      break;

    default:
      return itg_sso_user_email_step_1_form($form, $form_state);
      break;
  }

  return $form;
}

/**
 * Form for the rate_the_room step.
 * 
 * @see itg_sso_user_email_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function itg_sso_user_email_step_1_form($form, &$form_state, $unique_id) {

  $values = isset($form_state['multistep_values']['step_1']) ? $form_state['multistep_values']['step_1'] : array();
  
  $form['heading'] = array(
    '#markup' => '<h3>' . drupal_set_title('Change Email/Mobile') . '</h3>',
  );
  
  $form['emobile'] = array(
    '#title' => t('Email/Mobile'),
    '#description' => '',
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Email/Mobile'), 'autocomplete' => 'off'),
    '#prefix' => '<div id="ufname">',
    '#suffix' => '</div>',
  );

  $form['unique_id'] = array(
    '#title' => '',
    '#description' => '',
    '#type' => 'hidden',
    '#value' => $unique_id,
  );


  $form['domain_info_url'] = array(
    '#type' => 'hidden',
    '#title' => t(''),
    '#value' => base64_decode(arg(3)),
  );


  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}

/**
 * Form for the rate_the_service step.
 * 
 * @see itg_sso_user_email_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function itg_sso_user_email_step_2_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['step_2']) ? $form_state['multistep_values']['step_2'] : array();
  $form['emobile'] = array(
    '#title' => '',
    '#description' => '',
    '#type' => 'hidden',
    '#value' => $form_state['values']['emobile'],
  );

  $form['unique_id'] = array(
    '#title' => '',
    '#description' => '',
    '#type' => 'hidden',
    '#value' => $form_state['values']['unique_id'],
  );

  $form['domain_info_url'] = array(
    '#type' => 'hidden',
    '#title' => t(''),
    '#value' => $form_state['values']['domain_info_url'],
  );

  $form['fotp'] = array(
    '#title' => '',
    '#description' => '',
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#attributes' => array('placeholder' => t('OTP'), 'autocomplete' => 'off'),
    '#prefix' => '<div id="fotp">',
  );

  $form['forgot_otp_links'] = array(
    '#markup' => '<div id="forgototpclickme">Resend OTP</div>',
  );

  $form['loader'] = array(
    '#markup' => '<div id="ajax-loader" style="display:none">
      <img src="' . base_path() . path_to_theme() . '/images/loader.svg" alt=""/>
      </div>
    ',
  );

  $form['forgot_otp_success'] = array(
    '#markup' => '<div id="forgot_otp_success"></div>',
    '#suffix' => '</div>',
  );


  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );

  return $form;
}

/**
 * Given the current stage the user is on, calculate what the next step would be
 * 
 * @param type $form_state
 * @return string 
 */
function customer_survey_move_to_next_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'step_1':
      return 'step_2';
      break;

    case 'step_2':
      return 'step_3';
      break;
  }
}

/**
 * Handles what to do with the submitted form depending on what stage has been
 * completed.
 * 
 * @see itg_sso_user_email_form()
 * @see itg_sso_user_email_form_validate()
 * 
 * @param type $form
 * @param type $form_state 
 */
function itg_sso_user_email_form_submit($form, &$form_state) {
  $unique_id = $form_state['values']['unique_id'];
  $account_id = user_load_by_name(array('name' => $unique_id));
  $account = user_load($account_id->uid);
  $emobile = $form_state['values']['emobile'];
  switch ($form_state['stage']) {
    case 'step_2':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];

      if ($form_state['triggering_element']['#value'] != 'Back') {

        if (is_numeric($emobile)) {
          //if (is_numeric($unique_id)) {
            $edit = array(
              'name' => $emobile,
              'field_mobile_number' => array(
                LANGUAGE_NONE => array(
                  0 => array(
                    'value' => $emobile
                  )
                )
              )
            );
         // }
          /*else {
            $edit = array(
              'name' => $emobile,
              'field_mobile_number' => array(
                LANGUAGE_NONE => array(
                  0 => array(
                    'value' => $emobile
                  )
                )
              )
            );
          }*/
        }
        else {

          if (!is_numeric($unique_id)) {
            $edit = array(
              'name' => $emobile,
              'mail' => $emobile
            );
          }
          else {
            $edit = array(
              'mail' => $emobile
            );
          }
        }

        // save existing user
//        user_save(
//            (object) array('uid' => $account_id->uid), $edit);
        user_save($account, $edit);

        if (is_numeric($emobile)) {
          if (function_exists(itg_sso_otp_delete)) {
            itg_sso_otp_delete($mail = '', $emobile, 'change_email_mobile');
          }
        }
        else {
          if (function_exists(itg_sso_otp_delete)) {
            itg_sso_otp_delete($emobile, $mobile = '', 'change_email_mobile');
          }
        }
        $form_state['complete'] = TRUE;
      }
      break;

    case 'step_1':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      if ($form_state['triggering_element']['#value'] != 'Back') {
        $emobile = $form_state['values']['emobile'];
        if (is_numeric($emobile)) {
          $rand_otp = rand(0, 9999);
          if (function_exists(itg_sso_first_time_otp_insert)) {
            itg_sso_first_time_otp_insert($emobile, $email = '', $rand_otp, 'change_email_mobile');
            itg_sso_sms_send($rand_otp, $emobile);
          }
          drupal_set_message('Please check your mobile for otp');
          // to do mobile script for sending sms
        }
        else {
          $rand_otp = rand(0, 9999);
          if (function_exists(itg_sso_first_time_otp_insert)) {
            itg_sso_first_time_otp_insert($mobile = '', $emobile, $rand_otp, 'change_email_mobile');
          }
          if (function_exists(itg_forgot_otp_content)) {
            $mail_content = itg_forgot_otp_content($rand_otp, $emobile);
          }

          drupal_set_message('Please check your mail for otp');
        }

        $form_state['new_stage'] = customer_survey_move_to_next_stage($form, $form_state);
      }
      break;



    default:
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $form_state['new_stage'] = customer_survey_move_to_next_stage($form, $form_state);
      break;
  }

  if (isset($form_state['complete']))
    drupal_goto('complete-page/' . $form_state['values']['domain_info_url']);

  if ($form_state['triggering_element']['#value'] == 'Back') {
    $form_state['new_stage'] = customer_survey_move_to_previous_stage($form, $form_state);
  }

  if (isset($form_state['multistep_values']['form_build_id'])) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }
  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  $form_state['stage'] = $form_state['new_stage'];
  $form_state['rebuild'] = TRUE;
}

/**
 * Master validation function for the customer survey form - uses per-stage 
 * validation and calls functions for each one.
 * 
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function itg_sso_user_email_form_validate($form, &$form_state) {

  if ($form_state['triggering_element']['#value'] == 'Back') {
    return;
  }

  switch ($form_state['stage']) {

    case 'step_1':
      return step_1_validate($form, $form_state);
      break;

    case 'step_2':
      return step_2_validate($form, $form_state);
      break;
  }
}

/**
 * Validation for the step_1_validate step
 * 
 * @param type $form
 * @param type $form_state 
 */
function step_1_validate($form, &$form_state) {
  if (!$form_state['values']['emobile']) {
    form_set_error('emobile', 'Please Enter Mobile/Email');
  }


  // Check that the first value is alphabetic
  $emobile = $form_state['values']['emobile'];

  if (is_numeric($emobile)) {
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($emobile);
      if (!empty($get_user_check_mobile)) {
        form_set_error('emobile', t("Mobile No. Already Exist!"));
      }
      if (!preg_match('/^\d{10}$/', $emobile)) {
        form_set_error('emobile', t("Enter valid Mobile Number!"));
      }
    }
  }
  else {
    if (!empty($emobile)) {

      if (!filter_var($emobile, FILTER_VALIDATE_EMAIL)) {
        form_set_error('mail', t('Please enter valid email address.'));
      }

      if (function_exists(itg_sso_user_email_check)) {
        $get_user_check_email = itg_sso_user_email_check($emobile);
        if (!empty($get_user_check_email)) {
          form_set_error('emobile', t("Email Already Exist!"));
        }
      }
    }
  }
}

/**
 * Validation for the step_2_validate step
 * 
 * @param type $form
 * @param type $form_state 
 */
function step_2_validate($form, &$form_state) {
  // Check that the second value is numeric
  $emobile = $form_state['values']['mobile'];
  $otp = $form_state['values']['fotp'];
  if (function_exists(itg_sso_reg_get_otp)) {
    if (is_numeric($ufname)) {
      $otp_match = itg_sso_reg_get_otp($emobile, $email = '', 'change_email_mobile');
    }
    else {
      $otp_match = itg_sso_reg_get_otp($emobile = '', $unemail, 'change_email_mobile');
    }
  }

  if (empty($otp)) {

    form_set_error('otp', t("Enter OTP!"));
  }

  if ($otp_match != $otp) {

    form_set_error('otp', t("Enter valid OTP!"));
  }
}

/**
 * Implements itg_sso_user_email_complete().
 */
function itg_sso_user_email_complete() {
  if (user_is_anonymous()) {
    return drupal_access_denied();
  }
  else {
    $form['email_success'] = array(
      '#prefix' => '<div class="email-success">',
      '#markup' => 'Your Email/Mobile has been changed successfully!</div>',
    );

    return $form;
  }
}
