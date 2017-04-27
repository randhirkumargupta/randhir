<?php
/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_follow_story_get_mail_content($node) {
  
  global $base_url;
  $uname = user_load($node->uid);
  $story_url = url('node/' . $node->nid, array('absolute' => TRUE));
  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $mail_data = itg_mail_templates_get_mailcontent($node, 'Follow Story');
    $mail_body_author = str_replace('[itg_mail_token:itg_author]', $uname->name, $mail_data->field_mail_body_follow_story[LANGUAGE_NONE][0]['value']);
    $mail_content_title = str_replace('[itg_mail_token:itg_node_title]', $type, $mail_body_author);
    $mail_content = str_replace('[itg_mail_token:itg_node_title_link]', $story_url, $mail_content_title);
    $get_body = explode(",",$mail_content);
  }
  
  $content = '<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Story updation</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">';
      foreach ($get_body as $bk => $bv) {
        $content .= '<tr> <td style="padding: 10px 20px;">' . $bv . '</td></tr>';
      } 
      $content .= '<tr>
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
