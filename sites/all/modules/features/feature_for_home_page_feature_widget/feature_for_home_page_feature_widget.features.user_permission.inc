<?php
/**
 * @file
 * feature_for_home_page_feature_widget.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_home_page_feature_widget_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg_preview_log settings'.
  $permissions['administer itg_preview_log settings'] = array(
    'name' => 'administer itg_preview_log settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_workflow',
  );

  return $permissions;
}
