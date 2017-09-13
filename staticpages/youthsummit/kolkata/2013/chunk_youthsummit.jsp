







<script type="text/javascript"> var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www."); document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E")); </script> <script type="text/javascript"> try { var pageTracker = _gat._getTracker("UA-795349-14"); pageTracker._setAllowLinker(true); pageTracker._setDomainName("none"); pageTracker._trackPageview();pageTracker._trackPageLoadTime();
 } catch(err) {}</script> 

<!DOCTYPE HTML>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Mindrocks 2013 highlights chunk</title>
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
	var urltoPass = "story/mind-rocks-youth-summit-2013---highlights/1/259679.html#rating";
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
			document.getElementById("commenttext"+cid).innerHTML = cmnt;
			runScripts(document.getElementById('upcount'+cid));
			runScripts(document.getElementById('downcount'+cid));
			runScripts(document.getElementById('commenttext'+cid));
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
	url="http://indiatoday.intoday.in/highlights/rating_data_highlights.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&totalcount="+totalc+"&part_id="+part_id;
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
		
		.content{margin:0; width:297px; height:400px; padding:0; overflow:auto;}
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
    border-bottom: 1px solid #E2E2E2;
    border-top: 3px solid #E2E2E2;
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
<div class="strheadline"><div class="headertext"><a href="http://indiatoday.intoday.in/story/mind-rocks-youth-summit-2013---highlights/1/259679.html" target="_blank">HIGHLIGHTS</a></div></div>
<div class="clear"></div>
	<!-- content block -->
	<div id="content_1" class="content">
		<div class="highlighttxt">
        <ul>
        

<li>Now a trio of Majaw, Bappi da and son Bappa stir up a tune.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','181', '46', '25')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount181">46</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','181', '46', '25')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount181">25</span></div></a>
</li>
<li>How many roads must a man walk down...the very sublime Lou Majaw.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','180', '23', '17')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount180">23</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','180', '23', '17')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount180">17</span></div></a>
</li>
<li>Majaw and Bappibda duet.Woohoo!<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','179', '23', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount179">23</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','179', '23', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount179">13</span></div></a>
</li>
<li>Request to Majaw to sing Dylan's Blowing in The Wind. Soulful stuff. Interestingly the first time I heard the song in 65 was in Kolkata, says Majaw.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','178', '26', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount178">26</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','178', '26', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount178">8</span></div></a>
</li>
<li> It's a long way Bappi da...40 years of singing in 500 movies.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','177', '17', '11')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount177">17</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','177', '17', '11')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount177">11</span></div></a>
</li>
<li>De de pyar de pyar de..., sings Bappi da.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','176', '13', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount176">13</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','176', '13', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount176">9</span></div></a>
</li>
<li>House wants more from Bappi da.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','175', '11', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount175">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','175', '11', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount175">6</span></div></a>
</li>
<li>When I went to Mumbai it was the golden era. The legends were there, I was the newcomer, says Bappi Lahiri.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','174', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount174">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','174', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount174">4</span></div></a>
</li>
<li> Bahut log Bappi da ko copy karte hai stage main, par ek film hit jane se koi star nahi ho jata, says Bappi da.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','173', '30', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount173">30</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','173', '30', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount173">8</span></div></a>
</li>
<li>Ooo la la by Bappi Da.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','172', '19', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount172">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','172', '19', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount172">13</span></div></a>
</li>
<li> Bappi da performs, enthrals audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','171', '17', '22')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount171">17</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','171', '17', '22')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount171">22</span></div></a>
</li>
<li>I'm a tabla player first and a composer after, says Bappi.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','170', '16', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount170">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','170', '16', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount170">10</span></div></a>
</li>
<li>I have seen four decades of music and lived with it, says Bappi da.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','169', '13', '12')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount169">13</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','169', '13', '12')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount169">12</span></div></a>
</li>
<li>Bappi da arrives at Mind Rocks.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','168', '15', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount168">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','168', '15', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount168">7</span></div></a>
</li>
<li>Lou Majaw performs at Mind Rocks.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','167', '11', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount167">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','167', '11', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount167">7</span></div></a>
</li>
<li> I never really decided that this is what I want to be but somehow music and Lou Majaw met, says Majaw.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','166', '19', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount166">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','166', '19', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount166">13</span></div></a>
</li>
<li>Lou Majaw - a Rock star, troubadour, guitarist, poet and Zubeen Garg - a singer, composer, actor, filmmaker, author to address the gathering.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','165', '12', '12')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount165">12</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','165', '12', '12')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount165">12</span></div></a>
</li>
<li>The final session - Music is a universal language begins.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','164', '18', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount164">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','164', '18', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount164">6</span></div></a>
</li>
<li>Nobody wants to be a part of a sinking ship. You are one of the most corrupt govt the country has ever seen, Bose tells Mishra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','163', '10', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount163">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','163', '10', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount163">5</span></div></a>
</li>
<li>Om Prakash Mishra says, politics is not about authority, it is about responsibility and ideology.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','162', '26', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount162">26</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','162', '26', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount162">6</span></div></a>
</li>
<li>The UPA did not live up to any kind coalition. That's why we had to leave, says Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','161', '10', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount161">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','161', '10', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount161">3</span></div></a>
</li>
<li>The most important thing we've done is to give a life free from terror, says Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','160', '12', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount160">12</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','160', '12', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount160">8</span></div></a>
</li>
<li>You come in on the back of such stagnation to a bankrupt state what do you do? Says Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','159', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount159">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','159', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount159">4</span></div></a>
</li>
<li>Mishra carries with him the Congress's legacy of being irrelevant, says Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','158', '28', '14')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount158">28</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','158', '28', '14')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount158">14</span></div></a>
</li>
<li>Q&amp;A session begins with Mahua Moitra, Prasenjit Bose and Om Prakash Mishra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','157', '26', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount157">26</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','157', '26', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount157">10</span></div></a>
</li>
<li>I call the TMC a temporary congress. They call themselves Congress and follow CPI(M), says Om Prakash Mishra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','156', '10', '12')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount156">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','156', '10', '12')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount156">12</span></div></a>
</li>
<li>I am apologizing for the Nandigram incident. You are defending the cartoonist's arrest&gt;, asks Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','155', '14', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount155">14</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','155', '14', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount155">9</span></div></a>
</li>
<li>We matter. Our votes matter. Our voice matters, says Om Prakash Mishra, Congress General Secretary while addressing the audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','154', '12', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount154">12</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','154', '12', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount154">5</span></div></a>
</li>
<li> There have been serious deficits even under the Left. But Poriborton has been change for the worst, says Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','153', '5', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount153">5</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','153', '5', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount153">4</span></div></a>
</li>
<li> If the electorate is passive for five years after casting their votes, the system stops working, says Prasenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','152', '7', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount152">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','152', '7', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount152">6</span></div></a>
</li>
<li> Social Media role is there but there is a digital divide in India, says Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','151', '9', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount151">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','151', '9', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount151">10</span></div></a>
</li>
<li>If there was electronic media 15 years ago the Left would have been wiped out 15 years ago: Mahua while answering a question.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','150', '9', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount150">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','150', '9', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount150">4</span></div></a>
</li>
<li>Our democracy needs an overhaul. Should have more referendums for an issue, says Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','149', '7', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount149">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','149', '7', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount149">2</span></div></a>
</li>
<li>More centralisation leads to more corruption. You have to decentralize power: Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','148', '10', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount148">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','148', '10', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount148">7</span></div></a>
</li>
<li>If you want a more accountable system you have to demand answers everyday, says Prasenjit Bose.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','147', '2', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount147">2</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','147', '2', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount147">7</span></div></a>
</li>
<li>Former CPI(M) leader Prasenjit Bose addresses the gathering.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','146', '21', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount146">21</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','146', '21', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount146">9</span></div></a>
</li>
<li>We do tolerate dissent. Yes the fact that we are here in an open platform with reps of other parties is a proof, says Mahua, concluding her speech.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','145', '51', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount145">51</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','145', '51', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount145">8</span></div></a>
</li>
<li>We have out-lefted the left," says Mahua Moitra, TMC Gen Secy.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','144', '7', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount144">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','144', '7', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount144">6</span></div></a>
</li>
<li>Can I fight the election effectively within the limits set by election commission? Yes, says Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','143', '18', '29')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount143">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','143', '18', '29')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount143">29</span></div></a>
</li>
<li>The social media topic is a bit overplayed. Internet penetration in India is only 10.2%: Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','142', '11', '14')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount142">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','142', '11', '14')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount142">14</span></div></a>
</li>
<li>Politicians will have to make themselves available to voters and have to be accountable, says Mahua Moitra.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','141', '19', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount141">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','141', '19', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount141">3</span></div></a>
</li>
<li>Prasenjit Bose, Former CPI(M) leader, Om Prakash Mishra, Congress General Secretary and Mahua Moitra, General Secretary, Trinamool Congress to address the audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','140', '22', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount140">22</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','140', '22', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount140">8</span></div></a>
</li>
<li>Session on How to make your vote and voice count begins.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','139', '43', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount139">43</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','139', '43', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount139">5</span></div></a>
</li>
<li> Conversation with Irrfan Khan comes to end. Audience rush to Irrfan for autograph.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','138', '20', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount138">20</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','138', '20', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount138">7</span></div></a>
</li>
<li>I started watching (Hindi) films when I was giving my class 10 exams. Only in NSD did we see English films.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','137', '8', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount137">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','137', '8', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount137">5</span></div></a>
</li>
<li>I saw DeNiro and Sean Penn during the Oscar awards. They have a kind of graciousness, says Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','136', '6', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount136">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','136', '6', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount136">7</span></div></a>
</li>
<li>Awards are a game of TRPs. Hindi film awards need credibility.They must recognise talent.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','135', '18', '11')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount135">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','135', '18', '11')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount135">11</span></div></a>
</li>
<li>I was offered the role of a father in Life of Pi.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','134', '179', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount134">179</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','134', '179', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount134">10</span></div></a>
</li>
<li> National awards still carry credibility in the eyes of public: Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','133', '10', '30')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount133">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','133', '10', '30')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount133">30</span></div></a>
</li>
<li>I like seeing films from other countries: Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','132', '6', '21')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount132">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','132', '6', '21')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount132">21</span></div></a>
</li>
<li>For me Stardom is about creating an image, says Irrfan Khan<br />Highlight130:Had to reshoot many scenes in Life of Pi. It was like making love, and then making love again, says Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','131', '5', '41')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount131">5</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','131', '5', '41')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount131">41</span></div></a>
</li>
<li>Had to reshoot many scenes in Life of Pi. It was like making love, and then making love again, says Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','130', '7', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount130">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','130', '7', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount130">9</span></div></a>
</li>
<li>The film Paan Singh Tomar tested us. When you connect to the role the challenges are enjoyable.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','129', '4', '24')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount129">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','129', '4', '24')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount129">24</span></div></a>
</li>
<li>The new generation is trying for better and better cinema: Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','128', '30', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount128">30</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','128', '30', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount128">7</span></div></a>
</li>
<li>Did you know Irrfan almost quit cinema. Now on his journey in cinema he says: I can be inspired throughout my life.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','127', '20', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount127">20</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','127', '20', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount127">4</span></div></a>
</li>
<li>Even if you were having a heart attack on the streets, people might just come up and ask for an autograph: Irrfan.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','126', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount126">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','126', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount126">0</span></div></a>
</li>
<li>In my childhood no one could imagine becoming an actor. But I dreamt and became one: Irrfan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','125', '53', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount125">53</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','125', '53', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount125">9</span></div></a>
</li>
<li>I'm from a very middle class family who never approved of cinema, says actor Irrfan Khan.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','124', '104', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount124">104</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','124', '104', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount124">9</span></div></a>
</li>
<li> Session on Bollywood to Hollywood to Bollywood: The Long Journey Home begins. Actor Irrfan Khan&nbsp;&nbsp;&nbsp; <br />addresses the gathering.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','123', '153', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount123">153</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','123', '153', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount123">1</span></div></a>
</li>
<li> The session ends.<br />Highlight121:"There's one person who you don't sledge. With Sachin Tendulkar you just bow before him and try to bowl," a humbled Brett Lee on the Cricket legend.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','122', '119', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount122">119</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','122', '119', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount122">8</span></div></a>
</li>
<li>"There's one person who you don't sledge. With Sachin Tendulkar you just bow before him and try to bowl," a humbled Brett Lee on the Cricket legend.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','121', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount121">1</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','121', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount121">0</span></div></a>
</li>
<li>"I bowled to Laxman and the ball went past his nose. Asked him what does VVS stand for? He said Very Very Scared," says Brett Lee at Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','120', '144', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount120">144</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','120', '144', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount120">7</span></div></a>
</li>
<li>I got injured and the doc told me I'd never bowl again, says Brett Lee.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','119', '24', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount119">24</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','119', '24', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount119">8</span></div></a>
</li>
<li>Brett lee says that he has the attention span of a mouse so T-20 suits him best.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','118', '20', '27')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount118">20</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','118', '20', '27')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount118">27</span></div></a>
</li>
<li>"I love T20 cricket. But there's nothing like test cricket. It's a test of character and a test of time," says Brett Lee at Mind Rocks 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','117', '9', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount117">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','117', '9', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount117">10</span></div></a>
</li>
<li>Australia is going through a rebuilding and transitional phase, will take time to be on top again. Brett Lee on Australia's current position after it lost badly in India vs Aus series.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','116', '46', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount116">46</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','116', '46', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount116">8</span></div></a>
</li>
<li>Brett Lee says he loves the Indian people, culture and the organised chaos of the field.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','115', '8', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount115">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','115', '8', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount115">6</span></div></a>
</li>
<li>If kids are inspired by watching a Beckham more might come in to play. But the bad thing is that they see the glamour and not the hard work that goes into playing for a Mohun Bagan. Bhutia on popularity of International Football.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','114', '14', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount114">14</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','114', '14', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount114">8</span></div></a>
</li>
<li>Bhaichung Bhatia complained "Sadly in India we've 14 I-league clubs but none of them have good grassroots programme."<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','113', '9', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount113">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','113', '9', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount113">9</span></div></a>
</li>
<li>Bhaichung Bhatia: When I started playing foootball, I had no stars to idolise. It was the local players who were the big names.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','112', '4', '42')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount112">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','112', '4', '42')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount112">42</span></div></a>
</li>
<li>Bhaichung Bhutia says it was passion &amp; love for the game that led him to play Football. It was all around him, while growing up in Sikkim.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','111', '18', '42')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount111">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','111', '18', '42')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount111">42</span></div></a>
</li>
<li>"The Australian team tried their best, but were obviously outplayed by the Indians," says Brett Lee at Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','110', '32', '14')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount110">32</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','110', '32', '14')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount110">14</span></div></a>
</li>
<li>Football Player Baichung Bhutia, Australian cricketer Brett Lee and former Indian cricketer Nikhil Chopra address the youth at Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','109', '19', '66')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount109">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','109', '19', '66')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount109">66</span></div></a>
</li>
<li>Football Player Baichung Bhutia and former Australian cricketer Brett Lee to address the youth in the next Session.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','108', '19', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount108">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','108', '19', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount108">8</span></div></a>
</li>
<li>Session with Pradyot Bikram Manikya Deb Barma comes to an end.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','107', '15', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount107">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','107', '15', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount107">7</span></div></a>
</li>
<li>Delhi is too interested in power. But Tripura, Bengal and North East believe more in organisation.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','106', '54', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount106">54</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','106', '54', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount106">4</span></div></a>
</li>
<li>Bikram keeps it simple, says love your people.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','105', '37', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount105">37</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','105', '37', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount105">5</span></div></a>
</li>
<li>Bikram's Poll lessons: Shake Delhi, Delhi itself will listen.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','104', '127', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount104">127</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','104', '127', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount104">4</span></div></a>
</li>
<li>Youngsters need to be more aware. Listen to conversations at the dinner table, at the para: Bikram.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','103', '30', '10')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount103">30</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','103', '30', '10')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount103">10</span></div></a>
</li>
<li>I learned Hindi by watching Hindi movies, especially Amitabh Bachchan. Dialogue - Khush to bahut ho ge tum, says Bikram.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','102', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount102">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','102', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount102">0</span></div></a>
</li>
<li>To bring up your own kind it doesn't mean you put down others: Bikram.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','101', '20', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount101">20</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','101', '20', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount101">5</span></div></a>
</li>
<li>Politics doesn't happen by accident. If it does, then your intention is wrong. It happens with commitment, says Bikram.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','100', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount100">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','100', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount100">0</span></div></a>
</li>
<li>Politics in the North East is different from the rest of the country, says Bikram.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','99', '8', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount99">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','99', '8', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount99">5</span></div></a>
</li>
<li>At 1.30 am when you're locked in a police station you don't think that you're the son of the last Maharaja of Tripura, says Bikram.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','98', '19', '46')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount98">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','98', '19', '46')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount98">46</span></div></a>
</li>
<li>Pradyot Bikram Manikya Deb Barma, General Secretary, Tripura Congress and Editor, The Northeast Today begins addressing the gathering.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','97', '155', '100')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount97">155</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','97', '155', '100')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount97">100</span></div></a>
</li>
<li>Dibakar didn't come to me as a star but as an actor, says Prosenjit. Prosenjit's session comes to an end.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','96', '16', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount96">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','96', '16', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount96">6</span></div></a>
</li>
<li>I never tried for Bollywood. But Shanghai gave me a different kind of high, says Prosenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','95', '7', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount95">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','95', '7', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount95">9</span></div></a>
</li>
<li>Question to Prosenjit - Is there still a need for any other Bengali artist to prove himself in Bollywood?.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','94', '38', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount94">38</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','94', '38', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount94">6</span></div></a>
</li>
<li>I think today's generation wants more sensible films: Prosenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','93', '16', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount93">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','93', '16', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount93">5</span></div></a>
</li>
<li>We used to make films where we'd jump off tall buildings like Phantom and fight 40 people highhandedly, says Prosenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','92', '11', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount92">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','92', '11', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount92">7</span></div></a>
</li>
<li>Rituparno Ghosh is one filmmaker who brought national viewership to Bengali films, says Prosenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','91', '13', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount91">13</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','91', '13', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount91">7</span></div></a>
</li>
<li>We have been able to take Bangla cinema to a new level of good cinema: Prosenjit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','90', '15', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount90">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','90', '15', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount90">6</span></div></a>
</li>
<li>Prosenjit says he wants to know youth's reaction to Bengal cinema.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','89', '100', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount89">100</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','89', '100', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount89">4</span></div></a>
</li>
<li>The Session on Knock-out Punch: Lights, Camera, Drama begins. Actor Prosenjit Chatterjee addresses the Session.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','88', '42', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount88">42</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','88', '42', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount88">6</span></div></a>
</li>
<li>There are many songs. And many first songs, says Rupam. The Session comes to an end with the crowd singing along to Benche Thakar Gaan with Rupam.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','87', '18', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount87">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','87', '18', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount87">4</span></div></a>
</li>
<li>Rupam on writing songs - ami jani na ami ki bhabe gaan likhi (I don't know how I write songs).<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','86', '15', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount86">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','86', '15', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount86">7</span></div></a>
</li>
<li>We got noticed when a radio station started playing our two songs - Ekla Ghar and Hasnuhana.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','85', '16', '9')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount85">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','85', '16', '9')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount85">9</span></div></a>
</li>
<li>There was no music company who wanted to release our album, says Rupam.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','84', '28', '60')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount84">28</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','84', '28', '60')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount84">60</span></div></a>
</li>
<li>Rupam on studying English: Lekha ta holo, pora ta holo, kintu bola ta holo na.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','83', '31', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount83">31</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','83', '31', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount83">5</span></div></a>
</li>
<li>The secret of success is practice, practice and practice driven by passion, says Rupam Islam.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','82', '27', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount82">27</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','82', '27', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount82">8</span></div></a>
</li>
<li>Rupam Islam, playback singer, Song Writer, Composer and the Lead Singer of the band Fossils begins his speech.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','81', '55', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount81">55</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','81', '55', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount81">8</span></div></a>
</li>
<li> Madam hum gunday. Ek bar jiske saath jee liye marte bhi usike saath hai, Ranveer ends his speech with a dialogue.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','80', '30', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount80">30</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','80', '30', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount80">4</span></div></a>
</li>
<li>You have to be really thick skinned. I'd ambush guys at restaurants and give them my portfolio, tells Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','79', '9', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount79">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','79', '9', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount79">7</span></div></a>
</li>
<li>I took four months off to build my body. And 6 to 8 months to work on my portfolio. It's your calling card, says Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','78', '23', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount78">23</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','78', '23', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount78">7</span></div></a>
</li>
<li>You have to earn your stripes in theatre. For a few months I was the guy who swept floors.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','77', '24', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount77">24</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','77', '24', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount77">3</span></div></a>
</li>
<li>I came back to India in 2007 with a degree and said OK I want to be an actor.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','76', '21', '14')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount76">21</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','76', '21', '14')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount76">14</span></div></a>
</li>
<li>Watching 'Taxi Driver' was a turning point, says Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','75', '34', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount75">34</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','75', '34', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount75">13</span></div></a>
</li>
<li>Can you imagine my conversation with my father. A dad who's paid through his nose to educate his son in the US and he says papa mujhe actor banana hai: Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','74', '4', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount74">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','74', '4', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount74">2</span></div></a>
</li>
<li>That day I felt the rush of performance and appreciation. I realised then this is what I wanted to do: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','73', '22', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount73">22</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','73', '22', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount73">5</span></div></a>
</li>
<li>I performed the monologue from Deewar at the acting school, the only dialogue I knew.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','72', '22', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount72">22</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','72', '22', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount72">6</span></div></a>
</li>
<li>I studied Acting while studying in USA as I wasn't late in enrolling and that was the only course left: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','71', '34', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount71">34</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','71', '34', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount71">7</span></div></a>
</li>
<li>As an actor you always collect life experiences that you can use in a performance, tells Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','70', '19', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount70">19</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','70', '19', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount70">4</span></div></a>
</li>
<li>Thank God I didn't make it as a copywriter: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','69', '18', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount69">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','69', '18', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount69">6</span></div></a>
</li>
<li>I went to JWT and O&amp;M. I'd come up with slogans like "Coil tha hara lekin macchar nahin mara".<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','68', '6', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount68">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','68', '6', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount68">2</span></div></a>
</li>
<li>Don't let any one tell you what you can be. My aptitude tests said I could be good in computers or business: Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','67', '14', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount67">14</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','67', '14', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount67">3</span></div></a>
</li>
<li>I peed in my pants when I had to speak in front of the entire school: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','66', '6', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount66">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','66', '6', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount66">7</span></div></a>
</li>
<li>I always wanted to be an actor in the mainstream Hindi cinema: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','65', '16', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount65">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','65', '16', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount65">5</span></div></a>
</li>
<li>I wanted to be an actor in the mainstream Hindi cinema: Ranveer Singh.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','64', '15', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount64">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','64', '15', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount64">2</span></div></a>
</li>
<li>It's okay to get nervous and screw up at times, says Ranveer.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','63', '7', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount63">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','63', '7', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount63">5</span></div></a>
</li>
<li> Actor Ranveer Singh breaks into Jumma Chumma number.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','62', '10', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount62">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','62', '10', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount62">4</span></div></a>
</li>
<li>There are no rules for success. Follow your own journey, says Ranveer Singh. He always wanted to become an actor.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','61', '9', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount61">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','61', '9', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount61">5</span></div></a>
</li>
<li>Actor Ranveer Singh speaks at the Session.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','60', '3', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount60">3</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','60', '3', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount60">6</span></div></a>
</li>
<li>The session on How I Made It: 30 minute performances by youth icons begins.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','59', '4', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount59">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','59', '4', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount59">6</span></div></a>
</li>
<li>The Session on the Raaz of Relationships: Commitment in the Time of Casual Love comes to an end.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','58', '18', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount58">18</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','58', '18', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount58">2</span></div></a>
</li>
<li>My butt is more famous than my face. Kunaal Roy Kapur tells the audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','57', '4', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount57">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','57', '4', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount57">2</span></div></a>
</li>
<li>Live in relationships: I've just entered one: Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','56', '3', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount56">3</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','56', '3', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount56">4</span></div></a>
</li>
<li>Marriage is about companionship. You should enjoy your silences: Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','55', '14', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount55">14</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','55', '14', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount55">7</span></div></a>
</li>
<li>Relationships are not gadgets. It's a rare and wonderful thing when you really connect with that special someone, says Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','54', '7', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount54">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','54', '7', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount54">0</span></div></a>
</li>
<li>Commitment is staying true to someone, says Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','53', '38', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount53">38</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','53', '38', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount53">7</span></div></a>
</li>
<li>The first relationship I've been is with the girl I married, tells Kunaal Roy Kapur to the audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','52', '9', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount52">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','52', '9', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount52">1</span></div></a>
</li>
<li>We go extra mile to complicate things for ourselves. Free will brings a&nbsp; lot of confusion, says Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','51', '7', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount51">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','51', '7', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount51">3</span></div></a>
</li>
<li>Disloyalty is an action not a thought, says Soha Ali.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','50', '8', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount50">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','50', '8', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount50">3</span></div></a>
</li>
<li>The Q&amp;A Session begins.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','49', '1', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount49">1</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','49', '1', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount49">3</span></div></a>
</li>
<li>We sustained ourselves for a year on the gift money, says Kunaal.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','48', '5', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount48">5</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','48', '5', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount48">7</span></div></a>
</li>
<li>I got married for two reasons. To keep my wife and in-laws happy. And the second was for the gifts: Kunaal Kapur.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','47', '9', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount47">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','47', '9', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount47">4</span></div></a>
</li>
<li>I am married and I have two children. So I don't know what I'm doing a youth summit, asks Kunaal Roy Kapur.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','46', '4', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount46">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','46', '4', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount46">2</span></div></a>
</li>
<li>Actor Kunaal Roy Kapur speaks at the Session.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','45', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount45">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','45', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount45">4</span></div></a>
</li>
<li>It's important to get your heart broken. It's important to feel the deep dark emotions, says Soha Ali.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','44', '6', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount44">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','44', '6', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount44">4</span></div></a>
</li>
<li>You must listen to your heart, even though it sounds really trite: Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','43', '5', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount43">5</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','43', '5', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount43">5</span></div></a>
</li>
<li>What's behind the 'hey what's up'?, asks Soha.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','42', '15', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount42">15</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','42', '15', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount42">3</span></div></a>
</li>
<li>I don't understand people who are in long term casual relationships: Soha Ali.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','41', '1', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount41">1</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','41', '1', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount41">1</span></div></a>
</li>
<li> I'm not unafraid of making a commitment to someone. Commitment means different things to different people, says Soha Ali.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','40', '3', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount40">3</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','40', '3', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount40">4</span></div></a>
</li>
<li>I'm in a long term relationship. Does it mean I'm not in a committed relationship because I'm not married?, asks Soha Ali.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','39', '3', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount39">3</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','39', '3', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount39">6</span></div></a>
</li>
<li>Actor Soha Ali Khan and Kunaal Roy Kapur to speak at the session&gt;<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','38', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount38">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','38', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount38">4</span></div></a>
</li>
<li>Session on The Raaz of Relationships: Commitment in the Time of Casual Love begins.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','37', '11', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount37">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','37', '11', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount37">3</span></div></a>
</li>
<li>Up next Bollywood actors Soha Ali Khan and Kunaal Roy Kapur on the Raaz of Relationships: Commitment in the Time of Casual Love.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','36', '4', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount36">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','36', '4', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount36">4</span></div></a>
</li>
<li>An interesting Chetan Bhagat session ends at Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','35', '8', '80')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount35">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','35', '8', '80')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount35">80</span></div></a>
</li>
<li>Chetan Bhagat urges "Let us reset our standards of morality keeping the youth in mind."<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','34', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount34">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','34', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount34">0</span></div></a>
</li>
<li>When they clap, it does not matter if its a brown hand or white hand. My goal is to reach more Indians, says Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','33', '17', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount33">17</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','33', '17', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount33">1</span></div></a>
</li>
<li>Why don't we show working women with kids in a kids product ad, asks Chetan Bhagat.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','32', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount32">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','32', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount32">0</span></div></a>
</li>
<li>"I used to think I wanted to be a woman," confesses Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','31', '9', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount31">9</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','31', '9', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount31">1</span></div></a>
</li>
<li>Chetan Bhagat explains the meaning of LBD. Look busy do nothing.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','30', '7', '8')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount30">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','30', '7', '8')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount30">8</span></div></a>
</li>
<li>Chetan Bhagat exposes Bollywood's obsession with looking thin. Says that actors don't have salt 3 days before a big photo shoot.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','29', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount29">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','29', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount29">0</span></div></a>
</li>
<li>"What is this seduction of Bollywood you talked about? I know your wife is sitting here." Tough questions being asked to Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','28', '7', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount28">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','28', '7', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount28">0</span></div></a>
</li>
<li>The Q&amp;A session of Chetan Bhagat with the audience begins.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','27', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount27">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','27', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount27">0</span></div></a>
</li>
<li>Chetan Bhagat - Bad mistakes are mistakes that are caused by human weaknesses. Greed. Laziness.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','26', '7', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount26">7</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','26', '7', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount26">1</span></div></a>
</li>
<li>"Bollywood's allure is as attractive as it's brutal," says Chetan Bhagat.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','25', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount25">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','25', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount25">0</span></div></a>
</li>
<li>All my batchmates, people around me were obsessed with money. Money destroys your soul, says Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','24', '5', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount24">5</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','24', '5', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount24">3</span></div></a>
</li>
<li>"My best success was turning my passion into a reality and not letting success go to my head," boasts Chetan Bhagat.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','23', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount23">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','23', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount23">0</span></div></a>
</li>
<li>3 'good' mistakes Chetan Bhagat cites: 1st bad book, 2nd the disastrous film 'Hello' and 3rd Kai Po Che.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','22', '6', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount22">6</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','22', '6', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount22">2</span></div></a>
</li>
<li>"Why is chasing money alone a bad mistake? It misdirects you," Chetan Bhagat speaks at Mind Rocks, Kolkata on good mistakes and bad successes and what he learnt from them.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','21', '13', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount21">13</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','21', '13', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount21">4</span></div></a>
</li>
<li>"My bad mistakes? Chasing money," confesses Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','20', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount20">8</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','20', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount20">4</span></div></a>
</li>
<li>When you take a risk and it doesn't pay off, people call it a mistake. That's not right," complains Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','19', '11', '3')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount19">11</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','19', '11', '3')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount19">3</span></div></a>
</li>
<li>I didn't see one bad review of Kai Po Che. That was strange, because I mostly get bad reviews - Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','18', '16', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount18">16</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','18', '16', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount18">1</span></div></a>
</li>
<li>We wanted stars for Kai Po Che, but nobody came. They all said "No yaar, three middleclass boys in Ahmedabad," reveals Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','17', '4', '1')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount17">4</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','17', '4', '1')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount17">1</span></div></a>
</li>
<li>The second mistake was the movie Hello. How many of you liked it, asks Chetan Bhagat to the audience.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','16', '10', '11')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount16">10</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','16', '10', '11')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount16">11</span></div></a>
</li>
<li>The first book I wrote was dull and stupid and I felt bad when it was rejected. But I am happy I made that mistake, says Chetan Bhagat.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','15', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount15">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','15', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount15">0</span></div></a>
</li>
<li>My next film is a 'mass' movie called Kick. We don't really need a scriptwriter because it has Salman Khan in it, says Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','14', '227', '26')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount14">227</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','14', '227', '26')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount14">26</span></div></a>
</li>
<li>Chetan Bhagat quotes Warren Buffet to say we don't grow emotionally.<div class='clear'></div> 

						<a onClick="javascript:changeRating1('259679','text','1','13', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount13">0</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','13', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount13">0</span></div></a>
</li>
<li>All Indians ar my brothers and sisters barring the really pretty girls, winks Chetan Bhagat<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','12', '1', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount12">1</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','12', '1', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount12">2</span></div></a>
</li>
<li>In a country like India mistakes are not pardoned. Very few people get a second chance, says Chetan Bhagat.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','11', '1', '2')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount11">1</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','11', '1', '2')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount11">2</span></div></a>
</li>
<li>Chetan Bhagat speaks on the 3 Mistakes 3 Successes of his life at the Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','10', '207', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount10">207</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','10', '207', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount10">13</span></div></a>
</li>
<li>Author Chetan Bhagat on stage at the Youth Summit.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','9', '64', '35')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount9">64</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','9', '64', '35')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount9">35</span></div></a>
</li>
<li>CEO, India Today Group, Ashish Bagga delivers welcome address at the Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','8', '47', '55')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount8">47</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','8', '47', '55')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount8">55</span></div></a>
</li>
<li>CEO, India Today Group, Ashish Bagga with India Today Conclave Director Kalli Purie is on stage.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','7', '51', '39')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount7">51</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','7', '51', '39')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount7">39</span></div></a>
</li>
<li>Coming up next author Chetan Bhagat on the 3 Mistakes 3 Successes of his life.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','6', '250', '25')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount6">250</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','6', '250', '25')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount6">25</span></div></a>
</li>
<li>Watch Ultimate Teenage Angst with Bon Jovi's It's My Life at Mind Rocks Youth Summit 2013.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','5', '90', '18')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount5">90</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','5', '90', '18')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount5">18</span></div></a>
</li>
<li>Mind Rocks Youth Summit 2013 kicks of with rocking Dil Se, covered by band Tenth Harmony.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','4', '78', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount4">78</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','4', '78', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount4">5</span></div></a>
</li>
<li>Rockband performs at the Mind Rock Youth Summit in Kolkata.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','3', '53', '22')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount3">53</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','3', '53', '22')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount3">22</span></div></a>
</li>
<li>Mind Rocks Youth Summit 2013 begins. <div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','2', '48', '21')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount2">48</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','2', '48', '21')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount2">21</span></div></a>
</li>
<li>Mind Rocks Youth Summit 2013 to begin shortly.<div class='clear'></div> 
						<a onClick="javascript:changeRating1('259679','text','1','1', '69', '38')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount1">69</span> </div></a>
						<a onClick="javascript:changeRating1('259679','text','2','1', '69', '38')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount1">38</span></div></a>
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


