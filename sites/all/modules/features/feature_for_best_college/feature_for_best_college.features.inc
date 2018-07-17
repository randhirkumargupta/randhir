<?php
/**
 * @file
 * feature_for_best_college.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_best_college_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_best_college_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_best_college_node_info() {
  $items = array(
    'bestcolleges' => array(
      'name' => t('bestcolleges'),
      'base' => 'node_content',
      'description' => t('Bestcolleges'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
