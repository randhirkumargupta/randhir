<?php

/**
 * Main function to render chart.
 * @return string
 */
function itg_registered_vs_anonymous_user_form() {
  $form = array();
  $form['chart'] = array(
    '#markup' => print_registered_vs_anonymous_chart() ,
  );
  return $form;
}

/**
 * Function which print the chart
 * @return html
 */
function print_registered_vs_anonymous_chart() {
  $chart = get_registered_vs_anonymous_user_node_visit_count();
  return '<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
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
          title: \'Registered Vs Anonymous user content visited chart\'
        };

        var chart = new google.visualization.PieChart(document.getElementById(\'piechart\'));

        chart.draw(data, options);
      }
    </script>
    <div id="piechart" style="width: 900px; height: 500px;"></div>
  ';
}

/**
 * Function which calculate the registered and anonymous.
 * @return array
 */
function get_registered_vs_anonymous_user_node_visit_count() {
  $final_data_array_count = array();
  if (function_exists('mongodb')) {
    $conn = mongodb();
    if ($conn) {
      $collection = $conn->pagedetails;
      $condition = array(
        'uid' => array(
          '$eq' => 0 ,
        )
      );
      $anonymous_user_count = $collection->find($condition)->count();

      $condition_2 = array(
        'uid' => array(
          '$ne' => 0 ,
        )
      );
      $registered_user_count = $collection->find($condition_2)->count();

      $final_data_array_count = array(
        'registred' => $registered_user_count ,
        'anonymous' => $anonymous_user_count ,
      );
      return $final_data_array_count;
    }
  }
}
