<?php
/**
 * @file
 * event_backend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_backend_ctools_plugin_api($module = NULL, $api = NULL) {
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
function event_backend_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function event_backend_node_info() {
  $items = array(
    'event_backend' => array(
      'name' => t('Event_backend'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sponsor' => array(
      'name' => t('Sponsor'),
      'base' => 'node_content',
      'description' => t('This Sponsor is using in event backend content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
