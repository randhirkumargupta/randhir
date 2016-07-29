<?php
/**
 * @file
 * features_for_itg_template_widgets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_itg_template_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create itg_template_widgets content'.
  $permissions['create itg_template_widgets content'] = array(
    'name' => 'create itg_template_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any itg_template_widgets content'.
  $permissions['delete any itg_template_widgets content'] = array(
    'name' => 'delete any itg_template_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own itg_template_widgets content'.
  $permissions['delete own itg_template_widgets content'] = array(
    'name' => 'delete own itg_template_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any itg_template_widgets content'.
  $permissions['edit any itg_template_widgets content'] = array(
    'name' => 'edit any itg_template_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own itg_template_widgets content'.
  $permissions['edit own itg_template_widgets content'] = array(
    'name' => 'edit own itg_template_widgets content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
