<?php
/**
 * Get Mail content
 * @param array $node
 * @return string
 */
function itg_follow_story_get_mail_content($node) {
  
  global $base_url;
  $uname = user_load($node->uid);
//  $story_url = url('node/' . $node->nid, array('absolute' => TRUE));
  $story_url = l($node->title, FRONT_URL . '/node/' . $node->nid, array('absolute' => TRUE));
  
  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $mail_data = itg_mail_templates_get_mailcontent($node, 'Follow Story');
    $mail_body_author = str_replace('[itg_mail_token:itg_account_user_fname]', $uname->name, $mail_data->field_mail_body_follow_story[LANGUAGE_NONE][0]['value']);
    $mail_content_title = str_replace('[itg_mail_token:itg_node_title]', $type, $mail_body_author);
    $mail_content = str_replace('[itg_mail_token:itg_node_title_link]', $story_url, $mail_content_title);
    return $mail_content;
  }  

}
