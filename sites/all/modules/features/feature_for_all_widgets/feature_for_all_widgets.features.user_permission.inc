<?php
/**
 * @file
 * feature_for_all_widgets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_all_widgets_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'execute itg_widget_categories_wise_node_group'.
  $permissions['execute itg_widget_categories_wise_node_group'] = array(
    'name' => 'execute itg_widget_categories_wise_node_group',
    'roles' => array(
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  return $permissions;
}
