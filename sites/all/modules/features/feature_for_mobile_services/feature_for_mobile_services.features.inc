<?php
/**
 * @file
 * feature_for_mobile_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_mobile_services_ctools_plugin_api($module = NULL, $api = NULL) {
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
function feature_for_mobile_services_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_mobile_services_node_info() {
  $items = array(
    'client_service_association' => array(
      'name' => t('Associate Client & Services'),
      'base' => 'node_content',
      'description' => t('ITG CMS users should be able to associate a service with one or multiple clients in the system to share the mobile feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clients_creation' => array(
      'name' => t('Clients'),
      'base' => 'node_content',
      'description' => t('ITG CMS users should be able to create a client in the system to share the Mobile feed with them.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'create_content' => array(
      'name' => t('Content'),
      'base' => 'node_content',
      'description' => t('ITG CMS users should be able to create content for a service which have been associated with a client and shall be able to share it with client for mobile service.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service_creation' => array(
      'name' => t('Service'),
      'base' => 'node_content',
      'description' => t('ITG CMS users should be able to create a service in my system to share the mobile service with clients.'),
      'has_title' => '1',
      'title_label' => t('Service Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
