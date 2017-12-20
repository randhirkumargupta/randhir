<?php
/**
 * @file
 * feature_category_management.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_category_management_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__category_management';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '9',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'name' => array(
          'weight' => '9',
        ),
        'description' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__category_management'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'itg_category_manager_vocabularies';
  $strongarm->value = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  $export['itg_category_manager_vocabularies'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_taxonomy_term__category_management';
  $strongarm->value = 1;
  $export['metatag_enable_taxonomy_term__category_management'] = $strongarm;

  return $export;
}
