<?php
/**
 * @file
 * feature_for_video.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_video_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create videogallery content'.
  $permissions['create videogallery content'] = array(
    'name' => 'create videogallery content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any videogallery content'.
  $permissions['delete any videogallery content'] = array(
    'name' => 'delete any videogallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own videogallery content'.
  $permissions['delete own videogallery content'] = array(
    'name' => 'delete own videogallery content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any videogallery content'.
  $permissions['edit any videogallery content'] = array(
    'name' => 'edit any videogallery content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own videogallery content'.
  $permissions['edit own videogallery content'] = array(
    'name' => 'edit own videogallery content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
