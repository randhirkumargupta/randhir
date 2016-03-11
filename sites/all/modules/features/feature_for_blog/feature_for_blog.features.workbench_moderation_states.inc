<?php
/**
 * @file
 * feature_for_blog.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function feature_for_blog_workbench_moderation_export_states() {
  $items = array(
    'archive' => array(
      'name' => 'archive',
      'label' => 'Archive',
      'description' => ' For soft delete content',
      'weight' => 0,
    ),
    'rejected' => array(
      'name' => 'rejected',
      'label' => 'Rejected',
      'description' => 'Rejected for copy editor, section editor and editor',
      'weight' => -8,
    ),
    'un_published' => array(
      'name' => 'un_published',
      'label' => 'Un published',
      'description' => 'For un publish content',
      'weight' => 0,
    ),
  );
  return $items;
}
