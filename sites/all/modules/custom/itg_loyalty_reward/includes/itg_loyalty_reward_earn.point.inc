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
  $output .= '</div>';

  return $output;
}

/**
 * Validate news letter points.
 *
 * @param int $user
 * @param string $type
 * @param string $news_letter
 * @return boolean
 */
function itg_loyalty_reward_newsletter_point($user, $type, $news_letter) {
  $itg_result = '';
  $dedicated_point = itg_loyalty_reward_dedicated_point($type);
  $itg_query = db_select('itg_lrp_loyalty_points', 'p')
      ->fields('p', array('newsletter'))
      ->condition('uid', $user)
      ->condition('loyalty_type', $dedicated_point['label']);
  $itg_result = $itg_query->execute()->fetchAll();
  // If newsletter subscription is first time then earn point else not.
  foreach ($itg_result as $value) {
    if ($value->newsletter == $news_letter) {
      return TRUE;
    }
  }
}
/**
 * Validate fb and twitter points.
 *
 * @param int $user
 * @param string $type
 * @param int $nid
 * @return boolean
 */
function itg_loyalty_reward_share_point($user, $type, $nid = NULL) {
  $itg_result = '';
  $dedicated_point = itg_loyalty_reward_dedicated_point($type);
  $itg_query = db_select('itg_lrp_loyalty_points', 'p')
      ->fields('p', array('id'))
      ->condition('uid', $user);
      if(!empty($nid)) {
      $itg_query->condition('node_id', $nid);
      }
      $itg_query->condition('loyalty_type', $dedicated_point['label']);
  $itg_result = $itg_query->execute()->fetchField();
  
    if (!empty($itg_result)) {
      return TRUE;
    }
  
}



/**
 * Implements callback function for points earning.
 * 
 * @global stdObject $user
 * @param int $nid
 * @param string $type
 * @param int $uid
 * @param string $news_l
 * @return
 */
function itg_loyalty_reward_earnpoint($nid = NULL, $type = NULL, $uid = NULL, $news_l = NULL) {
  global $user;
  $ns_validate = FALSE;
  if ($uid != NULL) {
    $user_id = $uid;
    switch ($type) {
      case 'ns':
        $ns_validate = itg_loyalty_reward_newsletter_point($uid, $type, $news_l);
        if ($ns_validate) {
          return;
        }
        break;
        case 'twitter_share':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type, $nid);
        if ($ns_validate) {
          return;
        }
        break;
        case 'google_share':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type, $nid);
        if ($ns_validate) {
          return;
        }
        break;
        case 'share':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type, $nid);
        if ($ns_validate) {
          return;
        }
        break;
        case 'twitter_follow':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type);
        if ($ns_validate) {
          return;
        }
        break;
        case 'fb_follow':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type);
        if ($ns_validate) {
          return;
        }
        break;
        case 'google_follow':
        $ns_validate = itg_loyalty_reward_share_point($uid, $type);
        if ($ns_validate) {
          return;
        }
        
    }
  } else {
    $user_id = $user->uid;
  }
  // Check user unique expiration key.
  $unique_exp_key = itg_loyalty_reward_unique_expiration($user_id);
  $time_span = variable_get('lrp_loyality_points_expiry');
  if (isset($_POST['type'])) {
    $inputs = $_POST;
  } else {
    $inputs['type'] = $type;
  }
  $dedicated_point = itg_loyalty_reward_dedicated_point(check_plain($inputs['type']));
  $point_presave = array(
    'uid' => $user_id,
    'loyalty_type' => $dedicated_point['label'],
    'loyalty_points' => $dedicated_point['point'],
    'pointer_key' => $unique_exp_key != '' ? $unique_exp_key : '',
    'node_id' => $nid != NULL ? $nid : 0,
    'created' => REQUEST_TIME,
  );
  if ($news_l != NULL) {
    $point_presave['newsletter'] = $news_l;
  }
  $flag = '';
  // Check if expiry key is availbal and not expired.
  if ($unique_exp_key != '') {
    // Add point into user point table.    
    itg_loyalty_reward_add_point($point_presave, 'update');
    $flag = 'old_key';
  } else {
    $presave = array(
      'uid' => $user_id,
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
    watchdog('Loyalty Points', drupal_json_encode(array('code' => 1)));
  } elseif ($flag == 'old_key') {
    watchdog('Loyalty Points', drupal_json_encode(array('code' => 2)));
  } else {
    watchdog('Loyalty Points', drupal_json_encode(array('code' => 0)));
  }
}

/**
 * Insert points into point table.
 *
 * @param array $presave
 *   Mixed array for inserting data.
 * @param string $op
 *   Type of operation. 'new' and 'update'.
 */
function itg_loyalty_reward_add_point($presave, $op) {
  $itg_query = db_insert('itg_lrp_loyalty_points')
      ->fields($presave)
      ->execute();
  if ($itg_query >= 1 && $op == 'new') {
    $point_presave = array(
      'uid' => $presave['uid'],
      'total_point' => $presave['loyalty_points'],
      'redeemed_point' => 0,
      'remaining_point' => $presave['loyalty_points'],
      'pointer_key' => $presave['pointer_key'],
    );
    // Inser into point history table.
    $itg_query = db_insert('itg_loyalty_reward_point_history')
        ->fields($point_presave)
        ->execute();
  } elseif ($itg_query >= 1 && $op == 'update') {
    // Update new points on table.
    $itg_query = db_update('itg_loyalty_reward_point_history')
        ->fields(array('total_point' => $presave['loyalty_points']))
        ->expression('total_point', 'total_point + :loyalty', array(':loyalty' => $presave['loyalty_points']))
        ->expression('remaining_point', 'remaining_point + :loyalty', array(':loyalty' => $presave['loyalty_points']))
        ->condition('pointer_key', $presave['pointer_key'])
        ->execute();
  }
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
    'share' => array(
      'label' => 'Content Share',
      'point' => variable_get('lrp_content_share'),
    ),
    'google_share' => array(
      'label' => 'Google Share',
      'point' => variable_get('lrp_content_share'),
    ),
    'twitter_share' => array(
      'label' => 'Twitter Share',
      'point' => variable_get('lrp_content_share'),
    ),
    'like' => array(
      'label' => 'Content Like',
      'point' => variable_get('lrp_content_like'),
    ),
    'visit' => array(
      'label' => 'Content Visit',
      'point' => variable_get('lrp_content_visit'),
    ),
    'follow' => array(
      'label' => 'Content Follow',
      'point' => variable_get('lrp_follow_itg_on_social_sites'),
    ),
    'fb_follow' => array(
      'label' => 'Facebook Follow',
      'point' => variable_get('lrp_follow_itg_on_social_sites'),
    ),
    'twitter_follow' => array(
      'label' => 'Twitter Follow',
      'point' => variable_get('lrp_follow_itg_on_social_sites'),
    ),
    'google_follow' => array(
      'label' => 'Google Follow',
      'point' => variable_get('lrp_follow_itg_on_social_sites'),
    ),
    'ns' => array(
      'label' => 'Newsletter Subscription',
      'point' => variable_get('lrp_newsletter_subscription'),
    ),
    'ugc' => array(
      'label' => 'UGC Contribution',
      'point' => variable_get('lrp_ugc_contribution'),
    ),
    'ol-register' => array(
      'label' => 'Online Registration for Any Events',
      'point' => variable_get('lrp_online_registration_for_any_events'),
    ),
    'participate' => array(
      'label' => 'Participation in Poll/Campaign/Survey',
      'point' => variable_get('lrp_participation_in_poll_campaign_survey'),
    ),
    'raf' => array(
      'label' => 'Refer a Friend',
      'point' => variable_get('lrp_refer_a_friend'),
    ),
  );

  return $data[$type];
}

/**
 * Implements callback function for point notification.
 */
function itg_loyalty_reward_points_expire_notification_callback() {
  $itg_result = array();
  try {
    $itg_query = db_select('itg_lrp_pointer_key', 'pk');
    $itg_query->join('users', 'u', 'pk.uid=u.uid');    
    $itg_query->join('itg_loyalty_reward_point_history', 'ph', 'pk.pointer_key=ph.pointer_key');
    $itg_query->fields('u', array('mail', 'name'));
    $itg_query->fields('ph', array('remaining_point'));
    $itg_query->fields('pk', array('expiry_date'));
    $itg_query->addExpression('DATEDIFF(from_unixtime(pk.expiry_date), CURDATE())', 'date_diff_real');
    $itg_query->havingCondition('date_diff_real', 1);
    $itg_result = $itg_query->execute()->fetchAll();
  } catch (Exception $ex) {
    watchdog('Point Expiry Notification', $ex->getMessage());
  }
  // Send mail if got some user on result.  
  $erros = array_filter($itg_result);
  if (!empty($itg_result)) {
    foreach ($itg_result as $value) {
      $data['remaining_point'] = $value->remaining_point;
      $data['name'] = $value->name;
      $data['expiry_date'] = $value->expiry_date;
      // for mail code
      itg_common_get_mail_content($data, $value->mail, 'lrp_point', 'India Today | Loyalty Points Notification');
    }
  }
}
