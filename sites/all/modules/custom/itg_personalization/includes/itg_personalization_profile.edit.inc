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
function itg_personalization_edit_profile_form() {
  global $user;
  //prepare url for change mobile and email
  $edit_email_url = $edit_email_link= $edit_mobile_url = $edit_mobile_link = '';
  if (strpos($user->name, '@') != false || is_numeric($user->name)) {
    $edit_email_url = 'http://' . PARENT_SSO . '/sso-user/email/' . base64_encode($user->name) . '/' . base64_encode($_SERVER['HTTP_HOST']);
    $edit_email_link = '<a href="javascript:void(0)"  onclick="CenterWindow(550, 200, 50, ' . "'" . $edit_email_url . "'" . ');">Edit</a>';
    $edit_mobile_url = 'http://' . PARENT_SSO . '/sso-user/mobile/' . base64_encode($user->name) . '/' . base64_encode($_SERVER['HTTP_HOST']);
    $edit_mobile_link = '<a href="javascript:void(0)"  onclick="CenterWindow(550, 200, 50, ' . "'" . $edit_mobile_url . "'" . ');">Edit</a>';
  }
  
  $user_detail = user_load($user->uid);
  if (is_numeric($user_detail->name)) {
    $mobile = $user_detail->name;
  }
  else {
    $mobile = $user_detail->field_mobile_number['und'][0]['value'];
  }
  // email setting
  if (strpos($user_detail->mail, 'nowhere.com') !== false) {
    $email = '';
  }
  else {
    $email = $user_detail->mail;
  }
  
  $form['fname'] = array(
    '#title' => t('First Name'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array('placeholder' => 'E.g., Ram'),
    '#default_value' => $user_detail->field_first_name['und'][0]['value'],
  );
  $form['lname'] = array(
    '#title' => t('Last Name'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array('placeholder' => 'E.g., Patel'),
    '#default_value' => $user_detail->field_last_name['und'][0]['value'],
  );
  $form['mail'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => 'E.g., abc@example.com',
      'readonly' => TRUE
    ),
    '#prefix' => '<div class="change-email">',
    '#default_value' => $email,
    '#suffix' => $edit_email_link . '</div>',
  );
  $form['mobile'] = array(
    '#title' => t('Mobile'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#attributes' => array(
      'placeholder' => 'E.g., +91 9999999999',
      'readonly' => TRUE,
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
    '#upload_location' => 'public://profile_pic/',
    '#description' => 'Files must be less than<strong>512 MB</strong>.<br>Allowed file types:<strong>gif jpg jpeg</strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("gif jpeg jpg"),
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
  $form['address'] = array(
    '#title' => t('Address'),
    '#type' => 'textarea',
    '#default_value' => $user_detail->field_short_description['und'][0]['value'],
  );
  $form['zip_code'] = array(
    '#title' => t('Pincode'),
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'E.g., 122016'),
    '#default_value' => $user_detail->field_user_pincode['und'][0]['value'],
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

  return $form;
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
  $first_name = trim($form_state['values']['fname']);
  if ($first_name) {
    if (!preg_match("/^[a-zA-Z. ]*$/", $first_name)) {
      form_set_error('fname', t('Please enter only letters, dot and white space allowed.'));
    }
  }
  $last_name = trim($form_state['values']['lname']);
  if ($last_name) {
    if (!preg_match("/^[a-zA-Z. ]*$/", $last_name)) {
      form_set_error('lname', t('Please enter only letters, dot and white space allowed.'));
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
  }

  // Update address field.
  if (!empty($inputs['address'])) {
    $user_detail->field_short_description['und'][0]['value'] = check_plain($inputs['address']);
  }

  // Update zipcode field.
  if (!empty($inputs['zip_code'])) {
    $user_detail->field_user_pincode['und'][0]['value'] = check_plain($inputs['zip_code']);
  }

  //Update News Letters field.  
  $flag = FALSE;
  foreach ($inputs['news_letter'] as $value) {
    $flag = TRUE;
    if ($value != '0') {
      $data[]['value'] = $value;
      itg_loyalty_reward_earnpoint(0, 'ns', $user->uid, $value);
    }
  }
  if ($flag) {
    $user_detail->field_subscribe_for_newsletter['und'] = $data;
  }

  // Save user object.
  user_save($user_detail);
}

?>
