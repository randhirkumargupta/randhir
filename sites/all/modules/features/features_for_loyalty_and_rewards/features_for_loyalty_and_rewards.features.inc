<?php
/**
 * @file
 * features_for_loyalty_and_rewards.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_loyalty_and_rewards_ctools_plugin_api($module = NULL, $api = NULL) {
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
function features_for_loyalty_and_rewards_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_loyalty_and_rewards_node_info() {
  $items = array(
    'loyalty_and_rewards' => array(
      'name' => t('Loyalty and Rewards'),
      'base' => 'node_content',
      'description' => t('Created to manage loyalty and rewards.'),
      'has_title' => '1',
      'title_label' => t('Product Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
