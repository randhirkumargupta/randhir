<?php
/**
 * @file
 * feature_for_personalization.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_personalization_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view personalized content'.
  $permissions['view personalized content'] = array(
    'name' => 'view personalized content',
    'roles' => array(
      'Front User' => 'Front User',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_personalization',
  );

  return $permissions;
}
