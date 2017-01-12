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

  // Exported permission: 'create loyalty_and_rewards content'.
  $permissions['create loyalty_and_rewards content'] = array(
    'name' => 'create loyalty_and_rewards content',
    'roles' => array(
      'Editor' => 'Editor',
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any loyalty_and_rewards content'.
  $permissions['delete any loyalty_and_rewards content'] = array(
    'name' => 'delete any loyalty_and_rewards content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own loyalty_and_rewards content'.
  $permissions['delete own loyalty_and_rewards content'] = array(
    'name' => 'delete own loyalty_and_rewards content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any loyalty_and_rewards content'.
  $permissions['edit any loyalty_and_rewards content'] = array(
    'name' => 'edit any loyalty_and_rewards content',
    'roles' => array(
      'Editor' => 'Editor',
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own loyalty_and_rewards content'.
  $permissions['edit own loyalty_and_rewards content'] = array(
    'name' => 'edit own loyalty_and_rewards content',
    'roles' => array(
      'Editor' => 'Editor',
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'loyalty points configuration form'.
  $permissions['loyalty points configuration form'] = array(
    'name' => 'loyalty points configuration form',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_loyalty_reward',
  );

  // Exported permission: 'view product page'.
  $permissions['view product page'] = array(
    'name' => 'view product page',
    'roles' => array(
      'Front User' => 'Front User',
    ),
    'module' => 'itg_loyalty_reward',
  );

  return $permissions;
}
