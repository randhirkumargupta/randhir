var loadstatustext="<img src='/pix/common/loading.gif' /> Requesting content..."


function funcMouseOver( arg )
{	
	document.getElementById(arg).className = 'select';
}

function changeMustWatch( name, arg, total_arg){
	for (var i=1;i <= total_arg;i++){
		if(i == arg ){
			document.getElementById( name+i+"_0").style.display="block";
			document.getElementById( name+i+"_1").style.display="none";
		}
		else{
			document.getElementById( name+i+"_0").style.display="none";
			document.getElementById( name+i+"_1").style.display="block";
		}
	}
}

var arrayList = new Array (  "/tab/", //// Tab 
							"/tab/changeMustWatch", //// Must Watch
							"/tab/changeMustRead", //// Must Read
							"/tab/showbuzz/", //// Showbuzz Review
							"/tab/changeTech", //// Tech Womaon Portal
							"/tab/section/", //// Section Pages india, world etc
							"/tab/business/" //// Section Pages Load, Tax etc

						 ); 	

function changeNavigation ( arg, total_arg, tab_name )
{	
   try 
   {   		
		if ( tab_name == 'most' )	var url = arrayList[ 0 ];
		if ( tab_name == 'mustwatch' )	var url = arrayList[ 1 ];
		if ( tab_name == 'mustread' )	var url = arrayList[ 2 ];
		if ( tab_name == 'showbuzzReview' )	var url = arrayList[ 3 ];
		if ( tab_name == 'techWomanPotal' )	var url = arrayList[ 4 ];
		if ( tab_name == 'nation' || tab_name == 'business' || tab_name == 'world' ||tab_name == 'sci-tech' ||tab_name == 'lifestyle' ||tab_name == 'sports' || tab_name == 'health' || tab_name == 'entertainment' )	var url = arrayList[ 5 ];
		if ( tab_name == 'loan_tax' )	var url = arrayList[ 6 ];
		


		if ( tab_name != 'mustreadMouseOver') 
			http.open("GET", url + arg +"/" +tab_name+".html", true);
		
		//document.write (url + arg +"&tab=" +tab_name);

		if ( tab_name == 'mustwatch' )		 http.onreadystatechange = mustWatchHttpResponse;
		if ( tab_name == 'mustread' )		 http.onreadystatechange = mustReadHttpResponse;	 
		if ( tab_name == 'most' ) 			 http.onreadystatechange = tabNavHttpResponse;	 	 
		if ( tab_name == 'showbuzzReview' )  http.onreadystatechange = showbuzzReviewHttpResponse;	 	 
		if ( tab_name == 'techWomanPotal' )  http.onreadystatechange = techWomanPotalHttpResponse;	 	 			 
		if ( tab_name == 'nation' )	 		 http.onreadystatechange = sectionNationHttpResponse;	 	 			 
		if ( tab_name == 'business')	 	 http.onreadystatechange = sectionBusinessHttpResponse;	 	 			 
		if ( tab_name == 'world' )	 		 http.onreadystatechange = sectionWorldHttpResponse;	 	 			 
		if ( tab_name == 'sci-tech')	 	 http.onreadystatechange = sectionSciTechHttpResponse;	 	 			 
		if ( tab_name == 'lifestyle' )	 	 http.onreadystatechange = sectionLifeStyleHttpResponse;	 	 			 
		if ( tab_name == 'sports')	 		 http.onreadystatechange = sectionSportsHttpResponse;	
		if ( tab_name == 'health')	 		 http.onreadystatechange = sectionHealthHttpResponse;	
		if ( tab_name == 'entertainment')	 	 http.onreadystatechange = sectionEntertainmentHttpResponse;	
 	 			 
		if ( tab_name == 'loan_tax')	 	http.onreadystatechange = sectionLoanTaxHttpResponse;	
	 	
	
	if ( tab_name == 'most' || tab_name == 'showbuzzReview' || tab_name == 'mustreadMouseOver' || tab_name == 'techWomanPotal' || tab_name == 'loan_tax' ) 		
		{	 
			 for ( var i=1; i <= total_arg ; i++ )	 {
				if ( arg == i )
					document.getElementById( tab_name +i).style.display="block";
				else
					document.getElementById( tab_name +i).style.display="none";
			}
		}
		http.send(null);
   }catch(e){}
}

function changeNavigationTab ( arg, total_arg, focusTab, tab_name )
{	
	url = "/tab/mostread/";
	http.open("GET", url + arg +"-" +focusTab+".html", true);
		
	if ( tab_name == 'tabNav' )
	 	 http.onreadystatechange = mostReadCommentedHttpResponse;	 
	 http.send(null);
}

function mostReadCommentedHttpResponse() {
 
  
  if (http.readyState == 4)  {  	
  		var temp = http.responseText.split("**~~**")
		document.getElementById('tab_desc').innerHTML      = temp[0];
		document.getElementById('tab_next_desc').innerHTML = temp[1];
		for ( var i=1; i <= 6 ; i++ )	 
		{
			if ( i == temp[2] )
				document.getElementById("tabNav"+i).className = "active";
			else
				document.getElementById("tabNav"+i).className = "none";		
		}
  }
}


function tabNavHttpResponse() {				


  if (http.readyState == 4)  {  	
	  document.getElementById('tabContainer').innerHTML = http.responseText;
  }
}

function sectionEntertainmentHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('entertainmentContainer').innerHTML = http.responseText;
  }
}


function sectionHealthHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('healthContainer').innerHTML = http.responseText;
  }
}

function sectionLoanTaxHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('loadTaxContainer').innerHTML = http.responseText;
  }
}

function sectionNationHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('nationContainer').innerHTML = http.responseText;
  }
}

function sectionBusinessHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('businessContainer').innerHTML = http.responseText;
	 }
}

function sectionWorldHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('worldContainer').innerHTML = http.responseText;
  }
}

function sectionSciTechHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('sci-techContainer').innerHTML = http.responseText;
  }
}

function sectionLifeStyleHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('lifestyleContainer').innerHTML = http.responseText;
  }
}

function sectionSportsHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('sportsContainer').innerHTML = http.responseText;
  }
}

function techWomanPotalHttpResponse() {			
  if (http.readyState == 4)  {  	
	  document.getElementById('techWomanPotalContainer').innerHTML = http.responseText;
  }
}

function showbuzzReviewHttpResponse() {			
  if (http.readyState == 1)  {  	
  		document.getElementById('showbuzzReviewContainer').innerHTML = loadstatustext;
  }
  if (http.readyState == 4)  {  	
	  document.getElementById('showbuzzReviewContainer').innerHTML = http.responseText;
  }
}

function mustWatchHttpResponse() {

	if (http.readyState == 4)  {  	
		document.getElementById('mustwatchContainer').innerHTML = http.responseText;
  }
}

function mustReadHttpResponse() {

  if (http.readyState == 4)  {  	
		document.getElementById('mustreadContainer').innerHTML = http.responseText;
  }
}

function getHTTPObject() 
{
  var xmlhttp;
  /*@cc_on
  @if (@_jscript_version >= 5)
    try {
      xmlhttp = new ActiveXObject("Msxml2.XMLHTTP");
    } catch (e) {
      try {
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
      } catch (E) {
        xmlhttp = false;
      }
    }
  @else
  xmlhttp = false;
  @end @*/
  if (!xmlhttp && typeof XMLHttpRequest != 'undefined') {
    try {
      xmlhttp = new XMLHttpRequest();
    } catch (e) {
      xmlhttp = false;
    }
  }
  return xmlhttp;
}
var http = getHTTPObject(); // We create the HTTP Object