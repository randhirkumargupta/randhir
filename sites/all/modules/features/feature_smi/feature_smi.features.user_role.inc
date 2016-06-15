<?php
/**
 * @file
 * feature_smi.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_smi_user_default_roles() {
  $roles = array();

  // Exported role: Social Media.
  $roles['Social Media'] = array(
    'name' => 'Social Media',
    'weight' => 20,
  );

  return $roles;
}
