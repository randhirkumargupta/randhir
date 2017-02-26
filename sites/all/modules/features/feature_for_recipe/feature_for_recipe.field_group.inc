<?php
/**
 * @file
 * feature_for_recipe.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_for_recipe_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recipe_details|node|recipe|form';
  $field_group->group_name = 'group_recipe_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recipe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recipe Details',
    'weight' => '11',
    'children' => array(
      0 => 'field_recipe_description',
      1 => 'field_recipe_cuisine_type',
      2 => 'field_recipe_meal_for',
      3 => 'field_recipe_calorie_type',
      4 => 'field_recipe_calorie_count',
      5 => 'field_recipe_time',
      6 => 'field_recipe_ailment',
      7 => 'field_recipe_meal_type',
      8 => 'field_recipe_festivals',
      9 => 'field_recipe_ingredients',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-recipe-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_recipe_details|node|recipe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recipe_syndication|node|recipe|form';
  $field_group->group_name = 'group_recipe_syndication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recipe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Syndication',
    'weight' => '13',
    'children' => array(
      0 => 'field_recipe_syndication',
      1 => 'field_recipe_client_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-recipe-syndication field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_recipe_syndication|node|recipe|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Recipe Details');
  t('Syndication');

  return $field_groups;
}
