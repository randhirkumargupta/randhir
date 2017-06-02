
<!doctype html>
<html>
<head>
<base href="/staticpages/applications/" />
<meta charset="utf-8">
<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
  ga('create', 'UA-795349-17', 'auto');
  ga('send', 'pageview');
</script>

<title>IndiaToday Apps</title>
<link href='http://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<link href="css/style.css" rel="stylesheet">
<style>
.popup-mobile {

  height: 440px;
}

.mobile-box {
  padding: 50px;
  width:auto !important;  margin: auto;
}

form {
 padding:0;
}
.error_msg{  font-size: 11px;
  color: #c00;
  padding-bottom: 1px;
  display: block;
  margin-bottom: 10px;
  margin-left: 71px;
  margin-top: -14px;
  float: left;
  width: 100%;}
/*.close{ display:none;}*/
</style>
<script src="http://code.jquery.com/jquery-1.7.0.min.js"></script>
<script src="js/custom.js"></script>
<script>
$(document).ready(function(e) {
	$('.content:first').show();
	$('ul#tab li a:last').addClass('current')
	$('ul#tab li a').click(function(){
		$('ul#tab li a').removeClass('current')
		$(this).addClass('current');
		$('.content').hide();
		var getAttr = $(this).attr('href');
		$(getAttr).show();
		return false;
	});
});
</script>


</head>

<body>
<div class="trans"></div>
<div class="popup">
 <div class="close"><a href="#">X</a></div>
 <h2>Android</h2>
 <div class="home-slider-popup">
      <div class="prev-popup"></div>
      <div class="next-popup"></div>
    <div class="belt-outer-popup">

      <ul class="belt-popup">
      <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=in.AajTak.headlines" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Aajtak-176x176.png" width="144"></a>Aaj Tak</div></li>
     <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=com.indiatoday&hl=en" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/it-app.jpg" width="144"></a>India Today</div></li>
     <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=in.hlt.headlines" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/HT-176x176.png" width="144"></a>Headlines Today</div></li>
     <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=com.businesstoday" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/BT-176x176.png" width="144"></a>Business Today</div></li>
     <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=com.itg.cosmopolitan" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Cosmo-176x176.png" width="144"></a>Cosmopoliton</div></li>
    <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=com.readwhere.whitelabel.mailtoday" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Mail-today-176x176.png" width="144"></a>Mail Today</div></li>
    <li><div class="box-popup"><a href="https://play.google.com/store/apps/details?id=com.itgd.newsflick" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Newsflick-176x176.png" width="144"></a>NewsFlicks</div></li>
      </ul>

    </div>
  </div>
</div>

<div class="popup-ios">
 <div class="close-ios"><a href="#">X</a></div>
 <h2>iOS</h2>
 <div class="home-slider-popup">
      <div class="prev-popup"></div>
      <div class="next-popup"></div>
    <div class="belt-outer-popup">

      <ul class="belt-popup">
<li><div class="box-popup"><a href="https://itunes.apple.com/in/app/aaj-tak/id493319791?mt=8" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Aajtak-176x176.png" width="144"></a>Aaj Tak</div></li>
<li><div class="box-popup"><a href="https://itunes.apple.com/in/app/india-today-live/id510733452?mt=8" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/it-app.jpg" width="144"></a>India Today</div></li>
<li><div class="box-popup"><a href="https://itunes.apple.com/in/app/headlines-today/id493304768?mt=8" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/HT-176x176.png" width="144"></a>Headlines Today</div></li>
<li><div class="box-popup"><a href="https://itunes.apple.com/in/app/business-today-live/id510626540?mt=8" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/BT-176x176.png" width="144"></a>Business Today</div></li>
<li><div class="box-popup"><a href="https://itunes.apple.com/us/app/cosmopolitan-in/id733762097?ls=1&mt=8" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Cosmo-176x176.png" width="144"></a>Cosmopoliton</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Mail-today-176x176.png" width="144"></a>Mail Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Newsflick-176x176.png" width="144"></a>NewsFlicks
</div></li>

      </ul>

    </div>
  </div>
</div>

<div class="popup-bb">
 <div class="close-bb"><a href="#">X</a></div>
 <h2>Backberry</h2>
 <div class="home-slider-popup">
      <div class="prev-popup"></div>
      <div class="next-popup"></div>
    <div class="belt-outer-popup">
      <ul class="belt-popup">
<li><div class="box-popup"><a href="http://appworld.blackberry.com/webstore/content/26085872/?countrycode=IN&countrycode=IN&lang=en" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Aajtak-176x176.png" width="144"></a>Aaj Tak</div></li>
<li><div class="box-popup"><a href="http://appworld.blackberry.com/webstore/content/128334/?lang=en" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/it-app.jpg" width="144"></a>India Today</div></li>
<li><div class="box-popup"><a href="http://appworld.blackberry.com/webstore/content/98803/?lang=en" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/HT-176x176.png" width="144"></a>Headlines Today</div></li>
<li><div class="box-popup"><a href="http://appworld.blackberry.com/webstore/content/79054/?lang=en" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/BT-176x176.png" width="144"></a>Business Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Cosmo-176x176.png" width="144"></a>Cosmopoliton</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Mail-today-176x176.png" width="144"></a>Mail Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps//Newsflick-176x176.png" width="144"></a>Newsflicks</div></li>
      </ul>
    </div>
  </div>
</div>

<div class="popup-windows">
 <div class="close-windows"><a href="#">X</a></div>
 <h2>Windows</h2>
 <div class="home-slider-popup">
      <div class="prev-popup"></div>
      <div class="next-popup"></div>
    <div class="belt-outer-popup">
      <ul class="belt-popup">
<li><div class="box-popup"><a href="http://www.windowsphone.com/en-in/store/app/aajtak/eee0afc3-32ef-454d-8fd4-bb45901348b7" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Aajtak-176x176.png" width="144"></a>Aaj Tak</div></li>
<li><div class="box-popup"><a href="http://www.windowsphone.com/en-us/store/app/indiatoday/ced3e1db-dd84-42db-8bcf-e355ad85cd7b" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/it-app.jpg" width="144"></a>India Today</div></li>
<li><div class="box-popup"><a href="http://www.windowsphone.com/en-in/store/app/headlines-today/fd57be7c-d607-4d42-b6cf-1068fea9e9a5" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/HT-176x176.png" width="144"></a>Headlines Today</div></li>
<li><div class="box-popup"><a href="http://www.windowsphone.com/en-us/store/app/businesstoday/89dbf8fc-9b05-4232-acfc-1fb34b8a509f" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/BT-176x176.png" width="144"></a>Business Today</div></li>
<li><div class="box-popup"><a href="http://www.windowsphone.com/en-in/store/app/cosmopolitan/86b13e6a-c18b-48fc-b770-6b06996c95b6" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Cosmo-176x176.png" width="144"></a>Cosmopoliton</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Mail-today-176x176.png" width="144"></a>Mail Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Newsflick-176x176.png" width="144"></a>News Flicks</div></li>

      </ul>
    </div>
  </div>
</div>

<div class="popup-ovi">
 <div class="close-ovi"><a href="#">X</a></div>
 <h2>OVI</h2>
 <div class="home-slider-popup">
      <div class="prev-popup"></div>
      <div class="next-popup"></div>
    <div class="belt-outer-popup">
      <ul class="belt-popup">
<li><div class="box-popup"><a href="http://store.ovi.com/content/50709" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Aajtak-176x176.png" width="144"></a>Aaj Tak</div></li>
<li><div class="box-popup"><a href="http://store.ovi.com/content/6393" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/it-app.jpg" width="144"></a>India Today</div></li>
<li><div class="box-popup"><a href="http://store.ovi.com/content/214165" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/HT-176x176.png" width="144"></a>Headlines Today</div></li>
<li><div class="box-popup"><a href="http://store.ovi.com/content/129458" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/BT-176x176.png" width="144"></a>Business Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Cosmo-176x176.png" width="144"></a>Cosmopoliton</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Mail-today-176x176.png" width="144"></a>Mail Today</div></li>
<li><div class="box-popup"><a href="#" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/Newsflick-176x176.png" width="144"></a>Aaj Tak</div></li>
      </ul>
    </div>
  </div>
</div>

<!-- include mobile-form file -->
<?php require("mobile-form.html"); ?>
<!-- end include mobile-form file -->

<div class="os-icon android">Android</div>
<div class="os-icon apple">iOS</div>
<div class="os-icon blackb">Blackberry</div>
<div class="os-icon windows">Windows</div>
<div class="os-icon ovi">OVI</div>


<!--topnav start-->
<div class="container topnav cf">
 <div class="wrapper">
 <div class="itgd_links" id="top-web">
<ul>
<li class="last"><a href="http://indiatodaygroup.com/" target="_blank" rel="nofollow">THE INDIA TODAY GROUP</a></li>
<li><a href="http://www.indiatoday.in/" target="_blank" class="mainlevel" rel="nofollow">India Today</a></li>
<li><a href="http://www.aajtak.in/" target="_blank" class="mainlevel" rel="nofollow">Aaj Tak</a></li>
<!--<li><a href="http://www.headlinestoday.in/" target="_blank" class="mainlevel" rel="nofollow">Headlines Today</a></li>-->
<li><a href="http://www.businesstoday.in/" target="_blank" class="mainlevel" rel="nofollow">Business Today</a></li>
<li><a href="http://www.menshealthindia.in/" target="_blank" class="mainlevel" rel="nofollow">Men's Health</a></li>
<li><a href="http://www.wonderwoman.in" target="_blank" class="mainlevel" rel="nofollow">Wonder Woman</a></li>
<li><a href="http://www.cosmopolitan.in/" target="_blank" class="mainlevel" rel="nofollow">Cosmopolitan</a></li>
<li><a href="http://oyefm.in/" target="_blank" class="mainlevel" rel="nofollow">Oye! 104.8FM</a></li>
<li><a href="http://travelplus.intoday.in" target="_blank" class="mainlevel" rel="nofollow">Travel Plus</a></li>
<li class="last"><a href="http://www.bagittoday.com/" target="_blank" class="mainlevel" rel="nofollow">Bag it Today</a></li>
</ul>
<div class="cf"></div>
</div>
 </div>
</div>
<!--topnav end-->

<!--header start-->
<div class="container cf">
 <div class="wrapper header cf">
   <div class="logo"><a href="/applications/index.jsp">India Today</a></div>
   <div class="ad-top">
        <!-- Javascript tag: -->
        <!-- begin ZEDO for channel:  IT App ROS Topnav LB , publisher: India Today App , Ad Dimension: Super Banner - 728 x 90 -->
        <script language="JavaScript">
        var zflag_nid="821"; var zflag_cid="2320"; var zflag_sid="4"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
        </script>
        <script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
        <!-- end ZEDO for channel:  IT App ROS Topnav LB , publisher: India Today App , Ad Dimension: Super Banner - 728 x 90 -->
   </div>
 </div>
</div>
<!--header end-->

<!-- include navigation menu file -->
<?php require("navigation.html"); ?>
<!-- end include navigation menu file -->

<!-- <link href='https://fonts.googleapis.com/css?family=Roboto:400,700' rel='stylesheet' type='text/css'> -->
<style>
/*body{ font-family:"Roboto";}*/
.margintop40{ margin-top:40px;}
.wrapper_apps{ width:1000px; margin:0 auto;}
.wrapper_apps .cont_hh_apps{ width:100%; float:left; box-sizing:border-box; margin-bottom:40px; }
.wrapper_apps .cont_hh_apps .hdn_apps{}
.wrapper_apps .cont_hh_apps .hdn_apps h3{ font-size:18px; margin:0; padding:0; background:#c00; color:#fff; display:inline-block; padding:5px 10px; border-top-right-radius:5px; border-top-left-radius:5px;}
.wrapper_apps .cont_hh_apps .cont_apps{width:970px; float:left; padding:15px;background:#fff;box-shadow:0 0 3px #ccc;}
.wrapper_apps .cont_hh_apps .cont_apps .row_apps{ width:100%; float:left;  }
.wrapper_apps .cont_hh_apps .cont_apps .row_apps a{ border:0; outline:none;}
.wrapper_apps .cont_hh_apps .cont_apps .row_apps .app_img{ float:left;}
.wrapper_apps .cont_hh_apps .cont_apps .row_apps .app_img.amazon{width:247px; margin-right:47px;}
.indiatoday_h{ margin-bottom:30px;}
.indiatoday_h img{width:100%; float:left;}
.indiatoday_h .amazon{width:248px; margin-right:45px; margin-top:10px;}
.indiatoday_h .tikilive{width:171px; margin-right:70px;margin-top:10px;}
.indiatoday_h .vidilion{width:162px;margin-right:34px;}
.indiatoday_h .chromecast{width:198px;margin-top:10px;}
.indiatoday_h .flipps{width:161px; margin-top:12px; margin-right:12px;}
.indiatoday_h .android{width:115px; margin-right:15px; margin-top: 12px;}
.indiatoday_h .googleplay{width:108px; margin-right:68px;}
.indiatoday_h .roku{width:176px; margin-right:68px; margin-top:10px;}
.indiatoday_h .ios{width:100px; }

.common_h img{width:100%; float:left;}
.common_h .chromecast{ width:226px; margin-right:0; margin-top:5px;}
.common_h .flipps{ width:160px; margin-right:20px;}
.common_h .roku{width:170px; margin-right:40px;}
.common_h .tikilive{width:160px; margin-right:20px;margin-top:10px;}
.common_h .vidilion{width:161px;}
.clearfix{ clear:both;}


</style>
<!--body area start-->
<div class="wrapper_apps">
  <div class="cont_hh_apps margintop40">
    <div class="hdn_apps">
      <h3>India Today</h3>
    </div>
    <div class="cont_apps">
      <div class="row_apps indiatoday_h"> <span class="app_img amazon"> <a target="_blank"  href="http://www.amazon.com/Vidillion-India-Today-Channels/dp/B015G7UYEI" title="Amazon fire"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/amazon-fire.jpg" alt="apps" /> </a> </span> <span class="app_img tikilive"> <a target="_blank"  href="http://www.tikilive.com/tiki-blog/hd-live-video-streaming/watch-live-streaming-inhdfor-free" title="TIKILIVE"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/tikilive.jpg" alt="apps" /> </a> </span> <span class="app_img vidilion"> <a target="_blank"  href="http://vidillion.tv/indiatoday/indiatoday.html" title="viDillion"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/vidillion.jpg" alt="apps" /> </a> </span> <span class="app_img chromecast"> <a target="_blank"  href="http://www.vidillion.tv/indiatoday/indiatoday.html" title="chromecast"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/chromecast.jpg" alt="apps" /> </a> </span> </div>
      <div class="row_apps indiatoday_h"> <span class="app_img flipps"> <a target="_blank"  href="http://www.flipps.com" title=""> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/flipps.jpg" alt="apps" /> </a> </span> <span class="app_img android"> <a target="_blank"  href="https://play.google.com/store/apps/details?id=com.vidillion.livingmediaindia" title="Android"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/android.jpg" alt="apps" /> </a> </span> <span class="app_img googleplay"> <a target="_blank"  href="https://play.google.com/store/apps/details?id=com.vidillion.livingmediaindia" title="Google Play"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/googleplay.jpg" alt="apps" /> </a> </span> <span class="app_img roku"> <a target="_blank"  href="https://my.roku.com/account/add?channel=INDIATODAY" title="Roku"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/roku.jpg" alt="apps" /> </a> </span> <span class="app_img ios"> <a target="_blank"  href="https://itunes.apple.com/de/app/india-today-channels/id992814247?l=en&mt=8" title="ios"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/ios.jpg" alt="apps" /> </a> </span> </div>
    </div>
  </div>
  <div class="cont_hh_apps">
    <div class="hdn_apps">
      <h3>Aaj Tak</h3>
    </div>
    <div class="cont_apps">
      <div class="row_apps common_h"> <span class="app_img chromecast"> <a target="_blank"  href="http://www.vidillion.tv/indiatoday/aajtak.html" title="chromecast"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/chromecast.jpg" alt="apps" /> </a> </span> <span class="app_img flipps"> <a target="_blank"  href="http://www.flipps.com" title="flipps"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/flipps.jpg" alt="apps" /> </a> </span> <!--<span class="app_img roku"> <a target="_blank"  href="#" title="Roku"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/roku.jpg" alt="apps" /> </a> </span>--> <span class="app_img tikilive"> <a target="_blank"  href="#" title="TIKILIVE"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/tikilive.jpg" alt="apps" /> </a> </span> <span class="app_img vidilion"> <a target="_blank"  href="http://vidillion.tv/indiatoday/aajtak.html" title="vidillion"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/vidillion.jpg" alt="apps" /> </a> </span> </div>
    </div>
  </div>
  <div class="cont_hh_apps">
    <div class="hdn_apps">
      <h3>Delhi Aaj Tak</h3>
    </div>
    <div class="cont_apps">
      <div class="row_apps common_h"> <span class="app_img chromecast"> <a target="_blank"  href="http://www.vidillion.tv/indiatoday/dilliaajtak.html" title="chromecast"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/chromecast.jpg" alt="apps" /> </a> </span> <span class="app_img flipps"> <a target="_blank"  href="http://www.flipps.com" title="flipps"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/flipps.jpg" alt="apps" /> </a> </span> <!--<span class="app_img roku"> <a target="_blank"  href="#" title="Roku"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/roku.jpg" alt="apps" /> </a> </span>--> <span class="app_img tikilive"> <a target="_blank"  href="#" title="TIKILIVE"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/tikilive.jpg" alt="apps" /> </a> </span> <span class="app_img vidilion"> <a target="_blank"  href="http://vidillion.tv/indiatoday/dilliaajtak.html" title="vidillion"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/vidillion.jpg" alt="apps" /> </a> </span> </div>
    </div>
  </div>
  <div class="cont_hh_apps">
    <div class="hdn_apps">
      <h3>Tez</h3>
    </div>
    <div class="cont_apps">
      <div class="row_apps common_h"> <span class="app_img chromecast"> <a target="_blank"  href="http://www.vidillion.tv/indiatoday/tez.html" title="chromecast"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/chromecast.jpg" alt="apps" /> </a> </span> <span class="app_img flipps"> <a target="_blank"  href="http://www.flipps.com" title="flipps"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/flipps.jpg" alt="apps" /> </a> </span> <!--<span class="app_img roku"> <a target="_blank"  href="#" title="Roku"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/roku.jpg" alt="apps" /> </a> </span>--> <span class="app_img tikilive"> <a target="_blank"  href="#" title="TIKILIVE"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/tikilive.jpg" alt="apps" /> </a> </span> <span class="app_img vidilion"> <a target="_blank"  href="http://vidillion.tv/indiatoday/tez.html" title="vidillion"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/indiatoday-apps/iptv-ott/vidillion.jpg" alt="apps" /> </a> </span> </div>
    </div>
  </div>
 <div class="clearfix"></div>
</div>
<!--body area end -->


<div class="footer_img"></div>

<!--footer start -->
<?php require("footer.html"); ?>
<!-- footer ends -->

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


</body>
</html>
