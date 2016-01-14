<?php
/**
 * @file
 * user_management.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function user_management_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin-menu_user-management:manage-users.
  $menu_links['menu-admin-menu_user-management:manage-users'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'manage-users',
    'router_path' => 'manage-users',
    'link_title' => 'User Management',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_user-management:manage-users',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('User Management');

  return $menu_links;
}
