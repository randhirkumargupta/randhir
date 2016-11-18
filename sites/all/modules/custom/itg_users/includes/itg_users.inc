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
 * query to block user on expirt date
 */

function itg_users_block_user() {

  $query = db_select('users', 'u');
  $query->join('field_data_field_story_expiry_date', 'de', 'u.uid = de.entity_id');
  $query->fields('u', array('uid'));
  $query->fields('de', array('field_story_expiry_date_value'));
  $result = $query->execute();
  // get current date for compare expiry date of user
  $current_date = date('Y-m-d');
  while ($user_record = $result->fetchAssoc()) {
    $user_id = $user_record['uid'];
    $user_exp_date = strtotime($user_record['field_story_expiry_date_value']);
    $user_exp_date = date('Y-m-d', $user_exp_date);

    if ($user_exp_date == $current_date) {
      // block user
      db_update('users')
          ->fields(array(
            'status' => 0
          ))
          ->condition('uid', $user_id)
          ->execute();
    }
  }
}
