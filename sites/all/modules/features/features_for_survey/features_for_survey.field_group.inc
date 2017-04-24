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
      1 => 'field_story_reporter',
      2 => 'field_supp_publish',
      3 => 'field_survey_question_display',
      4 => 'field_survey_questions_format',
      5 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'basicdetails',
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
      1 => 'field_survey_expity_date',
      2 => 'field_survey_start_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'date-settings-wrapper',
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
  $field_groups['group_survey_date_settings|node|survey|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_metatags|node|survey|form';
  $field_group->group_name = 'group_survey_metatags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SEO Meta Tags',
    'weight' => '6',
    'children' => array(
      0 => 'field_pqs_add_token',
      1 => 'metatags',
      2 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'SEO Meta Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'metatags-wrapper',
        'classes' => 'group-survey-metatags field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_survey_metatags|node|survey|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_question|node|survey|form';
  $field_group->group_name = 'group_survey_question';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add Questions',
    'weight' => '1',
    'children' => array(
      0 => 'field_survey_add_questions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Add Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'survey-add-questions-wrapper',
        'classes' => 'group-survey-question field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_survey_question|node|survey|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_survey_related_content|node|survey|form';
  $field_group->group_name = 'group_survey_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'survey';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Content',
    'weight' => '5',
    'children' => array(
      0 => 'field_common_related_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'survey-related-content',
        'classes' => 'group-survey-related-content field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_survey_related_content|node|survey|form'] = $field_group;

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
    'label' => 'Categorization',
    'weight' => '3',
    'children' => array(
      0 => 'field_survey_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'category-wrapper',
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
  $field_groups['group_survey_section|node|survey|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Questions');
  t('Basic Settings');
  t('Categorization');
  t('Date Settings');
  t('Related Content');
  t('SEO Meta Tags');

  return $field_groups;
}
