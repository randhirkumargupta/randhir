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
 *
 * @return string
 *   Modified mail content.
 */
function itg_common_get_mail_content($data, $to) {
  $mail_content = itg_common_notification_mail_content($data);
  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today | Refer a friend',
  );
  $mail = drupal_mail('itg_common', 'refer_a_friend', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
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
 * Get approval mail content.
 * @param array $node
 * @return array
 */
function itg_common_notification_mail_content($data) {
  return theme('itg_personalization_refer_friend_mail', array('data' => $data));
}
