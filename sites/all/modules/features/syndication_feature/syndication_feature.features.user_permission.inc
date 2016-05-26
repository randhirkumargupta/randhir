<?php
/**
 * @file
 * syndication_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function syndication_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create syndication_client content'.
  $permissions['create syndication_client content'] = array(
    'name' => 'create syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create syndication_rule content'.
  $permissions['create syndication_rule content'] = array(
    'name' => 'create syndication_rule content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any syndication_client content'.
  $permissions['delete any syndication_client content'] = array(
    'name' => 'delete any syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any syndication_rule content'.
  $permissions['delete any syndication_rule content'] = array(
    'name' => 'delete any syndication_rule content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own syndication_client content'.
  $permissions['delete own syndication_client content'] = array(
    'name' => 'delete own syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own syndication_rule content'.
  $permissions['delete own syndication_rule content'] = array(
    'name' => 'delete own syndication_rule content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any syndication_client content'.
  $permissions['edit any syndication_client content'] = array(
    'name' => 'edit any syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any syndication_rule content'.
  $permissions['edit any syndication_rule content'] = array(
    'name' => 'edit any syndication_rule content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own syndication_client content'.
  $permissions['edit own syndication_client content'] = array(
    'name' => 'edit own syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own syndication_rule content'.
  $permissions['edit own syndication_rule content'] = array(
    'name' => 'edit own syndication_rule content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
