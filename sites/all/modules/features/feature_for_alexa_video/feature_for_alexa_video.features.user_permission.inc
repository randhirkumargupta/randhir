<?php
/**
 * @file
 * feature_for_alexa_video.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_alexa_video_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create alexa_audio_clips content'.
  $permissions['create alexa_audio_clips content'] = array(
    'name' => 'create alexa_audio_clips content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
