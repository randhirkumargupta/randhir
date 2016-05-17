<?php
/**
 * @file
 * features_for_newsletter.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_newsletter_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newsl_basic_settings|node|newsletter|form';
  $field_group->group_name = 'group_newsl_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'newsletter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_newsl_header_headline',
      1 => 'field_newsl_main_headline',
      2 => 'field_newsl_website_name',
      3 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'itg-group-field',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_newsl_basic_settings|node|newsletter|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Settings');

  return $field_groups;
}
