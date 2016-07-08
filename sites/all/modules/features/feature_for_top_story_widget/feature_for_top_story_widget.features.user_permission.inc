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
