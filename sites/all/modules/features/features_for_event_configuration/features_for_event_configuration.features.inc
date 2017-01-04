<?php
/**
 * @file
 * features_for_event_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_event_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_event_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
