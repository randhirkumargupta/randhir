<?php
/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_ugc_get_mail_content($uname, $type, $status, $to) {
  global $base_url;

  // todo: move to email template
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
<head>
    <title></title>
</head>
<body style="margin:0; padding:0;">
      <table cellpadding="0" cellspacing="0" width="760" align="center"><tr><td>Dear, ' .$uname.'</td></tr>
      
      <tr><td></td></tr>
      <tr><td>Your  ' . $type . ' content has been '.$status.' by the reviewer.</td></tr>
      <tr><td></td></tr>
      <tr><td>Thanks,</td></tr>
      <tr><td>India Today Team</td></tr></table>
</body></html>';

  $params = array(
      'body' => $content,
      'subject' => 'India Today | UGC Content '.$status.'!',
    );

   
    $mail = drupal_mail('itg_ugc_user', 'send_'.$status.'_mail_to_ugc_user', $to, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    if ($mail['result']) {
      return TRUE;
    }
    else {
      $error_msg = 'Failed to send the email!';
      watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
      return FALSE;
    }
  
}