<?php
/**
 * @file
 * features_for_event_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_event_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_event_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_event_configuration_node_info() {
  $items = array(
    'event_configurations' => array(
      'name' => t('Event Configurations'),
      'base' => 'node_content',
      'description' => t('Created for configuration of events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
