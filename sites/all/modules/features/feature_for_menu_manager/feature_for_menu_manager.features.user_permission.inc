<?php
/**
 * @file
 * feature_for_menu_manager.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_menu_manager_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg menu manager'.
  $permissions['administer itg menu manager'] = array(
    'name' => 'administer itg menu manager',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_menu_manager',
  );

  return $permissions;
}
