<?php
/**
 * @file itg_quiz_result.inc
 */

function itg_quiz_user_list() {
  global $user;
  $node = node_load(arg(1));
  
  if ($node->type == 'quiz') {
    $output = '';
    
    //Send mail link is visible only for site admin, editor and main admin
    if(in_array('Site Admin', array_values($user->roles))  
       || in_array('administrator', array_values($user->roles)) 
      // || in_array('Editor', array_values($user->roles))
      ) {
      
      $send_mail = l(t("Send Mail"),"quiz-winners-mail/".$node->nid);
    } 
    else {
      $send_mail = '';
    }
    
    $output.= '<div><strong>'.  itg_common_get_node_title(arg(1)).'</strong></div><div align="right">'.$send_mail.'</div>
      <table class="views-table">
        <thead>        
          <tr>
            <th>Username</th>
            <th>Email</th>
            <th>Quiz Taken</th>
            <th>Quiz Taken Date</th>
            <th>Total Question</th>
            <th>Attempted Question</th>
            <th>Correct</th>
            <th>Incorrect</th>
            <th>Total Score</th>
        </tr>
      </thead><tbody>';
    
      $answer_op_tbl = '';
      $query = db_select('itg_quiz_user_score', 'qs');
      $query->fields('qs')
          ->condition('qs.nid', $node->nid , '=')
          ->orderBy('qs.quiz_score', 'DESC');
      $result = $query->execute();
      
       while ($record = $result->fetchObject()) {
         if (strpos($record->user_email, 'nowhere.com') !== false) {
            $email = '';
          }
          else {
            $email = $record->user_email;
          }
      $correct_answer = itg_quiz_contest_result($node->nid, $record->quiz_key, 'yes');
         $incorrect_answer = $record->ques_attempt - $correct_answer;
         $answer_op_tbl .= '<tr>
          <td>' . $record->user_name . '</td>
          <td>'.$email.'</td>
          <td>'.$record->quiz_title.'</td>
          <td>'.date('d/m/Y', $record->created).'</td>
          <td>'.$record->ques_total.'</td>
          <td>'.$record->ques_attempt.'</td>
          <td>'.$correct_answer.'</td>
          <td>'.$incorrect_answer.'</td>
          <td>'.$record->quiz_score.'</td>
        </tr>';
      }
         $output.= $answer_op_tbl;
      $output.= '</tbody></table><p>&nbsp;</p>';
      return $output;
  } else {
    drupal_not_found();
  }
}