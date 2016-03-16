<?php

/**
 * @file: itg_survey_form.inc
 */


/**
 * Create survey form
 */
function itg_survey_survey_form() {
  
  //Get node of current survey (load all questions ans answer options to generate survey form)
  $node = itg_survey_get_current_survey();

  //Check: Any survey is activated OR not
  if ($node) {
    
    //Add survey JS file
    //drupal_add_js(drupal_get_path('module', 'itg_survey').'/js/itg_survey.js');
    
    $num = 0;
    $form = array();

    $total_num_of_ques = count($node->field_survey_add_questions[LANGUAGE_NONE]);
    
    foreach ($node->field_survey_add_questions[LANGUAGE_NONE] as $question_arr) {

      //Question Info
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));
      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];
      $skip_question[$num] = $question_detail[$question_arr['value']]->field_survey_skip[LANGUAGE_NONE][0]['value'];

      if ($skip_question[$num] == 'yes') {
        $required = '';
      } else {
        $required = '<span style="color:red">*</span>';
      }

      //Answer Info
      $answer_type = $question_detail[$question_arr['value']]->field_survey_answer_type[LANGUAGE_NONE][0]['value'];
      $answer_op1 = $question_detail[$question_arr['value']]->field_survey_answer_option_1[LANGUAGE_NONE][0]['value'];
      $answer_op2 = $question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE][0]['value'];
      
      //Submit button text
      if(($total_num_of_ques-1) === $num){
        $button_text = 'Submit';
      } else {
        $button_text = 'Next';
      }

      //Get more answer options
      foreach ($question_detail[$question_arr['value']]->field_survey_answer_option_more[LANGUAGE_NONE] as $more_ans_arr) {
        $more_ans_option[$num][$more_ans_arr['value']] = t($more_ans_arr['value']);
      }


      //Required answer option array
      $answer_options[$num] = array(
          $answer_op1 => t($answer_op1),
          $answer_op2 => t($answer_op2),
      );

      //Array collection of both arrays
      if(!empty($more_ans_option[$num])){
        $all_ans_options[$num] = array_merge($answer_options[$num], $more_ans_option[$num]);
      } else {
        $all_ans_options[$num] = $answer_options[$num];
      }
     
      //Show error message
      $form['messages'] = array(
          '#prefix' => '<div style="color:red" id="messages">',
          '#suffix' => '</div>'
      );
      
      //Prepare form
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

      if ($answer_type == 'textfield') {
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
        
      } elseif ($answer_type == 'rating') {
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
      } else {
        $form['answer_option' . $num] = array(
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
            '#suffix' => '</div>',
        );
      }
      
      if(($total_num_of_ques-1) != $num){
        $form['survey_submit_skip' . $num] = array(
            '#type' => 'submit',
            '#value' => 'Skip',
            '#name' => 'surveysubmit_' . $num,
            '#ajax' => array(
                'callback' => 'survey_form_ajax_handler',
                'effect' => 'fade',
            ),
            '#attributes' => array('class' => array('survey-submit-skip'))
        );
      }
      
      $form['survey_submit_' . $num] = array(
        '#type' => 'submit',
        '#value' => $button_text,
        '#name' => 'surveysubmit_' . $num,
        '#ajax' => array(
            'callback' => 'survey_form_ajax_handler',
            'effect' => 'fade',
        ),
          '#suffix' => '</div>',
          '#attributes' => array('class' => array('survey-submit'))
      );

      $num++;
      
    } //End of for loop

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

//    $form['survey_submit'] = array(
//        '#type' => 'submit',
//        '#value' => 'Submit',
//    );
    
  } else { //If no survey found
    $form['no_survey'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>Survey has been expired!</h2>',
    );
  }

  return $form;
}

/**
 * Validate functionality of survey form
 * @param Array $form
 * @param Array $form_state
 */
function itg_survey_survey_form_validate($form, &$form_state) {
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
  
  //Insert question & answer in to DB
  db_insert('itg_survey_user')
          ->fields(array(
              'nid' => $form_state['values']['nid'],
              'uid' => $user->uid,
              'user_type' => $user_type,
              'page_url' => $_GET['q'],
              'created' => time(),
          ))
          ->execute();

  //Display saved survey message on final submit only.
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

