<?php
/**
 * @file
 * syndication_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function syndication_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_syndication_delivery_mode'.
  $field_bases['field_syndication_delivery_mode'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_syndication_delivery_mode',
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
        'xml' => 'XMLs',
        'rss' => 'RSS',
        'mrss' => 'MRSS',
        'ussd' => 'USSD',
        'sms' => 'SMS',
        'stf' => 'SIMPLE TEXT FEED',
        'html' => 'HTML',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
