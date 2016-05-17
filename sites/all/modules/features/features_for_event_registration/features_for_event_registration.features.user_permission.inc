<?php
/**
 * @file
 * features_for_event_registration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_event_registration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create event_registration content'.
  $permissions['create event_registration content'] = array(
    'name' => 'create event_registration content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event_registration content'.
  $permissions['delete any event_registration content'] = array(
    'name' => 'delete any event_registration content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own event_registration content'.
  $permissions['delete own event_registration content'] = array(
    'name' => 'delete own event_registration content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any event_registration content'.
  $permissions['edit any event_registration content'] = array(
    'name' => 'edit any event_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event_registration content'.
  $permissions['edit own event_registration content'] = array(
    'name' => 'edit own event_registration content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
