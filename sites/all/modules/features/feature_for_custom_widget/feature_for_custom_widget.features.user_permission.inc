<?php
/**
 * @file
 * feature_for_custom_widget.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_for_custom_widget_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer itg custom widget'.
  $permissions['administer itg custom widget'] = array(
    'name' => 'administer itg custom widget',
    'roles' => array(
      'Copy Editor' => 'Copy Editor',
      'Editor' => 'Editor',
      'SEO' => 'SEO',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'itg_custom_widget',
  );

  // Exported permission: 'execute itg_custom_widget_categories_wise_node_group'.
  $permissions['execute itg_custom_widget_categories_wise_node_group'] = array(
    'name' => 'execute itg_custom_widget_categories_wise_node_group',
    'roles' => array(
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'actions_permissions',
  );

  return $permissions;
}
