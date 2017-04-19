<?php
/**
 * @file
 * mail_templates.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mail_templates_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_password_changed|node|mail_templates|form';
  $field_group->group_name = 'group_password_changed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Password Changed',
    'weight' => '14',
    'children' => array(
      0 => 'field_mail_subject_password_chan',
      1 => 'field_mail_body_password_changed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-password-changed field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_password_changed|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_print_team|node|mail_templates|form';
  $field_group->group_name = 'group_print_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Print Team',
    'weight' => '12',
    'children' => array(
      0 => 'field_mail_subject_print_t',
      1 => 'field_mail_body_print_team',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-print-team field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_print_team|node|mail_templates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sign_up|node|mail_templates|form';
  $field_group->group_name = 'group_sign_up';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mail_templates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sign Up',
    'weight' => '13',
    'children' => array(
      0 => 'field_mail_subject_sign_up',
      1 => 'field_mail_body_sign_up',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sign-up field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sign_up|node|mail_templates|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Password Changed');
  t('Print Team');
  t('Sign Up');

  return $field_groups;
}
