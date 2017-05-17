<?php
/**
 * @file
 * ads_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ads_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ads_management content'.
  $permissions['create ads_management content'] = array(
    'name' => 'create ads_management content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ads_management content'.
  $permissions['delete any ads_management content'] = array(
    'name' => 'delete any ads_management content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ads_management content'.
  $permissions['delete own ads_management content'] = array(
    'name' => 'delete own ads_management content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in ads_content'.
  $permissions['delete terms in ads_content'] = array(
    'name' => 'delete terms in ads_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any ads_management content'.
  $permissions['edit any ads_management content'] = array(
    'name' => 'edit any ads_management content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ads_management content'.
  $permissions['edit own ads_management content'] = array(
    'name' => 'edit own ads_management content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in ads_content'.
  $permissions['edit terms in ads_content'] = array(
    'name' => 'edit terms in ads_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
