<?php

/* 
 * @file
 *   Product listing page callback and other settings. 
 */

/**
 * Implements callback function for product listing page.
 */
function itg_loyalty_reward_redeem_points() {
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
