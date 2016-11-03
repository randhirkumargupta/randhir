<?php
/**
 * @file
 * feature_tag_management.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_tag_management_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_tag_management_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function feature_tag_management_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow".
  $flags['itg_follow'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Follow',
    'global' => 0,
    'types' => array(
      0 => 'tags',
    ),
    'flag_short' => 'Follow',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfollow',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'feature_tag_management',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
