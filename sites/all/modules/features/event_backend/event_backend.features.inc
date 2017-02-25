<?php
/**
 * @file
 * event_backend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_backend_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "msnf" && $api == "msnf") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function event_backend_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function event_backend_image_default_styles() {
  $styles = array();

  // Exported image style: 110x82.
  $styles['110x82'] = array(
    'label' => '110x82',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 110,
          'height' => 82,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_364x205.
  $styles['event_364x205'] = array(
    'label' => 'event_364x205',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 364,
          'height' => 205,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_post_364x205.
  $styles['event_post_364x205'] = array(
    'label' => 'event_post_364x205',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 364,
          'height' => 205,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_speaker_168x168.
  $styles['event_speaker_168x168'] = array(
    'label' => 'event_speaker_168x168',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 168,
          'height' => 168,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_speaker_program_72x72.
  $styles['event_speaker_program_72x72'] = array(
    'label' => 'event_speaker_program_72x72',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 72,
          'height' => 72,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_136x73.
  $styles['image_136x73'] = array(
    'label' => 'image 136X73',
    'effects' => array(
      17 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 136,
          'height' => 73,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_221x54.
  $styles['image_221x54'] = array(
    'label' => 'image 221X54',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 221,
          'height' => 54,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: speaker_detail_168x168.
  $styles['speaker_detail_168x168'] = array(
    'label' => 'speaker_detail_168x168',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 168,
          'height' => 168,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: speaker_right_103x103.
  $styles['speaker_right_103x103'] = array(
    'label' => 'speaker_right_103x103',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 103,
          'height' => 103,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sponsor85___33.
  $styles['sponsor85___33'] = array(
    'label' => 'sponsor85 * 33',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 85,
          'height' => 33,
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
function event_backend_node_info() {
  $items = array(
    'event_backend' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sponsor' => array(
      'name' => t('Sponsor'),
      'base' => 'node_content',
      'description' => t('This Sponsor is using in event backend content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
