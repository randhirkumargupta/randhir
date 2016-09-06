<?php

/**
 * @file: itg_survey_form.inc
 */


/**
 * Create survey form
 */
function itg_survey_survey_form() {
  global $base_url;
  
  //Get node of current survey (load all questions ans answer options to generate survey form)
  $arg = arg();
  $node = node_load($arg[1]);
  
  //Check: Any survey is activated OR not
  if ($node) {
    
    $num = 0;
    $form = array();
    
    $cookie_name = 'Drupal_visitor_itgcms_survey_' . $node->nid;

    if (isset($_COOKIE[$cookie_name])) {
      $survey_taken = 'yes';
    } else {
      $survey_taken = 'no';
    }
    
    $question_display = $node->field_survey_question_display[LANGUAGE_NONE][0]['value'];
    if($question_display == 'random'){
      foreach ($node->field_survey_add_questions[LANGUAGE_NONE] as $ques_arr_for_shuffle){
        $ques_arr_shuffle[] = $ques_arr_for_shuffle['value'];
      }
      shuffle($ques_arr_shuffle);
      
      foreach($ques_arr_shuffle as $ques_arr_new){
          $ques_arr[]['value'] = $ques_arr_new;
      }
    } else {
      $ques_arr = $node->field_survey_add_questions[LANGUAGE_NONE];
    }
 
    $total_num_of_ques = count($ques_arr);
 
    foreach ($ques_arr as $question_arr) {
      //Question Info
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));
      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];
      $skip_question[$num] = $question_detail[$question_arr['value']]->field_survey_skip[LANGUAGE_NONE][0]['value'];
      
      //If any question is required, show required sign(*) for that question
      if ($skip_question[$num] == 'yes') {
        $required = '';
      } else {
        $required = '<span style="color:red">*</span>';
      }

      //Answer Info
      $answer_type = $question_detail[$question_arr['value']]->field_survey_answer_type[LANGUAGE_NONE][0]['value'];
      $answer_op1 = $question_detail[$question_arr['value']]->field_survey_answer_option_1[LANGUAGE_NONE][0]['value'];
      
      
      //Media info
      $media = $question_detail[$question_arr['value']]->field_survey_add_media[LANGUAGE_NONE][0]['uri'];
      $media_type = strtolower(substr(strrchr($media, '.'), 1));
      $media_path = $base_url.str_replace('public://', '/sites/default/files/', $media);
      
      //Submit button text
      if(($total_num_of_ques-1) === $num){
        $button_text = 'Submit';
      } else {
        $button_text = 'Next';
      }

      //Get more answer options
      foreach ($question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE] as $more_ans_arr) {
        $more_ans_option[$num][$more_ans_arr['value']] = t($more_ans_arr['value']);
      }

      //Required answer option array (Option 1 and Option 2)
      $answer_options[$num] = array(
          $answer_op1 => t($answer_op1)
      );

      //Merge array of answer options and more answer options
      if(!empty($more_ans_option[$num])){
        //$all_ans_options[$num] = array_merge($answer_options[$num], $more_ans_option[$num]);
         $all_ans_options[$num] = $answer_options[$num] + $more_ans_option[$num];
      } else {
        $all_ans_options[$num] = $answer_options[$num];
      }
     
      //Show error message, if user tries to skip required question
      $form['messages'] = array(
          '#prefix' => '<div style="color:red" id="messages">',
          '#suffix' => '</div>'
      );
   
      //Prepare Question and Answer form
      $form['question_number' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<div class="question-number">' . ($num + 1) . ' of ' . $total_num_of_ques . '</div>',
          '#prefix' => '<div id="question-container-' . $num . '" class="question-container">'
      );
      $form['question_heading' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<div class="question-heading">' . $question . '</div>',
          
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
          '#markup' => '<div class="answer-heading">Answer: ' . $required . '</div> ',
      );

      if ($answer_type == 'textfield') { // Answer options for Textfield
        $txt_num = 0;
        foreach ($all_ans_options[$num] as $val_txt_option) {
          $form['answer_option' . $num . '_' . $txt_num] = array(
              '#title' => $val_txt_option,
              '#type' => $answer_type,
              '#size' => 30,
          );
          
          $form['answer_option_name' . $num . '_' . $txt_num] = array(
              '#type' => 'hidden',
              '#value' => $val_txt_option,
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
          $form['answer_option' . $num . '_' . $rating_num.'_name'] = array(
              '#type' => 'hidden',
              '#value' => $rating_option,
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
      
      if (!empty($media_type)) {
        if ($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif') {
        $form['media' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div>',
              '#markup' => '<img src="' . $media_path . '" height="100" width="130"/>',
            '#suffix' => '</div>',
        );
      } else {
        $form['media' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div>',
            '#markup' => '<video width="140" height="145" controls="controls">
                <source src="' . $media . '" type="video/mp4"> 
                 <object> 
                   <embed  src="' . $media . '"> 
                 </object> 
               </video>',
            '#suffix' => '</div>',
        );
      }
      }
      
      //Nex button for all questions
      $form['survey_submit_' . $num] = array(
        '#type' => 'submit',
        '#value' => $button_text,
        '#name' => 'surveysubmit_' . $num,
        '#ajax' => array(
            'callback' => 'survey_form_ajax_handler',
            'effect' => 'fade',
        ),
          '#attributes' => array('class' => array('survey-submit'))
      );
     
     //Skip button for all qustions except last one
      if ($skip_question[$num] == 'yes') {
        if (($total_num_of_ques - 1) !== $num) {
        $form['survey_submit_skip' . $num] = array(
            '#type' => 'submit',
            '#value' => 'Skip',
            '#name' => 'surveyskip_' . $num,
            '#ajax' => array(
                'callback' => 'survey_form_ajax_handler',
                'effect' => 'fade',
            ),
            '#suffix' => '</div>',
            '#attributes' => array('class' => array('survey-submit-skip'))
        );
      }
      } else {
          $form['close_question_container' . $num] = array(
            '#type' => 'markup',
            '#markup' => '</div>',
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
    
    $form['node'] = array(
        '#type' => 'hidden',
        '#value' => $node,
    );

    $form['textfield_total_count'] = array(
        '#type' => 'hidden',
        '#value' => $txt_num,
    );
    
    $form['rating_total_count'] = array(
        '#type' => 'hidden',
        '#value' => $rating_num,
    );
    
    $form['survey_url'] = array(
        '#type' => 'hidden',
        '#value' => $_GET['q'],
    );
    
    $form['survey_title'] = array(
        '#type' => 'hidden',
        '#value' => $node->title,
    );
    
   $form['survey_taken'] = array(
        '#type' => 'hidden',
        '#value' => $survey_taken
    );
    
  } else { //If no survey found
    $form['no_survey'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>Survey has been expired!</h2>',
    );
  }
  
  $form['#theme'] = array('itg_survey_form', $node);
  return $form;
}

/**
 * Validate functionality of survey form
 * @param Array $form
 * @param Array $form_state
 */
function itg_survey_survey_form_validate($form, &$form_state) {

  $cookie_name = 'Drupal_visitor_itgcms_survey_' . $form_state['values']['nid'];

  if (isset($_COOKIE[$cookie_name])) {
    form_set_error('answer_option', t('Sorry! You can not proceed, you have already taken this survey!'));
  } else {

    $btn_num_arr = explode('_', $form_state['clicked_button']['#name']);
    $num = $btn_num_arr[1];
    $button_name = $btn_num_arr[0];

    $form_detail = $form_state['values'];
    $ans_flag = FALSE;
    $txt_ans_flag = FALSE;
    $rating_ans_flag = FALSE;

    //Checkbox validation
    if ($form_detail['question_type' . $num] === 'checkboxes') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        foreach ($form_detail['answer_option' . $num] as $key => $value) {
          if ($value !== 0) {
            $ans_flag = TRUE;
          }
        }
        if (!$ans_flag) {
          if ($button_name == 'surveysubmit') {
            form_set_error('answer_option' . $num, t('Question "' . $form_detail['question' . $num] . '?" is required. Please select any answer option to proceed.'));
          } else {
            form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
          }
        }
      }
    }

    //Radio Button validation
    if ($form_detail['question_type' . $num] === 'radios') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        if (empty($form_detail['answer_option' . $num])) {
          if ($button_name == 'surveysubmit') {
            form_set_error('answer_option' . $num, t('Question "' . $form_detail['question' . $num] . '?" is required. Please select any answer option to proceed.'));
          } else {
            form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
          }
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
          if ($button_name == 'surveysubmit') {
            form_set_error('answer_option' . $num, t('Question "' . $form_detail['question' . $num] . '?" is required. Please provide your answer to proceed.'));
          } else {
            form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
          }
        }
      }
    }

    //Textfield validation
    if ($form_detail['question_type' . $num] === 'textfield') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        $txt_ans_flag = FALSE;
        for ($text_field = 0; $text_field < $form_detail['textfield_total_count']; $text_field++) {
          if ($form_detail['answer_option' . $num . '_' . $text_field] !== '') {
            $txt_ans_flag = TRUE;
          }
        }
        if (!$txt_ans_flag) {
          if ($button_name == 'surveysubmit') {
            form_set_error('answer_option' . $num, t('Question "' . $form_detail['question' . $num] . '?" is required. Please provide your answer to proceed.'));
          } else {
            form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
          }
        }
      }
    }
  }
}

/**
 * Submit handler for survey form
 * @param Array $form
 * @param Array $form_state
 */
function itg_survey_survey_form_submit($form, &$form_state){
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
  
  //Set a session for a survey(Will be same for all questions during a survey) 
  if(!isset($_SESSION['survey_unique_key'])){
    $_SESSION['survey_unique_key'] = user_password(6);
  }
  
  // Insert anwer value after each question
  if ($btn_num_arr[0] == 'surveysubmit') {
    
    // Insert for radio button type answer
    if ($form_state['values']['question_type' . $num] == 'radios') {

      db_insert('itg_survey_detail')
              ->fields(array(
                  'nid' => $form_state['values']['nid'],
                  'uid' => $user->uid,
                  'ques_id' => $form_state['values']['question_id' . $num],
                  'question' => $form_state['values']['question' . $num],
                  'answer' => strtolower($form_state['values']['answer_option' . $num]),
                  'ans_type' => $form_state['values']['question_type' . $num],
                  'user_type' => $user_type,
                  'page_url' => $form_state['values']['survey_url'],
                  'survey_title' => $form_state['values']['survey_title'],
                  'survey_key' => $_SESSION['survey_unique_key'],
                  'survey_info' => 0,
                  'created' => time(),
              ))
              ->execute();
    }

    // Insert for checkboxs type answer
    if ($form_state['values']['question_type' . $num] == 'checkboxes') {

      foreach ($form_state['values']['answer_option' . $num] as $key => $value) {
        if ($value) {
          db_insert('itg_survey_detail')
                  ->fields(array(
                      'nid' => $form_state['values']['nid'],
                      'uid' => $user->uid,
                      'ques_id' => $form_state['values']['question_id' . $num],
                      'question' => $form_state['values']['question' . $num],
                      'answer' => strtolower($value),
                      'ans_type' => $form_state['values']['question_type' . $num],
                      'user_type' => $user_type,
                      'page_url' => $form_state['values']['survey_url'],
                      'survey_title' => $form_state['values']['survey_title'],
                      'survey_key' => $_SESSION['survey_unique_key'],
                      'survey_info' => 0,
                      'created' => time(),
                  ))
                  ->execute();
        }
      }
    }

    // Insert for textfield type answer
    if ($form_state['values']['question_type' . $num] == 'textfield') {

      for ($text_field = 0; $text_field < $form_detail['textfield_total_count']; $text_field++) {
        if ($form_detail['answer_option' . $num . '_' . $text_field] !== '') {
          db_insert('itg_survey_detail')
                  ->fields(array(
                      'nid' => $form_state['values']['nid'],
                      'uid' => $user->uid,
                      'ques_id' => $form_state['values']['question_id' . $num],
                      'question' => $form_state['values']['question' . $num],
                      'answer' => strtolower($form_detail['answer_option_name' . $num . '_' . $text_field]),
                      'ans_type' => $form_state['values']['question_type' . $num],
                      'user_type' => $user_type,
                      'page_url' => $form_state['values']['survey_url'],
                      'survey_title' => $form_state['values']['survey_title'],
                      'survey_key' => $_SESSION['survey_unique_key'],
                      'survey_info' => 0,
                      'created' => time(),
                  ))
                  ->execute();
        }
      }
    }

    
    // Insert for rating type answer
    if ($form_state['values']['question_type' . $num] == 'rating') {

      for ($rating_field = 0; $rating_field < $form_detail['rating_total_count']; $rating_field++) {
        for ($rating_field_val = 1; $rating_field_val <= 5; $rating_field_val++) {
          if ($form_detail['answer_option' . $num . '_' . $rating_field][$rating_field_val] == 1) {
            db_insert('itg_survey_detail')
                    ->fields(array(
                        'nid' => $form_state['values']['nid'],
                        'uid' => $user->uid,
                        'ques_id' => $form_state['values']['question_id' . $num],
                        'question' => $form_state['values']['question' . $num],
                        'answer' => $form_detail['answer_option' . $num . '_' . $rating_field . '_name'] ? strtolower($form_detail['answer_option' . $num . '_' . $rating_field . '_name']) : $form_state['values']['question' . $num],
                        'ans_type' => $form_state['values']['question_type' . $num],
                        'user_type' => $user_type,
                        'page_url' => $form_state['values']['survey_url'],
                        'survey_title' => $form_state['values']['survey_title'],
                        'survey_key' => $_SESSION['survey_unique_key'],
                        'survey_info' => 0,
                        'created' => time(),
                    ))
                    ->execute();
          }
        }
      }
    }
  }
 
  //On final survey submit
  if(strtolower($form_state['clicked_button']['#value']) == 'submit') {
    
    //Set cookie for survey
    user_cookie_save(array('itgcms_survey_'.$form_state['values']['nid'] => 1));
    
    //Insert in to survey user table
    db_insert('itg_survey_user')
            ->fields(array(
                'nid' => $form_state['values']['nid'],
                'uid' => $user->uid,
                'user_type' => $user_type,
                'page_url' => $_GET['q'],
                'created' => time(),
            ))
            ->execute();
    
    //Update table and set survey_info(status) = 1, means this survey has been completed by a user 
    db_update('itg_survey_detail')
            ->fields(array(
                'survey_info' => 1,
            ))
            ->condition('survey_key', $_SESSION['survey_unique_key'], '=')
            ->execute();
    
    unset($_SESSION['survey_unique_key']);
  }

  //Display message on final submit.
  if ($num == ($form_detail['question_total'] - 1)) {
    drupal_set_message(t('Survey has been saved successfully. Thank you for taking our survey!'));
  }
}

/**
 * Submit handler of Ajax
 * @param Array $form
 * @param Array $form_state
 * @return Array
 */
function survey_form_ajax_handler(&$form, &$form_state){
  $commands = array();
  $commands[] = ajax_command_replace('#messages', '<div id="messages">' . theme('status_messages') . '</div>');
  return array(
      '#type' => 'ajax',
      '#commands' => $commands);
}

?>

