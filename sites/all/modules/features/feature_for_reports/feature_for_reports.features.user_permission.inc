<?php
/**
 * @file
 * feature_for_reports.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_reports_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view report dashboard'.
  $permissions['view report dashboard'] = array(
    'name' => 'view report dashboard',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_reports',
  );

  return $permissions;
}
