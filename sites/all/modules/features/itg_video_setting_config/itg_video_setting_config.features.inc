<?php
/**
 * @file
 * itg_video_setting_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function itg_video_setting_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function itg_video_setting_config_node_info() {
  $items = array(
    'video_setting_by_bucket_name' => array(
      'name' => t('Video setting by bucket name'),
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
