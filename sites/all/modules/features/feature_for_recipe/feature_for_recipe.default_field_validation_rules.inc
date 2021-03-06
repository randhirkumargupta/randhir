<?php
/**
 * @file
 * feature_for_recipe.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function feature_for_recipe_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Calorie only numeric value';
  $rule->name = 'calorie_only_numeric_value';
  $rule->field_name = 'field_recipe_calorie_count';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'recipe';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      7 => 0,
      9 => 0,
      5 => 0,
      20 => 0,
      6 => 0,
      10 => 0,
      19 => 0,
      13 => 0,
      11 => 0,
      16 => 0,
      17 => 0,
      14 => 0,
      12 => 0,
      15 => 0,
      18 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please enter only numeric value in calorie count.';
  $export['calorie_only_numeric_value'] = $rule;

  return $export;
}
