<?php
/**
 * @file itg_survey_result.inc
 */
function itg_get_rating_value($qid) {
    $result = db_select('itg_survey_detail', 's')
            ->fields('s', array('rating_value'))
            ->condition('ques_id', $qid)
            ->execute();
    $rating_value = $result->fetchField();

    if ($rating_value) {
        return $rating_value;
    } else {
        return 0;
    }
}
function itg_survey_result() {
  $node = node_load(arg(1));
  
  if(itg_common_check_record_existance($node->nid, 'itg_survey_detail', 'nid') > 0){
  if ($node->type == 'survey') {
      $num = 0;
      $sn = 1;
      $final_output = '';
      
    //  $rating= $_GET['rating_value'];
      
      
      $ques_arr = $node->field_survey_add_questions[LANGUAGE_NONE];
 
      foreach ($ques_arr as $question_arr) {
       
      $output.$num = '';
      $answer_options = '';
      
      //Question Info
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));

      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];
      
      $answer_type = $question_detail[$question_arr['value']]->field_survey_answer_type[LANGUAGE_NONE][0]['value'];

      // Collect answer 1 and more oprions
      $answer_op1 = $question_detail[$question_arr['value']]->field_survey_answer_option_1[LANGUAGE_NONE][0]['value'];

       foreach ($question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE] as $more_ans_arr) {
          $answer_options[] = t($more_ans_arr['value']);
       }
       
       // Push first answer option into second answer option and prepare all answer options
       if(empty($answer_options)) {
         $answer_options[] = $answer_op1;
       } 
       else {
         array_unshift($answer_options, $answer_op1);
       }
      
        if ($answer_type == 'rating') {
          if(empty($answer_options)){
            $answer_options = array($question);
          }
        }

      $output.$num .= '<div><strong>Question-' . $sn.'. ' . $question . '?</strong></div>
      <table style="width:100%" class="views-table">
        <tr>
        <th>Answers</th>
        <th>Vote Count</th>
        <th>Authenticated User Vote</th>
        <th>Anonymous User Vote</th>
        <th>One Star</th>
        <th>Two Star</th>
        <th>Three Star</th>
        <th>Four Star</th>
        <th>Five Star</th>
      </tr>';
      
      $answer_op_tbl = '';
      
      foreach ($answer_options as $key => $value) {
        
        
        if ($answer_type == 'rating') {
          $rating = itg_get_rating_value($question_arr['value']);
            
            $answer = $value ? $value : $question;
            $vote_percentage = itg_survey_vote_percentage($node->nid, $question_arr['value'], strtolower($answer));
            $authenticated_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($answer), 'authenticated');
            $anonymous_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($answer), 'anonymous');
          
               
            $rating_star_percentage = itg_survey_vote_percentage_user_rating($node->nid, $question_arr['value'], strtolower($answer),$rating);
       
            $i = 1;
                foreach($rating_star_percentage as $value) {                   
                    if($value->rating_value == 1) {                       
                       $rating_user1 = $value->user*100;                       
                    } else if($value->rating_value == 2) {
                       $rating_user2 = $value->user*100; 
                    } else if($value->rating_value == 3) {
                       $rating_user3 = $value->user*100; 
                    } else if($value->rating_value == 4) {
                       $rating_user4 = $value->user*100; 
                    } else if($value->rating_value == 5) {
                       $rating_user5 = $value->user*100; 
                    } 
                    $total_rating_user+= $value->user;
                }
                 $one_star_percentage = $rating_user1/$total_rating_user;
               
                 $two_star_percentage = $rating_user2/$total_rating_user;
                 $three_star_percentage = $rating_user3/$total_rating_user;
                 $four_star_percentage = $rating_user4/$total_rating_user;
                 $five_star_percentage = $rating_user5/$total_rating_user;
            
            $answer_op_tbl .= '<tr>
              <td style="width:25%">' . $answer . '</td>
              <td>' . $vote_percentage . '</td>
              <td>' . $authenticated_percentage . '</td>
              <td>' . $anonymous_percentage . '</td>
              <td>' . number_format($one_star_percentage,2).'%' . '</td>
              <td>' . number_format($two_star_percentage,2).'%' . '</td>
              <td>' . number_format($three_star_percentage,2).'%' . '</td>
              <td>' . number_format($four_star_percentage,2).'%' . '</td>
              <td>' . number_format( $five_star_percentage,2).'%' . '</td>
            </tr>';
          } elseif ($answer_type == 'textfield') {
              
              
               $answer = $value ? $value : $question;
            $vote_percentage = itg_survey_vote_percentage($node->nid, $question_arr['value'], strtolower($answer));
            $authenticated_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($answer), 'authenticated');
            $anonymous_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($answer), 'anonymous');
          
              
              $answer_op_tbl .= '<tr>
              <td style="width:25%">' . $answer . '</td>
              <td>' . $vote_percentage . '</td>
              <td>' . $authenticated_percentage . '</td>
              <td>' . $anonymous_percentage . '</td>
              
              </tr>';       
          } else  {
            
            $vote_percentage = itg_survey_vote_percentage($node->nid, $question_arr['value'], strtolower($value));
            $authenticated_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($value), 'authenticated');
            $anonymous_percentage = itg_survey_vote_percentage_user($node->nid, $question_arr['value'], strtolower($value), 'anonymous');

            $answer_op_tbl .= '<tr>
              <td style="width:25%">' . $value . '</td>
              <td>' . $vote_percentage . '</td>
              <td>' . $authenticated_percentage . '</td>
              <td>' . $anonymous_percentage . '</td>
            </tr>';
          } 
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
    drupal_not_found();
  }
  
  } else {
    return '<h2>No Result Found! This survey has not taken yet.</h2>';
  }
}
   
          
          
          
          
          
          
          
          
      
 