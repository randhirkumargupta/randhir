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