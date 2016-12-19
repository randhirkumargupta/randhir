<?php
/**
 * @file
 * features_for_event_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_event_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "msnf" && $api == "msnf") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_event_registration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_event_registration_node_info() {
  $items = array(
    'event_registration' => array(
      'name' => t('Event Registration'),
      'base' => 'node_content',
      'description' => t('Created to manage registration form for events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
