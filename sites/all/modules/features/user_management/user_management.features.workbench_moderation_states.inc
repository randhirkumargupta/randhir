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
      'label' => 'Approved/Rejected',
      'description' => '',
      'weight' => 0,
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
      'description' => '',
      'weight' => 0,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Ready for moderation',
      'weight' => 0,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => -10,
    ),
    're_submitted' => array(
      'name' => 're_submitted',
      'label' => 'Re-Submitted',
      'description' => '',
      'weight' => 0,
    ),
  );
  return $items;
}
