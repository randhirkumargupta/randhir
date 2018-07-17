<?php
/**
 * @file
 * feature_for_alexa_video.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_for_alexa_video_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_alexa_audio_clips';
  $strongarm->value = '2';
  $export['comment_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_alexa_audio_clips';
  $strongarm->value = '0';
  $export['comment_anonymous_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_alexa_audio_clips';
  $strongarm->value = 1;
  $export['comment_default_mode_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_alexa_audio_clips';
  $strongarm->value = '50';
  $export['comment_default_per_page_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_alexa_audio_clips';
  $strongarm->value = 1;
  $export['comment_form_location_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_alexa_audio_clips';
  $strongarm->value = '1';
  $export['comment_preview_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_alexa_audio_clips';
  $strongarm->value = 1;
  $export['comment_subject_field_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__alexa_audio_clips';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_alexa_audio_clips';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_alexa_audio_clips';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_alexa_audio_clips';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_alexa_audio_clips';
  $strongarm->value = '0';
  $export['node_preview_alexa_audio_clips'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_alexa_audio_clips';
  $strongarm->value = 1;
  $export['node_submitted_alexa_audio_clips'] = $strongarm;

  return $export;
}
