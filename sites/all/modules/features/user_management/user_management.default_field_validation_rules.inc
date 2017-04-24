<?php
/**
 * @file
 * user_management.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function user_management_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Mobile number validation';
  $rule->name = 'mobile_number_validation';
  $rule->field_name = 'field_mobile_number';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
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
  $rule->error_message = 'Please enter valid mobile number without Country Code.';
  $export['mobile_number_validation'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'mobile_number_contain_zero';
  $rule->name = 'mobile_number_zero';
  $rule->field_name = 'field_mobile_number';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[1-9][0-9]{9}$',
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
  $rule->error_message = 'Please enter valid mobile number without Country Code or Without Zero.';
  $export['mobile_number_zero'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Mobile validation';
  $rule->name = 'mobiler_validation';
  $rule->field_name = 'field_mobile_number';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '10',
    'max' => '10',
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
  $rule->error_message = 'Mobile number must be valid 10 digit number.';
  $export['mobiler_validation'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'PinCode';
  $rule->name = 'pincode';
  $rule->field_name = 'field_user_pincode';
  $rule->col = 'value';
  $rule->entity_type = 'user';
  $rule->bundle = 'user';
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
  $rule->error_message = 'Please enter valid Pincode.';
  $export['pincode'] = $rule;

  return $export;
}
