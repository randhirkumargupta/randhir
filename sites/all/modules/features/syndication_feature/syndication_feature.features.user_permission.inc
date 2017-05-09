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

  // Exported permission: 'create syndication_feed_from_pattern content'.
  $permissions['create syndication_feed_from_pattern content'] = array(
    'name' => 'create syndication_feed_from_pattern content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
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
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any syndication_feed_from_pattern content'.
  $permissions['delete any syndication_feed_from_pattern content'] = array(
    'name' => 'delete any syndication_feed_from_pattern content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any syndication_rule content'.
  $permissions['delete any syndication_rule content'] = array(
    'name' => 'delete any syndication_rule content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own syndication_client content'.
  $permissions['delete own syndication_client content'] = array(
    'name' => 'delete own syndication_client content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own syndication_feed_from_pattern content'.
  $permissions['delete own syndication_feed_from_pattern content'] = array(
    'name' => 'delete own syndication_feed_from_pattern content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own syndication_rule content'.
  $permissions['delete own syndication_rule content'] = array(
    'name' => 'delete own syndication_rule content',
    'roles' => array(),
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

  // Exported permission: 'edit any syndication_feed_from_pattern content'.
  $permissions['edit any syndication_feed_from_pattern content'] = array(
    'name' => 'edit any syndication_feed_from_pattern content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
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

  // Exported permission: 'edit own syndication_feed_from_pattern content'.
  $permissions['edit own syndication_feed_from_pattern content'] = array(
    'name' => 'edit own syndication_feed_from_pattern content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
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

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  return $permissions;
}
