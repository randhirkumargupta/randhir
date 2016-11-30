<?php
/**
 * @file
 * features_for_highlights.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_highlights_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create heighlights content'.
  $permissions['create heighlights content'] = array(
    'name' => 'create heighlights content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any heighlights content'.
  $permissions['edit any heighlights content'] = array(
    'name' => 'edit any heighlights content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own heighlights content'.
  $permissions['edit own heighlights content'] = array(
    'name' => 'edit own heighlights content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
