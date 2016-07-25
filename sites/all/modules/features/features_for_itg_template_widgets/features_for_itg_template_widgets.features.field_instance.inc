<?php
/**
 * @file
 * features_for_itg_template_widgets.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function features_for_itg_template_widgets_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-itg_template_widgets-field_itg_widget_name'.
  $field_instances['node-itg_template_widgets-field_itg_widget_name'] = array(
    'bundle' => 'itg_template_widgets',
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
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_itg_widget_name',
    'label' => 'Widget name',
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
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Widget name');

  return $field_instances;
}
