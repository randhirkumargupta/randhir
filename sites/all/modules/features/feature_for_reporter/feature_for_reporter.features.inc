<?php
/**
 * @file
 * feature_for_reporter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_reporter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_reporter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_reporter_node_info() {
  $items = array(
    'reporter' => array(
      'name' => t('Reporter'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Reporter name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
