<?php
/**
 * @file itg_quiz_winners_mail.inc
 */

function itg_quiz_winners_mail_list() {
 $nid = arg(1);
  $user_email = itg_quiz_winners_user_list($nid);
  foreach($user_email as $key=>$value) {
    $user_email_arr[] = $value['user_email'];
  }
  
    $user_email_str = implode(',',$user_email_arr);
  $mail_content = itg_quiz_get_mail_content($nid);
    $params = array(
      'body' => $mail_content,
      'subject' => 'India Today | Quiz Winners',
    );

    $mail = drupal_mail('itg_quiz_winners_list', 'send_mail_to_winners', $user_email_str, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    if ($mail['result']) {
      drupal_set_message('Winners list has been sent to users.');
      drupal_goto('quiz-user-list/'.$nid);
    }
    else {
      $error_msg = 'Failed to send the email!';
      watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
      return FALSE;
    }
}


// function to get user email
function itg_quiz_winners_user_list($nid) {
  $query = db_select('itg_quiz_user_score', 'qs');
  $query->fields('qs')
      ->condition('qs.nid', $nid, '=')
      ->condition('qs.quiz_score', 0, '!=')
      ->orderBy('qs.quiz_score', 'DESC');
  $result = $query->execute();
  $i = 0;
  while ($user_email_list = $result->fetchAssoc()) {
    $user_rec[$i]['user_email'] = $user_email_list['user_email'];
    $user_rec[$i]['user_name'] = $user_email_list['user_name'];
    $user_rec[$i]['quiz_score'] = $user_email_list['quiz_score'];
    $i++;
    }

  return $user_rec;
}

/**
 * Send mail to expert, when query is received
 * @global String $base_url
 * @param String $key
 * @param String $message
 * @param Array $entity
 */
function itg_quiz_winners_list_mail($key, &$message, $params) {
  switch ($key) {
    case 'send_mail_to_winners':
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

/**
 * Get Mail content
 * @global String $base_url
 * @param Array $node
 * @return string
 */
function itg_quiz_get_mail_content($nid) {
  
  global $base_url;
  $winner_records = itg_quiz_winners_user_list($nid);
  
$content = '';
$content_end = '';
$winners = '';
  $content = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
<head>
    <title></title>
</head>
<body style="margin:0; padding:0;">
<table cellpadding="0" cellspacing="0"><tr><td>Dear user,<td></tr><tr><td>Thanks for taking our quiz. Winners list is given below:<td></tr><tr><td>&nbsp;</td></tr></table>
<table cellpadding="0" cellspacing="0"><tr style="font-weight:bold"><td>User Name</td><td>Score</td></tr>';
  foreach ($winner_records as $key=>$value) {
   $winners .= '<tr><td>'.$value['user_name'].'</td>
        <td>'.$value['quiz_score'].'</td></tr>';
     
  }
  $content_end ='<tr><td>&nbsp;</td></tr><tr><td>Thanks,</td></tr><tr><td>India Today Team</td></tr></table></body></html>';
  $final_output = $content.$winners.$content_end;
  return $final_output;
}
