<?php

/**
 * @file
 * itg_budget_predictor.inc
 *
 * Provides customizations and functions for Budget Predictor Widgets.
 *
 */

/**
 * function to get data of taxonomy
 * @global array $user
 * @return array
 */
function itg_budget_predictor_get_taxonomy() {
  global $user, $base_url;
  $user_id = $user->uid;
  $arg = arg();
  $section_id = isset($arg[2]) ? $arg[2] : '';
  $cookies_id = $_COOKIE['COOKIES_IT_' . $section_id];
  $exist_predictor = check_exist_predictor($user_id, $section_id); 
  
  if(empty($exist_predictor) && $user_id && $cookies_id) {
    update_user_by_cookies($user_id, $section_id, $cookies_id);
  }

  $check_budget_status = check_budget_status($section_id);
  $check_budget_status_front_user = check_budget_status_front_user($section_id);
  $check_budget = check_budget($section_id);

  if (!empty($check_budget['status'])) {

    $ranking_array = array();
    $querys = db_select('itg_budget_predictor', 'r')->distinct();
    $querys->fields('r', array('entity_id', 'ranking_column', 'file_name'));
    $querys->condition('r.section_id', $section_id);

    if (empty($check_budget_status)) {
      if ($user_id && $user_id > 1) {
        $querys->condition('r.user_id', $user_id);
      }
      else {
        $querys->condition('r.cookies_id', $cookies_id);
      }
    }
    else {
      $querys->condition('r.status', 2);
    }

    $results = $querys->execute()->fetchAll(PDO::FETCH_ASSOC);
    foreach ($results as $k => $row) {
      $ranking_array[$k]['ranking_column'] = $row['ranking_column'];
      $ranking_array[$k]['entity_id'] = $row['entity_id'];
      $file_name = $row['file_name'];
      $entity_array[] = $row['entity_id'];
    }
    $query = db_select('taxonomy_term_data', 'td')->distinct();
    $query->leftJoin('taxonomy_vocabulary', 'v', 'td.vid=v.vid');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->leftJoin('itg_budget_predictor', 'r', 'td.tid=r.entity_id');
    $query->fields('td', array('name', 'vid', 'tid'));
    $query->fields('img', array('field_story_small_image_fid'));
    //$query->condition('r.section_id', $section_id);
    $query->condition('v.machine_name', 'cheaper_dearer');

    if (count($entity_array) > 0 && is_array($entity_array)) {
      $query->condition('td.tid', $entity_array, 'NOT IN');
    }
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $entity_data = array();

    foreach ($result as $key => $entity_data_node) {
      $entity_data[$key]['tid'] = $entity_data_node['tid'];
      $entity_data[$key]['name'] = $entity_data_node['name'];
      $entity_data[$key]['image'] = $entity_data_node['field_story_small_image_fid'];
    }

    $entity_data['ranking'] = $ranking_array;

    $budget_type = '1';
    $ip_address = $_SERVER['REMOTE_ADDR'];
    $column1 = '';
    $column2 = '';
    $column3 = '';

    $column4 = '';
    $user_id = $user->uid;
    if (!empty($entity_data)) {
      foreach ($entity_data as $key => $node_data) {
        $tid = $node_data['tid'];
        $name = $node_data['name'];
        $fid = $node_data['image'];
        $file = file_load($fid);
        $uri = $file->uri;
        if ($tid) {
          $column4 .= '<li id="entry_' . $tid . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '" title="' . $name . '"></li>';
        }
      }
    }
    if (!empty($entity_data['ranking'])) {
      foreach ($entity_data['ranking'] as $keys => $values) {
        $entity_id = $values['entity_id'];
        $fid = get_ranking_fid($entity_id, $section_id);
        $file = file_load($fid);
        $uri = $file->uri;
        if ($values['ranking_column'] == '1') {
          $column1 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '2') {
          $column2 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '3') {
          $column3 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
      }
    }

    $budget_data['column1'] = $column1;
    $budget_data['column2'] = $column2;
    $budget_data['column3'] = $column3;
    $budget_data['column4'] = $column4;
    $budget_data['actual_link'] = $base_url . $_SERVER['REQUEST_URI']; 
    $budget_data['exist'] = 1;
    $budget_data['file_names'] = $file_name;

    $budget_data['budget_title'] = $check_budget['budget_title'];
    $budget_data['budget_description'] = $check_budget['budget_description'];
    $budget_data['budget_message'] = $check_budget['budget_message'];
    $budget_data['budget_social_message'] = $check_budget['budget_social_message'];
    $budget_data['budget_message_flag'] = ($check_budget_status) ? 1 : '';
    $budget_data['budget_message_front_flag'] = ($check_budget_status_front_user) ? 1 : '';
    $budget_data['section_id'] = $section_id;
  }
  else {
    $budget_data['exist'] = '';
  }

  return $budget_data;
}

/**
 * Budget Predictor Budget Insert/Update
 * @global array $user
 */
function itg_budget_predictor_update_budget() {
  global $user;
  $arg = arg();
  $section_id = isset($arg[2]) ? $arg[2] : '';
  $user_id = $user->uid;
  $allowed_roles = array('Editor', 'Site Admin', 'administrator');
  if (count(array_intersect($user->roles, $allowed_roles)) > 0) {
    $budget_status = 2;
  }
  else {
    $budget_status = 1;
  }
  $budget_type = 1;
  $ip_address = $_SERVER['REMOTE_ADDR'];
  $sort1 = '';
  $sort2 = '';
  $sort3 = '';
  $sort4 = '';

  // PARSES THE POSTS FROM EACH COLUMN INTO AN ARRAY
  parse_str($_POST['sort1'], $sort1);
  parse_str($_POST['sort2'], $sort2);
  parse_str($_POST['sort3'], $sort3);
  $cookies_id = $_POST['cookies_id'];
  if (!empty($sort1['entry'])) {
    //parse_str($_POST['sort4'], $sort4);
    foreach ($sort1['entry'] as $key => $value) {
      $count = itg_budget_predictor_check_ranking($value, $section_id, $cookies_id);
      if ($count < 1) {
        $nid = db_insert('itg_budget_predictor')
            ->fields(array(
              'entity_id' => $value,
              'ranking_value' => $key,
              'ranking_column' => 1,
              'budget_type' => $budget_type,
              'user_id' => $user_id,
              'cookies_id' => $cookies_id,
              'section_id' => $section_id,
              'file_name' => '',
              'status' => $budget_status,
              'timestamp' => REQUEST_TIME,
              'ip_address' => $ip_address,
            ))
            ->execute();
      }
      else {
        db_update('itg_budget_predictor')
            ->fields(array(
              'ranking_value' => $key,
              'ranking_column' => 1,
              'ip_address' => $ip_address,
            ))
            ->condition('entity_id', $value, '=')
            ->condition('user_id', $user_id, '=')
            ->execute();
      }
    }
  }

  if (!empty($sort2['entry'])) {
    foreach ($sort2['entry'] as $key => $value) {
      $count = itg_budget_predictor_check_ranking($value, $section_id, $cookies_id);
      if ($count < 1) {
        $nid = db_insert('itg_budget_predictor')
            ->fields(array(
              'entity_id' => $value,
              'ranking_value' => $key,
              'ranking_column' => 2,
              'budget_type' => $budget_type,
              'user_id' => $user_id,
              'cookies_id' => $cookies_id,
              'section_id' => $section_id,
              'file_name' => '',
              'status' => $budget_status,
              'timestamp' => REQUEST_TIME,
              'ip_address' => $ip_address,
            ))
            ->execute();
      }
      else {
        db_update('itg_budget_predictor')
            ->fields(array(
              'ranking_value' => $key,
              'ranking_column' => 2,
              'ip_address' => $ip_address,
            ))
            ->condition('entity_id', $value, '=')
            ->condition('user_id', $user_id, '=')
            ->execute();
      }
    }
  }

  if (!empty($sort3['entry'])) {
    foreach ($sort3['entry'] as $key => $value) {
      $count = itg_budget_predictor_check_ranking($value, $section_id, $cookies_id);
      if ($count < 1) {
        $nid = db_insert('itg_budget_predictor')
            ->fields(array(
              'entity_id' => $value,
              'ranking_value' => $key,
              'ranking_column' => 3,
              'budget_type' => $budget_type,
              'user_id' => $user_id,
              'cookies_id' => $cookies_id,
              'section_id' => $section_id,
              'file_name' => '',
              'status' => $budget_status,
              'timestamp' => REQUEST_TIME,
              'ip_address' => $ip_address,
            ))
            ->execute();
      }
      else {
        db_update('itg_budget_predictor')
            ->fields(array(
              'ranking_value' => $key,
              'ranking_column' => 3,
              'ip_address' => $ip_address,
            ))
            ->condition('entity_id', $value, '=')
            ->condition('user_id', $user_id, '=')
            ->execute();
      }
    }
  }
}

/**
 * Get date from itg_budget_predictor
 * @return array
 */
function itg_budget_predictor_get_budget_ranking() {
  $arg = arg();
  $section_id = isset($arg[2]) ? $arg[2] : '';
  if ($section_id) {
    $query = db_select('itg_budget_predictor', 'r');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->fields('td', array('name', 'vid', 'tid'));
    $query->fields('img', array('field_story_small_image_fid'));
    $query->condition('r.section_id', $section_id);
    $query->condition('v.machine_name', 'cheaper_dearer');
    return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
}

/**
 * chaeck budget predictor ranking
 * @global array $user
 * @param int $entity_id
 * @param type $section_id
 * @return int
 */
function itg_budget_predictor_check_ranking($entity_id, $section_id, $cookies_id) {
  if ($section_id) {
    global $user;
    $user_id = $user->uid;
    $query = db_select('itg_budget_predictor', 'r');
    $query->fields('r', array('entity_id'));
    $query->condition('r.section_id', $section_id);
    if ($user_id) {
      $query->condition('r.user_id', $user_id);
    }
    else {
      $query->condition('r.cookies_id', $cookies_id);
    }
    $query->condition('r.entity_id', $entity_id);
    return $query->execute()->rowCount();
  }
}

/**
 * Get fid from taxonomy
 * @param int $tid
 * @param int $section_id
 * @return int
 */
function get_ranking_fid($tid, $section_id) {
  if ($section_id) {
    $query = db_select('taxonomy_term_data', 'td');
    $query->leftJoin('taxonomy_vocabulary', 'v', 'td.vid=v.vid');
    $query->leftJoin('field_data_field_story_small_image', 'img', 'td.tid=img.entity_id');
    $query->leftJoin('itg_budget_predictor', 'r', 'td.tid=r.entity_id');
    $query->fields('img', array('field_story_small_image_fid'));
    $query->condition('r.section_id', $section_id);
    $query->condition('v.machine_name', 'cheaper_dearer');
    $query->condition('td.tid', $tid, '=');
    $result = $query->execute()->fetchAssoc();
    return $result['field_story_small_image_fid'];
  }
}

/**
 * function for list of budget 
 * @global string $base_url
 * @return string
 */
function itg_budget_predictor_list() {
  global $base_url;
  $build = array();
  $query = db_select('itg_budget_predictor', 'p')->extend('PagerDefault');
  if (!empty($_GET['section_id'])) {
    $section_id = $_GET['section_id'];
    $query->condition('p.section_id', $section_id);
  }

  $user_type = $_GET['user_type'];
  if ($user_type == 2) {
    $query->condition('p.user_id', $user_type, '>=');
  }
  elseif ($user_type == 1) {
    $query->condition('p.user_id', 0, '=');
  }
  $query->condition('p.status', 1, '=')
      ->condition('p.budget_type', 1, '=')
      ->groupBy('p.user_id');

  $query->fields('p', array('user_id', 'timestamp'))
      ->orderBy('timestamp', 'DESC')
      ->limit(10);

  # execute the query
  $results = $query->execute();
  $header = array(
    '1' => t('S. No.'),
    '2' => array('data' => t('User Name'), 'sort' => 'desc'),
    '3' => array('data' => t('Email'), 'sort' => 'desc'),
    '4' => t('Created Date'),
  );
  # build the table fields
  $rows = array();
  $i = 1;

  if (!empty($results)) {
    foreach ($results as $row) {
      $name = !empty($row->user_id) ? user_load($row->user_id)->name : t('Anonymous user');
      $email = user_load($row->user_id)->mail;
      $created_date = isset($row->timestamp) ? date('d/m/Y H:i:s', ($row->timestamp)) : '';

      $rows[] = array($i,
        $name,
        $email,
        $created_date
      );
      $i++;
    }
  }

  $caption_table_edit = l(t('List Of Budget'), 'manage-budget-list') . "&nbsp;" . l(t('Download Excel'), 'budget-download-excel', array('query' => array('section_id' => $_GET['section_id'], 'user_type' => $_GET['user_type'])));
  // Format and print out the table.
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'caption' => $caption_table_edit, 'attributes' => array('class' => array('views-table'))));

  $build['content'] = array(
    'itg_budget_predictor_search' => drupal_get_form('itg_budget_predictor_search_form'),
    'itg_budget_predictor_content' => array(
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

/**
 * 
 * @global string $base_url
 * @param array $form
 * @param array $form_state
 * @return type
 */
function itg_budget_predictor_search_form($form, &$form_state) {
  global $base_url;
  $form = array();
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  $op = array("" => "-- Section --");
  foreach ($tax as $key => $val) {
    if (itg_category_manager_term_state($val->tid)) {
      $op[$val->tid] = $val->name;
    }
  }

  $user_arr = array("" => t("-- Section --"), '1' => t('Anonymous user'), '2' => t('Authenticated user'));

  $form['#method'] = 'get';
  $form['section_id'] = array(
    '#type' => 'select',
    '#title' => t('Select Section'),
    '#options' => $op,
    '#default_value' => isset($_GET['section_id']) ? $_GET['section_id'] : '',
  );

  $form['user_type'] = array(
    '#type' => 'select',
    '#title' => t('User Type'),
    '#options' => $user_arr,
    '#default_value' => isset($_GET['user_type']) ? $_GET['user_type'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $url = $base_url . '/budget-predictor-list';
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Reset'), $url, array(
      'attributes' => array(
        'class' => 'button custom-url-search'
      )
    )),
    '#weight' => 9,
    '#value' => t('Reset')
  );
  return $form;
}

/**
 * 
 * @param type $form
 * @param array $form_state
 */
function itg_budget_predictor_search_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * function for list of manage budget 
 * @global string $base_url
 * @return string
 */
function itg_budget_manage_list() {
  global $base_url;
  $build = array();

  $query = db_select('itg_manage_budget', 'm')->extend('PagerDefault');
  $query->fields('m', array('id', 'budget_title', 'budget_description', 'budget_section', 'budget_section', 'status'))
      ->orderBy('id', 'DESC')
      ->limit(10);
  # execute the query
  $results = $query->execute();

  $header = array(
    '1' => t('S. No.'),
    '2' => array('data' => t('Title'), 'sort' => 'desc'),
    '3' => t('Description'),
    '5' => t('Section'),
    '6' => t('Status'),
    '7' => t('Action'),
  );
  # build the table fields
  $rows = array();
  $i = 1;

  if (!empty($results)) {
    foreach ($results as $row) {
      $budget_id = $row->id;
      $budget_title = $row->budget_title;
      $budget_description = $row->budget_description;
      $budget_section = taxonomy_term_load($row->budget_section)->name;
      $status = $row->status;
      $play_link = l(t('Final Play'), 'budget/predictor/' . $row->budget_section);
      $action = l(t('Edit'), 'manage-budget-predictor/edit/' . $budget_id, array('query' => array('destination' => 'manage-budget-list')));
      $rows[] = array($i,
        $budget_title,
        $budget_description,
        $budget_section,
        $status,
        $action . " | " . $play_link,
      );
      $i++;
    }
  }
  $caption_table_edit = l(t('Add Budget'), 'manage-budget-predictor') . "&nbsp;&nbsp;";
  $caption_table_edit .= l(t('List Of Budget User'), 'budget-predictor-list');
  // Format and print out the table.
  $output = theme('table', array('header' => $header,
    'rows' => $rows,
    // table caption will be in $caption_edit_table
    'caption' => $caption_table_edit,
    'attributes' => array('class' => array('views-table'))));

  $build['content'] = array(
    'itg_budget_predictor_content' => array(
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

/**
 * This function is used to manage budget form
 * @return string
 */
function itg_manage_budget() {
  $arg = arg();
  if (isset($arg) && $arg[1] == 'edit') {
    $action = $arg[2];
    $query = db_select('itg_manage_budget', 'm');
    $query->condition('m.id', $action, '=');
    # get the desired fields from the database
    $query->fields('m', array('id', 'budget_title', 'budget_description', 'budget_message', 'budget_social_message', 'budget_section', 'file_id', 'status'));
    # execute the query
    $results = $query->execute()->fetchObject();
  }
  else {
    $action = '';
  }

  $form = array();
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  $op = array("" => "-- Section --");
  foreach ($tax as $key => $val) {

    if (itg_category_manager_term_state($val->tid)) {
      $op[$val->tid] = $val->name;
    }
  }

  $form['budget_section'] = array(
    '#type' => 'select',
    '#title' => t('Select Section'),
    '#options' => $op,
    '#required' => TRUE,
    '#default_value' => isset($results->budget_section) ? $results->budget_section : '',
  );

  $form['budget_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($results->budget_title) ? $results->budget_title : '',
    '#required' => TRUE
  );
  $form['budget_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => ($results->budget_description) ? $results->budget_description : '',
    '#required' => TRUE
  );

  $form['budget_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Success message'),
    '#default_value' => ($results->budget_message) ? $results->budget_message : '',
    '#required' => TRUE
  );

  $form['budget_social_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Social message'),
    '#default_value' => ($results->budget_social_message) ? $results->budget_social_message : '',
    '#required' => TRUE
  );

  $form['budget_image'] = array(
    '#title' => t('Budget Image'),
    '#type' => 'managed_file',
    '#upload_validators' => array('file_validate_extensions' => array('jpeg jpg png gif')),
    '#default_value' => ($results->file_id) ? $results->file_id : '',
    '#upload_location' => 'public://budget/',
    '#required' => TRUE
  );

  $form['budget_status'] = array(
    '#type' => 'radios',
    '#title' => t('Budget status'),
    '#options' => array(1 => "Show", 2 => "Off"),
    '#default_value' => ($results->status) ? $results->status : 2,
    '#required' => TRUE
  );

  $form['budget_action'] = array(
    '#type' => 'hidden',
    '#value' => $action,
  );

  $form['budget_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $destination = 'manage-budget-list';

  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), $destination),
    '#weight' => 20,
  );

  return $form;
}

/**
 * This function is used to budget form validation
 * {@inheritdoc}
 */
function itg_manage_budget_validate($form, &$form_state) {
  $budget_action = $form_state['values']['budget_action'];
  $budget_section = $form_state['values']['budget_section'];
  $query = db_select('itg_manage_budget', 'm');
  $query->condition('m.budget_section', $budget_section, '=');
  if ($budget_action) {
    $query->condition('m.id', $budget_action, '<>');
  }
  $query->fields('m', array('id'));
  # execute the query
  $results = $query->execute()->fetchObject();
  if ($results->id) {
    form_set_error('field', t('Budget Predictor already exist.'));
  }
}

/**
 * This function is used to budget form submit.
 * {@inheritdoc}
 */
function itg_manage_budget_submit($form, &$form_state) {
  global $user;
  $budget_title = $form_state['values']['budget_title'];
  $budget_section = $form_state['values']['budget_section'];
  $budget_description = $form_state['values']['budget_description'];
  $budget_message = $form_state['values']['budget_message'];
  $budget_social_message = $form_state['values']['budget_social_message'];
  $budget_year = $form_state['values']['budget_year'];
  $budget_status = $form_state['values']['budget_status'];
  $budget_action = $form_state['input']['budget_action'];

  $file_id = $form_state['input']['budget_image']['fid'];
  $file = file_load($form_state['values']['budget_image']);

  if ($file) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'user', 'user', $user->uid);
  }


  if (isset($budget_action) && $budget_action > 0) {
    db_update('itg_manage_budget')
        ->fields(array(
          'budget_title' => $budget_title,
          'budget_description' => $budget_description,
          'budget_message' => $budget_message,
          'budget_social_message' => $budget_social_message,
          'budget_section' => $budget_section,
          'file_id' => $file_id,
          'status' => $budget_status,
        ))
        ->condition('id', $budget_action, '=')
        ->execute();
    drupal_set_message(t('The form has been updated'));
  }
  else {
    db_insert('itg_manage_budget')
        ->fields(array(
          'budget_title' => $budget_title,
          'budget_title' => $budget_title,
          'budget_description' => $budget_description,
          'budget_message' => $budget_message,
          'budget_social_message' => $budget_social_message,
          'budget_section' => $budget_section,
          'file_id' => $file_id,
          'status' => $budget_status,
          'created_date' => REQUEST_TIME,
        ))
        ->execute();
    drupal_set_message(t('The form has been submitted'));
  }
  drupal_goto('manage-budget-list');
}

/**
 * update image at the budget predictor table
 */
function itg_budget_crop_image() {
  global $user;
  $arg = arg();
  $section_id = isset($arg[1]) ? $arg[1] : '';
  if ($section_id && isset($_POST['data'])) {
    $cookies_id = $_POST['cookies_id'];
    $data = $_POST['data'];
    $uniqid = uniqid();
    $file = $uniqid . '.png';
    $budget_dir = "public://budget/";

    if (!file_exists($budget_dir)) {
      mkdir($budget_dir, 0777, TRUE);
    }

    $file_name = 'budget/' . $file;
    $uri = substr($data, strpos($data, ",") + 1);
    // save to file
    file_put_contents('public://budget/' . $file, base64_decode($uri));

    $num_updated = db_update('itg_budget_predictor')
        ->fields(array('file_name' => $file_name))
        ->condition('section_id', $section_id)
        ->condition('user_id', $user->uid, '=')
        ->execute();

    if (!$num_updated) {
      drupal_set_message('Please Drag and Drop Images.', 'error');
    }
  }
}

/**
 * Download image
 * @global string $base_url
 * @global array $user
 */
function itg_budget_download_image() {
  global $base_url, $user;
  $timestamp = date('Y');
  $query = db_select('itg_budget_predictor', 'p');
  # get the desired fields from the database
  $query->where('YEAR(FROM_UNIXTIME(p.timestamp)) = :timestamp', array(':timestamp' => $timestamp))
      ->condition('p.status', 1, '=')
      ->condition('p.user_id', $user->uid, '=');
  $query->fields('p', array('file_name'));
  # execute the query
  $results = $query->execute()->fetchObject();
  $path = file_create_url('public://');
  echo $real_path = $path . $results->file_name;
}

/**
 * get budget data from table.
 * @param string $year
 * @return array
 */
function check_budget($section_id) {
  $query = db_select('itg_manage_budget', 'm');
  $query->fields('m', array('id', 'budget_title', 'budget_description', 'budget_message', 'budget_social_message', 'status'));
  $query->condition('m.budget_section', $section_id);
  $record = $query->range(0, 1)->execute()->fetchAssoc();
  return $record;
}

/**
 * get budget id
 * @param string $timestamp
 * @return int
 */
function check_budget_status($section_id) {
  $query = db_select('itg_budget_predictor', 'p');
  $query->condition('p.section_id', $section_id)
      ->condition('p.status', 2, '=')
      ->condition('p.file_name', '', '!=');
  $query->fields('p', array('budget_id'));
  # execute the query
  $results = $query->execute()->fetchObject();
  return $results->budget_id;
}

/**
 * get budget id
 * @param string $timestamp
 * @return int
 */
function check_budget_status_front_user($section_id) {
  global $user;
  $user_id = $user->uid;
  $query = db_select('itg_budget_predictor', 'p');
  $query->condition('p.section_id', $section_id)->condition('p.status', 1, '=');
  if ($user_id && $user_id > 1) {
    $query->condition('p.user_id', $user->uid);
  }
  else {
    $query->condition('p.cookies_id', $cookies_id);
  }

  $query->condition('p.file_name', '', '!=');
  $query->fields('p', array('budget_id'));
  # execute the query
  $results = $query->execute()->fetchObject();
  return $results->budget_id;
}

/**
 * Download Excel
 */
function itg_budget_download_excel() {

  $section_id = isset($_GET['section_id']) ? $_GET['section_id'] : '';
  $user_id = isset($_GET['user_type']) ? $_GET['user_type'] : '';

  $query = db_select('itg_budget_predictor', 'p');
  if (!empty($section_id)) {
    $query->condition('p.section_id', $section_id);
  }
  if ($user_id == 1) {
    $query->condition('p.user_id', 0, '=');
  }
  else if ($user_id == 2) {
    $query->condition('p.user_id', $user_id, '>=');
  }
  $query->fields('p', array('user_id'));
  $query->condition('p.status', 1, '=')->groupBy('p.user_id');
  # execute the query
  $result = $query->execute()->fetchAll();

  $name = date('d-m-y') . '-budget-usermail-list.xls';
  header("Content-type:application/vnd.ms-excel;name='excel'");
  header("Content-Disposition: attachment; filename=$name");
  header("Pragma: no-cache");
  header("Expires: 0");
  echo "Mail";
  echo "\015\012";
  foreach ($result as $row) {
    pr($row);
    $mail = !empty($row->user_id) ? user_load($row->user_id)->mail : t('Anonymous user');
    echo $mail;
    echo "\015\012";
  }
}

/**
 * update user by cookies
 * @param int $user_id
 * @param int $section_id
 * @param string $cookies_id
 */
function update_user_by_cookies($user_id, $section_id, $cookies_id) {
  db_update('itg_budget_predictor')
      ->fields(array('user_id' => $user_id))
      ->condition('section_id', $section_id)
      ->condition('cookies_id', $cookies_id, '=')
      ->condition('user_id', 0, '=')
      ->execute();
}

	/**
 * check existing user play predictor widget. 
 * @param int $user_id
 * @param int $section_id
 * @param string $cookies_id
 * @return int
 */
function check_exist_predictor($user_id, $section_id) {
    return db_select('itg_budget_predictor')
          ->fields(NULL, array('user_id'))
          ->condition('user_id', $user_id, '=')
          ->condition('section_id', $section_id)
          ->countQuery()->execute()
          ->fetchField();
}