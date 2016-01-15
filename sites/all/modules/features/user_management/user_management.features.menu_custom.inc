<?php
/**
 * @file
 * user_management.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function user_management_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-menu.
  $menus['menu-admin-menu'] = array(
    'menu_name' => 'menu-admin-menu',
    'title' => 'Admin Menu',
    'description' => 'Admin menu for Management. ',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Menu');
  t('Admin menu for Management. ');

  return $menus;
}
