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

  // Exported image style: photogallery_preview184x245.
  $styles['photogallery_preview184x245'] = array(
    'label' => 'photogallery_preview815x300',
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
function photogallery_node_info() {
  $items = array(
    'photogallery' => array(
      'name' => t('photogallery'),
      'base' => 'node_content',
      'description' => t('photogallery'),
      'has_title' => '1',
      'title_label' => t('Gallery Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
