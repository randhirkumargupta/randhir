<?php
/**
 * @file
 * itg_bitrates_video.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function itg_bitrates_video_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_itg_bitrates_video_pattern';
  $strongarm->value = '';
  $export['pathauto_node_itg_bitrates_video_pattern'] = $strongarm;

  return $export;
}
