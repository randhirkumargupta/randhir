<?php
/**
 * @file
 * feature_for_breaking_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_breaking_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create breaking_news content'.
  $permissions['create breaking_news content'] = array(
    'name' => 'create breaking_news content',
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

  // Exported permission: 'edit any breaking_news content'.
  $permissions['edit any breaking_news content'] = array(
    'name' => 'edit any breaking_news content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own breaking_news content'.
  $permissions['edit own breaking_news content'] = array(
    'name' => 'edit own breaking_news content',
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

  return $permissions;
}
