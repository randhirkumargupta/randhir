<?php
/**
 * @file
 * feature_for_personalization.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_for_personalization_user_default_roles() {
  $roles = array();

  // Exported role: Front User.
  $roles['Front User'] = array(
    'name' => 'Front User',
    'weight' => 23,
  );

  return $roles;
}
