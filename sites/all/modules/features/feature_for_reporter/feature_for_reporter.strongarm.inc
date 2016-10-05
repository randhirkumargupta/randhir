<?php
/**
 * @file
 * feature_for_reporter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_for_reporter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_reporter';
  $strongarm->value = array();
  $export['menu_options_reporter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_reporter';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_reporter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_reporter';
  $strongarm->value = '1';
  $export['node_preview_reporter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_reporter';
  $strongarm->value = 1;
  $export['node_submitted_reporter'] = $strongarm;

  return $export;
}
