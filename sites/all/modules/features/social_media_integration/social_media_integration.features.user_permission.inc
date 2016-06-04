<?php
/**
 * @file
 * social_media_integration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function social_media_integration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg_social_media edit_content settings'.
  $permissions['administer itg_social_media edit_content settings'] = array(
    'name' => 'administer itg_social_media edit_content settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Social Media' => 'Social Media',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_social_media',
  );

  return $permissions;
}
