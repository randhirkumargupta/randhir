<?php
/**
 * @file
 * feature_category_management.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_category_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in category_management'.
  $permissions['delete terms in category_management'] = array(
    'name' => 'delete terms in category_management',
    'roles' => array(
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in category_management'.
  $permissions['edit terms in category_management'] = array(
    'name' => 'edit terms in category_management',
    'roles' => array(
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
