<?php
/**
 * @file
 * feature_for_live_tv_integration.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_for_live_tv_integration_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_live_tv_device'.
  $field_bases['field_live_tv_device'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_live_tv_device',
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
        'Web' => 'Web',
        'Web Mobile' => 'Web Mobile',
        'iOS' => 'iOS',
        'Android' => 'Android',
        'Window' => 'Window',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
