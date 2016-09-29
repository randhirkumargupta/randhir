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
  // Check if node is set.
  if ($node_id > 0) {
    // Check if product is already in cart.
    $itg_result = 0;
    $itg_query = db_select('itg_loyalty_reward_cart', 'itg')
        ->fields('itg', array('nid', 'quintity'))
        ->condition('uid', $user->uid)
        ->condition('nid', $node_id);
    $itg_result = $itg_query->execute()->fetchObject();        
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
    if ($node_id == $itg_result->nid) {
      $quantity = $itg_result->quintity + 1;
      // Update item on cart page.
      _update_cart_item($node->nid, $user->uid, $quantity);
    }
    else {
      $node_info_array['quantity'] = 1;
    }
  }
  // check action.
  if (isset($node) && $action == NULL) {
    // Insert product into cart.
    $response = _insert_product_into_cart($node_info_array);    
    if ($response == 1) {
      drupal_set_message(t('Product added to cart successfully.') 
      . l(t('GO TO CART'), 'cart'), 'status');
    }
    else {
      drupal_set_message(t('Something went wrong please try after some time.') 
      , 'error');
    }
    // Redirect to product listing page.    
    drupal_goto('redeem-points');
  }
  elseif (isset($node) && $action == 'buy-now') {
    // Insert product into cart.
    $response = _insert_product_into_cart($node_info_array);
    if ($response == 0) {
      drupal_set_message(t('Something went wrong please try after some time.') 
      , 'error');
      // Redirect to cart page.
      drupal_goto('redeem-points');
    }    
  }
}

/**
 * Update items quantity on cart.
 *
 * @param int $nid
 *   Node if of the product.
 * @param int $uid
 *   User id of the user.
 */
function _update_cart_item($nid, $uid, $quantity) {
  $itg_query = db_update('itg_loyalty_reward_cart')
      ->fields(array('quintity' => $quantity))
      ->condition('nid', $nid)
      ->condition('uid', $uid)
      ->execute();
  drupal_set_message('Item updated on cart successfully.', 'status');
  drupal_goto('redeem-points');
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
    $response = 1;    
  }
  catch (Exception $ex) {
    watchdog('ITG CART', $ex->getMessage());
    $response = 0;
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
  $data = _get_cart_full_details($user->uid);

  return theme('itg_loyalty_reward_cart', array('data' => $data));
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
    t('Point'),
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
      ->fields('itg', array('order_id', 'product_information'))
      ->condition('uid', $user->uid);
  $itg_result = $itg_query->execute()->fetchAll();  
  $data = array();
  foreach ($itg_result as $value) {    
    $products = unserialize($value->product_information);    
    foreach ($products['cart-items'] as $product) {
      $product_pic = theme(
        'image_style', array(
          'style_name' => 'magazine_rhs_100x140',
          'path' => $product['image']['uri'],
        )
      );
      $output = '<div>';
      $output .= $product_pic . 'Magzine ID: ' . $product['nid'];
      $output .= '</div>';
      $data[] = array(
        $output,
        $product['points'],
        $value->order_id,
      );
    }
  }
  
  return $data;    
}