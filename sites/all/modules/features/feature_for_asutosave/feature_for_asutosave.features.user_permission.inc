<?php
/**
 * @file
 * feature_for_asutosave.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_asutosave_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg_autosave settings'.
  $permissions['administer itg_autosave settings'] = array(
    'name' => 'administer itg_autosave settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'itg_autosave',
  );

  return $permissions;
}
