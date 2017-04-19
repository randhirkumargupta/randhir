<?php
/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_ask_expert_get_mail_content($node) {
  global $base_url;
  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $ask_expert_submit_query = itg_mail_templates_get_mailcontent($node);
    $body = $ask_expert_submit_query->field_mail_body_expert;
  }
  $uname = $node->field_user_name[LANGUAGE_NONE][0]['value'];
  $uemail = $node->field_user_email[LANGUAGE_NONE][0]['value'];
  $ucity = $node->field_user_city[LANGUAGE_NONE][0]['value'];
  $ustate = $node->field_user_state[LANGUAGE_NONE][0]['value'];
  $question = $node->title;

  // todo: move to email template
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
<head>
    <title></title>
</head>
<body style="margin:0; padding:0;">
      <table cellpadding="0" cellspacing="0" width="760" align="center"><tr><td>Hi Team,</td></tr>
      <tr><td></td></tr>
      <tr><td>New Query has been received, please find below detail.</td></tr>
      <tr><td></td></tr>
      <tr><td>Question: ' . $question . '</td></tr>
      <tr><td>Name: ' . $uname . '</td></tr>
      <tr><td>Email: ' . $uemail . '</td></tr>
      <tr><td>City: ' . $ucity . '</td></tr>
      <tr><td>State: ' . $ustate . '</td></tr>
      <tr><td></td></tr>
      <tr><td>Thanks,</td></tr>
      <tr><td>India Today Team</td></tr></table>
</body></html>';

  return $content;
}