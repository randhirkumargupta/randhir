<?php 
/**
 * Template file to send mail on user Activation
 * @file: sso-notification-mail.tpl.php
 */

global $base_url, $user;

if (is_string($account) && $account == 'Password Changed'){
  $get_user = user_load($user->uid);
  $fname = $get_user->field_first_name[LANGUAGE_NONE][0]['value'];
  $lname = $get_user->field_last_name[LANGUAGE_NONE][0]['value'];
} else {
  $fname = $account->field_first_name[LANGUAGE_NONE][0]['value'];
  $lname = $account->field_last_name[LANGUAGE_NONE][0]['value'];
}

$user_id = base64_encode($account->uid);
$url_info = base64_decode($url_info);
if (!empty($url_info)) {
  $activate_url_info = rtrim($url_info,"/");;
}
else {
  $activate_url_info = PARENT_SSO;
}
$activate_link = $activate_url_info.'/user-activate/'.$user_id;

if ($act_type != 'password_changed') {
  $activelink = l('here', $activate_link, array('attributes' => array('target' => '_blank')));
  $get_body = str_replace("[itg_mail_token:itg_account_user_fname]", $fname, $mail_body);
  $get_body_val = str_replace('[itg_mail_token:itg_account_activation_link]', $activelink, $get_body);
  $get_body_vals = explode(",",$get_body_val);
} else {
  $get_body = str_replace("[itg_mail_token:itg_account_user_fname]", $fname, $mail_body);
  $get_body_vals = explode(',', $get_body);
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
      foreach ($get_body_vals as $bk => $bv) {
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
