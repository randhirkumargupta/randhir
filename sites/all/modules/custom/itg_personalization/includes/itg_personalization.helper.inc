<?php

/*
 * @file
 *   Helper file for moduel itg personalization.
 */

/**
 * Ajax callback for getting saved content all block.
 *
 * @param string $view_name
 *   Name of the view.
 * @param string $type
 *   Type of the ajax callback.
 */
function _personalized_saved_content($view_name, $type = 'ajax') {
  if ($type == 'ajax') {
    $commands = array();
    switch ($view_name) {
      case 'all':
        $content = views_embed_view('personalization_saved_content', 'block_1');
        $commands[] = ajax_command_invoke('#block-itg-personalization-personalized-saved-content', 'show');
        $commands[] = ajax_command_invoke('.view-display-id-block_5', 'hide');
        break;
      case 'articles':
        $content = views_embed_view('personalization_saved_content', 'block_2');
        break;
      case 'videos':
        $content = views_embed_view('personalization_saved_content', 'block_3');
        break;
      case 'photogallery':
        $content = views_embed_view('personalization_saved_content', 'block_4');
        break;
      case 'author':
        $content = views_embed_view('personalization_saved_content', 'block_5');
        $commands[] = ajax_command_invoke('#block-itg-personalization-personalized-saved-content', 'hide');
        $commands[] = ajax_command_replace("#target-content", '<div id="target-content">' . $content . '</div>');
        break;
      case 'my-content':
        $content = '';
        $commands[] = ajax_command_invoke('#block-itg-personalization-user-my-content', 'show');
    }   
    $commands[] = ajax_command_replace("#target", '<div id="target">' . $content . '</div>');
    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
  }
}

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
  foreach ($badge as $key => $point) {    
    if ($point >= $data['total_earned_so_far']) {      
      $earned_badge = $key + 1;
      $points_to_go = $point - $data['total_earned_so_far'];
      break;
    }    
  }
  $data = array(
    'total' => $data['total_earned_so_far'],
    'earn' => $earned_badge,
    'next' => $earned_badge + 1,
    'points_to_go' => $points_to_go,
  );  
  
  return $data;
}