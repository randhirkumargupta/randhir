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

  // Exported permission: 'create coupon content on assigned domains'.
  $permissions['create coupon content on assigned domains'] = array(
    'name' => 'create coupon content on assigned domains',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete coupon content on assigned domains'.
  $permissions['delete coupon content on assigned domains'] = array(
    'name' => 'delete coupon content on assigned domains',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update coupon content on assigned domains'.
  $permissions['update coupon content on assigned domains'] = array(
    'name' => 'update coupon content on assigned domains',
    'roles' => array(
      'Marketing Manager' => 'Marketing Manager',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'domain',
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
