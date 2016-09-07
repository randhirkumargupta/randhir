<?php
/**
 * @file
 * feature_category_management.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_category_management_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cm_basic_details|taxonomy_term|category_management|form';
  $field_group->group_name = 'group_cm_basic_details';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category_management';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_cm_display_title',
      1 => 'field_cm_redirection_url',
      2 => 'field_sponser_logo',
      3 => 'field_user_city',
      4 => 'field_description',
      5 => 'name',
      6 => 'description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
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
  $field_groups['group_cm_basic_details|taxonomy_term|category_management|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cm_selection_details|taxonomy_term|category_management|form';
  $field_group->group_name = 'group_cm_selection_details';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category_management';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selection Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_cm_select_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Selection Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
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
  $field_groups['group_cm_selection_details|taxonomy_term|category_management|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cm_settings|taxonomy_term|category_management|form';
  $field_group->group_name = 'group_cm_settings';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category_management';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_cm_hide_cat_from_home',
      1 => 'field_cm_hide_cat_from_search',
      2 => 'field_cm_no_follow',
      3 => 'field_cm_sponsored_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
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
  $field_groups['group_cm_settings|taxonomy_term|category_management|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Details');
  t('Selection Details');
  t('Settings');

  return $field_groups;
}
