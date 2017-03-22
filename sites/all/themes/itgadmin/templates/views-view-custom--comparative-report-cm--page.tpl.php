<?php foreach($rows as $index => $row): ?>
	<?php 
       
        $inputdata .= "['".$row['name']."',   ".$row['nid']."],"
        
        
        ?>
<?php endforeach; $inputdata = rtrim($inputdata,','); ?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);
      function drawChart() {

        var data = google.visualization.arrayToDataTable([
          ['Task', 'Count'],
         <?php echo $inputdata;?>
        ]);


        var options = {
          title: 'Comparative Report'
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechart'));
        chart.draw(data, options);
      }
     
    </script>
<div id="piechart" style="width: 900px; height: 500px;"></div>