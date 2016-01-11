<?php
/**
 * @file
 * user_management.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_management_user_default_roles() {
  $roles = array();

  // Exported role: Author/Guest.
  $roles['Author/Guest'] = array(
    'name' => 'Author/Guest',
    'weight' => 3,
  );

  // Exported role: Copy Editor.
  $roles['Copy Editor'] = array(
    'name' => 'Copy Editor',
    'weight' => 6,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 8,
  );

  // Exported role: Intern.
  $roles['Intern'] = array(
    'name' => 'Intern',
    'weight' => 4,
  );

  // Exported role: Section Editor.
  $roles['Section Editor'] = array(
    'name' => 'Section Editor',
    'weight' => 7,
  );

  // Exported role: Subeditor/Sr.Sub.
  $roles['Subeditor/Sr.Sub'] = array(
    'name' => 'Subeditor/Sr.Sub',
    'weight' => 5,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
