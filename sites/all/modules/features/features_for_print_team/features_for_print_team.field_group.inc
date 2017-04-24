<?php
/**
 * @file
 * features_for_print_team.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_print_team_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pti_basic_info|node|print_team_integration|form';
  $field_group->group_name = 'group_pti_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'print_team_integration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_pti_magazine_kicker',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'pti-basic-info',
        'classes' => 'group-pti-basic-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pti_basic_info|node|print_team_integration|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pti_categorization|node|print_team_integration|form';
  $field_group->group_name = 'group_pti_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'print_team_integration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '1',
    'children' => array(
      0 => 'field_story_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'pti-categorization',
        'classes' => 'group-pti-categorization field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pti_categorization|node|print_team_integration|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pti_images|node|print_team_integration|form';
  $field_group->group_name = 'group_pti_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'print_team_integration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Section',
    'weight' => '2',
    'children' => array(
      0 => 'field_pti_print_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'pti-image',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pti_images|node|print_team_integration|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pti_settings|node|print_team_integration|form';
  $field_group->group_name = 'group_pti_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'print_team_integration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_pti_idea_status',
      1 => 'field_pti_words_limit',
      2 => 'field_survey_end_date',
      3 => 'field_pti_mark_as_complete',
      4 => 'field_story_rating',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'pti-settings',
        'classes' => 'group-pti-settings field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pti_settings|node|print_team_integration|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');
  t('Categorization');
  t('Image Section');
  t('Settings');

  return $field_groups;
}
