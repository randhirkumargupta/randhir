<?php
/**
 * @file
 * feature_for_custom_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function feature_for_custom_style_image_default_styles() {
  $styles = array();

  // Exported image style: 50x50.
  $styles['50x50'] = array(
    'label' => '50x50',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 98x55.
  $styles['98x55'] = array(
    'label' => '98x55',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 98,
          'height' => 55,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
