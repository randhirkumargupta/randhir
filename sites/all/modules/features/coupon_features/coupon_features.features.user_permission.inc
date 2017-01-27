<?php
/**
 * @file
 * coupon_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function coupon_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create coupon content'.
  $permissions['create coupon content'] = array(
    'name' => 'create coupon content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any coupon content'.
  $permissions['delete any coupon content'] = array(
    'name' => 'delete any coupon content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own coupon content'.
  $permissions['delete own coupon content'] = array(
    'name' => 'delete own coupon content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any coupon content'.
  $permissions['edit any coupon content'] = array(
    'name' => 'edit any coupon content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own coupon content'.
  $permissions['edit own coupon content'] = array(
    'name' => 'edit own coupon content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'upload third party coupon'.
  $permissions['upload third party coupon'] = array(
    'name' => 'upload third party coupon',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_coupon',
  );

  return $permissions;
}
