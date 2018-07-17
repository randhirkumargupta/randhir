<?php
/**
 * @file
 * custom_html_widgets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_html_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create custom_html_widgets content'.
  $permissions['create custom_html_widgets content'] = array(
    'name' => 'create custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any custom_html_widgets content'.
  $permissions['delete any custom_html_widgets content'] = array(
    'name' => 'delete any custom_html_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own custom_html_widgets content'.
  $permissions['delete own custom_html_widgets content'] = array(
    'name' => 'delete own custom_html_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any custom_html_widgets content'.
  $permissions['edit any custom_html_widgets content'] = array(
    'name' => 'edit any custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own custom_html_widgets content'.
  $permissions['edit own custom_html_widgets content'] = array(
    'name' => 'edit own custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
