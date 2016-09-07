<?php
/**
 * @file
 * features_for_magazine_front.features.inc
 */

/**
 * Implements hook_views_api().
 */
function features_for_magazine_front_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function features_for_magazine_front_image_default_styles() {
  $styles = array();

  // Exported image style: magazine_rhs_100x140.
  $styles['magazine_rhs_100x140'] = array(
    'label' => 'magazine_rhs_100x140',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: magazine_top_issue_172x240.
  $styles['magazine_top_issue_172x240'] = array(
    'label' => 'Magazine_top_issue_172x240',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 172,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: magazine_top_story_483x271.
  $styles['magazine_top_story_483x271'] = array(
    'label' => 'Magazine_top_story_483x271',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 483,
          'height' => 271,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: magazine_top_three_story_237x133.
  $styles['magazine_top_three_story_237x133'] = array(
    'label' => 'Magazine_top_three_story 237x133',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 237,
          'height' => 133,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
