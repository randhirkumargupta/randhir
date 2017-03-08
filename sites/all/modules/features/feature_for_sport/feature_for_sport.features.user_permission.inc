<?php
/**
 * @file
 * feature_for_sport.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_sport_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create sport_static_page content'.
  $permissions['create sport_static_page content'] = array(
    'name' => 'create sport_static_page content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sport_static_page content'.
  $permissions['delete any sport_static_page content'] = array(
    'name' => 'delete any sport_static_page content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sport_static_page content'.
  $permissions['delete own sport_static_page content'] = array(
    'name' => 'delete own sport_static_page content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sport_static_page content'.
  $permissions['edit any sport_static_page content'] = array(
    'name' => 'edit any sport_static_page content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sport_static_page content'.
  $permissions['edit own sport_static_page content'] = array(
    'name' => 'edit own sport_static_page content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
