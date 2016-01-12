<?php
/**
 * @file
 * features_for_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_for_story_node_info() {
  $items = array(
    'story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Short headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
