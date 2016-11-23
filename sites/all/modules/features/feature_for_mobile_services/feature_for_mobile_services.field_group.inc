<?php
/**
 * @file
 * feature_for_mobile_services.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_for_mobile_services_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_associate_client|node|service_creation|form';
  $field_group->group_name = 'group_associate_client';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service_creation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associate Client & Services',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-associate-client field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_associate_client|node|service_creation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business_contact|node|clients_creation|form';
  $field_group->group_name = 'group_business_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'clients_creation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Business Contact',
    'weight' => '3',
    'children' => array(
      0 => 'field_contact_person_name',
      1 => 'field_mobile_number',
      2 => 'field_contact_business_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Business Contact',
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
  $field_groups['group_business_contact|node|clients_creation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_ftp|node|clients_creation|form';
  $field_group->group_name = 'group_service_ftp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'clients_creation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FTP',
    'weight' => '9',
    'children' => array(
      0 => 'field_ftp_ip_address',
      1 => 'field_ftp_password',
      2 => 'field_ftp_username',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'FTP',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'itg-group-service-ftp',
        'classes' => 'group-service-ftp field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_service_ftp|node|clients_creation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_ftp|node|service_creation|form';
  $field_group->group_name = 'group_service_ftp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service_creation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FTP',
    'weight' => '12',
    'children' => array(
      0 => 'field_ftp_ip_address',
      1 => 'field_ftp_username',
      2 => 'field_ftp_password',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_service_ftp|node|service_creation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_contact|node|clients_creation|form';
  $field_group->group_name = 'group_technical_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'clients_creation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical Contact',
    'weight' => '4',
    'children' => array(
      0 => 'field_contact_tech_email_address',
      1 => 'field_contact_tech_mobile_number',
      2 => 'field_contact_tech_person_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Technical Contact',
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
  $field_groups['group_technical_contact|node|clients_creation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associate Client & Services');
  t('Business Contact');
  t('FTP');
  t('Technical Contact');

  return $field_groups;
}
