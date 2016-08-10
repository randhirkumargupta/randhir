<?php
/**
 * @file
 * features_for_print_team.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_print_team_ctools_plugin_api($module = NULL, $api = NULL) {
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
function features_for_print_team_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_print_team_node_info() {
  $items = array(
    'print_team_integration' => array(
      'name' => t('Print Team Integration'),
      'base' => 'node_content',
      'description' => t('Created for print team integration.'),
      'has_title' => '1',
      'title_label' => t('Idea Headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
