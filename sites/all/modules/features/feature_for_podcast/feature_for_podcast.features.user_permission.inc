<?php
/**
 * @file
 * feature_for_podcast.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_podcast_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create podcast content'.
  $permissions['create podcast content'] = array(
    'name' => 'create podcast content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any podcast content'.
  $permissions['delete any podcast content'] = array(
    'name' => 'delete any podcast content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own podcast content'.
  $permissions['delete own podcast content'] = array(
    'name' => 'delete own podcast content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any podcast content'.
  $permissions['edit any podcast content'] = array(
    'name' => 'edit any podcast content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own podcast content'.
  $permissions['edit own podcast content'] = array(
    'name' => 'edit own podcast content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Expert' => 'Expert',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
    ),
    'module' => 'node',
  );

  return $permissions;
}
