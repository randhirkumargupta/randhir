<?php
/**
 * @file
 * features_for_newsletter.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_newsletter_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newsl_add_news|node|newsletter|form';
  $field_group->group_name = 'group_newsl_add_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'newsletter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add News',
    'weight' => '1',
    'children' => array(
      0 => 'field_newsl_add_news',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Add News',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'newsletter-add-news',
        'classes' => 'group-newsl-add-news field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_newsl_add_news|node|newsletter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newsl_basic_settings|node|newsletter|form';
  $field_group->group_name = 'group_newsl_basic_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'newsletter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_newsl_website_name',
      1 => 'field_newsl_date',
      2 => 'field_newsl_day',
      3 => 'field_newsl_frequency',
      4 => 'field_newsl_newsletter_content',
      5 => 'field_newsl_newsletter_type',
      6 => 'field_newsl_schedule',
      7 => 'field_newsl_select_template',
      8 => 'field_newsl_time',
      9 => 'field_survey_start_date',
      10 => 'field_story_category',
      11 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'newsletter-basic-details',
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
  $field_groups['group_newsl_basic_settings|node|newsletter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quiz_metatags|node|newsletter|form';
  $field_group->group_name = 'group_quiz_metatags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'newsletter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Tags',
    'weight' => '3',
    'children' => array(
      0 => 'metatags',
      1 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meta Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'newsletter-metatags',
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
  $field_groups['group_quiz_metatags|node|newsletter|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add News');
  t('Basic Settings');
  t('Meta Tags');

  return $field_groups;
}
