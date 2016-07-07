<?php 
/**
 * Template file to send mail on idea submission
 * @file: print-team-idea-status-mail.tpl.php
 */

global $base_url;
$idea_link = $base_url.'/node/'.$node->nid.'/edit';

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
        <td style="padding: 10px 20px;">Dear Team,</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">An idea has been submitted, please review.</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Title: <strong><?php echo $node->title; ?></strong></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;"><?php echo l('Click here to see details', $idea_link, array('attributes' => array('target' => '_blank'))); ?></td>
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
