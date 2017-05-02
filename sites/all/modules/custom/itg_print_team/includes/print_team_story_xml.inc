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
  if ($form_state['input']['op'] == 'Generate XML') {
    $views_bulk_operations = $form_state['values']['views_bulk_operations'];
    if (is_array($views_bulk_operations) && count($views_bulk_operations) > 0) {
      if (!max($views_bulk_operations) > 0) {
        form_set_error('views_bulk_operations', t('Please select atleast one checkbox to generate story xml.'));
      }
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
  global $base_url;
  module_load_include('inc', 'itg_syndication', 'includes/itg_syndication_custom_feed');
  $feed_pattern = get_default_feed_pattern('xml', 'story');
  $timestamp = time();
  $views_bulk_operations = $form_state['values']['views_bulk_operations'];
  if (is_array($views_bulk_operations) && count($views_bulk_operations) > 0) {
    $feed_dir = "public://story/";
    if (!file_exists($feed_dir)) {
      mkdir($feed_dir, 0777, TRUE);
    }
    $xml = "<root>";
    //p($views_bulk_operations);
    foreach ($views_bulk_operations as $nid) {
      if (!empty($nid) && $nid>0) {
        $xml .= get_custom_feeds_files($nid, $feed_pattern ,'xml');
      }
    }
    $xml .= "</root>";
    $filename = 'story_' . $timestamp . '.xml';
   $file= file_save_data($xml, "$feed_dir" . $filename);
   $file_uri = file_create_url($file->uri);
    
  }
  
  $options_download['attributes']['download'] = '';
   $options_download['attributes']['target'] = '_blank';
  $link_val = t('XML have been generated for selected stories. ') . l(t('Click here to download'), $file_uri, $options_download);
  drupal_set_message($link_val, 'status');
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
function itg_print_team_association_update($node_info, $issue_nid, $magazine, $associated_source_id, $print_update = FALSE, $supplement) {

  if ($print_update) {
    
    $idea_node = node_load($node_info); // Here "node_info" is nid
    
    // Update print team node with selected issue and magazine
    $node = node_load($node_info);
    $node->field_pti_issue[LANGUAGE_NONE][0]['target_id'] = $issue_nid;
    $node->field_pti_magazine[LANGUAGE_NONE][0]['target_id'] = $magazine;
    if ($supplement != '_none') {
      $node->field_pti_supplement[LANGUAGE_NONE][0]['target_id'] = $supplement;
    }
    
    field_attach_update('node', $node);
    
    // Update story node with selected issue and magazine
    $story_node = new stdClass();
    $story_node->nid = $associated_source_id;
    $story_node->type = 'story';
    $story_node->field_story_issue_date[LANGUAGE_NONE][0]['value'] = itg_common_get_node_title($issue_nid);
    $story_node->field_story_select_magazine[LANGUAGE_NONE][0]['target_id'] = $magazine;
    if ($supplement != '_none') {
      $story_node->field_story_select_supplement[LANGUAGE_NONE][0]['target_id'] = $supplement;
    }    
    field_attach_update('node', $story_node);
  }
  else {
    
    $idea_node = $node_info; // Here "node_info" is complete node
    
    // Collect variables to use in story node
    $headline = $node_info->title;
    $body = $node_info->body[LANGUAGE_NONE][0]['value'];
    $fid = $node_info->field_quiz_answer_image[LANGUAGE_NONE][0]['fid'];
    $rating = $node_info->field_story_rating[LANGUAGE_NONE][0]['value'];
    $magazine_kicker = $node_info->field_pti_magazine_kicker[LANGUAGE_NONE][0]['value'];

    // Update story node
    $node = node_load($associated_source_id);
    $node->title = trim($headline);
    $node->field_story_long_head_line[LANGUAGE_NONE][0]['value'] = trim($headline) ? trim($headline) : 'NA';
    $node->body[LANGUAGE_NONE][0]['value'] = $body ? $body : 'NA';
    $node->field_story_magazine_kicker_text[LANGUAGE_NONE][0]['value'] = $magazine_kicker ? $magazine_kicker : 'NA';
    
    // Update rating field
    if (!empty($rating)) {
      $node->field_story_rating[LANGUAGE_NONE][0]['value'] = $rating;
    }
    
    // Update large image field
    if ($fid) {
      $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'] = $fid;
    }
    
    // Finally Update story node
    field_attach_update('node', $node);
    node_save($node);
  }

  //Send mail after updation
  module_load_include('inc', 'itg_print_team', 'includes/print_team_mail');
  itg_print_team_send_idea_status_mail($idea_node, 'association', 'idea_update');
  drupal_set_message('Selected ideas have been associated to selected issue and magazine successfully.');
}