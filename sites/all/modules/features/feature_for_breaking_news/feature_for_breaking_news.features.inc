<?php
/**
 * @file
 * feature_for_breaking_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_breaking_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_breaking_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_breaking_news_image_default_styles() {
  $styles = array();

  // Exported image style: photogallery_slider.
  $styles['photogallery_slider'] = array(
    'label' => 'photogallery_slider',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 815,
          'height' => 300,
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
function feature_for_breaking_news_node_info() {
  $items = array(
    'breaking_news' => array(
      'name' => t('Breaking News'),
      'base' => 'node_content',
      'description' => t('Breaking News'),
      'has_title' => '1',
      'title_label' => t('News Title 1'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
