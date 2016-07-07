<?php
/**
 * @file
 * feature_for_ugc.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_for_ugc_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ugc_ctype'.
  $field_bases['field_ugc_ctype'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ugc_ctype',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'story' => 'story',
        'recipe' => 'recipe',
        'photogallery' => 'photogallery',
        'videogallery' => 'videogallery',
        'podcast' => 'podcast',
        'blog' => 'blog',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_ugc_upload_photo'.
  $field_bases['field_ugc_upload_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ugc_upload_photo',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
