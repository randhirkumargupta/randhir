<?php
/**
 * @file
 * feature_category_management.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_category_management_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cm_hide_cat_from_home'.
  $field_bases['field_cm_hide_cat_from_home'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_hide_cat_from_home',
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
        1 => 'Hide category from home page navigation.',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_cm_hide_cat_from_search'.
  $field_bases['field_cm_hide_cat_from_search'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_hide_cat_from_search',
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
        1 => ' Hide Category from search engine',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_cm_no_follow'.
  $field_bases['field_cm_no_follow'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_no_follow',
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
        1 => 'No Follow',
        2 => 'No Index',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_cm_redirection_url'.
  $field_bases['field_cm_redirection_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_redirection_url',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_cm_select_template'.
  $field_bases['field_cm_select_template'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_select_template',
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
      'allowed_values' => array(),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_cm_select_template_type'.
  $field_bases['field_cm_select_template_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_select_template_type',
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
        'section' => 'section',
        'special' => 'special',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_cm_sponsored_category'.
  $field_bases['field_cm_sponsored_category'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cm_sponsored_category',
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
        1 => 'Sponsored Category',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_description'.
  $field_bases['field_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
