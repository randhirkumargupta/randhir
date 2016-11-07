<?php
/**
 * @file
 * user_management.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function user_management_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basic_details|user|user|form';
  $field_group->group_name = 'group_user_basic_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_mobile_number',
      3 => 'field_user_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_basic_details|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Details');

  return $field_groups;
}
