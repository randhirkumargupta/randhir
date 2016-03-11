<?php
/**
 * @file
 * feature_tag_management.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_tag_management_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-left-menu.
  $menus['menu-admin-left-menu'] = array(
    'menu_name' => 'menu-admin-left-menu',
    'title' => 'ITG Admin Menu',
    'description' => 'Admin menu for Management.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin menu for Management.');
  t('ITG Admin Menu');

  return $menus;
}
