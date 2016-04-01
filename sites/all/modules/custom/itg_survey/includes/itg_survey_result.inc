<?php
/**
 * @file itg_survey_result.inc
 */

function itg_survey_result() {
  $node = node_load(arg(1));

  if ($node->type == 'survey') {
    
      $num = 0;
      $sn = 1;
      $final_output = '';

      $ques_arr = $node->field_survey_add_questions[LANGUAGE_NONE];
 
      foreach ($ques_arr as $question_arr) {
        
      $output.$num = '';
      $answer_options = '';
      
      //Question Info
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));
      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];

      //Answer Info
      $answer_op1 = $question_detail[$question_arr['value']]->field_survey_answer_option_1[LANGUAGE_NONE][0]['value'];
   
     // Prepare options for all answers
     foreach ($question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE] as $more_ans_arr) {
        $answer_options[] = t($more_ans_arr['value']);
      }
     
      //Push first answer option in to second answer option and prepare all answer options 
      array_unshift($answer_options,$answer_op1);

      $output.$num .= '<div><strong>Question-' . $sn.'. ' . $question . '?</strong></div>
      <table style="width:100%">
        <tr>
        <th>Answers</th>
        <th>Total Vote</th>
        <th>Authenticated User Vote</th>
        <th>Anonymous User Vote</th>
      </tr>';
      
      $answer_op_tbl = '';
      foreach ($answer_options as $key => $value) {
        $vote_percentage = itg_survey_vote_percentage($node->nid, $question_arr['value'], strtolower($value));
        $authenticated_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($value), 'authenticated');
        $anonymous_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($value), 'anonymous');
        
        $answer_op_tbl .= '<tr>
        <td style="width:25%">' . $value . '</td>
        <td>'.$vote_percentage.'</td>
          <td>'.$authenticated_percentage.'</td>
            <td>'.$anonymous_percentage.'</td>
        </tr>';
      }
 
      $output.$num .= $answer_op_tbl;
      $output.$num .= '</table><p>&nbsp;</p>';
      //return $output;
      
      $num++;
      $sn++;
      $final_output .= $output.$num;
    } //End of for loop
    
    
    return $final_output;
    
  } else {
    drupal_access_denied();
  }
}