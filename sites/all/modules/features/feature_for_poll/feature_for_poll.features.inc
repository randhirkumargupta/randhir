<?php
/**
 * @file
 * feature_for_poll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_poll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_poll_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_for_poll_image_default_styles() {
  $styles = array();

  // Exported image style: home_page_poll_images_style.
  $styles['home_page_poll_images_style'] = array(
    'label' => 'Home Page Poll Images Style',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 280,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: past_poll_images_style_front_end.
  $styles['past_poll_images_style_front_end'] = array(
    'label' => 'Past Poll Images Style Front End',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 127,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: poll_active_poll_image_option_front_end.
  $styles['poll_active_poll_image_option_front_end'] = array(
    'label' => 'Poll Active Poll Image Option Front End',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 93,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: poll_banner_active_poll_front_end.
  $styles['poll_banner_active_poll_front_end'] = array(
    'label' => 'Poll Banner Active Poll Front End',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 127,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_for_poll_node_info() {
  $items = array(
    'poll' => array(
      'name' => t('poll'),
      'base' => 'node_content',
      'description' => t('Poll Management'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
