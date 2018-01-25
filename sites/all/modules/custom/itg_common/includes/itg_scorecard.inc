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
    $query->fields('m', array('id', 'score_section', 'score_title', 'score_description', 'score_story', 'score_photo', 'score_video', 'score_status'));
    # execute the query
    $results = $query->execute()->fetchObject();
  }
  else {
    drupal_set_title(t('Add Score Card'));
    $action = '';
  }

  $form = array();
  /*
  module_load_include('inc', 'itg_layout_manager', 'includes/itg_layout_autocomplete');
  $op = score_card_tid_by_content_type();
  $form['score_section'] = array(
    '#type' => 'select',
    '#title' => t('Select Section'),
    '#options' => $op,
    '#required' => TRUE,
    '#default_value' => isset($results->score_section) ? $results->score_section : '',
  );
  
  $form['score_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($results->score_title) ? $results->score_title : '',
    '#required' => TRUE
  );
  */
  
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
    '#title' => t('Description'),
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

/**
 * This function is used to score form submit.
 * {@inheritdoc}
 */
function itg_manage_score_card_submit($form, &$form_state) {
  global $user;
  $score_title = $form_state['values']['score_title'];
  $score_section = $form_state['values']['score_section'];
  $score_description = $form_state['values']['score_description'];
  $score_story = $form_state['values']['score_story'];
  $score_photo = $form_state['values']['score_photo'];
  $score_video = $form_state['values']['score_video'];
  $score_status = $form_state['values']['score_status'];
  $score_action = $form_state['input']['score_action'];


  if (isset($budget_action) && $budget_action > 0) {
    db_update('itg_score_card')
        ->fields(array(
			'score_section' => $score_section,
			'score_title' => $score_title,
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
          'score_section' => $score_section,
          'score_title' => $score_title,
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
 * callback for all the story of title
 * @param $title
 */
function itg_score_get_content_title($title) {

    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        $query->fields('n', array('nid','title'));
        $query->condition('title', '%' . $title . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');
        $query->condition('n.status', 1);
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
			$key = $record['title'] . "(" . $record['nid'] . ")";
            $options[$key] = $record['title'];
        }

        drupal_json_output($options);
    }
}
