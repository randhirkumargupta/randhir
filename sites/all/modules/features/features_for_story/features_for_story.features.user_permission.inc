<?php
/**
 * @file
 * features_for_story.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_story_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access itg story'.
  $permissions['access itg story'] = array(
    'name' => 'access itg story',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'itg_story',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'SEO' => 'SEO',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create reporter content'.
  $permissions['create reporter content'] = array(
    'name' => 'create reporter content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create story content'.
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'UGC Moderator' => 'UGC Moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any reporter content'.
  $permissions['delete any reporter content'] = array(
    'name' => 'delete any reporter content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any story content'.
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own reporter content'.
  $permissions['delete own reporter content'] = array(
    'name' => 'delete own reporter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own story content'.
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in city'.
  $permissions['delete terms in city'] = array(
    'name' => 'delete terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in reasons_for_reject'.
  $permissions['delete terms in reasons_for_reject'] = array(
    'name' => 'delete terms in reasons_for_reject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any reporter content'.
  $permissions['edit any reporter content'] = array(
    'name' => 'edit any reporter content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any story content'.
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own reporter content'.
  $permissions['edit own reporter content'] = array(
    'name' => 'edit own reporter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own story content'.
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
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

  // Exported permission: 'edit terms in city'.
  $permissions['edit terms in city'] = array(
    'name' => 'edit terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in reasons_for_reject'.
  $permissions['edit terms in reasons_for_reject'] = array(
    'name' => 'edit terms in reasons_for_reject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
