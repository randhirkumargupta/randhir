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
  // validate cart total.
  $cart_total_valid = _cart_total_point($user->uid, 'compare');
  if (!$cart_total_valid) {
    drupal_set_message('You do not have enough point to checkout.', 'error');
    drupal_goto('personalization/my-credits');
  }
  // Load user fields.
  $user_fields = user_load($user->uid);
  $f_name = $user_fields->field_first_name['und'][0]['value'];
  $l_name = $user_fields->field_last_name['und'][0]['value'];
  // Check cart value.
  $data = _get_cart_item($user->uid, 'total');
  if ($data >= 1) {
    // Add js file for validation.
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'itg_astro') . '/js/jquery.validate.min.js',
      drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js',
    );
    // Prepare form array.
    $form['name'] = array(
//      '#title' => t('Name'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Name'),
      ),
      '#default_value' => $f_name . ' ' . $l_name,
      '#required' => TRUE,
    );
    $form['email'] = array(
//      '#title' => t('Email'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Email'),
      ),
      '#default_value' => $user->mail,
      '#required' => TRUE,
    );
    $form['phone'] = array(
//      '#title' => t('Mobile'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Mobile'),
      ),
      '#required' => TRUE,
    );
    $form['address'] = array(
//      '#title' => t('Address'),
      '#type' => 'textarea',
      '#attributes' => array(
        'placeholder' => t('Address'),
      ),
      '#required' => TRUE,
    );
//    $form['city'] = array(
//      '#title' => t('City'),
//      '#type' => 'textfield',
//      '#attributes' => array(
//        'placeholder' => t('City'),
//      ),
//      '#required' => TRUE,
//    );
    $form['zip_code'] = array(
//      '#title' => t('Zip Code'),
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Pincode'),
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
  global $user;
  //Prepare array for saving product information.  
  //$inputs = $form_state['values'];
  // Prepare user info.
//  $data['user_info'] = array(
//    'name' => $inputs['name'],
//    'email' => $inputs['email'],
//    'phone' => $inputs['phone'],
//    'address' => $inputs['addess'],
//    'city' => $inputs['city'],
//    'zip_code' => $inputs['zip_code'],
//  );
//  // Get product info.
//  $cart_detail = _get_cart_full_details($user->uid);
//  $data['cart-items'] = $cart_detail;
//  // Save data into order table.
//  $presave = array(
//    'uid' => $user->uid,
//    'product_information' => serialize($data),
//    'created' => REQUEST_TIME,
//  );
//  $order_placed = 0;
//  try {
//    $order_placed = db_insert('itg_loyalty_reward_order')
//        ->fields($presave)
//        ->execute();
//    $unique_key = itg_loyalty_reward_unique_expiration($user->uid);
//    $total_point = _cart_total_point($user->uid);
//    $itg_query = db_update('itg_loyalty_reward_point_history');
//    $itg_query->fields(array('redeemed_point' => $total_point, 'cart_point' => 0))
//        ->condition('pointer_key', $unique_key)
//        ->expression('redeemed_point', 'redeemed_point + :point', array(':point' => $total_point))        
//        ->execute();
//  }
//  catch (Exception $ex) {
//    watchdog('ITG Order', $ex->getMessage());
//  }
//  if ($order_placed > 0) {
//    $flush_cart = db_delete('itg_loyalty_reward_cart')
//        ->condition('uid', $user->uid)
//        ->execute();
//    drupal_set_message('Your order has been placed', 'status');
//  }
//  drupal_goto('order');
}

/**
 * Get cart total points.
 *
 * @param int $uid
 *   User id of the current cart owner.
 *
 * @return int
 *   Cart total points.
 */
function _cart_total_point($uid, $op = NULL) {
  $itg_result = 0;
  $itg_query = db_select('itg_loyalty_reward_cart', 'itg')
      ->condition('uid', $uid);
  $itg_query->addExpression('SUM(points * quintity)', 'mul');
  $itg_result_cart = $itg_query->execute()->fetchField();

  // Get unique expiry key.
  $pointer_key = itg_loyalty_reward_unique_expiration($uid);
  $itg_query = db_select('itg_loyalty_reward_point_history', 'itg');
  $itg_query->fields('itg', array('cart_point'))
      ->condition('pointer_key', $pointer_key);
  $itg_result_history = $itg_query->execute()->fetchField();
  if ($op == 'compare' && $itg_result_cart == $itg_result_history) {
    return TRUE;
  }
  elseif ($op == 'compare' && $itg_result_cart != $itg_result_history) {
    return FALSE;
  }
  else {
    return $itg_result_cart;
  }
}

/**
 * Page callback function for order place page.
 *
 * @global stdObject $user
 */
function itg_loyalty_reward_place_order() {
  global $user;
  $user_detail = user_load($user->uid);
  $fname = $user_detail->field_first_name['und'][0]['value'];
  $lname = $user_detail->field_last_name['und'][0]['value'];
  $data['user_info'] = array(
    'name' => $fname . ' ' . $lname,
    'email' => $user_detail->mail,
    'phone' => $user_detail->field_mobile_number['und'][0]['value'],
    'address' => $user_detail->field_short_description['und'][0]['value'],
    'city' => $inputs['city'],
    'zip_code' => 462011,
  );
  // Get product info.
  $cart_detail = _get_cart_full_details($user->uid);
  $data['cart-items'] = $cart_detail;  
  // Save data into order table.
  $presave = array(
    'uid' => $user->uid,
    'product_information' => serialize($data),
    'created' => REQUEST_TIME,
  );
  $order_placed = 0;
  try {
    $order_placed = db_insert('itg_loyalty_reward_order')
        ->fields($presave)
        ->execute();
    $unique_key = itg_loyalty_reward_unique_expiration($user->uid);
    $total_point = _cart_total_point($user->uid);
    $itg_query = db_update('itg_loyalty_reward_point_history');
    $itg_query->fields(array('redeemed_point' => $total_point, 'cart_point' => 0))
        ->condition('pointer_key', $unique_key)
        ->expression('redeemed_point', 'redeemed_point + :point', array(':point' => $total_point))
        ->execute();
  }
  catch (Exception $ex) {
    watchdog('ITG Order', $ex->getMessage());
    drupal_set_message('Something went wrong please try after some time.', 'error');
  }
  if ($order_placed > 0) {
    $flush_cart = db_delete('itg_loyalty_reward_cart')
        ->condition('uid', $user->uid)
        ->execute();
    // Set cart order into session for order confirmation page.
    $_SESSION['placed-item'] = $cart_detail;
    drupal_set_message('Your order has been placed', 'status');
    drupal_goto('order-confirmation');
  }
  drupal_goto('order-confirmation');
}
