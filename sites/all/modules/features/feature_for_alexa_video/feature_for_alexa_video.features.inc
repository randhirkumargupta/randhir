<?php
/**
 * @file
 * feature_for_alexa_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_alexa_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_alexa_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_alexa_video_node_info() {
  $items = array(
    'alexa_audio_clips' => array(
      'name' => t('Alexa Audio Clips'),
      'base' => 'node_content',
      'description' => t('Alexa Audio Clips : Upload Audio clips here for Alexa (50 News)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
