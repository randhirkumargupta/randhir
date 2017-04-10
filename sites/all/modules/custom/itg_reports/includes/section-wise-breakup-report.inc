<?php

/**
 * Function which insert section wise report data in mongo
 * @global array $user
 * @param int $tid
 * @param int $uid
 * @param array $node
 */
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

/**
 * Implements hook_form.
 */
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
    '#type' => 'fieldset' ,
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
    '#type' => 'fieldset' ,
    '#title' => 'Date range'
  );
  $form['range_group_two']['date_from_two'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date from') ,
    '#attributes' => array("placeholder" => array("Enter Date From")) ,
    '#default_value' => isset($_GET['date_from_two']) ? date('d-m-Y' , $_GET['date_from_two']) : "" ,
  );

  $form['range_group_two']['date_to_two'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date to') ,
    '#attributes' => array("placeholder" => array("Enter Date To")) ,
    '#default_value' => isset($_GET['date_to_two']) ? date('d-m-Y' , $_GET['date_to_two']) : "" ,
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
    '#suffix' => '<a class="user-log-reset btn-reset" href="' . base_path() . 'itg-section-wise-breakup-report">' . t('Reset') . '</a></div>' ,
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

/**
 * Implements hook_form_submit().
 */
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
      'date_from' => (!empty($date_from)) ? strtotime($date_from) : "" ,
      'date_to' => (!empty($date_to)) ? strtotime($date_to) : "" ,
      'date_from_two' => (!empty($date_from_two)) ? strtotime($date_from_two) : "" ,
      'date_to_two' => (!empty($date_to_two)) ? strtotime($date_to_two) : "" ,
      'type' => $content_type ,
      'item_per_page' => $item_per_page ,
    )
  );
  drupal_goto($path , $options);
}

/**
 * Function which returns table of report.
 * @return string
 */
function itg_section_wise_breakup_table() {
  module_load_include('php' , 'itg_reports' , 'includes/pagination');
  module_load_include('inc' , 'itg_reports' , 'includes/itg_reports.helper');

  $start_date = isset($_GET['date_from']) ? $_GET['date_from'] : NULL;
  $end_date = isset($_GET['date_to']) ? $_GET['date_to'] : NULL;
  $start_date_two = isset($_GET['date_from_two']) ? $_GET['date_from_two'] : NULL;
  $end_date_two = isset($_GET['date_to_two']) ? $_GET['date_to_two'] : NULL;
  $type = isset($_GET['type']) ? $_GET['type'] : NULL;

  $start_date = strtotime('-1day' , $start_date);
  $end_date = strtotime('+1day' , $end_date);
  $start_date_two = strtotime('-1day' , $start_date_two);
  $end_date_two = strtotime('+1day' , $end_date_two);

  $table_data = itg_section_wise_breakup_mongo_data($start_date , $end_date , $type);
  $table_data_two = itg_section_wise_breakup_mongo_data($start_date_two , $end_date_two , $type);

  $all_sections = array_unique(array_merge(array_keys($table_data_two) , array_keys($table_data)));
  $full_table = array_unique(array_merge(array_keys($table_data) , array_keys($table_data_two)));

  $output_table_array = array();
  foreach ($full_table as $key => $unique_section) {
    $output_table_array[$unique_section] = array(
      "DR_1" => $table_data[$unique_section] ,
      "DR_2" => $table_data_two[$unique_section] ,
    );
  }

  foreach ($output_table_array as $section => $count) {
    $DR_1 = (int) $count['DR_1'] + 1;
    $DR_2 = (int) $count['DR_2'] + 1;
    if ($DR_1) {
      $percentage_growth = ((($DR_2 - $DR_1))/$DR_1)*100;
    }
    else {
      $percentage_growth = ($DR_2)*10;
    }
    $new_table_data[] = array(
      'section' => $section ,
      'viewed' => $DR_1 . '-' . $DR_2 ,
      'count' => $percentage_growth . '%' ,
    );
  }
  $products = $new_table_data;
  // Create the pagination object
  $pagination = new pagination;
  $count = 0;
  $date_from_1 = date('d-m-Y' , $_GET['date_from']);
  $date_from_2 = date('d-m-Y' , $_GET['date_from_two']);
  $date_to_1 = date('d-m-Y' , $_GET['date_to']);
  $date_to_2 = date('d-m-Y' , $_GET['date_to_two']);
  $string = $date_from_1 . " to " . $date_from_2;
  $string .= "<br/>";
  $string .= $date_to_1 . " to " . $date_to_2;
  $header = array(
    array('data' => t('S.No')) ,
    array('data' => t('Section ID')) ,
    array('data' => t('Section')) ,
    array('data' => t("Node Viewed <br/>" . $string)) ,
    array('data' => t('Actions')) ,
  );
  // If we have an array with items
  if (count($products)) {
    // Parse through the pagination class
    $item_per_page = isset($_GET['item_per_page']) ? $_GET['item_per_page'] : 20;
    $user_details_pages = $pagination->generate($products , $item_per_page);
    // Load users report data.
    // If we have items 
    if (count($user_details_pages) != 0) {
      // Get pagination.
      $pageNumbers = '<div class="numbers">' . $pagination->links() . '</div>';
      foreach ($user_details_pages as $row) {
        // Prepare rows as per pagination.
        $rows[] = array(
          array('data' => $count + 1) ,
          array('data' => $row['section']) ,
          array('data' => get_term_name_from_tid_for_report($row['section'])->name) ,
          array('data' => '<' . $row['viewed'] . '> ' . $row['count']) ,
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

/**
 * Main function to return report.
 * 
 * @param int $start_date
 * @param int $end_date
 * @param string $type
 * @return mixed
 */
function itg_section_wise_breakup_mongo_data($start_date , $end_date , $type) {
  $final_data_array_count = array();
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $collection = $conn->section_breakup;
      if (empty($start_date)) {
        $start_date = 0;
      }

      if (empty($end_date)) {
        $end_date = time() + 1;
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
