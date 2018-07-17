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

  // Exported role: Ads Manager.
  $roles['Ads Manager'] = array(
    'name' => 'Ads Manager',
    'weight' => 24,
  );

  // Exported role: Author/Guest.
  $roles['Author/Guest'] = array(
    'name' => 'Author/Guest',
    'weight' => 3,
  );

  // Exported role: Co-ordinator.
  $roles['Co-ordinator'] = array(
    'name' => 'Co-ordinator',
    'weight' => 12,
  );

  // Exported role: Copy Desk.
  $roles['Copy Desk'] = array(
    'name' => 'Copy Desk',
    'weight' => 16,
  );

  // Exported role: Copy Editor.
  $roles['Copy Editor'] = array(
    'name' => 'Copy Editor',
    'weight' => 6,
  );

  // Exported role: Correspondent.
  $roles['Correspondent'] = array(
    'name' => 'Correspondent',
    'weight' => 11,
  );

  // Exported role: Design Head.
  $roles['Design Head'] = array(
    'name' => 'Design Head',
    'weight' => 15,
  );

  // Exported role: Designer.
  $roles['Designer'] = array(
    'name' => 'Designer',
    'weight' => 18,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 8,
  );

  // Exported role: Expert.
  $roles['Expert'] = array(
    'name' => 'Expert',
    'weight' => 9,
  );

  // Exported role: Intern.
  $roles['Intern'] = array(
    'name' => 'Intern',
    'weight' => 4,
  );

  // Exported role: Mobile VAS.
  $roles['Mobile VAS'] = array(
    'name' => 'Mobile VAS',
    'weight' => 26,
  );

  // Exported role: Photo Coordinator.
  $roles['Photo Coordinator'] = array(
    'name' => 'Photo Coordinator',
    'weight' => 13,
  );

  // Exported role: Photo Head.
  $roles['Photo Head'] = array(
    'name' => 'Photo Head',
    'weight' => 14,
  );

  // Exported role: Photographer.
  $roles['Photographer'] = array(
    'name' => 'Photographer',
    'weight' => 19,
  );

  // Exported role: Section Editor/Anchor.
  $roles['Section Editor/Anchor'] = array(
    'name' => 'Section Editor/Anchor',
    'weight' => 7,
  );

  // Exported role: Site Admin.
  $roles['Site Admin'] = array(
    'name' => 'Site Admin',
    'weight' => 10,
  );

  // Exported role: Subeditor/Sr.Sub.
  $roles['Subeditor/Sr.Sub'] = array(
    'name' => 'Subeditor/Sr.Sub',
    'weight' => 5,
  );

  // Exported role: Syndication.
  $roles['Syndication'] = array(
    'name' => 'Syndication',
    'weight' => 25,
  );

  // Exported role: UGC Moderator.
  $roles['UGC Moderator'] = array(
    'name' => 'UGC Moderator',
    'weight' => 21,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
