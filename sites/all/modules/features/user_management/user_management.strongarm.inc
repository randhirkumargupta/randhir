<?php
/**
 * @file
 * user_management.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function user_management_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_qualification_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_qualification_pattern'] = $strongarm;

  return $export;
}
