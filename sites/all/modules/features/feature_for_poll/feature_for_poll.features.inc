<?php
/**
 * @file
 * feature_for_poll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_poll_ctools_plugin_api($module = NULL, $api = NULL) {
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
function feature_for_poll_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_poll_node_info() {
  $items = array(
    'poll' => array(
      'name' => t('poll'),
      'base' => 'node_content',
      'description' => t('Poll Management'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
