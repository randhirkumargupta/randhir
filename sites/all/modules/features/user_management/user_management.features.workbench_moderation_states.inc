<?php
/**
 * @file
 * user_management.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function user_management_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -10,
    ),
    'needs_modification' => array(
      'name' => 'needs_modification',
      'label' => 'Needs Modification',
      'description' => 'Mark as Needs Modification assign to copy editor, section editor and editor',
      'weight' => -7,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Submitted for Review',
      'description' => 'Ready for moderation',
      'weight' => -9,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => -5,
    ),
  );
  return $items;
}
