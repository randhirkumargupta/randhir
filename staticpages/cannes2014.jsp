<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Cannes 2014</title>
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
<script type="text/javascript" language="javascript" src="/staticpages/js/ajaxinclude.js"></script>

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
			counter -= 1;
			$('.right-arrow').show();
		 
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
<li class="last"><a rel="nofollow" class="mainlevel" target="_blank" href="http://travelplus.wayn.com/profiles/travelplus">Travel Plus</a></li>
</ul>
<div class="clr"></div>
</div>

<div id="header-outer">
  <div class="header-inner">
    	<div class="home-icon"><a href="http://indiatoday.intoday.in/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/homeicon.png" width="39" height="30" alt=""></a></div>
       <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/banners/cannes/header.jpg" alt="" width="998" height="167" usemap="#Map1">
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
          <ul>
		  
  <li><a href="story/cannes--paz-vega-ralph-russo-chopard-alice-rohrwacher-grand-prix-bennett-miller--leila-hatami-gilles-jacob/1/363617.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/26fir21-13_650_666_052614112957.jpg" alt="" title=""  width="666" height="500"  border="0" /></a>
   <div class="slider-content"><b><a href="story/cannes--paz-vega-ralph-russo-chopard-alice-rohrwacher-grand-prix-bennett-miller--leila-hatami-gilles-jacob/1/363617.html"  >Cannes 2014 ends on high note</a></b>
  The 67th edition of the international film fest honours this year's best</div></li>

  <li><a href="story/bright-and-sunny-at-cannes-2014/1/363504.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/25fir13-4_666_052514014806.jpg" alt="" title=""  width="666" height="500"  border="0" /></a>
   <div class="slider-content"><b><a href="story/bright-and-sunny-at-cannes-2014/1/363504.html"  >Bright and sunny at Cannes 2014</a></b>
  Two top- notch films with political tones receive accolades at film festival.</div></li>

  <li><a href="story/cinema-as-i-knew-it-is-dead-quentin-tarantino/1/363500.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/quentin-story_666_052514014329.jpg" alt="Quentin Tarantino" title="Quentin Tarantino"  width="666" height="500"  border="0" /></a>
   <div class="slider-content"><b><a href="story/cinema-as-i-knew-it-is-dead-quentin-tarantino/1/363500.html"  >Cinema as I knew it is dead: Quentin Tarantino</a></b>
  Celebrated actor-filmmaker Quentin Tarantino, whose iconic cult classis 
"Pulp Fiction" was screened here at the 67th Cannes International Film 
Festival, says the practice of screening films in digital has led to the
 death of "cinema as I knew".</div></li>
   </ul>
        </div>    
        
            
        </div>
        <div class="divclear"></div>
        
     

<div class="divclear"></div>
 <!-- 4 stories ends -->
  <!-- 2 galleries start -->
<div class="leftbar">
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/cannes-2014-best-dressed-red-carpet-blake-lively-nicole-kidman-aishwarya-rai-bachchan-sonam-kapoor/1/11877.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage_350_052714053233.jpg" alt="Cannes 2014: The best dressed ladies of all!" title="Cannes 2014: The best dressed ladies of all!"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/cannes-2014-best-dressed-red-carpet-blake-lively-nicole-kidman-aishwarya-rai-bachchan-sonam-kapoor/1/11877.html" >Cannes 2014: The best dressed ladies of all!</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/cannes-2014-best-dressed-red-carpet-blake-lively-nicole-kidman-aishwarya-rai-bachchan-sonam-kapoor/1/11877.html" ctitle="Cannes 2014: The best dressed ladies of all!"></div><ul id="11877" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/sharon-stone-sphia-loren-cannes-film-festival-2014/1/11835.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/thumb4_350_052214043425.jpg" alt="Sophia Loren and Sharon Stone steal the thunder at Cannes on Day 8" title="Sophia Loren and Sharon Stone steal the thunder at Cannes on Day 8"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/sharon-stone-sphia-loren-cannes-film-festival-2014/1/11835.html" >Sophia Loren and Sharon Stone steal the thunder at Cannes on Day 8</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/sharon-stone-sphia-loren-cannes-film-festival-2014/1/11835.html" ctitle="Sophia Loren and Sharon Stone steal the thunder at Cannes on Day 8"></div><ul id="11835" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>

</div>
<div class="middlebar">
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/amfar-gala-cannes-2014-sharon-stone-dita-von-teese-aids/1/11841.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/thumb-eve_350_052314042056.jpg" alt="Cannes 2014: Sharon Stone, Dita Von Teese make amfAR a gala affair" title="Cannes 2014: Sharon Stone, Dita Von Teese make amfAR a gala affair"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/amfar-gala-cannes-2014-sharon-stone-dita-von-teese-aids/1/11841.html" >Cannes 2014: Sharon Stone, Dita Von Teese make amfAR a gala affair</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/amfar-gala-cannes-2014-sharon-stone-dita-von-teese-aids/1/11841.html" ctitle="Cannes 2014: Sharon Stone, Dita Von Teese make amfAR a gala affair"></div><ul id="11841" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="http://indiatoday.intoday.in/gallery/cannes-2014-paris-hilton-rosie-huntington-whiteley-cara-delevingne/1/11824.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/collage_350_052114025950.jpg" alt="Cannes diaries: Oomphy Cara, classy Rosie, bold Paris" title="Cannes diaries: Oomphy Cara, classy Rosie, bold Paris"   border="0" class="images" /><span class='pmedia-image-icon sp_bg'></span></a></div><div class="innerbox"><a href="http://indiatoday.intoday.in/gallery/cannes-2014-paris-hilton-rosie-huntington-whiteley-cara-delevingne/1/11824.html" >Cannes diaries: Oomphy Cara, classy Rosie, bold Paris</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="/gallery/cannes-2014-paris-hilton-rosie-huntington-whiteley-cara-delevingne/1/11824.html" ctitle="Cannes diaries: Oomphy Cara, classy Rosie, bold Paris"></div><ul id="11824" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>

</div><div class="divclear"></div>
 <!-- 2 galleries end -->
 
    <!-- 4 stories starts -->
        
		<div class="leftbar"><div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="story/canees-2014-turkish-drama-winter-sleep-wins-palme-dor/1/363479.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/cannes-story_350_052514111155.jpg" alt="" title=""   border="0" class="images" /></a></div><div class="innerbox"><a href="story/canees-2014-turkish-drama-winter-sleep-wins-palme-dor/1/363479.html"  >Cannes 2014: Turkish drama Winter Sleep wins Palme d'Or</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/canees-2014-turkish-drama-winter-sleep-wins-palme-dor/1/363479.html" ctitle="Cannes 2014: Turkish drama Winter Sleep wins Palme d'Or"></div><ul id="363479" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="story/cannes-2014-bridges-of-sarajevo-world-war-i-jean-michel-frodon-aishwarya-rai-bachchanberenice-bejo/1/363157.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/23fir18-19-4_350_052314105512.jpg" alt="Aishwarya Rai Bachchan, Berenice Bejo, Kristen Stewart" title="Aishwarya Rai Bachchan, Berenice Bejo, Kristen Stewart"   border="0" class="images" /></a></div><div class="innerbox"><a href="story/cannes-2014-bridges-of-sarajevo-world-war-i-jean-michel-frodon-aishwarya-rai-bachchanberenice-bejo/1/363157.html"  >Cannes 2014: Films and Fashion at French Riviera</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/cannes-2014-bridges-of-sarajevo-world-war-i-jean-michel-frodon-aishwarya-rai-bachchanberenice-bejo/1/363157.html" ctitle="Cannes 2014: Films and Fashion at French Riviera"></div><ul id="363157" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
<div class="boxcont"><div class="box">
 
	<div class="posrel"><a href="story/aishwarya-rai-bachchan-armani-amfar-cannes-2014-abhishek-bachchan/1/363149.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/ash-new_350_052314105316.jpg" alt="Aishwarya Rai" title="Aishwarya Rai"   border="0" class="images" /></a></div><div class="innerbox"><a href="story/aishwarya-rai-bachchan-armani-amfar-cannes-2014-abhishek-bachchan/1/363149.html"  >Aishwarya scores hat-trick with Armani gown at amfAR</a>

<div class="clear"></div>
<div class="share-story"><div class="share-icon" url="story/aishwarya-rai-bachchan-armani-amfar-cannes-2014-abhishek-bachchan/1/363149.html" ctitle="Aishwarya scores hat-trick with Armani gown at amfAR"></div><ul id="363149" style="border:none"></ul></div>
</div></div></div><div class="divclear"></div>
</div>



<div class="middlebar"><div class="boxcont"><div class="box">
 
		<div class="posrel"><a href="story/cannes-2014-quentin-tarantino-django-unchained/1/363385.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/24fir18-19-1_350_052414011712.jpg" alt="" title=""   border="0" class="images" /></a></div><div class="innerbox"><a href="story/cannes-2014-quentin-tarantino-django-unchained/1/363385.html"  >Cannes 2014 gets pulp and mush</a>
 
<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/cannes-2014-quentin-tarantino-django-unchained/1/363385.html" ctitle="Cannes 2014 gets pulp and mush"></div><ul id="363385" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>
<div class="boxcont"><div class="box">
 
		<div class="posrel"><a href="story/cannes-2014-aids-charity-gala-amfar/1/363156.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/amfar-story_350_052314104529.jpg" alt="amfAR" title="amfAR"   border="0" class="images" /></a></div><div class="innerbox"><a href="story/cannes-2014-aids-charity-gala-amfar/1/363156.html"  >Cannes glitterati step up for AIDS charity gala by amfAR</a>
 
<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/cannes-2014-aids-charity-gala-amfar/1/363156.html" ctitle="Cannes glitterati step up for AIDS charity gala by amfAR"></div><ul id="363156" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>
<div class="boxcont"><div class="box">
 
		<div class="posrel"><a href="story/khan-starrers-kick-happy-new-year-pk-biopics-wow-buyers-at-cannes/1/363101.html" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/aamir_350_052214071937.jpg" alt="The Khans" title="The Khans"   border="0" class="images" /></a></div><div class="innerbox"><a href="story/khan-starrers-kick-happy-new-year-pk-biopics-wow-buyers-at-cannes/1/363101.html"  >Khan-starrers, biopics wow buyers at Cannes</a>
 
<div class="clear"></div><div class="share-story"><div class="share-icon" url="story/khan-starrers-kick-happy-new-year-pk-biopics-wow-buyers-at-cannes/1/363101.html" ctitle="Khan-starrers, biopics wow buyers at Cannes"></div><ul id="363101" style="border:none"></ul></div>
</div></div></div>
<div class="divclear"></div>

</div>
 
 
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
   <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/oscar/2014/twitr.jpg" width="299" height="54">
<div style="width:277px; border:11px solid #31cbfd; height:475px; background:#fff; margin:-3px 0 20px 0;">
<a class="twitter-timeline"  height="475" width="395" href="https://twitter.com/search?q=%23Cannes2014"  data-widget-id="468648802216210432">Tweets about "#Cannes2014"</a>
    <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
 	</div>
    </div>

	
    <div class="colum">
    	<div class="nomination-img">
        <a href="http://indiatoday.intoday.in/gallery/cannes-film-festival-2013-wrap-up/1/9440.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/banners/cannes/cannes-wrap-up.jpg" border="0"  width="299" ></a> 
        
        </div>
    </div>
 

     <div class="colum" style="margin-top:20px;">
    	<div class="nomination-img">
         <a href="http://indiatoday.intoday.in/gallery/indian-films-that-won-award-at-cannes/1/11773.html">
        <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/banners/cannes/collage.jpg" width="299"  border="0"> </a>
        
        </div>
    </div>
   	  	  
  </div>        

  
  	
  
<footer style="margin:0px auto;" >
<div id="footer1" style="display:block !important">
	<!--<iframe width="100%" scrolling="no" height="455" frameborder="0" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/it-footer2015.html"></iframe>-->
    <link href="http://fonts.googleapis.com/css?family=Roboto:100,200,300,700,500,400,900" rel="stylesheet">
<style>
body { padding:0px; margin:0;}
.spritbg {background-image: url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png");}
.spical-footer{ font-family:roboto;}
.below-footer_h, .footer-main-wrapper {z-index: 10;}
.below-footer_h { background: #0d0d0d none repeat scroll 0 0;overflow: hidden;width: 100%;}
.new_nav {background: #191718 none repeat scroll 0 0;clear: both;width: 100%;}
.new_nav ul { margin: 0 auto;width: 1003px; padding:0;}
.new_nav ul li { color: #ffffff; float: left;font-family: roboto;list-style: outside none none; padding: 10px 12px;text-transform: uppercase; font-size:16px;}  
.new_nav ul li a {color: #ffffff;text-decoration: none;}
.footer-main-wrapper {background: #0d0d0d none repeat scroll 0 0; width: 100%;} .below-footer_h {background: #0d0d0d none repeat scroll 0 0; overflow: hidden; width: 100%;}.footer_cnt_h {width: 100%;} .footer_ads_h, .footer_lnk_m {margin: 0 auto; width: 1003px;}.ft_lnks_h { float: left; padding-left:5px; margin-right: 6px; width: 128px;} .footer_lnk_m h3 { color: #888888; font-size: 14px; margin: 10px 0;text-transform: uppercase;}.footer_lnk_m ul, .middle_center_h .m_cont ul, .nav_bar ul, .nav_bar2 ul {list-style-type: none;margin: 0; padding: 0;}.footer_lnk_m ul li {display: block;line-height: 14px;margin-top: 10px;}.footer_lnk_m ul li a {color: #494949;font-size: 12px;text-decoration: none;z-index: 1;} #copyrights { border-top: 1px solid #000000;color: #333333;float: left;    font-size: 12px;margin-top: 15px;padding: 10px 0; text-align: center; width: 100%;}#copyrights a {color: #333333;font-size: 12px;text-decoration: none;}.below-footer_h.ads_f {background: #000000 none repeat scroll 0 0;padding: 15px 0;}.below-footer_h, .below-footer_h, .footer-main-wrapper {z-index: 10;}.below-footer_h {background: #0d0d0d none repeat scroll 0 0; overflow: hidden; width: 100%;}.ads_f {background: #000000 none repeat scroll 0 0; border: 0 none;}.footer_right_h {float: right; width: 250px;
}.socials_footer_links_h {margin-top: 20px;}.socials_footer_links_h ul {list-style-type: none; margin: 0; padding: 0;}.socials_footer_links_h ul li {float: left;margin-right: 10px;}
.socials_footer_links_h ul li .fb_h { background: rgba(0, 0, 0, 0) url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png") repeat scroll -226px -188px; height: 45px; transition: background-position 0.2s ease-in 0s; width: 40px;}
.socials_footer_links_h ul li .fb_h:hover { background-position: -226px -238px;}
.socials_footer_links_h ul li .tw_h { background: rgba(0, 0, 0, 0) url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png") repeat scroll -265px -188px; height: 45px; transition: background-position 0.2s ease-in 0s; width: 40px;}
.socials_footer_links_h ul li .tw_h:hover { background-position: -265px -238px;}
.socials_footer_links_h ul li .gp_h { background: rgba(0, 0, 0, 0) url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png") repeat scroll -320px -188px; height: 45px;transition: background-position 0.2s ease-in 0s; width: 40px;}
.socials_footer_links_h ul li .gp_h:hover { background-position: -320px -238px;}
.socials_footer_links_h ul li .rss_h { background: rgba(0, 0, 0, 0) url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png") repeat scroll -375px -188px; height: 45px; transition: background-position 0.2s ease-in 0s; width: 40px;}
.socials_footer_links_h ul li .rss_h:hover { background-position: -375px -238px;}
.socials_footer_links_h ul li .mbl_h { background: rgba(0, 0, 0, 0) url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/homenew/Sprit-IT-Home.png") repeat scroll -428px -184px; height: 45px; margin-top: -5px; transition: background-position 0.2s ease-in 0s;    width: 40px;}.footer_left_h { float: left;width:730px;}.socials_footer_links_h ul li .mbl_h:hover {background-position: -428px -230px;}
a#footerprev, a#footernext{ display:none;}
.mob{display:none;}
.footer_lnk_m ul li a strong{ font-weight:900 !important;}

@media screen and (max-width :800px){
.new_nav ul li{padding: 10px 0 10px 11px;}
a#footerprev, a#footernext{ display:block; position:absolute; top:85px;}
a#mobfooterprev, a#mobfooternext{ display:block; position:absolute; top:85px;}
.new_nav ul li {font-size:14px;}
.footer_cnt_h{ position:relative; overflow:hidden; width:720px; margin:0 auto;}
.footer_lnk_m, .below-footer_h{ position:relative;}
.below-footer_h a#footernext {background-position: -210px -368px; display: block; height: 58px; right: 1px; text-indent: -999999px; width: 37px;}
.below-footer_h a#footerprev {background-position: -171px -368px; display: block; height: 58px; left: -2px; text-indent: -999999px; width: 37px;}
.below-footer_h a#mobfooternext {background-position: -210px -368px; display: block; height: 58px; right: 1px; text-indent: -999999px; width: 37px;}
.below-footer_h a#mobfooterprev {background-position: -171px -368px; display: block; height: 58px; left: -2px; text-indent: -999999px; width: 37px;}

.mob{display:none;}
.ipad{display:block;}
.footer_right_h{margin-left:27%; clear:left; float:left;}
}

@media screen and (max-width :480px){
.mob{display:block;}
.ipad{display:none;}
.new_nav ul{width:100%;}
.below-footer_h.ads_f{display:none;}
.new_nav ul li{padding:2px 0 2px 9px; font-size:12px;}
#copyrights{text-align:left;}
#copyrights a{float:left; clear:left; width:100%;}

}
@media only screen and (min-device-width : 320px) and (max-device-width : 640px) and (orientation:landscape){

.below-footer_h.ads_f{display:none !important;}
.footer_cnt_h{width:100%;}
}
@media only screen and (min-device-width : 320px) and (max-device-width : 640px) and (orientation:portrait ){

.below-footer_h.ads_f{display:none !important;}
.footer_cnt_h{width:100%;}
}

@media (max-width: 640px) and (min-width:320px){
.new_nav ul li {font-size:11px; padding:5px 0 5px 5px;}

}
</style>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script>
$(document).ready(function(){
if($(window).width() < 801){
var footerlen  = $('.footer_lnk_m .ft_lnks_h').length;
var footerwidth = $('.footer_lnk_m .ft_lnks_h').outerWidth();
var footerwidth = footerlen*(footerwidth+6);
$('.footer_lnk_m').css('width', footerwidth);
//alert(footerlen);
var footercountersipad = 1;
$('#footernext').click(function(){
if(footercountersipad < footerlen-4)
{$('.footer_lnk_m').animate({left : '-=144'});
footercountersipad +=1;
$('#footerprev').css('display', 'block');
}
else{
$('#footernext').css('display', 'none');
}
});	
$('#footerprev').click(function(){
if(footercountersipad == 1)
{
//$('#photoprev').css('display', 'none');
$('#footerprev').css('display', 'none');
$('#footernext').css('display', 'block');
}
else{
$('.footer_lnk_m').animate({
left : '+=144'
});
footercountersipad -= 1;
$('#footernext').css('display', 'none');
//$('#ipadphoto-next').css('display', 'block');
		}
	});

	}	 
	if($(window).width() <= 480){
		
var footerlen  = $('.footer_lnk_m .ft_lnks_h').length;
var footerwidth = $('.footer_lnk_m .ft_lnks_h').width();
var footerwidth = footerlen*(footerwidth+20);
$('.footer_lnk_m').css('width', footerwidth);
//alert(footerlen);
var footercountersmob = 1;
$('#mobfooternext').click(function(){
if(footercountersmob < footerlen)
{$('.footer_lnk_m').animate({left : '-=138'});
footercountersmob +=1;
$('#mobfooterprev').css('display', 'block');
}
else{
//$('#mobfooternext').css('display', 'none');
}
});	
$('#mobfooterprev').click(function(){
if(footercountersmob == 1)
{
//$('#photoprev').css('display', 'none');
//$('#mobfooterprev').css('display', 'none');
$('#mobfooternext').css('display', 'block');
}
else{
$('.footer_lnk_m').animate({
left : '+=138'
});
footercountersmob -= 1;
//$('#mobfooternext').css('display', 'none');
//$('#ipadphoto-next').css('display', 'block');
		}
	});

	} 
			  
});





</script>
</head>
<body>

<div class="spical-footer">
  <div class="below-footer_h">
    <div class="new_nav">
      <ul>

        <li><a href="http://indiatoday.intoday.in/news.html" target="_blank">NEWS</a></li>
        <li><a href="http://indiatoday.intoday.in/section/114/1/india.html" target="_blank">INDIA</a></li>
        <li><a href="http://indiatoday.intoday.in/section/113/1/world.html" target="_blank">WORLD</a></li>
        <li><a href="http://indiatoday.intoday.in/galleries" target="_blank">PHOTOS</a></li>
        <li><a href="http://indiatoday.intoday.in/section/214/1/cricket.html" target="_blank">CRICKET</a></li>
        <li><a href="http://indiatoday.intoday.in/section/67/1/movies.html" target="_blank">MOVIES</a></li>
        <li><a href="http://indiatoday.intoday.in/section/230/1/auto.html" target="_blank">AUTO</a></li>
        <li><a href="http://indiatoday.intoday.in/section/84/1/sports.html" target="_blank">SPORTS</a></li>
        <li><a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html" target="_blank">LIFESTYLE</a></li>
        <li><a href="http://indiatoday.intoday.in/technology/" target="_blank">TECH</a></li>
        <li><a href="http://indiatoday.intoday.in/education/" target="_blank">EDUCATION</a></li>
        <li><a href="http://businesstoday.intoday.in/" target="_blank">BUSINESS</a></li>
      </ul>
      <div class="clear"></div>
    </div>
  </div>
  <div class="below-footer_h ads_f">
    <div class="footer_ads_h" >
      <div class="footer_left_h"> 
        <!-- /1007232/Indiatoday_ROS_Desktop_BTF_728x90 -->
<div id='div-gpt-ad-1507120650515-4' style='height:90px; width:728px;'>
<script>
googletag.cmd.push(function() { googletag.display('div-gpt-ad-1507120650515-4'); });
</script>
</div>
      </div>
      <div class="footer_right_h">
        <div class="socials_footer_links_h">
          <ul>
            <li><a href="http://www.facebook.com/indiatoday" target="_blank">
              <div class="fb_h"></div>
              </a></li>
            <li><a href="http://www.twitter.com/indiatoday" target="_blank">
              <div class="tw_h"></div>
              </a></li>
            <li><a href="http://www.google.com/+indiatoday" target="_blank">
              <div class="gp_h"></div>
              </a></li>
            <li><a href="http://indiatoday.intoday.in/site/rssFeed.jsp" target="_blank">
              <div class="rss_h"></div>
              </a></li>
            <li><a href="http://m.indiatoday.in/" target="_blank">
              <div class="mbl_h"></div>
              </a></li>
          </ul>
        </div>
      </div>
    </div>
    <div class="clearfix"></div>
  </div>
  <div class="footer-main-wrapper">
    <div class="below-footer_h">
      <div class="footer_cnt_h">
        <div class="footer_lnk_m">
          <div class="ft_lnks_h">
            <h3>Publications</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.intoday.in">India Today</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://subscriptions.intoday.in/subscriptions/itoday/ith_offer.jsp?source=website">India Today - Hindi</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://businesstoday.intoday.in">Business Today</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://cosmo.intoday.in/cosmopolitan/index.jsp">Cosmopolitan</a></li>
              <!-- <li><a target="_blank"  rel="nofollow" href="http://menshealth.intoday.in">Men's Health</a></li> -->
              <li><a target="_blank"  rel="nofollow" href="http://www.oddnaari.in/">Oddnaari</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://moneytoday.intoday.in">Money Today</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://preventionindia.in/issue.html">Prevention</a></li>
            </ul>
          </div>
          <div class="ft_lnks_h">
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.rd-india.com/newsite/home/home.asp">Reader's Digest</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://www.indiatodaygroup.com/goodhouse/issue.html">Good Housekeeping</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://subscriptions.digitaltoday.in/subscriptions/time/subscription.html">Time</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://www.hbrsasia.org">Harvard Business Review</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://www.gadgetsngizmos.in">Gadgets &amp; Gizmos</a></li>
            </ul>
          </div>
          <div class="ft_lnks_h">
            <h3>Television</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://aajtak.intoday.in">Aaj Tak</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://aajtak.intoday.in/dilliaajtak/">Delhi Aaj Tak</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://aajtak.intoday.in/tez/">Tez</a></li>
              <li><a href="http://indiatoday.intoday.in/livetv.jsp" target="_blank"  rel="nofollow">India Today TV</a></li> 
            </ul>
            <h3>Radio</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://oyefm.in/">ISHQ 104.8FM</a></li>
            </ul>
          </div>
          <div class="ft_lnks_h">
            <h3>Education</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.vasantvalley.org/vasantvalley/default.shtml">Vasant Valley</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://learntoday.in/">Online Courses</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://ulearntoday.com">U Learn Today</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://education.intoday.in/">India Today Education</a></li>
            </ul>
            <h3>Online Shopping</h3>
            <ul>
              <!-- <li><a target="_blank"  rel="nofollow" href="http://www.bagittoday.com/">Bag It Today</a></li> -->
              <li><a target="_blank"  rel="nofollow" href="http://www.indiatodaydiaries.com/">India Today Diaries</a></li>
            </ul>
          </div>
          <div class="ft_lnks_h">
            <h3>Events</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://aajtak.intoday.in/agenda-aajtak/">Agenda Aajtak</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://www.indiatodayconclave.com">India Today Conclave</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.in/womansummit/index.php">India Today Woman's Summit</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://www.indiatoday.in/youthsummit">India Today Youth Summit</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.intoday.in/state-of-the-states/">State Of The States Conclave</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.intoday.in/educationsummit/">India Today Education Summit</a></li>
            </ul>
          </div>
          <div class="ft_lnks_h">
            <h3>Printing</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.thomsonpress.com">Thomson Press</a></li>
            </ul>
            <h3> Welfare</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.caretoday.in">Care Today</a></li>
            </ul>
            <h3> Music</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.music-today.com">Music Today</a></li>
            </ul>
            <h3>Distribution</h3>
  <ul>
     <li> <a href="http://indiatoday.intoday.in/distribution/index.jsp" target="_blank"  rel="nofollow">Rate Card</a></li>
     <li> <a href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/aajtak/images/das_application/DAS-Application-form.pdf" target="_blank"  rel="nofollow">DAS Application form</a></li>
      <li> <a href="http://indiatoday.intoday.in/distribution/das_phase_three.jsp" target="_blank"  rel="nofollow">Contact persons for DAS phase III</a></li>
  </ul>
          </div>
          <div class="ft_lnks_h">
            <h3> Syndications</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.indiatodayimages.com/">India Today Images</a></li>
            </ul>            
            <h3> Useful Links</h3>
            <ul>
              <li><a target="_blank"  rel="nofollow" href="http://www.dailyo.in/">DailyO</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.intoday.in/site/partners.jsp">Partners</a></li>
              <li><a target="_blank"  rel="nofollow" href="http://indiatoday.intoday.in/prnewswire/index.jsp"><strong>Press Release</strong></a></li>
            </ul>
          </div>
        </div>
        <div id="copyrights">Copyright &copy; 2017 Living Media India Limited. For reprint rights: <a target="_blank"  rel="nofollow" href="http://www.syndicationstoday.com/">Syndications Today.</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
      </div>
      <div class="ipad"><a href="javascript:void(0);" id="footerprev" class="spritbg ipad">Prev</a> <a href="javascript:void(0);" id="footernext" class="spritbg ipad">Next</a> </div>
      <div class="mob"><a href="javascript:void(0);" id="mobfooterprev" class="spritbg mob">Prev</a> <a href="javascript:void(0);" id="mobfooternext" class="spritbg mob">Next</a> </div>
      </div>
    <div class="clearfix"></div>
  </div>
</div>
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
              

                 
             </div>
             
<div class="rightad">               
          
               
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
<script src="staticpages/js/jquery.lazyload.js" type="text/javascript" charset="utf-8"></script>
<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/javascript.js" type="text/javascript" charset="utf-8"></script>
<script type='text/javascript' src='http://indiatoday.intoday.in/js/copypaste_common.js' ></script>
<script type="text/javascript" >$(document).ready(function(){insertCustomSymbols();copypasteinit();});</script>
<img height="1" width="1" src="http://s3-pixel.c1exchange.com/pubpixel/82493" style="display:none;">
<script src="http://tags.crwdcntrl.net/c/9709/cc_af.js"></script>
 <!-- begin ZEDO for channel:- IT RichMedia Ros, Publisher: India Today, Ad Dimension: Overlay 1x1-1x1 --> 
 <div id="zt_1270_1" style="display:show"> 
 <script id="zt_1270_1" language="javascript"> 

if(typeof zmt_mtag !='undefined' && typeof zmt_mtag.zmt_render_placement !='undefined')
{
     zmt_mtag.zmt_render_placement(p1270_1);
}
 </script>
 </div>
 <!-- end ZEDO for channel: - IT RichMedia Ros, Publisher: India Today, Ad Dimension: Overlay 1x1-1x1 --> 

</div>

</div>
<div class="clr">&nbsp;</div>

<script type='text/javascript' src='http://apis.google.com/js/plusone.js'></script>
</body>
</html>

