<?php
/**
 * @file
 * features_for_survey.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_survey_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_survey_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_survey_node_info() {
  $items = array(
    'survey' => array(
      'name' => t('Survey'),
      'base' => 'node_content',
      'description' => t('Created for survey.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
