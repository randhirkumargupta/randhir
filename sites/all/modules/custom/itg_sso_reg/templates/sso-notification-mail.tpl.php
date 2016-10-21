<?php 
/**
 * Template file to send mail on user Activation
 * @file: sso-notification-mail.tpl.php
 */

global $base_url;

$user_id = base64_encode($account->uid);
$activate_link = $base_url.'/user-activate/'.$user_id;

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
      <tr>
        <td style="padding: 10px 20px;">Dear User,</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">You are registered successfully.</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;"><?php echo l('Click here to activate your account', $activate_link, array('attributes' => array('target' => '_blank'))); ?></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Thanks,</td>
      </tr>
      <tr>
        <td style="padding: 0px 20px;">India Today Group</td>
      </tr>
    </table>
  </body>
</html>
