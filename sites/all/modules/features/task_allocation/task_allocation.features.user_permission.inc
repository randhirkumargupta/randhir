<?php
/**
 * @file
 * task_allocation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function task_allocation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create task_idea_allocation_tracking content'.
  $permissions['create task_idea_allocation_tracking content'] = array(
    'name' => 'create task_idea_allocation_tracking content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Co-ordinator' => 'Co-ordinator',
      'Copy Desk' => 'Copy Desk',
      'Copy Editor' => 'Copy Editor',
      'Correspondent' => 'Correspondent',
      'Design Head' => 'Design Head',
      'Designer' => 'Designer',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Photo Coordinator' => 'Photo Coordinator',
      'Photo Head' => 'Photo Head',
      'Photographer' => 'Photographer',
      'SEO' => 'SEO',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any task_idea_allocation_tracking content'.
  $permissions['delete any task_idea_allocation_tracking content'] = array(
    'name' => 'delete any task_idea_allocation_tracking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own task_idea_allocation_tracking content'.
  $permissions['delete own task_idea_allocation_tracking content'] = array(
    'name' => 'delete own task_idea_allocation_tracking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any task_idea_allocation_tracking content'.
  $permissions['edit any task_idea_allocation_tracking content'] = array(
    'name' => 'edit any task_idea_allocation_tracking content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own task_idea_allocation_tracking content'.
  $permissions['edit own task_idea_allocation_tracking content'] = array(
    'name' => 'edit own task_idea_allocation_tracking content',
    'roles' => array(
      'Author/Guest' => 'Author/Guest',
      'Co-ordinator' => 'Co-ordinator',
      'Copy Desk' => 'Copy Desk',
      'Copy Editor' => 'Copy Editor',
      'Correspondent' => 'Correspondent',
      'Design Head' => 'Design Head',
      'Designer' => 'Designer',
      'Editor' => 'Editor',
      'Intern' => 'Intern',
      'Photo Coordinator' => 'Photo Coordinator',
      'Photo Head' => 'Photo Head',
      'Photographer' => 'Photographer',
      'SEO' => 'SEO',
      'Section Editor/Anchor' => 'Section Editor/Anchor',
      'Site Admin' => 'Site Admin',
      'Subeditor/Sr.Sub' => 'Subeditor/Sr.Sub',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
