<?php
/**
 * @file
 * features_for_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_notification_node_info() {
  $items = array(
    'notification' => array(
      'name' => t('Notification'),
      'base' => 'node_content',
      'description' => t('Content type for notification.'),
      'has_title' => '1',
      'title_label' => t('Message Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
