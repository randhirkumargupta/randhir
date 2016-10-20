<?php
/**
 * @file
 * feature_for_entertainment.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_entertainment_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_entertainment_image_default_styles() {
  $styles = array();

  // Exported image style: image750x447.
  $styles['image750x447'] = array(
    'label' => 'Image750X447',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 447,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
