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
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js');
  // Pass data to js file.
  drupal_add_js(array('itg_loyalty_reward' => array('base_url' => $base_url)), array('type' => 'setting'));
  $user_fields = user_load($user->uid);  
  
  // Render user picture.
  $data['profile_pic'] = theme(
    'image_style',
    array(
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
 */
function itg_loyalty_reward_addtocart($node_id = NULL) {
  // If node is is present then send user to checkout page, else add item into cart.
  if ($node_id != NULL) {
    // Do something.
  }
  else {
    p($_POST);
  }
}
