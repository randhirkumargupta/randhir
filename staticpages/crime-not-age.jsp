

<script type="text/javascript" async="true">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("UA-795349-17");
pageTracker._trackPageview();
pageTracker._trackPageLoadTime();
} catch(err) {}</script>



<script>

function trim(field)
{
while(field.charAt(field.length-1)==" "){
		field=field.substring(0,field.length-1);
	}
	while(field.charAt(0)==" "){
		field=field.substring(1,field.length);
	}
	return field;
}


function handleHttpResponse2()
{
	var urltoPass = "";
	urltoPass=trim(urltoPass);
	if(urltoPass.length==0){
		urltoPass = url;
	}
	//alert(urltoPass);
	if (http2.readyState == 4)
	{
		var results = http2.responseText;
		var arry = results.split('|'); 
		var upcnt=	(arry[0]);
		var dncnt=(arry[1]);
		var cmnt=(arry[2]);
		if (http2.status == 200) {
			pageTracker._trackPageview(urltoPass); 
			document.getElementById("upcount").innerHTML = upcnt;
			document.getElementById("downcount").innerHTML = dncnt;
			document.getElementById("commenttext").innerHTML = cmnt;
			runScripts(document.getElementById('upcount'));
			runScripts(document.getElementById('downcount'));
			runScripts(document.getElementById('commenttext'));
		} else {                 
			alert('There was a problem retrieving the data');
		} 
	}
}
function getHTTPObject()
{
	var xmlhttp;
	if(window.XMLHttpRequest)
	{
		xmlhttp = new XMLHttpRequest();
	}
		else if (window.ActiveXObject)
	{
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		if (!xmlhttp)
		{
			xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
	}
	return xmlhttp;
}

var http2 = getHTTPObject();
function changeRating(contentId,content_type,action)
{ 
	upc = document.getElementById('upcount').firstChild.nodeValue;
	downc = document.getElementById('downcount').firstChild.nodeValue;
	totalc = upc+downc;
	url="http://indiatoday.intoday.in/rating_data.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&totalcount="+totalc;
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
}
</script>


<div style="clear: both; text-align: center;color: #C30000;   font-size: 50px; margin-bottom:5px;">
	<span style="font-weight: bold; margin-right:5px;">
    
    Do you agree? </span>
    <div style="clear:both"></div>
	<div style="margin:0 auto; text-align:center">
    <span style="margin-right:0px;font: 20px/30px arial;">
    	<a  onClick="javascript:changeRating('0','2109201301','1')">
        <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/yes_crime.png"  border="0" align="absmiddle" style="float:none; margin:0;"/></a>
    	<span id="upcount" style="font-family:arial;font-size:28px;">1 </span>
    </span>
    <span style="margin-left:5px; font: 20px/30px arial;">
    	<a  onClick="javascript:changeRating('0','2109201301','2')">
        <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/no_crime.png"  border="0" align="absmiddle" style="float:none; margin:0 0 0 50px; "/></a>
        <span id="downcount" style="font-family:arial;font-size:28px;">0</span>
    </span>
    </div>
    
    <span id="commenttext" ></span>
    <div class="clear"></div> 
</div> 

