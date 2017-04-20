<?php
/**
 * @file
 * mail_templates.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mail_templates_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create mail_templates content'.
  $permissions['create mail_templates content'] = array(
    'name' => 'create mail_templates content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any mail_templates content'.
  $permissions['edit any mail_templates content'] = array(
    'name' => 'edit any mail_templates content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own mail_templates content'.
  $permissions['edit own mail_templates content'] = array(
    'name' => 'edit own mail_templates content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
