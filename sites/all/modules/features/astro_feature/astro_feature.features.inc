<?php
/**
 * @file
 * astro_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function astro_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function astro_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function astro_feature_node_info() {
  $items = array(
    'astro' => array(
      'name' => t('Astro'),
      'base' => 'node_content',
      'description' => t('ITG CMS users should be able to file astrology for all zodiac signs in the system.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
