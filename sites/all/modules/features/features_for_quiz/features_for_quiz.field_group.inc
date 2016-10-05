<?php
/**
 * @file
 * features_for_quiz.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_quiz_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_add_ques|node|quiz|form';
  $field_group->group_name = 'group_quiz_add_ques';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add Quiz Questions',
    'weight' => '2',
    'children' => array(
      0 => 'field_quiz_add_questions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Add Quiz Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-add-questions',
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
  $field_groups['group_quiz_add_ques|node|quiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_basic_settings|node|quiz|form';
  $field_group->group_name = 'group_quiz_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_quiz_display_sequence',
      2 => 'field_quiz_immediate_result',
      3 => 'field_quiz_scoring_type',
      4 => 'field_quiz_type',
      5 => 'field_quiz_winners',
      6 => 'field_story_reporter',
      7 => 'field_survey_questions_format',
      8 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-basic-settings',
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
  $field_groups['group_quiz_basic_settings|node|quiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_date_settings|node|quiz|form';
  $field_group->group_name = 'group_quiz_date_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date Settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_survey_end_date',
      1 => 'field_survey_start_date',
      2 => 'field_survey_expity_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-date-settings',
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
  $field_groups['group_quiz_date_settings|node|quiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_metatags|node|quiz|form';
  $field_group->group_name = 'group_quiz_metatags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SEO Meta Tags',
    'weight' => '5',
    'children' => array(
      0 => 'metatags',
      1 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'SEO Meta Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-metatags',
        'classes' => 'group-quiz-metatags field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_quiz_metatags|node|quiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_publish_unpublish|node|quiz|form';
  $field_group->group_name = 'group_quiz_publish_unpublish';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publish/Unpublish',
    'weight' => '4',
    'children' => array(
      0 => 'field_quuiz_publish',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Publish/Unpublish',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-publish-unpublish',
        'classes' => 'group-quiz-publish-unpublish field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_quiz_publish_unpublish|node|quiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_section|node|quiz|form';
  $field_group->group_name = 'group_quiz_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'quiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '1',
    'children' => array(
      0 => 'field_survey_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'tab-quiz-section',
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
  $field_groups['group_quiz_section|node|quiz|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Quiz Questions');
  t('Basic Settings');
  t('Categorization');
  t('Date Settings');
  t('Publish/Unpublish');
  t('SEO Meta Tags');

  return $field_groups;
}
