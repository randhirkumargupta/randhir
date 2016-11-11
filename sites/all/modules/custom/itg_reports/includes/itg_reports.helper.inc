<?php

/**
 * @file
 *   This file contains report dashboard logic and implementation.
 */

/**
 * Implments callback function for "itg-report-dashboard".
 *
 * @return
 *   Themed html output.
 */
function itg_report_user_dashboard() {
  $data = array();
  $user_menu_tree = menu_tree_all_data('menu-itg-reports');  
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
  $data['user_link'] = $menu_link;

  return theme('itg_reports_dashboard', array('data' => $data));
}
