<?php
/**
 * @file
 * feature_for_sirf_web_per.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_sirf_web_per_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_sirf_web_per_image_default_styles() {
  $styles = array();

  // Exported image style: sirf_web_per.
  $styles['sirf_web_per'] = array(
    'label' => 'sirf web per',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
