<?php
/**
 * @file
 * feature_for_so_sorry.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_so_sorry_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_so_sorry_image_default_styles() {
  $styles = array();

  // Exported image style: so_sorry_remix.
  $styles['so_sorry_remix'] = array(
    'label' => 'so sorry remix',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 209,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
