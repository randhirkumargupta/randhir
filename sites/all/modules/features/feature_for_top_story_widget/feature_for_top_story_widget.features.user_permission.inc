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

  // Exported permission: 'administer itg analytics widget'.
  $permissions['administer itg analytics widget'] = array(
    'name' => 'administer itg analytics widget',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'itg_analytics',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  return $permissions;
}
