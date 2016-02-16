<?php
/**
 * @file
 * photogallery.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function photogallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create photogallery content'.
  $permissions['create photogallery content'] = array(
    'name' => 'create photogallery content',
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

  // Exported permission: 'delete any photogallery content'.
  $permissions['delete any photogallery content'] = array(
    'name' => 'delete any photogallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own photogallery content'.
  $permissions['delete own photogallery content'] = array(
    'name' => 'delete own photogallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any photogallery content'.
  $permissions['edit any photogallery content'] = array(
    'name' => 'edit any photogallery content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own photogallery content'.
  $permissions['edit own photogallery content'] = array(
    'name' => 'edit own photogallery content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Intern' => 'Intern',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
    ),
    'module' => 'node',
  );

  return $permissions;
}
