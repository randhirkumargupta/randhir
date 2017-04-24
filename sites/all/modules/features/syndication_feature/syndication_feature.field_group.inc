<?php
/**
 * @file
 * syndication_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function syndication_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_syndication_ftp|node|syndication_client|form';
  $field_group->group_name = 'group_syndication_ftp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'syndication_client';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FTP',
    'weight' => '8',
    'children' => array(
      0 => 'field_ftp_ip_address',
      1 => 'field_ftp_username',
      2 => 'field_ftp_password',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-syndication-ftp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_syndication_ftp|node|syndication_client|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('FTP');

  return $field_groups;
}
