<?php
/**
 * @file
 * custom_html_widgets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_html_widgets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function custom_html_widgets_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function custom_html_widgets_node_info() {
  $items = array(
    'custom_html_widgets' => array(
      'name' => t('Custom html widgets'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Widget Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
