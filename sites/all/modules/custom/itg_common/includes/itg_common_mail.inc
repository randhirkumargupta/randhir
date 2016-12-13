<?php

/**
 * @file
 *   Custom mail formating file.
 */

/**
 * Get Mail content
 * @param array $data
 *   Personalized mail content.
 * @param string $to
 *   To email address.
 * @param string $key
 *   Mail specific key.
 * @param string $subject
 *   Mail subject text.
 *
 * @return string
 *   Modified mail content.
 */
function itg_common_get_mail_content($data, $to, $key = NULL, $subject = NULL) {
  $mail_content = itg_common_notification_mail_content($data, $key);
  $params = array(
    'body' => $mail_content,
    //'subject' => 'India Today | Refer a friend',
    'subject' => $subject,
  );
  //$mail = drupal_mail('itg_common', 'refer_a_friend', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  $mail = drupal_mail('itg_common', $key, $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
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
 * Implement mail template for specific mail.
 *
 * @param array $data
 *   Mixed array containing mail template data.
 * @param string $key
 *   Specific key for specific mail.
 *
 * @return
 *   Themed mail template data.
 */
function itg_common_notification_mail_content($data , $key) {  
  switch ($key) {
    case 'refer_friend':
      return theme('itg_personalization_refer_friend_mail', array('data' => $data));
      break;
    case 'lrp_point':      
      return theme('itg_loyalty_point_notification', array('data' => $data));    
      break;
    case 'personalization_mail':
      return theme('itg_personalization_personalization_mail', array('data' => $data));
      break;
  }
  
}
