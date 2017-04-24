<?php
/**
 * @file
 * features_for_highlights.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_highlights_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_highlights_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_highlights_node_info() {
  $items = array(
    'heighlights' => array(
      'name' => t('Highlights'),
      'base' => 'node_content',
      'description' => t('Created for heighlights.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
