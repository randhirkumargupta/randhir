<?php
/**
 * @file
 * feature_for_aajtak_big_story.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_aajtak_big_story_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_aajtak_big_story_image_default_styles() {
  $styles = array();

  // Exported image style: at_big_story.
  $styles['at_big_story'] = array(
    'label' => 'at_big_story',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 850,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
