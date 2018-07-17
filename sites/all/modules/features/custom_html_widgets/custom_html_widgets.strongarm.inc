<?php
/**
 * @file
 * custom_html_widgets.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function custom_html_widgets_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_custom_html_widgets_pattern';
  $strongarm->value = '';
  $export['pathauto_node_custom_html_widgets_pattern'] = $strongarm;

  return $export;
}
