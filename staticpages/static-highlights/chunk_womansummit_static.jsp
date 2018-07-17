







 <script src="http://www.google-analytics.com/urchin.js" type="text/javascript">

</script>

<script type="text/javascript">

_uacct = "UA-795349-17";

urchinTracker();

</script>

<script type="text/javascript">

var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");

document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));

</script>

<script type="text/javascript">

var pageTracker = _gat._getTracker("UA-795349-48");

pageTracker._trackPageview();

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

<!DOCTYPE HTML>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Woman summit 2013 highlights chunk</title>
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
	var urltoPass = "story/india-today-woman-summit-2013-highlights/1/266490.html#rating";
	urltoPass=trim(urltoPass);
	if(urltoPass.length==0){
		urltoPass = url;
	}
	if (http2.readyState == 4)
	{
		var results = http2.responseText;
		var arry = results.split('|'); 
		var upcnt=	(arry[0]);
		var dncnt=(arry[1]);
		var cmnt=(arry[2]);
		var cid=(arry[3]);
		if (http2.status == 200) {
			pageTracker._trackPageview(urltoPass); 
			document.getElementById("upcount"+cid).innerHTML = upcnt;
			document.getElementById("downcount"+cid).innerHTML = dncnt;
			//document.getElementById("commenttext"+cid).innerHTML = cmnt;
			//runScripts(document.getElementById('upcount'+cid));
			//runScripts(document.getElementById('downcount'+cid));
			//runScripts(document.getElementById('commenttext'+cid));
		} else {                 
			alert('There was a problem retrieving the data');
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
function changeRating1(contentId,content_type,action,part_id, upc, dwnc)
{ 
	upc = document.getElementById('upcount'+part_id).firstChild.nodeValue;
	downc = document.getElementById('downcount'+part_id).firstChild.nodeValue;
	totalc = upc+downc;
	url="http://indiatoday.intoday.in/highlights/rating_data_highlights_ws.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&totalcount="+totalc+"&part_id="+part_id;
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
}
</script>


	<!-- style for demo and examples -->
	<style>
		body{margin:0; padding:0; color:#000;font-family:Verdana,Geneva,sans-serif; font-size:13px; line-height:20px;}
		a:link,a:visited,a:hover{color:inherit;}
		h1{font-family:Georgia,serif; font-size:18px; font-style:italic; margin:40px; color:#26beff;}
		h2{font-family:Georgia,serif; font-size:16px; font-style:italic; color:#eee;}
		
		.content{margin:0; width:200px; height:286px; padding:0 0 10px 0; overflow:auto;border-bottom: 2px solid #E2E2E2;}
		.highlighttxt { font:normal 12px/16px Arial; color:#000;}
		.highlighttxt ul { margin:0; padding:0;}
		.highlighttxt ul li {
    background: url("http://businesstoday.intoday.in/budget/images/bult.png") no-repeat scroll 0 3px transparent;
    color: #000000;
    font: 12px/16px arial;
    list-style: none outside none;
    margin: 0 20px 10px 0;
    padding: 0 0 0 20px;
    float: left;
}
		.highlighttxt ul li span { float:left; width:100%; margin:5px;}
		.thumbup { background:url(http://businesstoday.intoday.in/budget/images/thumbup.png) no-repeat top left; width:10px; height:10px; margin:5px;}
		.thumbdown {background:url(http://businesstoday.intoday.in/budget/images/thumbdown.png) no-repeat top right; width:10px; height:10px; margin:5px;}
		.clear {clear:both}
		.lft { float:left}
		.marglft {padding-left:30px;}
		.strheadline {
    border-bottom: 0px solid #E2E2E2;
    border-top: 0px solid #E2E2E2;
    float: left;
    margin-bottom: 10px;
    width: 100%;
}
.headertext {
    background-image: url("http://businesstoday.intoday.in/images/head-img.gif");
    background-position: left top;
    background-repeat: repeat-x;
    color: #000000;
    float: left;
    font: bold 12px Georgia;
    margin-top: -3px;
    padding: 7px 0 5px;
    text-align: left;
}
	</style>
	<!-- Custom scrollbars CSS -->
	<link href="http://businesstoday.intoday.in/budget/jquery.mCustomScrollbar.css" rel="stylesheet" />
</head>
<body>
<div class="strheadline"><div class="headertext"><a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2013-highlights/1/266490.html" target="_blank" style="font: bold 20px/24px Arial-Black; color: #F57921; text-transform:uppercase; text-decoration:none;">HIGHLIGHTS</a></div></div>
<div class="clear"></div>
	<!-- content block -->
	<div id="content_1" class="content">
		<div class="highlighttxt">
        <ul>
        

<li> Coverage of the India Today Woman Summit and Awards is over. Thank you for being with us.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','196', '7', '17')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount196">7</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','196', '7', '17')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount196">17</span></div></a>
</li>
<li> India Today Most Inspirational Woman Award goes to the Delhi Braveheart.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','195', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount195">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','195', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount195">0</span></div></a>
</li>
<li> India Today Woman Entrepreneur Award goes to Dr Gazalla Amin.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','194', '7', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount194">7</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','194', '7', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount194">2</span></div></a>
</li>
<li> India Today Woman in Arts Award goes to actor Sridevi.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','193', '0', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount193">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','193', '0', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount193">2</span></div></a>
</li>
<li> India Today Woman in Corporate World Award goes to Capgemini India CEO Aruna Jayanthi.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','192', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount192">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','192', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount192">0</span></div></a>
</li>
<li> India Today Woman in Sport Award goes to squash player Dipika Pallikal.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','191', '1', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount191">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','191', '1', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount191">1</span></div></a>
</li>
<li> India Today Woman In Science Award goes to neuro-scientist Shubha Tole.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','190', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount190">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','190', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount190">0</span></div></a>
</li>
<li> India Today Woman In Public Service Award goes to SEWA social worker Renana Jhabvala.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','189', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount189">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','189', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount189">0</span></div></a>
</li>
<li> India Today Woman As Story Teller Award goes to Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','188', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount188">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','188', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount188">0</span></div></a>
</li>
<li>Session Stand Up, Speak Out to ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','187', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount187">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','187', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount187">0</span></div></a>
</li>
<li>Teachers must maintain certain quality standards, says Shashi Tharoor.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','186', '2', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount186">2</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','186', '2', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount186">0</span></div></a>
</li>
<li>I have been defamed numerous times over. Public rebuttal and not suing settles the matter better, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','185', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount185">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','185', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount185">0</span></div></a>
</li>
<li>Not give reservation, give opportunities (to women), says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','184', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount184">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','184', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount184">0</span></div></a>
</li>
<li>We have a one-to-one gender parity at primary school level and we need mechanisms to ensure this continues, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','183', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount183">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','183', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount183">0</span></div></a>
</li>
<li>Woman power can electrify the 21st century, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','182', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount182">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','182', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount182">0</span></div></a>
</li>
<li>The failure to invest in girls education puts in jeopardy many other development goals, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','181', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount181">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','181', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount181">0</span></div></a>
</li>
<li>Men need to be educated too, especially men who wield power, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','180', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount180">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','180', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount180">0</span></div></a>
</li>
<li>We cannot have this division between girls and boys in the school enrollment ratio, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','179', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount179">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','179', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount179">0</span></div></a>
</li>
<li>Not everyone willing to sign up for a simple cause of educating girls, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','178', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount178">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','178', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount178">0</span></div></a>
</li>
<li>Our efforts at educational reforms have not had the desired reach, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','177', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount177">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','177', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount177">0</span></div></a>
</li>
<li>Women like to learn from other women, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','176', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount176">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','176', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount176">0</span></div></a>
</li>
<li>Educated girls marry later, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','175', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount175">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','175', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount175">0</span></div></a>
</li>
<li>The best way to improve the world is in two words - educate girls, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','174', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount174">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','174', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount174">0</span></div></a>
</li>
<li>Women ask why their bedroom should be a dictatorship, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','173', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount173">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','173', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount173">0</span></div></a>
</li>
<li>In mythology, women are a source of knowledge and power. Real women are raped and murdered, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','172', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount172">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','172', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount172">0</span></div></a>
</li>
<li> Widow remarriage was an alternative to sati and a departure from customs, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','171', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount171">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','171', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount171">0</span></div></a>
</li>
<li>Government has two tools: legislation and education.The former is based on instrumental logic, the latter is organic, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','170', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount170">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','170', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount170">0</span></div></a>
</li>
<li> Their struggle is a struggle of every right-minded Indian who needs a better society, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','169', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount169">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','169', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount169">0</span></div></a>
</li>
<li>Even today, we grapple with the horror of the rape of a five year old, says Shashi Tharoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','168', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount168">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','168', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount168">0</span></div></a>
</li>
<li>Union HRD Minister for State Shashi Tharoor to speak.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','167', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount167">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','167', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount167">0</span></div></a>
</li>
<li>Session Stand Up, Speak Out to begin.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','166', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount166">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','166', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount166">0</span></div></a>
</li>
<li>Session Conversation with a Superstar ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','165', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount165">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','165', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount165">0</span></div></a>
</li>
<li>There is no casting couch and no filmmaker indulges in it, says Boney Kapoor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','164', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount164">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','164', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount164">0</span></div></a>
</li>
<li>I followed her to Switzerland during the shooting of Chandani on some pretext, says Boney Kapoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','163', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount163">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','163', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount163">0</span></div></a>
</li>
<li> Sridevi's mother quoted to me Rs 10 lakh for a role for her daughter, says Boney Kapoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','162', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount162">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','162', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount162">0</span></div></a>
</li>
<li>I first saw Sridevi in a Tamil film in the 70s, says Boney Kapoor.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','161', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount161">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','161', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount161">0</span></div></a>
</li>
<li>I look for a role I can proudly show to my family, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','160', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount160">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','160', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount160">0</span></div></a>
</li>
<li>There was no rivalry with Madhuri Dixit, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','159', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount159">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','159', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount159">0</span></div></a>
</li>
<li>I lead a very ordinary life, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','158', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount158">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','158', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount158">0</span></div></a>
</li>
<li>I loved Vidya in Kahaani and Kareena in Talaash, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','157', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount157">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','157', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount157">0</span></div></a>
</li>
<li>I am very fond of Rani Mukerji, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','156', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount156">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','156', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount156">0</span></div></a>
</li>
<li>Of course, casting couch exists in Bollywood. It didn't earlier, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','155', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount155">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','155', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount155">0</span></div></a>
</li>
<li>I am a big fan of Meryl Streep and I wish I get to portray the characters like the ones she has, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','154', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount154">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','154', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount154">0</span></div></a>
</li>
<li>Acting comes from the heart, not from the mind, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','153', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount153">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','153', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount153">0</span></div></a>
</li>
<li>I never plan things and whatever happened was thanks to my directors and producers, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','152', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount152">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','152', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount152">0</span></div></a>
</li>
<li>Dubbing was really a pain, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','151', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount151">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','151', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount151">0</span></div></a>
</li>
<li>My daughters are independent and are doing well in their studies.I don't want to put acting in their mind, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','150', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount150">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','150', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount150">0</span></div></a>
</li>
<li>Very often, I would have to dance in the streets abroad with foreigners wondering what I was doing, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','149', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount149">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','149', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount149">0</span></div></a>
</li>
<li>Jahnvi just turned 16 and she is a very obidient child. She really respects us, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','148', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount148">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','148', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount148">0</span></div></a>
</li>
<li>Yash Chopra waited for 20 minutes at the premiere of English Vinglish to congratulate me, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','147', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount147">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','147', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount147">0</span></div></a>
</li>
<li>I don't want to change anything in my past. If I had to relive my life, I'd live it the same way, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','146', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount146">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','146', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount146">0</span></div></a>
</li>
<li>I still travel with my husband, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','145', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount145">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','145', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount145">0</span></div></a>
</li>
<li>No pain, no gain, one needs to lead a systematic life and feel good from within, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','144', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount144">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','144', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount144">0</span></div></a>
</li>
<li>If you feel good, it reflects on your face, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','143', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount143">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','143', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount143">0</span></div></a>
</li>
<li>There were no vanity vans in early days, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','142', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount142">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','142', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount142">0</span></div></a>
</li>
<li>I had not heard of a bound script 15 years ago. Now it's a cakewalk with every section being taken care of, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','141', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount141">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','141', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount141">0</span></div></a>
</li>
<li> I felt I was starting where I left off 15 years ago, I never felt I was out of touch, says Sridevi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','140', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount140">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','140', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount140">0</span></div></a>
</li>
<li>I confessed to my ex-wife that I was in love with Sridevi, says Boney Kapoor. <div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','139', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount139">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','139', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount139">0</span></div></a>
</li>
<li>Sridevi to talk about movies and motivation and what she's learnt along the way. <div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','138', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount138">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','138', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount138">0</span></div></a>
</li>
<li>Session Conversation with a Superstar to begin shortly.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','137', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount137">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','137', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount137">0</span></div></a>
</li>
<li>Session Why Family Is Not A Burden ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','136', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount136">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','136', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount136">0</span></div></a>
</li>
<li>Take up a leadership role once you understand the industry, then people realise you've earned your position, says Aditi Kothari<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','135', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount135">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','135', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount135">0</span></div></a>
</li>
<li>I want the team to respect me because I understand the business not because I am my fathers daughter, says Aditi Kothari<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','134', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount134">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','134', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount134">0</span></div></a>
</li>
<li>My leadership style is participative, says Zahabiya Khorakiwala.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','133', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount133">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','133', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount133">0</span></div></a>
</li>
<li>I take pride in having set my own benchmarks, says Sarah Jane Dais<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','132', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount132">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','132', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount132">0</span></div></a>
</li>
<li>It would have been easier if I had someone to fall back on, and making it on my own brings me pride, says Sarah Jane Dias<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','131', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount131">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','131', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount131">0</span></div></a>
</li>
<li>At some point, I thought I will make my own money and no one will tell me what to do with it, says Aditi Kothari<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','130', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount130">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','130', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount130">0</span></div></a>
</li>
<li>No one teaches you to employ management and leadership skills, says Aditi Kothari<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','129', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount129">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','129', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount129">0</span></div></a>
</li>
<li>My father was a merchant banker and, back in the 80s, no one understood what that meant, says Aditi Kothari<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','128', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount128">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','128', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount128">0</span></div></a>
</li>
<li>At auditions suggestions were made and this was alien to me because I grew up in Muscat, says Sarah Jane Dais<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','127', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount127">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','127', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount127">0</span></div></a>
</li>
<li>I went for auditions taking trains in Bombay, says Sarah Jane Dias<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','126', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount126">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','126', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount126">0</span></div></a>
</li>
<li>No one teaches you to employ management and leadership skills, says Aditi Kothari.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','125', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount125">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','125', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount125">0</span></div></a>
</li>
<li>The number of issues that scandalised me when I started out are much lesser today, says Sarah Jane Dias.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','124', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount124">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','124', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount124">0</span></div></a>
</li>
<li> Aditi Kothari, Executive VP, DSP BlackRock Investment Managers, Zahabiya Khorakiwala, MD, Wockhardt Hospitals Zahabiya Khorakiwala, Jayanti Chauhan, Director, Bisleri Group, and Sarah Jane Dias, Actor, speak why legacy need not come in the way of the road ahead.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','123', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount123">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','123', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount123">0</span></div></a>
</li>
<li> Session Why Family Is Not A Burden begins.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','122', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount122">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','122', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount122">0</span></div></a>
</li>
<li>Session Madam Boss to Mrs Mom ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','121', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount121">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','121', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount121">0</span></div></a>
</li>
<li>Men move for 10 per cent hikes. Women are fiercely loyal. I took 18 years to move from UBS, says Manisha Gihrotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','120', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount120">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','120', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount120">0</span></div></a>
</li>
<li>A child being raised to be a good human being is one way of defining a successful mother, says Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','119', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount119">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','119', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount119">0</span></div></a>
</li>
<li>Behind every successful man, it's a woman. Behind a successful working mom, it's a nanny, says Manisha Girhotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','118', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount118">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','118', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount118">0</span></div></a>
</li>
<li>I have huge respect for stay-at-home moms. Hats off to them, says Manisha Girhotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','117', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount117">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','117', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount117">0</span></div></a>
</li>
<li>A child being raised to be a good human being is one way of defining a successful mother, says Aruna Jayanthi<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','116', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount116">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','116', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount116">0</span></div></a>
</li>
<li>If my daughter grows up to be a good human being, I think I've been a good mom, says Aruna Jayanthi<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','115', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount115">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','115', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount115">0</span></div></a>
</li>
<li>A successful mom raises a happy child, says Manisha Girhotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','114', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount114">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','114', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount114">0</span></div></a>
</li>
<li>A country easiest for working women, it's India. Won't get the same support system elsewhere, says Aruna Jayanthi, CEO Capegemini.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','113', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount113">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','113', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount113">0</span></div></a>
</li>
<li>It's difficult for all the women to have it all at one time, so choose the right time for right thing to be, says Manisha Girhotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','112', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount112">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','112', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount112">0</span></div></a>
</li>
<li>My nanny is not my significant half. My nanny is my boss, says Manisha Girhotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','111', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount111">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','111', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount111">0</span></div></a>
</li>
<li>India has a phenomenal support system. It's not like abroad. My colleagues abroad are jealous of the support system that we have here, says Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','110', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount110">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','110', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount110">0</span></div></a>
</li>
<li>So what if you take a two-year break in a 30-year career span? It's a good thing, says Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','109', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount109">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','109', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount109">0</span></div></a>
</li>
<li>'Fathers are generally good parent to the kids as he pampers them unlike mothers who discipline them.'<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','108', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount108">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','108', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount108">0</span></div></a>
</li>
<li>Women need to have flexible timing. It is about quality time that you spend anywhere, says Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','107', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount107">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','107', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount107">0</span></div></a>
</li>
<li>The guilt of not being able to spend time with your child, sticks to you, says Kalyani Saha of Dior.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','106', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount106">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','106', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount106">0</span></div></a>
</li>
<li>Aruna Jayanthi and Manisha Girotra feels its quality and not quantity time that matters in parenting.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','105', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount105">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','105', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount105">0</span></div></a>
</li>
<li>There are moments when you need to be there for your child, says Manisha Girotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','104', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount104">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','104', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount104">0</span></div></a>
</li>
<li>I spend important quality time with my daughter. I am there for her. There is no compromise, says Aruna Jayanthi. <br /></p>
<p>Highlight102:I believe in quality time, says Manisha Girotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','103', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount103">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','103', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount103">0</span></div></a>
</li>
<li>I believe in quality time, says Manisha Girotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','102', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount102">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','102', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount102">0</span></div></a>
</li>
<li>Do we deliver guilt with a baby? Kalli Purie questions Aruna Jayanthi and Manisha Girotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','101', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount101">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','101', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount101">0</span></div></a>
</li>
<li>'Am sure men too suffer from the dilemma of work-life balance,' says Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','100', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount100">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','100', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount100">0</span></div></a>
</li>
<li>Women want to be perfect homemakers, mom, daughter and perfect at work as well: Manisha Girotra.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','99', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount99">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','99', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount99">0</span></div></a>
</li>
<li>Women are more demonstrative about it and they are the ones who hold the family together: Aruna Jayanthi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','98', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount98">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','98', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount98">0</span></div></a>
</li>
<li> CEO, Capgemini India Aruna Jayanthi and CEO Moelis and Company Manisha Girotra will discuss how they strike the perfect balance between home and work.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','97', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount97">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','97', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount97">0</span></div></a>
</li>
<li> Session Madam Boss to Mrs Mom to begin shortly.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','96', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount96">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','96', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount96">0</span></div></a>
</li>
<li>Session My Vision for a New Order ends.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','95', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount95">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','95', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount95">0</span></div></a>
</li>
<li>Time has come to initiate professional interest in politics. Start the process of interns, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','94', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount94">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','94', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount94">0</span></div></a>
</li>
<li>As far as entrepreneurs are concerned there is no difference between men and women: Vasundhara Raje on access to finance.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','93', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount93">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','93', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount93">0</span></div></a>
</li>
<li>Sati is not about throwing women onto their husband's pyre. Sati is the woman who transcended odds to rise above them, says Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','92', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount92">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','92', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount92">0</span></div></a>
</li>
<li>It's just about ceding space. Women are going out more, men have to learn to cede space whether in politics or corporate, says Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','91', '0', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount91">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','91', '0', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount91">1</span></div></a>
</li>
<li>There's so much one against the other in Rajasthan. Everyone needs to work together for development, says Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','90', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount90">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','90', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount90">0</span></div></a>
</li>
<li>If u want to play the long game, stay in there and work together: Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','89', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount89">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','89', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount89">0</span></div></a>
</li>
<li>Ashok Gehlot spent his yatra talking about me instead of development: Vasundhara Raje takes jibes at the Rajasthan CM.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','88', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount88">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','88', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount88">0</span></div></a>
</li>
<li>Ashok Gehlot spent 3/4th of his rally speeches talking about me. I would never waste so much time on him, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','87', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount87">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','87', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount87">0</span></div></a>
</li>
<li>Everybody, despite their caste, is part of family Rajasthan and is dealt with affection, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','86', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount86">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','86', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount86">0</span></div></a>
</li>
<li>I will get Modi to Rajasthan, why not asks Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','85', '2', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount85">2</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','85', '2', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount85">0</span></div></a>
</li>
<li>People in politics say a lot of lies: Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','84', '2', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount84">2</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','84', '2', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount84">0</span></div></a>
</li>
<li>Narendra Modi knows the pulse of his people, therefore there is great synergy at play, says Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','83', '2', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount83">2</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','83', '2', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount83">0</span></div></a>
</li>
<li>There's something that Narendra Modi is doing right, that people are appreciating, says Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','82', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount82">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','82', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount82">0</span></div></a>
</li>
<li>In 2003, women voters in Rajasthan were only 30-40 per cent, today the figure has gone up to more than 70 per cent, says Vasundhara Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','81', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount81">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','81', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount81">0</span></div></a>
</li>
<li>50 per cent women in panchayat, five years back were a rubber stamp, today their husbands are making tea, says Raje.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','80', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount80">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','80', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount80">0</span></div></a>
</li>
<li>Now, women have started to claim their space in Rajasthan, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','79', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount79">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','79', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount79">0</span></div></a>
</li>
<li>Work and create a situation that Rajasthan moves forward is the promise that Vasundhara Raje has made to herself.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','78', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount78">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','78', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount78">0</span></div></a>
</li>
<li> Without woman the beginning of our life would be helpless, the middle without pleasure and the end without consolation, says Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','77', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount77">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','77', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount77">0</span></div></a>
</li>
<li>Do you think a man is really running the country, asks Raje<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','76', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount76">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','76', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount76">0</span></div></a>
</li>
<li>My record in Rajasthan speaks for itself, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','75', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount75">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','75', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount75">0</span></div></a>
</li>
<li>I travel in Rajasthan as much as I travel abroad, says Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','74', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount74">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','74', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount74">0</span></div></a>
</li>
<li>Vasundhara Raje, says I lived in London and travelled the world much before people talked about it! They talk because I matter.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','73', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount73">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','73', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount73">0</span></div></a>
</li>
<li>When I get annoyed with someone, I take off my glasses. If I can't see them, I can't hear them, says Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','72', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount72">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','72', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount72">0</span></div></a>
</li>
<li>Politics isn't only about calculation. It's also about having affection and heart, says Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','71', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount71">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','71', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount71">0</span></div></a>
</li>
<li>As a woman, you have to work double the ammount to make yourself known in politics, says Vasundhara Raje.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','70', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount70">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','70', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount70">0</span></div></a>
</li>
<li> Former Rajasthan CM Vasundhara Raje speaks on the struggle to overcome gender bias during the session My Vision for a New Order.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','69', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount69">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','69', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount69">0</span></div></a>
</li>
<li>Vasundhara Raje is on stage.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','68', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount68">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','68', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount68">0</span></div></a>
</li>
<li>The session Beating the odds ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','67', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount67">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','67', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount67">0</span></div></a>
</li>
<li>The police force, even the women officers, are part of a very masculine force that glorifies brutality, feels Meena Kandasamy.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','66', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount66">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','66', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount66">0</span></div></a>
</li>
<li>One needs to respect a woman's right to say 'yes' or 'no' feels Kavita Krishnan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','65', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount65">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','65', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount65">0</span></div></a>
</li>
<li>Cooking was taught to my brother, my sister and me as a skill. There wasn't any gender role being encouraged, says Sakshi Tanwar.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','64', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount64">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','64', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount64">0</span></div></a>
</li>
<li>As an actor, I am only concerned about justifying my character, Sakshi Tanwar speaks on the steamy scene in her daily show.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','63', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount63">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','63', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount63">0</span></div></a>
</li>
<li>Sakshi Tanwar says, 'SRK's gesture of placing the lady actor's name before his own, is rather inconsequential.'<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','62', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount62">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','62', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount62">0</span></div></a>
</li>
<li>Winds of change as Renana Jhabvala says, 'my daughter is so achieving.'<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','61', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount61">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','61', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount61">0</span></div></a>
</li>
<li>Earlier when we'd get men to speak about women, the only thing they'd say is my mother and how self sacrificing she is, says Renana Jhabvala.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','60', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount60">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','60', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount60">0</span></div></a>
</li>
<li>Tokenism doesn't help. Go alphabetically in credits for actors in a film, says Sakshi Tanwar.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','59', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount59">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','59', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount59">0</span></div></a>
</li>
<li>The Tamil word for rape means 'destroying the chastity of a woman'. Chastity is assumed, says Kavita Krishnan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','58', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount58">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','58', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount58">0</span></div></a>
</li>
<li>Society has been profiting from free labour by women at home for generations says Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','57', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount57">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','57', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount57">0</span></div></a>
</li>
<li>The 'real Indian man' is the brother who polices what his sister is wearing but then watches porn later, says Meena Kandaswamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','56', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount56">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','56', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount56">0</span></div></a>
</li>
<li>On questioning Indian culture, especially caste and heirarchy that constitutes it, you are branded western says Kavita Krishnan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','55', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount55">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','55', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount55">0</span></div></a>
</li>
<li>Language is a part of structural oppression. Gruesome violation is masked by words like 'compensation', says Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','54', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount54">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','54', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount54">0</span></div></a>
</li>
<li>Epic answer by Sakshi Tanwar on her marriage proposal. The guy asked when she will leave her job. She said when he leaves his.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','53', '2', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount53">2</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','53', '2', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount53">0</span></div></a>
</li>
<li>I am not ambitious, says Sakshi Tanwar.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','52', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount52">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','52', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount52">0</span></div></a>
</li>
<li>The society maintains the caste system by consciously controlling women's sexuality and gender roles, says Kavita Krishnan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','51', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount51">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','51', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount51">0</span></div></a>
</li>
<li>Female rivalry doesn't exist, except in male imagination: Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','50', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount50">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','50', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount50">0</span></div></a>
</li>
<li>We aren't exercising choices in a vacuum, there are structures like khap panchayats we need to battle, says Kavita Krishnan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','49', '0', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount49">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','49', '0', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount49">1</span></div></a>
</li>
<li>Organised groups of people are working at maintaining traditional barriers against women, says Kavita Krishnan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','48', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount48">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','48', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount48">0</span></div></a>
</li>
<li>Kavita Krishnan talks about politics maintaining khap panchayats.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','47', '1', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount47">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','47', '1', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount47">1</span></div></a>
</li>
<li>Activist Kavita Krishnan says, 'Structural oppression comes in the way to prevent women from getting justice.'<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','46', '0', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount46">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','46', '0', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount46">2</span></div></a>
</li>
<li>Why condemn when it has 30 lakh hits on YouTube, asks Sakshi.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','45', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount45">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','45', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount45">0</span></div></a>
</li>
<li>Sakshi Tanwar questions the hypocrisy around the steamy scene in her TV soap.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','44', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount44">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','44', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount44">0</span></div></a>
</li>
<li>We need to kick up a fuss to break the silence about violence and oppression against women says Meena Kandaswamy.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','43', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount43">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','43', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount43">0</span></div></a>
</li>
<li>Women need to be heard, provoke and offend. We need to become professional troublemakers:Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','42', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount42">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','42', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount42">0</span></div></a>
</li>
<li>Meena Kandaswamy says you need to be a professional troublemaker to get attention.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','41', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount41">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','41', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount41">0</span></div></a>
</li>
<li>Tell people you're suffering, they'll ask you to put up with it. People don't respond unless you provoke and offend, says Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','40', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount40">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','40', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount40">0</span></div></a>
</li>
<li>Social worker Renana Jhabvala says, We need to stop everyday harassment.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','39', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount39">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','39', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount39">0</span></div></a>
</li>
<li>Women need to be heard, provoke and offend. We need to become professional troublemakers, says Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','38', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount38">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','38', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount38">0</span></div></a>
</li>
<li>I write to make people squeamish, says writer Meena Kandasamy.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','37', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount37">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','37', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount37">0</span></div></a>
</li>
<li> Speakers:Renana Jhabvala, Meena Kandasamy, Sakshi Tanwar and Kavita Krishnan talk about the challenges women face in big cities.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','36', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount36">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','36', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount36">0</span></div></a>
</li>
<li>The first session of India Today Women Summit comes ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','35', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount35">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','35', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount35">0</span></div></a>
</li>
<li>Smriti Irani and Jayanthi Natarajan unveils India Today High and Mighty cover.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','34', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount34">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','34', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount34">0</span></div></a>
</li>
<li>Price we pay for a democracy we even uphold the rights of a rapist: Smriti.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','33', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount33">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','33', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount33">0</span></div></a>
</li>
<li>For the first time, a day-to-day trial is going on. There will be punishment: Jayanthi Natarajan on Delhi gangrape case.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','32', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount32">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','32', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount32">0</span></div></a>
</li>
<li>Minor who rapes is old enough to be punished: Jayanthi<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','31', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount31">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','31', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount31">0</span></div></a>
</li>
<li>Senior leaders should show complete intolerance to anything sexist, even a remark, says Jayanthi Natarajan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','30', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount30">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','30', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount30">0</span></div></a>
</li>
<li>I go to Parliament to do my job as an MP, not to sensitise male colleagues: Smriti Irani.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','29', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount29">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','29', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount29">0</span></div></a>
</li>
<li>Gender sensitisation is the collective responsibility of both men and women politicians, says Smriti Irani.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','28', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount28">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','28', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount28">0</span></div></a>
</li>
<li>Being a woman is an art and a gift from God, if men can't understand art and not take care of the gift, then God save mankind, says Jayanthi Natarajan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','27', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount27">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','27', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount27">0</span></div></a>
</li>
<li>What Sanjay Nirupam said to Smriti Irani was highly objectionable. I condemn it, says Jayanti Natarajan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','26', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount26">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','26', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount26">0</span></div></a>
</li>
<li>Jayanthi Natarajan condemns Sanjay Nirupam's defamatory remarks against Smriti Irani.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','25', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount25">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','25', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount25">0</span></div></a>
</li>
<li>Our forensic labs only have a few hundred medical experts and works on a thin budget of just 11 crore, says Smriti Irani.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','24', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount24">1</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','24', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount24">0</span></div></a>
</li>
<li>We haven't thrown out a name for PM candidate, who are you talking about? Smriti Irani dodges questions on Narendra Modi.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','23', '5', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount23">5</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','23', '5', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount23">1</span></div></a>
</li>
<li>Why do you need a screaming virago? Why can't you be quietly strong, asks Jayanthi Natarajan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','22', '7', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount22">7</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','22', '7', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount22">0</span></div></a>
</li>
<li>Jayanthi Natarajan calls Pratibha Patil quietly strong.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','21', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount21">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','21', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount21">0</span></div></a>
</li>
<li>There are villages in India unanimously electing women because, on ground level, women deliver better than men says Smriti Irani.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','20', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount20">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','20', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount20">0</span></div></a>
</li>
<li>Everything is a woman's issue... let us not have a 'janana dabba' mentality: Jayanthi Natarajan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','19', '0', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount19">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','19', '0', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount19">1</span></div></a>
</li>
<li>The question is not who's going to let me, the question is who's going to stop me:Smriti Irani quotes Ayn Rand.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','18', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount18">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','18', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount18">0</span></div></a>
</li>
<li>The presumption that a woman is intelligent only if a man is behind her, not only in politics, says Smriti Irani.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','17', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount17">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','17', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount17">0</span></div></a>
</li>
<li>We will make it happen in the Lok Sabha, Jayanthi and Smriti on Women's Reservation Bill.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('266490','text','1','16', '0', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount16">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','16', '0', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount16">1</span></div></a>
</li>
<li>Jayanthi Natarajan says, 'We made the Women's Reservation Bill happen in the Rajya Sabha, we'll make it happen in the Lok Sabha.'<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','15', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount15">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','15', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount15">0</span></div></a>
</li>
<li>Defense, education, healthcare... everything is a women's issue. Women need to be aware of this: Jayanthi Natrajan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','14', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount14">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','14', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount14">0</span></div></a>
</li>
<li>90 per cent of people in Parliament will lose 180 seats, nobody wants to vote for that, says Jayanthi Natrajan on Women's Reservation Bill.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','13', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount13">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','13', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount13">0</span></div></a>
</li>
<li>Nobody wants to alter the patriarchal power structure of gender roles at home' says Jayanthi Natarajan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','12', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount12">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','12', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount12">0</span></div></a>
</li>
<li>Smriti Irani, Member of Parliament (Rajya Sabha) & Vice President, BJP to address the gathering.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','11', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount11">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','11', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount11">0</span></div></a>
</li>
<li>Jayanthi Natarajan, Union Minister of State (Independent charge), Environment and Forests answers the questions.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','10', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount10">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','10', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount10">0</span></div></a>
</li>
<li>The welcome address by Kaveree Bamzai ends.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','9', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount9">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','9', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount9">0</span></div></a>
</li>
<li>There are a large number of women CEOs in the brutal world of banking, says Kaveree Bamzai.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','8', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount8">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','8', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount8">0</span></div></a>
</li>
<li>Kaveree Bamzai, Editor, India Today, delivers the welcome address at the India Today Woman Summit and Awards.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','7', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount7">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','7', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount7">0</span></div></a>
</li>
<li>The India Today Woman Summit and Awards begins.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','6', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount6">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','6', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount6">0</span></div></a>
</li>
<li>The India Today Woman Summit and Awards is about to start.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','5', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount5">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','5', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount5">0</span></div></a>
</li>
<li>The summit will begin with a Welcome Address by Kaveree Bamzai, Editor, India Today.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','4', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount4">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','4', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount4">0</span></div></a>
</li>
<li>The day-long Summit, now in its fourth year, will be addressed by women and men achievers from a wide spectrum of society.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','3', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount3">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','3', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount3">0</span></div></a>
</li>
<li>The event is hosted by India Today Woman, the popular magazine for the corporate and professional woman, published by the India Today Group.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','2', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount2">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','2', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount2">0</span></div></a>
</li>
<li>The day-long India Today Woman Summit and Awards will begin shortly.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('266490','text','1','1', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount1">0</span> </div></a>
						<a onClick="javascript:changeRating1('266490','text','2','1', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount1">0</span></div></a>
</li>



	
        	
        </ul>
        </div>
	</div>
	
<!-- Google CDN jQuery with fallback to local -->
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
	
	<!-- custom scrollbars plugin -->
	<script src="http://businesstoday.intoday.in/budget/jquery.mCustomScrollbar.concat.min.js"></script>
	<script>
		(function($){
			$(window).load(function(){
				$("#content_1").mCustomScrollbar({
					scrollButtons:{
						enable:true
					}
				});
				//ajax demo fn
				$("a[rel='load-content']").click(function(e){
					e.preventDefault();
					var $this=$(this),
						url=$this.attr("href");
					$this.addClass("loading");
					$.get(url,function(data){
						$this.removeClass("loading");
						$("#content_1 .mCSB_container").html(data); //load new content inside .mCSB_container
						$("#content_1").mCustomScrollbar("update"); //update scrollbar according to newly loaded content
						$("#content_1").mCustomScrollbar("scrollTo","top",{scrollInertia:200}); //scroll to top
					});
				});
				$("a[rel='append-content']").click(function(e){
					e.preventDefault();
					var $this=$(this),
						url=$this.attr("href");
					$this.addClass("loading");
					$.get(url,function(data){
						$this.removeClass("loading");
						$("#content_1 .mCSB_container").append(data); //append new content inside .mCSB_container
						$("#content_1").mCustomScrollbar("update"); //update scrollbar according to newly appended content
						$("#content_1").mCustomScrollbar("scrollTo","h2:last",{scrollInertia:2500,scrollEasing:Power3.easeInOut}); //scroll to appended content
					});
				});
			});
		})(jQuery);
	</script>
	
</body>
</html>

