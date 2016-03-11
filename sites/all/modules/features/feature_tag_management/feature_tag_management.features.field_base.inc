<?php
/**
 * @file
 * feature_tag_management.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_tag_management_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tags_display'.
  $field_bases['field_tags_display'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tags_display',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Yes',
        0 => 'No',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
