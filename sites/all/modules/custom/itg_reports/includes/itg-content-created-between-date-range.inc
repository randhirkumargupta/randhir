<?php

define('REPORT_PER_PAGE', 50);

function itg_report_created_date_range($form, $form_state) {
  drupal_add_js(drupal_get_path('module', 'itg_reports') . '/js/itg_reports.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_css("#ui-datepicker-div {display:none} ", 'inline');
  $form['content_type'] = array(
    '#type' => 'select',
    '#title' => 'Select Content Type',
    '#options' => array(
      'All' => 'All',
      'story' => 'Story',
      'videogallery' => 'Videogallery',
      'photogallery' => 'Photogallery',
      'podcast' => 'Podcast',
      'mega_review_critic' => 'Mega Review & Critic',
    ),
    '#default_value' => isset($_GET['content_type']) ? $_GET['content_type'] : "All",
  );
  // Range1
  $form['range1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Range 1'),
  );

  $form['range1']['rg1_date_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Date from'),
    '#default_value' => (!empty($_GET['rg1_date_from'])) ? $_GET['rg1_date_from'] : date('Y-m-d', strtotime('-1day')),
    '#attributes' => array('readonly' => 'readonly' , 'size'=>0),
  );
  $form['range1']['rg1_date_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Date to'),
    '#attributes' => array('readonly' => 'readonly' , 'size'=>0),
    '#default_value' => (!empty($_GET['rg1_date_to'])) ? $_GET['rg1_date_to'] : date('Y-m-d', strtotime('-1day')),
  );
  // Range 2
  $form['range2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Range 2'),
  );
  $form['range2']['rg2_date_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Date from'),
    '#attributes' => array('readonly' => 'readonly' , 'size'=>0),
    '#default_value' => (!empty($_GET['rg2_date_from'])) ? $_GET['rg2_date_from'] : date('Y-m-d'),
  );
  $form['range2']['rg2_date_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Date to'),
    '#attributes' => array('readonly' => 'readonly' , 'size'=>0),
    '#default_value' => (!empty($_GET['rg2_date_to'])) ? $_GET['rg2_date_to'] : date('Y-m-d'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['reset'] = array(
    '#type' => 'markup',
    '#markup' => l('Reset', 'itg-content-created-between-date-range', array('attributes' => array('class' => array('btn-reset')))),
  );

  $form['report_markup'] = array(
    '#type' => 'markup',
    '#markup' => __form_markup_dispay_report(),
  );

  return $form;
}

/**
 * Implements Hook_form_submit.
 * {@inheritdocs}
 */
function itg_report_created_date_range_submit($form, $form_state) {
  $rg1_date_from = $form_state['values']['rg1_date_from'];
  $rg1_date_to = $form_state['values']['rg1_date_to'];
  $rg2_date_from = $form_state['values']['rg2_date_from'];
  $rg2_date_to = $form_state['values']['rg2_date_to'];
  $content_type = $form_state['values']['content_type'];
  $path = "itg-content-created-between-date-range";
  $options = array(
    'query' => array(
      'rg1_date_from' => $rg1_date_from,
      'rg1_date_to' => $rg1_date_to,
      'rg2_date_from' => $rg2_date_from,
      'rg2_date_to' => $rg2_date_to,
      'content_type' => $content_type,
    ),
  );
  drupal_goto($path, $options);
}

/**
 * Function which gives output for report.
 * 
 * @global string $base_url
 * @param string $start_date
 * @param string $end_date
 * @return string
 */
function itg_report_created_date_range_display_report($start_date, $end_date) {
  global $base_url;
  $page = 1;
  if (!empty($_GET['page'])) {
    $page = filter_input(INPUT_GET, 'page', FILTER_VALIDATE_INT);
    if (false === $page) {
      $page = 1;
    }
  }
  $offset = ($page - 1) * REPORT_PER_PAGE;
  
  $final_output = [];
  //Create proper timestemp for start date.
  $s_date_time_stamp = strtotime($start_date);
  $s_day = date('d', $s_date_time_stamp);
  $s_month = date('m', $s_date_time_stamp);
  $s_year = date('Y', $s_date_time_stamp);
  $start_date_timstamp = mktime(0, 0, 0, $s_month, $s_day, $s_year);

  //Create proper timestemp for end date.
  $e_date_time_stamp = strtotime($end_date);
  $e_day = date('d', $e_date_time_stamp);
  $e_month = date('m', $e_date_time_stamp);
  $e_year = date('Y', $e_date_time_stamp);

  $end_date_timestamp = mktime(23, 59, 59, $e_month, $e_day, $e_year);

  $query = db_select('node', 'n');
  $query->fields('n', array('title', 'type', 'nid', 'created'));
  $query->condition('n.created', array($start_date_timstamp, $end_date_timestamp), 'BETWEEN');

  if (isset($_GET['content_type']) && strtolower($_GET['content_type']) != 'all') {
    $query->condition('n.type', $_GET['content_type']);
  } else {
    $query->condition('n.type', array("story", "videogallery", "photogallery", "podcast", "mega_review_critic"));
  }
  $query->range($offset, REPORT_PER_PAGE);
  $query->orderBy('n.nid', 'DESC');
  $query->condition('n.status', 1);
  $data = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $count_query = db_select('node', 'n');
  $count_query->fields('n', array('nid'));
  $count_query->condition('n.created', array($start_date_timstamp, $end_date_timestamp), 'BETWEEN');
  if (isset($_GET['content_type']) && strtolower($_GET['content_type']) != 'all') {
    $count_query->condition('n.type', $_GET['content_type']);
  } else {
    $count_query->condition('n.type', array("story", "videogallery", "photogallery", "podcast", "mega_review_critic"));
  }
  $count_query->condition('n.status', 1);
  $row_count = $count_query->execute()->rowCount();
  
  $header = array(
    array('data' => t('S.No')),
    array('data' => t('Type')),
    array('data' => t('Titte')),
    array('data' => '<span title="d-M-Y H:i:s">'. t('Created Date') . '</span>'),
    array('data' => t('Url')),
  );

  $count = 0;
  foreach ($data as $row) {
    // Prepare rows as per pagination.
    $rows[] = array(
      array('data' => $count + 1),
      array('data' => $row['type']),
      array('data' => $row['title']),
      array('data' => date('d-M-Y H:i:s' , $row['created'])),
      array('data' => FRONT_URL . url('node/' . $row['nid'])),
    );
    $count++;
  }

  $final_output['row_count'] = $row_count;
  $final_output['pagger'] = _create_pagnation($row_count);
  $final_output['table'] = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table', 'date-wise-content-report')), 'empty' => 'No result found.'));

  return $final_output;
}

/**
 * Function creates pagination.
 * 
 * @param int $total_rows
 * @return string
 */
function _create_pagnation($total_rows) {
  global $base_url;
  //include pagination class file
  module_load_include('php', 'itg_reports', 'includes/pagination_new');
  $data_url = array(
    'q' => 'itg-content-created-between-date-range',
    'rg1_date_from' => $_GET['rg1_date_from'],
    'rg1_date_to' => $_GET['rg1_date_to'],
    'rg2_date_from' => $_GET['rg2_date_from'],
    'rg2_date_to' => $_GET['rg2_date_to'],
  );
//initialize pagination class
  $pagConfig = array(
    'baseURL' => $base_url . "?" . http_build_query($data_url),
    'totalRows' => $total_rows,
    'perPage' => REPORT_PER_PAGE
  );
  $pagination = new Pagination($pagConfig);
  return $pagination->createLinks();
}

/**
 * Function gives tabluar markup for form api to display report.
 * 
 * @return string
 */
function __form_markup_dispay_report() {
  $div = '';
  $rg1_date_from = isset($_GET['rg1_date_from']) ? $_GET['rg1_date_from'] : date('Y-m-d', strtotime('-1day'));
  $rg1_date_to = isset($_GET['rg1_date_to']) ? $_GET['rg1_date_to'] : date('Y-m-d', strtotime('-1day'));
  $rg2_date_from = isset($_GET['rg2_date_from']) ? $_GET['rg2_date_from'] : date('Y-m-d');
  $rg2_date_to = isset($_GET['rg2_date_to']) ? $_GET['rg2_date_to'] : date('Y-m-d');

  $report1_data = itg_report_created_date_range_display_report($rg1_date_from, $rg1_date_to);
  $report2_data = itg_report_created_date_range_display_report($rg2_date_from, $rg2_date_to);

  $div .= '<div class="row">';
  $div .= '<div class="col-md-6">';
  $div .= '<div class="pull-right"> Range1 Count: <b>' . $report1_data['row_count'] . '</b> </div>';
  $div .= $report1_data['table'];
  $div .= '</div>';
  $div .= '<div class="col-md-6">';
  $div .= '<div class="pull-right">Range2 Count: <b>' . $report2_data['row_count'] . '</b> </div>';
  $div .= $report2_data['table'];
  $div .= '</div>';
  $div .= '</div>';
  $div .= '<div class="row">';
  $div .= '<div class="col-md-12">';
  if ($report1_data['row_count'] > $report2_data['row_count']) {
    $final_output_pagger = $report1_data['pagger'];
  } else {
    $final_output_pagger = $report2_data['pagger'];
  }
  $div .= $final_output_pagger;
  $div .= '</div>';
  $div .= '</div>';
  return $div;
}
