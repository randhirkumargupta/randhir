<?php
/**
 * @file
 * photogallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function photogallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function photogallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function photogallery_image_default_styles() {
  $styles = array();

  // Exported image style: photogallery_slide.
  $styles['photogallery_slide'] = array(
    'label' => 'Photogallery_slide',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 815,
          'height' => '',
          'upscale' => 0,
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
function photogallery_node_info() {
  $items = array(
    'photogallery' => array(
      'name' => t('photogallery'),
      'base' => 'node_content',
      'description' => t('photogallery'),
      'has_title' => '1',
      'title_label' => t('Gallery Headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
