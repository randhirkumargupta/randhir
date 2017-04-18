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

  // Translatables
  // Included for use with string extractors like potx.
  t('Print Team');

  return $field_groups;
}
