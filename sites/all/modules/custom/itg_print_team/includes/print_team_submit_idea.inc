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
 * Change status of idea form
 */
function itg_print_team_idea_status(){
  $nid = arg(2);
  $node = node_load($nid);
  $status = str_replace('_', ' ', arg(1));

  $node->field_pti_idea_status[LANGUAGE_NONE][0]['value'] = ucfirst($status);
  field_attach_update('node', $node);
  drupal_goto('manage-print-team');
}