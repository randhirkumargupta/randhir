<?php

/**
* callback for the reported to username
*  
*/

function itg_task_allocation_autocomplete($title) {
    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('users', 'u');
        $query->fields('u', array('mail', 'created'));
        $query->condition('mail', '%' . $title . '%', 'LIKE');
        $query->condition('u.status', '1', '=');
        $query->range(0, 20);

        $result = $query->execute();
        while ($record = $result->fetchAssoc()) {
            $options[$record['mail']] = $record['mail'];
        }
        drupal_json_output($options);
    }
}

/**
 * Display task notification of user.    
 */
function get_task_notification_of_user() {
  global $user;
  $string = '';
  if (function_exists('get_idea_notification_of_user')) {
    $idea_data = get_idea_notification_of_user();
  }
  if (!empty($idea_data)) {
    $string.=$idea_data;
  }
  $string.="<ul>";
  $start = date('Y-m-d H:i');
  $end = date('Y-m-d H:i', strtotime('+1 day'));
  $query = db_select('node', 'n');
  $query->fields('n', array('title'));
  $query->fields('n', array('nid'));
  $query->join('field_data_field_task_comment_change_status', 's', 'n.nid = s.entity_id');
  $query->join('field_data_field_task_finish_date_and_time', 'f', 'n.nid = f.entity_id');
  $query->join('field_data_field_task_team_member', 'tm', 'n.nid = tm.entity_id');
  $query->fields('s', array('field_task_comment_change_status_value'));
  $query->condition('f.field_task_finish_date_and_time_value', $start, '>');
  $query->condition('f.field_task_finish_date_and_time_value', $end, '<=');
  $query->condition('s.field_task_comment_change_status_value', 'open', '=');
  $query->condition('tm.field_task_team_member_target_id', $user->uid, '=');
  $query->condition('n.type', 'task_idea_allocation_tracking', '=');
  $result = $query->execute();
  foreach ($result as $value) {
    $string .= '<li>' . l("your task " . $value->title . " is going to expire", 'node/' . $value->nid) . '</li>';
  }
  $string .= "</ul>";
  print $string;
  drupal_exit();
}

/**
 * Expire task acc to date and send mail to the author of node.   
 */
function itg_task_allocation_expirestatus_enddatemail() {
    $current_time = date('Y-m-d H:i:s');  
  
    $query = db_select('node', 'n');
    $query->leftjoin('field_data_field_task_finish_date_and_time', 'f', 'n.nid = f.entity_id');
    $query->leftjoin('field_data_field_task_comment_change_status', 's', 'n.nid = s.entity_id');
    $query->leftjoin('field_data_field_task_team_member', 'ttm', 'n.nid = ttm.entity_id');
    $query->join('users', 'u', 'u.uid = n.uid');
    $query->join('users', 'ur', 'ur.uid = ttm.field_task_team_member_target_id');
    $query->fields('n', array('nid'));
    $query->condition('n.status', 1, '=');
    $query->condition('n.type', 'task_idea_allocation_tracking', '=');
    $query->fields('f', array('field_task_finish_date_and_time_value'));
    $query->fields('s', array('field_task_comment_change_status_value'));
    $query->fields('u', array('mail'));
    $query->fields('ur', array('mail'));
    $query->condition('s.field_task_comment_change_status_value', 'open', '=');
    $query->condition('f.field_task_finish_date_and_time_value', $current_time, '<=');
    $result = $query->execute();
    foreach ($result as $value) {   
      $node = node_load($value->nid);
      $node->field_task_comment_change_status['und'][0]['value'] = 'expired';
      field_attach_update('node', $node);
      expiredtask_authormail_content($value, 'task_expiry', 'task_idea_allocation_tracking');
    }
}

/**
 * Get Mail content
 * @param type $to
 * @return 
 */
function expiredtask_authormail_content($var, $expiry_task, $task_type) {
  if (function_exists("itg_mail_templates_get_mailcontent")) {
    $get_mail_data = itg_mail_templates_get_mailcontent($task_type, $expiry_task);
    $subject = $get_mail_data->field_mail_subject_task_idea[LANGUAGE_NONE][0]['value'];
  }

  global $base_url, $user;
  if (!empty($var->ur_mail) || !empty($var->mail)) {
    if (isset($user->uid) && !empty($user->uid) && ($user->uid > 0)) {
      $node_url = l('URL', $base_url.'/node/'.$var->nid);
    } else {
      $node_url = t('<a href="@login-link">URL</a>', array('@login-link' => $base_url . '/user/login?destination=node/'.$var->nid));
    }
    $node_title = itg_common_get_node_title($var->nid);

    $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
                <html xmlns:v="urn:schemas-microsoft-com:vml">
                  <head><title></title></head>
                  <body style="margin:0; padding:0;">';

    if (array_key_exists('ur_mail', $var)) {
      $body = $get_mail_data->field_mail_subject_body[LANGUAGE_NONE][0]['value'];
      $get_title = str_replace('[itg_mail_token:itg_node_title]', $node_title, $body);
      $body_data = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $get_title);
      $content .= $body_data;
      $content .= '</body>';
      $content .= '</html>';
      $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $content);
      $params = array(
          'body' => $mail_content,
          'subject' => $subject,
      );
      $to_mail = $var->ur_mail;
      $mail = drupal_mail('itg_task_allocation', 'exp_task_rem', $to_mail, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
      if ($mail['result']) {
        return TRUE;
      } else {
        $error_msg = 'Failed to send the email!';
        watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
        return FALSE;
      }
    }
    
    if (array_key_exists('mail', $var)) {
      $body = $get_mail_data->field_mail_body_task_idea_assign[LANGUAGE_NONE][0]['value'];
      $get_title = str_replace('[itg_mail_token:itg_node_title]', $node_title, $body);
      $body_data = str_replace('[itg_mail_token:itg_node_title_link]', $node_url, $get_title);
      $content .= $body_data;
      $content .= '</body>';
      $content .= '</html>';
      $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $content);
      $params = array(
          'body' => $mail_content,
          'subject' => $subject,
      );
      $to_mail = $var->mail;
      $mail = drupal_mail('itg_task_allocation', 'exp_task_rem', $to_mail, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
      if ($mail['result']) {
        return TRUE;
      } else {
        $error_msg = 'Failed to send the email!';
        watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
        return FALSE;
      }
    }
  }
}
