<?php
/**
 * @file
 * feature_for_photo_and_video_related_content.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_photo_and_video_related_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_photo_and_video_related_content_image_default_styles() {
  $styles = array();

  // Exported image style: story_related_content_138x103.
  $styles['story_related_content_138x103'] = array(
    'label' => 'story_related_content_138x103',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 138,
          'height' => 103,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
