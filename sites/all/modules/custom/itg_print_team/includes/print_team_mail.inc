<?php

/**
 * Send mail related to print team
 * @file print_team_mail.inc
 */

/**
 * Send mail to user, when idea status is updated by admin
 * @param object $node
 */
function itg_print_team_send_idea_status_mail($node, $source){
  
  if($source == 'insert'){
    $mail_content = itg_print_team_approval_mail_content($node);
    $user_email_ids = itg_print_team_get_approval_user_emails();
  }
  else {
    $mail_content = itg_print_team_status_mail_content($node);
    $user = user_load($node->uid);
    $user_email_ids = $user->mail;
  }

  //Array of email subject and body 
  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today | '.$node->title .' status!',
  );

  $mail = drupal_mail('itg_print_team_status', 'print_team_mail', $user_email_ids, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if($mail['result']){
    drupal_set_message(t('Mail has been sent successfully!'));
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
function itg_print_team_status_mail_content($node){
  return theme('itg_print_team_idea_status_mail', array('node' => $node));
}

/**
 * Get idea approval mail content
 * @param object $node
 * @return type
 */
function itg_print_team_approval_mail_content($node){
  return theme('itg_print_team_idea_approval_mail', array('node' => $node));
}

/**
 * Get user email of idea approval team
 * 
 * @return array
 *    an array of users uid, email and name
 */
function itg_print_team_get_approval_user_emails(){
  $user_list = array();
  $roles = array('Co-ordinator', 'Editor', 'Section Editor/Anchor');
  $query = db_select('users_roles', 'ur')
          ->join('users', 'u', 'u.uid = ur.uid')
          ->join('role', 'r', 'r.rid = ur.rid')
          ->fields('u', array('uid'))
          ->fields('u', array('mail'))
          ->fields('u', array('name'))
          ->condition('r.name', $roles, 'IN');

  $result = $query->execute()->fetchObject();

  if ($result) {
    foreach ($result as $row) {
      $uid = $row->uid;
      $user_list[$uid]['mail'] = $row->mail;
      $user_list[$uid]['name'] = $row->name;
      $user_list[$uid]['uid'] = $uid;
    }
  }

  return $user_list;
}
