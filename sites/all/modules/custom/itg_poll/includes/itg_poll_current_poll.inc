<?php

/**
 * Implementation of itg_poll_get_all_current_poll()
 * @return string
 */

function itg_poll_get_all_current_poll() {
    $polls_info = array();
    $total_polls = get_total_count_polls();
    $list = itg_poll_get_all_current_poll_qry(); 
    $polls_info['list'] = $list;
    $polls_info['count'] = $total_polls;
    return theme('itg_poll_list_all_forms', array('data' => $polls_info));
}


/**
 * Implementation of itg_poll_get_all_past_poll()
 * @return string
 */

function itg_poll_get_all_past_poll() {
    $polls_info = array();
    return theme('itg_poll_list_all_past_polls', array('data' => $polls_info));
}


/**
 * Implementation of itg_poll_get_all_current_poll_qry()
 * @return array
 */

function itg_poll_get_all_current_poll_qry() {
    
    try{
         
    $current_index  = isset($_GET['poll_index']) && !empty($_GET['poll_index']) ? $_GET['poll_index']:0;  
    
    $cur_date = date('Y-m-d H:i:s');
    $query = db_select('node', 'n');
    $query->leftjoin('field_data_field_poll_start_date', 'sd', 'n.nid = sd.entity_id');
    $query->leftjoin('field_data_field_poll_end_date', 'ed', 'n.nid = ed.entity_id');
    $query->fields('n', array('nid'));
    $query->fields('sd',array('field_poll_start_date_value'));
    $query->fields('ed',array('field_poll_end_date_value'));
    $query->condition('n.type','poll','=');
    $query->condition('n.status',1,'=');
    $query->condition('sd.field_poll_start_date_value', $cur_date, '<=');
    $query->condition(db_or()->isNull('ed.field_poll_end_date_value')->condition('ed.field_poll_end_date_value', $cur_date, '>='));
    $query->range($current_index, 1);

    $data  = array();
    $result = $query->execute();
        while($record = $result->fetchObject()) {
           $data  = $record;
     }   
     return $data;
    } 
    catch(Exception $e){
    watchdog('Error while fatching POLLS:'.$e->getMessage());    
    }   
}

/**
 * Implementation of hook_form().
 * @param array $form
 * @param array reference $form_state
 * @param array $parms
 * @return array
 */
function itg_poll_form_new($form, &$form_state, $nid) {
  $form = array();
  $form['#id'] = 'subsPollForm';
  $form["wrapper"] = array(
    "#markup" => "<div class='inline-messages-".$nid."'></div>",
  );
  
  //foreach ($parms as $item):
    $node = node_load($nid);
    foreach ($node->field_poll_answer['und'] as $row) {
      $item_id[] = $row['value']; // fieldcollection id
    }
    // instant or after complete
    $display_result = isset($node->field_display_result[LANGUAGE_NONE]) ? $node->field_display_result[LANGUAGE_NONE][0]['value'] : '';

    $fieldcollect = entity_load('field_collection_item', $item_id);
    if (is_array($fieldcollect) && count($fieldcollect) > 0) {

      foreach ($fieldcollect as $key => $temp_ent) {
        $poll_answer_text = isset($temp_ent->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
        $poll_answer_image = isset($temp_ent->field_poll_answer_image[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_image[LANGUAGE_NONE][0]['fid'] : '';
        $poll_caption_text = isset($temp_ent->field_ans_caption[LANGUAGE_NONE]) ? $temp_ent->field_ans_caption[LANGUAGE_NONE][0]['value'] : '';
        if (isset($poll_answer_image) && $poll_answer_image > 0) {
          $poll_image = theme('image_style', array('style_name' => 'thumbnail', 'path' => file_load($poll_answer_image)->uri)) . '<br /><span class="poll-ans-caption">' . $poll_caption_text . '</span>';
          $poll_answer[$key] = isset($poll_image) ? $poll_image : '';
        }
        else {
          $poll_answer[$key] = isset($poll_answer_text) ? $poll_answer_text . '<br /><span class="poll-ans-caption">' . $poll_caption_text . '</span>' : '';
        }
      }
    }
  //endforeach;
  $form['pole_answer'] = array(
    '#type' => 'radios',
    '#options' => $poll_answer,
    '#prefix' => '<div class="poll-main-wrap-'.$nid.'">',
    '#suffix' => '</div><span class="poll-ans-error-'.$nid.'"></span>',
  );

  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );

  $form['argument_current_nid'] = array(
    '#type' => 'hidden',
    '#value' => arg(1),
  );

  $form['display_result'] = array(
    '#type' => 'hidden',
    '#value' => $display_result,
  );

//  $form['captcha'] = array(
//    '#type' => 'captcha',
//    '#captcha_type' => 'recaptcha/reCAPTCHA',
//    '#prefix' => '<span class="poll-ajax-error"></span>',
//  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#ajax' => array(
      'callback' => 'itg_poll_form_new_ajax_submit',
      'effect' => 'fade',
      'progress' => array('type' => 'throbber', 'message' => ''),
      'validate_first' => TRUE,
    ),
  );
  
  
  return $form;
}


function itg_poll_form_new_call($data = array()) {
  for ($i=0; $i < count($data); $i++) {
    $output  = drupal_get_form("itg_poll_form_new" . $i, $data[$i]);
  }
  return $output;
}

function get_total_count_polls() {
    $cur_date = date('Y-m-d H:i:s');
    $query = db_select('node', 'n');
    $query->leftjoin('field_data_field_poll_start_date', 'sd', 'n.nid = sd.entity_id');
    $query->leftjoin('field_data_field_poll_end_date', 'ed', 'n.nid = ed.entity_id');
    $query->fields('n', array('nid'));
    $query->fields('sd',array('field_poll_start_date_value'));
    $query->fields('ed',array('field_poll_end_date_value'));
    $query->condition('n.type','poll','=');
    $query->condition('n.status',1,'=');
    $query->condition('sd.field_poll_start_date_value', $cur_date, '<=');
    $query->condition(db_or()->isNull('ed.field_poll_end_date_value')->condition('ed.field_poll_end_date_value', $cur_date, '>='))
          ->execute();
    
    return $query->countQuery()->execute()->fetchField();
}