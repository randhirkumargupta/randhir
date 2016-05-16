<?php

/**
 * @file: itg_event_registration.inc
 */

function itg_event_registration_form(){
  $node = node_load($_GET['event_id']);
  $no_of_tickets = $node->field_no_of_tickets[LANGUAGE_NONE][0]['value'];

  if ($node->status == 1) {
    module_load_include('inc', 'node', 'node.pages');
    $form = array();
    $form = node_add('event_registration');
    $form['#cache'] = TRUE;
    return $form;
  } 
  else {
    if($node->title){
      $message = 'Event <strong>'.  ucwords($node->title).'</strong> is unpublished. ';
    } else {
      $message = 'Event not found. ';
    }
    return $message.'Sorry! you can not register for this event.';
  }
}