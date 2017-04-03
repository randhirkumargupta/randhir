<?php

function itg_reports_save_section_wise_report_data($tid , $uid , $node) {
  global $user;
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->section_breakup;
      $qry = array(
        "nid" => $node->nid ,
        "uid" => $user->uid ,
        "type" => $node->type ,
        "section" => $tid ,
        "viewtime" => REQUEST_TIME
      );
      $people->insert($qry);
    }
  }
}

function itg_section_wise_breakup_form($form , &$form_state) {
  $form = array();
  $form['content_type'] = array(
    '#title' => t('Content type') ,
    '#type' => 'select' ,
    '#options' => array(
      '' => '-- Select --' ,
      'story' => 'Story' ,
      'videogallery' => "Video gallery" ,
      'photogallery' => "Photogallery" ,
    ) ,
    '#default_value' => isset($_GET['type']) ? $_GET['type'] : "" ,
  );

  $form['range_group_one'] = array(
    '#type' => 'fieldset',
    '#title' => 'Date range'
  );  
  $form['range_group_one']['date_from'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date from') ,
    '#attributes' => array("placeholder" => array("Enter Date From")) ,
    '#default_value' => isset($_GET['date_from']) ? date('d-m-Y' , $_GET['date_from']) : "" ,
  );

  $form['range_group_one']['date_to'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date to') ,
    '#attributes' => array("placeholder" => array("Enter Date To")) ,
    '#default_value' => isset($_GET['date_to']) ? date('d-m-Y' , $_GET['date_to']) : "" ,
  );
  
  $form['range_group_two'] = array(
    '#type' => 'fieldset',
    '#title' => 'Date range'
  );  
  $form['range_group_two']['date_from_two'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date from') ,
    '#attributes' => array("placeholder" => array("Enter Date From")) ,
    '#default_value' => isset($_GET['date_from']) ? date('d-m-Y' , $_GET['date_from']) : "" ,
  );

  $form['range_group_two']['date_to_two'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date to') ,
    '#attributes' => array("placeholder" => array("Enter Date To")) ,
    '#default_value' => isset($_GET['date_to']) ? date('d-m-Y' , $_GET['date_to']) : "" ,
  );

  $form['items_per_page'] = array(
    '#type' => 'select' ,
    '#title' => 'Items per page' ,
    '#options' => array(5 => 5 , 10 => 10 , 20 => 20 , 40 => 40 , 60 => 60 , 100 => 100 , 500 => 500 , 1000 => 1000) ,
    '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20 ,
  );

  $form['submit'] = array(
    '#value' => 'Apply' ,
    '#type' => 'submit' ,
    '#attributes' => array('class' => array('user-all-content')) ,
    '#prefix' => '<div class = "user-log-filter-btn">' ,
    '#suffix' => '<a class="user-log-reset" href="' . base_path() . 'itg-section-wise-breakup-report">' . t('Reset') . '</a></div>' ,
  );

  $form['markup'] = array(
    '#type' => 'markup' ,
    '#markup' => itg_section_wise_breakup_table() ,
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module' , 'itg_reports') . '/js/itg_reports.js' ,
  );

  return $form;
}

function itg_section_wise_breakup_form_submit($form , $form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $date_from_two = $form_state['values']['date_from_two'];
  $date_to_two = $form_state['values']['date_to_two'];
  $content_type = $form_state['values']['content_type'];
  $item_per_page = $form_state['values']['items_per_page'];
  $path = 'itg-section-wise-breakup-report';
  $options = array(
    'query' => array(
      'date_from' => strtotime('-1day' , strtotime($date_from)) ,
      'date_to' => strtotime('+1day' , strtotime($date_to)) ,
      'date_from_two' => strtotime('-1day' , strtotime($date_from_two)) ,
      'date_to_two' => strtotime('+1day' , strtotime($date_to_two)) ,
      'type' => $content_type ,
      'item_per_page' => $item_per_page ,
    )
  );
  drupal_goto($path , $options);
}

function itg_section_wise_breakup_table() {
  module_load_include('php' , 'itg_reports' , 'includes/pagination');
  module_load_include('inc' , 'itg_reports' , 'includes/itg_reports.helper');

  $start_date = isset($_GET['date_from']) ? $_GET['date_from'] : NULL;
  $end_date = isset($_GET['date_to']) ? $_GET['date_to'] : NULL;

  $start_date_two = isset($_GET['date_from_two']) ? $_GET['date_from_two'] : NULL;
  $end_date_two = isset($_GET['date_to_two']) ? $_GET['date_to_two'] : NULL;
  
  $type = isset($_GET['type']) ? $_GET['type'] : NULL;

  $table_data = itg_section_wise_breakup_mongo_data($start_date , $end_date , $type);
  
  $table_data_two = itg_section_wise_breakup_mongo_data($start_date_two , $end_date_two , $type);
  
  arsort($table_data);
  foreach ($table_data as $section => $count) {
    $new_table_data[] = array(
      'section' => $section ,
      'count' => $count+1 ,
    );
  }
  $products = $new_table_data;
  // Create the pagination object
  $pagination = new pagination;
  $count = 0;
  $header = array(
    array('data' => t('ID')) ,
    array('data' => t('Section')) ,
    array('data' => t('Section ID')) ,
    array('data' => t('Nodes Viewd')) ,
    array('data' => t('Action')) ,
  );
  // If we have an array with items
  if (count($products)) {
    // Parse through the pagination class
    $item_per_page = isset($_GET['item_per_page']) ? $_GET['item_per_page'] : 20;
    $user_details_pages = $pagination->generate($products , $item_per_page);
    //p($user_details_pages);
    // Load users report data.
    // If we have items 
    if (count($user_details_pages) != 0) {
      // Get pagination.
      $pageNumbers = '<div class="numbers">' . $pagination->links() . '</div>';

      foreach ($user_details_pages as $row) {
        //p(taxonomy_term_load($row['section']));
        // Prepare rows as per pagination.
        $rows[] = array(
          array('data' => $count + 1) ,
          array('data' => $row['section']) ,
          array('data' => get_term_name_from_tid($row['section'])->name),
          array('data' => $row['count']) ,
          array('data' => l('View Section' , 'taxonomy/term/' . $row['section'] , array("attributes" => array("target" => array("_blank"))))) ,
        );
        $count++;
      }

      $output = '<div class="view"><div class="attachment"><span class="count">Count (' . count($table_data) . ') </span>';
      $output .= '</div></div>';
      $output .= theme('table' , array('header' => $header , 'rows' => $rows , 'attributes' => array('class' => array('views-table' , 'preview-log-table')) , 'empty' => 'No result found.'));
      // add the pager
      $output .= '<ul class="pager">' . $pageNumbers . '</ul>';
      return $output;
    }
  }
}

function itg_section_wise_breakup_mongo_data($start_date , $end_date , $type) {
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $collection = $conn->section_breakup;
      if (empty($start_date)) {
        $start_date = 0;
      }

      if (empty($end_date)) {
        $end_date = time() + 100;
      }

      $condition = array(
        'viewtime' => array(
          '$gte' => (int) $start_date ,
          '$lte' => (int) $end_date ,
        ) ,
      );

      if (!empty($type)) {
        $condition['type'] = array(
          '$eq' => $type ,
        );
      }

      $cursor = $collection->find($condition);

      foreach ($cursor as $item_data) {
        $count = count($final_data[$item_data['section']]);
        $final_data[$item_data['section']][] = $count;
        $final_data_array_count[$item_data['section']] = end($final_data[$item_data['section']]);
      }
      return $final_data_array_count;
    }
    return array();
  }
  return array();
}
