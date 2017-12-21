<?php
/**
 * @file
 * feature_for_app_rest_api.features.inc 
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_app_rest_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
