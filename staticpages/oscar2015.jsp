
<!doctype html>
<html>
<head>
<script type='text/javascript'>var _sf_startpt=(new Date()).getTime()</script>
<!-- Begin comScore Tag -->
<script type='text/javascript'>
  var _comscore = _comscore || [];
  _comscore.push({ c1: "2", c2: "8549097" });
  (function() {
    var s = document.createElement("script"), el = document.getElementsByTagName("script")[0];
    s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
    el.parentNode.insertBefore(s, el);
  })();
</script>
<noscript>
  <img src="http://b.scorecardresearch.com/p?c1=2&amp;ac2=8549097&amp;cv=2.0&amp;cj=1"/>
</noscript>
<!-- End comScore Tag -->
<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-795349-17', 'auto');
  ga('send', 'pageview');

</script>
<!-- IndiaToday Group - IndiaToday - RTA script -->
<script type='text/javascript'>
var crtg_nid = '5603';
var crtg_cookiename = 'crtg_rta';
var crtg_varname = 'crtg_content';
function crtg_getCookie(c_name){ var i,x,y,ARRCookies=document.cookie.split(";");for(i=0;i<ARRCookies.length;i++){x=ARRCookies[i].substr(0,ARRCookies[i].indexOf("="));y=ARRCookies[i].substr(ARRCookies[i].indexOf("=")+1);x=x.replace(/^\s+|\s+$/g,"");if(x==c_name){return unescape(y);} }return'';}
var crtg_content = crtg_getCookie(crtg_cookiename);
var crtg_rnd=Math.floor(Math.random()*99999999999);
(function(){
var crtg_url=location.protocol+'//rtax.criteo.com/delivery/rta/rta.js?netId='+escape(crtg_nid);
crtg_url +='&cookieName='+escape(crtg_cookiename);
crtg_url +='&rnd='+crtg_rnd;
crtg_url +='&varName=' + escape(crtg_varname);
var crtg_script=document.createElement('script');crtg_script.type='text/javascript';crtg_script.src=crtg_url;crtg_script.async=true;
if(document.getElementsByTagName("head").length>0)document.getElementsByTagName("head")[0].appendChild(crtg_script);
else if(document.getElementsByTagName("body").length>0)document.getElementsByTagName("body")[0].appendChild(crtg_script);
})();
</script>
<!--FB Claim URL // 22 june 2017-->
<meta property="fb:pages" content="23230437118" />
<!--End FB Claim URL -->

<meta charset="utf-8">
<title>Oscar 2015</title>
<meta name="description" content="All the updates from the biggest award show" />
<meta name="keywords" content="Oscars 2015, Academy Awards 2015, Oscar, Hollywood, Movies, India Today" />
<script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js' ></script>
<!-- disable iPhone inital scale -->
<meta name="viewport" content="width=device-width; initial-scale=1.0">
<link href="/staticpages/css/homepage-new.css" type="text/css" rel="stylesheet" />
<!-- html5.js for IE less than 9 -->
<!--[if lt IE 9]>
	<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
<!-- css3-mediaqueries.js for IE less than 9 -->
<!--[if lt IE 9]>
	<script src="http://css3-mediaqueries-js.googlecode.com/svn/trunk/css3-mediaqueries.js"></script>
<![endif]-->

<link href="/staticpages/css/jquery.bxslider.css" type="text/css" rel="stylesheet" />
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css'>
<link href="/staticpages/css/responsive.css" type="text/css" rel="stylesheet" />
<script type="text/javascript" language="javascript" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/ajaxinclude.js"></script>

<script>
$(document).ready(function(e) {
	var len = $('.belt ul li').length;

	var wd = 666*len;
	$('.video_area ul').css('width', wd);
	var counter = 1;
	 $('.left-arrow').hide();

$('.right-arrow').click(function(){
	if(counter < len )
	{
		 $('.belt ul').animate({
					left : '-=666px'
		 		})

	var li_height = $('.video_area ul li:eq('+counter+')').height();
			$('.video_area ul').css('height', li_height);

		counter += 1;
		$('.left-arrow').show();

	}
	else
	{
	  $('.right-arrow').hide();
	}
});


	$('.left-arrow').click(function(){
		if(counter == 1 )
		{
			 $('.left-arrow').hide();
		}
		else
		{
			 $('.belt ul').animate({
						left : '+=666px'
					})

			$('.right-arrow').show();


			counter -= 1;
			var counters = counter-1;
			//alert(counter);
			var li_heightb = $('.video_area ul li:eq('+counters+')').height();
			$('.video_area ul').css('height', li_heightb);
			//alert(li_heightb);


		}
	});

});
</script>


<style>
body { font: bold 12px/15px roboto; padding:0px; margin:0px; background:#e5e5e5}
.itgd_links {
    background-color: #D8D8D8 !important;
    border-bottom: 1px solid #FFFFFF;
    color: #7A7A7A;
    font: bold 12px/15px roboto;
    margin: 0;
    padding: 0.3%;
    text-align: center;
	overflow:hidden;
}


.itgd_links ul {
    margin: 0 auto;
    padding: 0;
    width: 1003px;
}


.itgd_links ul li.last {
    border-right: medium none;
}
.itgd_links ul li {
    float: left;
    list-style: none outside none;
    padding: 0 9px;
}
.itgd_links a {
    color: #7A7A7A;
    text-decoration: none;
}
#header-outer { background:#000; width:100%; overflow:hidden; height:167px;}
.header-inner { width:998px; margin:0 auto; position:relative}
.clr { clear:both;}
.header-inner img { position:absolute; left:0; top:0; z-index:9;}
.home-icon { position:absolute; z-index:99; top:137px; left:20px;}
#wapper {
    margin: 0 auto;
    width: 998px;
}
.homeleft {
    float: left;
    margin-bottom: 0;
    margin-right: 1.1%;
    width: 67%;
}
.homeright {
    float: right;
    width: 30.5%;
}
.video_area {padding:0px 0px 0px; position:relative; }
.video_area .belt {overflow:hidden; width:666px; margin-bottom:20px; }
.video_area ul { padding:0px; margin:0px 0px 0px 0px; position:relative; overflow:hidden}
.video_area ul li { list-style:none; padding:0px; margin:0px; float:left; position:relative;}
.y-headings { background:#ffce41; padding:7px 10px;  font-size:16px; font-weight:bold; color:#020100; display:inline-block; position:absolute; z-index:10; left:20px;}
.left-arrow {position:absolute; right:58px; top:450px; z-index:10;}
.right-arrow {position:absolute; right:30px; top:450px; z-index:10;}
.slider-content { background:#000; font-weight:normal; padding:10px 10px 20px; color:#ffcc3f; font-size:16px; width:646px; line-height:22px; margin-top:-5px }
.slider-content b { display:block; line-height:26px; color:#ffcc3f; font-size:24px; font-weight:bold}
.slider-content b a { color:#ffcc3f; text-decoration:none;}
.morehead {
    color: #000000;
    font: 900 24px/20px Roboto,sans-serif;
    padding: 5px 10px;
    position: absolute;
    text-transform: uppercase;
	background:#ffce41;
	text-transform:uppercase;
}
.red-dot { border-radius:100%; background:#F00; float:left;  height: 13px;
    margin: 5px 8px 6px 0;
    width: 13px;}
.morehead span {font: 100 24px/20px Roboto,sans-serif;}

.morehead a {
    color: #000;
    padding: 0 5px;
	text-decoration:none;
}
.topstr-list {
    list-style: none outside none;
    padding: 25px 10px 0;
    position: relative;
    transform-style: preserve-3d;
}
.topstr-list li {
    border-bottom: 1px solid #CCCCCC;
    font: 500 15px/18px Roboto,sans-serif;
    list-style: none outside none;
    margin: 8px 0;
    padding-bottom: 7px;
}
.topstr-list li a {
    color: #000000;
    text-decoration: none;
}

.more {
    color: #fff;
    font: 900 16px/20px Roboto,sans-serif;
    padding:3px 7px;
    text-transform: uppercase;
	float:right;
	background:#333333;
}
.more a, .more a:hover {
    color: #fff;
	text-decoration:none;
}
.breaking-news {background: none repeat scroll 0% 0% rgb(255, 255, 255); float: left; margin-bottom: 20px; width:100%;}

.nomination-img { position:relative; z-index:1; float:right}
.centerdiv {
    margin: 0 auto;
    overflow: hidden;
    padding: 0px 0 13px;
    width: 1000px;
}
.colum {
    float: left;
    width: 300px !important;
}
#top_ad{
position:relative !important;
top:1px !important;
}


</style>


</head>

<body>
<div id="top-web" class="itgd_links">
<ul>
<li class="last"><a rel="nofollow" target="_blank" href="http://indiatodaygroup.com/">THE INDIA TODAY GROUP</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.indiatoday.in/">India Today</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.aajtak.in/">Aaj Tak</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.headlinestoday.in/">Headlines Today</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.businesstoday.in/">Business Today</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.menshealthindia.in/">Men's Health</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.wonderwoman.in">Wonder Woman</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.cosmopolitan.in/">Cosmopolitan</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://oyefm.in/">Oye! 104.8FM</a></li>
<li class="last"><a rel="nofollow" class="mainlevel" target="_blank" href="http://travelplus.intoday.in">Travel Plus</a></li>
</ul>
<div class="clr"></div>
</div>

<div id="header-outer">
  <div class="header-inner">
    	<div class="home-icon"><a href="http://indiatoday.intoday.in/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/homeicon.png" width="39" height="30" alt=""></a></div>
       <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/header.png" alt="" width="998" height="167" usemap="#Map1">
       <map name="Map1">
         <area shape="rect" coords="18,10,255,68" href="http://indiatoday.intoday.in/">
       </map>
      </div>
</div>
<div class="centerdiv" >
<div class="clr">&nbsp;</div>
<script type="text/javascript">ajaxinclude("http://indiatoday.intoday.in/chunk_topfive.jsp")</script>
<div id="top_ad">

						<!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT Movie Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1150/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT Movie Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
</div>
</div>

<div class="clear"></div>

<div id="wapper" >
	<div class="homeleft">
    <div class="video_area">
   	  <div class="y-headings">TOP STORIES</div>
      <div class="right-arrow"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/rightarrow.png" width="29" height="26"></div>
      <div class="left-arrow"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/leftarrow.png" width="29" height="26"></div>
		<div class="belt">
          <ul style="height:573px;">

  <li><a href="http://indiatoday.intoday.in/story/john-travolta-scarlett-johansson-kiss-creepy-academy-awards-oscars-2015/1/421492.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/scarlett_650_022815111841.jpg" alt="John Travolta and Scarlett Johansson" title="John Travolta and Scarlett Johansson"  width="666"   border="0" /></a>
   <div class="slider-content"><b><a href="http://indiatoday.intoday.in/story/john-travolta-scarlett-johansson-kiss-creepy-academy-awards-oscars-2015/1/421492.html"  >There is nothing creepy about John Travolta, says Scarlett Johansson</a></b>
  Now Scarlett Johansson has spoken out to defend John Travolta, stating
there's "nothing creepy" about the actor. Although the exchange looked
awkward, but Johansson insists it was a "pleasure", reports
femalefirst.co.uk.</div></li>

  <li><a href="http://indiatoday.intoday.in/story/oscars-2015-lupita-nyongo-pearl-dress-stolen/1/421404.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/collage_650_022715053722.jpg" alt="Lupita Nyong'O" title="Lupita Nyong'O"  width="666"   border="0" /></a>
   <div class="slider-content"><b><a href="http://indiatoday.intoday.in/story/oscars-2015-lupita-nyongo-pearl-dress-stolen/1/421404.html"  >Oscars 2015: Lupita Nyong'o's $1,50,000 red carpet dress stolen</a></b>
  12 years a slave actress Lupita Nyong'o has lost her pearl-decorated dress that she wore to the 87th annual Academy Awards.<br /></div></li>

  <li><a href="http://indiatoday.intoday.in/story/academy-awards-edward-snowden-wikileaks-oscars-treason-laughed-neil-patrick-harris-joke/1/420893.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/collage_650_022515040651.jpg" alt="Edward Snowden (L) and Neil Patrick Harris" title="Edward Snowden (L) and Neil Patrick Harris"  width="666"   border="0" /></a>
   <div class="slider-content"><b><a href="http://indiatoday.intoday.in/story/academy-awards-edward-snowden-wikileaks-oscars-treason-laughed-neil-patrick-harris-joke/1/420893.html"  >Treason Tales: Edward Snowden 'laughed' at Harris' Oscar joke</a></b>
  Edward Snowden, who was the subject of Laura Poitras' Oscar-winning
documentary feature Citizenfour, says he 'laughed' when the Academy
Awards 2015 host Neil Patrick Harris said he could not be here tonight
for some treason.</div></li>
   </ul>
        </div>


        </div>
        <div class="divclear"></div>

        <!-- 4 stories starts -->

		<div class="leftbar"><div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/story/academy-awards-interstellar-visual-effects-vfx-oscars-2015-nasa-tweet-indian-namit-malhotra/1/420843.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/interstellar-story_350_022515010656.jpg" alt="A still from Christopher Nolan's Interstellar" title="A still from Christopher Nolan's Interstellar"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/academy-awards-interstellar-visual-effects-vfx-oscars-2015-nasa-tweet-indian-namit-malhotra/1/420843.html"  >Interstellar Effect: From Oscars to NASA, all in awe of a Mumbaiite</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/academy-awards-interstellar-visual-effects-vfx-oscars-2015-nasa-tweet-indian-namit-malhotra/1/420843.html" ctitle="Interstellar Effect: From Oscars to NASA, all in awe of a Mumbaiite"></div><ul id="420843" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/story/reese-witherspoon-grabs-jennifer-anistons-butt-oscars-2015-academy-awards/1/420696.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/collage_350-2_022415034048.jpg" alt="Collage of Jennifer Aniston and Reese Witherspoon" title="Collage of Jennifer Aniston and Reese Witherspoon"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/reese-witherspoon-grabs-jennifer-anistons-butt-oscars-2015-academy-awards/1/420696.html"  >Oscars 2015: Reese Witherspoon grabs Jennifer Aniston's butt</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/reese-witherspoon-grabs-jennifer-anistons-butt-oscars-2015-academy-awards/1/420696.html" ctitle="Oscars 2015: Reese Witherspoon grabs Jennifer Aniston's butt"></div><ul id="420696" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/story/academy-awards-oscars-2015-neil-patrick-harris-lady-gaga/1/420635.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/harris-story-350_022415113022.jpg" alt="Neil Patrick Harris" title="Neil Patrick Harris"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/academy-awards-oscars-2015-neil-patrick-harris-lady-gaga/1/420635.html"  >Bland show: Oscars viewership drops by 16%, Patrick to be blamed?</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/academy-awards-oscars-2015-neil-patrick-harris-lady-gaga/1/420635.html" ctitle="Bland show: Oscars viewership drops by 16%, Patrick to be blamed?"></div><ul id="420635" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
</div>



<div class="middlebar"><div class="boxcont"><div class="box">

		<div class="posrel"><a href="http://indiatoday.intoday.in/story/oscars-2015-academy-awards-lady-gaga-crystal-gown-1600/1/420717.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/gagastorry_350_022415043406.jpg" alt="Lady Gaga" title="Lady Gaga"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/oscars-2015-academy-awards-lady-gaga-crystal-gown-1600/1/420717.html"  >Oscars 2015: Gaga's crystal embellished gown took 1600 hours to make</a>

<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/oscars-2015-academy-awards-lady-gaga-crystal-gown-1600/1/420717.html" ctitle="Oscars 2015: Gaga's crystal embellished gown took 1600 hours to make"></div><ul id="420717" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>
<div class="boxcont"><div class="box">

		<div class="posrel"><a href="http://indiatoday.intoday.in/story/oscars-2015-lady-gaga-gloves-academy-awards-twitter-meme-jokes/1/420668.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/collage_350_022415013157.jpg" alt="Lady Gaga" title="Lady Gaga"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/oscars-2015-lady-gaga-gloves-academy-awards-twitter-meme-jokes/1/420668.html"  >Oscars 2015: Twitter cracks jokes on Lady Gaga's gloves</a>

<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/oscars-2015-lady-gaga-gloves-academy-awards-twitter-meme-jokes/1/420668.html" ctitle="Oscars 2015: Twitter cracks jokes on Lady Gaga's gloves"></div><ul id="420668" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>
<div class="boxcont"><div class="box">

		<div class="posrel"><a href="http://indiatoday.intoday.in/story/academy-awards-2015-diversity-race-issue-oscars-winners/1/420632.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/neil_350_022415110608.jpg" alt="Neil Patrick Harris on the Oscars 2015 stage" title="Neil Patrick Harris on the Oscars 2015 stage"   border="0" class="images" /></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/academy-awards-2015-diversity-race-issue-oscars-winners/1/420632.html"  >Academy Awards 2015: Diversity storm in the Oscars' teacup</a>

<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/academy-awards-2015-diversity-race-issue-oscars-winners/1/420632.html" ctitle="Academy Awards 2015: Diversity storm in the Oscars' teacup"></div><ul id="420632" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>

</div>

<div class="divclear"></div>
 <!-- 4 stories ends -->
  <!-- 2 galleries start -->
<div class="leftbar">
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/lupita-nyongo-rosamund-scarlett-johanson-red-carpet-best-dressed/1/14251.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage6_350_022315112302.jpg" alt="Oscars 2015: Red carpet favourites" title="Oscars 2015: Red carpet favourites"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/lupita-nyongo-rosamund-scarlett-johanson-red-carpet-best-dressed/1/14251.html" >Oscars 2015: Red carpet favourites</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/lupita-nyongo-rosamund-scarlett-johanson-red-carpet-best-dressed/1/14251.html" ctitle="Oscars 2015: Red carpet favourites"></div><ul id="14251" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-meet-the-winners-jk-simmons-ida-whiplash/1/14249.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage5_350_022315105413.jpg" alt="And the Oscar goes to: Winners' list" title="And the Oscar goes to: Winners' list"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-meet-the-winners-jk-simmons-ida-whiplash/1/14249.html" >And the Oscar goes to: Winners' list</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/oscars-2015-meet-the-winners-jk-simmons-ida-whiplash/1/14249.html" ctitle="And the Oscar goes to: Winners' list"></div><ul id="14249" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>

</div>
<div class="middlebar">
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-neil-patrick-harris-strips-underpants-birdman-los-angeles/1/14250.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/neil-thumb_350_022315085928.jpg" alt="Oscars 2015: Neil Patrick Harris' undies moment and more" title="Oscars 2015: Neil Patrick Harris' undies moment and more"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-neil-patrick-harris-strips-underpants-birdman-los-angeles/1/14250.html" >Oscars 2015: Neil Patrick Harris' undies moment and more</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/oscars-2015-neil-patrick-harris-strips-underpants-birdman-los-angeles/1/14250.html" ctitle="Oscars 2015: Neil Patrick Harris' undies moment and more"></div><ul id="14250" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-red-carpet-arrivals/1/14248.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage_350_022315061645.jpg" alt="Oscars 2015: Dazzling Red Carpet arrivals" title="Oscars 2015: Dazzling Red Carpet arrivals"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/oscars-2015-red-carpet-arrivals/1/14248.html" >Oscars 2015: Dazzling Red Carpet arrivals</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/oscars-2015-red-carpet-arrivals/1/14248.html" ctitle="Oscars 2015: Dazzling Red Carpet arrivals"></div><ul id="14248" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>

</div><div class="divclear"></div>
 <!-- 2 galleries end -->


  <!-- 2 static cards start -->
<!-- <div class="leftbar">
 <div class="boxcont"><div class="box">

	<div class="posrel"><a href="http://indiatoday.intoday.in/story/ben-afflecks-argo-bags-best-film-oscar/1/251688.html"><img border="0" class="images" title="Ben Affleck" alt="Ben Affleck" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/ben-affleck_350_022513054618.jpg" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/ben-affleck_350_022513054618.jpg" style="display: inline;"></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/story/ben-afflecks-argo-bags-best-film-oscar/1/251688.html">Ben Affleck's Argo bags best film Oscar</a>

<div class="clear"></div>
<div class="share-story"><div ctitle="Ben Affleck's Argo bags best film Oscar" url="/story/ben-afflecks-argo-bags-best-film-oscar/1/251688.html" class="share-icon"></div><ul style="border:none" id="8807"></ul></div>
</div></div></div>
 </div>
<div class="middlebar">
<div class="boxcont"><div class="box">
	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/best-and-worst-dressed-at-the-oscars-2013/1/8807.html"><img border="0" class="images" title="Oscars red carpet: Hits and misses" alt="Oscars red carpet: Hits and misses" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage_350_022613045530.jpg" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage_350_022613045530.jpg" style="display: inline;"><span class="pmedia-image-icon sp_bg"></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/best-and-worst-dressed-at-the-oscars-2013/1/8807.html">Oscars red carpet: Hits and misses</a>
<div class="clear"></div>
<div class="share-story"><div ctitle="Oscars red carpet: Hits and misses" url="/gallery/best-and-worst-dressed-at-the-oscars-2013/1/8807.html" class="share-icon"></div><ul style="border:none" id="8807"></ul></div>
</div></div></div>
</div><div class="divclear"></div>-->
 <!-- 2 static cards end -->
</div>

  <div class="homeright">
  <div class="colum">
   <div class="breaking-news">
    				<!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT Movie Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1152/1137"; var zflag_sid="2"; var zflag_width="300"; var zflag_height="250"; var zflag_sz="9";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT Movie Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
  </div>
  </div>

    <div class="colum">
    	<div class="nomination-img">
        <a href="http://indiatoday.intoday.in/oscar2014.jsp"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/banners/it/blast-from-past-2014.jpg" border="0"  width="299" ></a>

        </div>
    </div>


     <div class="colum" style="margin-top:20px;">
    	<div class="nomination-img">
         <a href="http://indiatoday.intoday.in/gallery/oscar-awards-best-dressed-women-hollywood/1/11277.html">
        <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/banners/it/best-dressed-women-hollywood.jpg" width="299"  border="0"> </a>

        </div>
    </div>





   <div class="colum" style="margin-top:20px;">
   <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/twitr.jpg" width="299" height="54">

<div style="width:277px; border:11px solid #31cbfd; height:600px; background:#fff; margin:-3px 0 20px 0;">

            <a class="twitter-timeline"  href="https://twitter.com/hashtag/Oscars2015" data-widget-id="568310377281114112">#Oscars2015 Tweets</a>
            <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>


 	</div>
    </div>

  </div>
<div class="clr">&nbsp;</div>




<footer style="margin:0px auto;" >
<div id="footer1" style="display:block !important">
	<iframe width="100%" scrolling="no" height="455" frameborder="0" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/it-footer2015.html"></iframe>
    </div>
  </div>
  </div>
</footer>


</div>
</div>
<style>
#leftrightads { height: 0; position: absolute; top: 86px; width: 1020px;}
.leftad, .rightad{position: absolute; top: 160px;}
#leftrightads .leftad{left: -130px}
#leftrightads .rightad{right: 12px}
#leftrightads .leftad {
    left: -165px;
    top:75px;
}
#leftrightads .rightad {
    left: 1005px;
    top:75px;
}
.fixed {
    position: fixed!Important;
    top: 50px !Important;
}
.fixed-r {
    position: fixed!Important;
    top: 50px !Important;
}
.footertag .nav ul li a{ font-size:12px;}
</style>

<script type="text/javascript">
$(function () {
var msie6 = $.browser == 'msie' && $.browser.version < 7;
if (!msie6) {
var top = $('.leftad').offset().top - parseFloat($('.leftad').css('margin-top').replace(/auto/, 0));
$(window).scroll(function (event) {
var y = $(this).scrollTop();
if (y >= top) {
$('.leftad a').addClass('fixed');
} else {
$('.leftad a').removeClass('fixed');
}
});
}
});
            </script>

            <script type="text/javascript">
$(function () {
var msie6 = $.browser == 'msie' && $.browser.version < 7;
if (!msie6) {
var top = $('.rightad').offset().top - parseFloat($('.rightad').css('margin-top').replace(/auto/, 0));
$(window).scroll(function (event) {
var y = $(this).scrollTop();
if (y >= top) {
$('.rightad a').addClass('fixed-r');
} else {
$('.rightad a').removeClass('fixed-r');
}
});
}
});
            </script>


<div id="leftrightads">
            <div style="left:-170px;" class="leftad">

<!-- Javascript tag: -->
<!-- begin ZEDO for channel:  IT Homepage SkyScraper Ex Left , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1142/1137"; var zflag_sid="2"; var zflag_width="160"; var zflag_height="600"; var zflag_sz="7";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT Homepage SkyScraper Ex Left , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->

             </div>

<div class="rightad">
           <!-- Javascript tag: -->
<!-- begin ZEDO for channel:  IT Homepage SkyScraper Ex right , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1143/1137"; var zflag_sid="2"; var zflag_width="160"; var zflag_height="600"; var zflag_sz="7";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT Homepage SkyScraper Ex Left , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->

             </div>

</div>




<script>
winscreen();
$(window).resize(function() {
	winscreen();
});

function winscreen(){
if (document.body.offsetWidth>=1250) {
		if (document.getElementById("leftrightads") != null || document.getElementById("leftrightads") != undefined)
		{document.getElementById("leftrightads").style.display="block";
			var lft = ((document.body.offsetWidth-1000)/2);
			document.getElementById("leftrightads").style.left=lft+'px';
		}
	}
	else {
		if (document.getElementById("leftrightads") != null || document.getElementById("leftrightads") != undefined){
		document.getElementById("leftrightads").style.display="none"; }}
}
</script>
<script>
	var myUserAgent = navigator.userAgent.toLowerCase();
	if(myUserAgent.match('ipad')) {
		   $('.leftad, .rightad').remove();
		}
</script>

<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/funalytics/jquery.bxslider.min.js"></script>
<script src="/staticpages/js/jquery.lazyload.js" type="text/javascript" charset="utf-8"></script>
<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/javascript.js" type="text/javascript" charset="utf-8"></script>
<script type='text/javascript' src='/staticpages/js/copypaste_common.js' ></script>
<script type="text/javascript" >$(document).ready(function(){insertCustomSymbols();copypasteinit();});</script>
<img height="1" width="1" src="http://s3-pixel.c1exchange.com/pubpixel/82493" style="display:none;">
<script src="http://tags.crwdcntrl.net/c/9709/cc_af.js"></script>

</div>

</div>
<div class="clr">&nbsp;</div>

<script type='text/javascript' src='http://apis.google.com/js/plusone.js'></script>
</body>
</html>
