<?php
/**
 * @file
 * social_media_integration.features.inc
 */

/**
 * Implements hook_views_api().
 */
function social_media_integration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_facebook_publication_type().
 */
function social_media_integration_default_facebook_publication_type() {
  $items = array();
  $items['video'] = entity_import('facebook_publication_type', '{
    "type" : "video",
    "label" : "Video",
    "weight" : "0",
    "description" : "Share video on facebook page.",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
