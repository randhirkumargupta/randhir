<?php
/**
 * @file
 * features_supplement_magazine.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_supplement_magazine_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
function features_supplement_magazine_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_supplement_magazine_node_info() {
  $items = array(
    'issue' => array(
      'name' => t('Issue'),
      'base' => 'node_content',
      'description' => t('Created for issues'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'magazine' => array(
      'name' => t('Magazine'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'supplement' => array(
      'name' => t('Supplement'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
