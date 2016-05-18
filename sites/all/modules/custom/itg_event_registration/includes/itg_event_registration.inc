<?php

/**
 * @file: itg_event_registration.inc
 */

function itg_event_registration_form(){
  $node = node_load($_GET['event_id']);
  $no_of_tickets = $node->field_no_of_tickets[LANGUAGE_NONE][0]['value'];
  $event_type = $node->field_event_type[LANGUAGE_NONE][0]['value'];
  
  //Check for published node, registration is allowed for published event only.
  if ($node->status == 1) {
      if ($event_type == 'invite') {
        return 'Registration is not required for event <strong>' . ucwords($node->title) . '</strong>. Please contact to India Today Group.';
      } 
      else {
      $corrent_date = strtotime(date('Y-m-d').' 00:00:00');  
      $event_reg_start_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      $event_reg_close_date = strtotime($node->field_registration_close_date[LANGUAGE_NONE][0]['value']);
      if($event_reg_start_date > $corrent_date || $corrent_date > $event_reg_close_date){
        return 'Registration has been closed for event <strong>' . ucwords($node->title) . '</strong>.';
      } 
      else {
      $registration_main_users = itg_common_check_record_existance($_GET['event_id'], 'field_data_field_story_source_id', 'field_story_source_id_value');

      //Count group users registration for an event
      $main_user_nid_arr = itg_common_select_field_value('entity_id', 'field_data_field_story_source_id', 'field_story_source_id_value', $_GET['event_id']);
      $registration_group_users = 0;
      foreach ($main_user_nid_arr as $main_user_nid) {
        $registration_group_users = $registration_group_users + itg_common_check_record_existance($main_user_nid, 'field_data_field_erf_registration_fee', 'entity_id');
      }

      //Total count for an event
      $total_registration_users = $registration_main_users + $registration_group_users;

      //If registration has been reached to no. of tickets, stop for next registration
      if ($no_of_tickets < $total_registration_users) {
        return 'Tickets are not available for an event <strong>' . ucwords($node->title) . '</strong>.';
      } else {
        module_load_include('inc', 'node', 'node.pages');
        $form = array();
        $form = node_add('event_registration');
        $form['#cache'] = TRUE;
        return $form;
      }
      }
    }
  } else {
    if ($node->title) {
      $message = 'Event <strong>' . ucwords($node->title) . '</strong> is unpublished. ';
    } else {
      $message = 'Event not found. ';
    }
    return $message . 'Sorry! you can not register for this event.';
  }
}