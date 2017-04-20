<?php

/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_ugc_get_mail_content($uname, $type, $status, $to) {

  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $mail_data = itg_mail_templates_get_mailcontent($type, 'UGC', $status);
    $template_status = $mail_data->field_ugc_comments_status[LANGUAGE_NONE][0]['value'];
    $mail_subject = $mail_data->field_mail_subject[LANGUAGE_NONE][0]['value'];
    $mail_body_author = str_replace('[itg_mail_token:itg_author]', $uname, $mail_data->field_mail_body_ugc[LANGUAGE_NONE][0]['value']);
    $mail_content = str_replace('[itg_mail_token:itg_node_type]', $type, $mail_body_author);
  }

  global $base_url;

  // todo: move to email template
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
              <html xmlns:v="urn:schemas-microsoft-com:vml"><head><title></title></head><body style="margin:0; padding:0;"><table cellpadding="0" cellspacing="0" width="760" align="center">';
  $content .= $mail_content;
  $content .= '<tr><td>Thanks,</td></tr>';
  $content .= '<tr><td>India Today Team</td></tr>';
  $content .= '</table></body></html>';

  $params = array(
      'body' => $content,
      'subject' => 'India Today | UGC Content ' . $status . '!',
  );

  $mail = drupal_mail('itg_ugc_user', 'send_' . $status . '_mail_to_ugc_user', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
  if ($mail['result']) {
    return TRUE;
  } else {
    $error_msg = 'Failed to send the email!';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}
