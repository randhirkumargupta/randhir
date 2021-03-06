<?php

/*
 * @file
 *   Edit profile form and submit function. 
 */

/**
 * Implements hook_form()
 *
 * {@inheritdoc}
 */
function itg_personalization_edit_profile_form($form, &$form_state) {
  global $user;
  
  if (!empty(SITE_PROTOCOL)) {
    $scheme = SITE_PROTOCOL;
  }
  else {
    $scheme = 'http://';
  }
  
  $uri = base64_encode($scheme . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
  //prepare url for change mobile and email
  $edit_email_url = $edit_email_link= $edit_mobile_url = $edit_mobile_link = '';
  if (strpos($user->name, '@') != false || is_numeric($user->name)) {
    $edit_email_url = PARENT_SSO . '/sso-user/email/' . base64_encode($user->name) . '/' . $uri;
    $edit_email_link = '<a href="'.$edit_email_url .'">Edit</a>';
  }
  // edit mobile link of user
  $edit_mobile_url =  PARENT_SSO . '/sso-user/mobile/' . base64_encode($user->name) . '/' . $uri;
  $edit_mobile_link = '<a href="'. $edit_mobile_url .'">Edit</a>';
  
  $user_detail = user_load($user->uid);
  if (strpos($user_detail->mail, '@twitter.com') !== false || strpos($user_detail->mail, '@facebook.com') !== false) {
    if (array_key_exists(FRONT_USER, $user->roles)) {
      // code to use in optimization using drupal http request.
      if (function_exists('itg_global_loyality_get_sso_id')) {
        $sso_final_id = itg_global_loyality_get_sso_id($user->uid);
      }
      if (empty($sso_final_id)) {
        $sso_id = $user->uid;
      }
      else {
        $sso_id = $sso_final_id;
      }
      if (function_exists('itg_sso_get_social_uid')) {
        $mobile = itg_sso_get_social_uid($sso_id);
      }
    }
  }
  else {
    if(is_numeric($user_detail->name)) {
      $mobile = $user_detail->name;
    } else {
      $mobile = $user_detail->field_mobile_number['und'][0]['value'];
    }
  }
  // email setting
  if (strpos($user_detail->mail, 'nowhere.com') !== false) {
    $email_required = FALSE;
    $email = '';
  }
  else {
    $email = $user_detail->mail;
    $email_required = TRUE;
  }
  
  $form['fname'] = array(
    '#title' => t('First Name'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => true,
    '#attributes' => array('placeholder' => 'E.g., Ram', 'autocomplete' => 'off'),
    '#default_value' => $user_detail->field_first_name['und'][0]['value'],
  );
  $form['lname'] = array(
    '#title' => t('Last Name'),
    '#type' => 'textfield',
    '#required' => true,
    '#maxlength' => 255,
    '#attributes' => array('placeholder' => 'E.g., Patel', 'autocomplete' => 'off'),
    '#default_value' => $user_detail->field_last_name['und'][0]['value'],
  );
  $form['mail'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => $email_required,
    '#attributes' => array(
      'placeholder' => 'E.g., abc@example.com',
      'readonly' => TRUE,
      'autocomplete' => 'off'
    ),
    '#prefix' => '<div class="change-email">',
    '#default_value' => $email,
    '#suffix' => $edit_email_link . '</div>',
  );
  if (strpos($email, '@twitter.com') !== false || strpos($email, '@facebook.com') !== false) {
    $form['alt_email'] = array(
      '#title' => t('Alternate Email'),
      '#type' => 'textfield',
      '#maxlength' => 255,
      '#attributes' => array(
        'placeholder' => 'E.g., xyz@example.com',
        'autocomplete' => 'off'
      ),
      '#prefix' => '<div class="al-email">',
      '#suffix' => '</div>',
      '#default_value' => $user_detail->field_user_alternate_email[LANGUAGE_NONE][0]['value'],
    );
  }
  
  $form['mobile'] = array(
    '#title' => t('Mobile'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#attributes' => array(
      'placeholder' => 'E.g., +91 9999999999',
      'readonly' => TRUE,
      'autocomplete' => 'off',
    ),
    '#prefix' => '<div class="change-mobile">',
    '#suffix' => $edit_mobile_link . '</div>',
    '#default_value' => $mobile,
  );
  $dob_default_value = '';
  if (!empty($user_detail->field_story_issue_date['und'][0]['value'])) {
    $dob_default_value = $user_detail->field_story_issue_date['und'][0]['value'];
  }
  $form['dob'] = array(
    '#type' => 'date_popup',
    '#title' => t("DOB"),
    '#date_format' => 'd/m/Y',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => $dob_default_value,
    '#date_year_range' => '1900:+0d',
    '#datepicker_options' => array('maxDate' => '+0d'),
    '#date_timezone' => date_default_timezone(),
  );
  $gender_default_value = '';
  if (!empty($user_detail->field_user_gender['und'][0]['value'])) {
    $gender_default_value = $user_detail->field_user_gender['und'][0]['value'];
  }
  $form['gender'] = array(
    '#title' => t('Gender'),
    '#type' => 'radios',
    '#options' => array(
      'male' => 'Male',
      'female' => 'Female'
    ),
    '#default_value' => $gender_default_value,
  );
  $form['profile_pic'] = array(
    '#title' => t('Profile Pic'),
    '#type' => 'managed_file',
    '#upload_location' => file_default_scheme() . '://sso_user_image/',
    '#description' => 'Files must be less than<strong>512 MB</strong>.<br>Allowed file types:<strong>gif jpg jpeg</strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("jpeg jpg png"),
      "file_validate_size" => array(500 * 1024 * 1024),
    ),
    '#default_value' => $user_detail->field_user_picture['und'][0]['fid'],
  );
  // Get options.
  $itg_vid = taxonomy_vocabulary_machine_name_load('qualification');
  $itg_term = taxonomy_get_tree($itg_vid->vid, 0, NULL, TRUE);
  $options = array('_none' => '- Select -');
  foreach ($itg_term as $term) {
    $options[$term->tid] = $term->name;
  }
  $default_qualification = '';
  if (!empty($user_detail->field_user_qualification['und'][0]['tid'])) {
    $default_qualification = $user_detail->field_user_qualification['und'][0]['tid'];
  }
  $form['qualification'] = array(
    '#title' => t('Qualification'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $default_qualification,
  );
  
  // Get options.
  $itg_country_vid = taxonomy_vocabulary_machine_name_load('country');
  $itg_country_term = taxonomy_get_tree($itg_country_vid->vid, 0, NULL, TRUE);
  $country = array('_none' => '- Select -');
  foreach ($itg_country_term as $term) {
    $country[$term->tid] = $term->name;
  }
  $default_country = '';
  if (!empty($user_detail->field_user_counrty['und'][0]['tid'])) {
    $default_country = $user_detail->field_user_counrty['und'][0]['tid'];
  }
  
  $form['country'] = array(
    '#title' => t('Country'),
    '#type' => 'select',
    '#options' => $country,
    '#default_value' => $default_country,
    '#ajax' => array(
    'event' => 'change',
    'wrapper' => 'state-wrapper',
    'callback' => 'itg_personalization_state_ajax_callback',
    'method' => 'replace',
  ),
  );

  if(!empty($form_state['values']['country'])) {
    $state = get_state_by_country($form_state['values']['country']);
  } else {
    $state = get_state_by_country($user_detail->field_user_counrty['und'][0]['tid']);
  }
  
  $default_state = '';
  if (!empty($user_detail->field_personalization_state['und'][0]['tid'])) {
    $default_state = $user_detail->field_personalization_state['und'][0]['tid'];
  } else {
    $default_state = isset($form_state['values']['user_state']) ? $form_state['values']['user_state'] : '';
  }
  
  $form['user_state'] = array(
    '#type' => 'select',
    '#prefix' => '<div id="state-wrapper">',
    '#suffix' => '</div>',
    '#default_value' => $default_state, 
    '#title' => t('State'),
    '#options' => $state,
    '#ajax' => array(
    'event' => 'change',
    'wrapper' => 'city-wrapper',
    'callback' => 'itg_personalization_city_ajax_callback',
    'method' => 'replace',
  ),
  );
  
  /*if($form_state['values']['user_state'] != '_none') {
    $city = get_city_by_state($form_state['values']['user_state']);
  } else {
    $city = get_city_by_state($user_detail->field_personalization_state['und'][0]['tid']);
  }*/
  $city = get_city_by_state();
  $default_city = '';
  if (!empty($user_detail->field_personalization_city['und'][0]['tid'])) {
    $default_city = $user_detail->field_personalization_city['und'][0]['tid'];
  } else {
    $default_city = isset($form_state['values']['user_city']) ? $form_state['values']['user_city'] : '';
  }
  $form['user_city'] = array(
    '#type' => 'select',
    //'#prefix' => '<div id="city-wrapper">',
    //'#suffix' => '</div>',
    '#default_value' => $default_city, 
    '#title' => t('City'),
    '#options' => $city,
  );

  $form['address'] = array(
    '#title' => t('Address'),
    '#type' => 'textarea',
    '#default_value' => $user_detail->field_short_description['und'][0]['value'],
  );
  $form['zip_code'] = array(
    '#title' => t('Pincode'),
    '#type' => 'textfield',
    '#maxlength' => 6,
    '#attributes' => array('placeholder' => 'E.g., 122016'),
    '#default_value' => $user_detail->field_user_pincode['und'][0]['value'],
  );
  $forget_me = $user_detail->field_forget_me['und'][0]['value'];
  $form['forget_me'] = array(
    '#title' => '',
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array('Forget Me')),
    '#default_value' => $forget_me,
  );
  // create default value for newsletter subscription.
  $data = array();
  if (isset($user_detail->field_subscribe_for_newsletter['und']) && is_array($user_detail->field_subscribe_for_newsletter['und'])) {
    foreach ($user_detail->field_subscribe_for_newsletter['und'] as $option) {
      $data[] = $option['value'];
    }
  } else {
    $data = array('India Today', 'Aaj Tak', 'Business Today');
  }
  $form['news_letter'] = array(
    '#title' => t('Subscribe Our Newsletters'),
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array('India Today', 'Aaj Tak', 'Business Today')),
    '#default_value' => $data,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['user_state']['#states'] = array(
      'visible' => array(
        ':input[name="country"]' => array('!value' => '_none'),
      ),
    );
  
  $form['user_city']['#states'] = array(
      'visible' => array(
        ':input[name="user_state"]' => array('!value' => '_none'),
      ),
    );
  
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_personalization') . '/js/itg_personalization.js',
    drupal_get_path('module', 'itg_astro') . '/js/jquery.validate.min.js',
  );
  
  return $form;
}

/**
 * Ajax callback for state dropdown
 * @param array $form
 * @param array $form_state
 * @return int
 */
function itg_personalization_state_ajax_callback($form, &$form_state) {
  return $form['user_state'];
}

/**
 * Ajax callback for city dropdown
 * @param array $form
 * @param array $form_state
 * @return int
 */
function itg_personalization_city_ajax_callback($form, &$form_state) {
  return $form['user_city'];
}

/**
 * 
 * @param type $country_id
 * @return type
 */
function get_state_by_country($country_id) {
    $query = db_select('field_data_field_state_county', 'c');
    $query->fields('c', array('entity_id'));
    if (!empty($country_id)) {
    $query->condition('c.field_state_county_tid', $country_id);
    }
    $result = $query->execute();
    $state_list = array('_none' => '- Select state -');
    while ($record = $result->fetchAssoc()) {
      if(function_exists('get_term_name_from_tid_for_report')) {
        $name = get_term_name_from_tid_for_report($record['entity_id']);
      }
      $state_list[$record['entity_id']] = $name;
    }

    return $state_list;
}

/**
 * 
 * @param type $state_id
 * @return type
 */
function get_city_by_state($state_id) {
  
    $query = db_select('field_data_field_city_states', 'c');
    $query->fields('c', array('entity_id'));
    if (!empty($state_id)) {
    $query->condition('c.field_city_states_tid', $state_id);
    }
    $result = $query->execute();
    $city_list = array('_none' => '- Select city -');
    while ($record = $result->fetchAssoc()) {
      if(function_exists('get_term_name_from_tid_for_report')) {
        $name = get_term_name_from_tid_for_report($record['entity_id']);
      }
      $city_list[$record['entity_id']] = $name;
    }

    return $city_list;
  
}

/**
 * Implements hook_validate().
 *
 * {@inheritdoc}.
 */
function itg_personalization_edit_profile_form_validate($form, &$form_state) {
  if ($form_state['values']['mail']) {
    $user_email = substr($form_state['values']['mail'], strpos($form_state['values']['mail'], "@") + 1);
    $user_email_count = substr_count($user_email, '.');
    if ($user_email_count > 2) {
      form_set_error('mail', t('Please enter valid email address.'));
    }
  }
  // validate alternate email
  if (function_exists('itg_sso_user_email_check')) {
    $get_user_check_email = itg_sso_user_email_check($form_state['values']['alt_email']);
  }
  if (!empty($form_state['values']['alt_email'])) {
    if (!filter_var($form_state['values']['alt_email'], FILTER_VALIDATE_EMAIL)) {
      form_set_error('mail', t('Please enter valid email address.'));
    }
    else if (!empty($get_user_check_email)) {
      form_set_error('mail', t("Email id Already Exist!"));
    }
  }
}

/**
 * Implements hook_submit().
 *
 * {@inheritdoc}.
 */
function itg_personalization_edit_profile_form_submit($form, &$form_state) {
  global $user;
  if (function_exists('itg_global_loyality_get_sso_id')) {
    $sso_id = itg_global_loyality_get_sso_id($user->uid);
  }
  $inputs = $form_state['values'];
  $user_detail = user_load($user->uid);
  // Update First Name.
  if (!empty($inputs['fname'])) {
    $user_detail->field_first_name['und'][0]['value'] = check_plain($inputs['fname']);
  }

  // Update Last Name.
  if (!empty($inputs['lname'])) {
    $user_detail->field_last_name['und'][0]['value'] = check_plain($inputs['lname']);
  }

  // Update alternate email.
  if (!empty($inputs['alt_email'])) {
    $user_detail->field_user_alternate_email['und'][0]['value'] = check_plain($inputs['alt_email']);
  } else {
    unset($user_detail->field_user_alternate_email['und']);
  }
  
   // update mobile number
  if (!empty($inputs['mobile'])) {
    $user_detail->field_mobile_number['und'][0]['value'] = check_plain($inputs['mobile']);
  }
  
  // Update dob field.
  if (!empty($inputs['dob'])) {
    $user_detail->field_story_issue_date['und'][0]['value'] = check_plain($inputs['dob']);
  }

  // Update gender field.
  if (!empty($inputs['gender'])) {
    $user_detail->field_user_gender['und'][0]['value'] = check_plain($inputs['gender']);
  }

  // Update profile pic
  if (!empty($inputs['profile_pic'])) {
    $user_detail->field_user_picture['und'][0]['fid'] = check_plain($inputs['profile_pic']);
  }

  // Update Qualification field.
  if (!empty($inputs['qualification']) && $inputs['qualification'] !== '_none') {
    $user_detail->field_user_qualification['und'][0]['tid'] = check_plain($inputs['qualification']);
  }else {
    unset($user_detail->field_user_qualification['und']);
  }

  // Update address field.
  if (!empty($inputs['address'])) {
    $user_detail->field_short_description['und'][0]['value'] = check_plain($inputs['address']);
  }

  // Update zipcode field.
  if (!empty($inputs['zip_code'])) {
    $user_detail->field_user_pincode['und'][0]['value'] = check_plain($inputs['zip_code']);
  }
  
  //update country
  if (!empty($inputs['country'])  && $inputs['country'] !== '_none') {
    $user_detail->field_user_counrty['und'][0]['tid'] = check_plain($inputs['country']);
  }else {
    unset($user_detail->field_user_counrty['und']);
  }
  
  //update state
  if (!empty($inputs['user_state']) && $inputs['user_state'] !== '_none') {
    $user_detail->field_personalization_state['und'][0]['tid'] = check_plain($inputs['user_state']);
  }else {
    unset($user_detail->field_personalization_state['und']);
  }
  
  if (!empty($inputs['forget_me'])) {
    $user_detail->field_forget_me['und'][0]['value'] = check_plain($inputs['forget_me']);
  }else {
    unset($user_detail->field_forget_me['und']);
  }
  
  if (!empty($inputs['country'])  && $inputs['country'] !== '_none') {
    $_country_data = get_country_by_tid($inputs['country']);
    if(!empty($_country_data->field_is_gdpr[LANGUAGE_NONE][0]['value']) || !empty($inputs['forget_me'])){
       $user_detail->status = 0;
    }
  }
  //update city
  if (!empty($inputs['user_city']) && $inputs['user_city'] !== '_none') {
    $user_detail->field_personalization_city['und'][0]['tid'] = check_plain($inputs['user_city']);
  }else {
    unset($user_detail->field_personalization_city['und']);
  }

  //Update News Letters field.  
  $flag = FALSE;
  foreach ($inputs['news_letter'] as $value) {
    $flag = TRUE;
    if ($value != '0') {
      $data[]['value'] = $value;
      //itg_loyalty_reward_earnpoint(0, 'ns', $user->uid, $value);
      itg_global_loyality_send_data($user->uid, 'Newsletter_subscription', 0, $value, $sso_id);
    }
  }
  if ($flag) {
    $user_detail->field_subscribe_for_newsletter['und'] = $data;
  }

  // Save user object.
  user_save($user_detail);
  
  if (function_exists('itg_global_loyality_get_sso_id')) {
   $sso_final_id = itg_global_loyality_get_sso_id($user->uid);
  }
  if (empty($sso_final_id)) {
    $sso_id = $user->uid;
  }
  else {
    $sso_id = $sso_final_id;
  }
  if(function_exists('global_update_alternate_email') && !empty($inputs['alt_email'])) {
    global_update_alternate_email(check_plain($inputs['alt_email']), $sso_id);
  }
  
  $_REQUEST['destination'] = 'personalization/edit-profile/general-settings';
  $success = base64_encode('success');
    $form_state['redirect'] = array(
      'personalization/edit-profile/general-settings',
      array('query' => array('profile' => $success))
    );
}