<?php
/**
 * @file
 * feature_for_ugc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_ugc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_ugc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_ugc_node_info() {
  $items = array(
    'ugc' => array(
      'name' => t('UGC'),
      'base' => 'node_content',
      'description' => t('User Generated Content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
