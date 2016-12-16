<?php
/**
 * @file
 * feature_for_aaj_tak_widgets.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_aaj_tak_widgets_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_aaj_tak_widgets_image_default_styles() {
  $styles = array();

  // Exported image style: aaj_tak_category_wise_content_banner_big.
  $styles['aaj_tak_category_wise_content_banner_big'] = array(
    'label' => 'Aaj tak category wise content banner big',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: aaj_tak_category_wise_content_banner_small.
  $styles['aaj_tak_category_wise_content_banner_small'] = array(
    'label' => 'aaj_tak_category_wise_content_banner_small',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: aaj_tak_category_wise_content_photo_block_big.
  $styles['aaj_tak_category_wise_content_photo_block_big'] = array(
    'label' => 'aaj_tak_category_wise_content_photo_block_big',
    'effects' => array(
      18 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: aaj_tak_category_wise_content_photo_small.
  $styles['aaj_tak_category_wise_content_photo_small'] = array(
    'label' => 'aaj_tak_category_wise_content_photo_small',
    'effects' => array(
      19 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: aaj_tak_category_wise_content_story_block.
  $styles['aaj_tak_category_wise_content_story_block'] = array(
    'label' => 'aaj_tak_category_wise_content_story_block',
    'effects' => array(
      17 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
