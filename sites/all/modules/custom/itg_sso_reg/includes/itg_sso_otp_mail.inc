<?php

/**
 * Get Mail otp content
 * @param array $node
 * @return string
 */

function itg_sso_otp_mail_content($rand_otp, $to) {

  $mail_contents = itg_sso_notification_otp_content($rand_otp);
  $mail_content = preg_replace("/\[([^\[\]]++|(?R))*+\]/", "", $mail_contents);
  $params = array(
    'body' => $mail_content,
    'subject' => $mail_subject,
  );

//  $to = 'gourav.walia@kelltontech.com';
  $mail = drupal_mail('itg_sso_reg_user', 'send_mail_to_sso_user', $to, language_default(), $params, 'no-reply@intoday.com', TRUE);
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
function itg_sso_notification_otp_content($rand_otp) {
  return theme('itg_sso_otp_mail', array('rand_otp' => $rand_otp));
}
