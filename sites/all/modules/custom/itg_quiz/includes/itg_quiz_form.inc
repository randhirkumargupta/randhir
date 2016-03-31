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
    //$ques_arr = $node->field_quiz_add_questions[LANGUAGE_NONE];
    
    $question_display = $node->field_quiz_question_display[LANGUAGE_NONE][0]['value'];
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
      $question = $question_detail[$question_arr['value']]->field_quiz_question[LANGUAGE_NONE][0]['value'];
      $skip_question[$num] = $question_detail[$question_arr['value']]->field_quiz_skip[LANGUAGE_NONE][0]['value'];
      
      //If any question is required, show required sign(*) for that question
      if ($skip_question[$num] == 'yes') {
        $required = '';
      } else {
        $required = '<span style="color:red">*</span>';
      }

      //Answer Info
      $answer_type = $question_detail[$question_arr['value']]->field_quiz_answer_type[LANGUAGE_NONE][0]['value'];
      $answer_op1 = $question_detail[$question_arr['value']]->field_quiz_answer_option_1[LANGUAGE_NONE][0]['value'];
      $answer_op2 = $question_detail[$question_arr['value']]->field_quiz_answer_option_2[LANGUAGE_NONE][0]['value'];
      
      
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

      //Get more answer options
      foreach ($question_detail[$question_arr['value']]->field_quiz_answer_option_more[LANGUAGE_NONE] as $more_ans_arr) {
        $more_ans_option[$num][$more_ans_arr['value']] = t($more_ans_arr['value']);
      }

      //Required answer option array (Option 1 and Option 2)
      $answer_options[$num] = array(
          $answer_op1 => t($answer_op1),
          $answer_op2 => t($answer_op2),
      );

      //Merge array of answer options and more answer options
      if(!empty($more_ans_option[$num])){
        $all_ans_options[$num] = array_merge($answer_options[$num], $more_ans_option[$num]);
      } else {
        $all_ans_options[$num] = $answer_options[$num];
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

      if ($answer_type == 'textfield') { // Answer options for Textfield
        $txt_num = 0;
        foreach ($all_ans_options[$num] as $val_txt_option) {
          $form['answer_option' . $num . '_' . $txt_num] = array(
              '#title' => $val_txt_option,
              '#type' => $answer_type,
              '#size' => 30,
          );
          $txt_num++;
        }
        $form['answer_option' . $num . '_' . $txt_num]['#suffix'] = '</div>';
        
      } elseif ($answer_type == 'rating') { // Answer option for Rating
        $rating_num = 0;
        foreach ($all_ans_options[$num] as $rating_option) {
          $arr = array(1 => '', 2 => '', 3 => '', 4 => '', 5 => '');
          $form['answer_option' . $num . '_' . $rating_num] = array(
              '#title' => t($rating_option),
              '#type' => 'checkboxes',
              '#options' => $arr,
              '#attributes' => array('class' => array('rating'))
          );
          $rating_num++;
        }
        $form['answer_option' . $num . '_' . $txt_num]['#suffix'] = '</div>';
        
      } else {  //Answer option for Radios and Checkboxes
        $form['answer_option' . $num] = array(
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
            '#suffix' => '</div>',
        );
      }
      
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
     if(($total_num_of_ques-1) !== $num){
        $form['quiz_submit_skip' . $num] = array(
            '#type' => 'submit',
            '#value' => 'Skip',
            '#name' => 'quizsubmit_' . $num,
            '#ajax' => array(
                'callback' => 'quiz_form_ajax_handler',
                'effect' => 'fade',
            ),
            '#suffix' => '</div>',
            '#attributes' => array('class' => array('quiz-submit-skip'))
        );
      }
      
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

    $form['textfield_total_count'] = array(
        '#type' => 'hidden',
        '#value' => $txt_num,
    );
    
    $form['rating_total_count'] = array(
        '#type' => 'hidden',
        '#value' => $rating_num,
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
function itg_quiz_quiz_form_validate($form, &$form_state) {
  $btn_num_arr = explode('_', $form_state['clicked_button']['#name']);
  $num = $btn_num_arr[1];

  $form_detail = $form_state['values'];
  $ans_flag = FALSE;
  $txt_ans_flag = FALSE;
  $rating_ans_flag = FALSE;

  //for ($num = 0; $num < $form_detail['question_total']; $num++) {
  
  //Checkbox validation
    if ($form_detail['question_type' . $num] === 'checkboxes') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        foreach ($form_detail['answer_option' . $num] as $key => $value) {
          if ($value !== 0) {
            $ans_flag = TRUE;
          }
        }
        if (!$ans_flag) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
        }
      }
    }
    
   //Radio Button validation
    if ($form_detail['question_type' . $num] === 'radios') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        if (empty($form_detail['answer_option' . $num])) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
        }
      }
    } 
    
    //Rating validation
    if ($form_detail['question_type' . $num] === 'rating') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        for ($rating_field = 0; $rating_field < $form_detail['rating_total_count']; $rating_field++) {
          for ($rating_field_val = 1; $rating_field_val <= 5; $rating_field_val++) {
            if ($form_detail['answer_option' . $num . '_' . $rating_field][$rating_field_val] !== 0) {
              $rating_ans_flag = TRUE;
            }
          }
        }
        if (!$rating_ans_flag) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
        }
      }
    } 
    
    //Textfield validation
    if($form_detail['question_type' . $num] === 'textfield'){
      if ($form_detail['question_skip' . $num] !== 'yes') {
        $txt_ans_flag = FALSE;
        for ($text_field = 0; $text_field < $form_detail['textfield_total_count']; $text_field++) {
          if ($form_detail['answer_option' . $num . '_' . $text_field] !== '') {
            $txt_ans_flag = TRUE;
          }
        }
        if (!$txt_ans_flag) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
        }
      }
    }
    
  //}
}

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
  
  //Insert each question of quiz in our DB
  db_insert('itg_quiz_detail')
        ->fields(array(
            'nid' => $form_state['values']['nid'],
            'uid' => $user->uid,
            'ques_id' => $form_state['values']['question_id'.$num],
            'question' => $form_state['values']['question'.$num],
            'answer' => '',
            'ans_type' => $form_state['values']['question_type'.$num],
            'user_type' => $user_type,
            'page_url' => $form_state['values']['quiz_url'],
            'quiz_title' => $form_state['values']['quiz_title'],
            'quiz_key' => $_SESSION['quiz_unique_key'],
            'created' => time(),
        ))
        ->execute();

  
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

