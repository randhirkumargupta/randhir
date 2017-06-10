<?php
/**
 * @file
 * itg_bitrates_video.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function itg_bitrates_video_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-itg_bitrates_video-field_resolution'.
  $field_instances['node-itg_bitrates_video-field_resolution'] = array(
    'bundle' => 'itg_bitrates_video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resolution',
    'label' => 'Resolution',
    'required' => FALSE,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 44,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Resolution');

  return $field_instances;
}
