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
  // Exported flag: "Follow".
  $flags['follow'] = array(
    'entity_type' => 'node',
    'title' => 'Follow',
    'global' => 0,
    'types' => array(
      0 => 'reporter',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Follow this author or content.',
    'flag_message' => 'Author or content has been followed by you.',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Follow this author or content.',
    'unflag_message' => 'Author or content has been unfollowed by you.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
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
    'module' => 'feature_for_personalization',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
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
    'flag_long' => 'Save content to your save content list.',
    'flag_message' => 'Content has been saved.',
    'unflag_short' => 'Remove',
    'unflag_long' => 'Remove content from your save list.',
    'unflag_message' => 'content has been removed.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
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
    'module' => 'feature_for_personalization',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
