<?php

/**
 * Main function for reports.
 * {@inheritdoc}.
 */
function itg_registered_vs_anonymous_user_form() {
  $form = array();

  $form['date_from'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date From') ,
    '#attributes' => array("placeholder" => 'Enter Date From'),
    '#default_value' => (!empty($_GET['date_from'])) ? date('d-m-Y' , $_GET['date_from']) : "" ,
  );

  $form['date_to'] = array(
    '#type' => 'textfield' ,
    '#title' => t('Date From') ,
    '#attributes' => array("placeholder" => 'Enter Date To'),
    '#default_value' => (!empty($_GET['date_to'])) ? date('d-m-Y' , $_GET['date_to']) : "" ,
  );

  $form['submit'] = array(
    '#type' => 'submit' ,
    '#value' => t('Submit') ,
  );

  $form['reset'] = array(
    '#type' => 'markup' ,
    '#markup' => l('Reset' , 'itg-registered-vs-anonymous-user-content-visited-report' , array('attributes' => array('class' => array('btn-reset')) , 'query' => array('report_type' => 'section_wise_report'))) ,
  );

  $form['chart'] = array(
    '#markup' => print_registered_vs_anonymous_chart() ,
  );

  drupal_add_js(drupal_get_path('module' , 'itg_reports') . '/js/itg_reports.js' , array('type' => 'file'));
  return $form;
}

/**
 * {@inheritdoc}.
 */
function itg_registered_vs_anonymous_user_form_submit($form , $form_state) {
  $date_from = $form_state['values']['date_from'];
  $date_to = $form_state['values']['date_to'];
  $path = "itg-registered-vs-anonymous-user-content-visited-report";
  $options = array(
    'query' => array(
      'date_from' => strtotime($date_from) ,
      'date_to' => strtotime($date_to) ,
    ) ,
  );
  drupal_goto($path , $options);
}

/**
 * Function which print the chart
 * @return html
 */
function print_registered_vs_anonymous_chart() {
  $start_date = 0;
  $end_date = time();
  if (!empty($_GET['date_from'])) {
    $start_date = strtotime('-1day' , $_GET['date_from']);
  }
  if (!empty($_GET['date_to'])) {
    $end_date = strtotime('+1day' , $_GET['date_to']);
  }
  $chart = get_registered_vs_anonymous_user_node_visit_count($start_date , $end_date);
  $user_data = "<ul>"
      . "<li>Total Count : " . $chart['total_count'] . "</li>"
      . "<li>Registred Users count : " . $chart['registred'] . "</li>"
      . "<li>Anonymous Users count : " . $chart['anonymous'] . "</li>"
      . "</ul>";
  return $user_data . '<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
      google.charts.load(\'current\', {\'packages\':[\'corechart\']});
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {

        var data = google.visualization.arrayToDataTable([
          [\'User type\', \'Count\'],
          [\'Registred\',' . $chart['registred'] . ' ],
          [\'Anonymous\',' . $chart['anonymous'] . '],
        ]);

        var options = {
          title: \'Registered Vs Anonymous User Content Visited Chart\'
        };

        var chart = new google.visualization.PieChart(document.getElementById(\'piechart\'));

        chart.draw(data, options);
      }
    </script>
    <div id="piechart" style="width: 900px; height: 500px;"></div>
  ';
}

/**
 * Function which calculate the registered and anonymous count for report.
 * @param int $start_date
 * @param int $end_date
 * @return array
 */
function get_registered_vs_anonymous_user_node_visit_count($start_date = 0 , $end_date = REQUEST_TIME) {
  $final_data_array_count = array();
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $collection = $conn->pagedetails;
      $condition = array(
        'uid' => array(
          '$eq' => 0 ,
        ) ,
        'viewtime' => array(
          '$gte' => $start_date ,
          '$lte' => $end_date ,
        ) ,
      );
      $anonymous_user_count = $collection->find($condition)->count();

      $condition_2 = array(
        'uid' => array(
          '$ne' => 0 ,
        ) ,
        'viewtime' => array(
          '$gte' => $start_date ,
          '$lte' => $end_date ,
        ) ,
      );
      $registered_user_count = $collection->find($condition_2)->count();

      //Handel case for terms.

      $collection_term = $conn->term_view_info;
      // Calculate for anyonomus users.
      $condition_term = array(
        'viewtime' => array(
          '$gte' => $start_date ,
          '$lte' => $end_date ,
        ) ,
        'role' => "Front User",
      );
      $term_view_count_reg = $collection_term->find($condition_term)->count();
      // Calculate for registred users.
      $condition_term_ann = array(
        'viewtime' => array(
          '$gte' => $start_date ,
          '$lte' => $end_date ,
        ) ,
        'role' => 'Anonymous User',
      );
      $term_view_count_ann = $collection_term->find($condition_term_ann)->count();
      $only_registred_count = $registered_user_count + $term_view_count_reg;
      $only_ann_count = $anonymous_user_count + $term_view_count_ann;
      $final_data_array_count = array(
        'registred' => $only_registred_count ,
        'anonymous' => $only_ann_count ,
        'total_count' => $only_registred_count + $only_ann_count ,
      );
      return $final_data_array_count;
    }
  }
}
