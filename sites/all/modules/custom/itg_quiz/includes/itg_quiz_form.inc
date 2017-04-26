<?php

/**
 * @file: itg_quiz_form.inc
 */

/**
 * Create quiz form
 */
function itg_quiz_quiz_form($form, &$form_state, $node_id = NULL) {
  global $base_url;
  global $user;
  
  if($user->uid) {
  $cookie = $_COOKIE['Drupal_visitor_itgcms_quiz_'.arg(1).'_'.$user->uid];
  } else {
   $cookie = $_COOKIE['Drupal_visitor_itgcms_quiz_'.arg(1)];  
  }
  //Get node of current quiz (load all questions ans answer options to generate quiz form)
  if ($node_id) {
    $current_nid = $node_id;
    $from_story = 'yes';
  }
  else {
    $current_nid = arg(1);
    $from_story = 'no';
  }
  $node = node_load($current_nid);

  // Check for type
  if ($node->type == 'quiz') {

    // Add JS for front
    drupal_add_js(drupal_get_path('module', 'itg_quiz') . '/js/itg_quiz_front.js');

    // If quiz is not published
    if (!$node->status) {
      $form['survey_status'] = array(
          '#type' => 'markup',
          '#markup' => '<div style="margin-top:10px"><h2>Quiz "' . $node->title . '" is not published!</h2></div>',
      );
      return $form;
    }

    // Quiz start date and expiry date restrictions
    $quiz_start_date = strtotime($node->field_survey_start_date[LANGUAGE_NONE][0]['value']);
    $quiz_expiry_date = strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'] . ' + 23 hours');
    if (time() < $quiz_start_date) {
      $form['quiz_start_status'] = array(
          '#type' => 'markup',
          '#markup' => '<div style="margin-top:10px"><h2>You can not attempt quiz "' . $node->title . '!" Start Date: ' . date('d/m/Y', strtotime($node->field_survey_start_date[LANGUAGE_NONE][0]['value'])) . '</h2></div>',
      );
      return $form;
    }
//    if(time() > $quiz_expiry_date) {
//       $form['quiz_expiry_status'] = array(
//         '#type' => 'markup',
//         '#markup' => '<div style="margin-top:10px"><h2>Quiz "'.$node->title.'" has been expired!</h2></div>',
//      );
//       return $form;
//     }
    // Creation of quiz form 
    $num = 0;
    $form = array();

    // Check this survey has been attempted by current user OR not.
    if ($user->uid) {
      $cookie_name = 'Drupal_visitor_itgcms_quiz_' . $node->nid . '_' . $user->uid;
    }
    else {
      $cookie_name = 'Drupal_visitor_itgcms_quiz_' . $node->nid;
    }

    if (isset($_COOKIE[$cookie_name])) {
      $quiz_taken = 'yes';
    }
    else {
      $quiz_taken = 'no';
    }

    // Quiz global settings
    $question_display = $node->field_quiz_display_sequence[LANGUAGE_NONE][0]['value'];
    $quiz_no_of_winners = $node->field_quiz_winners[LANGUAGE_NONE][0]['value'];
    $quiz_type = $node->field_quiz_type[LANGUAGE_NONE][0]['value']; //immediate/contest_type
    $quiz_result_type = $node->field_quiz_immediate_result[LANGUAGE_NONE][0]['value']; //qwr/ate
    $quiz_score_type = $node->field_quiz_type[LANGUAGE_NONE][0]['value'];

    // Add JS for one question at a time
    $quiz_question_format = $node->field_survey_questions_format[LANGUAGE_NONE][0]['value'];
    if ($quiz_question_format == 'One question at a time') {
      drupal_add_js(drupal_get_path('module', 'itg_quiz') . '/js/itg_quiz_questions.js');
    }

    // If question display type is "random", shuffle the array
    if ($question_display == 'random') {
      foreach ($node->field_quiz_add_questions[LANGUAGE_NONE] as $ques_arr_for_shuffle) {
        $ques_arr_shuffle[] = $ques_arr_for_shuffle['value'];
      }
      shuffle($ques_arr_shuffle);

      foreach ($ques_arr_shuffle as $ques_arr_new) {
        $ques_arr[]['value'] = $ques_arr_new;
      }
    }
    else {
      $ques_arr = $node->field_quiz_add_questions[LANGUAGE_NONE];
    }

    // Count total no. of questions for a quiz
    $total_num_of_ques = count($ques_arr);

    // Parent loop for generate quiz form
    foreach ($ques_arr as $question_arr) {
      // Question Details
      $question_detail = entity_load('field_collection_item', array($question_arr['value']));
      $question = $question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value'];
      $question_weightage = $question_detail[$question_arr['value']]->field_quiz_weightage[LANGUAGE_NONE][0]['value'];

      // Answer type segregation
      $answer_type_type = $question_detail[$question_arr['value']]->field_quiz_answer_type[LANGUAGE_NONE][0]['value'];
      if ($answer_type_type == 'single_correct') {
        $answer_type = 'radios';
      }
      else {
        $answer_type = 'checkboxes';
      }
      // Loop for answer details
      $all_ans_options_media = '';
      $answer_option = $question_detail[$question_arr['value']]->field_quiz_option[LANGUAGE_NONE][0]['value'];
      foreach ($question_detail[$question_arr['value']]->field_quiz_options_answer[LANGUAGE_NONE] as $ans_option) {
        $ans_option_arr = entity_load('field_collection_item', array($ans_option['value']));

        // Prepare array of correct answers
        $option_class = 'wrong-answer';
        if (!empty($ans_option_arr[$ans_option['value']]->field_quiz_correct_answer[LANGUAGE_NONE])) {
          foreach ($ans_option_arr[$ans_option['value']]->field_quiz_correct_answer[LANGUAGE_NONE] as $currect_ans) {
            if ($currect_ans['value'] == 'Yes') {
              $option_class = 'right-answer';
              $correct_ans_op[$num][] = $ans_option['value'];
            }
          }
        }

        // Prepare array of answer options
        foreach ($ans_option_arr[$ans_option['value']]->field_quiz_answer_text[LANGUAGE_NONE] as $final_ans_op) {
          $all_ans_options[$num][$ans_option['value'] . '-' . $final_ans_op['value']] = "<span class='" . $option_class . "'>" . $final_ans_op['value'] . '</span>';
        }

        // Photo options
        if ($answer_option == 'Photo') {
          foreach ($ans_option_arr[$ans_option['value']]->field_quiz_answer_image[LANGUAGE_NONE] as $final_ans_op) {
            $all_ans_options_media .= '<div class="quiz-media-file">' . theme('image_style', array('style_name' => 'thumbnail', 'path' => $final_ans_op['uri'])) . '</div>';
          }
        }

        // Video options
        $ans_media = "";
        if ($answer_option == 'Video') {
          foreach ($ans_option_arr[$ans_option['value']]->field_quiz_answer_video[LANGUAGE_NONE] as $final_ans_op) {
            if (function_exists('itg_videogallery_get_videoid_new')) {
          $video_ids = itg_videogallery_get_videoid_new($final_ans_op['fid']);
           $ans_media = '<iframe width="130" height="100" frameborder="0" scrolling="no"
                                                src="https://www.dailymotion.com/embed/video/'.$video_ids.'?autoplay=0&ui-logo=1&mute=1&ui-start-screen-info"
                                                allowfullscreen></iframe>';
        }
            $all_ans_options_media .= '<div class="quiz-media-file">
              '.$ans_media.'
               </div>';
          }
        }
      }
$question_media = "";
      //Media information
//      $media = $question_detail[$question_arr['value']]->field_survey_add_media[LANGUAGE_NONE][0]['uri'];
//      $media_type = strtolower(substr(strrchr($media, '.'), 1));
//      $media_path = $base_url . str_replace('public://', '/sites/default/files/', $media);
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


      // Submit button text
      if (($total_num_of_ques - 1) === $num) {
        $button_text = 'Submit';
      }
      else {
        $button_text = 'Next';
      }

      // Show error message, if user tries to skip required question
      $form['messages'] = array(
          '#prefix' => '<div style="color:red" id="messages">',
          '#suffix' => '</div>'
      );

      // Main container
      $form['question_container' . $num] = array(
          '#type' => 'markup',
          '#markup' => '',
          '#prefix' => '<div id="question-container-' . $num . '" class="question-container">'
      );

      // Show current question no.
      if ($quiz_question_format == 'One question at a time') {
        $form['question_number' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div class="question-number">' . ($num + 1) . ' of ' . $total_num_of_ques . '</div>',
        );
      }

      // Question text
      $form['question_heading' . $num] = array(
          '#type' => 'markup',
          '#markup' => '<div class="question-heading">' . $question . '</div>',
      );

      // Question Media Section
   //   if (!empty($media_type)) {
        //if ($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif') {
          $form['media' . $num] = array(
              '#type' => 'markup',
              '#prefix' => '<div>',
              '#markup' => $question_media,
              '#suffix' => '</div>',
          );
//        }
//        else {
//          $form['media' . $num] = array(
//              '#type' => 'markup',
//              '#prefix' => '<div>',
//              '#markup' => '<video width="730" height="500" controls="controls">
//               <source src="' . $media . '" type="video/mp4"> 
//                <object> 
//                  <embed  src="' . $media . '"> 
//                </object> 
//               </video>',
//              '#suffix' => '</div>',
//          );
//        }
     // }

      $items = field_get_items('node', $node, 'field_quiz_add_questions');

      if (!empty($items)) {
        foreach ($items as $item) {
          $fc = field_collection_field_get_entity($item);
        }
      }

      // Answer Section
      //if($node->field_quiz_immediate_result[LANGUAGE_NONE][0]['value'] == 'qwr' && $fc->field_quiz_answer_type[LANGUAGE_NONE][0]['value'] == 'multiple_correct') {
      if ($node->field_quiz_immediate_result[LANGUAGE_NONE][0]['value'] == 'qwr' && $quiz_type == 'immediate') {
        $form['answer' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div id="answer-container-' . $num . '" class="answer-container answer_block_' . $num . '">',
            '#suffix' => '<div id="answer-response-' . $question_arr['value'] . '" class="answer-container-actual"></div><button data-type="' . $num . '" id="show_answer" class="answer' . $num . '">Show answer</button>',
        );
      }
      else {
        $form['answer' . $num] = array(
            '#type' => 'markup',
            '#prefix' => '<div id="answer-container-' . $num . '" class="answer-container">',
            '#suffix' => '<div id="answer-response-' . $question_arr['value'] . '" class="answer-container-actual"></div>',
        );
      }

      if ($answer_option == 'Photo' || $answer_option == 'Video') {
        $form['answer_option' . $num] = array(
            '#prefix' => '<div class="quiz-media-container">' . $all_ans_options_media . '</div>',
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
            '#suffix' => '</div>',
        );
      }
      else {
        $form['answer_option' . $num] = array(
            '#title' => t(''),
            '#type' => $answer_type,
            '#options' => $all_ans_options[$num],
            '#suffix' => '<span class="sss"></span></div>',
                //'#suffix' => '</div><div id=answer_option' . $num.'><a href="javascript:void(0)" class="associate-content-block" data-widget="echo $associate_type;-echo $associate_id;">click here</a></div>',
        );
      }




      $form['correct_answer' . $num] = array(
          '#type' => 'hidden',
          '#value' => $correct_ans_op[$num],
      );

      // Hidden variables
      $form['question' . $num] = array(
          '#type' => 'hidden',
          '#value' => $question,
      );

      if ($quiz_score_type == 'normal') {
        $form['question_weightage_' . $question_arr['value']] = array(
            '#type' => 'hidden',
            '#value' => 1,
        );
      }
      else {
        $form['question_weightage_' . $question_arr['value']] = array(
            '#type' => 'hidden',
            '#value' => $question_weightage,
        );
      }

      $form['question_id' . $num] = array(
          '#type' => 'hidden',
          '#value' => $question_arr['value'],
      );

      $form['question_skip' . $num] = array(
          '#type' => 'hidden',
          '#value' => 'yes',
          '#attributes' => array('id' => array('question-skip-' . $num), 'class' => array('question-skip'))
      );

      $form['question_type' . $num] = array(
          '#type' => 'hidden',
          '#value' => $answer_type,
          '#attributes' => array('id' => array('question-type-' . $num))
      );

      // Next button for all questions, if type is "One question at a time"
      if ($quiz_question_format == 'One question at a time') {
        if ($button_text == 'Submit' && time() > $quiz_expiry_date) {
          $form['quiz_has_been_expired' . $num] = array(
              '#type' => 'markup',
              '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>This quiz has been expired. So you can not submit!</strong></div>',
          );
        } elseif(isset($cookie)){
        $form['quiz_has_been_already_taken' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>Sorry! You can not proceed, you have already taken this Quiz!</strong></div>',
        );
        }
        else {
          $form['quiz_submit_' . $num] = array(
              '#type' => 'submit',
              '#value' => $button_text,
              '#prefix' => '<div class="quiz-submit-btn-wrapper">',
              '#name' => 'quizsubmit_' . $num,
              //'#suffix' => '</div>',
              '#ajax' => array(
                  'callback' => 'quiz_form_ajax_handler',
                  'effect' => 'fade',
              ),
              '#attributes' => array('class' => array('quiz-submit')),
              '#suffix' => '</div></div>'
          );
        }
      }

      if ($quiz_question_format == 'All questions at a time') {
        $form['close_question_container' . $num] = array(
            '#type' => 'markup',
            '#markup' => '</div>',
        );
      }

      $num++;
    } //End of main loop
    // Variables for a quiz (Hidden variables)
    $form['question_total'] = array(
        '#type' => 'hidden',
        '#value' => $total_num_of_ques,
    );

    $form['question_format'] = array(
        '#type' => 'hidden',
        '#value' => $quiz_question_format,
    );

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $node->nid,
    );

    $form['node'] = array(
        '#type' => 'hidden',
        '#value' => $node,
    );

    $form['no_of_winners'] = array(
        '#type' => 'hidden',
        '#value' => $quiz_no_of_winners,
    );

    $form['quiz_url'] = array(
        '#type' => 'hidden',
        '#value' => $_GET['q'],
    );

    $form['quiz_title'] = array(
        '#type' => 'hidden',
        '#value' => $node->title,
    );

    $form['quiz_taken'] = array(
        '#type' => 'hidden',
        '#value' => $quiz_taken
    );

    $form['quiz_type'] = array(
        '#type' => 'hidden',
        '#value' => $quiz_type,
    );

    $form['quiz_resut_type'] = array(
        '#type' => 'hidden',
        '#value' => $quiz_result_type,
    );

    $form['from_story'] = array(
        '#type' => 'hidden',
        '#value' => $from_story,
    );

    // Single submit button, if all questions are showing at once
    if ($quiz_question_format == 'All questions at a time') {

      if (time() > $quiz_expiry_date) {
        $form['quiz_has_been_expired' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>This quiz has been expired. So you can not submit!</strong></div>',
        );
      } elseif(isset($cookie)){
        $form['quiz_has_been_already_taken' . $num] = array(
            '#type' => 'markup',
            '#markup' => '<div style="margin: 10px 0px 20px 0px;"><strong>Sorry! You can not proceed, you have already taken this Quiz!</strong></div>',
        );
      }
      else {
        $form['quiz_submit_' . $num] = array(
            '#type' => 'submit',
            '#value' => 'Submit',
            '#prefix' => '<div class="quiz-submit-btn-wrapper">',
            '#name' => 'quizsubmit_' . $num,
            '#ajax' => array(
                'callback' => 'quiz_form_ajax_handler',
                'effect' => 'fade',
            ),
            '#attributes' => array('class' => array('quiz-submit')),
            '#suffix' => '</div>'
        );
      }
    }
  }
  else {
    drupal_not_found();
  }

  $form['#theme'] = array('itg_quiz_form', $node);
  return $form;
}
