<?php
/**
 * @file
 * feature_for_ask_an_expert.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function feature_for_ask_an_expert_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'ask_an_expert_node_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['ask_an_expert_node_form'] = $captcha;

  return $export;
}
