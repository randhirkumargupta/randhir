







<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Chart</title>
    <link rel="stylesheet" type="text/css" href="css/chart.css" />
        <script type="text/javascript" src="http://www.google.com/jsapi"></script>
        
        <script type="text/javascript">
            google.load('visualization', '1.1', {'packages':['corechart']});
			google.load("jqueryui", "1.8.4");
        </script>
</head>

<body>

	 <div class="chart-frame">
        <div id="chart_div" class="chart_div"></div>
         <div class="total">Total respondents: 0</div>
        <ul>
            <li class="overall"><a href="sex-chart.jsp?id=0">Overall</a></li>
            <li class="male selected"><a href="sex-chart.jsp?id=0">Male</a></li>
            <li class="female"><a href="sex-chart.jsp?id=0">Female</a></li>
        </ul>
    </div>

	
	<!-- <div id="chart_div" style="width: 250px; height:250px;"></div> -->

<script>
//Initializes Google Chart Values and Generates Initial Chart
function drawChart() { 
		var data = new google.visualization.DataTable();
		data.addColumn("string", "Topping");
		data.addColumn("number", "Slices");
    	data.addRows(0);


		  var options = {  
		  		title: "",
                titleTextStyle: {color: "#000000", fontName: "arial", fontSize: 14},
                is3D: true,
                backgroundColor: '#fff0f0'
				};
		
		
        wrapper = new google.visualization.ChartWrapper( { chartType: 'PieChart', containerId: 'chart_div' , options: options } );
        wrapper.setDataTable(data);
        google.visualization.events.addListener(wrapper, 'ready', readyHandler);
		ready = false;
        wrapper.draw();
      }
      
function readyHandler() {
	ready = true;
}

google.setOnLoadCallback(drawChart);

</script>

<!-- Begin comScore Tag -->
<script >
  var _comscore = _comscore || [];
  _comscore.push({ c1: "2", c2: "8549097" });
  (function() {
    var s = document.createElement("script"), el = document.getElementsByTagName("script")[0];
    s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
    el.parentNode.insertBefore(s, el);
  })();
</script>
<noscript>
  <img src="http://b.scorecardresearch.com/p?c1=2&c2=8549097&cv=2.0&cj=1" />
</noscript>
<!-- End comScore Tag -->


<script type="text/javascript" >
	var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
	document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
	</script>
	<script type="text/javascript">
	try {
	var pageTracker = _gat._getTracker("UA-795349-17");
	pageTracker._trackPageview();
	pageTracker._trackPageLoadTime();
	} catch(err) {}</script>


</body>
</html>
 