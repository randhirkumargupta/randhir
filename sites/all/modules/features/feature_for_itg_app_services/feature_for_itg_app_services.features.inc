<?php
/**
 * @file
 * feature_for_itg_app_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_itg_app_services_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
