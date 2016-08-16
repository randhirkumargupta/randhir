<?php
/**
 * @file
 * features_for_survey.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_survey_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create survey content'.
  $permissions['create survey content'] = array(
    'name' => 'create survey content',
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

  // Exported permission: 'delete any survey content'.
  $permissions['delete any survey content'] = array(
    'name' => 'delete any survey content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own survey content'.
  $permissions['delete own survey content'] = array(
    'name' => 'delete own survey content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any survey content'.
  $permissions['edit any survey content'] = array(
    'name' => 'edit any survey content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own survey content'.
  $permissions['edit own survey content'] = array(
    'name' => 'edit own survey content',
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

  // Exported permission: 'survey admin users'.
  $permissions['survey admin users'] = array(
    'name' => 'survey admin users',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_survey',
  );

  return $permissions;
}
