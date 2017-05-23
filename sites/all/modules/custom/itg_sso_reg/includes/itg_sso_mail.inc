<?php
/**
 * Get Mail content
 * @param array $account
 * @param string $to
 * @return string
 */
function itg_sso_get_mail_content($account, $to, $url_info) {
  
    if (function_exists('itg_mail_templates_get_mailcontent')) {
      if (is_string($account) && $account == 'Password Changed'){
        $action = 'Password Changed';
      } else {
        $action = 'Sign up';
      }
      
      $mail_data = itg_mail_templates_get_mailcontent($action);
      $name = $mail_data->field_mail_templates_category[LANGUAGE_NONE][0]['value'];

      if ($name == 'password_changed') {
        $mail_subject = $mail_data->field_mail_subject_password_chan[LANGUAGE_NONE][0]['value'];
        $mail_body = $mail_data->field_mail_body_password_changed[LANGUAGE_NONE][0]['value'];
      } else {
        $mail_subject = $mail_data->field_mail_subject_sign_up[LANGUAGE_NONE][0]['value'];
        $mail_body = $mail_data->field_mail_body_sign_up[LANGUAGE_NONE][0]['value'];
      }
    }
    $mail_content = itg_sso_notification_mail_content($account, $url_info, $mail_body, $name);

    $params = array(
      'body' => $mail_content,
      'subject' => $mail_subject,
    );
    $mail = drupal_mail('itg_sso_reg_user', 'send_mail_to_sso_user', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
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
 * Get approval mail content
 * @param object $node
 * @return type
 */
function itg_sso_notification_mail_content($account, $url_info, $mail_body, $name) {
  return theme('itg_sso_notification_mail', array('account' => $account, 'url_info' => $url_info, 'mail_body' => $mail_body, 'act_type' => $name));
}