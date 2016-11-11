<?php

/**
 * @file: itg_event_registration.inc
 */

/**
 * Render event registration form
 * @return string|bool
 */
function itg_event_registration_form($form, &$form_state) {
  
  $event_id = itg_event_registration_get_event_nid();
  $node = node_load($event_id);

  $no_of_tickets = $node->field_no_of_tickets[LANGUAGE_NONE][0]['value'];
  $event_type = $node->field_event_type[LANGUAGE_NONE][0]['value'];
  // Check for published node, registration is allowed for published event only.
  if ($node->status == 1) {
    if ($event_type == 'invite') {
      return 'Registration is not required for event <strong>' . ucwords($node->title) . '</strong>. Please contact to India Today Group.';
    }
    else {
      // TODO: Fix date format
      $current_date = strtotime(date('Y-m-d') . ' 00:00:00');
      $event_reg_start_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      $event_reg_close_date = strtotime($node->field_registration_close_date[LANGUAGE_NONE][0]['value']);

      if ($current_date < $event_reg_start_date) {
        return itg_event_registration_get_status_message($node, 'not_started');
      } 
      elseif ($current_date > $event_reg_close_date) {
        if($node->field_force_registration_open[LANGUAGE_NONE][0]['value']) {
          return itg_event_registration_get_form();
        }
        else {
          return itg_event_registration_get_status_message($node, 'closed');
        }
      } 
      else {
        $total_registration_users = itg_event_registration_get_total_registration($event_id);
        if ($total_registration_users >= $no_of_tickets) {
          return itg_event_registration_get_status_message($node, 'tickets_not_available');
          return '';
        }
        else {
          return itg_event_registration_get_form();
        }
      }
    }
  }
  else {
    if ($node->title) {
      $message = 'Event <strong>' . ucwords($node->title) . '</strong> is unpublished. ';
    }
    else {
      $message = 'Event not found. ';
    }
    return $message . 'Sorry! you can not register for this event.';
  }
}

/**
 * Show list of users registered for an event.
 * @return string
 */
function itg_event_registration_users_list() {
  $node_event = node_load(arg(2));
  
  if ($node_event->type == 'event_backend') {
    
      // Get event registered user list
      $main_user_nid_arr = itg_common_select_field_value('entity_id', 'field_data_field_story_source_id', 'field_story_source_id_value', $node_event->nid);
      
      $i = 0;
      foreach ($main_user_nid_arr as $main_user_nid) {
        $node = node_load($main_user_nid);
        $data[$i]['name'] = $node->field_erf_gender[LANGUAGE_NONE][0]['value'] . '. ' . $node->title . ' ' . $node->field_last_name[LANGUAGE_NONE][0]['value'];
        $data[$i]['email'] = $node->field_email_address[LANGUAGE_NONE][0]['value'];
        $data[$i]['mobile'] = $node->field_erf_mobile[LANGUAGE_NONE][0]['value'];
        $data[$i]['company'] = $node->field_erf_company_name[LANGUAGE_NONE][0]['value'];
        $data[$i]['designation'] = $node->field_erf_designation[LANGUAGE_NONE][0]['value'];
        $data[$i]['city'] = taxonomy_term_load($node->field_erf_city[LANGUAGE_NONE][0]['tid'])->name;
        
        if (!empty($node->field_erf_registration_fee[LANGUAGE_NONE])) {
          
          foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $group_user_arr) {
            $i++;
            $field_collection_id = $group_user_arr['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $data[$i]['name'] = $entity[$field_collection_id]->field_erf_gender[LANGUAGE_NONE][0]['value'] . '. ' . $entity[$field_collection_id]->field_first_name[LANGUAGE_NONE][0]['value'] . ' ' . $entity[$field_collection_id]->field_last_name[LANGUAGE_NONE][0]['value'];
            $data[$i]['email'] = $entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['mobile'] = $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['company'] = $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['designation'] = $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['city'] = taxonomy_term_load($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['tid'])->name ? taxonomy_term_load($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['tid'])->name : '-';
          }
        }
        $i++;
      }
      
      $output_header = '<div><strong>Event: ' . $node_event->title . '</strong></div>
      <table class="views-table">
      <thead>
        <tr>
        <th>Name</th>
        <th>Email</th>
        <th>Mobile</th>
        <th>Company</th>
        <th>Designation</th>
        <th>City</th>
      </tr></thead><tbody>';
      
      $output_data = '';
      for ($user_list = 0; $user_list < count($data); $user_list++) {
        $output_data .= '<tr>
            <td>' . $data[$user_list]['name'] . '</td>
            <td>' . $data[$user_list]['email'] . '</td>
            <td>' . $data[$user_list]['mobile'] . '</td>
            <td>' . $data[$user_list]['company'] . '</td>
            <td>' . $data[$user_list]['designation'] . '</td>
            <td>' . $data[$user_list]['city'] . '</td>
          </tr>';
      }
      $output_data .= '</tbody></table>';
      $output = $output_header . $output_data;
      return $output;
  }
  else {
    return 'Event is not valid! Please check your url.';
  }
}

/**
 * List of users registered for an event.
 * @return string
 */
function itg_event_registration_group_users_list() {
  $node_event = node_load(arg(2));
  
  if ($node_event->type == 'event_backend') {
    
      //Get event registered user list
      $main_user_nid_arr = itg_common_select_field_value('entity_id', 'field_data_field_story_source_id', 'field_story_source_id_value', $node_event->nid);
      
      $i = 0;
      foreach ($main_user_nid_arr as $main_user_nid) {
        $node = node_load($main_user_nid);
        $data[$i]['name'] = $node->field_erf_gender[LANGUAGE_NONE][0]['value'] . '. ' . $node->title . ' ' . $node->field_last_name[LANGUAGE_NONE][0]['value'];
        $data[$i]['email'] = $node->field_email_address[LANGUAGE_NONE][0]['value'];
        $data[$i]['mobile'] = $node->field_erf_mobile[LANGUAGE_NONE][0]['value'];
        $data[$i]['company'] = $node->field_erf_company_name[LANGUAGE_NONE][0]['value'];
        $data[$i]['designation'] = $node->field_erf_designation[LANGUAGE_NONE][0]['value'];
        $data[$i]['city'] = taxonomy_term_load($node->field_erf_city[LANGUAGE_NONE][0]['tid'])->name;
        
        if (!empty($node->field_erf_registration_fee[LANGUAGE_NONE])) {
          
          foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $group_user_arr) {
            
            $i++;
            $field_collection_id = $group_user_arr['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $data[$i]['name'] = $entity[$field_collection_id]->field_erf_gender[LANGUAGE_NONE][0]['value'] . '. ' . $entity[$field_collection_id]->field_first_name[LANGUAGE_NONE][0]['value'] . ' ' . $entity[$field_collection_id]->field_last_name[LANGUAGE_NONE][0]['value'];
            $data[$i]['email'] = $entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['mobile'] = $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['company'] = $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['designation'] = $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i]['city'] = taxonomy_term_load($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['tid'])->name ? taxonomy_term_load($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['tid'])->name : '-';
          }
        }
        $i++;
      }
      
      $output_header = '<div><strong>Event: ' . $node_event->title . '</strong></div>
      <table class="views-table">
      <thead>
        <tr>
        <th>Name</th>
        <th>Email</th>
        <th>Mobile</th>
        <th>Company</th>
        <th>Designation</th>
        <th>City</th>
      </tr></thead><tbody>';
      
      $output_data = '';
      for ($user_list = 0; $user_list < count($data); $user_list++) {
        $output_data .= '<tr>
            <td>' . $data[$user_list]['name'] . '</td>
            <td>' . $data[$user_list]['email'] . '</td>
            <td>' . $data[$user_list]['mobile'] . '</td>
            <td>' . $data[$user_list]['company'] . '</td>
            <td>' . $data[$user_list]['designation'] . '</td>
            <td>' . $data[$user_list]['city'] . '</td>
          </tr>';
      }
      $output_data .= '</tbody></table>';
      $output = $output_header . $output_data;
      return $output;
  }
  else {
    return 'Event is not valid! Please check your url.';
  }
}