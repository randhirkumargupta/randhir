
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
<meta name="robots" content="index,follow" />
<title>Great Overland Adventure - India Today</title>
<meta name="description" content="Election Express travels the length and breadth of the country to bring you ground reports from the campaign for Lok Sabha 2014." />
<meta name="keywords" content="Election Express, Lok Sabha Elections 2014, Elections 2014, election reports, election videos, election photos" />
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />
<script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
<script>
$(document).ready(function(e) {
	var len  = $('.belt h5').length;
    var twidth = $('.belt h5').width();
	var fwidth = (twidth+10)*len;
	$('.belt').css('width', fwidth);
		$('.shprevarrow').css('opacity', '0.5');
		//$('.belt').width(900*len);

		$('.belt').animate({
					left : '-=3451px'
				});
				var counter = 14;


        $('.shprevarrow').click(function(){
			if (counter == 0)
				{
					$('.shprevarrow').css('opacity', '0.5');
				}
				else
				{
					$('.belt').animate({
					left : '+=128',
					});
					counter -= 1;
					$('.shnextarrow').css('opacity', '1');

				}
			});

		 $('.shnextarrow').click(function(){
				if (counter == len-18)
				{
					$('.shnextarrow').css('opacity', '0.5');
				}
				else
				{
					$('.belt').animate({
					left : '-=128',

					});
					counter +=1;
					$('.shprevarrow').css('opacity', '1');
				}
			});





    });
</script>

<script>
$(document).ready(function(){
		$('.share-icon').click(function(){
			$('.share-icon').show();
			if(!$(this).next('ul').html().match('facebook')) {
				contentURL = $(this).attr('url');
				contentTitle = $(this).attr('ctitle');
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=http://indiatoday.intoday.in/"+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=80&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:80px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http://indiatoday.intoday.in/"+contentURL+"&amp;size=m&amp;text="+escape(contentTitle)+"%20-%20India%20Today&amp;url=http://indiatoday.intoday.in/"+contentURL+"&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=http://indiatoday.intoday.in/"+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
				var thisss = $(this);
				$('.open').css({display:'none'});
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'}).html(contenttotwrite);
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			} else {
				var thisss = $(this);
				$('.share-story ul').css({display:'none'});
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'});
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			}
		});
	});
</script>

<style type="text/css">
.share-story{float:left;padding-top:7px;height:34px;width:97%; margin-left:10px;}
.share-icon{background:url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/sprite-image.png") no-repeat scroll -135px -10px;width:42px;height:34px;float:left;margin-left:-5px;cursor:pointer;}
.share-story ul{border-bottom:1px solid #DADADA;margin:0;padding:0;float:left;}
.share-story li{border:medium none !important;color:#B2A6AA;margin:0 !important;padding:0 0px 0 0;list-style:none;float:left;}
</style>

</head>
<body style="overflow-x:hidden">
<style>
.day-text { width:100%!important; text-align:center; color:#089fd7}
h5 a { text-decoration:none!Important;}
.ddate {font-size: 18px; font-weight: normal;text-align: center; color:#4c2724; line-height:20px;}
.wt { color:#fff}
.day-active { background:#fca929!Important;}
.colum {
	width: 305px!Important;
	float: left;
	box-shadow: 2px 2px 10px 2px #CCCCCC;
	-moz-box-shadow: 2px 2px 10px 2px #CCCCCC;
	-webkit-box-shadow: 2px 2px 10px 2px #CCCCCC;
	}
.map-continer{ padding:0 10px;}
.follow-me{ height:460px!Important;}
.row-team{ overflow:hidden; padding:10px 0; border-bottom:1px solid #ddd;}
.row-team .left-img{ width:93px; margin-right:20px; float:left;}
.row-team .left-img img{ float:left;}
.row-team .right-text{ width:500px; float:right;}
.row-team .right-text p{ margin:0; padding:0; font-size:15px; line-height:20px;}


</style>

<style>
.follow-me { height:auto!Important; overflow:hidden}
.top_ad { float:right; margin-top:8px;}
</style>

<link href="/gladventure/css/layout.css" rel="stylesheet" type="text/css" />
<script src="/gladventure/js/ajaxinclude.js"></script>
<!--<div><iframe src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/intoday/mp-report-header/header.html" width="100%" frameborder="0" height="42"></iframe></div>-->
<div style="border-bottom: 1px solid rgb(136, 136, 136); box-shadow: none; position: relative; top: 0px; margin: auto; width: 100%; z-index: 999999;" class="menues">
<nav>
<div class="app sp_bg" style="display: none;"><a href="http://indiatoday.intoday.in/">Indiatoday</a></div>
<ul>
<li class="home-icon sp_bg home_b " style="display: block;"><a href="index.jsp" class="nav_padding"></a></li>
<li class="india_b ">
<h2><a href="http://indiatoday.intoday.in/section/114/1/india.html" class="nav_padding">India</a></h2>
</li>
<li class="world_b ">
<h2><a href="http://indiatoday.intoday.in/section/113/1/world.html" class="nav_padding">World</a></h2>
</li>
<li class="video_b ">
<h2><a href="http://indiatoday.intoday.in/videos" class="nav_padding">Videos</a></h2>
</li>
<li class="photo_b photos">
<h2><a href="http://indiatoday.intoday.in/galleries" class="nav_padding">Photos</a></h2>
</li>
<li class="cricket_b ">
<h2><a href="http://indiatoday.intoday.in/section/214/1/cricket.html" class="nav_padding">Cricket</a></h2>
</li>
<li class="movies_b ">
<h2><a href="http://indiatoday.intoday.in/section/67/1/movies.html" class="nav_padding">Movies</a></h2>
</li>
<li class="auto_b ">
<h2><a href="http://indiatoday.intoday.in/section/230/1/auto.html" class="nav_padding">Auto</a></h2>
</li>
<li class="sports_b ">
<h2><a href="http://indiatoday.intoday.in/section/84/1/sports.html" class="nav_padding">Sports</a></h2>
</li>
<li class="lifestyle_b ">
<h2><a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html" class="nav_padding">Lifestyle</a></h2>
</li>
<li class="tech_b ">
<h2><a href="http://indiatoday.intoday.in/technology/" class="nav_padding">Tech</a></h2>
</li>
<li class="edu_b ">
<h2><a href="http://indiatoday.intoday.in/education/" class="nav_padding">Education</a></h2>
</li>
<li class="business_b"><h2><a target="_blank" href="http://businesstoday.intoday.in/" class="nav_padding">Business</a></h2></li>
<li class="real_b"><h2><a class="nav_padding" target="_blank" href="http://indiatoday.magicbricks.com" onclick="_gaq.push(['_trackEvent', 'MAGICBRICKS', 'CLICK', '1']);return true;">Real Estate</a></h2></li>
<!--<li class="shop_b"><h2><a href="http://www.bagittoday.com/" target="_blank" class="shop" >Shop</a></h2></li>-->
</ul>
<div class="clear"></div>
</nav> </div>
<div class="main_header">
  <div class="container">
      <div class="logo">


      <div class="top_ad">

						<!-- Javascript tag: -->
<!-- begin ZEDO for channel: IT ROS Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1216/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT ROS Topnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->

</div>

      <div class="itg-logo">
      <a href="http://indiatodaygroup.com/" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday//microsites/greatoverland_adventure/Top-logo-1.jpg"></a>
            <a href="http://indiatodaygroup.com/" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday//microsites/greatoverland_adventure/Top-logo-2.png"></a>
                  <a href="http://indiatodaygroup.com/" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday//microsites/greatoverland_adventure/Top-logo-3.png"></a>
      </div>


      <div class="res-wrapper2">
    <div class="nav-ex">
      <ul class="cf">
        <li><a href="index.jsp">home</a></li>
        <li><a href="http://indiatoday.intoday.in/story/the-great-overland-adventure-from-stuttgart-to-pune-in-a-mercedes-gla/1/398410.html">about</a></li>
        <li><a href="http://indiatoday.intoday.in/category/gladventure/1/945.html">stories</a></li>
        <li><a href="http://indiatoday.intoday.in/videolist/gladventure/1/946.html">Videos</a></li>
        <li><a href="http://indiatoday.intoday.in/gallerylist/gladventure/1/133.html">Pictures</a></li>
        <li><a href="http://indiatoday.intoday.in/story/the-great-overland-adventure-from-stuttgart-to-pune-in-a-mercedes-gla/1/398410.html">Route Map</a></li>
        <li><a href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html">The Team</a></li>
      </ul>
    </div>
  </div>

      <a href="http://indiatoday.intoday.in/gladventure/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/logo.jpg"></a></div>
  </div>
  </div>


  <!--<div class="main_carousel">
  <div class="container">
  <div class="home_slider">
                  <div class="belt_outer">
                    <div class="belt">
                    <h5><a href="http://indiatoday.intoday.in/story/election-express-bus-live-blog/1/353126.html" ><div class="day"><div class="day-text">DAY 01</div> <div class="ddate">DELHI<br> 05.04.2014</div></div></a>  </h5>
                    <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-2/1/353214.html"> <div class="day"><div class="day-text">DAY 02</div><div class="ddate">Ghaziabad<br> 06.04.2014</div></div></a>  </h5>

                    <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-3-april-07-2014-lok-sabha-polls/1/353330.html"> <div class="day"><div class="day-text">DAY 03</div><div class="ddate" >Muzaffar Nagar 07.04.2014</div></div> </a> </h5>


					 <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-8-april-08-2014-lok-sabha-polls/1/353506.html"> <div class="day"><div class="day-text">DAY 04</div><div class="ddate" >Rampur <br> 08.04.2014</div></div> </a> </h5>


                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-5-bareilly/1/353691.html"> <div class="day"><div class="day-text">DAY 05</div><div class="ddate" >Bareilly <br> 09.04.2014</div></div> </a> </h5>

                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-6-lucknow/1/354908.html"> <div class="day"><div class="day-text">DAY 06</div><div class="ddate" >Lucknow <br> 10.04.2014</div></div> </a> </h5>

                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-7-amethi-rahul-gandhi/1/355061.html"> <div class="day"><div class="day-text">DAY 07</div><div class="ddate" >Amethi <br> 11.04.2014</div></div> </a> </h5>



     <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-8-gujarat-amethi/1/355373.html"> <div class="day"><div class="day-text">DAY 08</div><div class="ddate" ><br> 12.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-9-gujarat-narendra-modi-lok-sabha-polls/1/355482.html"> <div class="day"><div class="day-text">DAY 09</div><div class="ddate" ><br> 13.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-10-narendra-modi-mehsana-lok-sabha-polls/1/355611.html"> <div class="day"><div class="day-text">DAY 10</div><div class="ddate" >Mehsana<br> 14.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/live-blog-election-express-day-11-vadodara-narendra-modi/1/355767.html"> <div class="day"><div class="day-text">DAY 11</div><div class="ddate" >Vadodara<br> 15.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/election-express-mumbai-maharashtra-lok-sabha-polls-2014/1/356062.html"> <div class="day"><div class="day-text">DAY 12</div><div class="ddate" >Mumbai<br> 16.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/live-blog-election-express-day-13-mumbai/1/356183.html"> <div class="day"><div class="day-text">DAY 13</div><div class="ddate" >Mumbai<br> 17.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/day-14-election-express-to-reach-baramati-today-2014-lok-sabha-polls/1/356333.html"> <div class="day"><div class="day-text">DAY 14</div><div class="ddate" >Baramati<br> 18.04.2014</div></div> </a> </h5>

                   <h5><a href="#"> <div class="day"><div class="day-text">DAY 15</div><div class="ddate" >Mumbai<br> 19.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/day-16-election-express-in-chennai-lok-sabha-polls/1/356699.html"> <div class="day"><div class="day-text">DAY 16</div><div class="ddate" >Chennai<br> 20.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/election-express-goes-live-from-chennai-lok-sabha-polls/1/356795.html"> <div class="day"><div class="day-text">DAY 17</div><div class="ddate" >Chennai<br> 21.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/election-express-2014-lok-sabha-election-tirupati-andhra-pradesh-politics-telangana/1/357030.html
"> <div class="day"><div class="day-text">DAY 18</div><div class="ddate" >Tirupati<br>22.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/live-day-18-election-express-in-bangalore/1/357184.html"> <div class="day"><div class="day-text">DAY 19</div><div class="ddate" >Bangalore<br>23.04.2014</div></div> </a> </h5>


                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad/1/357288.html"> <div class="day"><div class="day-text">DAY 20</div><div class="ddate" >Hyderabad<br>24.04.2014</div></div> </a> </h5>

                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad/1/357494.html"> <div class="day"><div class="day-text">DAY 21</div><div class="ddate" >Hyderabad<br>25.04.2014</div></div> </a> </h5>

                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad-day-2/1/357957.html"> <div class="day"><div class="day-text">DAY 22</div><div class="ddate" >KCR TO ISB<br>26.04.2014</div></div> </a> </h5>

                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-kolkata/1/357840.html
"> <div class="day"><div class="day-text">DAY 23</div><div class="ddate" >Kolkata<br>27.04.2014</div></div> </a> </h5>

  <h5><a href="http://indiatoday.intoday.in/story/election-express-in-asansol-lok-sabha-elections-2014/1/358238.html
"> <div class="day"><div class="day-text">DAY 24</div><div class="ddate" >Asansol<br>29.04.2014</div></div> </a> </h5>

 <h5><a href="http://indiatoday.intoday.in/story/election-express-patna-bihar-gaya/1/358271.html
"> <div class="day"><div class="day-text">DAY 25</div><div class="ddate" >Patna<br>30.04.2014</div></div> </a> </h5>

 <h5><a href="http://indiatoday.intoday.in/story/election-express-gaya-chapra/1/358566.html
"> <div class="day"><div class="day-text">DAY 26</div><div class="ddate" >Chhapra<br>01.05.2014</div></div> </a> </h5>

 <h5><a href="http://indiatoday.intoday.in/story/election-express-day-27-catch-the-bus-here/1/358623.html
"> <div class="day"><div class="day-text">DAY 27</div><div class="ddate" >Bihar<br>02.05.2014</div></div> </a> </h5>



 <h5><a href="http://indiatoday.intoday.in/story/election-express-halts-at-battleground-amethi/1/359007.html"> <div class="day"><div class="day-text">DAY 28</div><div class="ddate" >Amethi<br>04.05.2014</div></div> </a> </h5>



 <h5><a href="http://indiatoday.intoday.in/story/election-express-in-amethi-on-day-30/1/359130.html"> <div class="day"><div class="day-text">DAY 31</div><div class="ddate" >Amethi<br>05.05.2014</div></div> </a> </h5>


 <h5><a href="http://indiatoday.intoday.in/story/election-express-in-azamgarh-day-32/1/359355.html"> <div class="day"><div class="day-text">DAY 32</div><div class="ddate" >Azamgarh<br>06.05.2014</div></div> </a> </h5>

  <h5><a href="http://indiatoday.intoday.in/story/election-express-varanasi-benaras-bhu-elections-2014-lok-sabha-polls-2014/1/359554.html"> <div class="day"><div class="day-text">DAY 33</div><div class="ddate" >Varanasi<br>07.05.2014</div></div> </a> </h5>

  <h5><a href="http://indiatoday.intoday.in/story/election-express-in-varanasi-narendra-modi-protest-roadshow/1/359620.html"> <div class="day"><div class="day-text">DAY 34</div><div class="ddate" >Varanasi<br>08.05.2014</div></div> </a> </h5>


  <h5><a href="http://indiatoday.intoday.in/story/day-35-election-express-in-varanasi-modi-kejriwal/1/359982.html"> <div class="day"><div class="day-text">DAY 35</div><div class="ddate" >Varanasi<br>09.05.2014</div></div> </a> </h5>

    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-varanasi/1/360084.html"> <div class="day "><div class="day-text">DAY 36</div><div class="ddate" >Varanasi<br>10.05.2014</div></div> </a> </h5>




<!-- <h5> <div class="day"><div class="day-text">DAY</div><div class="day-num">29</div></div>  </h5>
 <h5> <div class="day"><div class="day-text">DAY</div><div class="day-num">30</div></div>  </h5>


                    </div>
                  </div>
                  <span class="shprevarrow"></span> <span class="shnextarrow"></span>
                </div>
  </div>
  </div>-->
<!-- HOME SLIDER -->
<!-- HOME SLIDER END -->
<div class="container">
<div class="res-wrapper cf">
<div class="space"></div>
<div class="left-area">

<!--<div class="follow-me"><div class="follow-title story1"><h3>I Am Here</h3></div>

<img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/Bus-at-chennai.jpg">
</div>-->

<div class="follow-me"><div class="follow-title story1"><h3>THE TEAM</h3></div>
<div class="clear"></div>
<div class="map-continer">

<div class="row-team">
  <div class="left-img"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/teammember-dummy.jpg" width="93" height="114" border="0"></div>
  <div class="right-text"><p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p></div>
</div>
<div class="row-team">
  <div class="left-img"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/teammember-dummy.jpg" width="93" height="114" border="0"></div>
<div class="right-text"><p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p></div>
</div>




</div>
</div>
</div>


<div class="right-area">

<div class="item stayconnected">
    <p class="blueheader">STAY CONNECTED WITH US ON</p>
    <a href="http://www.facebook.com/indiatoday" target="_blank" rel="nofollow" title="Facebook"><span class="fb-icon"></span></a>
    <a href="http://www.twitter.com/indiatoday" target="_blank" rel="nofollow" title="Twitter"><span class="tw-icon"></span></a>
    <a href="http://www.google.com/+indiatoday" target="_blank" rel="nofollow" title="Google Plus"><span class="plus-icon"></span></a>
    <a href="http://indiatoday.intoday.in/site/rssFeed.jsp" target="_blank" rel="nofollow" title="RSS"><span class="rss-icon"></span></a>
    <a href="http://m.indiatoday.in/" target="_blank" rel="nofollow" title="Mobile"><span class="mobile-icon"></span></a>
    <a href="http://indiatoday.intoday.in/site/livetv.jsp" target="_blank" title="Live TV"><span class="tv-icon"></span></a>
    <div class="clear"></div>
</div>

<div class="right-add2">
 <div class="add-text">ADVERTISMENT</div>
<!-- begin ZEDO for channel:  IT Election Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1140/1137"; var zflag_sid="2"; var zflag_width="300"; var zflag_height="250"; var zflag_sz="9";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT Homepage Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
</div>


<div class="right-add_top"><span>#gladventure</span></div>
	<div class="tw-area" style="background:#4e2724;">
    <div class="right-add1">

<a class="twitter-timeline" width="300" height="432"  href="https://twitter.com/search?q=%23gladventure+OR+%40gladventour" data-widget-id="529524450874494976">Tweets about "#gladventure OR @gladventour"</a>
            <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
    </div>
    </div>
    <div class="clear"></div>
<div class="right-add_bottom"></div>



<div class="team_heading" >
    <div class="team"><span>The Team</span></div>
    <div style="position:relative" ><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/Team-image.jpg" width="300" height="521" usemap="#Map" />
      <map name="Map">
        <area shape="poly" coords="106,175,25,173,25,102,62,76,56,40,79,22,103,28,111,50,108,87,126,102,136,135,107,134" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip">
        <area shape="poly" coords="145,140,138,116,129,94,139,83,133,69,130,39,150,28,165,32,177,36,180,59,183,77,204,86,212,97,199,106,192,130,194,135,194,176,114,176,114,140" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip" >
        <area shape="poly" coords="200,174,199,132,202,110,215,102,214,88,202,75,206,35,228,28,251,36,258,72,257,96,282,116,283,171" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip" >
        <area shape="poly" coords="140,350,60,351,58,291,76,274,77,266,70,239,76,212,98,199,131,214,118,277,145,304" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip" alt="kingshuk dutta" title="kingshuk Dutta">
        <area shape="poly" coords="162,351,159,314,148,308,144,289,174,272,166,243,172,211,203,198,222,214,224,250,219,266,238,281,250,309,248,351" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip" >
        <area shape="poly" coords="34,461,81,440,71,409,78,377,99,368,125,379,127,410,122,443,165,458,172,478,145,486,143,512,60,515,57,483,29,477" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip" >
        <area shape="poly" coords="178,516,175,447,189,433,181,417,185,380,210,366,226,374,235,393,237,414,228,437,244,450,259,458,253,512" href="http://indiatoday.intoday.in/story/great-overland-adventure-meet-the-team/1/399059.html" class="hastip">
      </map>
    </div>
    <div><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/Team-bottom-band.png" width="300" height="23" /></div>
</div>

</div>
</div></div>
<footer class="footerwhite">
<style>
.sponsores-section{ background:#fff; padding:5px 0;}
.sponsores-section .bluebg{ background:#00ADEF; padding:20px 0;}
.spon-heading{ font-size:25px; color:#fff; width:165px; float:left; text-transform:uppercase; line-height:73px;}
.spong-image{ background:#fff; border-radius:10px; overflow:hidden; padding:2px 0;}
.spong-image img{ float:left;}
.spong-image ul li{ width:auto; float:left;}
.footnav {width: 900px;}
</style>

<div class="sponsores-section">
   <div class="bluebg">
     <div class="container">
        <!--<div class="spon-heading">Sponsors</div>-->
        <div class="spong-image">
           <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/greatoverland_adventure/gla-sponsors.gif" width="898">
        </div>

     </div>
   </div>
</div>

<div class="container">
<style>

.bottomad {
    margin-top: 5px;
    text-align: center;
}
.footertag, footer {
    background-color: #333333;
    overflow: hidden;
    position: relative;
    width: 100%;
}

.footertag nav, footer nav {
    background-color: #333333;
    color: #FFFFFF;
    float: left;
    font-size:13px;
    height: 43px;
    width: 77.5%;
}

.nav ul {
    margin: 0 auto;
    padding: 0;
}
nav ul {
    margin: 0 auto;
    padding: 0;
    position: relative;
    width: 1000px;
}
.home {
    background-color: #EB1C24;
    color: #FFFFFF;
    cursor: pointer;
}
.home {
    float: left;
    margin: 0 !important;
    padding: 0 !important;
}
.home a {
    background: url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/sprite-image.png") no-repeat scroll -311px -95px rgba(0, 0, 0, 0);
    display: inline-block;
    height: 43px;
    text-indent: -9999px;
    width: 27px;
}
.footertag nav ul li, footer nav ul li {
    background-color: #333333;
}
.nav ul li {
    float: left;
    list-style: none outside none;
    padding: 11px 0 !important;
    text-transform: uppercase;
}
.nav ul li a {
    padding: 0 6px !important;
	color: #FFFFFF; text-decoration:none
}
.nav ul li:hover, nav ul li.active {
    background-color: #D71920;
    color: #ffffff;
    cursor: pointer; text-decoration:none
}
.footertag .nav ul li a{ font-size:12px;}
</style>

<div class="bottomad">
	<div class="loadingad" >
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
<footer style="width: 1000px; margin: 15px auto 0 auto;">
<div class="footertag">
<img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/btm-logo.jpg" height="43" border="0" style="float:left;" >
<nav class="nav">
<ul>
<div class="home" style="background:none"><a href="http://indiatoday.intoday.in/index.jsp"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/home-cion.jpg" height="43"  border="0"></a></div>
<li ><a href="http://indiatoday.intoday.in/news.html" >News</a></li>
<li ><a href="http://indiatoday.intoday.in/section/114/1/india.html" >India</a>
<li ><a href="http://indiatoday.intoday.in/section/113/1/world.html" >World</a>
<li ><a href="http://indiatoday.intoday.in/videos" >Videos</a></li>
<li ><a href="http://indiatoday.intoday.in/galleries" >Photos</a></li>
<li ><a href="http://indiatoday.intoday.in/section/214/1/cricket.html" >Cricket</a></li>
<li ><a href="http://indiatoday.intoday.in/section/67/1/movies.html" >Movies</a></li>
<li ><a href="http://indiatoday.intoday.in/auto" >Auto</a></li>
<li ><a href="http://indiatoday.intoday.in/section/84/1/sports.html" >Sports</a></li>
<li ><a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html" >Lifestyle</a></li>
<li ><a href="http://indiatoday.intoday.in/technology" >Tech</a></li>
<li ><a href="http://indiatoday.intoday.in/education" >Education</a></li>
<li ><a href="http://businesstoday.intoday.in/"  target="_blank" >business</a></li>

</ul>
<div class="clear"></div>
</nav>

<div class="searc-icon1"><img style="margin-bottom:-5px;" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/btn-down-arrow.jpg"/>
<div id="footer1" style=" background-color:#fff">
	<iframe width="98%" scrolling="no" height="210" frameborder="0" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/microsites/common/common_it_footer.html"></iframe>
    </div>
  </div>
  </div>
</footer>
</div>
</div>


</div>
</footer>
<!--[if lt IE 9]>
<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
<script src="http://indiatoday.intoday.in/greatoverland-adventure/js/custom.js"></script>
<!--<div id="busleft" style=" position:fixed; left:0; top:30%; z-index:99999999999;"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/aajtak/static/tez/Bus-right.png" /></div>
<div id="busright" style=" position:absolute; right:0; top:80%; z-index:99999999999;"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/aajtak/static/tez/Bus-left.png" /></div>-->
<!--<script>
$(document).ready(function(){
	var widthtomove = (parseInt($(document).width()));//-parseInt($('#busleft').width()))-10;
	$('#busleft').animate({left:+widthtomove},10000);
	$('#busright').animate({right:+widthtomove},10000);
});
</script>-->
</body>
</html>
