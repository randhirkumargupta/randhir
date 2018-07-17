<?php
/**
 * @file
 * astro_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function astro_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create astro content'.
  $permissions['create astro content'] = array(
    'name' => 'create astro content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any astro content'.
  $permissions['delete any astro content'] = array(
    'name' => 'delete any astro content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own astro content'.
  $permissions['delete own astro content'] = array(
    'name' => 'delete own astro content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any astro content'.
  $permissions['edit any astro content'] = array(
    'name' => 'edit any astro content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own astro content'.
  $permissions['edit own astro content'] = array(
    'name' => 'edit own astro content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
