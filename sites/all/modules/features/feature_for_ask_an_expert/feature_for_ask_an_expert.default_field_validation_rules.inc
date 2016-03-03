<?php
/**
 * @file
 * feature_for_ask_an_expert.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function feature_for_ask_an_expert_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'ask_an_expert_field_validation';
  $rule->name = 'Ask an Expert Email validation';
  $rule->field_name = 'field_user_email';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'ask_an_expert';
  $rule->validator = 'field_validation_email_validator';
  $rule->settings = array(
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
      22 => 0,
      19 => 0,
      10 => 0,
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
  $rule->error_message = 'Please Enter Valid Email Address';
  $export['Ask an Expert Email validation'] = $rule;

  return $export;
}
