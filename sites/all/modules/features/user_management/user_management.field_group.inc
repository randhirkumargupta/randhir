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
  $field_group->identifier = 'group_configuration|user|user|form';
  $field_group->group_name = 'group_configuration';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'configuration',
    'weight' => '1',
    'children' => array(
      0 => 'field_mark_as_expert',
      1 => 'field_user_section',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'configuration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'user-configurations',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reset_password|user|user|form';
  $field_group->group_name = 'group_reset_password';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_notify_user_of_update_acco',
      1 => 'field_story_expiry_date',
      2 => 'field_subscribe_for_newsletter',
      3 => 'account',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Account Details',
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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Account Details');
  t('Basic Details');
  t('configuration');

  return $field_groups;
}
