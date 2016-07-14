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
        <td style="padding: 10px 20px;">Dear User,</td>
      </tr>
      
      <tr>
        <td style="padding: 10px 20px;">Your idea is about to expire.</td>
      </tr>
      
      <tr>
        <td style="padding: 10px 20px;">Current status: <strong><?php echo $node->field_pti_idea_status[LANGUAGE_NONE][0]['value']; ?></strong></td>
      </tr>

      <tr>
        <td style="padding: 10px 20px;">Words limit to write story: <?php echo $node->field_pti_words_limit[LANGUAGE_NONE][0]['value']; ?></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Last Date of submission: <?php echo date('d/m/Y', strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'])); ?></td>
      </tr>
      
      <tr>
        <td style="padding: 10px 20px;"><?php echo l('Click here to update', $idea_link, array('attributes' => array('target' => '_blank'))); ?></td>
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
