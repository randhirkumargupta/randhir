<?php
/**
 * @file
 * features_supplement_magazine.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_supplement_magazine_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_issue_basic_settings|node|issue|form';
  $field_group->group_name = 'group_issue_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'issue';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_issue_magazine',
      1 => 'field_issue_supplement',
      2 => 'field_issue_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-issue-basic-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_issue_basic_settings|node|issue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_issue_img|node|issue|form';
  $field_group->group_name = 'group_issue_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'issue';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Issue Cover Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_issue_large_cover_image',
      1 => 'field_issue_small_cover_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-issue-img field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_issue_img|node|issue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_issue_supp_img|node|issue|form';
  $field_group->group_name = 'group_issue_supp_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'issue';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplement Cover Images',
    'weight' => '3',
    'children' => array(
      0 => 'field_issue_supp_large_image',
      1 => 'field_issue_supp_small_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-issue-supp-img field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_issue_supp_img|node|issue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_issue_upload_xml|node|issue|form';
  $field_group->group_name = 'group_issue_upload_xml';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'issue';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Import XML',
    'weight' => '1',
    'children' => array(
      0 => 'field_field_issue_import_xml',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-issue-upload-xml field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_issue_upload_xml|node|issue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_magazine_basic_settings|node|magazine|form';
  $field_group->group_name = 'group_magazine_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_print_magazine_issue_date',
      1 => 'field_magazine_publish',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-magazine-basic-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_magazine_basic_settings|node|magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_magazine_cover_photo|node|magazine|form';
  $field_group->group_name = 'group_magazine_cover_photo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'magazine';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Magazine Cover Photo',
    'weight' => '1',
    'children' => array(
      0 => 'field_magazine_cover_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Magazine Cover Photo',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-magazine-cover-photo field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_magazine_cover_photo|node|magazine|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_basic_settings|node|supplement|form';
  $field_group->group_name = 'group_supp_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'supplement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_supp_publish',
      1 => 'field_supp_select_magazine',
      2 => 'field_supp_issue',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-supp-basic-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_supp_basic_settings|node|supplement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_import_xml|node|supplement|form';
  $field_group->group_name = 'group_supp_import_xml';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'supplement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Import XML',
    'weight' => '1',
    'children' => array(
      0 => 'field_supp_import_xml',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-supp-import-xml field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_supp_import_xml|node|supplement|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Settings');
  t('Import XML');
  t('Issue Cover Images');
  t('Magazine Cover Photo');
  t('Supplement Cover Images');

  return $field_groups;
}
