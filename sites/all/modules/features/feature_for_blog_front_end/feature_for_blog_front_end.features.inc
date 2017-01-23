<?php
/**
 * @file
 * feature_for_blog_front_end.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_blog_front_end_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_blog_front_end_image_default_styles() {
  $styles = array();

  // Exported image style: blog_landing_image.
  $styles['blog_landing_image'] = array(
    'label' => 'blog landing image',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 647,
          'height' => 363,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
