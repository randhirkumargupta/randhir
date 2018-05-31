<?php

/**
 * Send mail related to print team
 * @file print_team_mail.inc
 */

/**
 * Send mail to user, when idea status is updated by admin
 * @param object $node
 */
function itg_print_team_send_idea_status_mail($node, $source, $op_type = FALSE) {
  global $base_url;
  $idea_link = l("here", $base_url.'/node/'.$node->nid.'/edit');
  //Mail content: In case of "insert", "update" and "association"
  if ($source == 'insert') {
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      $mail_template_data = itg_mail_templates_get_mailcontent($node);
      $mail_subject = str_replace('[itg_mail_token:itg_node_title]', $node->title, $mail_template_data->field_mail_subject_print_t[LANGUAGE_NONE][0]['value']);
      $body_data = $mail_template_data->field_mail_body_print_team[LANGUAGE_NONE][0]['value'];
      $body_datas = str_replace('[itg_mail_token:itg_node_title]', $node->title, $body_data);
      $mail_content = str_replace('Click here for more details', 'Click ' . $idea_link . ' for more details', $body_datas);
    }
    $user_emails = itg_print_team_get_approval_user_emails('approval_users');
    $umail = array_unique($user_emails);
    $user_email_ids = implode(",", $umail);
  }
  elseif($source == 'update') {
    $mail_content = itg_print_team_status_mail_content($node);
    $user = user_load($node->uid);
    if ($user->status == 1) {
      if (!empty($node->field_add_member[LANGUAGE_NONE])) {
        foreach ($node->field_add_member[LANGUAGE_NONE] as $mk => $mv){
          $umails[] = db_query("SELECT mail from {users} WHERE uid = :uid ", array(":uid" => $mv['target_id']))->fetchField();
        }
        $mail_content = itg_print_team_status_mail_content($node);
      }
      $current_mail[] = $user->mail;
      $user_email_id = array_merge($current_mail, $umails);
    }
    
    $rid = array(PHOTO_COORDINATOR, PHOTO_HEAD, DESIGN_HEAD, COPY_DESK, DESIGNER, PHOTOGRAPHER);
    $user_email = get_email_by_roll($rid);
    if (!empty($user_email_id) && is_array($user_email_id)) {
      $all_mails = array_merge($user_email_id, $user_email);
    } else {
      $all_mails = $user_email;
    }
    $umail = array_unique($all_mails);
    $user_email_ids = implode(",", $umail);
  }
  else {
    $mail_content = itg_print_team_association_mail_content($node, $op_type);
    $user_emails = itg_print_team_get_approval_user_emails('association_users');
    $umail = array_unique($user_emails);
    $user_email_ids = implode(",", $umail);
  }

  // Array of email subject and body 
  $mail_contents = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_content);
  $params = array(
    'body' => $mail_contents,
    'subject' => $mail_subject,
  );
  $mail = drupal_mail('itg_print_team_status', 'print_team_mail', $user_email_ids, language_default(), $params, variable_get('site_mail', 'care@intoday.in'), TRUE);
  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = 'Failed to send the email!';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}

/**
 * Send mail to notify user for expiration of his story
 * @param int $nid
 */
function itg_print_team_send_mail_for_notification($nid){
  $node = node_load($nid);
  $mail_content = itg_print_team_notification_mail_content($node);
  $user = user_load($node->uid);
  $user_email_ids = $user->mail;

  // Array of email subject and body 
  $mail_contents = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_content);
  $params = array(
      'body' => $mail_contents,
      'subject' => 'India Today | ' . $node->title . ' status!',
  );

  // Send notification mail
  $mail = drupal_mail('itg_print_team_status', 'print_team_mail', $user_email_ids, language_default(), $params, variable_get('site_mail', 'care@intoday.in'), TRUE);
  
  //Update mail status after sending notification 
  if ($mail['result']) {
    db_update('itg_cron_print_team')
            ->fields(array(
                'status' => 1,
            ))
            ->condition('nid', $nid, '=')
            ->execute();
  }
}

/**
 * Implements hook_mail
 * @param string $key
 * @param string $message
 * @param array $params
 */
function itg_print_team_status_mail($key, &$message, $params) {
  switch ($key) {
    case 'print_team_mail':
      $headers = array(
        'MIME-Version' => '1.0',
        'Content-Type' => 'text/html; charset=UTF-8; format=flowed; delsp=yes',
        'Content-Transfer-Encoding' => '8Bit',
        'X-Mailer' => 'Drupal'
      );
      $message['subject'] = $params['subject'];
      $message['body'][] = $params['body'];
      foreach ($headers as $key => $value) {
        $message['headers'][$key] = $value;
      }
      break;
  }
}

/**
 * Get idea status mail content
 * @param object $node
 * @return type
 */
function itg_print_team_status_mail_content($node) {
  return theme('itg_print_team_idea_status_mail', array('node' => $node));
}

/**
 * Get idea approval mail content
 * @param object $node
 * @return type
 */
function itg_print_team_approval_mail_content($node) {
  return theme('itg_print_team_idea_approval_mail', array('node' => $node));
}

/**
 * Get mail content after association from issue and magazine
 * @param object $node
 * @return type
 */
function itg_print_team_association_mail_content($node, $op_type = FALSE) {
  return theme('itg_print_team_idea_association_mail', array('node' => $node, 'op_type' => $op_type));
}

/**
 * Get notification mail content
 * @param object $node
 * @return type
 */
function itg_print_team_notification_mail_content($node) {
  return theme('itg_print_team_notification_mail', array('node' => $node));
}

/**
 * Get user email of idea approval team
 * 
 * @return array
 *    an array of users uid, email and name
 */
function itg_print_team_get_approval_user_emails($user_type) {
  $user_list = array();
  
  if ($user_type == 'approval_users') {
    $roles = array('Site Admin', 'Co-ordinator', 'Editor', 'Section Editor/Anchor', 'Knowledge Centre');
  }
  else {
    $roles = array('Photo Coordinator', 'Photo Head', 'Design Head', 'Copy Desk');
  }
   
  //Fetch name, mail and uid of all users having role Coordinator, editor and Anchor
  $query = db_select('users_roles', 'ur');
  $query->join('users', 'u', 'u.uid = ur.uid');
  $query->join('role', 'r', 'r.rid = ur.rid');
  $query->fields('u', array('uid', 'status'))
          ->fields('u', array('mail'))
          ->fields('u', array('name'))
          ->condition('u.status', 1)
          ->condition('r.name', $roles, 'IN');
  $result = $query->execute();
  
  while ($record = $result->fetchAssoc()) {
    $user_list[] = $record['mail'];
  }
  
  return $user_list;
}
