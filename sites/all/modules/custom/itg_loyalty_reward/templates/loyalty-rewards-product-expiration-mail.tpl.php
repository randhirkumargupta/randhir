<?php 
/**
 * Template file to send mail on product expiration
 * @file: loyalty-rewards-product-expiration-mail.tpl.php
 */
?> 

<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Mail</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">
      <tr>
        <td style="padding: 10px 20px;">Dear ITG Team,</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">The product <strong><?php echo $node->title; ?></strong> is going to expire in next 24 hours.</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Product Expiry Date: <strong><?php echo date('d/m/Y', strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])); ?></strong></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">&nbsp;</td>
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
