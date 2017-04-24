<?php
/**
 * @file
 * feature_for_ugc_comments.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_ugc_comments_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Front User' => 'Front User',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access edit ugc comment'.
  $permissions['access edit ugc comment'] = array(
    'name' => 'access edit ugc comment',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'UGC Moderator' => 'UGC Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_comments_ugc',
  );

  // Exported permission: 'access global comment configuration'.
  $permissions['access global comment configuration'] = array(
    'name' => 'access global comment configuration',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_comments_ugc',
  );

  // Exported permission: 'access ugc comment approve link'.
  $permissions['access ugc comment approve link'] = array(
    'name' => 'access ugc comment approve link',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'UGC Moderator' => 'UGC Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_comments_ugc',
  );

  // Exported permission: 'access ugc comment view'.
  $permissions['access ugc comment view'] = array(
    'name' => 'access ugc comment view',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'UGC Moderator' => 'UGC Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_comments_ugc',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Front User' => 'Front User',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
