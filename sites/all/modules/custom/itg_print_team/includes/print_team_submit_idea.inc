<?php

/**
 * Submit idea functionality
 * @file submit-idea.inc
 */

/**
 * Submit idea form
 * @return array
 */
function itg_print_team_submit_idea() {
  
  module_load_include('inc', 'node', 'node.pages');
  $form = array();
  $form = node_add('print_team_integration');
  $form['#cache'] = TRUE;
  return $form;
}

/**
 * Change status of idea
 */
function itg_print_team_idea_status() {
  
  $nid = arg(2);
  $node = node_load($nid);
  $status = str_replace('_', ' ', arg(1));
  
  //Set status and update node
  $node->field_pti_idea_status[LANGUAGE_NONE][0]['value'] = ucwords($status);
  field_attach_update('node', $node);
  
  if ($status == 'approved' || $status == 'rejected') {
    drupal_set_message(t('Idea <strong>@ideatitle</strong> has been @operation successfully.', array('@ideatitle' => $node->title, '@operation' => ucwords($status))));
  }
  else {
    drupal_set_message(t('Idea <strong>@ideatitle</strong> has been sent for modification.', array('@ideatitle' => $node->title)));
  }
  
  drupal_goto('manage-print-team');
}

/**
 * Get uids of users having role "correspondent"
 */
function itg_print_team_ideas_csv() {

  $role = user_role_load_by_name('Correspondent');
  $result_user = db_select('users_roles', 'ur')
      ->fields('ur', array('uid'))
      ->condition('rid', $role->rid)
      ->execute();

  foreach ($result_user as $record) {
    $uids[] = $record->uid;
  }

  // CSV file header
  $file = 'ideas_csv';
  $idea_csv = "Idea Title" . "," . "Magazine Kicker" . "," . "Section" 
          . "," . "Status" . "," . "Word Limit" . "," . "Timeline" . "," 
          . "Magazine" . "," . "Issue" . "," . "Created" . "," . "Rating" 
          . "," . "User Type" . "," . "Brief" . "\n\r\0";

  $query = db_select('node', 'n');
  $query->join('field_data_field_pti_idea_status', 'ps', 'n.nid = ps.entity_id'); //JOIN node with magazines
  $query->condition('n.type', 'print_team_integration')
      ->condition('n.uid', $uids, 'IN')
      ->fields('n')
      ->orderBy('ps.field_pti_idea_status_value', 'ASC');

  $result = $query->execute();

  // Generate CSV content
  foreach ($result as $row) {
    $node = node_load($row->nid);
    $title = $node->title;
    $brief_body = strip_tags(trim(preg_replace('/\s\s+/', ' ', $node->body[LANGUAGE_NONE][0]['value'])));
    $brief = $brief_body;
    $kicker = $node->field_pti_magazine_kicker[LANGUAGE_NONE][0]['value'];
    $section_tid = itg_print_tem_get_section($node->field_story_category[LANGUAGE_NONE][0]['tid']);
    $status = $node->field_pti_idea_status[LANGUAGE_NONE][0]['value'];
    $word_limit = $node->field_pti_words_limit[LANGUAGE_NONE][0]['value'];
    $time_line = explode(" ", $node->field_survey_end_date[LANGUAGE_NONE][0]['value']);
    $get_magazine = itg_print_tem_get_magazine($node->field_pti_magazine[LANGUAGE_NONE][0]['target_id']);
    $getissue = itg_print_tem_get_magazine($node->field_pti_issue[LANGUAGE_NONE][0]['target_id']);
    $get_issue = explode(" ", $getissue);    
    
    $created_date = date('d/m/Y', $node->created);
    $rating = $node->field_story_rating[LANGUAGE_NONE][0]['value'] ? $node->field_story_rating[LANGUAGE_NONE][0]['value'] : '0';
    $idea_csv .= $title . "," . $kicker . "," . $section_tid 
            . "," . $status . "," . $word_limit . "," . $time_line[0] . "," . $get_magazine 
            . "," . $get_issue[0] . "," . $created_date . "," . $rating . "," 
            . "Correspondent" . "," . $brief . "\n\r\0";
    
  }

  $filename = $file . "_" . date("d-m-Y:i", time());
  header('Content-Description: File Transfer');
  header('Content-Type: application/force-download');
  header('Content-Disposition: attachment; filename=' . $filename . '.csv');
  print $idea_csv;
}