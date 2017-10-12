






<script type="text/javascript"> var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www."); document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E")); </script> <script type="text/javascript"> try { var pageTracker = _gat._getTracker("UA-795349-14"); pageTracker._setAllowLinker(true); pageTracker._setDomainName("none"); pageTracker._trackPageview();pageTracker._trackPageLoadTime();
 } catch(err) {}</script> 

<!DOCTYPE HTML>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="refresh" content="300; URL=/staticpages/special40/chunk_mindrock1.jsp?id=511176">
	<title>Mindrocks 2015 highlights chunk</title>
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
	var urltoPass = "story/india-today-mind-rocks-2015-highlights/1/511176.html#rating";
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
		
			runScripts(document.getElementById('upcount'+cid));
			runScripts(document.getElementById('downcount'+cid));
			runScripts(document.getElementById('commenttext'+cid));
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
		
		.content{margin:0; width:200px; height:256px; padding:0; overflow:auto;}
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
<!-- <div class="strheadline"><div class="headertext"><a href="http://indiatoday.intoday.in/story/mind-rocks-youth-summit-2013---highlights/1/259679.html" target="_blank">HIGHLIGHTS</a></div></div> -->
<div class="clear"></div>
	<!-- content block -->
	<div id="content_1" class="content">
		<div class="highlighttxt">
        <ul>
        

<li> And now the final session of&nbsp;India Today Mind Rocks Youth Summit 2015 begins with DJ Wale Babu - Badshah<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','133', '26', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount133">26</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','133', '26', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount133">7</span></div></a>
</li>
<li> Sachin, Sourav,Sehwag, Kohli, Dravid, Dhoni, Yuvraj, Harbhajan, myself, Srinath, Zaheer and Venkatesh Prasad - Kumble names his favourite India XI<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','132', '16', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount132">16</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','132', '16', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount132">7</span></div></a>
</li>
<li> My parents were very supportive. I didn't give them an opportunity to complain. You can study and be a sportsman as well: Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','131', '18', '13')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount131">18</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','131', '18', '13')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount131">13</span></div></a>
</li>
<li> There are good bowlers in the current Indian team. We need to show a lot more patience with our current bunch of bowlers, says Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','130', '11', '7')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount130">11</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','130', '11', '7')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount130">7</span></div></a>
</li>
<li> India was totally outplayed by South Africa in Mumbai but overall the series was very well fought by both team: Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','129', '9', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount129">9</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','129', '9', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount129">4</span></div></a>
</li>
<li> I was fortunate to have Virender Sehwag in my team, says Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','128', '8', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount128">8</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','128', '8', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount128">5</span></div></a>
</li>
<li> MS Dhoni has been the most successful captains in India. Virat (Kohli) has just taken over in Tests. We don't need to find a third one: Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','127', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount127">8</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','127', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount127">4</span></div></a>
</li>
<li> You have to lead by example when you get an opportunity, says Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','126', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount126">8</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','126', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount126">4</span></div></a>
</li>
<li> You can't compare talent. What is important is how you react to different situations with your talent: Anil Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','125', '6', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount125">6</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','125', '6', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount125">5</span></div></a>
</li>
<li> The final session of India Today Mind Rocks Youth Summit 2015 is to begin shortly. The session - The perfect ten spinning a dream - will feature former Indian cricket team captain Anil Kumble<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','124', '8', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount124">8</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','124', '8', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount124">4</span></div></a>
</li>
<li> Youth like you here must join politics to take the country forward, adds Scindia<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','123', '9', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount123">9</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','123', '9', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount123">5</span></div></a>
</li>
<li> I assure you Acche din will come if India stays united, says Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','122', '7', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount122">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','122', '7', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount122">5</span></div></a>
</li>
<li> Today, India is much more a confident nation than what it was 15 months ago: Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','121', '7', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount121">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','121', '7', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount121">5</span></div></a>
</li>
<li> The problem with BJP is that they always look for a conspiracy when there is none, says Scindia<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','120', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount120">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','120', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount120">4</span></div></a>
</li>
<li> We can't help if writers, artists are inclined towards a political ideology. Returning an award is not a good gesture, says Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','119', '9', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount119">9</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','119', '9', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount119">4</span></div></a>
</li>
<li> Returning awards is a deep rooted conspiracy, says Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','118', '7', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount118">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','118', '7', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount118">5</span></div></a>
</li>
<li> There should be no differences in opinion among political parties over issues of national importance: Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','117', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount117">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','117', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount117">4</span></div></a>
</li>
<li> I can assure the young minds of India here that the country is safe than what it used to be earlier, says Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','116', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount116">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','116', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount116">4</span></div></a>
</li>
<li> You have got enough opportunities in the past, give us some time: Rijiju to Scindia<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','115', '7', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount115">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','115', '7', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount115">5</span></div></a>
</li>
<li> Why the PM remained silent for 15 days before making a statement over Dadri? asks Scindia<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','114', '6', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount114">6</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','114', '6', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount114">5</span></div></a>
</li>
<li> Today we need leaders who can walk the talk, says Scindia<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','113', '6', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount113">6</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','113', '6', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount113">5</span></div></a>
</li>
<li> Organised miscampaigning against the government is damaging country's image: Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','112', '5', '6')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount112">5</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','112', '5', '6')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount112">6</span></div></a>
</li>
<li> PM has made it clear that we are committed to the Constitution of country: Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','111', '5', '5')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount111">5</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','111', '5', '5')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount111">5</span></div></a>
</li>
<li> The government will not deviate from its focus, and the focus is only development, says Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','110', '7', '4')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount110">7</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','110', '7', '4')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount110">4</span></div></a>
</li>
<li> We are not deciding on the personal choices of people: Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','109', '6', '11')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount109">6</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','109', '6', '11')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount109">11</span></div></a>
</li>
<li> The freedom of choice should not be slapped upon anyone, says Scindia<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','108', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount108">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','108', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount108">0</span></div></a>
</li>
<li> Hindi is not a language of one region or city. Hindi connects the country, it should be used for national integration, says Rijiju<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','107', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount107">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','107', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount107">0</span></div></a>
</li>
<li> Success is collection of all failures, says Kiren Rijiju<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','106', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount106">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','106', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount106">0</span></div></a>
</li>
<li> The next session is Political duet - Politics as a 24x7 profession and why it's necessary. Speakers are Congress MP Jyotiraditya Scindia and Union Minister of State for Home Affairs Kiren Rijiju<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','105', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount105">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','105', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount105">0</span></div></a>
</li>
<li> If you want to be a stand-up comedian, stay ready to fail, but gradually things will take shape, says Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','104', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount104">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','104', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount104">0</span></div></a>
</li>
<li> If there is a consenting and eligible audience, why should government interfere in comedy business: Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','103', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount103">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','103', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount103">0</span></div></a>
</li>
<li> Writing jokes is like an art, you have to understand the context you are in, says Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','102', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount102">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','102', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount102">0</span></div></a>
</li>
<li> Most jokes in the world are against powerful people: Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','101', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount101">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','101', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount101">0</span></div></a>
</li>
<li> Bollywood has purified everything wrong with the Indian society, says Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','100', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount100">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','100', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount100">0</span></div></a>
</li>
<li> I was never funny, people around me were, that made me a comedian: Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','99', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount99">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','99', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount99">0</span></div></a>
</li>
<li> The next session is Interlude - Taking comedy seriously and the art of giving offence with stand-up comic Biswa Kalyan Rath<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','98', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount98">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','98', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount98">0</span></div></a>
</li>
<li> Follow what you really want to do in life. Follow your heart, says Papon as he concludes the session<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','97', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount97">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','97', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount97">0</span></div></a>
</li>
<li> Papon sings his inspirational song from Assam. He also dances to its tunes<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','96', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount96">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','96', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount96">0</span></div></a>
</li>
<li> Papon enthrals the audience with Humnava from Hamari Adhuri Kahani<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','95', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount95">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','95', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount95">0</span></div></a>
</li>
<li> It is fun to chase your dream: Papon<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','94', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount94">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','94', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount94">0</span></div></a>
</li>
<li> It is good that I&nbsp;get less songs to sing because my voice doesn't fit in to all songs: Papon<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','93', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount93">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','93', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount93">0</span></div></a>
</li>
<li> Folk music represents your roots: Papon<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','92', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount92">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','92', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount92">0</span></div></a>
</li>
<li> Papon hums ghazal Ranjish hi sahi<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','91', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount91">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','91', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount91">0</span></div></a>
</li>
<li> Singer Papon begins the session with Yeh moh moh ke dhaage<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','90', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount90">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','90', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount90">0</span></div></a>
</li>
<li> Singer Papon and Union Minister of State for Urban Development and singer Babul Supriyo take the stage for next session: Making the soul sing - The soundtrack of our lives<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','89', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount89">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','89', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount89">0</span></div></a>
</li>
<li> If you are different, you should learn to stand on your own. You must also seek help, it is not a sign of weakness, says Naina<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','88', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount88">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','88', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount88">0</span></div></a>
</li>
<li> I want Naina to be happy&nbsp;in her body, says Naina's mother<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','87', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount87">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','87', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount87">0</span></div></a>
</li>
<li>&nbsp;I always knew that Krishna (Naina)&nbsp;was girly, says&nbsp;Mishi Singh<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','86', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount86">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','86', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount86">0</span></div></a>
</li>
<li> When you are gay you are still a man. So, I wanted to be a transgender to be a girl, says Naina Singh<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','85', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount85">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','85', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount85">0</span></div></a>
</li>
<li> While I was about to attempt suicide, my friend called me to say that she loved me, and that brought me back, says Naina<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','84', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount84">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','84', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount84">0</span></div></a>
</li>
<li> The next session is Unconditional acceptance -&nbsp; What to expect from our parents. Naina Singh, a student and her mother Mishi Singh are the two speakers<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','83', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount83">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','83', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount83">0</span></div></a>
</li>
<li> If you are not nervous before a performance then you are overconfident: Faisal Khan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','82', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount82">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','82', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount82">0</span></div></a>
</li>
<li> If given a chance I would like to work with Shahrukh Khan and Nawazuddin Siddiqui, says Faisal<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','81', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount81">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','81', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount81">0</span></div></a>
</li>
<li> I also want to be a big superstar but all depends on my destiny: Faisal Khan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','80', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount80">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','80', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount80">0</span></div></a>
</li>
<li> All performances on Jhalak were live, without retakes, which&nbsp;was very challenging: Faisal Khan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','79', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount79">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','79', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount79">0</span></div></a>
</li>
<li> The next session is Man on the move - Dance like there's no one watching. Faisal Khan, winner, Jhalak Dikhhla Jaa Reloaded is the speaker<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','78', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount78">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','78', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount78">0</span></div></a>
</li>
<li> The government can't just gag the internet, says Shreya Singhal the law student who challenged Sec 66(A) of the IT Act<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','77', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount77">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','77', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount77">0</span></div></a>
</li>
<li> Ashraf's tip for a young rapper from the crowd - Make your own content<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','76', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount76">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','76', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount76">0</span></div></a>
</li>
<li> Ashraf made a rap song attacking the actions of Unilever in Kodaikanal. The song went viral and was a huge hit<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','75', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount75">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','75', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount75">0</span></div></a>
</li>
<li> The next speaker is&nbsp;rapper&nbsp;Sofia Ashraf<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','74', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount74">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','74', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount74">0</span></div></a>
</li>
<li> Radha Kapoor has also invested in a Kabaddi team, and it has been an exciting experience, she says<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','73', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount73">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','73', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount73">0</span></div></a>
</li>
<li> Trend is shifting now. Now, lot of big companies are investing in startups: Radha Kapoor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','72', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount72">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','72', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount72">0</span></div></a>
</li>
<li> Next guest&nbsp;on the session is Radha Kapoor, Founder and Director of the Indian School of Design and Innovation<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','71', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount71">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','71', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount71">0</span></div></a>
</li>
<li> A couple of lucky schoolgirls get chance to accompany Arjun Kanungo in singing Kabira from the movie Yeh Jawaani Hai Deewani<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','70', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount70">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','70', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount70">0</span></div></a>
</li>
<li> I learnt my music on internet, says Arjun Kanungo<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','69', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount69">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','69', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount69">0</span></div></a>
</li>
<li> Smart technology does not make smart music, says Arjun Kanungo<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','68', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount68">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','68', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount68">0</span></div></a>
</li>
<li> It's very difficult to find your own sound as a musician, when there is so much happening around you: Arjun<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','67', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount67">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','67', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount67">0</span></div></a>
</li>
<li> Musician Arjun Kanungo, law student Shreya Singhal,&nbsp; Founder and Director of the Indian School of Design and Innovation Radha Kapoor and rapper Sofia Ashraf are the speakers<div class='clear'></div> 
						<a onClick="javascript:changeRating1('511176','text','1','66', '1', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount66">1</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','66', '1', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount66">0</span></div></a>
</li>
<li> The session with Randeep Hooda ends. Time for the new session -  Being a newbie: Who's new, what's cool, why it's hot<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','65', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount65">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','65', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount65">0</span></div></a>
</li>
<li> I want to be remembered for my work, says Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','64', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount64">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','64', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount64">0</span></div></a>
</li>
<li> If you don't take risk you will be forgotten: Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','63', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount63">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','63', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount63">0</span></div></a>
</li>
<li> If you really want to stand out it's imperative you choose things that others don't: Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','62', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount62">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','62', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount62">0</span></div></a>
</li>
<li> I had no role model from Haryana to follow: Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','61', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount61">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','61', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount61">0</span></div></a>
</li>
<li> I don't like the term grey character, like to keep my work diverse:&nbsp;Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','60', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount60">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','60', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount60">0</span></div></a>
</li>
<li> Initially I felt I can never fit into Bollywood: Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','59', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount59">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','59', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount59">0</span></div></a>
</li>
<li> Worked very hard for the film: Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','58', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount58">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','58', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount58">0</span></div></a>
</li>
<li> I first heard about Charles Sobhraj when I was in school: Randeep Hooda<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','57', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount57">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','57', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount57">0</span></div></a>
</li>
<li> The session with actor Randeep Hooda begins<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','56', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount56">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','56', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount56">0</span></div></a>
</li>
<li> Welcome back to the post-lunch session of India Today Mind Rocks Youth Summit 2015<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','55', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount55">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','55', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount55">0</span></div></a>
</li>
<li> See you all next year, promises Sidharth as he leaves the stage<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','54', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount54">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','54', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount54">0</span></div></a>
</li>
<li> And now&nbsp;Sidharth shakes a leg with some of his&nbsp;fans on his song - Radha&nbsp;On The Dance Floor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','53', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount53">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','53', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount53">0</span></div></a>
</li>
<li> On huge public demand Sidharth Malhotra shows his moves on Disco Deewane<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','52', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount52">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','52', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount52">0</span></div></a>
</li>
<li> I feel like shifting back to my home town Delhi from Mumbai<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','51', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount51">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','51', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount51">0</span></div></a>
</li>
<li> I too have had my share of witnessing rejection by girls in my college days: Sidharth<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','50', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount50">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','50', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount50">0</span></div></a>
</li>
<li> Better looks in modelling and acting help you make it big, says Sidharth<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','49', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount49">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','49', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount49">0</span></div></a>
</li>
<li> After sensational Sonam it's time for hunk Sidharth Malhotra<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','48', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount48">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','48', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount48">0</span></div></a>
</li>
<li> Sonam's style advice for youngsters - It's just about being yourself and being comfortable<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','47', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount47">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','47', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount47">0</span></div></a>
</li>
<li> Salman Khan is an amazing person, he does everything that he can for anyone: Sonam Kapoor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','46', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount46">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','46', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount46">0</span></div></a>
</li>
<li> I am a very romantic person, yet to find the right man: Sonam Kapoor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','45', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount45">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','45', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount45">0</span></div></a>
</li>
<li> I am not in love. I am in love with life: Sonam Kapoor<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','44', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount44">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','44', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount44">0</span></div></a>
</li>
<li> Ravishing Sonam Kapoor enters the stage. Audience demand for more of Masakalli step from her<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','43', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount43">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','43', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount43">0</span></div></a>
</li>
<li> The next session is with Sonam Kapoor - actor and India's fashion icon<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','42', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount42">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','42', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount42">0</span></div></a>
</li>
<li> Inflation has gone down considerably in the last 16 months: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','41', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount41">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','41', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount41">0</span></div></a>
</li>
<li> Beef is not banned in India, cow slaughter is banned in some states in the country: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','40', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount40">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','40', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount40">0</span></div></a>
</li>
<li> We are doing all as far as ease of doing business is concerned: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','39', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount39">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','39', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount39">0</span></div></a>
</li>
<li> Constitutional and human rights will be fully protected in this country, as already affirmed by our PM: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','38', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount38">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','38', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount38">0</span></div></a>
</li>
<li> GST bill&nbsp;blocked due to Congress: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','37', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount37">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','37', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount37">0</span></div></a>
</li>
<li>&nbsp;I respect Arun shourie. but what he had said about Modi government is absolutely baseless: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','36', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount36">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','36', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount36">0</span></div></a>
</li>
<li> In terms of country's economy - the best is yet to come: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','35', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount35">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','35', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount35">0</span></div></a>
</li>
<li> The start-up ecosystem in India is really buzzing, including e-commerce: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','34', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount34">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','34', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount34">0</span></div></a>
</li>
<li> More money is coming to India, country's economy is booming: Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','33', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount33">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','33', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount33">0</span></div></a>
</li>
<li> I take my father's advice very seriously, says Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','32', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount32">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','32', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount32">0</span></div></a>
</li>
<li> Government to bring in new scheme Startup India soon<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','31', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount31">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','31', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount31">0</span></div></a>
</li>
<li> The next session begins with Minister of State for Finance Jayant Sinha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','30', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount30">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','30', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount30">0</span></div></a>
</li>
<li> OYO is more like Uber of hotels: Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','29', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount29">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','29', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount29">0</span></div></a>
</li>
<li> I have 10 college dropouts working with me: Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','28', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount28">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','28', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount28">0</span></div></a>
</li>
<li> If you want to establish a startup, don't stay with your family, says Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','27', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount27">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','27', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount27">0</span></div></a>
</li>
<li> American entrepreneur Peter Thiel has taught me to be shameless if you have to succeed as an entrepreneur: Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','26', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount26">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','26', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount26">0</span></div></a>
</li>
<li> Facebook CEO Mark&nbsp;Zuckerberg is my key source of inspiration: Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','25', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount25">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','25', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount25">0</span></div></a>
</li>
<li> OYO stands for On Your Own, says Ritesh<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','24', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount24">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','24', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount24">0</span></div></a>
</li>
<li> Ritesh Agarwal, founder and CEO, OYO Rooms takes the stage.&nbsp;At 21, Ritesh is one of the youngest CEOs in India<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','23', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount23">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','23', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount23">0</span></div></a>
</li>
<li> Charismatic Chauhan concludes the session with Masakalli from Delhi6<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','22', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount22">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','22', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount22">0</span></div></a>
</li>
<li> Mohit Chauhan mesmerises the young crowd with Dooba Dooba&nbsp;from Silk Route<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','21', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount21">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','21', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount21">0</span></div></a>
</li>
<li>&nbsp;Schoolgirls join Mohit Chauhan on the stage singing Tum ho paas mere, saath mere<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','20', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount20">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','20', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount20">0</span></div></a>
</li>
<li> I miss being part of a band: Mohit Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','19', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount19">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','19', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount19">0</span></div></a>
</li>
<li> Music has no borders which is most important: Chauhan&nbsp;on cancellation of Ghulam Ali concert<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','18', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount18">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','18', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount18">0</span></div></a>
</li>
<li> Your work is your best PR:&nbsp;Mohit Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','17', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount17">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','17', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount17">0</span></div></a>
</li>
<li> Rock mein bhi romance hota hai, says Mohit&nbsp;Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','16', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount16">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','16', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount16">0</span></div></a>
</li>
<li> I am just a dreamer. I love to recreate. I am just a musician, not a rockstar: Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','15', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount15">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','15', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount15">0</span></div></a>
</li>
<li> Rahman has an amazing sense of humour: Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','14', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount14">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','14', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount14">0</span></div></a>
</li>
<li> Working with AR Rahman has been a different experience: Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','13', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount13">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','13', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount13">0</span></div></a>
</li>
<li> My journey from the mountains to Delhi and Mumbai has been very beautiful: Mohit Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','12', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount12">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','12', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount12">0</span></div></a>
</li>
<li> The first session of Mind Rocks Youth Summit 2015 begins with playback singer&nbsp;Mohit&nbsp;Chauhan<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','11', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount11">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','11', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount11">0</span></div></a>
</li>
<li> Don't be afraid of falling down. Learn to laugh: Bamzai<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','10', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount10">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','10', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount10">0</span></div></a>
</li>
<li> Never be afraid to ask questions: Bamzai<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','9', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount9">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','9', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount9">0</span></div></a>
</li>
<li> Respect your parents, especially your mother - Bamzai's message for the young audience<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','8', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount8">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','8', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount8">0</span></div></a>
</li>
<li> Bigg Boss ke ghar mein apka swagat hai: Kaveree Bamzai, Editor-at-Large, India Today Group<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','7', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount7">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','7', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount7">0</span></div></a>
</li>
<li> Students singing along - Ye Zameen gaa rhi hai, aasman gaa rha<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','6', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount6">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','6', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount6">0</span></div></a>
</li>
<li>&nbsp;Time for some Hindi rock - Mere laundry ka ek bill from the movie&nbsp;Rockstar<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','5', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount5">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','5', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount5">0</span></div></a>
</li>
<li> Loud cheers by&nbsp;the audience as the band plays - I want to break free<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','4', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount4">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','4', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount4">0</span></div></a>
</li>
<li> The action begins with Extronic Souls&nbsp;playing Hanuman Chalisa - the rock version<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','3', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount3">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','3', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount3">0</span></div></a>
</li>
<li> Welcome to India Today Mind Rocks Youth Summit 2015. The day-long celebration of ideas, music and art is to begin shortly<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','2', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount2">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','2', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount2">0</span></div></a>
</li>
<li> Mind Rocks is an event designed especially for the youth. The day-long conference is a forum that allows bright young minds to interact in an open two-way conversation with their icons<div class='clear'></div> 

						<a onClick="javascript:changeRating1('511176','text','1','1', '0', '0')"><div class="thumbup lft"></div><div class="lft"> <span id="upcount1">0</span> </div></a>
						<a onClick="javascript:changeRating1('511176','text','2','1', '0', '0')"><div class="marglft thumbdown lft"></div><div class="lft"> <span id="downcount1">0</span></div></a>
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

