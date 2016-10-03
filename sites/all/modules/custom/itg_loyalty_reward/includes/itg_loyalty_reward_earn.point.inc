<?php

/* 
 * @file
 *   Here logic written for loyalty point earning. 
 */

/**
 * Implements menu callback function for test earn points.
 */
function itg_loyalty_reward_testpoints() {
  global $base_url;
  drupal_add_js(drupal_get_path('module', 'itg_loyalty_reward') . '/js/itg_loyalty_reward_cart.js');
  
  // Pass data to js file.
  drupal_add_js(array('itg_loyalty_reward' => array('base_url' => $base_url),
    ), array('type' => 'setting'));
  
  $output = '<div>';
  $output .= '<div class="share" style="cursor:pointer">Content Share <span></span></div>';
  $output .= '<div class="like" style="cursor:pointer">Content Like<span></span></div>';
  $output .= '<div class="visit" style="cursor:pointer">Content Visit<span></span></div>';
  $output .= '<div class="follow" style="cursor:pointer">Follow ITG on Social Sites<span></span></div>';
  $output .= '<div class="ns" style="cursor:pointer">Newsletter Subscription<span></span></div>';
  $output .= '<div class="ugc" style="cursor:pointer">UGC Contribution<span></span></div>';
  $output .= '<div class="ol-register" style="cursor:pointer">Online Registration for Any Events<span></span></div>';
  $output .= '<div class="participate" style="cursor:pointer">Participation in Poll/Campaign/Survey<span></span></div>';
  $output .= '<div class="raf" style="cursor:pointer">Refer a Friend<span></span></div>';  
  
  $output .=  date('Y-m-d', strtotime("+2 days"));
  $output .= '</div>';
  
  return $output;
}

/**
 * Implements callback function for points earning.
 */
function itg_loyalty_reward_earnpoint() {
  global $user;
  // Check user unique expiration key.
  $unique_exp_key = itg_loyalty_reward_unique_expiration($user->uid);
  $time_span = variable_get('lrp_loyality_points_expiry');
  $inputs = $_POST;
  $presave = array(
    'uid' => $user->uid,
    'pointer_key' => uniqid('itg'),
    'created' => REQUEST_TIME,
    'expiry_date' => time() + ($time_span * 24 * 60 * 60),
  );
  $point_presave = array(
    'uid' => $user->uid,
    'loyalty_type' => check_plain($inputs['type']),
    'loyalty_points' => 5,
    'pointer_key' => $presave['pointer_key'],
    'node_id' => 1,
    'created' => REQUEST_TIME,
  );
  
  // Check if expiry key is availbal and not expired.
  if ($unique_exp_key != '') {
    // Add point into user point table.
    
    //itg_loyalty_reward_add_point($user->uid, $unique_exp_key);
  }
  else {
    $itg_query = db_insert('itg_lrp_pointer_key')
      ->fields($presave)
      ->execute();
  }
  
  
  if ($itg_query >= 1) {    
    echo drupal_json_encode(array('code' => 1));
  }
  else {
    echo drupal_json_encode(array('code' => 0));
  }  
}

/**
 * Get unique key for expiry date.
 *
 * @param int $uid
 *   User id of the user.
 *
 * @return string
 *   Unique expiration key.
 */
function itg_loyalty_reward_unique_expiration($uid) {
  $itg_result = '';
  $itg_query = db_select('itg_lrp_pointer_key', 'itg');
  $itg_query->fields('itg', array('pointer_key'))
      ->condition('uid', $uid)
      ->condition('expiry_date', REQUEST_TIME, '>=');
  $itg_result = $itg_query->execute()->fetchField();
  if ($itg_result != '') {
    return $itg_result;
  }
  
  return $itg_result;  
}
