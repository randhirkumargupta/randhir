var domain = "https://smedia2.intoday.in/";
var fpath = "/elections/js/";
//console.log(document.domain);

function UtilityHasTouch() {    
    var agent   = navigator.userAgent;
    if ( agent.match(/(iPhone|iPod|iPad|Blackberry|Android)/) ) {
        return true;
    }
	else
	{return false;}

}

function getAlliancePartyDetails(a)
{
var aURL = domain+fpath+"alliance/"+a+"-alliance.json";
$.ajax({type: "GET",url: aURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+a+'2014',success: function (data)
{
	var tARow= '<tbody><tr style="height:50px;background-color:#f2f2f2;"><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>';

	var aName = data.loksabha.aName;
	var aNameOthers = "Others";
	var aSeats = data.loksabha.aSeats;
	var aSeatOthers = data.loksabha.aSeatOthers;
	var aColor = data.loksabha.aColor;
	var aColorOthers = data.loksabha.aColorOthers;
    
	loadPieAllianceBigContainer(aName,aNameOthers,aSeats,aSeatOthers,aColor,aColorOthers);

 for(var x = 0;x < data.loksabha.items.length; x++)
 {
	 if(x%2==0)
	 {
     tARow += '<tr style="background-color:#ffffff;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';

	 }else{
     tARow += '<tr style="background-color:#f2f2f2;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';

	 }
 }
 $("#allianceTable").html(tARow+"</tbody>");
}
});

}

function  getFullMapDetails()
 {
	 var stateURL = domain+fpath+"india-map.json";
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'eindia2014',success: function (data)
 {
	for(var x = 0;x < data.loksabha.items.length; x++)
     {
	 $("[id^='cons"+data.loksabha.items[x].sNo+"']").attr("fill",data.loksabha.items[x].pColor);
	 if(UtilityHasTouch()==false)
		 {
	 $("[id^='cons"+data.loksabha.items[x].sNo+"']").attr('pvalue',data.loksabha.items[x].cName+"("+data.loksabha.items[x].sName+")");
		 }
	 $("[id^='cons"+data.loksabha.items[x].sNo+"']").attr('onclick',"getMapConsDetails('"+data.loksabha.items[x].sName+"','"+data.loksabha.items[x].cName+"','"+data.loksabha.items[x].sNo+"')");
     }
  }
});

setTimeout("getFullMapDetails()",120000);
 }

 function getMapConsDetails(s,c,i)
 {
	 if(s!='' && c!= '' && i != '')
	 {
	 s = s.replace(/ /g, '-');
	 c = c.replace(/ /g, '-');
	 //location.href = "/elections/cons_maps_loksabha2.jsp?cname="+s.toLowerCase()+"&consid="+i+"&consname="+c.toLowerCase();
	 location.href = "/elections/2014/state/"+s.toLowerCase()+"/"+i+"/"+c.toLowerCase()+".html";
	 }
 }
function getIndiaStateMapDetails(sName)
{
var stateURL = domain+fpath+"state/"+sName+".json";
var jsonpCallBackVal = sName.replace(/-/g,"");
var sID,totalSeats;
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+jsonpCallBackVal+'2014',success: function (data)
 {
	sID = data.loksabha.sID;
	totalSeats = data.loksabha.totalSeats;
	var cID="";var f=0;
		for(var i = 1;i<=totalSeats;i++)
		{
			if(i <10)
				{
				 cID=sID+"50"+i;
				}
				else
				{
					cID=sID+"5"+i;
				}
			getJSONFeedColorDetails(cID);
         }
  }
});
}
function  getStateMapDetails(sName,ncID)
{
var stateURL = domain+fpath+"state/"+sName+".json";
var jsonpCallBackVal = sName.replace(/-/g,"");
var sID,totalSeats;
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+jsonpCallBackVal+'2014',success: function (data)
{
	sID = data.loksabha.sID;
	totalSeats = data.loksabha.totalSeats;

	var pArray=new Array(),sArray = new Array(),cArray = new Array();
	for(var x = 0;x < data.loksabha.items.length; x++)
	{
		pArray[x]=data.loksabha.items[x].pName;
		sArray[x]=data.loksabha.items[x].pSeats;
		cArray[x]=data.loksabha.items[x].pColor;
	}
   if(pArray.length > '0'){loadPieChart(pArray,sArray,cArray,totalSeats);loadStateTable(pArray,sArray,cArray);}
	    var cID="";var f=0;
		for(var i = 1;i<=totalSeats;i++)
		{
			if(i < 10){cID=sID+"50"+i;}else{cID=sID+"5"+i;}
			if(cID != ncID)
			{
			  getJSONFeedColorDetails(cID);
			}
			if(ncID != 0)
			{
				//alert(ncID+"--"+cID);
				if(ncID == cID)
				{getJSONFeedDetailsOnLoad(ncID);f=1;}
				else
				{f=2;}
			}
		}
     //alert()
	//	if(f==1){getJSONFeedDetailsOnLoad(ncID);}
	//	if(f==2){alert("Wrong constituency");}
	},error: function (e, ts, et) { alert(ts + e + et) }});
}

function loadStateTable(pArray,sArray,cArray)
{
	var tRow = '';
	for(var i = 0;i < pArray.length;i++)
	{
		tRow += '<tr><td style="background-color:'+cArray[i]+';color:#fff">'+pArray[i]+'</td><td style="background-color:#eeeeee;"><span>'+sArray[i]+'</span></td></tr>';
	}
	$("#tRow").html(tRow);
}

function loadPieAllianceBigContainer(a1,a2,s1,s2,c1,c2)
{
	//alert(a1+"--"+a2+"-"+s1+"-"+s2+"-"+c1+"-"+c2);
  var combined = []; var colorArray=[];
  combined.push([a1,parseInt(s1)]);
  combined.push(["",parseInt(s2)]);
  console.log(combined);

  colorArray[0]=c1;
  colorArray[1]=c2;

	//$(function () {
    $('#pieAllianceBigContainer').highcharts({
		colors:colorArray,
        chart: {
            plotBackgroundColor: null,
            plotBorderWidth: 0,
            plotShadow: false
        },
        title: {
            text: a1+' ('+s1+')',
            align: 'center',
            verticalAlign: 'middle',
            y: 15
        },
        tooltip: {
				enabled: false,
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

function loadPieAllianceSmallContainer(a)
{
var aURL = domain+fpath+"alliance/"+a+"-alliance.json";
//alert(aURL);
$.ajax({type: "GET",url: aURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+a+'2014',success: function (data)
{

	  var combined = []; 
	  var colorArray=[];
	var aName = data.loksabha.aName;
	var aSeats = data.loksabha.aSeats;
	for(var x = 0;x < data.loksabha.items.length; x++)
	 {
	  colorArray[x]=data.loksabha.items[x].pColor;
	  combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))])
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
            text: aName+' ('+aSeats+')',
            align: 'center',
            verticalAlign: 'middle',
            y: 15
        },
        tooltip: {
				enabled: true,
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

});


}


function loadPieChart(pArray,sArray,cArray,totalSeats)
{
	var totalASeats = "0";
var combined = [],length = Math.min(pArray.length,sArray.length);
for(var i = 0; i < length; i++) {combined.push([pArray[i], parseInt(sArray[i])]);
 totalASeats = parseInt(totalASeats) + parseInt(sArray[i]);
}
	
//$(function () {
    $('#pieStateContainer').highcharts({
		colors: cArray,
        chart: {
            plotBackgroundColor: null,
            plotBorderWidth: 0,
            plotShadow: false
        },
        title: {
            text: 'Total <br/>'+totalASeats+'/'+totalSeats,style: {fontSize: '28px', color: '#007cee', fontweight: 'bolder'}/*,
			align: 'center',
            verticalAlign: 'middle',
            y: -95,
            style: {fontSize: '10px'}*/
        },
        tooltip: {
    	    pointFormat: '{series.name}: <b>{point.y}</b>'
        },
        plotOptions: {
            pie: {
                allowPointSelect: true,
                cursor: 'pointer',
                dataLabels: {
                 enabled: false
                }
            }
        },
        
        series: [{
            type: 'pie',
            name: 'Seats',
			data: combined
        }]
    });
//});
    
}

function getJSONFeedColorDetails(consID)
{
var feedURL = domain+fpath+"cons/"+consID+".json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,jsonp: false,success: function (data)
	{
   //   $("#cons"+consID).attr("fill",data.loksabha.colorCode);
	//  $("#cons"+consID).attr('onclick',"getJSONFeedDetails('"+consID+"')");
      
	  $("[id^='cons"+consID+"']").attr("fill",data.loksabha.colorCode);
	  $("[id^='cons"+consID+"']").attr('onclick',"getJSONFeedDetails('"+consID+"')");
	  if(UtilityHasTouch()==false)
		 {
	  $("[id^='cons"+consID+"']").attr('pvalue',data.loksabha.cName);
		 }
	},
            error: function (e, ts, et)
		{ 
		console.log(ts + e + et + consID)
			}
     });
}
function tabclose()
{$("#consTable").hide();
	}

function getJSONFeedDetails(consID)
{
var feedURL = domain+fpath+"cons/"+consID+".json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,success: function (data)
	{

	var tr;
    tr = "<tr><td colspan = '4' align = 'left'><div class='p_head'>"+data.loksabha.cName+"</div><div style='position: absolute;right: -8px;top: -11px;'><img src='http://media2.intoday.in/indiatoday/election2014/live-poll/close.png' style = 'cursor:pointer;' onclick = 'tabclose();'/></div></td></tr>";
  
	var itemsArray = data.loksabha.items; 
	  for(var i = 0;i<itemsArray.length;i++)
	  {
	   tr += "<tr><td><div class='p_cname'><img width='40' height='40' style='float:left; margin-right:5px;' src = '"+itemsArray[i].candImage+"' />"+itemsArray[i].candName+"</div></td></tr>";
	   tr += "<tr><td><div class='p_pname'>Party: "+itemsArray[i].pName+"</div></td></tr>";

	   var candProfileURL;
       if(document.domain == "aajtak.intoday.in")
	   {
		   candProfileURL = itemsArray[i].candProfile.replace("election.intoday.in",'aajtak.intoday.in');
	   }
	   else
	   {
   		   candProfileURL = itemsArray[i].candProfile;
	   }
	   tr += "<tr><td><div class='p_status'>Result: "+itemsArray[i].Status+"</div><div class='p_pname' style='width:240px; float:left;'><a style='color:#fff; text-decoration:underline' href = '"+candProfileURL+"' target = '_blank'>View Complete Profile</a></div></td></tr>";
	  
	  }
      $("#consTable").html("<table  border = '0' cellspacing='0' cellpadding='0'>"+tr+"</table>").show();
    },
            error: function (e, ts, et) { alert(ts + e + et) }
     });
}

function getJSONFeedDetailsOnLoad(consID)
{
var feedURL = domain+fpath+"cons/"+consID+".json";
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,success: function (data)
	{

    $("#cons"+consID).attr("fill",data.loksabha.colorCode);
    $("#cons"+consID).attr('onclick',"getJSONFeedDetails('"+consID+"')");

	var tr;
    tr = "<tr><td colspan = '4'><div class='p_head'>"+data.loksabha.cName+"</div><div style='position: absolute;right: -8px;top: -11px;'><img src='http://media2.intoday.in/indiatoday/election2014/live-poll/close.png' style = 'cursor:pointer;' onclick = 'tabclose();'/></div></td></tr>";
  
	var itemsArray = data.loksabha.items; 
	  for(var i = 0;i<itemsArray.length;i++)
	  {
	     tr += "<tr><td><div class='p_cname'><img width='40' height='40' style='float:left; margin-right:5px;' src = '"+itemsArray[i].candImage+"' />"+itemsArray[i].candName+"</div></td></tr>";
	   tr += "<tr><td><div class='p_pname'>Party: "+itemsArray[i].pName+"</div></td></tr>";

	   	   var candProfileURL;
       if(document.domain == "aajtak.intoday.in")
	   {
		   candProfileURL = itemsArray[i].candProfile.replace("election.intoday.in",'aajtak.intoday.in');
	   }
	   else
	   {
   		   candProfileURL = itemsArray[i].candProfile;
	   }


	   tr += "<tr><td><div class='p_status'>Result: "+itemsArray[i].Status+"</div><div class='p_pname' style='width:240px; float:left;'><a style='color:#fff; text-decoration:underline' href = '"+candProfileURL+"' target = '_blank'>View Complete Profile</a></div></td></tr>";
	  }
      $("#consTable").html("<table border = '1' cellspacing='0' cellpadding='0'>"+tr+"</table>");
    },
            error: function (e, ts, et) { alert(ts + e + et) }
     });
}

function getFullHouseDetails()
{
var stateURL = domain+fpath+"fullhouse.json";

$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'efullhouse2014',success: function (data)
 {
	var p,t,c;
	p = data.loksabha.items[0].pName;
	t = data.loksabha.items[0].totalSeats;
	c = data.loksabha.items[0].cCode;
	for(var j1 = 1; j1 <= t; j1++)
	{
		$("#p"+j1).attr("fill",c);
	}

	p = data.loksabha.items[1].pName;
	t = data.loksabha.items[1].totalSeats;
	c = data.loksabha.items[1].cCode;
	for(var j2 = j1; j2 <= (parseInt(t) + parseInt(j1) -1); j2++)
	{
		$("#p"+j2).attr("fill",c);
		//console.log(j2+"--"+p+"--"+c);
	}
	p = data.loksabha.items[2].pName;
	t = data.loksabha.items[2].totalSeats;
	c = data.loksabha.items[2].cCode;
	for(var j3 = j2; j3 <= (parseInt(t) + parseInt(j2) -1); j3++)
	{
		$("#p"+j3).attr("fill",c);
		//console.log(j3+"--"+p+"--"+c);
	}

  }
});
}
function getconssvg(s,cid)
{
var statemapurl = domain+fpath+"svg/"+s+"-loksabha.json";
$.ajax({type: "GET",url: statemapurl,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+s.replace(/-/g,'')+'map',success: function (data)
 {
   $("#conssvg").html(data.loksabha.htm);
   var consID = cid;
	if(consID.length == 4){consID = "0"+consID;}
	 getStateMapDetails(s,consID);

 }
});
}



function getindia()
{
var url = domain+fpath+"svg/india-loksabha.json";
$.ajax({type: "GET",url: url,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'eindiamap',success: function (data)
 {
   $("#indiamap").html(data.loksabha.htm);
   getFullMapDetails();
 }
});
}


function getPartyWiseDetails(p)
 {

var aURL = domain+fpath+"party/"+p+".json";
//alert(aURL)
$.ajax({type: "GET",url: aURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+p+'2014',success: function (data)
{
	var tARow= '<tbody><tr style="height:50px;background-color:#f2f2f2;"><th>STATE</th><th>CONSTITUENCY</th><th>CANDIDATE</th><th>RESULT</th></tr>';
//alert(data.loksabha.items.length);
 for(var x = 0;x < data.loksabha.items.length; x++)
 {
	 if(x%2==0)
	 {
     tARow += '<tr style="background-color:#ffffff;"><td>'+data.loksabha.items[x].sName+'</td><td>'+data.loksabha.items[x].cName+'</td><td>'+data.loksabha.items[x].candName+'</td><td>'+data.loksabha.items[x].Status+'</td></tr>';

	 }else{
     tARow += '<tr style="background-color:#f2f2f2;"><td>'+data.loksabha.items[x].sName+'</td><td>'+data.loksabha.items[x].cName+'</td><td>'+data.loksabha.items[x].candName+'</td><td>'+data.loksabha.items[x].Status+'</td></tr>';

	 }
 }
 $("#partyTable").html(tARow+"</tbody>");
}
});

 }

 


function hmelection2009()
{
	
var feedURL = domain+fpath+"svg/fullhousemap2009.json";
//alert(feedURL);
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfh2009',success: function (data)
{
	//alert(data);
	$("#hmelect2009").html(data.loksabha.htm);
	hmelectioninner2009();
}
});
}
function hmelectioninner2009()
{
 var stateURL = domain+fpath+"fullhousemapdetails2009.json";
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfhd2009',success: function (data1)
 {
	 $("#fhs2009").html(data1.loksabha.htm);
 }});
//setTimeout("hmelectioninner()",35000);
}

function hmelection2004()
{
	
var feedURL = domain+fpath+"svg/fullhousemap2004.json";
//alert(feedURL);
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfh2004',success: function (data)
{
	//alert(data);
	$("#hmelect2004").html(data.loksabha.htm);
	hmelectioninner2004();
}
});
}
function hmelectioninner2004()
{
 var stateURL = domain+fpath+"fullhousemapdetails2004.json";
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfhd2004',success: function (data1)
 {
	 $("#fhs2004").html(data1.loksabha.htm);
 }});

}

function hmelection2014()
{
	
var feedURL = domain+fpath+"svg/fullhousemap2014.json";
//alert(feedURL);
$.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfh',success: function (data)
{
	//alert(data);
	$("#hmelect").html(data.loksabha.htm);
	
	hmelectioninner2014();
}
});
}
function hmelectioninner2014()
{
 var stateURL = domain+fpath+"fullhousemapdetails.json";
$.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'ehmfhd',success: function (data1)
 {
	 $("#fhs").html(data1.loksabha.htm);
	 $(".newtable").hide();
 }});

 setTimeout("hmelectioninner2014()",35000);

}

function getAlliancePartyDetails1(a)
{
var aURL = domain+fpath+"alliance/"+a+"-alliance.json";
//alert(aURL);
$.ajax({type: "GET",url: aURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+a+'2014',success: function (data)
{
	var tARow= '<tbody><tr style="height:50px;background-color:#f2f2f2;"><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>';

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
     tARow += '<tr style="background-color:#ffffff;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';

	 }else{
     tARow += '<tr style="background-color:#f2f2f2;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';
	 }

  colorArray[x]=data.loksabha.items[x].pColor;
  combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))])

 }

loadPieAllianceBigContainer1(aName,aSeats,aSeatOthers,combined,colorArray);
 $("#allianceTable").html(tARow+"</tbody>");
}
});

setTimeout("getAlliancePartyDetails1()",60000);

}
 function loadPieAllianceBigContainer1(a1,a2,s1,combined,colorArray)
{
    $('#pieAllianceBigContainer').highcharts({
		colors:colorArray,
        chart: {
            plotBackgroundColor: null,
            plotBorderWidth: 0,
            plotShadow: false
        },
        title: {
            text: a1+' ('+a2+')',
            align: 'center',
            verticalAlign: 'middle',
            y: 15
        },
        tooltip: {
				enabled: true,
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
}

$(document).ready(function(e) {
	var myUserAgent = navigator.userAgent.toLowerCase();
	if(myUserAgent.match('ipad')) {
		   $('.subnav, #top-web').css('width', '1003px');
		   $('header').css('background', '#016fa4');
		}
    });