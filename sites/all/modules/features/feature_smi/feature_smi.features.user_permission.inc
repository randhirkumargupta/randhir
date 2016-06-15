<?php
/**
 * @file
 * feature_smi.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_smi_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg_social_media edit_content settings'.
  $permissions['administer itg_social_media edit_content settings'] = array(
    'name' => 'administer itg_social_media edit_content settings',
    'roles' => array(
      'Social Media' => 'Social Media',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_social_media',
  );

  // Exported permission: 'administer itg_social_media settings'.
  $permissions['administer itg_social_media settings'] = array(
    'name' => 'administer itg_social_media settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'itg_social_media',
  );

  return $permissions;
}
