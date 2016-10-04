<?php
/**
 * @file
 * features_for_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_newsletter_ctools_plugin_api($module = NULL, $api = NULL) {
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
function features_for_newsletter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_newsletter_node_info() {
  $items = array(
    'newsletter' => array(
      'name' => t('Newsletter'),
      'base' => 'node_content',
      'description' => t('Created for newsletter.'),
      'has_title' => '1',
      'title_label' => t('Subject Line'),
      'help' => '',
    ),
    'newsletter_templates' => array(
      'name' => t('Newsletter Templates'),
      'base' => 'node_content',
      'description' => t('Created to manage newsletter templates.'),
      'has_title' => '1',
      'title_label' => t('Template Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
