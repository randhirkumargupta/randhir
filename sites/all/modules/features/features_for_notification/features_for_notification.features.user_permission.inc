<?php
/**
 * @file
 * features_for_notification.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_notification_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create notification content'.
  $permissions['create notification content'] = array(
    'name' => 'create notification content',
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

  // Exported permission: 'edit any notification content'.
  $permissions['edit any notification content'] = array(
    'name' => 'edit any notification content',
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

  // Exported permission: 'edit own notification content'.
  $permissions['edit own notification content'] = array(
    'name' => 'edit own notification content',
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
