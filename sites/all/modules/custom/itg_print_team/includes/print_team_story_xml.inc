<?php

/**
 * Generate XML of submitted stories
 * @file print_team_story_xml.inc
 */

/**
 * Custom validation for generate xml story
 * @param array $form
 * @param array $form_state
 */
function itg_story_xml_validate($form, &$form_state) {
  $views_bulk_operations = $form_state['values']['views_bulk_operations'];
  if (is_array($views_bulk_operations) && count($views_bulk_operations) > 0) {
    if (!max($views_bulk_operations) > 0) {
      form_set_error('views_bulk_operations', t('Please select atleast one checkbox to generate story xml.'));
    }
  }
}

/**
 * Submit handler for generate xml story
 * @param array $form
 * @param array $form_state
 */
function itg_story_xml_submit($form, &$form_state) {
  // Load itg_syndication.inc from the node module.
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $feed_pattern = get_default_feed_pattern('xml', 'story');
  $timestamp = time();
  $views_bulk_operations = $form_state['values']['views_bulk_operations'];
  if (is_array($views_bulk_operations) && count($views_bulk_operations) > 0) {
    $feed_dir = "public://story/";
    if (!file_exists($feed_dir)) {
      mkdir($feed_dir, 0777, TRUE);
    }
    foreach ($views_bulk_operations as $nid) {
      if (!empty($nid)) {
        $xml = get_custom_feeds_files($nid, $feed_pattern);
        $filename = 'story_' . $nid . $timestamp . '.xml';
        $file = file_save_data($xml, "$feed_dir/" . $filename);
      }
    }
    drupal_set_message(t('Your selected story has been generated'));
  }
}
