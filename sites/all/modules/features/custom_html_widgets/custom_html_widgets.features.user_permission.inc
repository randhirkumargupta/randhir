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
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any custom_html_widgets content'.
  $permissions['delete any custom_html_widgets content'] = array(
    'name' => 'delete any custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own custom_html_widgets content'.
  $permissions['delete own custom_html_widgets content'] = array(
    'name' => 'delete own custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any custom_html_widgets content'.
  $permissions['edit any custom_html_widgets content'] = array(
    'name' => 'edit any custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own custom_html_widgets content'.
  $permissions['edit own custom_html_widgets content'] = array(
    'name' => 'edit own custom_html_widgets content',
    'roles' => array(
      'Editor' => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
