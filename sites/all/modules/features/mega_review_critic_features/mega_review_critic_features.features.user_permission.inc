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

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create itg_celebrity_profile content'.
  $permissions['create itg_celebrity_profile content'] = array(
    'name' => 'create itg_celebrity_profile content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mega_review_critic content'.
  $permissions['create mega_review_critic content'] = array(
    'name' => 'create mega_review_critic content',
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

  // Exported permission: 'delete any itg_celebrity_profile content'.
  $permissions['delete any itg_celebrity_profile content'] = array(
    'name' => 'delete any itg_celebrity_profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any mega_review_critic content'.
  $permissions['delete any mega_review_critic content'] = array(
    'name' => 'delete any mega_review_critic content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own itg_celebrity_profile content'.
  $permissions['delete own itg_celebrity_profile content'] = array(
    'name' => 'delete own itg_celebrity_profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own mega_review_critic content'.
  $permissions['delete own mega_review_critic content'] = array(
    'name' => 'delete own mega_review_critic content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any itg_celebrity_profile content'.
  $permissions['edit any itg_celebrity_profile content'] = array(
    'name' => 'edit any itg_celebrity_profile content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mega_review_critic content'.
  $permissions['edit any mega_review_critic content'] = array(
    'name' => 'edit any mega_review_critic content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own itg_celebrity_profile content'.
  $permissions['edit own itg_celebrity_profile content'] = array(
    'name' => 'edit own itg_celebrity_profile content',
    'roles' => array(),
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

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  return $permissions;
}
