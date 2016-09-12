<?php
/**
 * @file
 * online_story_archive.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function online_story_archive_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function online_story_archive_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
