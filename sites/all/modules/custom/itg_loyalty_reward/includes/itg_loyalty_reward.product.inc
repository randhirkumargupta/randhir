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
function itg_loyalty_reward_addtocart($node_id, $action = NULL) {
  global $user;
  $redirect = check_plain($_GET['destination']);
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
    $remaining_point = itg_loyalty_reward_remaining_point($user->uid);
    if ($remaining_point < $node_info_array['points']) {
      drupal_set_message(t('Insufficient points to redeem this product.'), 'error');
      drupal_goto($redirect);
    }

    if ($node_id == $itg_result->nid && $action == NULL) {
      $quantity = $itg_result->quintity + 1;
      // Update item on cart page.
      _update_cart_item($node->nid, $user->uid, $quantity, $node_info_array, $redirect);
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
    if ($node_id == $itg_result->nid) {
      drupal_goto('cart');
    }
    // Insert product into cart.
    $response = _insert_product_into_cart($node_info_array);
    if ($response == 0) {
      drupal_set_message(t('Something went wrong please try after some time.')
          , 'error');
      // Redirect to cart page.
      drupal_goto($redirect);
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
function _update_cart_item($nid, $uid, $quantity, $node_info_array, $redirect) {
  $itg_query = db_update('itg_loyalty_reward_cart')
      ->fields(array('quintity' => $quantity))
      ->condition('nid', $nid)
      ->condition('uid', $uid)
      ->execute();
  // Update points
  itg_loyalty_reward_update_point($uid, $node_info_array['points']);    
  $_SESSION['cart_after_popup'] = $node_info_array;
  drupal_goto($redirect);
}

/**
 * Update points value on add to cart action.
 *
 * @param int $uid
 *   User id of the current logged in user.
 * @param int $points
 *   Points assigned to particular product.
 */
function itg_loyalty_reward_update_point($uid, $points) {
  $unique_exp_key = itg_loyalty_reward_unique_expiration($uid);
  $itg_query = db_update('itg_loyalty_reward_point_history')
      ->fields(array('cart_point' => $points, 'remaining_point' => $points))
      ->condition('pointer_key', $unique_exp_key)
      ->expression('cart_point', 'cart_point + :point', array(':point' => $points))
      ->expression('remaining_point', 'remaining_point - :point', array(':point' => $points))
      ->execute();
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
    itg_loyalty_reward_update_point($user->uid, $node_info_array['points']);
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
 *   page remdered array.
 */
function itg_loyalty_reward_cart() {
  global $user;
  // Add js file.
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js');  
  $data = _get_cart_full_details($user->uid);  
  $remain_point = itg_loyalty_reward_remaining_point($user->uid);  

  return theme('itg_loyalty_reward_cart', array('data' => $data, 'remain_point' => $remain_point));
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
      ->condition('uid', $user->uid);
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
