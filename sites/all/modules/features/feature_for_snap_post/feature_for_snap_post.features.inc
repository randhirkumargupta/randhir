<?php
/**
 * @file
 * feature_for_snap_post.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_snap_post_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_snap_post_image_default_styles() {
  $styles = array();

  // Exported image style: buzz_image.
  $styles['buzz_image'] = array(
    'label' => 'buzz image',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 539,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: story_image.
  $styles['story_image'] = array(
    'label' => 'story image',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 601,
          'height' => 364,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
