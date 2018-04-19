<?php

/*
 * Inc file scorecard functions
 *
 *
 */

/**
 * This function is used to manage score card form
 * @return string
 */
function itg_manage_score_card() {
  $arg = arg();
  if (isset($arg[0]) && $arg[0] == 'manage-score-card' && !isset($arg[1])) {
    $query = db_select('itg_score_card', 's')
        ->fields('s', array('id'))
        ->execute();
    $num = $query->rowCount();
    if ($num >= 1) {
      drupal_goto('manage-score-list');
    }
  }
  if (isset($arg) && $arg[1] == 'edit') {
    drupal_set_title(t('Edit Score Card'));
    $action = $arg[2];
    $query = db_select('itg_score_card', 'm');
    $query->condition('m.id', $action, '=');
    # get the desired fields from the database
    $query->fields('m', array('id', 'score_section', 'score_description', 'score_story', 'score_photo', 'score_video', 'score_status','score_triangle'));
    # execute the query
    $results = $query->execute()->fetchObject();
  }
  else {
    drupal_set_title(t('Add Score Card'));
    $action = '';
  }

  $form = array();

  $form['score_status'] = array(
    '#type' => 'radios',
    '#title' => t('Score status'),
    '#options' => array(1 => "Active", 2 => "Inactive"),
    '#default_value' => ($results->score_status) ? $results->score_status : 1,
    '#required' => TRUE
  );

  $form['score_story'] = array(
    '#type' => 'textfield',
    '#title' => t('Associate to Story/Live Blog'),
    '#default_value' => ($results->score_story) ? $results->score_story : '',
  );

  $form['score_photo'] = array(
    '#type' => 'textfield',
    '#title' => t('Associate to Photo'),
    '#default_value' => ($results->score_photo) ? $results->score_photo : '',
  );

  $form['score_video'] = array(
    '#type' => 'textfield',
    '#title' => t('Associate to Video'),
    '#default_value' => ($results->score_video) ? $results->score_video : '',
  );

  $form['score_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Score card iframe'),
    '#default_value' => ($results->score_description) ? $results->score_description : '',
    '#required' => TRUE
  );
  
  $form['score_triangle'] = array(
    '#type' => 'radios',
    '#title' => t('Score Triangle'),
    '#options' => array(1 => "Active", 2 => "Inactive"),
    '#default_value' => ($results->score_triangle) ? $results->score_triangle : 1,
    '#required' => TRUE
  );
  
  $form['score_action'] = array(
    '#type' => 'hidden',
    '#value' => $action,
  );

  $form['score_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $destination = 'manage-score-list';

  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), $destination),
    '#weight' => 20,
  );

  return $form;
}

/**
 * This function is used to score form submit.
 * {@inheritdoc}
 */
function itg_manage_score_card_submit($form, &$form_state) {
  global $user;
  $score_section = isset($form_state['values']['score_section']) ? $form_state['values']['score_section'] : 0;
  $score_description = $form_state['values']['score_description'];
  $score_story = $form_state['values']['score_story'];
  $score_photo = $form_state['values']['score_photo'];
  $score_video = $form_state['values']['score_video'];
  $score_status = $form_state['values']['score_status'];
  $score_triangle = $form_state['values']['score_triangle'];
  $score_action = $form_state['input']['score_action'];


  if (isset($score_action) && $score_action > 0) {
    db_update('itg_score_card')
        ->fields(array(
          'score_section' => 0,
          'score_description' => $score_description,
          'score_story' => $score_story,
          'score_photo' => $score_photo,
          'score_video' => $score_video,
          'score_status' => $score_status,
          'score_triangle' => $score_triangle,
        ))
        ->condition('id', $score_action, '=')
        ->execute();
    drupal_set_message(t('The form has been updated'));
  }
  else {
    db_insert('itg_score_card')
        ->fields(array(
          'score_section' => 0,
          'score_description' => $score_description,
          'score_story' => $score_story,
          'score_photo' => $score_photo,
          'score_video' => $score_video,
          'score_status' => $score_status,
          'score_triangle' => $score_triangle,
        ))
        ->execute();
    drupal_set_message(t('The form has been submitted'));
  }
  drupal_goto('manage-score-list');
}

/**
 * Option value set by section for budget predictor form.
 * @return type
 */
function score_card_tid_by_content_type() {
  $array = array('story', 'photo', 'video');
  $query = db_select('field_data_field_cm_select_type', 's');
  $query->fields('s', array(entity_id));
  $query->fields('t', array(name));
  $query->leftJoin('taxonomy_term_data', 't', 's.entity_id=t.tid');
  $query->condition('s.field_cm_select_type_value', $array, 'IN');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $op = array("" => "-- Section --");
  if (is_array($result) && count($result) > 0) {
    foreach ($result as $key => $value) {
      $op[$value['entity_id']] = $value['name'];
    }
  }
  return $op;
}

/**
 * function for list of score card
 * @global string $base_url
 * @return string
 */
function itg_manage_score_list() {
  global $base_url;
  $build = array();
  $query = db_select('itg_score_card', 's')->extend('PagerDefault');
  $query->fields('s', array('id', 'score_story', 'score_photo', 'score_video', 'score_status', 'score_triangle'))
      ->orderBy('id', 'DESC')
      ->limit(10);

  # execute the query
  $results = $query->execute();
  $header = array(
    '1' => t('S. No.'),
    '2' => array('data' => t('Score story'), 'sort' => 'desc'),
    '3' => array('data' => t('Score photo'), 'sort' => 'desc'),
    '4' => array('data' => t('Score video'), 'sort' => 'desc'),
    '5' => array('data' => t('Score Status'), 'sort' => 'desc'),
    '6' => array('data' => t('Score Triangle'), 'sort' => 'desc'),
    '7' => t('Action'),
  );
  # build the table fields
  $rows = array();
  $i = 1;

  if (!empty($results)) {
    foreach ($results as $row) {
      $score_id = $row->id;
      $score_story = !empty($row->score_story) ? $row->score_story : '0';
      $score_photo = !empty($row->score_photo) ? $row->score_photo : '0';
      $score_video = !empty($row->score_video) ? $row->score_video : '0';
      if ($row->score_status == 1) {
        $status = 'Active';
      }
      elseif ($row->score_status == 2) {
        $status = 'Inactive';
      }
      if ($row->score_triangle == 1) {
        $triangle = 'Active';
      }
      elseif ($row->score_triangle == 2) {
        $triangle = 'Inactive';
      }
      $action = l(t('Edit'), 'manage-score-card/edit/' . $score_id, array('query' => array('destination' => 'manage-score-list')));
      $rows[] = array($i,
        $score_story,
        $score_photo,
        $score_video,
        $status,
        $triangle,
        $action
      );
      $i++;
    }
  }

  $caption_table_edit = l(t('Add Score card'), 'manage-score-card');

  // Format and print out the table.
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table'))));

  $build['content'] = array(
    'itg_score_card_content' => array(
      '#markup' => $output,
    ),
  );

  # add the pager
  $build['pager'] = array(
    '#theme' => 'pager',
    '#weight' => 5,
  );

  return $build;
}
