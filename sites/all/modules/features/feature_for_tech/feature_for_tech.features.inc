<?php
/**
 * @file
 * feature_for_tech.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_tech_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_tech_image_default_styles() {
  $styles = array();

  // Exported image style: image_750x363.
  $styles['image_750x363'] = array(
    'label' => 'Image_750X363',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 650,
          'height' => 363,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
