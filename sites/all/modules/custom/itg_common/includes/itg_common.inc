<?php

/*
 * Inc file contains the common functions
 */

/**
* callback for cms user dashboard
*  
*/

function itg_common_cms_user_dashboard() {
  
   $data = '';
   
   // Code for User menu on dashboard
   $user_menu_tree = menu_tree_all_data('menu-admin-left-menu');
   
   foreach ($user_menu_tree as $key_tree => $val_tree) {     
     if (empty($val_tree['below'])) {
       $menu_link[$val_tree['link']['link_path']] =  $val_tree['link']['link_title'];
     } else {
       foreach ($val_tree['below'] as $key => $val) {
         $menu_link[$val['link']['link_path']] =  $val['link']['link_title'];
       }
     }     
   }
   
   $data['user_link'] = $menu_link;
   
   return theme('cms_user_dashboard', array('data' => $data));   
 }