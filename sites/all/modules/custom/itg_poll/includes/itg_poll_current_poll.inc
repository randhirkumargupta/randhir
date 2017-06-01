<?php

/**
 * Implementation of itg_poll_get_all_current_poll()
 * @return string
 */
function itg_poll_get_all_current_poll() {
  global $base_url;
  $polls_info = array();
  $total_polls = get_total_count_polls();
  $list = itg_poll_get_all_current_poll_qry();
  $related_nids = get_polls_related_story($list->nid);
  $related_content = itg_get_related_content($list->nid);
  if (function_exists('itg_get_related_story_id')) {
    $related_result = itg_get_related_story_id($related_content);
  }
  $arg1 = __get_first_poll_nid();
  $node = node_load($arg1);
  $poll_banner_image = '';
  if (isset($node->field_poll_banner[$node->language][0]['uri']) && !empty($node->field_poll_banner[$node->language][0]['uri'])) {
    $poll_banner_image = theme('image_style' , array('style_name' => 'poll_banner_active_poll_front_end' , 'path' => $node->field_poll_banner[$node->language][0]['uri']));
  }
  else {
    $poll_banner_image = '<img src ="' . $base_url . "/" . drupal_get_path('theme' , 'itg') . '/images/itg_image370x208.jpg" alt="" title="">';
  }

  $poll_image_exist_class = '';

  foreach ($node->field_poll_answer['und'] as $row) {
    $item_id[] = $row['value']; // fieldcollection id
  }
  // instant or after complete

  $fieldcollect = entity_load('field_collection_item' , $item_id);
  if (is_array($fieldcollect) && count($fieldcollect) > 0) {
    $temp_ent = array_shift(array_slice($fieldcollect , 0 , 1));
    $poll_answer_image = isset($temp_ent->field_poll_answer_image[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_image[LANGUAGE_NONE][0]['fid'] : '';
    if (isset($poll_answer_image) && $poll_answer_image > 0) {
      $poll_image_exist_class = 'poll-option-image';
    }
    else {
      $poll_image_exist_class = '';
    }
  }

  if (isset($related_nids) && !empty($related_nids) && count($related_nids) > 0) {
    $related_nodes = get_polls_related_story_nodes($related_nids);
  }
  $polls_info['list'] = $list;
  $polls_info['count'] = $total_polls;
  $polls_info['related_nodes'] = $related_nodes;
  $polls_info['poll_banner_image'] = $poll_banner_image;
  $polls_info['title'] = $node->title;
  $polls_info['updated'] = t('Updated: ') . date('M d Y -h:i A' , $node->changed);
  $polls_info['poll_image_exist_class'] = $poll_image_exist_class;
  $polls_info['related_content'] = $related_result;
  $polls_info['nid'] = $node->nid;

  return theme('itg_poll_list_all_forms' , array('data' => $polls_info , 'pagination' => itg_poll_get_all_current_poll_qry_paging()));
}

/**
 * Implementation of itg_poll_get_all_current_poll_qry()
 * @return array
 */
function itg_poll_get_all_current_poll_qry_paging($limit = FALSE) {

  try {
    $cur_date = date('Y-m-d H:i:s');
    $query = db_select('node' , 'n');
    $query->leftjoin('field_data_field_poll_start_date' , 'sd' , 'n.nid = sd.entity_id');
    $query->fields('n' , array('nid'));
    $query->condition('n.type' , 'poll' , '=');
    $query->condition('n.status' , 1 , '=');
    $query->condition('sd.field_poll_start_date_value' , $cur_date , '<=');
    $query->orderBy('n.created' , 'DESC');
    if ($limit) {
      $query->range(0 , 1);
    }
    $result = $query->execute()->fetchCol();
    return $result;
  }
  catch (Exception $e) {
    watchdog('Error while fatching POLLS:' . $e->getMessage());
  }
}

/**
 * Implementation of itg_poll_get_all_current_poll_qry()
 * @return array
 */
function itg_poll_get_all_current_poll_qry() {

  try {
    $arg1 = __get_first_poll_nid();
    $cur_date = date('Y-m-d H:i:s');
    $query = db_select('node' , 'n');
    $query->leftjoin('field_data_field_poll_start_date' , 'sd' , 'n.nid = sd.entity_id');
    $query->leftjoin('field_data_field_poll_end_date' , 'ed' , 'n.nid = ed.entity_id');
    $query->fields('n' , array('nid'));
    $query->fields('sd' , array('field_poll_start_date_value'));
    $query->fields('ed' , array('field_poll_end_date_value'));
    $query->condition('n.type' , 'poll' , '=');
    if (!empty($arg1)) {
      $query->condition('n.nid' , $arg1 , '=');
    }
    $query->condition('n.status' , 1 , '=');
    $query->condition('sd.field_poll_start_date_value' , $cur_date , '<=');
    $query->orderBy('n.created' , 'DESC');
    $data = array();
    $result = $query->execute();
    while ($record = $result->fetchObject()) {
      $data = $record;
    }
    return $data;
  }
  catch (Exception $e) {
    watchdog('Error while fatching POLLS:' . $e->getMessage());
  }
}

function __get_first_poll_nid() {
  $arg1 = arg(1);
  if (empty($arg1)) {
    $arg1 = itg_poll_get_all_current_poll_qry_paging(TRUE)[0];
  }
  return $arg1;
}

/**
 * Implementation of hook_form().
 * @param array $form
 * @param array reference $form_state
 * @param string $parms
 * @return array
 */
function itg_poll_form_new($form , &$form_state , $nid) {
  $form = array();
  $form['#id'] = 'subsPollForm';
  $form["wrapper"] = array(
    "#markup" => "<div class='inline-messages-" . $nid . "'></div>" ,
  );

  $node = node_load($nid);

  foreach ($node->field_poll_answer['und'] as $row) {
    $item_id[] = $row['value']; // fieldcollection id
  }
  // instant or after complete
  $display_result = isset($node->field_display_result[LANGUAGE_NONE]) ? $node->field_display_result[LANGUAGE_NONE][0]['value'] : '';

  $fieldcollect = entity_load('field_collection_item' , $item_id);
  if (is_array($fieldcollect) && count($fieldcollect) > 0) {

    foreach ($fieldcollect as $key => $temp_ent) {
      $poll_answer_text = isset($temp_ent->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
      $poll_answer_image = isset($temp_ent->field_poll_answer_image[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_image[LANGUAGE_NONE][0]['fid'] : '';
      $poll_caption_text = isset($temp_ent->field_ans_caption[LANGUAGE_NONE]) ? $temp_ent->field_ans_caption[LANGUAGE_NONE][0]['value'] : '';
      if (isset($poll_answer_image) && $poll_answer_image > 0) {
        $poll_image = theme('image_style' , array('style_name' => 'poll_active_poll_image_option_front_end' , 'path' => file_load($poll_answer_image)->uri)) . '<br /><span class="poll-ans-caption">' . t($poll_caption_text) . '</span>';
        $poll_answer[$key] = isset($poll_image) ? $poll_image : '';
      }
      else {
        $poll_answer[$key] = isset($poll_answer_text) ? t($poll_answer_text) . '<span class="poll-ans-caption">' . t($poll_caption_text) . '</span>' : '';
      }
    }
  }

  $form['pole_answer'] = array(
    '#type' => 'radios' ,
    '#options' => $poll_answer ,
    '#prefix' => '<div class="poll-main-wrap-' . $nid . '">' ,
    '#suffix' => '</div><span class="poll-ans-error-' . $nid . '"></span>' ,
  );

  $form['nid'] = array(
    '#type' => 'hidden' ,
    '#value' => $nid ,
  );

  $form['argument_current_nid'] = array(
    '#type' => 'hidden' ,
    '#value' => arg(1) ,
  );

  $form['display_result'] = array(
    '#type' => 'hidden' ,
    '#value' => $display_result ,
  );

  $form['submit'] = array(
    '#type' => 'submit' ,
    '#value' => 'Submit' ,
    '#ajax' => array(
      'callback' => 'itg_poll_form_new_ajax_submit' ,
      'effect' => 'fade' ,
      'progress' => array('type' => 'throbber' , 'message' => '') ,
      'validate_first' => TRUE ,
    ) ,
  );


  return $form;
}

/**
 * Getting total count of Polls
 * @param array $data
 * @return array
 */
function get_total_count_polls() {
  $cur_date = date('Y-m-d H:i:s');
  $query = db_select('node' , 'n');
  $query->leftjoin('field_data_field_poll_start_date' , 'sd' , 'n.nid = sd.entity_id');
  $query->leftjoin('field_data_field_poll_end_date' , 'ed' , 'n.nid = ed.entity_id');
  $query->fields('n' , array('nid'));
  $query->fields('sd' , array('field_poll_start_date_value'));
  $query->fields('ed' , array('field_poll_end_date_value'));
  $query->condition('n.type' , 'poll' , '=');
  $query->condition('n.status' , 1 , '=');
  $query->condition('sd.field_poll_start_date_value' , $cur_date , '<=');
  $query->condition(db_or()->isNull('ed.field_poll_end_date_value')->condition('ed.field_poll_end_date_value' , $cur_date , '>='))
      ->execute();

  return $query->countQuery()->execute()->fetchField();
}

/**
 * Getting polls related story nids
 * @param type $nid
 * @return type
 */
function get_polls_related_story($nid) {
  $query = db_select('field_data_field_associate_poll' , 'poll');
  $query->leftjoin('node' , 'n' , 'n.nid = poll.entity_id');
  $query->fields('poll' , array('field_associate_poll_target_id'));
  $query->condition('n.type' , 'poll' , '=');
  $query->condition('poll.entity_id' , $nid , '=');
  $res = $query->execute();
  $data = array();
  foreach ($res as $row) {
    $data[] = $row->field_associate_poll_target_id;
  }
  return $data;
}

/**
 * Getting related story node with its links
 * @param type $nids
 * @return type
 */
function get_polls_related_story_nodes($nids) {

  $query = db_select('node' , 'n');
  $query->fields('n' , array('title' , 'nid'));
  $query->condition('n.nid' , $nids , 'IN');
  $query->condition('n.status' , 1);
  $res = $query->execute();
  $data = array();
  foreach ($res as $row) {
    $data[] = l(t($row->title) , 'node/' . $row->nid);
  }

  return $data;
}
