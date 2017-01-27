<?php
/**
 * @file
 * feature_for_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function feature_for_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: photo_story_771x432.
  $styles['photo_story_771x432'] = array(
    'label' => 'photo story',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 771,
          'height' => 432,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: photo_story_small_88x66.
  $styles['photo_story_small_88x66'] = array(
    'label' => 'photo story small',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 88,
          'height' => 66,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
