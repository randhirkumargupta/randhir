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

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'administrator' => 'administrator',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'create print_team_integration content'.
  $permissions['create print_team_integration content'] = array(
    'name' => 'create print_team_integration content',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Knowledge Centre' => 'Knowledge Centre',
      'Photographer' => 'Photographer',
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
      'Copy Desk' => 'Copy Desk',
      'Design Head' => 'Design Head',
      'Designer' => 'Designer',
      'Editor' => 'Editor',
      'Knowledge Centre' => 'Knowledge Centre',
      'Photo Coordinator' => 'Photo Coordinator',
      'Photo Head' => 'Photo Head',
      'Photographer' => 'Photographer',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own print_team_integration content'.
  $permissions['edit own print_team_integration content'] = array(
    'name' => 'edit own print_team_integration content',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Copy Desk' => 'Copy Desk',
      'Correspondent' => 'Correspondent',
      'Design Head' => 'Design Head',
      'Designer' => 'Designer',
      'Editor' => 'Editor',
      'Knowledge Centre' => 'Knowledge Centre',
      'Photo Coordinator' => 'Photo Coordinator',
      'Photo Head' => 'Photo Head',
      'Photographer' => 'Photographer',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Copy Desk' => 'Copy Desk',
      'Copy Editor' => 'Copy Editor',
      'Design Head' => 'Design Head',
      'Designer' => 'Designer',
      'Editor' => 'Editor',
      'Photo Coordinator' => 'Photo Coordinator',
      'Photo Head' => 'Photo Head',
      'Photographer' => 'Photographer',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print_ui',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'submit idea for story'.
  $permissions['submit idea for story'] = array(
    'name' => 'submit idea for story',
    'roles' => array(
      'Co-ordinator' => 'Co-ordinator',
      'Correspondent' => 'Correspondent',
      'Editor' => 'Editor',
      'Knowledge Centre' => 'Knowledge Centre',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'itg_print_team',
  );

  return $permissions;
}
