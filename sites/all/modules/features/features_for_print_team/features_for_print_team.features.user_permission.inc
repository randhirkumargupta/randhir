<?php
/**
 * @file
 * features_for_print_team.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_for_print_team_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create print_team_integration content'.
  $permissions['create print_team_integration content'] = array(
    'name' => 'create print_team_integration content',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any print_team_integration content'.
  $permissions['edit any print_team_integration content'] = array(
    'name' => 'edit any print_team_integration content',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own print_team_integration content'.
  $permissions['edit own print_team_integration content'] = array(
    'name' => 'edit own print_team_integration content',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'submit idea for story'.
  $permissions['submit idea for story'] = array(
    'name' => 'submit idea for story',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_print_team',
  );

  return $permissions;
}
