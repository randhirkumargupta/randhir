<?php
/**
 * @file
 * feature_for_live_tv_integration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_live_tv_integration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create live_tv_integration content'.
  $permissions['create live_tv_integration content'] = array(
    'name' => 'create live_tv_integration content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any live_tv_integration content'.
  $permissions['delete any live_tv_integration content'] = array(
    'name' => 'delete any live_tv_integration content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own live_tv_integration content'.
  $permissions['delete own live_tv_integration content'] = array(
    'name' => 'delete own live_tv_integration content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any live_tv_integration content'.
  $permissions['edit any live_tv_integration content'] = array(
    'name' => 'edit any live_tv_integration content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own live_tv_integration content'.
  $permissions['edit own live_tv_integration content'] = array(
    'name' => 'edit own live_tv_integration content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
