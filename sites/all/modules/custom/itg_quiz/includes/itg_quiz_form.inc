<?php

/**
 * @file: itg_quiz_form.inc
 */


/**
 * Create quiz form
 */
function itg_quiz_quiz_form() {
  global $base_url;
  
  //Get node of current quiz (load all questions ans answer options to generate quiz form)
  $node = itg_quiz_get_current_quiz();

  //Check: Any quiz is activated OR not
  if ($node) {
    
    $num = 0;
    $form = array();
    
    $question_display = $node->field_quiz_display_sequence[LANGUAGE_NONE][0]['value'];
    
    if($question_display == 'random'){
      foreach ($node->field_quiz_add_questions[LANGUAGE_NONE] as $ques_arr_for_shuffle){
        $ques_arr_shuffle[] = $ques_arr_for_shuffle['value'];
      }
      shuffle($ques_arr_shuffle);
      
      foreach($ques_arr_shuffle as $ques_arr_new){
          $ques_arr[]['value'] = $ques_arr_new;
      }
    } else {
      $ques_arr = $node->field_quiz_add_questions[LANGUAGE_NONE];
    }
 
    $total_num_of_ques = count($ques_arr);
 
    foreach ($ques_arr as $question_arr) {
      
      //Question Info
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));
      
      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];
      
      $skip_question[$num] = 'yes';
    
      //If any question is required, show required sign(*) for that question
      if ($skip_question[$num] == 'yes') {
        $required = '';
      } else {
        $required = '<span style="color:red">*</span>';
      }

      //Answer Info
      $answer_type_type = $question_detail[$question_arr['value']]->field_quiz_answer_type[LANGUAGE_NONE][0]['value'];
      if( $answer_type_type == 'single_correct') {
        $answer_type = 'radios';
      } else {
        $answer_type = 'checkboxes';
      }
       
      foreach($question_detail[$question_arr['value']]->field_quiz_options_answer[LANGUAGE_NONE] as $ans_option){
        $ans_option_arr = entity_load('field_collection_item', array($ans_option['value']));
        foreach($ans_option_arr[$ans_option['value']]->field_quiz_answer_text[LANGUAGE_NONE] as $final_ans_op){
          $all_ans_options[$num][$final_ans_op['value']] = $final_ans_op['value'];
        }
      }
 
      //Media info
      $media = $question_detail[$question_arr['value']]->field_quiz_add_media[LANGUAGE_NONE][0]['uri'];
      $media_type = strtolower(substr(strrchr($media, '.'), 1));
      $media_path = $base_url.str_replace('public://', '/sites/default/files/', $media);
      
      //Submit button text
      if(($total_num_of_ques-1) === $num){
        $button_text = 'Submit';
      } else {
        $button_text = 'Next';
      }
     
      //Show error message, if user tries to skip required question
      $form['messages'] = array(
          '#prefix' => '<div style="color:red" id="messages">',
          '#suffix' => '</div>'
      );
 
      //Prepare Question and Answer form
      $form['question_heading' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<h2 class="question-heading">' . ($num + 1) . '. ' . $question . '?</h2>',
          '#prefix' => '<div id="question-container-'.$num.'" class="question-container">'
      );
      
      $form['question' . $num] = array(
          '#type' => 'hidden',
          '#value' => $question,
      );

      $form['question_id' . $num] = array(
          '#type' => 'hidden',
          '#value' => $question_arr['value'],
      );

      $form['question_skip' . $num] = array(
          '#type' => 'hidden',
          '#value' => $skip_question[$num],
          '#attributes' => array('id' => array('question-skip-'.$num), 'class' => array('question-skip'))
      );

      $form['question_type' . $num] = array(
          '#type' => 'hidden',
          '#value' => $answer_type,
          '#attributes' => array('id' => array('question-type-'.$num))
      );
      
      $form['answer' . $num] = array(
          '#type' => 'markup',
          '#prefix' => '<div id="answer-container-'.$num.'" class="answer-container">',
          '#markup' => '<h2 class="answer-heading">Answer: ' . $required . '</h2> ',
      );

      $form['answer_option' . $num] = array(
          '#title' => t(''),
          '#type' => $answer_type,
          '#options' => $all_ans_options[$num],
          '#suffix' => '</div>',
      );
      
      
      if(!empty($media_type)){
      if($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif'){
        $form['media' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div>',
            '#markup' => '<img src="'.$media_path.'" height="100" width="130"/>',
            '#suffix' => '</div>',
        );
      } else {
        $form['media' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div>',
            '#markup' => '<video width="140" height="145" controls="controls">
        <source src="'.$media.'" type="video/mp4"> 
         <object> 
           <embed  src="'.$media.'"> 
         </object> 
      </video>',
            '#suffix' => '</div>',
        );
      }
      }
      
      //Nex button for all questions
      $form['quiz_submit_' . $num] = array(
        '#type' => 'submit',
        '#value' => $button_text,
        '#name' => 'quizsubmit_' . $num,
        '#ajax' => array(
            'callback' => 'quiz_form_ajax_handler',
            'effect' => 'fade',
        ),
          
          '#attributes' => array('class' => array('quiz-submit'))
      );
     
     //Skip button for all qustions except last one
//     if(($total_num_of_ques-1) !== $num){
//        $form['quiz_submit_skip' . $num] = array(
//            '#type' => 'submit',
//            '#value' => 'Skip',
//            '#name' => 'quizsubmit_' . $num,
//            '#ajax' => array(
//                'callback' => 'quiz_form_ajax_handler',
//                'effect' => 'fade',
//            ),
//            '#suffix' => '</div>',
//            '#attributes' => array('class' => array('quiz-submit-skip'))
//        );
//      }
      
      $num++;
      
    } //End of for loop

    //Hidden variable, same for all questions  
    $form['question_total'] = array(
        '#type' => 'hidden',
        '#value' => $total_num_of_ques,
    );

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $node->nid,
    );

    $form['quiz_url'] = array(
        '#type' => 'hidden',
        '#value' => $_GET['q'],
    );
    
    $form['quiz_title'] = array(
        '#type' => 'hidden',
        '#value' => $node->title,
    );
    
  } else { //If no quiz found
    $form['no_quiz'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>Quiz has been expired!</h2>',
    );
  }

  return $form;
}

/**
 * Validate functionality of quiz form
 * @param Array $form
 * @param Array $form_state
 */
//function itg_quiz_quiz_form_validate($form, &$form_state) {
//  $btn_num_arr = explode('_', $form_state['clicked_button']['#name']);
//  $num = $btn_num_arr[1];
//
//  $form_detail = $form_state['values'];
//  $ans_flag = FALSE;
//
//    //Checkbox validation
//    if ($form_detail['question_type' . $num] === 'checkboxes') {
//      if ($form_detail['question_skip' . $num] !== 'yes') {
//        foreach ($form_detail['answer_option' . $num] as $key => $value) {
//          if ($value !== 0) {
//            $ans_flag = TRUE;
//          }
//        }
//        if (!$ans_flag) {
//          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
//        }
//      }
//    }
//    
//   //Radio Button validation
//    if ($form_detail['question_type' . $num] === 'radios') {
//      if ($form_detail['question_skip' . $num] !== 'yes') {
//        if (empty($form_detail['answer_option' . $num])) {
//          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
//        }
//      }
//    } 
//}

/**
 * Submit handler for quiz form
 * @param Array $form
 * @param Array $form_state
 */
function itg_quiz_quiz_form_submit($form, &$form_state){
  global $user;

  //Form variable
  $form_detail = $form_state['values'];
  $btn_num_arr = explode('_', $form_state['clicked_button']['#name']);
  $num = $btn_num_arr[1];
  
  //Extract user type
  if ($user->uid) {
    $user_type = 'authenticated';
  } else {
    $user_type = 'anonymous';
  }
  
  //Set a session for a quiz(Will be same for all questions during a quiz) 
  if(!isset($_SESSION['quiz_unique_key'])){
    $_SESSION['quiz_unique_key'] = user_password(6);
  }
  
  //Insert each question and answer in to DB
  if ($form_state['values']['question_type' . $num] == 'radios') {

    db_insert('itg_quiz_detail')
            ->fields(array(
                'nid' => $form_state['values']['nid'],
                'uid' => $user->uid,
                'ques_id' => $form_state['values']['question_id' . $num],
                'question' => $form_state['values']['question' . $num],
                'answer' => strtolower($form_state['values']['answer_option' . $num]),
                'ans_type' => $form_state['values']['question_type' . $num],
                'user_type' => $user_type,
                'page_url' => $form_state['values']['quiz_url'],
                'quiz_title' => $form_state['values']['quiz_title'],
                'quiz_key' => $_SESSION['quiz_unique_key'],
                'created' => time(),
            ))
            ->execute();
  }

  if ($form_state['values']['question_type' . $num] == 'checkboxes') {

    foreach ($form_state['values']['answer_option' . $num] as $key => $value) {
      if ($value) {
        db_insert('itg_quiz_detail')
                ->fields(array(
                    'nid' => $form_state['values']['nid'],
                    'uid' => $user->uid,
                    'ques_id' => $form_state['values']['question_id' . $num],
                    'question' => $form_state['values']['question' . $num],
                    'answer' => strtolower($value),
                    'ans_type' => $form_state['values']['question_type' . $num],
                    'user_type' => $user_type,
                    'page_url' => $form_state['values']['quiz_url'],
                    'quiz_title' => $form_state['values']['quiz_title'],
                    'quiz_key' => $_SESSION['quiz_unique_key'],
                    'created' => time(),
                ))
                ->execute();
      }
    }
  }
  
  //Insert quiz in to DB on final submit
  if(strtolower($form_state['clicked_button']['#value']) == 'submit'){
    db_insert('itg_quiz_user')
            ->fields(array(
                'nid' => $form_state['values']['nid'],
                'uid' => $user->uid,
                'user_type' => $user_type,
                'page_url' => $_GET['q'],
                'created' => time(),
            ))
            ->execute();
    unset($_SESSION['unique_quiz']);
  }

  //Display saved quiz message on final submit only.
  if ($num == ($form_detail['question_total'] - 1)) {
    drupal_set_message(t('Quiz has been saved successfully. Thank you for taking our quiz!'));
  }
}

/**
 * Submit handler of Ajax
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function quiz_form_ajax_handler(&$form, &$form_state){
  $commands = array();
  $commands[] = ajax_command_replace('#messages', '<div id="messages">' . theme('status_messages') . '</div>');
  return array(
      '#type' => 'ajax',
      '#commands' => $commands);
}

?>

