<?php
/**
 * @file
 * feature_for_blog.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function feature_for_blog_workbench_moderation_export_transitions() {
  $items = array(
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Published',
    ),
    'needs_modification:needs_review' => array(
      'from_name' => 'needs_modification',
      'to_name' => 'needs_review',
      'name' => 'Re-Submitted',
    ),
    'needs_review:needs_modification' => array(
      'from_name' => 'needs_review',
      'to_name' => 'needs_modification',
      'name' => 'Needs Modification',
    ),
    'needs_review:rejected' => array(
      'from_name' => 'needs_review',
      'to_name' => 'rejected',
      'name' => 'Rejected',
    ),
    'published:archive' => array(
      'from_name' => 'published',
      'to_name' => 'archive',
      'name' => 'Archived',
    ),
    'published:un_published' => array(
      'from_name' => 'published',
      'to_name' => 'un_published',
      'name' => 'Un published',
    ),
    'un_published:published' => array(
      'from_name' => 'un_published',
      'to_name' => 'published',
      'name' => 'Published',
    ),
  );
  return $items;
}
