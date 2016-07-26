<?php
/**
 * @file
 * features_for_loyalty_and_rewards.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_loyalty_and_rewards_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'loyalty points configuration form'.
  $permissions['loyalty points configuration form'] = array(
    'name' => 'loyalty points configuration form',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_loyalty_reward',
  );

  return $permissions;
}
