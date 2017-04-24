<?php
/**
 * @file
 * feature_for_ugc.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function feature_for_ugc_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'ugc_node_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['ugc_node_form'] = $captcha;

  return $export;
}
