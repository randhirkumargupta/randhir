<?php

/**
 * @file: itg_event_registration.inc
 */

function itg_event_registration_form(){
  
  module_load_include('inc', 'node', 'node.pages');
  
  $form = array();
  $form = node_add('event_registration');
  $form['#cache'] = TRUE;
  return $form;
}