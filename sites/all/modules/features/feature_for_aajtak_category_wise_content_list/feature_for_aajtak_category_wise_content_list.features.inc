<?php
/**
 * @file
 * feature_for_aajtak_category_wise_content_list.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_aajtak_category_wise_content_list_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_aajtak_category_wise_content_list_image_default_styles() {
  $styles = array();

  // Exported image style: aaj_tak_category_wise_content.
  $styles['aaj_tak_category_wise_content'] = array(
    'label' => 'Aaj tak category wise content',
    'effects' => array(
      14 => array(
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
