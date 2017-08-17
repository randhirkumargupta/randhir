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
<title>Election Express - India Today</title>
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
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=/"+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=80&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:80px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=/"+contentURL+"&amp;size=m&amp;text="+escape(contentTitle)+"%20-%20India%20Today&amp;url=/"+contentURL+"&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=/"+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
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
.day-text { width:100%!important; text-align:center;}
h5 a { text-decoration:none!Important;}
.ddate {font-size: 15px; font-weight: normal;text-align: center; color:#fdff35; text-transform:uppercase}
.wt { color:#fff}
.day-active { background:#fca929!Important;}
.colum {
	width: 305px!Important;
	float: left;
	box-shadow: 2px 2px 10px 2px #CCCCCC;
	-moz-box-shadow: 2px 2px 10px 2px #CCCCCC;
	-webkit-box-shadow: 2px 2px 10px 2px #CCCCCC;
	}
</style>

 
<link href="/election-express/css/layout.css" rel="stylesheet" type="text/css" />
<script src="/staticpages/main/js/ajaxinclude.js"></script>
<div><iframe src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/intoday/mp-report-header/header.html" width="100%" frameborder="0" height="42"></iframe></div>
<div class="main_header">
  <div class="container">
      <div class="logo"><div class="itg-logo"><a href="http://indiatodaygroup.com/" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/itg-logo.png"></a></div><a href="/election-express/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/header_new.jpg"></a></div>
  </div>
  <div class="res-wrapper2"><div class="container nav-color">
    <div class="nav-ex">
      <ul class="cf">
        <li><a class="active" href="/">home</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/story/electionexpress-who-am-i/1/352705.html">WHO AM I</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/videolist/election-express/1/850.html">Visually Yours</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/gallerylist/election-express/1/121.html">Shutterbus</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/slideshows/the-electionexpress-electoons.html">my favourite electoons</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/subcategory/one-for-the-road/1/214.html">BUSPOST</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/elections/" target="_blank">Elections</a></li>
      </ul>
    </div>
  </div>
  </div></div>

  <div class="main_carousel">
  <div class="container">
  <div class="home_slider"> 
                  <div class="belt_outer">
                    <div class="belt">
                    <h5><a href="http://indiatoday.intoday.in/story/election-express-bus-live-blog/1/353126.html" ><div class="day"><div class="day-text">DAY 01</div> <div class="ddate">DELHI<br> 05.04.2014</div></div></a>  </h5>
                    <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-2/1/353214.html"> <div class="day"><div class="day-text">DAY 02</div><div class="ddate">Ghaziabad<br> 06.04.2014</div></div></a>  </h5>
                    
                    <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-3-april-07-2014-lok-sabha-polls/1/353330.html"> <div class="day"><div class="day-text">DAY 03</div><div class="ddate" style="line-height:16px;">Muzaffar Nagar 07.04.2014</div></div> </a> </h5>
					
					
					 <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-8-april-08-2014-lok-sabha-polls/1/353506.html"> <div class="day"><div class="day-text">DAY 04</div><div class="ddate" style="line-height:16px;">Rampur <br> 08.04.2014</div></div> </a> </h5>
                     
                     
                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-5-bareilly/1/353691.html"> <div class="day"><div class="day-text">DAY 05</div><div class="ddate" style="line-height:16px;">Bareilly <br> 09.04.2014</div></div> </a> </h5>
                   
                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-6-lucknow/1/354908.html"> <div class="day"><div class="day-text">DAY 06</div><div class="ddate" style="line-height:16px;">Lucknow <br> 10.04.2014</div></div> </a> </h5>
                      
                      <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-7-amethi-rahul-gandhi/1/355061.html"> <div class="day"><div class="day-text">DAY 07</div><div class="ddate" style="line-height:16px;">Amethi <br> 11.04.2014</div></div> </a> </h5>
                    
                       
                    
     <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-8-gujarat-amethi/1/355373.html"> <div class="day"><div class="day-text">DAY 08</div><div class="ddate" style="line-height:16px; "><br> 12.04.2014</div></div> </a> </h5>
                    
                   
                   <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-9-gujarat-narendra-modi-lok-sabha-polls/1/355482.html"> <div class="day"><div class="day-text">DAY 09</div><div class="ddate" style="line-height:16px;"><br> 13.04.2014</div></div> </a> </h5>
                   
                   
                   <h5><a href="http://indiatoday.intoday.in/story/election-express-live-blog-day-10-narendra-modi-mehsana-lok-sabha-polls/1/355611.html"> <div class="day"><div class="day-text">DAY 10</div><div class="ddate" style="line-height:16px; ">Mehsana<br> 14.04.2014</div></div> </a> </h5>
                   
                   <h5><a href="http://indiatoday.intoday.in/story/live-blog-election-express-day-11-vadodara-narendra-modi/1/355767.html"> <div class="day"><div class="day-text">DAY 11</div><div class="ddate" style="line-height:16px; ">Vadodara<br> 15.04.2014</div></div> </a> </h5>
                   
                   
                   <h5><a href="http://indiatoday.intoday.in/story/election-express-mumbai-maharashtra-lok-sabha-polls-2014/1/356062.html"> <div class="day"><div class="day-text">DAY 12</div><div class="ddate" style="line-height:16px; ">Mumbai<br> 16.04.2014</div></div> </a> </h5>
                   
                   <h5><a href="http://indiatoday.intoday.in/story/live-blog-election-express-day-13-mumbai/1/356183.html"> <div class="day"><div class="day-text">DAY 13</div><div class="ddate" style="line-height:16px; ">Mumbai<br> 17.04.2014</div></div> </a> </h5>
                   
                   
                   <h5><a href="http://indiatoday.intoday.in/story/day-14-election-express-to-reach-baramati-today-2014-lok-sabha-polls/1/356333.html"> <div class="day"><div class="day-text">DAY 14</div><div class="ddate" style="line-height:16px; ">Baramati<br> 18.04.2014</div></div> </a> </h5>
                   
                   <h5><a href="#"> <div class="day"><div class="day-text">DAY 15</div><div class="ddate" style="line-height:16px; ">Mumbai<br> 19.04.2014</div></div> </a> </h5>
                   
                   <h5><a href="http://indiatoday.intoday.in/story/day-16-election-express-in-chennai-lok-sabha-polls/1/356699.html"> <div class="day"><div class="day-text">DAY 16</div><div class="ddate" style="line-height:16px; ">Chennai<br> 20.04.2014</div></div> </a> </h5>
                   
                   <h5><a href="http://indiatoday.intoday.in/story/election-express-goes-live-from-chennai-lok-sabha-polls/1/356795.html"> <div class="day"><div class="day-text">DAY 17</div><div class="ddate" style="line-height:16px; ">Chennai<br> 21.04.2014</div></div> </a> </h5>


                   <h5><a href="http://indiatoday.intoday.in/story/election-express-2014-lok-sabha-election-tirupati-andhra-pradesh-politics-telangana/1/357030.html
"> <div class="day"><div class="day-text">DAY 18</div><div class="ddate" style="line-height:16px; ">Tirupati<br>22.04.2014</div></div> </a> </h5>

                   <h5><a href="http://indiatoday.intoday.in/story/live-day-18-election-express-in-bangalore/1/357184.html"> <div class="day"><div class="day-text">DAY 19</div><div class="ddate" style="line-height:16px; ">Bangalore<br>23.04.2014</div></div> </a> </h5>
                   
                   
                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad/1/357288.html"> <div class="day"><div class="day-text">DAY 20</div><div class="ddate" style="line-height:16px; ">Hyderabad<br>24.04.2014</div></div> </a> </h5>

                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad/1/357494.html"> <div class="day"><div class="day-text">DAY 21</div><div class="ddate" style="line-height:16px; ">Hyderabad<br>25.04.2014</div></div> </a> </h5>
                    
                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-hyderabad-day-2/1/357957.html"> <div class="day"><div class="day-text">DAY 22</div><div class="ddate" style="line-height:16px; ">KCR TO ISB<br>26.04.2014</div></div> </a> </h5>
                    
                    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-kolkata/1/357840.html
"> <div class="day"><div class="day-text">DAY 23</div><div class="ddate" style="line-height:16px; ">Kolkata<br>27.04.2014</div></div> </a> </h5>
 
  <h5><a href="http://indiatoday.intoday.in/story/election-express-in-asansol-lok-sabha-elections-2014/1/358238.html
"> <div class="day"><div class="day-text">DAY 24</div><div class="ddate" style="line-height:16px; ">Asansol<br>29.04.2014</div></div> </a> </h5>     

 <h5><a href="http://indiatoday.intoday.in/story/election-express-patna-bihar-gaya/1/358271.html
"> <div class="day"><div class="day-text">DAY 25</div><div class="ddate" style="line-height:16px; ">Patna<br>30.04.2014</div></div> </a> </h5>                   

 <h5><a href="http://indiatoday.intoday.in/story/election-express-gaya-chapra/1/358566.html
"> <div class="day"><div class="day-text">DAY 26</div><div class="ddate" style="line-height:16px; ">Chhapra<br>01.05.2014</div></div> </a> </h5>

 <h5><a href="http://indiatoday.intoday.in/story/election-express-day-27-catch-the-bus-here/1/358623.html
"> <div class="day"><div class="day-text">DAY 27</div><div class="ddate" style="line-height:16px; ">Bihar<br>02.05.2014</div></div> </a> </h5>



 <h5><a href="http://indiatoday.intoday.in/story/election-express-halts-at-battleground-amethi/1/359007.html"> <div class="day"><div class="day-text">DAY 28</div><div class="ddate" style="line-height:16px; ">Amethi<br>04.05.2014</div></div> </a> </h5>
 

 
 <h5><a href="http://indiatoday.intoday.in/story/election-express-in-amethi-on-day-30/1/359130.html"> <div class="day"><div class="day-text">DAY 31</div><div class="ddate" style="line-height:16px; ">Amethi<br>05.05.2014</div></div> </a> </h5>
 
 
 <h5><a href="http://indiatoday.intoday.in/story/election-express-in-azamgarh-day-32/1/359355.html"> <div class="day"><div class="day-text">DAY 32</div><div class="ddate" style="line-height:16px; ">Azamgarh<br>06.05.2014</div></div> </a> </h5>
 
  <h5><a href="http://indiatoday.intoday.in/story/election-express-varanasi-benaras-bhu-elections-2014-lok-sabha-polls-2014/1/359554.html"> <div class="day"><div class="day-text">DAY 33</div><div class="ddate" style="line-height:16px; ">Varanasi<br>07.05.2014</div></div> </a> </h5>
  
  <h5><a href="http://indiatoday.intoday.in/story/election-express-in-varanasi-narendra-modi-protest-roadshow/1/359620.html"> <div class="day"><div class="day-text">DAY 34</div><div class="ddate" style="line-height:16px; ">Varanasi<br>08.05.2014</div></div> </a> </h5>
 

  <h5><a href="http://indiatoday.intoday.in/story/day-35-election-express-in-varanasi-modi-kejriwal/1/359982.html"> <div class="day"><div class="day-text">DAY 35</div><div class="ddate" style="line-height:16px; ">Varanasi<br>09.05.2014</div></div> </a> </h5>
  
    <h5><a href="http://indiatoday.intoday.in/story/live-election-express-in-varanasi/1/360084.html"> <div class="day day-active"><div class="day-text">DAY 36</div><div class="ddate wt" style="line-height:16px; ">Varanasi<br>10.05.2014</div></div> </a> </h5>

 
 
 
<!-- <h5> <div class="day"><div class="day-text">DAY</div><div class="day-num">29</div></div>  </h5>
 <h5> <div class="day"><div class="day-text">DAY</div><div class="day-num">30</div></div>  </h5>-->
 
 
                    </div>
                  </div>
                  <span class="shprevarrow"></span> <span class="shnextarrow"></span>
                </div>
  </div>
  </div>
<!-- HOME SLIDER -->
<!-- HOME SLIDER END -->
<div class="container">
<div class="res-wrapper cf">
<div class="space"></div>
<div class="left-area">

<!--<div class="follow-me"><div class="follow-title story1"><h3>I Am Here</h3></div>

<img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/Bus-at-chennai.jpg">
</div>-->

<div class="follow-me"><div class="follow-title story1"><h3>I Am Here</h3></div>
<div class="autocop"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/autocop.jpg" width="150px" height="50px"></div>
<iframe src="http://autocopalerts.com/staticmap.aspx?i=865190016650809" width="636" height="390" scrolling="no"></iframe></div>





<div class='home-box'><div class='story-title story1'><h3><a href="/category/election-express/1/851.html">CONVERSATIONS</a></h3></div><div class='share'><a href='#'><img src='http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/share.jpg'></a></div><div class='home-box-img'><a href="/story/live-election-express-in-varanasi/1/360084.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/ee-varanasi_story_350_051014104343.jpg" width='305'></a></div><div class='home-box-title'><h3><a href="/story/live-election-express-in-varanasi/1/360084.html">Day 36: Catch political updates in Varanasi with Election Express</a></h3></div>		
<div class="share-story"><div class="share-icon" url="/story/live-election-express-in-varanasi/1/360084.html" ctitle="Day 36: Catch political updates in Varanasi with Election Express" style="display: block;"></div><ul id="360084" style="border: none; display: none;"></ul></div></div> 


  

<div class='home-box'><div class='story-title story1'><h3><a href="http://indiatoday.intoday.in/videolist/election-express/1/850.html">VISUALLY YOURS</a></h3></div><div class='share'><a href='#'><img src='http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/share.jpg'></a></div><li><div class='video-slider-content'><div class='home-box-img'><a href="/video/election-express-maninagar-divided-over-modis-invitation-to-nawaz/1/363143.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/modi-3-video_300x193_052314062337.jpg"></a></div><div class='home-box-title'><h3><a href="/video/election-express-maninagar-divided-over-modis-invitation-to-nawaz/1/363143.html">Election Express: Maninagar divided over Modi's invitation to Nawaz</a></h3></div>		


<div class="share-story">
  <div class="share-icon" url="/video/election-express-maninagar-divided-over-modis-invitation-to-nawaz/1/363143.html" ctitle="Election Express: Maninagar divided over Modi's invitation to Nawaz" style="display: block;"></div>
  <ul id="363143" style="border: none; display: none;">
    
  </ul>
</div>


</div>
</div>




<div class='home-box'><div class='story-title story1'><h3><a href="/category/election-express/1/851.html">BUSPOST</a></h3></div><div class='share'><a href='#'><img src='http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/share.jpg'></a></div><div class='home-box-img'><a href="/story/election-express-bus-post-sign-off-yourvote2014-poll-rallies/1/361471.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/bus1_350_051214064944.jpg" width='305'></a></div><div class='home-box-title'><h3><a href="/story/election-express-bus-post-sign-off-yourvote2014-poll-rallies/1/361471.html">ElectionExpress: Saw India the way it is, not the way we want to see it!</a></h3></div>		

<div class="share-story">
  <div class="share-icon" url="/story/election-express-bus-post-sign-off-yourvote2014-poll-rallies/1/361471.html" ctitle="ElectionExpress: Saw India the way it is, not the way we want to see it!" style="display: block;"></div>
  <ul id="361471" style="border: none; display: none;">
    
  </ul>
</div> 
		

 </div>


<div class="home-box">

<!--<div class="story-title story1"><h3><a href="http://indiatoday.intoday.in/slideshows/the-electionexpress-electoons.html">MY FAVOURITE ELECTOONS</a></h3></div>
<div class="share"><a href="#"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/share.jpg"></a></div>-->
<div class="home-box-img"><a href="http://indiatoday.intoday.in/slideshows/the-electionexpress-electoons.html"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election_express/images/cartoon-305.jpg"></a></div><!--<div class="home-box-title"><h3><a href="http://indiatoday.intoday.in/slideshows/the-electionexpress-electoons.html">When Election Express went to Toontown</a></h3></div>--></div>
</div>

<div class="right-area">
  <div class="right-add1">
  
  <a class="twitter-timeline"   width="300" height="432" href="https://twitter.com/ElectionExpress"  data-widget-id="452338829924388864">Tweets by @ElectionExpress</a>
    <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
    
</div>

 <div class="right-add2">
 <div class="add-text">ADVERTISMENT</div>
<!-- begin ZEDO for channel:  IT Election Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2132"; var zflag_sid="2"; var zflag_width="300"; var zflag_height="250"; var zflag_sz="9";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT Election Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 --></div>

	<script type="text/javascript">ajaxinclude("/election-express/chunk_shutterbus_photo.jsp")</script>

</div>
</div></div>
<footer><style>
.footnav {width: 900px;}
</style>
<div class="footer-ex">
  <div class="container">
    <div class="footnav">
      <ul class="cf">
        <li><a href="/">home</a></li>
        <li>|</li>
        <li><a href="http://indiatoday.intoday.in/subcategory/conversations/1/213.html">Conversations</a></li>
        <li>|</li>
        <li><a href="http://indiatoday.intoday.in/videolist/election-express/1/850.html">Visually Yours</a></li>
        <li>|</li>
        <li><a href="http://indiatoday.intoday.in/gallerylist/election-express/1/121.html">Shutterbus</a></li>
        <li>|</li>
        <li><a href="http://indiatoday.intoday.in/slideshows/the-electionexpress-electoons.html">my favourite electoons</a></li>
        <li>|</li>
        <li><a href="http://indiatoday.intoday.in/subcategory/one-for-the-road/1/214.html">BUSPOST</a></li>
        <li class="sep">|</li>
        <li><a href="http://indiatoday.intoday.in/elections/" target="_blank">Elections</a></li>
      </ul>
    </div>
    <div class="footer_add cf" align="center">
	<!-- begin ZEDO for channel: IT ROS Bottomnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="1217/1137"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel: IT ROS Bottomnav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
	
	</div>
  </div>
</div>
<div class="copyright_footer"><div class="container"><div class="footer-text">Copyright © 2014 Living Media India Limited. For reprint rights: <a target="_blank" href="http://www.syndicationstoday.com/">Syndications Today.</a></div></div></div></footer>
<!--[if lt IE 9]>
<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]--> 
<script src="/election-express/js/custom.js"></script>
<div id="busleft" style=" position:fixed; left:0; top:30%; z-index:99999999999;"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/aajtak/static/tez/Bus-right.png" /></div>
<div id="busright" style=" position:absolute; right:0; top:80%; z-index:99999999999;"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/aajtak/static/tez/Bus-left.png" /></div>
<script>
$(document).ready(function(){
	var widthtomove = (parseInt($(document).width()));//-parseInt($('#busleft').width()))-10;
	$('#busleft').animate({left:+widthtomove},10000);
	$('#busright').animate({right:+widthtomove},10000);
});
</script>
</body>
</html>






