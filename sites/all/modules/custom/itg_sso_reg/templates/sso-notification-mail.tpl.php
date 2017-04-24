<?php 
/**
 * Template file to send mail on user Activation
 * @file: sso-notification-mail.tpl.php
 */

global $base_url;

$user_id = base64_encode($account->uid);
$url_info = base64_decode($url_info);
if (!empty($url_info)) {
  $activate_url_info = rtrim($url_info,"/");;
}
else {
  $activate_url_info = PARENT_SSO;
}
$activate_link = $activate_url_info.'/user-activate/'.$user_id;

if ($act_type != 'Password Changed') {
  $activelink = l('here', $activate_link, array('attributes' => array('target' => '_blank')));
  $get_body_val = str_replace('[itg_mail_token:itg_account_activation_link]', $activelink, $mail_body);
  $get_body = explode("<p>",$get_body_val);
  unset($get_body[0]);
} else {
  $get_body = explode("<p>",$mail_body);
  unset($get_body[0]);
}
?> 

<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Account Activation Mail</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">
      <?php 
      foreach ($get_body as $bk => $bv) {
        print '<tr> <td style="padding: 10px 20px;">' . $bv . '</td></tr>';
      } 
      ?>
      <tr>
        <td style="padding: 10px 20px;">Thanks,</td>
      </tr>
      <tr>
        <td style="padding: 0px 20px;">India Today Group</td>
      </tr>
    </table>
  </body>
</html>
