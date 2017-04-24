<?php 
/**
 * Template file to send mail on otp
 * @file: sso-otp-mail.tpl.php
 */

global $base_url;

?> 

<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today | OTP</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">
      <tr>
        <td style="padding: 10px 20px;">Dear User,</td>
      </tr>
     <tr>
        <td style="padding: 10px 20px;">Your otp is <?php print $rand_otp; ?></td>
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
