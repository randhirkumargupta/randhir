<?php
/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_follow_story_get_mail_content($node) {
  global $base_url;
  $story_url = url('node/' . $node->nid, array('absolute' => TRUE));
  $content = '<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Story updation</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">
      <tr>
        <td style="padding: 10px 20px;">Dear User, </td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Story : ' . $node->title . ' has been updated</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">' . l('Click here to view story', $story_url, array('attributes' => array('target' => '_blank'))) . '</td>
      </tr>
      <tr>
        <td style="padding: 10px 20px;">Thanks,</td>
      </tr>
      <tr>
        <td style="padding: 0px 20px;">India Today Group</td>
      </tr>
    </table>
  </body>
</html>';
  return $content;
}
