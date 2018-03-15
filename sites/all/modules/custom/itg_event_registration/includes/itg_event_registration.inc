<?php

/**
 * @file: itg_event_registration.inc
 */

/**
 * Render event registration form
 * @return string|bool
 */
function itg_event_registration_form($form, &$form_state) {
  global $base_url;
  $arg = arg();
  $node = itg_event_backend_get_event_node('node');
  $event_close_date = strtotime($node->field_event_close_date[LANGUAGE_NONE][0]['value']);
  $current_date_time = strtotime(date('Y-m-d  H:i:s'));
  $event_alias = $base_url . '/' . $arg[1] . '/' . $arg[2] . '/' . $arg[3];
  $_SESSION['recent_event_payment_url'] = $event_alias;

  $no_of_tickets = $node->field_no_of_tickets[LANGUAGE_NONE][0]['value'];
  $total_registration_users = itg_event_registration_get_total_registration($event_id); // default = 0
  $event_type = $node->field_event_type[LANGUAGE_NONE][0]['value'];
  // Check for published node, registration is allowed for published event only.
  if ($node->status == 1) {
    if ($current_date_time < $event_close_date) {
      if ($event_type == 'invite') {
        return itg_event_registration_get_status_message($node, 'invite');
      }
      else {
        $current_date = strtotime(date('Y-m-d  H:i:s'));
        $event_reg_start_date = strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value']);
        $event_reg_close_date = strtotime($node->field_registration_close_date[LANGUAGE_NONE][0]['value']);
        $force_registration_flag = $node->field_force_registration_open[LANGUAGE_NONE][0]['value'];
        if ($current_date < $event_reg_start_date && !empty($event_reg_start_date)) {
          return itg_event_registration_get_status_message($node, 'not_started');
        }
        elseif ($current_date > $event_reg_close_date && !empty($event_reg_close_date)) {
          if ((($force_registration_flag) && ($event_close_date > $current_date)) || (!$force_registration_flag) && ($event_close_date > $current_date) && ($current_date > $event_reg_start_date)) {
            if ((1 > $no_of_tickets) || ($total_registration_users >= $no_of_tickets)) {
              return itg_event_registration_get_status_message($node, 'tickets_not_available');
            }
            elseif ($current_date > $event_reg_close_date && $force_registration_flag == 0) {
              return itg_event_registration_get_status_message($node, 'closed');
            }
            else {
              return itg_event_registration_get_form();
            }
          }
          else {
            return itg_event_registration_get_status_message($node, 'closed');
          }
        }
        else {
          $total_registration_users = itg_event_registration_get_total_registration($event_id);
          if ((1 > $no_of_tickets) || ($total_registration_users >= $no_of_tickets)) {
            return itg_event_registration_get_status_message($node, 'tickets_not_available');
          }
          else {
            return itg_event_registration_get_form();
          }
        }
      }
    }
    else {
      return itg_event_registration_get_status_message($node, 'closed');
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
          $data[$i][$j]['country'] = $entity[$field_collection_id]->field_event_country[LANGUAGE_NONE][0]['value'] ? $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['value'] : '-';
          $data[$i][$j]['rdate'] = $node->created ? $node->created : '-';
          if ($node->status == 0) {
            $node_status = t('Registration cancelled');
          }
          else {
            $node_status = t('Registered');
          }
          $data[$i][$j]['status'] = $node_status;
          $data[$i][$j]['payment'] = $node->field_erf_payment_gateway['und'][0]['value'];
          $j++;
        }
      }
      $i++;
    }

    $output_header = '<div class="dib full"><strong>Event: ' . $node_event->title . '</strong><div>' . l('Download', 'event-registration/users-list/download/' . $node_event->nid, array('attributes' => array('class' => array('btn-save', 'fright')))) . '</div></div>

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
        <th>Country</th>
        <th>Registration Date</th>
        <th>Payment Mode</th>
        <th>Status</th>
      </tr></thead><tbody>';

    $output_data = '';
    foreach ($data as $user_list) {
      for ($k = 0; $k < count($user_list); $k++) {
        $output_data .= '<tr>
            <td>' . $user_list[$k]['name'] . '</td>
            <td>' . $user_list[$k]['email'] . '</td>
            <td>' . $user_list[$k]['mobile'] . '</td>
            <td>' . $user_list[$k]['company'] . '</td>
            <td>' . $user_list[$k]['designation'] . '</td>
            <td>' . $user_list[$k]['city'] . '</td>
            <td>' . $user_list[$k]['state'] . '</td>            
            <td>' . $user_list[$k]['country'] . '</td>            
            <td>' . format_date($user_list[$k]['rdate'], $type = 'custom_date_d_m_y_', $format = '', $timezone = NULL, $langcode = NULL) . '</td>
            <td>' . $user_list[$k]['payment'] . '</td>            
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
          $users_list_csv .= $data[$i][$j]['name'] . "," . $data[$i][$j]['email'] . "," . $data[$i][$j]['mobile'] . "," . $data[$i][$j]['company'] . "," . $data[$i][$j]['designation'] . "," . $data[$i][$j]['city'] . "," . $data[$i][$j]['state'] . "," . $data_date . "\n\r\0";
          $j++;
        }
      }
      $i++;
    }
    $filename = $file . "_" . date("d-m-Y:i", time());
    header('Content-Description: File Transfer');
    header('Content-Type: application/force-download');
    header('Content-Disposition: attachment; filename=' . $filename . '.csv');
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
    return t('Event is not valid! Please check your url.');
  }
}

function _get_payment_gateway_name($nid) {
  return $nid;
}

/**
 * callback for all the story of title
 * @param $title
 */
function itg_event_get_content_title_autocomplete($title) {
  $current_date_time = date('Y-m-d H:i:s');
  if (strlen(trim($title)) > 0) {
    $event_type = arg(1);
    $options = '';
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->fields('n', array('title'));
    $query->condition('n.title', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', 'event_backend', '=');
    if ($event_type == 'active') {
      $query->leftjoin('field_data_field_step_completion', 'step_complete', 'step_complete.entity_id = n.nid');
      $query->leftjoin('field_data_field_event_close_date', 'close_date', 'close_date.entity_id=n.nid');
      $query->leftjoin('field_data_field_event_start_date', 'start_date', 'start_date.entity_id=n.nid');
      $query->condition('step_complete.field_step_completion_value', 2, '=');
      $query->condition('close_date.field_event_close_date_value', $current_date_time, '>=');
      $query->condition('start_date.field_event_start_date_value', $current_date_time, '<=');
      $query->isNotNull('step_complete.field_step_completion_value');
    } elseif($event_type == 'draft') {
      $query->leftjoin('field_data_field_step_completion', 'step_complete', 'step_complete.entity_id = n.nid');
      $query->condition('step_complete.field_step_completion_value', 0, '=');   
    }elseif($event_type == 'close') {
      $query->leftjoin('field_data_field_step_completion', 'step_complete', 'step_complete.entity_id = n.nid');
      $query->leftjoin('field_data_field_event_close_date', 'close_date', 'close_date.entity_id=n.nid');
      $query->condition('step_complete.field_step_completion_value', 2, '=');
      $query->condition('close_date.field_event_close_date_value', $current_date_time, '<=');
      $query->isNotNull('step_complete.field_step_completion_value');
    }
    $query->range(0, 20);
    $result = $query->execute();
    while ($record = $result->fetchAssoc()) {
      $options[$record['title']] = $record['title'];
    }
    drupal_json_output($options);
  }
}
