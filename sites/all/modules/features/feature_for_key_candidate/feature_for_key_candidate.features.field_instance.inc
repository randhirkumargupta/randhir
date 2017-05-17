<?php
/**
 * @file
 * feature_for_key_candidate.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_for_key_candidate_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-state_managment-field_section'.
  $field_instances['taxonomy_term-state_managment-field_section'] = array(
    'bundle' => 'state_managment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_section',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 45,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-state_managment-field_state_map_color_json'.
  $field_instances['taxonomy_term-state_managment-field_state_map_color_json'] = array(
    'bundle' => 'state_managment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_state_map_color_json',
    'label' => 'State Map Color JSON',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 43,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-state_managment-field_state_map_json'.
  $field_instances['taxonomy_term-state_managment-field_state_map_json'] = array(
    'bundle' => 'state_managment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_state_map_json',
    'label' => 'State Map JSON',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-state_managment-field_state_svg_json'.
  $field_instances['taxonomy_term-state_managment-field_state_svg_json'] = array(
    'bundle' => 'state_managment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_state_svg_json',
    'label' => 'State SVG JSON',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');
  t('State Map Color JSON');
  t('State Map JSON');
  t('State SVG JSON');

  return $field_instances;
}
