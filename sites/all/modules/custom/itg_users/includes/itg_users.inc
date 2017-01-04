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

  $menu_link = array_diff($menu_link, $remove_menu_link);
  $data['user_link'] = $menu_link;
  
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
