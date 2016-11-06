<?php
/**
 * @file
 * features_for_event_configuration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_event_configuration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create event_configurations content'.
  $permissions['create event_configurations content'] = array(
    'name' => 'create event_configurations content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event_configurations content'.
  $permissions['edit any event_configurations content'] = array(
    'name' => 'edit any event_configurations content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event_configurations content'.
  $permissions['edit own event_configurations content'] = array(
    'name' => 'edit own event_configurations content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
