<?php
/**
 * @file
 * features_for_itg_template_widgets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_itg_template_widgets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_for_itg_template_widgets_node_info() {
  $items = array(
    'itg_template_widgets' => array(
      'name' => t('Template widgets'),
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
