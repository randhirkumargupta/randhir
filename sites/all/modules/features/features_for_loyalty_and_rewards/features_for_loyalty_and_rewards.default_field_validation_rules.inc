<?php
/**
 * @file
 * features_for_loyalty_and_rewards.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function features_for_loyalty_and_rewards_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Actual Prize';
  $rule->name = 'actual_prize';
  $rule->field_name = 'field_lrp_actual_price';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'loyalty_and_rewards';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '1',
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
      21 => 0,
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
      23 => 0,
      22 => 0,
      24 => 0,
      25 => 0,
      26 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please enter positive number only.';
  $export['actual_prize'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Discounted Point';
  $rule->name = 'discounted_point';
  $rule->field_name = 'field_lrp_discounted_price';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'loyalty_and_rewards';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '1',
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
      21 => 0,
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
      23 => 0,
      22 => 0,
      24 => 0,
      25 => 0,
      26 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please enter positive number only.';
  $export['discounted_point'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Loyalty Point';
  $rule->name = 'loyalty_point';
  $rule->field_name = 'field_lrp_loyalty_points';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'loyalty_and_rewards';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '1',
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
      21 => 0,
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
      23 => 0,
      22 => 0,
      24 => 0,
      25 => 0,
      26 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Please enter positive number only.';
  $export['loyalty_point'] = $rule;

  return $export;
}
