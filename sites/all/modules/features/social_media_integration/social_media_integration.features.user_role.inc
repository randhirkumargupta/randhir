<?php
/**
 * @file
 * social_media_integration.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function social_media_integration_user_default_roles() {
  $roles = array();

  // Exported role: Social Media.
  $roles['Social Media'] = array(
    'name' => 'Social Media',
    'weight' => 20,
  );

  return $roles;
}
