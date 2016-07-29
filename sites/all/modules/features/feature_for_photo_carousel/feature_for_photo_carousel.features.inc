<?php
/**
 * @file
 * feature_for_photo_carousel.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_photo_carousel_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_photo_carousel_image_default_styles() {
  $styles = array();

  // Exported image style: photo_carousel_flexslider.
  $styles['photo_carousel_flexslider'] = array(
    'label' => 'Photo Carousel Flexslider',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 363,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: photo_carousel_rollingslider.
  $styles['photo_carousel_rollingslider'] = array(
    'label' => 'Photo Carousel Rollingslider',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 645,
          'height' => 363,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
