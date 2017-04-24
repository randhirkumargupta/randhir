<?php
/**
 * @file
 * feature_for_ugc.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_ugc_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access personalization all content link'.
  $permissions['access personalization all content link'] = array(
    'name' => 'access personalization all content link',
    'roles' => array(
      'Front User' => 'Front User',
    ),
    'module' => 'itg_personalization',
  );

  // Exported permission: 'access reject ugc content link'.
  $permissions['access reject ugc content link'] = array(
    'name' => 'access reject ugc content link',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'UGC Moderator' => 'UGC Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_ugc',
  );

  // Exported permission: 'access ugc list link'.
  $permissions['access ugc list link'] = array(
    'name' => 'access ugc list link',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'itg_ugc',
  );

  // Exported permission: 'create ugc content'.
  $permissions['create ugc content'] = array(
    'name' => 'create ugc content',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'Front User' => 'Front User',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ugc content'.
  $permissions['edit any ugc content'] = array(
    'name' => 'edit any ugc content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
