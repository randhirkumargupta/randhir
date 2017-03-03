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
  
  //Mail content: In case of "insert", "update" and "association"
  if ($source == 'insert') {
    $mail_content = itg_print_team_approval_mail_content($node);
    $user_emails = itg_print_team_get_approval_user_emails('approval_users');
    $user_email_ids = implode(",", $user_emails);
  }
  elseif($source == 'update') {
    $mail_content = itg_print_team_status_mail_content($node);
    $user = user_load($node->uid);
    $user_email_ids = $user->mail;
  }
  else {
    $mail_content = itg_print_team_association_mail_content($node, $op_type);
    $user_emails = itg_print_team_get_approval_user_emails('association_users');
    $user_email_ids = implode(",", $user_emails);
  }

  // Array of email subject and body 
  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today | ' . $node->title . ' status!',
  );

  // Send mail function
  // for code email
  //drupal_mail('itg_print_team_status', 'print_team_mail', $user_email_ids, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
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
  $params = array(
      'body' => $mail_content,
      'subject' => 'India Today | ' . $node->title . ' status!',
  );

  // Send notification mail
  $mail = drupal_mail('itg_print_team_status', 'print_team_mail', $user_email_ids, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  
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
  $query->fields('u', array('uid'))
          ->fields('u', array('mail'))
          ->fields('u', array('name'))
          ->condition('r.name', $roles, 'IN');
  $result = $query->execute();
  
  while ($record = $result->fetchAssoc()) {
    $user_list[] = $record['mail'];
  }
  
  return $user_list;
}
