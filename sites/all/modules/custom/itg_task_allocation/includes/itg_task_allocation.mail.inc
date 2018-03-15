<?php
/**
 * Get Mail content
 * @param type $to
 * @return 
 */
function expiredmail_mail_content($to) {
  global $base_url;
  $task_subject = t('A task has been expired that was created by you');
  $subject = t('Task Expired');
  
  if (isset($user->uid) && !empty($user->uid) && ($user->uid > 0)) {
    $node_url = l('URL', $base_url.'/node/'.$var->nid);
  } else {
    $node_url = t('URL', array('@login-link' => $base_url . '/user/login?destination=node/'.$var->nid));
  }

  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
              <html xmlns:v="urn:schemas-microsoft-com:vml">
                <head><title></title></head>
                <body style="margin:0; padding:0;">';
  $content .= 'Dear Team,';
  $content .= '<br /><br />' . $task_subject;
  $content .= '<br />' . $node_url;
  $content .= '</body>';
  $content .= '</html>';
  $params = array(
    'body' => $content,
    'subject' => $subject,
  );
  $mail = drupal_mail('itg_task_allocation', 'send_mail_to_task', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = t('Failed to send the email!');
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}

/**
 * Custom method for expired task.
 */
function itg_task_allocation_expiredmail() {
  $current_time = date('Y-m-d H:i:s');
  $query = db_select('field_data_field_task_finish_date_and_time', 'f');
  $query->condition('f.field_task_finish_date_and_time_value', $current_time, '<=');
  $query->join('node', 'n', 'n.nid = f.entity_id');
  $query->leftjoin('task_allocation', 'tm', 'n.nid = tm.node_id');
  $query->join('users', 'u', 'u.uid = n.uid');
  $query->fields('u', array('mail'));
  $query->fields('n', array('nid'));
  $query->fields('tm', array('node_id'));
  $result = $query->execute();
  foreach ($result as $val) {
    if ($val->node_id == '') {
      $value .= $val->mail . ',';
    }
    if ($val->node_id != $val->nid) {
      $value_id .= $val->nid . ',';
    }
  }
  $node_ids = trim($value_id, ",");
  $node_id = explode(",", $node_ids);
  foreach ($node_id as $value) {
    $query1 = db_insert('task_allocation');
    $query1->fields(array('node_id' => $value))->execute();
  }

  $high_level_user = trim($value, ",");
  expiredmail_mail_content($high_level_user);
}

/**
 * Get Mail content
 * @global String $base_url
 * @param type $node
 * @param type $event
 * @param type $to
 * @return 
 */
function task_get_mail_content($node, $event, $to, $user_name) {
  global $base_url;
  $your_idea = $node->field_task_task_idea[LANGUAGE_NONE][0]['value'];
  $finish_date = date("d/m/Y H:i:s", strtotime($node->field_task_finish_date_and_time[LANGUAGE_NONE][0]['value']));

  if ($event == 'create') {
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_data = itg_mail_templates_get_mailcontent($node, 'create');
      $task_subject = $mail_data->field_mail_subject_task_idea[LANGUAGE_NONE][0]['value'];
    }
  }
  else if ($event == 'update') {
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_data = itg_mail_templates_get_mailcontent($node, 'update');
      $task_subject = $mail_data->field_mail_subject_task_idea[LANGUAGE_NONE][0]['value'];
    }
  }
  else if ($event == 'comment') {
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_data = itg_mail_templates_get_mailcontent($node, 'comment');
      $task_subject = $mail_data->field_mail_subject_task_idea[LANGUAGE_NONE][0]['value'];
    }
  }
  if ($event != 'comment') {
    $body = str_replace('[itg_mail_token:itg_node_title]', l($node->title, $base_url . '/node/'.$node->nid), $mail_data->field_mail_subject_body[LANGUAGE_NONE][0]['value']);
    $assigned_by = str_replace('[itg_mail_token:itg_loggedin_user]', $user_name, $body);
    $idea = str_replace('[itg_mail_token:itg_node_body]', $your_idea, $assigned_by);
    $idea_last_date = str_replace('[itg_mail_token:itg_task_date_time]', $finish_date, $idea);
    $mail_content = $idea_last_date;
  } else {
    $body = str_replace('[itg_mail_token:itg_node_title]', l($node->title, $base_url . '/node/'.$node->nid), $mail_data->field_mail_subject_body[LANGUAGE_NONE][0]['value']);
    $assigned_by = str_replace('[itg_mail_token:itg_task_comment]', $node->comment_value, $body);
    $mail_content = $assigned_by;
  }
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
              <html xmlns:v="urn:schemas-microsoft-com:vml">
                <head><title></title></head>
                <body style="margin:0; padding:0;">';
  $content .= $mail_content;
  $content .= '</body>';
  $content .= '</html>';
  $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $content);
  $params = array(
    'body' => $mail_content,
    'subject' => $task_subject,
  );
  $mail = drupal_mail('itg_task_allocation', 'send_mail_to_task', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = 'Failed to send the email!';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}