<?php
/**
 * @file itg_quiz_result.inc
 */

function itg_quiz_user_list() {
  $node = node_load(arg(1));
  $nid = arg(1);
  if ($node->type == 'quiz') {
    $output = '';
    $output.= '<div><strong>Quiz User List</strong></div><div align="right">'.l(t("Send Mail"),"quiz-winners-mail/$nid").'</div>
      <table style="width:100%">
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
      </tr>';
    
      $answer_op_tbl = '';
      $query = db_select('itg_quiz_user_score', 'qs');
      $query->fields('qs')
          ->condition('qs.nid', $node->nid , '=')
          ->orderBy('qs.quiz_score', 'DESC');
      $result = $query->execute();
      
       while ($record = $result->fetchObject()) {
         $correct_answer = itg_quiz_contest_result($node->nid, $record->quiz_key, 'yes');
         $incorrect_answer = $record->ques_attempt - $correct_answer;
         $answer_op_tbl .= '<tr>
          <td>' . $record->user_name . '</td>
          <td>'.$record->user_email.'</td>
          <td>'.$record->quiz_title.'</td>
          <td>'.date('Y/m/d', $record->created).'</td>
          <td>'.$record->ques_total.'</td>
          <td>'.$record->ques_attempt.'</td>
          <td>'.$correct_answer.'</td>
          <td>'.$incorrect_answer.'</td>
          <td>'.$record->quiz_score.'</td>
        </tr>';
      }
         $output.= $answer_op_tbl;
      $output.= '</table><p>&nbsp;</p>';
      return $output;
  } else {
    drupal_access_denied();
  }
}