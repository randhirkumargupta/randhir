<?php

/*
 * Inc file contains the common functions
 */

/**
 * callback for cms user dashboard  
 */
function itg_users_cms_user_dashboard() {
  $data = '';
  // Code for User menu on dashboard

  // $remove_menu_link = array('manage-poll' => 'Poll', 'manage-survey' => 'Survey');
  $remove_menu_link = array();
  $user_menu_tree = menu_tree_all_data('menu-admin-left-menu');

  foreach ($user_menu_tree as $key_tree => $val_tree) {
    if (empty($val_tree['below'])) {
      $menu_link[$val_tree['link']['link_path']] = t($val_tree['link']['link_title']);
    }
    else {
      foreach ($val_tree['below'] as $key => $val) {
        $menu_link[$val['link']['link_path']] = t($val['link']['link_title']);
      }
    }
  }
  // Loyalty & Rewards not found
  $menu_link = array_diff($menu_link, $remove_menu_link);
  $listed_menu_link = array(
      'mydraft-story' => 'Story',
      'mydraft-photogallery' => 'Photogallery',
      'mydraft-video' => 'Videogallery',
      'breaking-news' => 'Breaking News',
      'category-manager-listing' => 'Category Management',
      'manage-users' => 'User Management',
      'manage-magazines' => 'Magazine',
      'manage-supplements' => 'Supplement',
      'manage-issues' => 'Issue',
      'manage-newsletter-templates' => 'Template Management',
      'movie-review-draft-list' => 'Mega Review',
      'manage-ads' => 'Ads',
      'manage-poll' => 'Poll',
      'manage-survey' => 'Survey',
      'manage-quiz' => 'Quiz',
      'manage-newsletter' => 'Newsletter',
      'manage-event-backend' => 'Events',
      'menu-manager/second' => 'Menu manager',
      'live-tv-integration' => 'Live tv Integration',
      'ugc-inqueue-content' => 'Manage UGC',
      'tv' => 'Upload Tv Schedule',
      'mydraft-blogs' => 'Blogs',
      'report/filed-content' => 'CMS Report');
  $data['user_link'] = array_intersect($menu_link, $listed_menu_link);
  return theme('cms_user_dashboard', array('data' => $data));
}

/**
 * Implements itg_users_block_user
 */

function itg_users_block_user() {
  $users = entity_load('user');
  $current_date = date('Y-m-d');
  foreach ($users as $user) {
    if ($user->uid != 0 && !empty($user->field_story_expiry_date[LANGUAGE_NONE][0]['value'])) {
      $user_exp_date = strtotime($user->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      $user_exp_date = date('Y-m-d', $user_exp_date);
      if ($user_exp_date == $current_date) {
        $user->status = 0;
        entity_save('user', $user);
      }
    }
  }
}
