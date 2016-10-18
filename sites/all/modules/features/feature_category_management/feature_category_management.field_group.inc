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
    'label' => 'Basic Detail',
    'weight' => '-1',
    'children' => array(
      0 => 'field_cm_display_title',
      1 => 'field_cm_redirection_url',
      2 => 'field_sponser_logo',
      3 => 'field_user_city',
      4 => 'name',
      5 => 'description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Detail',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'category-manager-basic-details',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

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
    'weight' => '23',
    'children' => array(
      0 => 'field_cm_select_type',
      1 => 'field_cm_select_template',
      2 => 'field_cm_select_template_type',
      3 => 'field_set_as_featured_cate',
      4 => 'field_cm_category_color',
      5 => 'field_cm_category_banner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Selection Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'category-manager-selection-details',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Detail');
  t('Selection Details');

  return $field_groups;
}
