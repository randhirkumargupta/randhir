<?php
/**
 * @file
 * feature_for_live_tv_front_page.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_live_tv_front_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_live_tv_front_page_image_default_styles() {
  $styles = array();

  // Exported image style: live_tv_latest_video.
  $styles['live_tv_latest_video'] = array(
    'label' => 'live tv latest video',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
