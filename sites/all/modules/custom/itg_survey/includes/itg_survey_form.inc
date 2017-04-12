<?php

/**
 * @file: itg_survey_form.inc
 */


/**
 * Create survey form
 */
function itg_survey_survey_form($form, &$form_state, $node_id = NULL) {
  global $base_url;
  global $user;
  if($user->uid) {
  $cookie = $_COOKIE['Drupal_visitor_itgcms_survey_'.arg(1).'_'.$user->uid];
  } else {
   $cookie = $_COOKIE['Drupal_visitor_itgcms_survey_'.arg(1)];  
  }
  
  //Get node of current survey
  if($node_id) {
    $current_nid = $node_id;
    $from_story = 'yes';
  }
  else {
    $current_nid = arg(1);
    $from_story = 'no';
  }
  $node = node_load($current_nid);
  
  // Check node type
  if ($node->type == 'survey') {
    
    // Add JS for front
    drupal_add_js(drupal_get_path('module', 'itg_survey') . '/js/itg_survey_front.js');
    
    // Survey End date
    $survey_expiry_date = strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'] . ' + 23 hours');
    
    // If survey is not published
    if(!$node->status) {
      $form['survey_status'] = array(
        '#type' => 'markup',
        '#markup' => '<div style="margin-top:10px"><h2>This survey is not published!</h2></div>',
     );
      return $form;
    }
    
   // If survey has been expired. 
//   if(time() > $survey_expiry_date) {
//      $form['survey_expiry_status'] = array(
//        '#type' => 'markup',
//        '#markup' => '<div style="margin-top:10px"><h2>This survey has been expired!</h2></div>',
//     );
//      return $form;
//    }
    
    $survey_question_format = $node->field_survey_questions_format[LANGUAGE_NONE][0]['value'];
    
    // Add JS for one question at a time
    if($survey_question_format == 'One question at a time') {
      drupal_add_js(drupal_get_path('module', 'itg_survey') . '/js/itg_survey_questions.js');
    }
    
    $num = 0;
    $form = array();
    
    // Generate cookie
    if($user->uid) {
      $cookie_name = 'Drupal_visitor_itgcms_survey_' .$node->nid . '_' . $user->uid;
    } else {
      $cookie_name = 'Drupal_visitor_itgcms_survey_' . $node->nid;
    }
    
    // Check this survey has been attempted by current user OR not.
    if (isset($_COOKIE[$cookie_name])) {
      $survey_taken = 'yes';
    } else {
      $survey_taken = 'no';
    }
    
    $question_display = $node->field_survey_question_display[LANGUAGE_NONE][0]['value'];
    if ($question_display == 'random') {
      foreach ($node->field_survey_add_questions[LANGUAGE_NONE] as $ques_arr_for_shuffle){
        $ques_arr_shuffle[] = $ques_arr_for_shuffle['value'];
      }
      shuffle($ques_arr_shuffle);
      
      foreach($ques_arr_shuffle as $ques_arr_new){
          $ques_arr[]['value'] = $ques_arr_new;
      }
    }
    else {
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
//      $media = $question_detail[$question_arr['value']]->field_survey_add_media[LANGUAGE_NONE][0]['uri'];
//      $media_type = strtolower(substr(strrchr($media, '.'), 1));
//      $media_path = $base_url.str_replace('public://', '/sites/default/files/', $media);
       if ($question_detail[$question_arr['value']]->field_question_media[LANGUAGE_NONE][0]['value'] == 'Video') {

         $videid = $question_detail[$question_arr['value']]->field_question_video[LANGUAGE_NONE][0]['fid'];

         if (function_exists('itg_videogallery_get_videoid_new')) {
          $video_ids = itg_videogallery_get_videoid_new($videid);
           $question_media = '<iframe width="740" height="447" frameborder="0" scrolling="no"
                                                src="https://www.dailymotion.com/embed/video/'.$video_ids.'?autoplay=0&ui-logo=1&mute=1&ui-start-screen-info"
                                                allowfullscreen></iframe>';
        }
      }
      if ($question_detail[$question_arr['value']]->field_question_media[LANGUAGE_NONE][0]['value'] == 'Photo') {
         $question_media_uri = $question_detail[$question_arr['value']]->field_question_image[LANGUAGE_NONE][0]['uri'];
                   $extra_large_image_url = image_style_url("image750x447", $question_media_uri);

        $question_media = '<img src="' . $extra_large_image_url . '" width="750" alt="" />';
        }

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
   
      // Question container
      $form['question_container' . $num] = array(
            '#type' => 'markup',
            '#markup' => '',
            '#prefix' => '<div id="question-container-' . $num . '" class="question-container">'
      );
      
      if ($survey_question_format == 'One question at a time') {
        $form['question_number' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div class="question-number">' . ($num + 1) . ' of ' . $total_num_of_ques . '</div>',
        );
      }
      
      $form['question_heading' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<div class="question-heading">' . $question . ' ' . $required. '</div>',
          
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
      ); 

      if ($answer_type == 'textfield') { // Answer options for textfield
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
        
      } elseif ($answer_type == 'rating') { // Answer option for rating
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
        
      } else {  //Answer option for radios and checkboxes
        $form['answer_option' . $num] = array(
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
        );
      }
      
    
         $form['media' . $num] = array(
              '#type' => 'markup',
              '#prefix' => '<div>',
              '#markup' => $question_media,
              '#suffix' => '</div>',
          );
      
      $form['answer_option' . $num . '_' . $txt_num]['#suffix'] = '</div>';
      
      // Render multiple submit buttons, if questions are displaying one-by-one
      if ($survey_question_format == 'One question at a time') {
        if ($button_text == 'Submit' && time() > $survey_expiry_date) {
          $form['survey_has_been_expired' . $num] = array(
              '#type' => 'markup',
              '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>This Survey has been expired. So you can not submit!</strong></div>',
          );
        } elseif(isset($cookie)){
        $form['survey_has_been_already_taken' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>Sorry! You can not proceed, you have already taken this survey!</strong></div>',
        );
        } else {
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
        }
    
        // Skip button for all qustions except last one
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
      }
      
      if($survey_question_format == 'All questions at a time') {
          $form['close_question_container' . $num] = array(
              '#type' => 'markup',
              '#markup' => '</div>',
          );
      }
      
      $num++;
      
    } //End of foreach loop

    //Hidden variable, same for all questions  
    $form['question_total'] = array(
        '#type' => 'hidden',
        '#value' => $total_num_of_ques,
    );
    
    $form['question_format'] = array(
        '#type' => 'hidden',
        '#value' => $survey_question_format,
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
    
    $form['from_story'] = array(
        '#type' => 'hidden',
        '#value' => $from_story,
    );
    
   $form['survey_taken'] = array(
        '#type' => 'hidden',
        '#value' => $survey_taken
    );
   
   // Render a single submit button, if all questions are showing at once
   if($survey_question_format == 'All questions at a time') {
     if (time() > $survey_expiry_date) {
        $form['survey_has_been_expired' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>This Survey has been expired. So you can not submit!</strong></div>',
        );
      } 
      elseif(isset($cookie)){
        $form['survey_has_been_already_taken' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>Sorry! You can not proceed, you have already taken this survey!</strong></div>',
        );
      } else {
        $form['survey_submit_' . $num] = array(
            '#type' => 'submit',
            '#value' => 'Submit',
            '#prefix' => '<div class="survey-submit-btn-wrapper">',
            '#name' => 'surveysubmit_' . $num,
            '#ajax' => array(
                'callback' => 'survey_form_ajax_handler',
                'effect' => 'fade',
            ),
            '#attributes' => array('class' => array('survey-submit')),
            '#suffix' => '</div>'
        );
      }
    }
  }
  else {
    drupal_not_found();
  }
  
  $form['#theme'] = array('itg_survey_form', $node);
  return $form;
}

