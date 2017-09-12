<?php
/**
 * @file
 * feature_for_report_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_report_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
