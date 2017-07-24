<?php

/*
 * Inc file contains the common functions
 */

/**
 * callback for cms user dashboard  
 */
function itg_users_cms_user_dashboard() {
  global $user;
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
   
    if (in_array("Author/Guest", $user->roles) || in_array("Intern", $user->roles) || in_array("Subeditor/Sr.Sub", $user->roles)) {
      $story_link = 'my-published-story';
      $photo_link = 'my-published-photogallery';
      $video_link = 'my-published-video';
    }
    else {
      $story_link = 'published-story?field_story_syndication_value_op=all';
      $video_link = 'published-video?field_story_syndication_value_op=all';
      $photo_link = 'published-photogallery?field_story_syndication_value_op=all';
    }
    
  $listed_menu_link_site_admin = array(
      $story_link => 'Story',
      $photo_link => 'Photogallery',
      $video_link => 'Videos',
      'breaking-news' => 'Breaking News',
      'category-manager-listing' => 'Category Management',
      'manage-users' => 'User Management',
      'manage-magazines' => 'Magazine',
      'manage-supplements' => 'Supplement',
      'manage-issues' => 'Issue',
      'manage-newsletter-templates' => 'Template Manager',
      'movie-review-draft-list' => 'Mega Review',
      'manage-ads' => 'Ads',
      'manage-poll' => 'Poll',
      'manage-survey' => 'Survey',
      'ask-an-expert' => 'Ask an expert',
      'manage-quiz' => 'Quiz',
      'manage-newsletter' => 'Newsletter',
      'manage-event-backend' => 'Events',
      'menu-manager/second' => 'Menu manager',
      'live-tv-integration' => 'Live TV Integration',
      'ugc-inqueue-content' => 'Manage UGC',
      'tv' => 'Upload TV Schedule',
      'admin/loyalty/lrp-manage-items' => 'Loyalty & Rewards',
      'mydraft-blogs' => 'Blogs',
      'report/filed-content' => 'CMS Report');

  
   if (in_array("Author/Guest", $user->roles) || in_array("Intern", $user->roles) || in_array("Subeditor/Sr.Sub", $user->roles)) {
      unset($listed_menu_link_site_admin['category-manager-listing'],
            $listed_menu_link_site_admin['manage-users'],
            $listed_menu_link_site_admin['manage-newsletter-templates'],
            $listed_menu_link_site_admin['manage-ads'],
            $listed_menu_link_site_admin['manage-poll'],
            $listed_menu_link_site_admin['menu-manager/second'], 
            $listed_menu_link_site_admin['live-tv-integration'],
            $listed_menu_link_site_admin['ugc-inqueue-content'],
            $listed_menu_link_site_admin['tv'],
            $listed_menu_link_site_admin['admin/loyalty/lrp-manage-items'],
            $listed_menu_link_site_admin['manage-newsletter']);
      
      $data['user_link'] = $listed_menu_link_site_admin;
     
   } else if(in_array("Copy Editor", $user->roles)) {

      unset($listed_menu_link_site_admin['category-manager-listing'],
            $listed_menu_link_site_admin['manage-newsletter-templates'],
            $listed_menu_link_site_admin['menu-manager/second'],
            $listed_menu_link_site_admin['live-tv-integration'],
            $listed_menu_link_site_admin['ugc-inqueue-content'],
            $listed_menu_link_site_admin['tv'],
            $listed_menu_link_site_admin['admin/loyalty/lrp-manage-items']);

     $data['user_link'] = $listed_menu_link_site_admin;
     
   } else if(in_array("UGC Moderator", $user->roles)) {
      unset($listed_menu_link_site_admin['breaking-news'],
            $listed_menu_link_site_admin['category-manager-listing'],
            $listed_menu_link_site_admin['ask-an-expert'],
            $listed_menu_link_site_admin['manage-newsletter-templates'],
            $listed_menu_link_site_admin['manage-users'],
            $listed_menu_link_site_admin['manage-magazines'],
            $listed_menu_link_site_admin['manage-supplements'],
            $listed_menu_link_site_admin['manage-issues'],
            $listed_menu_link_site_admin['movie-review-draft-list'],
            $listed_menu_link_site_admin['manage-ads'],
            $listed_menu_link_site_admin['manage-poll'],
            $listed_menu_link_site_admin['manage-survey'],
            $listed_menu_link_site_admin['manage-quiz'],
            $listed_menu_link_site_admin['manage-newsletter'],
            $listed_menu_link_site_admin['manage-event-backend'],
            $listed_menu_link_site_admin['menu-manager/second'],
            $listed_menu_link_site_admin['live-tv-integration'],
            $listed_menu_link_site_admin['tv'],
            $listed_menu_link_site_admin['admin/loyalty/lrp-manage-items'],
            $listed_menu_link_site_admin['mydraft-blogs'],
            $listed_menu_link_site_admin['report/filed-content'],
            $listed_menu_link_site_admin['my-published-story'],
            $listed_menu_link_site_admin['my-published-photogallery'],
            $listed_menu_link_site_admin['my-published-video'],
            $listed_menu_link_site_admin['published-story?field_story_syndication_value_op=all'],
            $listed_menu_link_site_admin['published-video?field_story_syndication_value_op=all'],
            $listed_menu_link_site_admin['published-photogallery?field_story_syndication_value_op=all']
          );

     $data['user_link'] = $listed_menu_link_site_admin;
     
   } else if (in_array("Section Editor/Anchor", $user->roles)) {
     
      unset($listed_menu_link_site_admin['manage-newsletter-templates'],
            $listed_menu_link_site_admin['menu-manager/second'],
            $listed_menu_link_site_admin['live-tv-integration'],
            $listed_menu_link_site_admin['ugc-inqueue-content'],
            $listed_menu_link_site_admin['tv'],
            $listed_menu_link_site_admin['admin/loyalty/lrp-manage-items']);
     
     $data['user_link'] = $listed_menu_link_site_admin;
     
   } else if (in_array("Editor", $user->roles) || in_array("Site Admin", $user->roles)) {
     $data['user_link'] = $listed_menu_link_site_admin;
   } else if (in_array("Correspondent", $user->roles)) {
     unset($menu_link['created-task-list']);
     $data['user_link'] = $menu_link;
   } else {
     $data['user_link'] = $menu_link;
   }
   
  return theme('cms_user_dashboard', array('data' => $data));
}

/**
 * Implements itg_users_block_user
 */

function itg_users_block_user() {
  $current_time = date("Y-m-d H:i:s");
  $itg_query = db_select('field_data_field_story_expiry_date', 'u');
  $itg_query->fields('u', array('entity_id'));
  $itg_query->condition('u.bundle', 'user', '=');
  $itg_query->condition('u.field_story_expiry_date_value', $current_time, '<');
  $itg_result = $itg_query->execute()->fetchAll();

  foreach ($itg_result as $itg_val) {
    $user = user_load($itg_val->entity_id);
    $user->status = 0;
    user_save($user);
  }
}
