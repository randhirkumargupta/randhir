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

  // Exported permission: 'access block refresh content'.
  $permissions['access block refresh content'] = array(
    'name' => 'access block refresh content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'itg_akamai_block_refresh',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

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
