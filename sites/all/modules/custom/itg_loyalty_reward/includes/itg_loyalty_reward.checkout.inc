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
function itg_loyalty_reward_address_form($form, &$form_state) {
  global $user;
  // validate cart total.
  $cart_total_valid = _cart_total_point($user->uid, 'compare');
  if (!$cart_total_valid) {
    drupal_goto('cart');
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
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Name'),
        'readonly' => TRUE,
      ),
      '#default_value' => $f_name . ' ' . $l_name,
      '#required' => TRUE,
    );
    $form['email'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Email'),
        'readonly' => TRUE,
      ),
      '#default_value' => $user->mail,
      '#required' => TRUE,
    );
    $form['phone'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Mobile'),
        'readonly' => TRUE,
      ),
      '#required' => TRUE,
      '#default_value' => $user_fields->field_mobile_number['und'][0]['value'],
    );
    $form['address'] = array(
      '#type' => 'textarea',
      '#attributes' => array(
        'placeholder' => t('Address'),
      ),
      '#required' => TRUE,
      '#default_value' => $user_fields->field_short_description['und'][0]['value'],
    );
    $form['zip_code'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Pincode'),
      ),
      '#required' => TRUE,
      '#default_value' => $user_fields->field_user_pincode['und'][0]['value'],
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
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
function itg_loyalty_reward_address_form_validate($form, &$form_state) {
  $inputs = $form_state['values'];
  // Validate address field.
  if (empty($inputs['address'])) {
    form_set_error('address', 'Address field is required.');
  }
  if (empty($inputs['zip_code'])) {
    form_set_error('zip_code', 'Pincode field is required.');
  }
}

/**
 * Implements hook_submit().
 *
 * {@inheritdoc}.
 */
function itg_loyalty_reward_address_form_submit($form, &$form_state) {
  global $user;
  //Prepare array for saving product information.  
  $inputs = $form_state['values'];
  // Get product info.
  $user_fields = user_load($user->uid);
  $user_fields->field_short_description['und'][0]['value'] = $inputs['address'];
  $user_fields->field_user_pincode['und'][0]['value'] = $inputs['zip_code'];
  user_save($user_fields);
  drupal_set_message('Address has been successfully updated.', 'status');
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
 * Compare product quantity on cart and node.
 *
 * @param array $cart_detail
 *   Product details available on cart.
 *
 * @return array
 *   Return node title and quantity of product in case cart quantity is
 *   is greater than actual quantity on node.
 */
function itg_loyalty_reward_product_availability($cart_detail) {
  $data = array();
  foreach ($cart_detail as $cart_value) {
    // Load node from node id.
    $node = node_load($cart_value['product']['nid']);

    // Update quantity field.
    $available_quantity = $node->field_lrp_product_count[LANGUAGE_NONE][0]['value'];

    // Compare cart and available quantity.
    if ($available_quantity < $cart_value['quantity']) {
      $data['not_available'][] = array(
        'title' => $node->title,
        'quantity' => $available_quantity
      );
    }
    else {
      $data['nid'][] = $cart_value['product']['nid'];
    }
  }

  return $data;
}

/**
 * Page callback function for order place page.
 *
 * @global stdObject $user
 */
function itg_loyalty_reward_place_order() {
  global $user, $base_url;
  // Get product info.
  $cart_detail = _get_cart_full_details($user->uid);
  $errors = array_filter($cart_detail);
  if (empty($errors)) {
    drupal_goto('product');
  }
  // Check availability of the product.
  $product_availability = itg_loyalty_reward_product_availability($cart_detail);
  $errors = array();
  if (!empty($product_availability['not_available'])) {
    $errors = array_filter($product_availability['not_available']);
  }  
  
  if (!empty($errors)) {
    foreach ($product_availability['not_available'] as $product) {
      drupal_set_message(
          t('@name Only @quantity left in stock', array('@name' =>
        $product['title'], '@quantity' => $product['quantity'])), 'error');
    }
    drupal_goto($base_url . '/cart');
  }

  // Load user from user id.
  $user_detail = user_load($user->uid);
  $fname = $user_detail->field_first_name['und'][0]['value'];
  $lname = $user_detail->field_last_name['und'][0]['value'];
  $data['user_info'] = array(
    'name' => $fname . ' ' . $lname,
    'email' => $user_detail->mail,
    'phone' => $user_detail->field_mobile_number['und'][0]['value'],
    'address' => $user_detail->field_short_description['und'][0]['value'],    
    'zip_code' => $user_detail->field_user_pincode['und'][0]['value'],
  );

  $data['cart-items'] = $cart_detail;
  // Save data into order table.
  $presave = array(
    'uid' => $user->uid,
    'product_information' => serialize($data),
    'created' => REQUEST_TIME,
    'nids' => implode(',', $product_availability['nid']),
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
    $_SESSION['order_id'] = $order_placed;
    // Update product count value is product node.
    foreach ($cart_detail as $cart_value) {
      // Load node from node id.
      $node = node_load($cart_value['product']['nid']);
      // Update quantity field.
      $current_quantity = $node->field_lrp_product_count[LANGUAGE_NONE][0]['value'];
      $updated_quantity = $current_quantity - $cart_value['quantity'];
      if ($updated_quantity == 0) {
        $node->field_lrp_completed[LANGUAGE_NONE][0]['value'] = 'Sold out';
        $node->field_lrp_product_count[LANGUAGE_NONE][0]['value'] = $updated_quantity;
      }
      else {
        $node->field_lrp_product_count[LANGUAGE_NONE][0]['value'] = $updated_quantity;
      }
      // Save node object.
      node_save($node);
    }
    drupal_goto($base_url . '/order-confirmation');
  }
  drupal_goto($base_url . '/order-confirmation');
}

/**
 * Implements sold history page callback.
 *
 * @param int $nid
 *   Node if of product.
 * @return array
 *   Return table layout of the sold history.
 */
function itg_loyalty_reward_product_sold_history($nid) {
  $itg_result = array();
  // get all order ids who have selected node id.
  $itg_query = db_select('itg_loyalty_reward_order', 'itg');
  $itg_query->fields('itg', array('order_id', 'uid'))
      ->condition('nids', '%' . db_like($nid) . '%', 'LIKE')
      ->orderBy('order_id', 'desc');
  $itg_result = $itg_query->execute()->fetchAll();
  // Make table header.
  $header = array(
    t('Sr. No.'),
    t('Username'),
    t('Order No'),
  );
  $errors = array_filter($itg_result);
  if (!empty($errors)) {
    foreach ($itg_result as $key => $value) {
      $user_detail = user_load($value->uid);
      $rows[] = array(
        $key + 1,
        $user_detail->name,
        $value->order_id,
      );
    }
  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => array('views-table'))
      )
  );
}
