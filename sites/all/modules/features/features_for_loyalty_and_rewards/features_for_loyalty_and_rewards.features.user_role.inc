<?php
/**
 * @file
 * features_for_loyalty_and_rewards.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function features_for_loyalty_and_rewards_user_default_roles() {
  $roles = array();

  // Exported role: Marketing Manager.
  $roles['Marketing Manager'] = array(
    'name' => 'Marketing Manager',
    'weight' => 22,
  );

  return $roles;
}
