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
    'approved_rejected' => array(
      'name' => 'approved_rejected',
      'label' => 'Approved / Rejected',
      'description' => 'Approve & rejected permission assign to copy editor, section editor and editor',
      'weight' => -8,
    ),
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
    're_submitted' => array(
      'name' => 're_submitted',
      'label' => 'Re-Submitted',
      'description' => 'Updates Content and Re-Submits for Review for Author, Intern & Subeditor',
      'weight' => -6,
    ),
  );
  return $items;
}
