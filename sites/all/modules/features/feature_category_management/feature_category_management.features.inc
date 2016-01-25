<?php
/**
 * @file
 * feature_category_management.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_category_management_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
