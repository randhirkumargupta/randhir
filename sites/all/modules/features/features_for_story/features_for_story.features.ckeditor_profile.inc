<?php
/**
 * @file
 * features_for_story.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function features_for_story_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '//cdn.ckeditor.com/4.5.4/full-all',
      ),
      'input_formats' => array(),
    ),
  );
  return $data;
}
