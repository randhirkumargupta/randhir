<script type="text/javascript">
  google.charts.load('current', {'packages':['corechart']});
          google.charts.setOnLoadCallback(drawChart);
  function drawChart() {

  var data = google.visualization.arrayToDataTable([
  ['<?php echo t("Sections") ?>', '<?php echo t("Visited nodes") ?>'],
    <?php
    foreach ($node_under_section_visited as $section => $count) {
      if(!empty(get_term_name_from_tid_for_report($section))) {
        $total = $count + 1;
        echo '["'.t(get_term_name_from_tid_for_report($section)) .'",'.$total.'],';
      }
    }
    ?>
  ])
  var options = {
    title: '<?php echo t("Section Visits") ?>',
  };
  var chart = new google.visualization.PieChart(document.getElementById('piechart_section'));
    chart.draw(data, options);
  }
</script>
<div id="piechart_section" style="width: 800px; height: 400px;"></div>