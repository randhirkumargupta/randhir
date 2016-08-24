<?php
/**
 * @file
 * feature_for_all_widgets.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_all_widgets_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_all_widgets_image_default_styles() {
  $styles = array();

  // Exported image style: anchors_landing.
  $styles['anchors_landing'] = array(
    'label' => 'anchors-landing (370X208)',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 208,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: section_ordering_widget.
  $styles['section_ordering_widget'] = array(
    'label' => 'section_ordering_widget',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 208,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: widget_small.
  $styles['widget_small'] = array(
    'label' => 'widget_small',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 127,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: widget_very_small.
  $styles['widget_very_small'] = array(
    'label' => 'widget_very_small',
    'effects' => array(
      4 => array(
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
