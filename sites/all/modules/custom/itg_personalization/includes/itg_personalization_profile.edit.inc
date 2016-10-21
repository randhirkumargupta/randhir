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
  $user_detail = user_load($user->uid);    
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
    '#attributes' => array('placeholder' => 'E.g., abc@example.com'),
    '#default_value' => $user_detail->mail,
  );
  $form['mobile'] = array(
    '#title' => t('Mobile'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#attributes' => array('placeholder' => 'E.g., +91 9999999999'),
    '#default_value' => $user_detail->field_mobile_number['und'][0]['value'],
  );
  $form['dob'] = array(
    '#type' => 'date_popup',
    '#title' => t("DOB"),
    '#date_format' => 'Y/m/d',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => $user_detail->field_story_issue_date['und'][0]['value'],
    '#date_timezone' => date_default_timezone(),
  );
  $form['gender'] = array(
    '#title' => t('Gender'),
    '#type' => 'radios',
    '#options' => array(
      'male' => 'Male',
      'female' => 'Female'
    ),
    '#default_value' => $user_detail->field_user_gender['und'][0]['value'],
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
  $form['qualification'] = array(
    '#title' => t('Qualification'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $user_detail->field_user_qualification['und'][0]['tid'],
  );
  $form['address'] = array(
    '#title' => t('Address'),
    '#type' => 'textarea',
    '#default_value' => $user_detail->field_short_description['und'][0]['value'],
  );
  $form['news_letter'] = array(
    '#title' => t('Subscribe Our Newsletters'),
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array('India Today', 'Aaj Tak', 'Business Today')),    
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
  if (!is_numeric($form_state['values']['mobile'])) {
    form_set_error('mobile', t('Please enter valid mobile number.'));
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
  $user_detail->field_first_name['und'][0]['value'] = check_plain($inputs['fname']);
  // Update Last Name.
  $user_detail->field_last_name['und'][0]['value'] = check_plain($inputs['lname']);
  // Update mail field.
  $user_detail->mail = check_plain($inputs['mail']);
  // Update mobile field.
  $user_detail->field_mobile_number['und'][0]['value'] = check_plain($inputs['mobile']);
  // Update dob field.
  $user_detail->field_story_issue_date['und'][0]['value'] = check_plain($inputs['dob']);
  // Update gender field.
  $user_detail->field_user_gender['und'][0]['value'] = check_plain($inputs['gender']);
  // Update profile pic
  $user_detail->field_user_picture['und'][0]['fid'] = check_plain($inputs['profile_pic']);
  // Update Qualification field.
  $user_detail->field_user_qualification['und'][0]['tid'] = check_plain($inputs['qualification']);
  // Update address field.
  $user_detail->field_short_description['und'][0]['value'] = check_plain($inputs['address']);
  //Update News Letters field.  
  foreach ($inputs['news_letter'] as $value) {    
    if ($value != '0') {      
      $data[]['value'] = $value;
    }
  }  
  $user_detail->field_subscribe_for_newsletter['und'] = $data;  
  user_save($user_detail);
}
