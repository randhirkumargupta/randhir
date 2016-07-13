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

/**
 * Check association print to story with magazine and issues
 * @param int $source_id
 * @return int
 */
function itg_print_team_check_association_print_to_story($source_id) {
  if ($source_id) {
    $record = db_select('field_data_field_story_source_id', 's')
            ->fields('s', array('entity_id'))
            ->condition('s.field_story_source_id_value', $source_id, '=')
            ->range(0, 1)->execute()->fetchAssoc();
  }
  return isset($record['entity_id']) ? $record['entity_id'] : FALSE;
}

/**
 * Callback for update association of story with magazine and issue
 * @global array $user
 * @param int $nid
 * @param string $issue
 * @param string $magazine
 * @param int $associated_source_id
 * @param boolean $print_update
 */
function itg_print_team_association_update($nid, $issue_nid, $magazine, $associated_source_id, $print_update = FALSE) {
  global $user;
  $node = node_load($nid);
  $headline = $node->title;
  $body = $node->body[LANGUAGE_NONE][0]['value'];
  $fid = $node->field_quiz_answer_image[LANGUAGE_NONE][0]['fid'];
  $issue_title = itg_common_get_node_title($issue_nid);  
  $node->field_pti_issue[LANGUAGE_NONE][0]['target_id'] = $issue_nid;
  $node->field_pti_magazine[LANGUAGE_NONE][0]['target_id'] = $magazine;
  if ($print_update) {
    field_attach_update('node', $node);
  }

  $story_node = new stdClass();
  $story_node->nid = $associated_source_id;
  $story_node->type = "story";
  $story_node->title = trim($headline);
  $story_node->uid = $user->uid;
  $story_node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
  $story_node->body[$node->language][0]['value'] = $body ? $body : 'NA';
  $story_node->field_story_issue_date[LANGUAGE_NONE][0]['value'] = isset($issue) ? $issue : date('Y-m-d h:i:s', time());
  //Issue, magazine and supplement
  $story_node->field_story_magazine_story_issue[LANGUAGE_NONE][0]['value'] = 'magazine_issue_story';
  if ($magazine) {
    $story_node->field_story_select_magazine[LANGUAGE_NONE][0]['target_id'] = $magazine;
  }
  if ($fid) {
    $story_node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
  }
  field_attach_update('node', $story_node);
}