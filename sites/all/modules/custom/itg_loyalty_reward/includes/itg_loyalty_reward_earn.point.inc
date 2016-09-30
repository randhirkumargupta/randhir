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
  $output .=  time() + (1 * 24 * 60 * 60) . '|';
  $output .=  date('Y-m-d', strtotime("+2 days"));
  $output .= '</div>';
  
  return $output;
}

/**
 * Implements callback function for points earning.
 */
function itg_loyalty_reward_earnpoint() {
  global $user;
  $time_span = variable_get('lrp_loyality_points_expiry');
  $inputs = $_POST;
  
  echo drupal_json_encode($inputs);
}