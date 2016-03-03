<?php
/**
 * @file
 * feature_for_ask_an_expert.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_ask_an_expert_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_ask_an_expert_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_ask_an_expert_node_info() {
  $items = array(
    'ask_an_expert' => array(
      'name' => t('Ask an Expert'),
      'base' => 'node_content',
      'description' => t('Ask an Expert'),
      'has_title' => '1',
      'title_label' => t('Question '),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
