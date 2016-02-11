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
  $field_group->identifier = 'group_reset_password|user|user|form';
  $field_group->group_name = 'group_reset_password';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Details',
    'weight' => '4',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-account-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_reset_password|user|user|form'] = $field_group;

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
      4 => 'picture',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-user-basic-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_basic_details|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Account Details');
  t('Basic Details');

  return $field_groups;
}
