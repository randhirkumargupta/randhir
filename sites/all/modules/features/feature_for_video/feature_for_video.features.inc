<?php
/**
 * @file
 * feature_for_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_video_image_default_styles() {
  $styles = array();

  // Exported image style: video_landing_page_170_x_127.
  $styles['video_landing_page_170_x_127'] = array(
    'label' => 'video_landing_page_170 X 127',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 127,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_for_video_node_info() {
  $items = array(
    'itg_delete_solr_video' => array(
      'name' => t('ITG Delete Solr Video'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'videogallery' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('This content type using for Video Gallery.'),
      'has_title' => '1',
      'title_label' => t('Long headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
