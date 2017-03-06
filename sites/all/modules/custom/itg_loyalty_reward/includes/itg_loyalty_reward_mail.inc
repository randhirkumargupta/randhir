<?php

/**
 * Send mail functions related to loyalty and rewards
 * @file itg_loyalty_reward_mail.inc
 */

/**
 * Send mail to editor and siteadmin on expiration of product
 * @param int $nid
 */
function itg_loyalty_reward_send_mail_product_expiration($nid ,$node_user) {
  $node = node_load($nid);
  $mail_content = itg_loyalty_reward_product_expiration_mail_content($node);
  $user_emails = itg_loyalty_reward_product_expiration_user_emails('association',$node_user);
  $user_email_ids = implode(", ", $user_emails);
  
  // Array of email subject and body 
  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today | Product Expiration Status!',
  );
  // for code email
  // Send product expiration notification mail
  //$mail = drupal_mail('itg_loyalty_reward_product_expiration', 'itg_loyalty_reward', $user_email_ids, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  // Update mail status after sending notification 
  /*if ($mail['result']) {
    db_update('itg_loyalty_reward_cron')
        ->fields(array(
          'status' => 1,
        ))
        ->condition('nid', $nid, '=')
        ->execute();
  }*/
}

/**
 * Implements hook_mail
 * @param string $key
 * @param string $message
 * @param array $params
 */
function itg_loyalty_reward_product_expiration_mail($key, &$message, $params) {
  switch ($key) {
    case 'itg_loyalty_reward':
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
 * Get product expiration notification mail content
 * @param object $node
 * @return type
 */
function itg_loyalty_reward_product_expiration_mail_content($node) {
  return theme('itg_loyalty_reward_product_notification_mail', array('node' => $node));
}

/**
 * Get users email of site admin and editor
 * @return array
 */
function itg_loyalty_reward_product_expiration_user_emails($user_type,$node_user) {
  $user_list = array();
if(!empty($node_user))
{
    $user_list[] = $node_user;
}
  $roles = array('Site Admin', 'Editor');

  // Fetch name, mail and uid of all users having role Site Admin & Editor
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
