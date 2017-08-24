<?php

/**
 * @file
 * ITG Octopus RFA inc.
 *
 * This file is responsible for managing RFA (For Live Blog)
 *
 */

/**
 * Entry in RFA for live blog
 */
function itg_rfa_file_live_blog() {
  if (isset($_POST) && !empty($_POST)) {
    $rfa_data = $_POST;
    $success = 0;
    foreach ($rfa_data as $key => $post) {
      $rundown_id = isset($post['rundown_id']) ? $post['rundown_id'] : 0;
      $source = isset($post['source']) ? $post['source'] : '';
      $text = isset($post['text']) ? $post['text'] : '';
      $created_date = isset($post['created_date']) ? $post['created_date'] : 0;
      $created_by = isset($post['created_by']) ? $post['created_by'] : '';
      $timestamp = REQUEST_TIME;
      $action = isset($post['action']) ? $post['action'] : '';
      $msg = '';
      $hyperlink = 'rfa-dashboard';
      $msg = '[' . $action . '] ' . $text . '(' . $rundown_id . ')[RFA]';
      itg_octopus_add_notification('RFA', $msg, $hyperlink, '', REQUEST_TIME, 1);

      if ($action == 'UPDATE') {
        itg_octopus_api_send_email_to_octopus("You have received UPDATE tag in XML(RFA)", 'You have received UPDATE tag in XML for breaking news:' . $text);
      }

      if ($action == 'DELETE') {
        itg_octopus_api_send_email_to_octopus("You have received DELETE tag in XML(RFA)", 'You have received DELETE tag in XML for breaking news:' . $text);
      }

      try {
        db_merge('itg_rfa')
            ->key(array('rundown_id' => $rundown_id, 'created_date' => $created_date))
            ->fields(array(
              'rundown_id' => $rundown_id,
              'source' => $source,
              'text' => $text,
              'created_date' => $created_date,
              'created_by' => $created_by,
              'timestamp' => $timestamp,
              'action' => $action,
            ))
            ->execute();
        $success = 1;
      }
      catch (Exception $e) {
        $success = 0;
        watchdog('aaa', '<pre>' . print_r($e->getMessage(), true) . '</pre>');
      }
    }

    if ($success == 1) {
      $msg_object = array(
        'success' => 1,
        'msg' => 'Data have been inserted successfully',
      );
      print drupal_json_output($msg_object);
      drupal_exit();
    }
  }
  else {
    print 'Access Denied';
    drupal_exit();
  }
}

/**
 * This method is used to test the data
 */
function itg_rfa_file_testing() {

  global $base_url;
  $rundown_id = 1223544;
  $source = 'This is source';
  $text = 'Hi this is for testing';
  $created_date = REQUEST_TIME;
  $created_by = 'Ishwar';
  $action = 'INSERT';

  $url = $base_url . "/itg-rfa-file-live-blog";
  $data = array(
    array(
      'rundown_id' => 121211,
      'source' => 'This is source',
      'text' => 'Hi this is for testing',
      'created_date' => REQUEST_TIME,
      'created_by' => 'Ishwar',
      'action' => 'INSERT',
    ),
    array(
      'rundown_id' => 121212,
      'source' => 'This is source',
      'text' => 'Hi this is for testing',
      'created_date' => REQUEST_TIME,
      'created_by' => 'Ishwar',
      'action' => 'DELETE',
    ),
    array(
      'rundown_id' => rand(12234, 55555),
      'source' => 'This is source',
      'text' => 'Hi this is for testing',
      'created_date' => REQUEST_TIME,
      'created_by' => 'Ishwar',
      'action' => 'UPDATE',
    ),
  );


  $options = array(
    'method' => 'POST',
    'data' => http_build_query($data, '', '&'),
    'timeout' => 15,
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
  );

  $result = drupal_http_request($url, $options);
  if ($result->code == 200) {
    $return_data = json_decode($result->data);
    if ($return_data->success == 1) {
      print $return_data->msg;
    }
  }
}

/**
 * This method is responsible for dashboard, filter and file  of FRA
 * @global type $base_url
 * @return type
 */
function itg_octopus_api_rfa_dashboard() {
  global $base_url;
  // This is for handling RFA notification read
  if (isset($_GET['onotify']) && !empty($_GET['onotify'])) {
    itg_octopus_notification_by_uid($_GET['onotify']);
  }
  drupal_add_css(drupal_get_path('module', 'itg_octopus_api') . '/css/itg_octopus_api.css');

  drupal_add_js("jQuery(document).ready(function(){
jQuery('#itg-octopus-api-rfa-form #edit-start-date-timeEntry-popup-1').attr('placeholder', 'Time');
jQuery('#itg-octopus-api-rfa-form #edit-end-date-timeEntry-popup-1').attr('placeholder', 'Time');
});", array('type' => 'inline', 'scope' => 'footer'));


  $query = db_select('itg_rundown', 'r')
      ->fields('r', array('rundown_id'));
  $result = $query->execute()->rowCount();
# configure the table header columns

  $header = array(
    array('data' => t('Sn.')),
    array('data' => t('RFA ID')),
    array('data' => t('Source')),
    array('data' => t('Text')),
    array('data' => t('Created Date')),
    array('data' => t('Created By')),
    array('data' => t('Action')),
  );

  $pagination = '';
  $current_rundown = '';

  $query = db_select('itg_rfa', 'rfa')->extend('PagerDefault')->limit(50);
  $query->fields('rfa');

  if (isset($_GET['source']) && !empty($_GET['source'])) { // source
    $query->condition('rfa.source', $_GET['source'], '=');
  }

  if (isset($_GET['rfaid']) && !empty($_GET['rfaid'])) { // rfaid
    $query->condition('rfa.rundown_id', $_GET['rfaid'], '=');
  }


  if (isset($_GET['text']) && !empty($_GET['text'])) { // text
    $query->condition('rfa.text', $_GET['text'], '=');
  }


  $start_date = isset($_GET['start_date']) && !empty($_GET['start_date']) && $_GET['start_date'] != ' ' ? trim($_GET['start_date']) : '';
  $end_date = isset($_GET['end_date']) && !empty($_GET['end_date']) && $_GET['end_date'] != ' ' ? trim($_GET['end_date']) : '';


  if (isset($start_date) && !empty($start_date)) { // start date
    $query->condition('rfa.created_date', strtotime($start_date), '>=');
  }

  if (isset($end_date) && !empty($end_date)) { // end date
    $query->condition('rfa.created_date', strtotime($end_date), '<=');
  }

  $query->orderBy('rfa.id', 'DESC');

  $result = $query->execute();
  $rows = array();
  $sn = 1;

  foreach ($result as $row) {
    $octopus_ref = base64_encode($row->id);
    $ctype_text = l('File Breaking News', $base_url . '/node/add/breaking-news?destination=rfa-dashboard&octopus_ref=' . $octopus_ref);
    $background_color = 'bg-none';
    if ($row->action == 'DELETE') {
      $background_color = 'bg-red';
    }
    elseif ($row->action == 'UPDATE') {
      $background_color = 'bg-yellow';
    }
    else {
      $background_color = 'bg-none';
    }
    $rows[] = array(
      array('data' => $sn++),
      array('data' => $row->rundown_id),
      array('data' => $row->source),
      array('data' => $row->text),
      array('data' => date('d/m/Y - H:i:s', $row->created_date), 'class' => $background_color),
      array('data' => $row->created_by),
      array('data' => $ctype_text),
    );
  }
  $itg_octopus_api_form = drupal_get_form('itg_octopus_api_rfa_form');

  $rundown_active_class = '';
  $rfa_active_class = '';
  if (isset($_GET['q']) && $_GET['q'] == 'rundown-listing') {
    $rundown_active_class = 'active-trail';
  }
  elseif (isset($_GET['q']) && $_GET['q'] == 'rfa-dashboard') {
    $rfa_active_class = 'active-trail';
  }
  $output = '<div class="content-block-menu">
            <ul class="menu">
           <li>' . l('Rundown', 'rundown-listing', array('attributes' => array('class' => array($rundown_active_class)))) . '</li>
           <li>' . l('RFA', 'rfa-dashboard', array('attributes' => array('class' => array($rfa_active_class)))) . '</li>
           </ul>
           </div>';
  $output .= render($itg_octopus_api_form);
  $output .= '<div class="octopus-pagination"><ul class="pager">' . $pagination . '</ul></div>';
  $output .= '<div class="octopus-pagination"><span style="float:right;">Count(' . count($rows) . ')</span></div>';
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));
# add the pager
  $output .= theme('pager');
  return $output;
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 */
function itg_octopus_api_rfa_form($form, &$form_state) {
  $form = array();


  $form['source'] = array(
    '#type' => 'textfield',
    '#title' => t('Source'),
    '#maxlength' => 255,
    '#size' => 30,
    '#default_value' => isset($_GET['source']) ? $_GET['source'] : '',
    '#weight' => 2,
  );

  $form['rfaid'] = array(
    '#type' => 'textfield',
    '#title' => t('RFA Id'),
    '#maxlength' => 255,
    '#size' => 30,
    '#default_value' => isset($_GET['rfaid']) ? $_GET['rfaid'] : '',
    '#weight' => 2,
  );

  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#maxlength' => 255,
    '#size' => 30,
    '#default_value' => isset($_GET['text']) ? $_GET['text'] : '',
    '#weight' => 2,
  );

  $form['start_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Start Date'),
    '#input' => TRUE,
    '#tree' => TRUE,
    '#date_timezone' => date_default_timezone(),
    '#date_flexible' => 0,
    '#date_format' => 'Y-m-d - H:i',
    '#timepicker' => 'default',
    '#date_increment' => 1,
    '#date_year_range' => '-100:+0',
    '#date_label_position' => 'above',
    '#process' => array('date_popup_element_process'),
    '#value_callback' => 'date_popup_element_value_callback',
    '#theme_wrappers' => array('date_popup'),
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly', 'placeholder' => 'Start Date'),
    '#weight' => 4,
    '#default_value' => isset($_GET['start_date']) ? $_GET['start_date'] : '',
  );

  $form['end_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('End Date'),
    '#input' => TRUE,
    '#tree' => TRUE,
    '#date_timezone' => date_default_timezone(),
    '#date_flexible' => 0,
    '#date_format' => 'Y-m-d - H:i',
    '#timepicker' => 'default',
    '#date_increment' => 1,
    '#date_year_range' => '-100:+0',
    '#date_label_position' => 'above',
    '#process' => array('date_popup_element_process'),
    '#value_callback' => 'date_popup_element_value_callback',
    '#theme_wrappers' => array('date_popup'),
    '#attributes' => array('autocomplete' => 'off', 'readonly' => 'readonly', 'placeholder' => 'End Date'),
    '#weight' => 5,
    '#default_value' => isset($_GET['end_date']) ? $_GET['end_date'] : '',
  );

  $form['submit'] = array(
    '#value' => 'Apply',
    '#type' => 'submit',
    '#attributes' => array('class' => array('octopus-apply btn-small')),
    '#prefix' => '<div class = "octopus-filter-btn">',
    '#suffix' => '<a class="btn-reset  btn-small" href="' . base_path() . 'rfa-dashboard">Reset</a></div>',
    '#weight' => 7,
  );
  return $form;
}

/**
 * Implements hook_validate for form validation handler
 * {@inheritdoc}
 */
function itg_octopus_api_rfa_form_validate($form, &$form_state) {

  $flag = 0;
  if (!empty($form_state['values']['start_date']['date']) && empty($form_state['values']['start_date']['time'])) {

    $array_error['start_date[time]'] = t("Please enter start date time.");
    $flag = 1;
  }
  if (!empty($form_state['values']['end_date']['date']) && empty($form_state['values']['end_date']['time'])) {
    $array_error['end_date[time]'] = t("Please enter end date time.");
    $flag = 1;
  }
  if ($flag == 1) {
    drupal_get_messages('error');
    foreach ($array_error as $key => $msgs) {
      form_set_error(check_plain($key), check_plain($msgs));
    }
  }
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_octopus_api_rfa_form_submit($form, &$form_state) {
  $form_state['redirect'] = array(
    'rfa-dashboard',
    array(
      'query' => array(
        'source' => $form_state['input']['source'],
        'rfaid' => $form_state['input']['rfaid'],
        'text' => $form_state['input']['text'],
        'start_date' => $form_state['input']['start_date']['date'] . ' ' . $form_state['input']['start_date']['time'],
        'end_date' => $form_state['input']['end_date']['date'] . ' ' . $form_state['input']['end_date']['time'],
      ),
    ),
  );
}
