/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */





function  getStateMapDetails(mapurls,ncID)
{
var stateURL = mapurls.mapjson;

var s = stateURL.split(/[\s/]+/);
s=s[s.length-1];
s= s.replace(/.json/g,'')
var jsonpCallBackVal = s.replace(/-/g,"");
var sID,totalSeats;
var url_color=mapurls.color_url;

var conurl = url_color.substring(0, url_color.lastIndexOf("/") + 1)






jQuery.ajax({type: "GET",url: stateURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+jsonpCallBackVal+'2014',success: function (data)
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
   if(pArray.length > '0'){}
	    var cID="";var f=0;
		for(var i = 1;i<=totalSeats;i++)
		{
			if(i < 10){cID=i;}else{cID=i;}
			//alert(cID);
			if(cID != ncID)
			{
			  getJSONFeedColorDetails(conurl,cID);
			}
			if(ncID != 0)
			{
				//alert(ncID+"--"+cID);
				if(ncID == cID)
				{getJSONFeedDetailsOnLoad(conurl,ncID);
                                    f=1;}
				else
				{f=2;}
			}
		}
     //alert()
	//	if(f==1){getJSONFeedDetailsOnLoad(ncID);}
	//	if(f==2){alert("Wrong constituency");}
	},error: function (e, ts, et) { alert(ts + e + et) }});
}


function getconssvg(mapurls,cid)
{
   
var statemapurl = mapurls.svgurl;
var mapurl=mapurls.mapjson;

var s = mapurl.split(/[\s/]+/);
s=s[s.length-1];
s= s.replace(/.json/g,'')


jQuery.ajax({type: "GET",url: statemapurl,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+s.replace(/-/g,'')+'map',success: function (data)
 {

   jQuery("#conssvg").html(data.loksabha.htm);
   var consID = cid;
	if(consID.length == 4){consID = "0"+consID;}
	
	 getStateMapDetails(mapurls,consID);

 }
});
}



function getJSONFeedColorDetails(conurl,consID)
{
   
var feedURL = conurl+"/"+consID+".json";


jQuery.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,jsonp: false,success: function (data)
	{
   //   $("#cons"+consID).attr("fill",data.loksabha.colorCode);
	//  $("#cons"+consID).attr('onclick',"getJSONFeedDetails('"+consID+"')");
 
	  jQuery("[id^='cons"+consID+"']").attr("fill",data.loksabha.colorCode);
	  jQuery("[id^='cons"+consID+"']").attr('onclick',"getJSONFeedDetails('"+conurl+"','"+consID+"')");
//	  if(UtilityHasTouch()==false)
//		 {
	  jQuery("[id^='cons"+consID+"']").attr('pvalue',data.loksabha.cName);
		// }
	},
            error: function (e, ts, et)
		{ 
//		console.log(ts + e + et + consID);
			}
     });
}

function getJSONFeedDetailsOnLoad(conurl,consID)
{
  
var feedURL = conurl+"/"+consID+".json";

jQuery.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,success: function (data)
	{

    $("#cons"+consID).attr("fill",data.loksabha.colorCode);
    $("#cons"+consID).attr('onclick',"getJSONFeedDetails('"+conurl+"','"+consID+"')");

	var tr;
  tr = "<tr><td colspan = '4' style='position:relative'><div class='p_head'>"+data.loksabha.cName+"</div><div style='position: absolute;right:0px;top: 0px;'><img src='http://media2.intoday.in/indiatoday/election2014/live-poll/close.gif' style = 'cursor:pointer;' onclick = 'tabclose();' alt='' /></div></td></tr>";
	var itemsArray = data.loksabha.items; 
	  for(var i = 0;i<itemsArray.length;i++)
	  {
	     tr += "<tr><td><div class='p_cname'><img width='60' height='60' style='float:left; margin-right:5px;' src = '"+itemsArray[i].candImage+"' alt='' />"+itemsArray[i].candName+" <div class='p_pname'>Party: "+itemsArray[i].pName+"</div></div></td></tr>";   

	   	   var candProfileURL;
       if(document.domain == "aajtak.intoday.in")
	   {
		   candProfileURL = itemsArray[i].candProfile.replace("election.intoday.in",'aajtak.intoday.in');
	   }
	   else
	   {
   		   candProfileURL = itemsArray[i].candProfile;
	   }


	   tr += "<tr><td><div class='p_status'>Result: "+itemsArray[i].Status+"</div><div class='p_pname2'><a href = '"+candProfileURL+"' target = '_blank'>View Complete Profile</a></div></td></tr>";
	  }
      jQuery("#consTable").html("<table border = '1' cellspacing='0' cellpadding='0' style='width: 220px;'>"+tr+"</table>");
    },
            error: function (e, ts, et) { alert(ts + e + et) }
     });
}
function getJSONFeedDetails(conurl,consID)
{
  jQuery('.map-result-detail').show();
var feedURL = conurl+"/"+consID+".json";


jQuery.ajax({type: "GET",url: feedURL,dataType: "jsonp", cache: "true",crossDomain: true,jsonpCallback: 'e'+consID,success: function (data)
	{

	var tr;
  tr = "<tr><td colspan = '4' style='position:relative'><div class='p_head'>"+data.loksabha.cName+"</div><div style='position: absolute;right:0px;top: 0px;'><img src='http://media2.intoday.in/indiatoday/election_delhi_2015/live-poll/close.gif' style = 'cursor:pointer;' onclick = 'tabclose();' alt='' /></div></td></tr>";
	var itemsArray = data.loksabha.items; 
	  for(var i = 0;i<itemsArray.length;i++)
	  {
	   tr += "<tr><td><div class='p_cname'><img width='60' height='60' style='float:left; margin-right:5px;' src = '"+itemsArray[i].candImage+"' alt='' />"+itemsArray[i].candName+" <div class='p_pname'>Party: "+itemsArray[i].pName+"</div><div class='p_status'>Result: "+itemsArray[i].Status+"</div></div></td></tr>";  

	   var candProfileURL;
       if(document.domain == "aajtak.intoday.in")
	   {
		   candProfileURL = itemsArray[i].candProfile.replace("election.intoday.in",'aajtak.intoday.in');
	   }
	   else
	   {
   		   candProfileURL = itemsArray[i].candProfile;
	   }
	if(candProfileURL.length > '0')	  
	  tr += "<tr><td><div class='p_pname2'><a href = '"+candProfileURL+"' target = '_blank'>View Complete Profile</a></div></td></tr>";
	  
	  }
      jQuery("#consTable").html("<table  border = '0' cellspacing='0' cellpadding='0' style='width:220px;'>"+tr+"</table>").show();
ga('send', 'event', 'IT-election-delhi-map', 'click',"versedelhiconstuencymap", consID, {'nonInteraction': 1});
    },
            error: function (e, ts, et) { alert(ts + e + et) }
     });
}

function tabclose()
{
     jQuery('.map-result-detail').hide();
   
}