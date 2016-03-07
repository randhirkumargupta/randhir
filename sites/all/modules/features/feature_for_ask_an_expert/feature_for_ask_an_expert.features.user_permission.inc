<?php
/**
 * @file
 * feature_for_ask_an_expert.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_ask_an_expert_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ask_an_expert content'.
  $permissions['create ask_an_expert content'] = array(
    'name' => 'create ask_an_expert content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ask_an_expert content'.
  $permissions['edit any ask_an_expert content'] = array(
    'name' => 'edit any ask_an_expert content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
