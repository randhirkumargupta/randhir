<?php

/**
 * Send newsletter functionality
 * @file newsletter_mail.inc
 */

function _send_mail_newsletter($node){
  //$node = node_load(1375);
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
 global $base_url;
// 
// $headline = $template_node->field_newst_header_headline[LANGUAGE_NONE][0]['value'];
// $logo = image_style_url("thumbnail", $template_node->field_newst_logo[LANGUAGE_NONE][0]['uri']);
$banner = $base_url . str_replace('public://','/sites/default/files/', $template_node->field_newst_banner[LANGUAGE_NONE][0]['uri']);

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
  
$header = '<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
  <head>
    <title>India Today Newsletter</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body><table cellspacing="0" cellpadding="0" style="width: 333px; margin: 0 auto; border: 5px solid #d9d9d9; font-family: Arial"><tr><td colspan="2"><img src="'.$banner.'" alt="" /></td></tr>';

$content = '<tr>
        <td colspan="2" style="padding: 10px 20px;">
          <table cellspacing="0" cellpadding="0" style="width: 100%;">
            <tr>
              <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;">
              </td>
              <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">Newsletter</h2>
                <p style="margin: 0; font-size: 14px;">Nam ante elit, varius sit amet arcu et, ultricies imperdiet ipsum. Nullam cursus dolor vitae consectetur viverra. Curabitur at porttitor elit! Fusce non nisl a urna porttitor imperdiet at non metus. Cras tincidunt lectus a sem ultrices, nec varius nulla scelerisque. Integer gravida libero nisl, eu ultrices augue condimentum ut. Nam egestas bibendum justo quis feugiat.</p>
              </td>
            </tr>
            <tr>
              <td style="padding: 20px 10px 20px 20px; vertical-align: top; border-bottom: 2px solid #d9d9d9;">
              </td>
              <td style="padding: 20px 20px 20px 10px; border-bottom: 2px solid #d9d9d9;">
                <h2 style="margin: 0; color: #337ab7; font-size: 18px; padding-bottom: 10px;">Newsletter Templates</h2>
                <p style="margin: 0; font-size: 14px;">Nam ante elit, varius sit amet arcu et, ultricies imperdiet ipsum. Nullam cursus dolor vitae consectetur viverra. Curabitur at porttitor elit! Fusce non nisl a urna porttitor imperdiet at non metus. Cras tincidunt lectus a sem ultrices, nec varius nulla scelerisque. Integer gravida libero nisl, eu ultrices augue condimentum ut. Nam egestas bibendum justo quis feugiat.</p>
              </td>
            </tr>

          </table>
        </td>
      </tr>';

//  foreach (foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
//   $winners .= '<tr><td>'.$value['user_name'].'</td>
//        <td>'.$value['quiz_score'].'</td></tr>';
//     
//  }
  
$footer = '<tr>
        <td colspan="2">
          <table cellspacing="0" cellpadding="0" style="width: 100%; text-align: center; font-size: 14px;">
            <tbody>
              <tr>
                <td style="padding: 10px 0 5px;">About US | India Today | AajTak</td>
              </tr>
              <tr>
                <td style="padding: 0 0 20px;">Copyright &copy; 2016 Living Media India Limited. For reprint rights: Syndications Today.</td>
              </tr>
            </tbody>
          </table>
        </td>
      </tr>';

  $content_end ='</table><p>Thanks,</p><p>India Today Team</p></body></html>';
  
  $final_output = $header. $content. $footer. $content_end;
  
  return $final_output;
}

    
function _newsletter_mail_sending_mail($key, &$message, $params) {
  switch ($key) {
    case 'send_newsletter':
      $headers = array(
        'MIME-Version' => '1.0',
        'Content-Type' => 'text/html; charset=UTF-8; format=flowed; delsp=yes',
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