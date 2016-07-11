<?php
/**
 * @file
 * feature_for_top_story_widget.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_top_story_widget_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'execute nodequeue_add_action'.
  $permissions['execute nodequeue_add_action'] = array(
    'name' => 'execute nodequeue_add_action',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute nodequeue_remove_action'.
  $permissions['execute nodequeue_remove_action'] = array(
    'name' => 'execute nodequeue_remove_action',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  return $permissions;
}
