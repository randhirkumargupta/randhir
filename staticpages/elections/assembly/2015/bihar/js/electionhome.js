var domain = "https://smedia2.intoday.in/";
var fpath = "/elections/js/";

//var domain = "http://ittemp.intoday.in";
//var fpath = "/elections/feeds/2014/js/";
function getHomeAlliance(a)
{

var fdata =  "";
var aURL = domain+fpath+"alliance/"+a+"-alliance.json";
$.ajax({type: "GET",url: aURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+a+'2014',success: function (data)
	{
		var aName = data.loksabha.aName;
		var aSeats = data.loksabha.aSeats;

		fdata = '<h3>'+aName+' ('+aSeats+')</h3><div id="piealliancehomecontainer_'+a+'" style="min-width: 250px; max-width: 300px; margin: 0 auto"></div><div class="high-container"><table width="90%" border="0" cellspacing="0" cellpadding="8" id="schedule" class="schedule"><tbody><tr><th>PARTIES</th><th>LEAD</th><th align="center">WON</th><th align="center">TOTAL</th></tr>';
		  var combined = []; var colorArray=[];
		for(var x = 0;x < data.loksabha.items.length; x++)
		 {

		fdata += '<tr style="border-left:5px solid '+data.loksabha.items[x].pColor+'; display:block;"><td class="lft">'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';

			combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))]);

			colorArray[x]=data.loksabha.items[x].pColor;
			
		 }
		
		fdata += '</tbody></table></div>';
		$("#f"+a).html(fdata);

		pie(a,colorArray,combined);
	}
	});

}

function pie(a,colorArray,combined)
{
	
$('#piealliancehomecontainer_'+a).highcharts({
				colors:colorArray,
				chart: {
					//height:187,
					//spacing:[0,0,0,0],
					plotBackgroundColor: null,
					plotBorderWidth: 0,
					plotShadow: false
				},
				title: {
					text: '',
					align: 'center',
					verticalAlign: 'middle',
					y: 15
				},
				tooltip: {
					
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
						center: ['45%', '40%']
					}
				},
				series: [{
					type: 'pie',
					name: '',
					innerSize: '60%',
					data:combined
				}]
			});
}

function hmelectioninner()
{
 var stateURL = domain+fpath+"fullhousemapdetails.json";
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfhd',success: function (data1)
 {
	 $("#fhs").html(data1.loksabha.htm);
 }});
setTimeout("hmelectioninner()",35000);
}

function hmelection1()
{
	
var feedURL = domain+fpath+"svg/fullhousemap.json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfh',success: function (data)
{
	$("#hmelect").html(data.loksabha.htm);
	hmelectioninner();
}
});
}

function abox()
{

var feedURL = domain+fpath+"alliancebox.json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'eab',success: function (data)
{
	$("#abox").html(data.loksabha.htm);
	aboxinner();
}
});
}
function aboxinner()
{
var feedURL = domain+fpath+"aboxinner.json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'eabinnerdata',success: function (data)
{
	$("#aboxres").html(data.loksabha.htm);
}
});

setTimeout("aboxinner()",25000);
}