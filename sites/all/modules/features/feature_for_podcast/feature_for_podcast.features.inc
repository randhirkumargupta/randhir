<?php
/**
 * @file
 * feature_for_podcast.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_podcast_ctools_plugin_api($module = NULL, $api = NULL) {
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
function feature_for_podcast_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_podcast_image_default_styles() {
  $styles = array();

  // Exported image style: podcast_audio_image_preview.
  $styles['podcast_audio_image_preview'] = array(
    'label' => 'Podcast Audio Image Preview',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 194,
          'height' => 124,
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
function feature_for_podcast_node_info() {
  $items = array(
    'podcast' => array(
      'name' => t('Podcast'),
      'base' => 'node_content',
      'description' => t('This content type using for  Podcast/Audio Creation.'),
      'has_title' => '1',
      'title_label' => t('Gallery Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
