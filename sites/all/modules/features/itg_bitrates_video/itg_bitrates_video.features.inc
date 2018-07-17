<?php
/**
 * @file
 * itg_bitrates_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itg_bitrates_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function itg_bitrates_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function itg_bitrates_video_node_info() {
  $items = array(
    'itg_bitrates_video' => array(
      'name' => t('ITG Bitrates Video'),
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
