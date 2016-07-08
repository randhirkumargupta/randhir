<?php
/**
 * @file
 * feature_for_top_story_widget.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_for_top_story_widget_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_links';
  $strongarm->value = TRUE;
  $export['nodequeue_links'] = $strongarm;

  return $export;
}
