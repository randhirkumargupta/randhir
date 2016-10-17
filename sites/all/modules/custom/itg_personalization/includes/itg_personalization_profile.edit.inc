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
  $form['fname'] = array(
    '#title' => t('First Name'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array('placeholder' => 'E.g, Ram'),
  );
  $form['lname'] = array(
    '#title' => t('Last Name'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array('placeholder' => 'E.g, Patel'),
  );
  $form['email'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#attributes' => array('placeholder' => 'E.g, abc@example.com'),
  );
  $form['mobile'] = array(
    '#title' => t('Mobile'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#attributes' => array('placeholder' => 'E.g, +91 9999999999'),
  );
  $form['dob'] = array(
    '#type' => 'date_popup',
    '#title' => t("DOB"),
    '#date_format' => 'd/m/Y',
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly'),
    '#default_value' => format_date(REQUEST_TIME, 'custom', 'd/m/Y'),
    '#date_timezone' => date_default_timezone(),
  );
  $form['gender'] = array(
    '#title' => t('Gender'),
    '#type' => 'radios',
    '#options' => array(
      'male' => 'Male',
      'female' => 'Female'
    ),
  );
  $form['profile_pic'] = array(
    '#title' => t('Profile Pic'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://profile_pic/',
    '#description' => 'Files must be less than<strong>512 MB</strong>.<br>Allowed file types:<strong>gif jpeg</strong>',
    '#preview' => TRUE,
    "#upload_validators" => array(
      "file_validate_extensions" => array("gif jpeg"),
      "file_validate_size" => array(500 * 1024 * 1024),
    ),
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
    '#defaule' => '_none',
  );
  $form['address'] = array(
    '#title' => t('Address'),
    '#type' => 'textarea',    
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
