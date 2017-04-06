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

  // Exported permission: 'authorized user dailymotion credin'.
  $permissions['authorized user dailymotion credin'] = array(
    'name' => 'authorized user dailymotion credin',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_videogallery',
  );

  // Exported permission: 'authorized user ftp credin'.
  $permissions['authorized user ftp credin'] = array(
    'name' => 'authorized user ftp credin',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_videogallery',
  );

  // Exported permission: 'create videogallery content'.
  $permissions['create videogallery content'] = array(
    'name' => 'create videogallery content',
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

  // Exported permission: 'delete any videogallery content'.
  $permissions['delete any videogallery content'] = array(
    'name' => 'delete any videogallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own videogallery content'.
  $permissions['delete own videogallery content'] = array(
    'name' => 'delete own videogallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any videogallery content'.
  $permissions['edit any videogallery content'] = array(
    'name' => 'edit any videogallery content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own videogallery content'.
  $permissions['edit own videogallery content'] = array(
    'name' => 'edit own videogallery content',
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
