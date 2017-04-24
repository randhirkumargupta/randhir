<?php
/**
 * @file
 * ads_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ads_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ads_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ads_features_node_info() {
  $items = array(
    'ads_management' => array(
      'name' => t('Ads Placeholder'),
      'base' => 'node_content',
      'description' => t('ITG CMS user should be able to create a place holder in the CMS and enter the script in the placeholder, and accordingly ads will appear on the front end.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
