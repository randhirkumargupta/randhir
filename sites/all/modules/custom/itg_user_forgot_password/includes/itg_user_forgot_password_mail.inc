<?php

/**
 * Get Mail otp content
 * @param array $node
 * @return string
 */

function itg_forgot_otp_content($rand_otp, $to) {

  $mail_content = itg_forgot_notification_otp_content($rand_otp);

  $params = array(
    'body' => $mail_content,
    'subject' => 'India Today | OTP',
  );


  $mail = drupal_mail('itg_user_forgot_password', 'send_forgot_otp_mail', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
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
 * Get otp mail content
 * @param object $node
 * @return type
 */
function itg_forgot_notification_otp_content($rand_otp) {
  return theme('itg_forgot_otp_mail', array('rand_otp' => $rand_otp));
}