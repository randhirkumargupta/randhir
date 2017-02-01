<?php
print $data;
?>
<br>
<h3>Social Medial Activity </h3>
<?php 

print $facebook_details;
?>
<?php 
   if($is_fb_graph == 1) { 
?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>

<script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);
      function drawChart() {

        var data = google.visualization.arrayToDataTable([
          ['Task', 'Count'],
          <?php echo $fb_graph_details;?>
        ]);

        var options = {
          title: 'Social Medial Activity Graph'
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechart'));

        chart.draw(data, options);
      }
    </script>

 <div id="piechart" style="width: 900px; height: 500px;"></div>
   <?php } ?>
