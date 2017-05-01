<?php
/**
 * @file
 * feature_for_akamai.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_akamai_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg akamai'.
  $permissions['administer itg akamai'] = array(
    'name' => 'administer itg akamai',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_akamai',
  );

  // Exported permission: 'purge itg akamai cache'.
  $permissions['purge itg akamai cache'] = array(
    'name' => 'purge itg akamai cache',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_akamai',
  );

  return $permissions;
}
