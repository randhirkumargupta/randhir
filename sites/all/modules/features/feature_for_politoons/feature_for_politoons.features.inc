<?php
/**
 * @file
 * feature_for_politoons.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_politoons_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_politoons_image_default_styles() {
  $styles = array();

  // Exported image style: politoons.
  $styles['politoons'] = array(
    'label' => 'politoons 88 88',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 88,
          'height' => 88,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
