<?php 
/**
 * Template file to send mail on idea association
 * @file: print-team-idea-association-mail.tpl.php
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
        <td style="padding: 10px 20px;">Dear Team,</td>
      </tr>
      <?php if ($op_type == 'idea_update') { ?>
      <tr>
        <td style="padding: 10px 20px;">An idea "<strong><?php echo $node->title; ?></strong>" has been update.</td>
      </tr>
      <?php } else { ?>
      <tr>
        <td style="padding: 10px 20px;">An idea "<strong><?php echo $node->title; ?></strong>" has been converted to story.</td>
      </tr>
      <?php } ?>

      <tr>
        <td style="padding: 10px 20px;">Associated Issue, Magazine and Supplement:</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Issue: <strong><?php echo date('d/m/Y', strtotime(itg_common_get_node_title($node->field_pti_issue[LANGUAGE_NONE][0]['target_id']))); ?></strong></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Magazine: <strong><?php echo itg_common_get_node_title($node->field_pti_magazine[LANGUAGE_NONE][0]['target_id']); ?></strong></td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Supplement: <strong><?php echo itg_common_get_node_title($node->field_pti_supplement[LANGUAGE_NONE][0]['target_id']); ?></strong></td>
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