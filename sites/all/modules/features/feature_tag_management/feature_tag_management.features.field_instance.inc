<?php
/**
 * @file
 * feature_tag_management.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_tag_management_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-tags-field_tags_display'.
  $field_instances['taxonomy_term-tags-field_tags_display'] = array(
    'bundle' => 'tags',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_tags_display',
    'label' => 'Feature Tags',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-tags-field_tags_status'.
  $field_instances['taxonomy_term-tags-field_tags_status'] = array(
    'bundle' => 'tags',
    'default_value' => array(
      0 => array(
        'value' => 'Published',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_tags_status',
    'label' => 'Tag Status',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature Tags');
  t('Tag Status');

  return $field_instances;
}
