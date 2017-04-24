<?php

/**
 * @file: itg_event_registration.inc
 */

/**
 * Render event registration form
 * @return string|bool
 */
function itg_event_registration_form($form, &$form_state) {
  $arg = arg();
  $event_id = itg_event_registration_get_event_nid();
  if ($arg[0] == 'event') {
    $path = drupal_lookup_path("source", $arg[1] . '/' . $arg[2]);
    $event_nid = explode('/', $path);
    $node = node_load($event_nid[1]);
    //$node = menu_get_object("node", 1, $path);

  } elseif (is_numeric($arg[1]) && $arg[0] == "node") {
    $node = node_load($arg[1]);
  } else {
    //$event_id = itg_event_registration_get_event_nid();
    $node = node_load($event_id);
  }

  $no_of_tickets = $node->field_no_of_tickets[LANGUAGE_NONE][0]['value'];
  $total_registration_users = itg_event_registration_get_total_registration($event_id); // default = 0
  $event_type = $node->field_event_type[LANGUAGE_NONE][0]['value'];
  // Check for published node, registration is allowed for published event only.
  if ($node->status == 1) {
    if ($event_type == 'invite') {
      return 'Registration is not required for event <strong>' . ucwords($node->title) . '</strong>. Please contact to India Today Group.';
    }
    else {
      // TODO: Fix date format
     // $current_date = strtotime(date('Y-m-d') . ' 00:00:00');
      $current_date = strtotime(date('Y-m-d  H:i:s'));
      $event_reg_start_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
      $event_reg_close_date = strtotime($node->field_registration_close_date[LANGUAGE_NONE][0]['value']);
      $event_close_date = strtotime($node->field_event_close_date[LANGUAGE_NONE][0]['value']);
      if ($current_date < $event_reg_start_date) {
        return itg_event_registration_get_status_message($node, 'not_started');
      } 
      elseif ($current_date > $event_reg_close_date) {
        if((($node->field_force_registration_open[LANGUAGE_NONE][0]['value']) && ($event_close_date > $current_date)) || (!$node->field_force_registration_open[LANGUAGE_NONE][0]['value']) && ($event_close_date > $current_date) && ($current_date > $event_reg_start_date)) {
          if ((1 >= $no_of_tickets) || ($total_registration_users >= $no_of_tickets)) {
            return itg_event_registration_get_status_message($node, 'tickets_not_available');
          }else{
            return itg_event_registration_get_form();
          }
        }
        else {
          return itg_event_registration_get_status_message($node, 'closed');
        }
      } 
      else {
        $total_registration_users = itg_event_registration_get_total_registration($event_id);
        if ((1 >= $no_of_tickets) || ($total_registration_users >= $no_of_tickets)) {
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
      return itg_event_registration_get_status_message($node, 'not_published');
  }
}

/**
 * Show list of users registered for an event.
 * @return string
 */
function itg_event_registration_users_list() {
  $node_event = node_load(arg(2));
  
  if ($node_event->type == 'event_backend') {
      $registered_user_nids = itg_common_select_field_value('entity_id', 'field_data_field_story_source_id', 'field_story_source_id_value', $node_event->nid);
      $i = 0;
      foreach ($registered_user_nids as $main_user_nid) {
        $node = node_load($main_user_nid);
        if (!empty($node->field_erf_registration_fee[LANGUAGE_NONE])) {
          $j = 0;
          foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $group_user_arr) {
            $field_collection_id = $group_user_arr['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $data[$i][$j]['name'] = $entity[$field_collection_id]->field_erf_name[LANGUAGE_NONE][0]['value'];
            $data[$i][$j]['email'] = $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['mobile'] = $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['company'] = $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['designation'] = $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['city'] = $entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['state'] = $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['rdate'] = $node->created ? $node->created : '-';
            if ($node->status == 0) {
             $node_status = 'Not complete'; 
            } else {
                $node_status = 'Complete';
            }
            $data[$i][$j]['status'] = $node_status;
            $j++;
          }
        }
        $i++;
      }
    

      $output_header = '<div class="dib full"><strong>Event: ' . $node_event->title . '</strong><div>'.l('Download', 'event-registration/users-list/download/' . $node_event->nid, array('attributes' => array('class' => array('btn-save', 'fright')))). '</div></div>

      <table class="views-table">
      <thead>
        <tr>
        <th>Name</th>
        <th>Email</th>
        <th>Mobile</th>
        <th>Company</th>
        <th>Designation</th>
        <th>City</th>
        <th>State</th>
        <th>Registration Date</th>
        <th>Status</th>
      </tr></thead><tbody>';
      
      $output_data = '';
      foreach($data as $user_list) {
        for($k = 0; $k < count($user_list); $k++) {
           $output_data .= '<tr>
            <td>' . $user_list[$k]['name'] . '</td>
            <td>' . $user_list[$k]['email'] . '</td>
            <td>' . $user_list[$k]['mobile'] . '</td>
            <td>' . $user_list[$k]['company'] . '</td>
            <td>' . $user_list[$k]['designation'] . '</td>
            <td>' . $user_list[$k]['city'] . '</td>
            <td>' . $user_list[$k]['state'] . '</td>            
            <td>' . format_date($user_list[$k]['rdate'], $type = 'custom_date_d_m_y_', $format = '', $timezone = NULL, $langcode = NULL) . '</td>
            <td>' . $user_list[$k]['status'] . '</td>
          </tr>';
        }
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
 * Downloads csv/xls file for list of users registered for an event.
 */
function itg_event_registration_users_list_download() {
    $node_event = node_load(arg(3));
    if ($node_event->type == 'event_backend') {
        $registered_user_nids = itg_common_select_field_value('entity_id', 'field_data_field_story_source_id', 'field_story_source_id_value', $node_event->nid);
        $file = 'users_list_csv';
        $users_list_csv = "Name" . "," . "Email" . "," . "Mobile" . "," . "Company" . "," . "Designation" . "," . "City" . "," . "State" . "," . "Registration Date" . "\n\r\0";
        $i = 0;
      foreach ($registered_user_nids as $main_user_nid) {
        $node = node_load($main_user_nid);
        if (!empty($node->field_erf_registration_fee[LANGUAGE_NONE])) {
          $j = 0;
          foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $group_user_arr) {
            $field_collection_id = $group_user_arr['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $data[$i][$j]['name'] = $entity[$field_collection_id]->field_erf_name[LANGUAGE_NONE][0]['value'];
            $data[$i][$j]['email'] = $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['mobile'] = $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['company'] = $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['designation'] = $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['city'] = $entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['state'] = $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['value'] : '-';
            $data[$i][$j]['rdate'] = $node->created ? $node->created : '-';
            $data_date = format_date($data[$i][$j]['rdate'], $type = 'custom_date_d_m_y_', $format = '', $timezone = NULL, $langcode = NULL);
            $users_list_csv .= $data[$i][$j]['name'] . "," . $data[$i][$j]['email'] . "," . $data[$i][$j]['mobile'] . ",". $data[$i][$j]['company'] . "," . $data[$i][$j]['designation'] . "," . $data[$i][$j]['city'] . "," . $data[$i][$j]['state'] . "," . $data_date . "\n\r\0";
            $j++;
          }
        }
        $i++;
      }
        $filename = $file . "_" . date("d-m-Y:i", time());
        header('Content-Description: File Transfer');
        header('Content-Type: application/force-download');
        header('Content-Disposition: attachment; filename='.$filename.'.csv');
        print $users_list_csv;
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
        if (!empty($node->field_erf_registration_fee[LANGUAGE_NONE])) {
          
          foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $group_user_arr) {
            
            $i++;
            $field_collection_id = $group_user_arr['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $data[$i]['name'] = $entity[$field_collection_id]->field_erf_name[LANGUAGE_NONE][0]['value'];
            $data[$i]['email'] = $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_email[LANGUAGE_NONE][0]['value'] : '-';
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