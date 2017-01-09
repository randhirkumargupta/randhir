<?php
/**
 * @file
 * feature_for_static_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_static_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create page content on assigned domains'.
  $permissions['create page content on assigned domains'] = array(
    'name' => 'create page content on assigned domains',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete page content on assigned domains'.
  $permissions['delete page content on assigned domains'] = array(
    'name' => 'delete page content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update page content on assigned domains'.
  $permissions['update page content on assigned domains'] = array(
    'name' => 'update page content on assigned domains',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  return $permissions;
}
