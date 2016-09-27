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
  // Get added item from db.
  $mid = _get_cart_item($user->uid);
  // Pass data to js file.  
  drupal_add_js(array('itg_loyalty_reward' => 
    array('mid' => $mid, 'base_url' => $base_url)), array('type' => 'setting'));
  $user_fields = user_load($user->uid);
  // Render user picture.
  $data['profile_pic'] = theme(
      'image_style', array(
    'style_name' => 'user_picture',
    'path' => $user_fields->field_user_picture['und'][0]['uri'],
      )
  );
  // Load user name    
  $f_name = $user_fields->field_first_name['und'][0]['value'];
  $l_name = $user_fields->field_last_name['und'][0]['value'];
  $data['full_name'] = $f_name . ' ' . $l_name;
  // user logout link
  $data['logout'] = l(t('Logout'), 'user/logout');

  return theme('itg_loyalty_reward_redeem_points', array('data' => $data));
}

/**
 * Add to cart ajax callback.
 *
 * @param int $node_id
 *   Node id of the node.
 */
function itg_loyalty_reward_addtocart($node_id, $action = NULL) {
  // Check if node is set.
  if ($node_id > 0) {
    $node = node_load($node_id);
    $node_info_array = array(
      'nid' => $node->nid,
      'title' => $node->title,
      'description' => $node->body['und'][0]['value'],
      'price' => $node->field_lrp_actual_price['und'][0]['value'],
      'discounted_price' => $node->field_lrp_discounted_price['und'][0]['value'],
      'image' => $node->field_lrp_image['und'][0],
      'points' => $node->field_lrp_loyalty_points['und'][0]['value']
    );
  }
  // check action.
  if (isset($node) && $action == NULL) {
    // Insert product into cart.
    _insert_product_into_cart($node_info_array);
    // Redirect to product listing page.
    drupal_set_message(t('Product added to cart successfully.') 
      . l(t('GO TO CART'), 'cart'), 'status');
    drupal_goto('redeem-points');
  }
  elseif (isset($node) && $action == 'buy-now') {
    // Insert product into cart.
    _insert_product_into_cart($node_info_array);
    // Redirect to cart page.
    drupal_goto('cart');
  }
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
  global $user;
  // Prepare array for inserting data into cart.
  $presave = array(
    'nid' => $node_info_array['nid'],
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
  }
  catch (Exception $ex) {
    watchdog('ITG CART', $ex->getMessage());
  }
  // If data u=inserted to cart table.    
  if ($order_id > 0) {
    drupal_add_js(array('itg_loyalty_reward' => 
      array('mid' => $node_info_array['nid'])), array('type' => 'setting'));    
  }
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
  $data = _get_cart_full_details($user->uid);

  return theme('itg_loyalty_reward_cart', array('data' => $data));
}

/**
 * get cart items from database.
 *
 * @param int $uid
 *   Current user id.
 * @return array
 *   Array of product details.
 */
function _get_cart_full_details($uid) {
  $data = array();
  $itg_query = db_select('itg_loyalty_reward_cart', 'itg');
  $itg_query->fields('itg', array('product_information'))
      ->condition('uid', $uid);
  $itg_result = $itg_query->execute()->fetchAll();
  foreach ($itg_result as $value) {
    $data[] = unserialize($value->product_information);
  }

  return $data;
}

/**
 * Remove product from cart.
 *
 * @param int $nid
 *   Product id to remove from cart page.
 */
function itg_loyalty_reward_removecart($nid, $name) {
  global $user;
  $itg_query = db_delete('itg_loyalty_reward_cart');
  $itg_query->condition('nid', $nid)
      ->condition('uid', $user->uid)
      ->execute();
  drupal_set_message(t('The item @product has been deleted from your cart.',
      array('@product' => $name)), 'status');
  drupal_goto('cart');
}
