<?php
/**
 * @file
 * mail_templates.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mail_templates_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_mail_templates_pattern';
  $strongarm->value = '';
  $export['pathauto_node_mail_templates_pattern'] = $strongarm;

  return $export;
}
