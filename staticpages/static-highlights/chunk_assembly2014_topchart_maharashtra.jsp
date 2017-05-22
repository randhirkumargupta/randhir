



<meta http-equiv="refresh" content="60; URL=http://indiatoday.intoday.in/highlights/chunk_assembly2014_topchart.jsp?page=1&aname=maharashtra">
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
<script src="http://media2.intoday.in/elections/js/highcharts.js"></script>
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css'>
<script>
	var domain = "http://media2.intoday.in/";
	var fpath = "feeds/election/assembly_election_2014/json";
	function loadPieAllianceBigContainer2(a,data)
	{
		var aURL = domain+fpath+"/"+a+"-assembly-alliance.json";
		//alert(aURL);
		if(data!='') 
		{
			var combined = []; 
			var colorArray=[];
			var aName = data.loksabha.aName;
			var aSeats = data.loksabha.aSeats;
			var aSeatOthers = data.loksabha.aSeatOthers;
			for(var x = 0;x < data.loksabha.items.length; x++)
			{
				colorArray[x]=data.loksabha.items[x].pColor;
				combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))]);
			}
			var showtooltip = true;
			if(aSeatOthers==0) {
				$('#resultawaited').show();
				colorArray[x]='#A2A9AD';
				combined.push(['Result Awaited','1']);
				showtooltip = false;
			}
			
			//$(function () {
			$('#pieAllianceSmallContainer_'+a).highcharts({
				colors:colorArray,
				chart: {
					plotBackgroundColor: null,
					plotBorderWidth: 0,
					plotShadow: false
				},
				title: {
					text: aName+' ('+aSeatOthers+'/'+aSeats+')',
					align: 'center',
					verticalAlign: 'middle',
					y: 37
				},
				tooltip: {
						enabled: showtooltip,
					pointFormat: '<b>{point.y}</b>'
				},
				plotOptions: {
					pie: {
						dataLabels: {
							enabled: false,
							distance: -50,
							style: {
								fontWeight: 'bold',
								color: 'white',
								textShadow: '0px 1px 2px black'
							}
						},
						startAngle: -90,
						endAngle: 90,
						center: ['50%', '55%']
					}
				},
				series: [{
					type: 'pie',
					name: '',
					innerSize: '60%',
					data:combined
				}]
			});
		//});
		}
	}


	function getAllianceAssemblyDetails(a)
	{
		var aURL = domain+fpath+"/"+a+"-assembly-alliance.json";
		//alert(aURL);
		$.ajax({type: "GET",cache:true,url: aURL,dataType: "jsonp",crossDomain: true,jsonpCallback: 'e'+a.replace("-","")+'2014',success: function (data)
			{
				var tARow= '<tbody><tr style="height:40px;"><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>';
				
				var combined = []; 
				var colorArray=[];
				var aName = data.loksabha.aName;
				var aNameOthers = "Others";
				var aSeats = data.loksabha.aSeats;
				var aSeatOthers = data.loksabha.aSeatOthers;
				
				for(var x = 0;x < data.loksabha.items.length; x++)
				{
					if(x%2==0)
					{
						tARow += '<tr style="background-color:#ffffff;"><td class="padtext">'+data.loksabha.items[x].pName.replace('JK','')+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr><tr><td class="nobg"></td></tr>';
					
					}else{
						tARow += '<tr style="background-color:#ffffff;"><td class="padtext">'+data.loksabha.items[x].pName.replace('JK','')+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr><tr><td class="nobg"></td></tr>';
					}
					
					colorArray[x]=data.loksabha.items[x].pColor;
					combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))]);
				}
				
				loadPieAllianceBigContainer2(a,data);
				$("#allianceTable_"+a).html(tARow+"</tbody>");
			}
		});
	}
 
</script>
<style>
.highcharts-background { border:1px solid red; height:300px!Important; }
#wrapper { width:300px;}
.schedule2{ margin-top:0;}
table.schedule2 th{ text-align:left; padding:0; font-weight:normal; color:#333333; font-family:roboto}
table.schedule2 td{ padding:0 5px 0 15px; margin-bottom:10px; color:#555; font-family:roboto}
table.schedule2 td.nobg{ background:none; height:10px; font-size:0; line-height:0; font-family:roboto}
.padtext{ padding-left:15px;}

</style>
<div id="wrapper" style="width:310px; margin-top:-70px; position:relative">
    <div style="width:4px; height:154px; position:absolute; border-right:1px dashed #666; top:60px; z-index:9;left: 49%;"></div>
    
    <div id="resultawaited" style="width:154px; height:24px; position:absolute;top:25%; z-index:9;left:36%; display:none;">Result Awaited</div>

	<div id="pieAllianceSmallContainer_maharashtra" style="height: 400px; margin-bottom:-150px;"></div>
		<div style="position:relative">
		
		<!--<div style="position:absolute; left:125px; top:-13px; "><a href="http://indiatoday.intoday.in/story/live-blog-assembly-poll-results/1/396502.html" target="_blank" style="color:#FF0000; font-family:roboto; font-size:14px; font-weight:normal; text-decoration:none">Live Blog</a></div>-->
          	
           <table width="100%" border="0" cellspacing="0" cellpadding="8" class="schedule2" id="allianceTable_maharashtra">
            </table>
        </div>
        
        <div>

 <script type = "text/javascript">getAllianceAssemblyDetails("maharashtra");
 </script>

        </div>
    
    </div>
