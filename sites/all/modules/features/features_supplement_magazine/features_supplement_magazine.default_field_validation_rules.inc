<?php
/**
 * @file
 * features_supplement_magazine.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function features_supplement_magazine_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Magazine Print Issue Date';
  $rule->name = 'magazine_print_issue_date';
  $rule->field_name = 'field_print_magazine_issue_date';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'magazine';
  $rule->validator = 'field_validation_date_range2_validator';
  $rule->settings = array(
    'cycle' => 'global',
    'min' => 'now - 1 day',
    'max' => '',
    'reverse' => 0,
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
  $rule->error_message = 'Print issue date should be current date or future date.';
  $export['magazine_print_issue_date'] = $rule;

  return $export;
}
