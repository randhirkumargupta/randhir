<?php

/*
 * @file
 *   Helper file for moduel itg personalization.
 */

/**
 * Get badge detail for current user.
 *
 * @param int $uid
 *  User unique id.
 *
 * @return array
 *   Earned and next badge information.
 */
function itg_personalization_badge($uid) {
  $data = itg_loyalty_reward_user_details($uid);    
  // Prepare array of all badge steps.
  $badge = array(
    variable_get('lrp_gold_star_one'),
    variable_get('lrp_gold_star_two'),
    variable_get('lrp_gold_star_three'),
    variable_get('lrp_gold_star_four'),
    variable_get('lrp_gold_star_five'),
  );
  // Compare earned points with badge points.
  $earned_badge = $points_to_go = 0;
  $flag = FALSE;  
  if ($data['total_earned_so_far'] > 0) {
    foreach ($badge as $key => $point) {
      $flag = itg_personalization_badge_stage($badge, $key, $data['total_earned_so_far']);      
      if ($flag && $key < 4) {        
        $earned_badge = $key + 1;
        $points_to_go = $badge[$key + 1] - $data['total_earned_so_far'];
        $point_between_badge = $badge[$key + 1] - $badge[$key];
        $over_point = $data['total_earned_so_far'] - $badge[$key];
        break;
      }
      elseif ($flag && $key == 4) {        
        $earned_badge = $key + 1;
        $points_to_go = 0;
        $point_between_badge = 0;        
      }
      else {
        $earned_badge = 0;
        $points_to_go = $badge[$key + 1] - $data['total_earned_so_far'];        
        $point_between_badge = $badge[$key + 1] - $badge[$key];
        $over_point = $data['total_earned_so_far'] - $badge[$key];
      }      
    }
  }  
  if ($point_between_badge) {
    $progress_bar = (100 * $over_point)/ $point_between_badge;
  }
  elseif($over_point == 0) {
    $progress_bar = 0;
  }
  else {
    $progress_bar = 100;
  }  
  $data = array(
    'total' => $data['total_earned_so_far'],
    'earn' => $earned_badge,
    'next' => $earned_badge != 5 ? $earned_badge + 1 : 0,
    'points_to_go' => $points_to_go,
    'progress_bar' => $progress_bar,
  );

  return $data;
}

/**
 * Implements 'itg_personalization_badge_stage' to get user badge status.
 *
 * @param array $badge
 *   Badge level and corrosponds point.
 * @param type $key
 *   Index for $badge array.
 * @param type $point
 *   Points earned by user.
 * @return boolean
 *   If user met with badge critera then return true else return false.
 */
function itg_personalization_badge_stage($badge, $key, $point) {
  if ($key < 4) {       
    return $point < $badge[$key + 1] && $point >= $badge[$key] ? TRUE : FALSE;
  }
  else {    
    return $point >= $badge[$key] ? TRUE : FALSE;
  }
}