<?php
/**
 * @file itg_quiz_winners_mail.inc
 */

function itg_quiz_winners_mail_list() {
 $nid = arg(1);
  $user_email = itg_quiz_winners_user_list($nid);
  
  foreach ($user_email as $key => $value) {
    $user_email_arr[] = $value['user_email'];
  }
  $user_email_arr_unique = array_unique($user_email_arr);
  $user_email_str = implode(',',$user_email_arr_unique);
  
  if (function_exists('itg_mail_templates_get_mailcontent')) {
    $mail_data = itg_mail_templates_get_mailcontent('Quiz');
    $mail_subject = $mail_data->field_mail_subject_quiz_completi[LANGUAGE_NONE][0]['value'];
    $mail_content = itg_quiz_get_mail_content($nid, $mail_data);
  }
  
    $params = array(
      'body' => $mail_content,
      'subject' => $mail_subject,
    );

    $mail = drupal_mail('itg_quiz_winners_list', 'send_mail_to_winners', $user_email_str, language_default(), $params, 'no-reply@kelltontech.com', TRUE);
    if ($mail['result']) {
      drupal_set_message(t('Mail has been sent successfully.'));
      drupal_goto('quiz-user-list/'.$nid);
    }
    else {
      $error_msg = 'Failed to send the email!';
      watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
      drupal_set_message(t($error_msg), 'error');
      drupal_goto('quiz-user-list/'.$nid);
    }
}


/**
 * Get winner's name, email and score
 * @param int $nid
 * @return array
 */
function itg_quiz_winners_user_list($nid, $no_of_winners = NULL) {
  $query = db_select('itg_quiz_user_score', 'qs');
  $query->fields('qs')
      ->condition('qs.nid', $nid, '=')
      ->condition('qs.quiz_score', 0, '!=')
      ->orderBy('qs.quiz_score', 'DESC');
  
  if($no_of_winners) {
    $query->range(0, $no_of_winners);
  }
      

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
 * @global string $base_url
 * @param string $key
 * @param string $message
 * @param array $entity
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
 * @global string $base_url
 * @param array $node
 * @return string
 */
function itg_quiz_get_mail_content($nid, $get_mail_data) {

  global $base_url;
  $winner_count = itg_quiz_winners_count($nid);
  $no_of_winner = $winner_count['field_quiz_winners_value'];
  $winner_records = itg_quiz_winners_user_list($nid, $no_of_winner);
  
  $result_link = $base_url.'/quiz-user-list/'.$nid;
  $winners = '';
  
  $get_mail_content = $get_mail_data->field_mail_body_quiz_completion[LANGUAGE_NONE][0]['value'];
  $content_link = '<a href="'.$result_link.'">here</a>';
  $content = str_replace('[itg_mail_token:itg_quiz_winner_list]', $content_link, $get_mail_content);
//  $content = '<p>Dear user, </p><p>Thanks for taking our quiz. Winners list is given below:</p>';
  $i = 1;
  foreach ($winner_records as $key => $value) {
    $winners .= '<p>' . $i . '. ' . $value['user_name'] . '(' . $value['quiz_score'] . ')' . '</p>';
    $i++;
  }
  $content_end ='<p>&nbsp;</p><p>Thanks,</p><p>India Today Team</p>';
  $final_output = $content . $winners .  $content_end;
  return $final_output;
}



/**
 * Get number of winners count
 * @param int $nid
 * @return int
 */
function itg_quiz_winners_count($nid) {
  $query = db_select('field_data_field_quiz_winners', 'qwc');
  $query->fields('qwc')
          ->condition('qwc.entity_id', $nid, '=');
  $result = $query->execute();
  $i = 0;
  while ($user_winner_count = $result->fetchAssoc()) {
    $user_rec_count['field_quiz_winners_value'] = $user_winner_count['field_quiz_winners_value'];
    $i++;
  }

  return $user_rec_count;
}