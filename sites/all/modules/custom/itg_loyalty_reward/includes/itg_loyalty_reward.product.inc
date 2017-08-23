<?php

/*
 * @file
 *   Product listing page callback and other settings. 
 */

/**
 * Implements callback function for product listing page.
 */
function itg_loyalty_reward_redeem_points() {
  global $user, $base_url;
  // Add js file to the page.
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward')
      . '/js/itg_loyalty_reward_cart.js');

  return '';
}

/**
 * Add to cart ajax callback.
 *
 * @param int $node_id
 *   Node id of the node.
 */
function itg_loyalty_reward_addtocart($node_id, $action = NULL, $new_quantity = NULL) {
  global $user;
  if ($new_quantity == NULL) {
    $redirect = check_plain($_GET['destination']);
  }
  // Check if node is set.
  if ($node_id > 0) {
    // Check if product is already in cart.
    $itg_result = _check_product_into_cart($user->uid, $node_id);
    $node = node_load($node_id);
    $node_info_array = array(
      'nid' => $node->nid,
      'title' => $node->title,
      'description' => $node->body['und'][0]['value'],
      'price' => $node->field_lrp_actual_price['und'][0]['value'],
      'discounted_price' => $node->field_lrp_discounted_price['und'][0]['value'],
      'image' => $node->field_lrp_image['und'][0],
      'points' => $node->field_lrp_loyalty_points['und'][0]['value'],
    );
    // Check if user has valid points to redeem product.
    //$remaining_point = itg_loyalty_reward_remaining_point($user->uid);
    if (function_exists('itg_global_loyality_get_sso_id')) {
      $sso_id = itg_global_loyality_get_sso_id($user->uid);
    }
    if (!empty(variable_get('property_name'))) {
      $property = variable_get('property_name');
    }
    $remaining_previous_point = itg_get_global_remaining_point($user->uid, $property, $sso_id);
    $cart_point = '';
    if(function_exists('itg_get_total_cart_point')) {
      $cart_point = itg_get_total_cart_point($user->uid);
    }
   
    if(!empty($cart_point)) {
      watchdog('cart_total_point', $cart_point);
      $remaining_point = $remaining_previous_point - $cart_point;
    } else {
      $remaining_point = $remaining_previous_point;
    }
    
    if ($remaining_point < $node_info_array['points'] && $action == 'buy-now') {
      drupal_set_message(t('Insufficient points to redeem this product.'), 'error');
      drupal_goto('product');
    }
    elseif ($remaining_point < $node_info_array['points'] && $new_quantity > 0) {
      return drupal_json_encode(array('code' => -2));
    }
    elseif ($remaining_point < $node_info_array['points'] && $new_quantity == NULL && $action == NULL) {
      drupal_set_message(t('Insufficient points to redeem this product.'), 'error');
      drupal_goto($redirect);
    }

    // Upfate cart quantity.
    if ($node_id == $itg_result->nid && $action == NULL && $new_quantity == NULL) {
      $quantity = $itg_result->quintity + 1;
      // Update item on cart page.
      _update_cart_item($node->nid, $user->uid, $quantity, $node_info_array, $redirect);
    }
    elseif ($node_id == $itg_result->nid && $new_quantity > 0) {
      // Set operation increase otr decrease points.
      $op = $itg_result->quintity > $new_quantity ? 'dec' : 'inc';
      if ($op == 'dec') {
        $quantity = $itg_result->quintity - $new_quantity;
      }
      elseif ($op == 'inc') {
        $quantity = $new_quantity - $itg_result->quintity;
      }
      else {
        $quantity = 0;
      }      
      _update_cart_item($node->nid, $user->uid, $quantity, $node_info_array, 'quantity', $op, $itg_result->quintity);

      return drupal_json_encode(array('code' => 1));
    }
    else {
      $node_info_array['quantity'] = 1;
    }
  }
  // check action.
  if (isset($node) && $action == NULL) {
    // Insert product into cart.
    $response = _insert_product_into_cart($node_info_array);
    if ($response != 1) {
      drupal_set_message(t('Something went wrong please try after some time.')
          , 'error');
    }
    // Redirect to product listing page.    
    drupal_goto($redirect);
  }
  elseif (isset($node) && $action == 'buy-now') {
    unset($_REQUEST['destination']);
    if ($node_id == $itg_result->nid) {
      drupal_goto('cart');
    }
    // Insert product into cart.
    $response = _insert_product_into_cart($node_info_array);
    if ($response == 0) {
      drupal_set_message(t('Something went wrong please try after some time.')
          , 'error');
      // Redirect to cart page.
      drupal_goto('product');
    }
    // Redirect to cart page.
    drupal_goto('cart');
  }
}

function _check_product_into_cart($uid, $nid) {
  $itg_result = 0;
  $itg_query = db_select('itg_loyalty_reward_cart', 'itg')
      ->fields('itg', array('nid', 'quintity'))
      ->condition('uid', $uid)
      ->condition('nid', $nid);
  $itg_result = $itg_query->execute()->fetchObject();

  return $itg_result;
}

/**
 * Update items quantity on cart.
 *
 * @param int $nid
 *   Node if of the product.
 * @param int $uid
 *   User id of the user.
 */
function _update_cart_item($nid, $uid, $quantity, $node_info_array, $redirect, $op = NULL, $old_qua = NULL) {
  $itg_query = db_update('itg_loyalty_reward_cart');
  if ($op == 'inc') {
    $itg_query->fields(array('quintity' => $quantity + $old_qua));
  }
  elseif ($op == 'dec') {
    $itg_query->fields(array('quintity' => $old_qua - $quantity));
  }
  else {
    $itg_query->fields(array('quintity' => $quantity));
  }
  $itg_query->condition('nid', $nid)
      ->condition('uid', $uid)
      ->execute();
  // Update points

  if ($redirect != 'quantity' && $op == NULL) {
    //itg_loyalty_reward_update_point($uid, $node_info_array['points']);
    $_SESSION['cart_after_popup'] = $node_info_array;
    drupal_goto($redirect);
  }
  elseif ($redirect == 'quantity' && $op != NULL) {
    //itg_loyalty_reward_update_point($uid, ($node_info_array['points'] * $quantity), $op);
  }
}

/**
 * Update points value on add to cart action.
 *
 * @param int $uid
 *   User id of the current logged in user.
 * @param int $points
 *   Points assigned to particular product.
 */
function itg_loyalty_reward_update_point($uid, $points, $op = NULL) {  
  $unique_exp_key = itg_loyalty_reward_unique_expiration($uid);
  $itg_query = db_update('itg_loyalty_reward_point_history')
      ->fields(array('cart_point' => $points, 'remaining_point' => $points))
      ->condition('pointer_key', $unique_exp_key);
  if ($op == NULL || $op == 'inc') {    
    $itg_query->expression('cart_point', 'cart_point + :point', array(':point' => $points))
        ->expression('remaining_point', 'remaining_point - :point', array(':point' => $points));   
  }
  elseif ($op == 'dec') {
    $itg_query->expression('cart_point', 'cart_point - :point', array(':point' => $points))
        ->expression('remaining_point', 'remaining_point + :point', array(':point' => $points));  
  }  
  $itg_query->execute();  
}

/**
 * Insert product to shopping cart.
 *
 * @global stdObject $user
 *   User oject containing user details.
 * @param array $node_info_array
 *   product details.
 */
function _insert_product_into_cart($node_info_array) {
  //p($node_info_array);
  global $user;
  // Prepare array for inserting data into cart.
  $presave = array(
    'nid' => $node_info_array['nid'],
    'quintity' => $node_info_array['quantity'],
    'uid' => $user->uid,
    'product_name' => $node_info_array['title'],
    'points' => $node_info_array['points'],
    'product_information' => serialize($node_info_array),
    'created' => REQUEST_TIME,
  );
  // Insert data to cart table.
  try {
    $order_id = db_insert('itg_loyalty_reward_cart')
        ->fields($presave)
        ->execute();
    // Update points.
    //itg_loyalty_reward_update_point($user->uid, $node_info_array['points']);
    $response = 1;
  }
  catch (Exception $ex) {
    watchdog('ITG CART', $ex->getMessage());
    $response = 0;
  }

  if ($response != 0) {
    $_SESSION['cart_after_popup'] = $node_info_array;
  }

  return $response;
}

/**
 * Callback function for cart detail page.
 *
 * @global stdObject $user
 *   User standard object.
 * @return array
 *   page rendered array.
 */
function itg_loyalty_reward_cart() {
  global $user, $base_url;
  // Add js file.
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js', array('scope' => 'footer'));
  drupal_add_js(array('itg_loyalty_reward' => array('base_url' => $base_url)), array('type' => 'setting'));
  $data = _get_cart_full_details($user->uid);
  //$remain_point = itg_loyalty_reward_remaining_point($user->uid);
  if (function_exists('itg_global_loyality_get_sso_id')) {
    $sso_id = itg_global_loyality_get_sso_id($user->uid);
  }
  if (!empty(variable_get('property_name'))) {
    $property = variable_get('property_name');
  }
  $remain_point = itg_get_global_remaining_point($user->uid, $property, $sso_id);
  if (function_exists('itg_get_total_cart_point')) {
    $cart_point = itg_get_total_cart_point($user->uid);
  }
  $final_point = $remain_point - $cart_point;
  return theme('itg_loyalty_reward_cart', array('data' => $data, 'remain_point' => $final_point));
}

/**
 * Update cart item quantity.
 *
 * @return array
 *   Cart full detail to render. 
 */
function itg_loyalty_reward_update_item_count() {
  $values = $_POST;
  $node_id = check_plain($values['encoded_id']);
  $quantity = check_plain($values['item_count']);
  $node_id = (int) $node_id;
  $quantity = (int) $quantity;
  // check if valid node id and quantity available.
  if ($node_id > 0 && $quantity > 0) {
    $code = itg_loyalty_reward_addtocart($node_id, NULL, $quantity);
    echo $code;
  }
  else {
    echo drupal_json_encode(array('code' => -1));
  }
}

/**
 * Remove product from cart.
 *
 * @param int $nid
 *   Product id to remove from cart page.
 */
function itg_loyalty_reward_removecart($nid, $name, $point) {
  global $user;
  $nid = check_plain($nid);
  $name = check_plain($name);
  $point = check_plain($point);
  $name = ucwords(str_replace('_', ' ', $name));
  // Get unique expiration key.
  $unique_key = itg_loyalty_reward_unique_expiration($user->uid);
  try {
    $itg_query = db_delete('itg_loyalty_reward_cart');
    $itg_query->condition('nid', $nid)
        ->condition('uid', $user->uid)
        ->execute();
    // Update user points.
    $itg_query = db_update('itg_loyalty_reward_point_history');
    $itg_query->fields(array('remaining_point' => $point, 'cart_point' => $point))
        ->condition('pointer_key', $unique_key)
        ->expression('remaining_point', 'remaining_point + :point', array(':point' => $point))
        ->expression('cart_point', 'cart_point - :point', array(':point' => $point))
        ->execute();
  }
  catch (Exception $ex) {
    watchdog('Remove Product', $ex->getMessage());
  }

  drupal_set_message(t('The item @product has been deleted from your cart.', array('@product' => $name)), 'status');
  drupal_goto('cart');
}

/**
 * Implements page callback function for order page.
 *
 * @global stdObject $user
 *   Standard user object.
 *
 * @return array
 *   Themes rendred array.
 */
function itg_loyalty_reward_order() {
  global $user;
  $header = array(
    t('Product Description'),
    t('Points'),
    t('Order No'),
  );
  // Get order detail.
  $rows = _get_order_item();

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => array('mytable'))
      )
  );
}

/**
 * Get oreder detail from database.
 *
 * @global stdObject $user
 *   Standard user object.
 *
 * @return array
 *   Array of user order details.
 */
function _get_order_item() {
  global $user;
  $itg_result = array();
  $itg_query = db_select('itg_loyalty_reward_order', 'itg')
      ->fields('itg', array('order_id', 'product_information', 'created'))
      ->condition('uid', $user->uid)
      ->orderBy('order_id', 'desc');
  $itg_result = $itg_query->execute()->fetchAll();
  $data = array();
  foreach ($itg_result as $value) {
    $products = unserialize($value->product_information);
    foreach ($products['cart-items'] as $product) {
      $product_pic = theme(
          'image_style', array(
        'style_name' => 'cart_172x240',
        'path' => $product['product']['image']['uri'],
          )
      );
      $output = '<div class="checkout-details">';
      $output = '<div class="checkout-inner">';
      $output .= $product_pic . '<div class="checkout-inner-details"><div><span>Magzine ID: </span><strong>' . $product['product']['nid'] . '</strong></div>';
      $output .= '<div><span>Quantity: </span><strong>' . $product['quantity'] . '</strong></div>';
      $output .= '<div><span>Date of Purchase: </span><strong>' . format_date($value->created, 'custom_date_d_m_y_') . '</strong></div></div>';
      $output .= '</div>';
      $output .= '</div>';
      $data[] = array(
        $output,
        $product['product']['points'] * $product['quantity'],
        $value->order_id,
      );
    }
  }

  return $data;
}

/**
 * Callback function for order summary page.
 *
 * @global stdObject $user
 * @return array
 */
function itg_loyalty_reward_order_summary() {  
  global $user;
  // Add js file.
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js', array('scope' => 'footer'));
  $user_detail = user_load($user->uid);
  $data['product_detail'] = _get_cart_full_details($user->uid);
  $fname = $user_detail->field_first_name['und'][0]['value'];
  $lname = $user_detail->field_last_name['und'][0]['value'];
  $data['user_detail']['name'] = $fname . ' ' . $lname;
  $data['user_detail']['mail'] = $user_detail->mail;
  $data['user_detail']['address'] = $user_detail->field_short_description['und'][0]['value'];
  $data['user_detail']['pincode'] = $user_detail->field_user_pincode['und'][0]['value'];
  //$remain_point = itg_loyalty_reward_remaining_point($user->uid);
  if (function_exists('itg_global_loyality_get_sso_id')) {
    $sso_id = itg_global_loyality_get_sso_id($user->uid);
  }
  if (!empty(variable_get('property_name'))) {
    $property = variable_get('property_name');
  }
  $remain_point = itg_get_global_remaining_point($user->uid, $property, $sso_id);
  if (function_exists('itg_get_total_cart_point')) {
    $cart_point = itg_get_total_cart_point($user->uid);
  }
  $final_point = $remain_point - $cart_point;
  return theme('cart_order_summary', array('data' => $data, 'remain_point' => $final_point));
}

/**
 * Callback function for order confirmation page.
 *
 * @return array
 */
function itg_loyalty_reward_order_confirmation() {
  global $base_url;  
  if (!isset($_SESSION['placed-item'])) {
    drupal_goto($base_url . '/product');
  }
  itg_loyalty_reward_redeem_points_send_mail('Redeem Points', $_SESSION['placed-item']);
  $data = array();
  return theme('cart_order_confirmation', array('data' => $data));
}

/*
 * Helper function for itg_loyalty_reward_redeem_points_send_mail
 */
function itg_loyalty_reward_redeem_points_send_mail($key, $value) {
  
  global $user;
  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $get_mail_content = itg_mail_templates_get_mailcontent($key, $task_event = NULL, $ugc_status = NULL);
    $mail_subject = $get_mail_content->field_mail_subject_loyalty[LANGUAGE_NONE][0]['value'];
    foreach ($value as $prd_key => $prd_val) {
      $prd_name[] = $prd_val['product']['title'];
    }
    
    if (is_array($prd_name)) {
      $productname = implode(', ', $prd_name);
    }
    
    $body1 = str_replace('[itg_mail_token:itg_loyalty_user]', $user->name, $get_mail_content->field_mail_body_loyalty[LANGUAGE_NONE][0]['value']);
    $mail_content = str_replace('[itg_mail_token:itg_product_name]', $productname, $body1);
  }
  $mail_contents = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_content);
  $params = array(
    'body' => $mail_contents,
    'subject' => $mail_subject,
  );
   $to = $user->mail;
//  $to = 'gourav.walia@kelltontech.com';
  $mail = drupal_mail('itg_loyalty_reward_redeem_points', 'itg_redeem_points_mail', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = 'Failed to send the email!';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}

/**
 * Implements hook_mail
 * @param string $key
 * @param string $message
 * @param array $params
 */
function itg_loyalty_reward_redeem_points_mail($key, &$message, $params) {
  switch ($key) {
    case 'itg_redeem_points_mail':
      $headers = array(
        'MIME-Version' => '1.0',
        'Content-Type' => 'text/html; charset=UTF-8; format=flowed; delsp=yes',
        'Content-Transfer-Encoding' => '8Bit',
        'X-Mailer' => 'Drupal'
      );
      $message['subject'] = $params['subject'];
      $message['body'][] = $params['body'];
      foreach ($headers as $key => $value) {
        $message['headers'][$key] = $value;
      }
      break;
  }
}