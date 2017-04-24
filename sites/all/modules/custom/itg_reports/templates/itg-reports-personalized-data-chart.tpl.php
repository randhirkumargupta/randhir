<script type="text/javascript">
  google.charts.load('current', {'packages':['corechart']});
          google.charts.setOnLoadCallback(drawChart);
  function drawChart() {

  var data = google.visualization.arrayToDataTable([
    ['<?php echo t("Sections") ?>', '<?php echo t("Visited nodes") ?>'],
    <?php
    foreach ($total_section_node_visited as $section => $count) {
      if(!empty(get_term_name_from_tid_for_report($section))) {
        echo '["'.t(get_term_name_from_tid_for_report($section)).'",'.$count.'],';
      }
    }
    ?>
  ]);
  var options = {
    title: '<?php echo t("Personalized Sections") ?>',
  };
  var chart = new google.visualization.PieChart(document.getElementById('piechart_person'));
    chart.draw(data, options);
  }
</script>
<div id="piechart_person" style="width: 800px; height: 400px;"></div>