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

  // Exported permission: 'create story content'.
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any story content'.
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own story content'.
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in byline'.
  $permissions['delete terms in byline'] = array(
    'name' => 'delete terms in byline',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in city'.
  $permissions['delete terms in city'] = array(
    'name' => 'delete terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any story content'.
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own story content'.
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in byline'.
  $permissions['edit terms in byline'] = array(
    'name' => 'edit terms in byline',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in city'.
  $permissions['edit terms in city'] = array(
    'name' => 'edit terms in city',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
