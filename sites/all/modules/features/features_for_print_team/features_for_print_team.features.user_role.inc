<?php
/**
 * @file
 * features_for_print_team.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function features_for_print_team_user_default_roles() {
  $roles = array();

  // Exported role: Knowledge Centre.
  $roles['Knowledge Centre'] = array(
    'name' => 'Knowledge Centre',
    'weight' => 23,
  );

  return $roles;
}
