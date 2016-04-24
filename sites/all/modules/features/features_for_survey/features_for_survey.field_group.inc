<?php
/**
 * @file
 * features_for_survey.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_survey_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_basic_settings|node|survey|form';
  $field_group->group_name = 'group_survey_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_survey_question_display',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'BasicDetails',
        'classes' => 'group-survey-basic-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_survey_basic_settings|node|survey|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_date_settings|node|survey|form';
  $field_group->group_name = 'group_survey_date_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_survey_end_date',
      1 => 'field_survey_start_date',
      2 => 'field_survey_expity_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Date Settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'DateSettings',
        'classes' => 'group-survey-date-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_survey_date_settings|node|survey|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_section|node|survey|form';
  $field_group->group_name = 'group_survey_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section',
    'weight' => '3',
    'children' => array(
      0 => 'field_survey_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Section',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'category',
        'classes' => 'group-survey-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_survey_section|node|survey|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Settings');
  t('Date Settings');
  t('Section');

  return $field_groups;
}
