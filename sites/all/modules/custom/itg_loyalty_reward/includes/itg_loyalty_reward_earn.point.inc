<?php

/*
 * @file
 *   Here logic written for loyalty point earning. 
 */

/**
 * Implements menu callback function for test earn points. 
 * 
 * @global stdObject $user
 *
 * @return string
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

  $output .= date('Y-m-d', strtotime("+2 days"));
  $output .= '</div>';

  return $output;
}

/**
 * Implements callback function for points earning.
 * 
 * @global stdObject $user
 */
function itg_loyalty_reward_earnpoint() {
  global $user;
  // Check user unique expiration key.
  $unique_exp_key = itg_loyalty_reward_unique_expiration($user->uid);
  $time_span = variable_get('lrp_loyality_points_expiry');
  $inputs = $_POST;
  $dedicated_point = itg_loyalty_reward_dedicated_point(check_plain($inputs['type']));
  $point_presave = array(
    'uid' => $user->uid,
    'loyalty_type' => check_plain($inputs['type']),
    'loyalty_points' => $dedicated_point,
    'pointer_key' => $unique_exp_key != '' ? $unique_exp_key : '',
    'node_id' => 1,
    'created' => REQUEST_TIME,
  );
  $flag = '';
  // Check if expiry key is availbal and not expired.
  if ($unique_exp_key != '') {
    // Add point into user point table.    
    itg_loyalty_reward_add_point($point_presave, 'update');
    $flag = 'old_key';
  }
  else {
    $presave = array(
      'uid' => $user->uid,
      'pointer_key' => uniqid('itg'),
      'created' => REQUEST_TIME,
      'expiry_date' => time() + ($time_span * 24 * 60 * 60),
    );
    $itg_query = db_insert('itg_lrp_pointer_key')
        ->fields($presave)
        ->execute();
    $point_presave['pointer_key'] = $presave['pointer_key'];
    // Add point into user point table.    
    itg_loyalty_reward_add_point($point_presave, 'new');
    $flag = 'new_key';
  }
  // Set ajax response code.
  if ($flag == 'new_key') {
    echo drupal_json_encode(array('code' => 1));
  }
  elseif ($flag == 'old_key') {
    echo drupal_json_encode(array('code' => 2));
  }
  else {
    echo drupal_json_encode(array('code' => 0));
  }
}

/**
 * Insert points into point table.
 *
 * @global stdObject $user
 * @param array $presave
 *   Mixed array for inserting data.
 */
function itg_loyalty_reward_add_point($presave, $op) {
  global $user;
  $itg_query = db_insert('itg_lrp_loyalty_points')
      ->fields($presave)
      ->execute();
  if ($itg_query >= 1 && $op == 'new') {
    $point_presave = array(
      'uid' => $presave['uid'],
      'total_point' => $presave['loyalty_points'],
      'redeemed_point' => 0,
      'remaining_point' => 0,
      'pointer_key' => $presave['pointer_key'],
    );
    // Inser into point history table.
    $itg_query = db_insert('itg_loyalty_reward_point_history')
        ->fields($point_presave)
        ->execute();
  }
  elseif ($itg_query >= 1 && $op == 'update') {
    $itg_result = new stdClass();
    $itg_query = db_select('itg_loyalty_reward_point_history', 'itg');
    $itg_query->fields('itg', array('id', 'total_point'))
        ->condition('uid', $user->uid)
        ->condition('pointer_key', $presave['pointer_key']);
    $itg_result = $itg_query->execute()->fetchObject();

    // Add point to existing point.
    $new_point = $itg_result->total_point + $presave['loyalty_points'];
    // Update new points on table.
    $itg_query = db_update('itg_loyalty_reward_point_history')
        ->fields(array('total_point' => $new_point))
        ->condition('id', $itg_result->id)
        ->execute();
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

/**
 * Return dedicated points against event.
 *
 * @param string $type
 *   Type of the events triggered by user.
 *
 * @return int
 *   Return points specified for given trigger.
 */
function itg_loyalty_reward_dedicated_point($type) {
  $data = array(
    'share' => variable_get(lrp_content_share),
    'like' => variable_get(lrp_content_like),
    'visit' => variable_get(lrp_content_visit),
    'follow' => variable_get(lrp_follow_itg_on_social_sites),
    'ns' => variable_get(lrp_newsletter_subscription),
    'ugc' => variable_get(lrp_ugc_contribution),
    'ol-register' => variable_get(lrp_online_registration_for_any_events),
    'participate' => variable_get(lrp_participation_in_poll_campaign_survey),
    'raf' => variable_get(lrp_refer_a_friend),
  );

  return $data[$type];
}
