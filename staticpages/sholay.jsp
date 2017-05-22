<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>15 Sholay characters & their best lines</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="description" content="Sholay's characters are etched in our memories, thanks to some brilliant acting and incredible dialogues. But some of them were silent and yet played their part in making the movie a classic." />
<meta name="keywords" content="sholay, jai, veeru, thakur, gabbar, dhanno, basanti, ramesh sippy" />

<meta property="og:title" content="15 Sholay characters & their best lines">
<meta property="og:image" content="http://media2.intoday.in/indiatoday/images/stories/2013aug/stargraph-sholey_300x350_081013043742.jpg">
<meta property="og:url" content="http://indiatoday.intoday.in/sholay.jsp">
<meta property="og:description" content="Sholay's characters are etched in our memories, thanks to some brilliant acting and incredible dialogues. But some of them were silent and yet played their part in making the movie a classic.">

<link rel="image_src" href="http://media2.intoday.in/indiatoday/images/stories/2013aug/stargraph-sholey_300x350_081013043742.jpg" />

<script type="text/javascript" language="javascript" src="http://indiatoday.intoday.in/js/ajaxinclude.js"></script>
<link type="text/css" rel="stylesheet" href="http://media2.intoday.in/microsites/specials/sholay/stylesheet.css">
 <style>
   .image_over_text{font:15px/16px arial; position:absolute; cursor:pointer; z-index:22222;}
   #lightbox {z-index: 55555555!important;}
   ul, li { margin:0; padding:0;}
   </style>
<script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js' ></script>
<script>
	$(document).ready(function(){
		$('.lb-close').click(function(){
			$("#lightboxOverlay").fadeOut(500);
			$('.lb-container .movie_name').html('');
			$('.lb-container .movie_text').html('');
			$('.lb-container .movie_img').html('');
			$("#lightbox").fadeOut(500);
			document.getElementById("maincontainer").style.backgroundColor="";
		document.getElementById("maincontainer").style.opacity="1";	
		document.getElementById("mainimg").style.opacity="1";	
		document.getElementById("navigation_nw").style.opacity="1";
		});
		$('#Map > area').mouseover(function(){
			var img = $(this).attr('img');
			img = img.replace('.jpg','');
			$('#'+img).css("font-weight","bold");
		});
		$('#Map > area').mouseout(function(){
			var img = $(this).attr('img');
			img = img.replace('.jpg','');
			$('#'+img).css("font-weight","normal");
		});
		
		$('.image_over_text').mouseover(function(){
			$(this).css("font-weight","bold");
		});
		$('.image_over_text').mouseout(function(){
			$(this).css("font-weight","normal");
		});
		
		$('#Map > area').click(function(){
			callpopup(this);
		});
		
		$('.image_over_text').click(function(){
			var gett = $("#Map > area[img='"+$(this).attr('id')+".jpg']");
			callpopup(gett);
		});
	});
	
	function callpopup(thisss)
	{
		var docwidth = $(document).width();
		var docheight = $(document).height();
		
		if(docwidth>500) {
			var leftmargin = ((parseInt(docwidth)-440)/2);
		} else {
			var leftmargin  = 0;
		}
		var img = $(thisss).attr('img');
		var head = $(thisss).attr('head');
		var textmovie = $(thisss).attr('textmovie');
		var topm = 25;
		var leftm = 36.5;
		
		var coords = $(thisss).attr('coords');
		coords = coords.split(',');
		
		if(coords[0]>570) {
			coords[0] = 570;
		}
		if(leftm!='') {
			coords[0] = leftm;
		}
		//document.getElementById("maincontainer").className="black_overlay";
		document.getElementById("maincontainer").style.backgroundColor="#000000";
		document.getElementById("maincontainer").style.opacity="0.8";	
		document.getElementById("mainimg").style.opacity="0.5";	
		document.getElementById("navigation_nw").style.opacity="0.5";	//$("#lightboxOverlay").fadeIn(500).css({height:docheight+'px',width:docwidth+'px'});
		//alert(topm);
		$("#lightbox").fadeIn(1500).css({left:coords[0]+'%',top:topm+'%',width:'400px', height:'225px'});
		if(head.match('Black')) {
			$("#lightbox").css("width","420px");
			$('.lb-container .movie_img').css("width","100%");
			$('.lb-container .movie_box').css("width","100%");
		} else {
			$('.lb-container .movie_img').css("width","39%");
			$('.lb-container .movie_box').css("width","55%");
		}
		$('.lb-container .movie_name').html(head);
		$('.lb-container .movie_text').html('"'+textmovie+'"');
		$('.lb-container .movie_img').html('<img src="http://media2.intoday.in/microsites/specials/sholay/'+img+'" />');
	}
</script>

<style>
.frm-share {float: right;height: 30px;position: relative;width: 150px; margin-top:5px;}
.socialcont { position: absolute;right: 0;top: 0;width: 120px;}
.socialdiv {bottom: 0;position: relative;right: 0;}
.email {background-position: -304px -8px;}
.fb, .tw, .email { background-image: url("http://specials.indiatoday.com/words-of-love/sprite.png");background-repeat: no-repeat;cursor: pointer;height: 32px;width: 36px;}
.imgs {margin: 0 2px;}
.lft {float: left;}
.fb {background-position: -224px -8px;}
.tw {background-position: -264px -8px;}
.mapped_image {left:0;position:absolute; width:1000px; height:1065px; display:none; top:0; margin:0px;}
.mapped_image a {color:#d71920; text-decoration:none; font-weight:bold; font-size:20px; float:right; margin-right:10px;}
.mapped_image a:hover {color:#0072bc; text-decoration:none; font-weight:bold}
.mapped_fri {left:0;width:1000px; height:1100px;top:0; margin:0px;}
.posrelv {position:relative;}
.commentboxdiv {text-align: left; width: 660px; margin: 0px auto;}
.lb-container {width:95% !important;}
#lightbox { position:fixed !important}
.mainlink {font:bold 16px/20px arial; color:#000; text-align:right; margin-bottom:10px;}
.mainlink a {color:#000; text-decoration:none}
.mainlink a:hover {text-decoration:underline}
</style>
</head>

<body>
<script>
if((navigator.userAgent.match(/iPhone/i)) || (navigator.userAgent.match(/iPod/i)) || (navigator.userAgent.match(/webOS/i)) || (navigator.userAgent.match(/BlackBerry/i)) || (navigator.userAgent.match(/Android/i))) {

if (document.cookie.indexOf("iphone_redirect=false") == -1) window.location = "http://m.indiatoday.in/sholay.jsp";
}
</script>
<div id="lightboxOverlay" style="display: none;"></div>
                	    <div id="lightbox" style="display: none; top: 10%;left: 0px;">
                	      <div class="lb-dataContainer" style="display: block; width: 100%;">
                	        <div class="lb-data">
                	          <div class="lb-closeContainer"> <a class="lb-close"></a></div>
              	          </div>
              	        </div>
                	      <div class="lb-outerContainer" style="width: 100%; height: auto;">
                	        <div class="lb-container">
                	          <div class="movie_img"></div>
                	          <div class="movie_box">
                	            <div class="movie_text"></div>
                                <div class="movie_name"></div>
                	            
              	            </div>
                            
              	          </div>
              	        </div>
              	      </div>
<div class="maincontainer" id="maincontainer">
<div id="wholecontent">	
<header>
	


<script src="//pagead2.googlesyndication.com/pagead/js/google_top_exp.js"></script>
<link rel="stylesheet" href="http://indiatoday.intoday.in/css/autosuggest_inquisitor.css" type="text/css" media="screen" charset="utf-8" />

<link rel="shortcut icon" href="http://indiatoday.intoday.in/images/favicon.ico" />
<script type="text/javascript" language="javascript" src="http://indiatoday.intoday.in/js/ajaxinclude.js"></script>
<!--[if lte IE 7]><link rel="stylesheet" type="text/css" href="css/ie.css" media="screen" /><![endif]-->
<link href="http://indiatoday.intoday.in/css/common.css" rel="stylesheet" type="text/css">
<!-- The below script Makes IE understand the new html5 tags are there and applies our CSS to it --><!--[if IE]><script src="http://indiatoday.intoday.in/js/html5.js"></script><![endif]-->
<div id="itgd_links">
<ul>
<li class="last">
<a rel="nofollow" target="_blank" href="http://indiatodaygroup.com/">INDIA TODAY GROUP :</a></li>
<!--<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.intoday.in/">InToday</a></li>-->
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.indiatoday.in/">India Today</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.aajtak.in/">Aaj Tak</a></li>
<!--<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.headlinestoday.in/">Headlines Today</a></li>-->
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.businesstoday.in/">Business Today</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.menshealthindia.in/">Men's Health</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.wonderwoman.in">Wonder Woman</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.cosmopolitan.in/">Cosmopolitan</a></li>
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://oyefm.in/">Oye! 104.8FM</a></li>
<li class="last"><a rel="nofollow" class="mainlevel" target="_blank" href="http://travelplus.intoday.in">Travel Plus</a></li>
</ul>
<div class="clr"></div>
</div>

<!--<meta http-equiv="X-UA-Compatible" content="IE=EmulateIE7" />-->

<div class="topbg">
		<div id="lefttop">
			
	<script type="text/javascript">ajaxinclude("http://indiatoday.intoday.in/updatedtime_chunk.jsp")</script>


<div id="logo"><a href="http://indiatoday.intoday.in/"><img src="http://indiatoday.intoday.in/images/it.png" alt="India Today" width="262" height="80" title="India Today"></a></div>
			
			<div id="sitelogo">
        		<div>In Association With</div>
	        		 <span class="mail-today"> <a href="http://mailtoday.in/" target="_blank"><img src="http://media2.intoday.in/indiatoday/images/mailtoday.gif" alt="" /></a></span>
				    <span class="business-today"><a href="http://www.businesstoday.in/" target="_blank">Business Today</a></span>
				    <span class="in-today"><a href="http://indiatoday.intoday.in/" target="_blank">India Today</a></span>
				    <span class="aajtak"><a href="http://www.aajtak.in/" target="_blank">AajTak</a></span>
				    <span class="headlines-today"><a href="http://www.headlinestoday.in/" target="_blank">Headlines Today</a></span>
	                <div class="clear"></div>
            </div>
        </div>
        <div id="righttop" class="t-a-p">
        <div class="ad">ADVERTISEMENT</div>
            <div id="ad">
				
			<div class="loadingad" >
						<!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT ROS Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1216/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT ROS Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
			</div>

			</div>
<div class="clear"></div>
		</div>
        <div class="clear"></div>
        </div>
		<div class="clear"></div>
		<nav>
<div id="navigation_nw">
<div id="topmenu_link">
	<ul class="dropdown zindex">
        	<li><a href="http://indiatoday.intoday.in/" >Home</a></li>
            <li>
			
				<a href="http://indiatoday.intoday.in/news.html">News</a>
				
			</li>
            <li><a href="http://indiatoday.intoday.in/section/114/1/india.html" >India</a></li>
            <li><a href="http://indiatoday.intoday.in/videos">Videos</a></li>
            <li><a href="http://indiatoday.intoday.in/galleries">Photos</a></li>
            <li><a href="http://indiatoday.intoday.in/section/214/1/cricket.html" >Cricket</a></li>
            <li><a href="http://indiatoday.intoday.in/section/67/1/movies.html" >Movies</a></li>
			<li><a href="http://indiatoday.intoday.in/section/230/1/auto.html">Auto</a></li>
            
            <!--<li><a href="section/84/1/sports.html" >Sport</a></li>-->
            <li><a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html" >Lifestyle</a></li>
            <li><a href="javascript:void(0);">Events</a>
			<ul class="sub_menu">
        			<li><a target="_blank" href="http://indiatodayconclave.com" rel="nofollow">India Today Conclave</a></li>
					<li><a target="_blank" href="http://indiatoday.intoday.in/youthsummit" rel="nofollow">Youth Summit</a></li>
					<li><a target="_blank" href="http://indiatoday.intoday.in/womansummit" rel="nofollow">Woman Summit</a></li>
			</ul>
			</li>
        	
        	<li><a href="#">Magazine</a>
        		<ul class="sub_menu">
        			<li><a href="http://indiatoday.intoday.in/section/30/1/cover-story.html" rel="nofollow">Cover Story</a></li>
					<li><a href="http://indiatoday.intoday.in/section/36/1/nation.html" rel="nofollow">Nation</a></li>
					<li><a href="http://indiatoday.intoday.in/section/21/1/states.html" rel="nofollow">States</a></li>
					<li><a href="http://indiatoday.intoday.in/section/34/1/economy.html" rel="nofollow">Economy</a></li>
					<li><a href="http://indiatoday.intoday.in/section/146/1/glass-house.html" rel="nofollow">Glass House</a></li>
					<li><a href="http://indiatoday.intoday.in/section/41/1/sport.html" rel="nofollow">Sport</a></li>
					<li><a href="http://indiatoday.intoday.in/section/145/1/up-front.html" rel="nofollow">Up Front</a></li>
					<li><a href="http://indiatoday.intoday.in/section/141/1/profile.html" rel="nofollow">Profile</a></li>
					<li><a href="http://indiatoday.intoday.in/section/144/1/byword.html" rel="nofollow">Byword</a></li>
					<li><a href="http://indiatoday.intoday.in/section/149/1/glossary.html" rel="nofollow">Glossary</a></li>
					<li class="seled"><a href="http://indiatoday.intoday.in/archive" rel="nofollow">Archives</a></li>
					<li><a href="#">Supplements</a>
        		<ul>
        			<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=16" rel="nofollow">Home</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=17" rel="nofollow">Aspire</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=28" rel="nofollow">Spice</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=18" rel="nofollow">Woman</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=19" rel="nofollow">Simply Delhi</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=30" rel="nofollow">Simply Chennai</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=31" rel="nofollow">Simply Gujarati</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=32" rel="nofollow">Simply Kolkata</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=33" rel="nofollow">Simply Punjabi</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=34" rel="nofollow">Simply Mumbai</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=35" rel="nofollow">Simply Bangalore</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=358" rel="nofollow">Simply Hyderabad</a></li>
					<li><a href="http://indiatoday.intoday.in/Simply?secId=20&amp;catId=359" rel="nofollow">Simply Pune</a></li>
        		</ul>
        	</li>
        		</ul>
        	</li>
        	<li class="last"><a href="http://indiatoday.intoday.in/shoppingit.html" target="_blank" rel="nofollow">Shopping</a></li>
        	<li><a href="http://indiatoday.intoday.in/site/livetv.jsp" style="color:#DB1820">Live TV</a></li>
        </ul>
	</div>
</div>
<div class="clear"></div>     
</nav>
 <!-- Begin comScore Tag -->
<script>
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
	<script type="text/javascript" >
	var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
	document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
	</script>
	<script type="text/javascript">
	try {
	
	
	var pageTracker = _gat._getTracker("UA-795349-17");
	pageTracker._trackPageview();
	pageTracker._trackPageLoadTime();
	} catch(err) {}</script>
<div class="clear"></div>

<div class="centerdiv">



<!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT RichMedia Ros , publisher: India Today , Ad Dimension: Billboard 1x1 - 1 x 1 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2044/1137"; var zflag_sid="2"; var zflag_width="1"; var zflag_height="1"; var zflag_sz="89";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT RichMedia Ros , publisher: India Today , Ad Dimension: Billboard 1x1 - 1 x 1 -->


</div>
<div class="clear" style="margin-bottom:10px;"></div>







</header>

<div class="frm-share rght">
        <div class="socialcont">
            <div class="socialdiv">
                <a href="javascript:void('0');" onclick='javascript:window.open("http://indiatoday.intoday.in/content_Email.jsp?email=0&title=15 Sholay characters & their best lines&URL=http://indiatoday.intoday.in/sholay.jsp","window", "status=no,resize=no,toolbar=no,scrollbars=no,width=478,height=390"); event.returnValue=false; return false;' title="Email" target="_new" rel="nofollow"><span class="imgs email lft"></span></a>
                <a href="http://www.facebook.com/sharer/sharer.php?p[url]=http://indiatoday.intoday.in/sholay.jsp&p[title]=15 Sholay characters & their best lines&s=100&p[summary]=Sholay has everything: action, comedy, romance and tragedy. But, what makes the movie an outstanding watch are the iconic dialogues & the multi-layered characterisation. See what makes these characters so special. CLICK on the images to read their most memorable  lines.&p[images][0]=http://media2.intoday.in/indiatoday/images/stories/2013aug/stargraph-sholey_300x350_081013043742.jpg" title="Facebook" target="_new" rel="nofollow"><span class="imgs fb lft"></span></a>
                <a href="http://twitter.com/?status=15 Sholay characters & their best lines%20http://indiatoday.intoday.in/sholay.jsp%20via%20%40indiatoday" title="Twitter" target="_new" rel="nofollow"><span class="imgs tw lft"></span></a>
            </div>
        </div>
    
    </div>
<section>

<div class="newtext" style="margin-top:0px;">
<div style="font:bold 36px arial black, arial; color:#000;text-transform: uppercase; margin-bottom:5px;">15 Sholay characters & their best lines
</div>
<div style="font:bold 16px arial; color:#000; margin-bottom:10px; text-align:left">Sholay has everything: action, comedy, romance and tragedy. But, what makes the movie an outstanding watch are the iconic dialogues & the multi-layered characterisation. See what makes these characters so special. <br /><span style="color:#d71920;">CLICK</span> on the images to read their most memorable  lines.</div>
                	<div align="center">
                	<div id="wrapper2" style="width:1000px; margin:0 auto 10px auto; position:relative; overflow:hidden; border-bottom:1px solid #ccc;"> <img src="http://media2.intoday.in/microsites/specials/sholay/StarGraph-Sholay.jpg" border="0" usemap="#Map" class="Map" id="mainimg" />
                	    
                	    <map name="Map" id="Map">
                	      <area shape="poly" coords="181,172,158,104,167,99,205,122,205,75,228,60,295,78,297,94,252,109,266,113,279,115,288,131,302,146,310,166,317,174" img="bigb.jpg" head="Jai (Amitabh)" textmovie="Tumhara naam kya hai, Basanti?" href="javascript:void(0);">
                	      <area shape="poly" coords="380,201,463,198,466,151,486,150,486,137,476,132,465,130,463,123,466,111,470,100,463,95,449,102,449,93,448,61,435,55,425,52,411,56,407,73,387,117,379,131,376,153" img="gabbar.jpg" head="Gabbar (Amjad Khan)" textmovie="Kitne aadami the?" href="javascript:void(0);">
                	      <area shape="poly" coords="53,295,163,295,154,264,225,251,226,236,139,224,132,195,128,180,118,174,107,175,99,185,84,215,66,205,54,205" img="thakur.jpg" head="Thakur (Sanjeev Kapoor)" textmovie="Jao ja ker kah do Gabbar se, Ramgarhwaalon ne paagal kutton ke saamne roti daalna bandh kar diya hai." href="javascript:void(0);">
                	      <area shape="poly" coords="146,378,162,364,178,369,189,390,192,413,182,427,176,440,189,451,202,456,212,467,220,481,218,497,208,500,178,500,145,500,116,499,98,499,92,498,97,480,103,457,63,458,48,429,62,393,115,401" href="javascript:void(0);" img="ak-hangal.jpg"  head="Rahim Chacha (AK Hangal)" textmovie="Itna sannata kyon hai bhai?">
                	      <area shape="poly" coords="290,373,276,382,273,398,277,408,272,415,265,422,258,427,245,418,240,428,249,444,255,452,254,462,279,462,299,459,302,452,303,424,308,395,390,385,379,368" img="ramlal_sholay.jpg" head="Ramlal (Satyen  Kappu)" textmovie="Bahut dukhiyari ladki hai, beta." href="javascript:void(0);">
                	      <area shape="poly" coords="277,498,374,501,360,492,348,488,425,481,435,461,378,456,348,436,341,419,326,413,319,414,307,417,302,459,271,469"  href="javascript:void(0);" img="ahmed.jpg" head="Ahmed (Sachin)" textmovie="Mujhe jaane dijiye.">
                	      <area shape="circle" coords="580,277,86"  href="javascript:void(0);" img="dhanno.jpg" head="Dhanno" textmovie="Neigh neigh">
                	      <area shape="rect" coords="687,214,851,335" img="kaalia.jpg" head="Kaalia (Viju Khote)" textmovie="Sardar, maine aapka namak khaya hai." href="javascript:void(0);">
                	      <area shape="rect" coords="828,51,939,198" img="veeru.jpg" head="Veeru (Dharmendra)" textmovie="Kutte, main tera khoon pee jaaonga." href="javascript:void(0);">
                	      <area shape="rect" coords="634,509,830,631"  href="javascript:void(0);" img="mausi.jpg" head="Mausi (Leela Mishra)" textmovie="Chahe sau buraiyan hai tumhare dost mein, phir bhi tumhare munh se uske liye taarifein hi nikalti hain.">
                	      <area shape="rect" coords="654,646,798,819"  href="javascript:void(0);" img="basanti.jpg" head="Basanti (Hema Malini)" textmovie="Bhaag Dhanno bhaag, aaj teri Basanti ki izzat ka sawal hai.">
                	      <area shape="rect" coords="47,655,195,842"  href="javascript:void(0);" img="jaya.jpg" head="Radha (Jaya Bachchan)" textmovie="Holi hai bhai, holi hai. Bura na mano, holi hai.">
                	      <area shape="poly" coords="854,389,832,374,802,374,790,381,779,392,767,401,733,399,694,397,678,399,683,421,686,435,730,439,765,439,779,451,800,464,821,468,829,468" href="javascript:void(0);" img="soormabhopali.jpg" head="Soorma Bhopali (Jagdeep)"  textmovie="Pair pakad ke dono ro diye ki Soorma bhai maaf kar do.">
                	      <area shape="poly" coords="827,499,939,497,950,480,939,459,929,443,921,424,913,419,916,406,954,404,958,388,929,381,908,381,894,370,875,366,862,368,858,378"  href="javascript:void(0);" img="jailor.jpg" head="Jailor (Asrani)" textmovie="Aadhe idhar jaao, aadhe udhar jaao, baaki mere peeche aao.">
                	      <area shape="poly" coords="514,492,648,490,661,483,710,486,732,485,728,466,668,463,649,452,643,417,646,394,606,392,540,394,518,394,511,394" href="javascript:void(0);" img="samba.jpg" head="Sambha (MacMohan)" textmovie="Poorey pachchaas hazaar">
              	      </map>
                	   
              	    </div>
                	  
              	    </div>
                    
                    <div class="mainlink"><a href="http://indiatoday.intoday.in/sholay-slide.jsp">Also see: 6 iconic non-human characters from Sholay &raquo;</a></div>
            	</div>

<div class="clear"></div>

      <div class="commentboxdiv">
      <script type="text/javascript">ajaxinclude("http://indiatoday.intoday.in/commentbox/comment_box.jsp?sId=298911&ScfUrl=&StoryTitle=6 iconic non-human, 'characters' from Sholay&message=&website=indiatoday&content_type=poll&storytemplate=site")</script>
     </div>
     
        
</section>

<div class="fotborder"><footer><script type="text/javascript">ajaxinclude("http://indiatoday.intoday.in/chunk_social_strip.html")</script>
<div class="clear"></div>
<div class="footband">
<ul>
	<li><a href="http://indiatoday.intoday.in/">Home</a></li>
	<li><a href="http://indiatoday.intoday.in/news.html">News</a></li>
	<li><a href="http://indiatoday.intoday.in/section/114/1/india.html">India</a></li>
	<li><a href="http://indiatoday.intoday.in/videos">Videos</a></li>
	<li><a href="http://indiatoday.intoday.in/galleries">Photos</a></li>
	<li><a href="http://indiatoday.intoday.in/section/67/1/movies.html">Movies</a></li>
	<li><a href="http://indiatoday.intoday.in/section/84/1/sports.html">Sport</a></li>
	<li><a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html">Lifestyle</a></li>
	<li><a href="http://indiatoday.intoday.in/section/20/1/supplements.html">Supplements</a></li>
	<li><a href="http://indiatoday.intoday.in/calendar/0/2012/magazine.html">Magazine</a></li>
	<li><a href="http://indiatoday.intoday.in/games/game.php">Games</a></li>
	<li><a rel="nofollow" target="_blank" href="http://indiatoday.freeads.in/">Classifieds</a></li>
	<li class="last"><a target="_blank" href="http://www.bagittoday.com/" rel="nofollow">Shopping</a></li>
</ul>
<div class="clear"></div>   
</div>
<div class="bottomad">




			<div class="loadingad" >
						<!-- Javascript tag: -->
				<!-- begin ZEDO for channel: IT ROS Bottomnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
				<script language="JavaScript">
				var zflag_nid="821"; var zflag_cid="1217/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
				</script>
				<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
				<!-- end ZEDO for channel: IT ROS Bottomnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
			</div>


<!-- Affinity In-Footer Site Code Starts Here (Required) -->
        <div id="af-display-unit" style="display:none">
        <script type="text/javascript" language="javascript">
                ;(function(){
                var v = {}; 
                v.pubid = 'saw31';
                v.aduid = '372';
                v.phR= Math.floor(Math.random()*100*(new Date().getTime()/1000));v.u = location.href;
                v.ru = document.referrer;v.scrRes = screen.width+'x'+screen.height;
                var servar = function(obj){var str=[];for(var p in obj) str.push(p + "=" + encodeURIComponent(obj[p]));return str.join("&");}
                var url = 'http://tbn.ph.affinity.com/init/i.js?'+servar(v);
                document.write(unescape("%3Cscript src='") + url + unescape("' type='text/javascript'%3E%3C/script%3E")); })();
        </script>
        </div>
<!-- Affinity In-Footer Site Code Ends Here -->



</div>
<div id="footer">
               <iframe width="990" scrolling="no" height="165" frameborder="0" src="http://media2.intoday.in/microsites/common/common_it_footer.html"></iframe>
            </div>
            
    <div style="display:none;" class="bott-popup" id="videopopup">
  <div class="bott-popup-inn" id="userreg">
    <div class="bott-popinn"><a id="cancelpopup" href="javascript:void(0);"><img border="0"  src="http://media2.intoday.in/microsites/specials/close.png"></a></div>
        <div class="bottspecinn"></div>  
    <div id="enrollfrm">
        	
    </div>
    </div>
</div>          
        
        
        
       
  <script type='text/javascript' src='http://media2.intoday.in/indiatoday/js/jquery.min.js' ></script>
   <script type="text/javascript" src="http://indiatoday.intoday.in/js/jquery.tinyscrollbar.min.js"></script>
   




 
<script type='text/javascript' src='http://indiatoday.intoday.in/js/copypaste_common.js' ></script>
<script type="text/javascript" >$(document).ready(function(){insertCustomSymbols();copypasteinit();});</script> 







<script type='text/javascript' src='http://media2.intoday.in/indiatoday/js/jquery.min.js' ></script>


 
<script type="text/javascript" language="javascript" src="http://indiatoday.intoday.in/js/common.js"></script>
<script type='text/javascript' src='http://indiatoday.intoday.in/js/script.js' ></script>




 
<script src="http://indiatoday.intoday.in/js/jquery.lazyload.js?v=4" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript" charset="utf-8">
//$(function() {
	$(document).find("img[data-original]").lazyload();
	$(document).find("img[data-original].imglazyload").lazyload();
	$('.loadingad').show(10);
//});
</script>

<script language="javascript" type="text/javascript" src="http://indiatoday.intoday.in/js/on-the-stand.js" ></script>




<style>
#leftrightads .leftad {
    left: -165px;
	top:184px;
	
	
	
}
#leftrightads .rightad {
    left: 1005px;
	top:184px;
	
}
.fixed {
    position: fixed!Important;
    top: 10px!Important;
}
.fix {
    position: fixed!Important;
    top: 160px!Important;
}

.fixed-r {
    position: fixed!Important;
    top: 10px!Important;
}
.fix-r {
    position: fixed!Important;
    top: 160px!Important;
}
</style>
<script type="text/javascript">
$(function () {
  var msie6 = $.browser == 'msie' && $.browser.version < 7;
  if (!msie6) {
    var top = $('.leftad').offset().top - parseFloat($('.leftad').css('margin-top').replace(/auto/, 0));
    $(window).scroll(function (event) {
      var y = $(this).scrollTop();
      if (y >= top) {
        $('.leftad .div').addClass('fixed');
		$('.leftad .divs').addClass('fix');
      } else {
        $('.leftad .div').removeClass('fixed');
		$('.leftad .divs').removeClass('fix');
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
        $('.rightad .div').addClass('fixed-r');
		$('.rightad .divs').addClass('fix-r');
      } else {
        $('.rightad .div').removeClass('fixed-r');
		$('.rightad .divs').removeClass('fix-r');
      }
    });
  } 
});
	</script>


    
    
    <!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT RichMedia Ros , publisher: India Today , Ad Dimension: Pixel/Popup - 1 x 1 -->
<!--<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2044/1137"; var zflag_sid="2"; var zflag_width="1"; var zflag_height="1"; var zflag_sz="15";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>-->
<!-- end ZEDO for channel: IT RichMedia Ros , publisher: India Today , Ad Dimension: Pixel/Popup - 1 x 1 -->


    <div id="leftrightads">
	<div class="leftad">
    
    <!---START ADDED BY LALIT ON 25-OCT-2013 --->
   <!--  <div class="div"> <a href="http://agenda.aajtak.in/" target="_blank"> <img src="http://media2.intoday.in/indiatoday/images/160x600-1.jpg"> </a></div> -->
     <!---ENDS ADDED BY LALIT ON 25-OCT-2013 --->
     
	 <div class="divs">
	<!-- Javascript tag  -->
<!-- begin ZEDO for channel:  IT ROS  SkyScraper Ex Left , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1220/1137"; var zflag_sid="2"; var zflag_width="160"; var zflag_height="600"; var zflag_sz="7"; 
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT ROS  SkyScraper Ex Left , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
	</div>
	
	</div>
	<div class="rightad">
        
    <!---START ADDED BY LALIT ON 25-OCT-2013 --->
    <!-- <div class="div"> <a href="http://agenda.aajtak.in/" target="_blank"> <img src="http://media2.intoday.in/indiatoday/images/160x600.jpg"> </a></div> -->
     <!---ENDS ADDED BY LALIT ON 25-OCT-2013 --->
     
	 <div class="divs">	
	<!-- Javascript tag  -->
<!-- begin ZEDO for channel:  IT ROS SkyScraper Ex Right , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1221/1137"; var zflag_sid="2"; var zflag_width="160"; var zflag_height="600"; var zflag_sz="7"; 
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT ROS SkyScraper Ex Right , publisher: India Today , Ad Dimension: Wide Skyscraper - 160 x 600 -->
	</div>
	
    
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
<!-- Javascript tag  -->
<!-- begin ZEDO for channel:  Aaj Tak Overlay , publisher: default , Ad Dimension: WAP - 1 x 1 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1732"; var zflag_sid="0"; var zflag_width="1"; var zflag_height="1"; var zflag_sz="51"; 
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  Aaj Tak Overlay , publisher: default , Ad Dimension: WAP - 1 x 1 -->






	<!-- Javascript tag  -->
<!-- begin ZEDO for channel:  IT RichMedia Ros , publisher: India Today , Ad Dimension: Overlay 1x1 - 1 x 1 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2044/1137"; var zflag_sid="2"; var zflag_width="1"; var zflag_height="1"; var zflag_sz="54"; 
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT RichMedia Ros , publisher: India Today , Ad Dimension: Overlay 1x1 - 1 x 1 -->
	
<!-- <style>
.maincontainer {background-image:none !important}
</style> -->
	
    
    
    
    
    


    
<!-- Javascript tag  -->
<!-- begin ZEDO for channel:  IT RichMedia Ros , publisher: India Today , Ad Dimension: Overlay 1x1 - 1 x 1 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2044/1137"; var zflag_sid="2"; var zflag_width="1"; var zflag_height="1"; var zflag_sz="54"; 
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT RichMedia Ros , publisher: India Today , Ad Dimension: Overlay 1x1 - 1 x 1 -->
	</footer></div>    
</div>

</div>

</body>
</html>