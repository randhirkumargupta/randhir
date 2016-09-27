<?php

/*
 * @file
 * Provide a checkout form for user. 
 */

/**
 * Create checkout form.
 *
 * @global stdObject $user
 *   Standard user object containing user information.
 * @return array
 *   Array of form elements.
 */
function itg_loyalty_reward_checkout_form() {
  global $user;
  // Load user fields.
  $user_fields = user_load($user->uid);
  $f_name = $user_fields->field_first_name['und'][0]['value'];
  $l_name = $user_fields->field_last_name['und'][0]['value'];
  // Check cart value.
  $data = _get_cart_item($user->uid, 'total');
  
  if ($data >= 1) {
    // Prepare form array.
    $form['name'] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Name'),
      ),
      '#default_value' => $f_name . ' ' . $l_name,
      '#required' => TRUE,
    );
    $form['email'] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Email'),
      ),
      '#default_value' => $user->mail,
      '#required' => TRUE,
    );
    $form['phone'] = array(
      '#title' => t('Phone'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Phone Number'),
      ),
      '#required' => TRUE,
    );
    $form['address'] = array(
      '#title' => t('Address'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Address'),
      ),
      '#required' => TRUE,
    );
    $form['city'] = array(
      '#title' => t('City'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('City'),
      ),
      '#required' => TRUE,
    );
    $form['zip_code'] = array(
      '#title' => t('Zip Code'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Zip Code'),
      ),
      '#required' => TRUE,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Order Now'),
      '#attributes' => array('class' => array('buttons'))
    );
  }
  else {
    $form['message'] = array(
      '#type' => 'markup',
      '#markup' => t('There are no items in this cart.'),
    );
  }

  return $form;
}

/**
 * Implements hook_validate().
 *
 * {@inheridoc} 
 */
function itg_loyalty_reward_checkout_form_validate($form, &$form_state) {
  $inputs = $form_state['values'];
  // Validate name field.
  if (empty($inputs['name'])) {
    form_set_error('name', 'Name field is required.');
  }
  // Validate email field.
  if (empty($inputs['email'])) {
    form_set_error('email', 'Email field is required.');
  }
  // Validate phone field.
  if (empty($inputs['phone'])) {
    form_set_error('phone', 'Phone field is required.');
  }
  // Validate address field.
  if (empty($inputs['address'])) {
    form_set_error('address', 'Address field is required.');
  }
  // Validate city field.
  if (empty($inputs['city'])) {
    form_set_error('city', 'City field is required.');
  }
  // Validate zip code field.
  if (empty($inputs['zip_code'])) {
    form_set_error('zip_code', 'Zip Code field is required.');
  }
}

/**
 * Implements hook_submit().
 *
 * {@inheritdoc}.
 */
function itg_loyalty_reward_checkout_form_submit($form, &$form_state) {
  //Prepare array for saving product information.
}