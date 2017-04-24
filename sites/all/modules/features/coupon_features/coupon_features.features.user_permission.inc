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
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any coupon content'.
  $permissions['edit any coupon content'] = array(
    'name' => 'edit any coupon content',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own coupon content'.
  $permissions['edit own coupon content'] = array(
    'name' => 'edit own coupon content',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'upload third party coupon'.
  $permissions['upload third party coupon'] = array(
    'name' => 'upload third party coupon',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_coupon',
  );

  return $permissions;
}
