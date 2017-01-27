<?php
/**
 * @file
 * coupon_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function coupon_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function coupon_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function coupon_features_node_info() {
  $items = array(
    'coupon' => array(
      'name' => t('Coupon'),
      'base' => 'node_content',
      'description' => t('This is to add Coupon!'),
      'has_title' => '1',
      'title_label' => t('Enter Coupon name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
