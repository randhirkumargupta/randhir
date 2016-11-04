<?php
/**
 * @file
 * feature_for_personalization.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_for_personalization_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function feature_for_personalization_flag_default_flags() {
  $flags = array();
  // Exported flag: "Read later".
  $flags['my_saved_content'] = array(
    'entity_type' => 'node',
    'title' => 'Read later',
    'global' => 0,
    'types' => array(
      0 => 'story',
      1 => 'videogallery',
      2 => 'photogallery',
    ),
    'flag_short' => 'READ LATER',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove',
    'unflag_long' => 'Unflag',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'anon_display' => 1,
    'anon_message' => '<a href="[login-url]" class="itg-flag-login">Watch</a>',
    'module' => 'feature_for_personalization',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
