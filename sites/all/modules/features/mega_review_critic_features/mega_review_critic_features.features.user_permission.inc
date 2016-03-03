<?php
/**
 * @file
 * mega_review_critic_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mega_review_critic_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create mega_review_critic content'.
  $permissions['create mega_review_critic content'] = array(
    'name' => 'create mega_review_critic content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor' => 'Section Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any mega_review_critic content'.
  $permissions['delete any mega_review_critic content'] = array(
    'name' => 'delete any mega_review_critic content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor' => 'Section Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own mega_review_critic content'.
  $permissions['delete own mega_review_critic content'] = array(
    'name' => 'delete own mega_review_critic content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any mega_review_critic content'.
  $permissions['edit any mega_review_critic content'] = array(
    'name' => 'edit any mega_review_critic content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor' => 'Section Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mega_review_critic content'.
  $permissions['edit own mega_review_critic content'] = array(
    'name' => 'edit own mega_review_critic content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Intern' => 'Intern',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
    ),
    'module' => 'node',
  );

  return $permissions;
}
