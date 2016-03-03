<?php
/**
 * @file
 * feature_tag_management.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_tag_management_user_default_roles() {
  $roles = array();

  // Exported role: SEO.
  $roles['SEO'] = array(
    'name' => 'SEO',
    'weight' => 10,
  );

  return $roles;
}
