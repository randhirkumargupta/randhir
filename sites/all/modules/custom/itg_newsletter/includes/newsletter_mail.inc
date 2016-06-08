<?php

/**
 * Send newsletter functionality
 * @file newsletter_mail.inc
 */

function _send_mail_newsletter($node){
   $template_node = node_load($node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id']);
   $user_email_arr = array('haripalrao@gmail.com', 'haripal.rao@kelltontech.com');
   $user_email_str = implode(',',$user_email_arr);
   
   //Get Mail content
   $mail_content = _get_newsletter_mail_content($node, $template_node);
  
    $params = array(
      'body' => $mail_content,
      'subject' => 'India Today Newsletter | '.$template_node->field_newst_header_headline[LANGUAGE_NONE][0]['value'],
    );

    $mail = drupal_mail('_newsletter_mail_sending', 'send_newsletter', $user_email_str, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    if ($mail['result']) {
      drupal_set_message('Newsletter has been sent successfully.');
    }
    else {
      $error_msg = 'Failed to send the newsletter mail!';
      watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
      return FALSE;
    }
}

function _get_newsletter_mail_content($node, $template_node) {
  
// global $base_url;
// 
// $headline = $template_node->field_newst_header_headline[LANGUAGE_NONE][0]['value'];
// $logo = image_style_url("thumbnail", $template_node->field_newst_logo[LANGUAGE_NONE][0]['uri']);
// $banner = $template_node->field_newst_banner[LANGUAGE_NONE][0]['uri'];
// $footer = $template_node->body[LANGUAGE_NONE][0]['value'];
// 
// foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
// 
//    $title = $news_arr['field_news_title'][LANGUAGE_NONE][0]['value'];
//    $kicker = $news_arr['field_news_kicker'][LANGUAGE_NONE][0]['value'];
//    $file = file_load($news_arr['field_news_thumbnail'][LANGUAGE_NONE][0]['fid']);
//    $thumbnail = image_style_url("thumbnail", $file->uri); 
//
//    if($news_arr['field_news_type'][LANGUAGE_NONE][0]['value'] == 'internal') {
//        $link = 'node/'.$news_arr['field_news_cid'][LANGUAGE_NONE][0]['target_id'];
//      } else {
//        $link = $news_arr['field_news_external_url'][LANGUAGE_NONE][0]['value'];
//    }
// }
  
$content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
<head>
    <title></title>
</head>
<body style="margin:0; padding:0;">
<table cellpadding="0" cellspacing="0"><tr><td>Dear user,<td></tr><tr><td>Thanks for taking our quiz. Winners list is given below:<td></tr><tr><td>&nbsp;</td></tr></table>
<table cellpadding="0" cellspacing="0"><tr style="font-weight:bold"><td>User Name</td><td>Score</td></tr>';
//  foreach ($winner_records as $key=>$value) {
//   $winners .= '<tr><td>'.$value['user_name'].'</td>
//        <td>'.$value['quiz_score'].'</td></tr>';
//     
//  }
//  
//  $i = 1;
//    foreach ($winner_records as $key=>$value) {
//   $winners .= '<p>'.$i.'. '.$value['user_name'].'('.$value['quiz_score'].')'.'</p>';
//     $i++;
//  }
  
  $content_end ='</table><p>&nbsp;</p><p>Thanks,</p><p>India Today Team</p></body></html>';
  $final_output = $content.$content_end;
  return $final_output;
}

    
function _newsletter_mail_sending_mail($key, &$message, $params) {
  switch ($key) {
    case 'send_newsletter':
      $headers = array(
        'MIME-Version' => '1.0',
        'Content-Type' => 'text/plain; charset=UTF-8; format=flowed; delsp=yes',
        'Content-Transfer-Encoding' => '8Bit',
        'X-Mailer' => 'Drupal'
      );
      $message['subject'] = $params['subject'];
      $message['body'][] = $params['body'];
      foreach ($headers as $key => $value) {
        $message['headers'][$key] = $value;
      }
      break;
  }
}