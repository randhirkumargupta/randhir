<?php

/*
 * Inc file scorecard functions
 *
 *
 */

/**
 * Page callback for scorecard.
 * @param string $matchid
 * @return string
 * Implements itg_common_get_scorecard().
 */
function itg_common_get_scorecard($matchid) {
  module_load_include('inc', 'itg_widget', 'includes/itg_widget_live_score');
  $data = live_score();
  $teamsabbr = $data['team1'] . " vs " . $data['team2'];
  $year = substr($data['date'], 4, 4);
  $title = $teamsabbr . " : Live Score, Cricket Commentary, Match Stats- India Today";
  $description = $teamsabbr . ": Get " . $teamsabbr ." Live Score, Full Scorecard, Ball by Ball cricket commentary and match stats. Visit IndiaToday.com";
  $keywords = $teamsabbr . ", " . $teamsabbr . " " . $year . ", " . $teamsabbr . " live score, " . $teamsabbr . $year." full scorecard, " . $teamsabbr . " match commentary, " .$teamsabbr . " " . $year . " match result, ball by ball commentary, india today";
  drupal_set_title($title);
  $html_head = array(
    'description' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'description',
        'content' => $description,
      ),
    ),
    'keywords' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'keywords',
        'content' => $keywords,
      ),
    ),
  );
  foreach ($html_head as $key => $data) {
    drupal_add_html_head($data, $key);
  }
  return '<iframe id="si-scorecard" width="100%" height="740" src="https://assets-indiatoday.sportz.io/cricket/matchcentre.html?matchid=' . $matchid . '" frameborder="0"></iframe>';
}

/**
 * This function is used to manage score card form
 * @return string
 */
function itg_manage_score_card() {
  $arg = arg();
  if (isset($arg) && $arg[1] == 'edit') {
    drupal_set_title(t('Edit Score Card'));
    $action = $arg[2];
    $query = db_select('itg_score_card', 'm');
    $query->condition('m.id', $action, '=');
    # get the desired fields from the database
    $query->fields('m', array('id', 'score_section', 'score_description', 'score_story', 'score_photo', 'score_video', 'score_status'));
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
    '#required' => TRUE
  );

  $form['score_photo'] = array(
    '#type' => 'textfield',
    '#title' => t('Associate to Photo'),
    '#default_value' => ($results->score_photo) ? $results->score_photo : '',
    '#required' => TRUE
  );
  
  $form['score_video'] = array(
    '#type' => 'textfield',
    '#title' => t('Associate to Video'),
    '#default_value' => ($results->score_video) ? $results->score_video : '',
    '#required' => TRUE
  );
  
   $form['score_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Score card iframe'),
    '#default_value' => ($results->score_description) ? $results->score_description : '',
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
 * This function is used to score form validation
 * {@inheritdoc}
 */
/* 
function itg_manage_score_card_validate($form, &$form_state) {
  $score_action = $form_state['input']['score_action'];
  $score_section = $form_state['values']['score_section'];
  $query = db_select('itg_score_card', 'm');
  $query->condition('m.score_section', $score_section, '=');
  if ($budget_action) {
    $query->condition('m.id', $score_action, '<>');
  }
  $query->fields('m', array('id'));
  # execute the query
  $results = $query->execute()->fetchObject();
  if ($results->id) {
    form_set_error('field', t('Score card already exist.'));
  }
}
*/

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
          'score_status' => $score_status
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
      $query->fields('s',array(entity_id));
      $query->fields('t',array(name));
      $query->leftJoin('taxonomy_term_data', 't', 's.entity_id=t.tid');
      $query->condition('s.field_cm_select_type_value', $array, 'IN');
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
      $op = array("" => "-- Section --");
      if(is_array($result) && count($result) > 0) {
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
  $query->fields('s', array('id','score_story', 'score_photo','score_video','score_status'))
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
    '6' => t('Action'),
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
      $action = l(t('Edit'), 'manage-score-card/edit/' . $score_id, array('query' => array('destination' => 'manage-score-list')));
      $rows[] = array($i,
        $score_story,
        $score_photo,
        $score_video,
        $status,
        $action
      );
      $i++;
    }
  }

  $caption_table_edit = l(t('Add Score card'), 'manage-score-card');

  // Format and print out the table.
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'caption' => $caption_table_edit, 'attributes' => array('class' => array('views-table'))));

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
