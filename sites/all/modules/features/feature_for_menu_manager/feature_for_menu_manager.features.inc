<?php
/**
 * @file
 * feature_for_menu_manager.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_menu_manager_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_menu_manager_image_default_styles() {
  $styles = array();

  // Exported image style: menu_manager_icons.
  $styles['menu_manager_icons'] = array(
    'label' => 'menu manager icons',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 37,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: vertical_menu_icons.
  $styles['vertical_menu_icons'] = array(
    'label' => 'vertical menu icons',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 35,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
