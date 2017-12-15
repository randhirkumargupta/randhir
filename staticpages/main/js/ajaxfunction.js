var afSiteURL = "http://indiatoday.intoday.in/education/";
//var afSiteURL = "http://localhost:8080/etoday/";
function trim(field) {
	while(field.charAt(field.length-1)==" ") {
			field=field.substring(0,field.length-1);
	}
	while(field.charAt(0)==" ") {
		field=field.substring(1,field.length);
	}
	return field;
}

function handleHttpResponse2()
{
	if (http2.readyState == 4)
	{
		var results = http2.responseText;
		var contentArray = results.split('~'); 
		var categoryid = (contentArray[0]);
		var content=(contentArray[1]);
		//alert(categoryid + " ----- "+ content);
		if (http2.status == 200) {
			document.getElementById(categoryid).innerHTML = content;
			//runScripts(document.getElementById(categoryid));
		} else {                 
			//alert('There was a problem retrieving the data');
		} 
	}
}
function getHTTPObject()
{
	var xmlhttp;
	if(window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
	} else if (window.ActiveXObject) {
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		if (!xmlhttp) {
			xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
	}
	return xmlhttp;
}

var http2 = getHTTPObject();
function ajaxContentFetchPYC(categoryId, contentCountToFetch, contentToAvoid)
{ 
	url=afSiteURL+"planyourcareer_chunk_ajaxpart.jsp?categoryId="+categoryId+"&contentCountToFetch="+contentCountToFetch+"&contentToAvoid="+contentToAvoid;
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
}
function ajaxContentFetchEED(categoryId, contentCountToFetch, contentToAvoid)
{ 
	url=afSiteURL+"entranceexamdates_chunk_ajaxpart.jsp?categoryId="+categoryId+"&contentCountToFetch="+contentCountToFetch+"&contentToAvoid="+contentToAvoid;
	//alert(url);
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
}
