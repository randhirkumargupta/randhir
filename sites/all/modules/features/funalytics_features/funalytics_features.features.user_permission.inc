<?php
/**
 * @file
 * funalytics_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function funalytics_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create itg_funalytics content'.
  $permissions['create itg_funalytics content'] = array(
    'name' => 'create itg_funalytics content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any itg_funalytics content'.
  $permissions['delete any itg_funalytics content'] = array(
    'name' => 'delete any itg_funalytics content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own itg_funalytics content'.
  $permissions['delete own itg_funalytics content'] = array(
    'name' => 'delete own itg_funalytics content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any itg_funalytics content'.
  $permissions['edit any itg_funalytics content'] = array(
    'name' => 'edit any itg_funalytics content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own itg_funalytics content'.
  $permissions['edit own itg_funalytics content'] = array(
    'name' => 'edit own itg_funalytics content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
