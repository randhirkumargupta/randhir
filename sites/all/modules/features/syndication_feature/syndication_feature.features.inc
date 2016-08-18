<?php
/**
 * @file
 * syndication_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function syndication_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function syndication_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function syndication_feature_node_info() {
  $items = array(
    'syndication_client' => array(
      'name' => t('Syndication Client'),
      'base' => 'node_content',
      'description' => t('Use <em>Syndication Client</em> to create client information for predefined clients.'),
      'has_title' => '1',
      'title_label' => t('Client Description'),
      'help' => '',
    ),
    'syndication_feed_from_pattern' => array(
      'name' => t('Syndication feed from pattern'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Create Syndication Default Configuration'),
      'help' => '',
    ),
    'syndication_rule' => array(
      'name' => t('Syndication rule'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Select Client Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
