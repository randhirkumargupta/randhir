<?php
/**
 * @file
 * feature_for_key_candidate.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_for_key_candidate_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_state_managment_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_state_managment_pattern'] = $strongarm;

  return $export;
}
