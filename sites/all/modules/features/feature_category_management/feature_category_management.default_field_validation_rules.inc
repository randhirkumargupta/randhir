<?php
/**
 * @file
 * feature_category_management.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function feature_category_management_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Redirect URL Validation';
  $rule->name = 'Category Management Redirect URL';
  $rule->field_name = 'field_cm_redirection_url';
  $rule->col = 'value';
  $rule->entity_type = 'taxonomy_term';
  $rule->bundle = 'category_management';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 1,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      12 => 0,
      19 => 0,
      7 => 0,
      17 => 0,
      11 => 0,
      18 => 0,
      16 => 0,
      8 => 0,
      5 => 0,
      13 => 0,
      14 => 0,
      9 => 0,
      6 => 0,
      10 => 0,
      15 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Redirection URL is not valid.';
  $export['Category Management Redirect URL'] = $rule;

  return $export;
}
