<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Gravity</title>
<meta name="description" content="Gravity" />
<meta name="keywords" content="Gravity" />
<link rel="image_src" href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-1_100913080948.jpg" />
<script src="/staticpages/main/js/jquery.min.js" type="text/javascript"></script>

<style>
.slidecont {}
.slidecontbg {background-color:#dfdfdf;}
.slider-left {
    color: #636466;
    float: left;
    font: 23px Arial;
    margin-left: 76px;
    margin-top: 40px;
    width: 260px;
}

.slider-right {
    float: right;
    overflow: hidden;
    width: 650px;
}

.slider-head {font:normal 48px/50px Arial Black; color:#f16e24; background-color:#fff; padding:10px;}

.slider-prev {position: absolute; left: 0px; top: 215px; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/specials/images/arrows_lft.png) no-repeat top left; width:45px; height:45px; text-indent:-9999px; cursor:pointer}
.slider-next {position: absolute; right: 3px; top: 215px;background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/specials/images/arrows_rt.png) no-repeat top left; width:45px; height:45px; text-indent:-9999px; cursor:pointer}
.pagination {position:absolute; bottom:15px; left:325px; font:bold 23px arial; color:#aeab96}
.pagination ul { margin:0; padding:0;}
.pagination ul li, .pagination ul li a { list-style:none; color:#333; padding:0 5px; float:left; margin-right:0px; text-decoration:none }
.pagination ul li a.sactive, .pagination ul li a:hover {background-color:#f16e24;color:#fff;}

</style>


<script>

        $(document).ready(function(e) {

                    var counter = 1;

                    var len = $('.story_slide ul li').length;

                    $('.story_slide ul').width(((1000*len)+10));

                    $('.left').click(function(){
					document.getElementById("right").style.display="";
                                if (counter == 1)

                                {

                                            $(this).css('opacity', '0.5');

                                }

                                else

                                {

                                            $('.story_slide ul').animate({

                                                        left : '+=1000',

                                            });

                                            counter -=1;

                                            $('.right').css('opacity', '1');

                                }



                                });

                 $('.right').click(function(){

                                if (counter == len)

                                {

                                            $(this).css('opacity', '0.5');
								 document.getElementById("right").style.display="none";

                                }

                                else

                                {

                                            $('.story_slide ul').animate({

                                                        left : '-=1000',

                                            });

                                            counter +=1;

                                            $('.left').css('opacity', '1');

                                }

                    });

});

</script>
<style>


.story_slide {
    height: 440px;
    overflow: hidden;
    position: relative;
    width: 1000px;
}

            .story_slide ul { padding:0px; margin:0px; float:left; position:relative  }

            .story_slide ul li { padding:0px; margin:0px; list-style:none; height:700px; float:left; width:1000px;  }

            .content {color: #2E2E2E;font-size: 14px;padding: 5px; font-family:Arial, Helvetica, sans-serif;}

            .content p { font-size:24px; font-family:"Times New Roman", Times, serif }
			.clr { clear:both}


            .story_slide .left { position:absolute; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/friends/Back-button.png) 5px 38px no-repeat; color:#fff; padding:10px; left:0px; top:150px; cursor:pointer; z-index:1; width:124px; height:74px  }

            .story_slide .right { position:absolute; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/friends/Forward-button.png) 122px 38px no-repeat; color:#fff; padding:10px; right:0px; top:150px; cursor:pointer; z-index:1;  width:165px; height:74px  }

</style>
<style>

.frm-share {float: right;height: 35px;position: relative;width: 150px;}
.socialcont { position: absolute;right: 0;top: 0;width: 120px;}
.socialdiv {bottom: 0;position: relative;right: 0;}
.email {background-position: -304px -8px;}
.fb, .tw, .email { background-image: url("http://specials.indiatoday.com/words-of-love/sprite.png");background-repeat: no-repeat;cursor: pointer;height: 32px;width: 36px;}
.imgs {margin: 0 2px;}
.lft {float: left;}
.fb {background-position: -224px -8px;}
.tw {background-position: -264px -8px;}
#slides {clear: both; width: 100%;position: relative;}
.slides_container {width:1000px;min-height: 600px;overflow:hidden;position:relative;display:none;}
.slides_container div.slide{width:1000px;min-height:600px;display:block;}
#slides .next,#slides .prev {position:absolute;top:35%;width:54px;height:60px;display:block;z-index:101;opacity: 0.5;filter:alpha(opacity=50);}
#slides .next:hover,#slides .prev:hover{opacity: 1;filter:alpha(opacity=100);}
#slides .next {right:-3px;}
#slides .prev {left:0px;}
a:link,a:visited {color:#599100;text-decoration:none;}
a:hover,a:active {color:#599100;text-decoration:underline;}
.backto1{position: absolute; right: 0px; top: 40%; font: bold 94px/6px Arial; color: #4f4b4c !important;}
.backto1:hover{text-decoration: none;}
.backto1 > span {font: bold 10px/22px arial; color: #000;}
.submit_button{  background-image: url("../images/str_sub.gif");background-position: left top;background-repeat: no-repeat;border: medium none;cursor: pointer;float: left;height: 21px;margin: 0;padding: 0;width: 66px;}
.close-spcl-pop{position: absolute; right: 10px; background-color: #CCCCCC; text-align: center; width: 20px; top: 10px; height: 20px; font: bold 12px/20px arial; border-radius: 10px 10px 10px 10px; color: #000!important;}
.close-spcl-pop:hover{background-color: #000!important;  color: #fff!important; text-decoration: none;}
.spclcomment{position: absolute;right: 100px;top: 0;}
.spclcomment > a:hover{text-decoration: none;}
#spclcomment{position: absolute; top: 30px; border: 1px solid #ccc; display: none; height: auto; right: 0px; background-color: #eee; padding: 25px; border-radius: 10px;}
#leftrightads{ display:none!important;}
.spclcomment{right: 130px!important;}
.mainlink {font:bold 16px/20px arial; color:#000; text-align:right; margin-bottom:10px;}
.mainlink a {color:#000; text-decoration:none}
.mainlink a:hover {text-decoration:underline}
</style>
</head>

<body class="nobg">

<div id="wrappercont">
<div class="maincontainer">
<div id="wrapper">



<script src="//pagead2.googlesyndication.com/pagead/js/google_top_exp.js"></script>
<link rel="stylesheet" href="/staticpages/main/css/autosuggest_inquisitor.css" type="text/css" media="screen" charset="utf-8" />

<link rel="shortcut icon" href="/staticpages/main/images/favicon.ico" />
<script type="text/javascript" language="javascript" src="/staticpages/main/js/ajaxinclude.js"></script>
<!--[if lte IE 7]><link rel="stylesheet" type="text/css" href="css/ie.css" media="screen" /><![endif]-->
<link href="/staticpages/main/css/common.css" rel="stylesheet" type="text/css">
<!-- The below script Makes IE understand the new html5 tags are there and applies our CSS to it --><!--[if IE]><script src="/staticpages/main/js/html5.js"></script><![endif]-->
<div id="itgd_links">
<ul>
<li class="last">
<a rel="nofollow" target="_blank" href="http://indiatodaygroup.com/">INDIA TODAY GROUP :</a></li>
<!--<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.intoday.in/">InToday</a></li>-->
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

<!--<meta http-equiv="X-UA-Compatible" content="IE=EmulateIE7" />-->

<div class="topbg">
		<div id="lefttop">

	<script type="text/javascript">ajaxinclude("/staticpages/gravity/updatedtime_chunk.jsp")</script>

            <div id="logo">
            	<a href="http://indiatoday.intoday.in/"><img src="/staticpages/main/images/it.png" alt="India Today" width="262" height="80" title="India Today"></a>
            </div>
			<div id="sitelogo">
        		<div>In Association With</div>
	        		 <span class="mail-today"> <a href="http://mailtoday.in/" target="_blank"><img src="/staticpages/main/images/mailtoday.gif" alt="" /></a></span>
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
            <li><a href="http://indiatoday.intoday.in/section/84/1/sports.html" >Sport</a></li>
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
<div class="container">
<div class="frm-share rght">
        <div class="socialcont">
            <div class="socialdiv">
                 <a href="javascript:void('0');" onclick='javascript:window.open("http://indiatoday.intoday.in/content_Email.jsp?email=0&title= Gravity&URL=http://indiatoday.intoday.in/gravity/","window", "status=no,resize=no,toolbar=no,scrollbars=no,width=468,height=390"); event.returnValue=false; return false;' title="Email" target="_new" rel="nofollow"><span class="imgs email lft"></span></a>
                <a rel="nofollow" target="_new" title="Facebook" href="http://www.facebook.com/sharer/sharer.php?p[url]=http://indiatoday.intoday.in/gravity/&amp;p[title]=Gravity&amp;s=100&amp;p[summary]=Gravity&amp;p[images][0]=http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-1_100913080948.jpg"><span class="imgs fb lft"></span></a>
                <a rel="nofollow" target="_new" title="Twitter" href="http://twitter.com/?status= Gravity%20http://indiatoday.intoday.in/gravity/%20via%20%40indiatoday"><span class="imgs tw lft"></span></a>
            </div>
        </div>



    </div>

    <div class="slider-head">Science versus fiction: Can 'Gravity' become a reality?
</div>
<p style="font-size:20px;text-align:center;">We grab the thread between reality and fiction to figure out where one starts and the other ends.
<br/><br/>
The Sandra Bullock and George Clooney starrer sci-fi movie 'Gravity' may make for a gripping watch, but the movie poses the question 'could this happen for real'?  Actual rocket scientists and astronauts have taken it upon themselves to point out the 'real stuff'.

 </p>
<div class="slidecont slidecontbg" style="float:left">
 <div class="story_slide">

<div class="left"></div>

<div class="right" id="right"></div>

            <ul>


<style>
.slidecontbg{"background-color:;"}
</style>

<li>

<div class="slider-left">

 <div style="clear:both"></div>
Movie: In a scene Bullock takes off her space suit and is shown wearing a sports bra and shorts underneath.

<br/> <br/>

Reality: In reality, astronauts have to wear one-piece long johns, cooling tubing and a diaper.
<p style="margin-bottom:50px;"></p></div>
<div class="slider-right"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-1_100913080948.jpg" border="0" >
</div>
</li>



<li>

<div class="slider-left">

 <div style="clear:both"></div>
Movie: The size of the visors the actors wear in the movie is large to give an unobstructed view of the actor's face.

 <br/> <br/>
Reality: There are two visors involved - one that seals up the air inside the suit; and the other, a much darker one, that protects the astronaut's eyes from the strong sun light in space.


<p style="margin-bottom:50px;"></p></div>
<div class="slider-right"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-2_100913080948.jpg" border="0" >
</div>
</li>
<li>

<div class="slider-left">

 <div style="clear:both"></div>
Movie: The Hubble Space Telescope, the ISS (International Space Station) and the Chinese space station are shown in relatively close proximity to one another.

<br/> <br/>
Experts: It cannot be so close, the distance is much more than shown.


<p style="margin-bottom:50px;"></p></div>
<div class="slider-right"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-3_100913080948.jpg" border="0" >
</div>
</li>

<li>

<div class="slider-left">

 <div style="clear:both"></div>
Movie: In another scene, Bullock floats straight on past a burning ISS.

 <br/> <br/>

Reality: An astronaut's ethical code demands that such issue be addressed immediately.




<p style="margin-bottom:50px;"></p></div>
<div class="slider-right"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-4_100913081302.jpg" border="0" >
</div>
</li>

<li>

<div class="slider-left">

 <div style="clear:both"></div>
What they covered to near perfection:

  <br/> <br/>

Bullock's character goes through space sickness in 'Gravity', which reportedly is quite common in space. Although, by the time she was shown doing the space walk, Bullock's character would've gotten over it.



<p style="margin-bottom:50px;"></p></div>
<div class="slider-right"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/slideshow/collage-5_100913081302.jpg" border="0" >
</div>
</li>






 </ul>
</div>



</div>


</div>

<div style="clear:both ; margin:10px 0;"></div>
<div align="center" style="width: 660px; text-align: left; margin: 10px 0px 10px 160px;">


<script src="http://vuukle.com/js/vuukle.js"></script>
 <div class="vukkul-comment">
  <div id="vuukle-emote"></div>
  <div id="vuukle_div"></div>
          <script type="text/javascript">
               var UNIQUE_ARTICLE_ID = "static_gravity";
               var SECTION_TAGS =  "";
               var ARTICLE_TITLE = "gravity";
               var GA_CODE = "UA-795349-17";
               var VUUKLE_API_KEY = "dc34b5cc-453d-468a-96ae-075a66cd9eb7";
               var TRANSLITERATE_LANGUAGE_CODE = ""; //"en" for English, "hi" for hindi
               var VUUKLE_COL_CODE = "d00b26";
               var ARTICLE_AUTHORS = "";
               create_vuukle_platform(VUUKLE_API_KEY, UNIQUE_ARTICLE_ID, "0", SECTION_TAGS, ARTICLE_TITLE, TRANSLITERATE_LANGUAGE_CODE , "1", "", GA_CODE, VUUKLE_COL_CODE, ARTICLE_AUTHORS);
          </script>
</div>


</div>
<div style="clear:both; margin:10px 0;"></div>

<div class="fotborder">
<div class="clear"></div>
   <script type="text/javascript">ajaxinclude("/staticpages/gravity/chunk_social_strip.html")</script>
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

</div>
<div id="footer">
               <iframe width="990" scrolling="no" height="165" frameborder="0" src="/staticpages/main/microsites/common/common_it_footer.html"></iframe>
            </div>

    <div style="display:none;" class="bott-popup" id="videopopup">
  <div class="bott-popup-inn" id="userreg">
    <div class="bott-popinn"><a id="cancelpopup" href="javascript:void(0);"><img border="0"  src="/staticpages/main/microsites/specials/close.png"></a></div>
        <div class="bottspecinn"></div>
    <div id="enrollfrm">

    </div>
    </div>
</div>




  <script type='text/javascript' src='/staticpages/main/js/jquery.min.js' ></script>
   <script type="text/javascript" src="/staticpages/main/js/jquery.tinyscrollbar.min.js"></script>






<script type='text/javascript' src='/staticpages/main/js/copypaste_common.js' ></script>
<script type="text/javascript" >$(document).ready(function(){insertCustomSymbols();copypasteinit();});</script>







<script type='text/javascript' src='/staticpages/main/js/jquery.min.js' ></script>



<script type="text/javascript" language="javascript" src="/staticpages/main/js/common.js"></script>
<script type='text/javascript' src='/staticpages/main/js/script.js' ></script>





<script src="/staticpages/main/js/jquery.lazyload.js?v=4" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript" charset="utf-8">
//$(function() {
	$(document).find("img[data-original]").lazyload();
	$(document).find("img[data-original].imglazyload").lazyload();
	$('.loadingad').show(10);
//});
</script>

<script language="javascript" type="text/javascript" src="/staticpages/main/js/on-the-stand.js" ></script>




<style>
#leftrightads .leftad {
    left: -165px;
	top:199px;

}
#leftrightads .rightad {
    left: 1005px;
	top:199px;
}
.fixed {
    position: fixed!Important;
    top: 10px!Important;
}

.fixed-r {
    position: fixed!Important;
    top: 10px!Important;
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
	<div class="leftad">
	<a href="http://election.intoday.in" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/160X600-IT.GIF" border="0"></a>
	</div>
	<div class="rightad">
	<a href="http://election.intoday.in" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/160X600-IT.GIF" border="0"></a>
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


  </div>
  </div>
  <div class="clear"></div>
  </div></div>
</body>
</html>

