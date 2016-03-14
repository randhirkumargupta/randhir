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
    $num = 0;
    $form = array();

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
      $all_ans_options[$num] = array_merge($answer_options[$num], $more_ans_option[$num]);


      //Prepare form
      $form['question_heading' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<h2>' . ($num + 1) . '. ' . $question . '?</h2>',
      );

      $form['answer' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<h2>Answer: ' . $required . '</h2> ',
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
      );

      $form['question_type' . $num] = array(
          '#type' => 'hidden',
          '#value' => $answer_type,
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
      } else {
        $form['answer_option' . $num] = array(
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
        );
      }

      $num++;
    } //End of for loop

    $form['question_total'] = array(
        '#type' => 'hidden',
        '#value' => $num,
    );

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $node->nid,
    );
    
   $form['textfield_val'] = array(
        '#type' => 'hidden',
        '#value' => $txt_num,
    );
   
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
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
function itg_survey_survey_form_validate($form, &$form_state){

  $form_detail = $form_state['values'];
  $ans_flag = FALSE;
  
  for ($num = 0; $num < $form_detail['question_total']; $num++) {
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
    } elseif ($form_detail['question_type' . $num] === 'radios') {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        if (empty($form_detail['answer_option' . $num])) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
        }
      }
    } else {
      if ($form_detail['question_skip' . $num] !== 'yes') {
        $txt_ans_flag = FALSE;
        for ($text_field = 0; $text_field < $form_detail['textfield_val']; $text_field++) {
          if ($form_detail['answer_option' . $num . '_' . $text_field] !== '') {
            $txt_ans_flag = TRUE;
          }
        }
        if (!$txt_ans_flag) {
          form_set_error('answer_option' . $num, t('You can not skip question "' . $form_detail['question' . $num] . '?"'));
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
  if ($user->uid) {
    $user_type = 'authenticated';
  } else {
    $user_type = 'anonymous';
  }
  db_insert('itg_survey_user')
          ->fields(array(
              'nid' => $form_state['values']['nid'],
              'uid' => $user->uid,
              'user_type' => $user_type,
              'page_url' => $_GET['q'],
              'created' => time(),
          ))
          ->execute();
  drupal_set_message(t('Survey has been saved successfully.'));
}

?>

