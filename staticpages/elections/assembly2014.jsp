


<!DOCTYPE HTML>
<html>
<head>
<!--<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />-->
<title>India Today - Elections 2014</title>
<meta name="description" content="Description: Get the latest General Election news, videos, photos, polling schedule, ground report and analysis. Stay tuned with the live election news updates, key candidates, campaign trails and polling." />
<meta name="keywords" content="India elections, election news, Lok Sabha polls 2014, India election 2014, lok sabha elections, indian general election 2014, elections in india, lok sabha polls, election 2014, Polls 2014, Key candidates 2014" />
<!-- disable iPhone inital scale -->
<meta name="viewport" content="width=device-width; initial-scale=1.0" />
<link href="/elections/assembly/2015/bihar/css/homepage-new.css" type="text/css" rel="stylesheet" />
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />
<link rel='shortcut icon' type='image/x-icon' href='http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/dot-in-fav-icon.ico' />
<!-- html5.js for IE less than 9 -->
<!--[if lt IE 9]>
	<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
<!-- css3-mediaqueries.js for IE less than 9 -->
<!--[if lt IE 9]>
	<script src="http://css3-mediaqueries-js.googlecode.com/svn/trunk/css3-mediaqueries.js"></script>
<![endif]-->
<!--<link href="http://indiatoday.intoday.in/css/responsive.css" type="text/css" rel="stylesheet" />-->
<link rel="canonical" href="/" />
<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/jquery.min.1.8.2.js" type="text/javascript"></script>
<link href="/elections/assembly/2015/bihar/css/election-style.css" type="text/css" rel="stylesheet" />
 <script src="/elections/assembly/2015/bihar/js/maps2.js" type="text/javascript"></script>
<script src="/elections/assembly/2015/bihar/js/highcharts.js"></script>
<!-- <script>
$(document).ready(function(){
  $("#allianceTable tr:even").css("background-color","#ffffff");
  $("#allianceTable tr:odd").css("background-color","#f2f2f2");
});
</script> -->
<script>
function loadPieAssemblyAllianceSmallContainer(a)
{
var aURL = domain+fpath+"alliance/"+a+"-assembly-alliance.json";
//alert(aURL);
$.ajax({type: "GET",url: aURL,dataType: "jsonp",crossDomain: true,jsonpCallback: 'e'+a.replace("-","")+'2014',success: function (data)
{

	  var combined = [];
	  var colorArray=[];
	var aName = data.loksabha.aName;
	var aSeats = data.loksabha.aSeats;
	for(var x = 0;x < data.loksabha.items.length; x++)
	 {
	  colorArray[x]=data.loksabha.items[x].pColor;
	  combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))])
	 }

	//$(function () {
    $('#pieAllianceSmallContainer_'+a).highcharts({
		colors:colorArray,
        chart: {
            plotBackgroundColor: null,
            plotBorderWidth: 0,
            plotShadow: false
        },
        title: {
            text: aName+'('+aSeats+')',
            align: 'center',
            verticalAlign: 'middle',
            y: 15
        },
        tooltip: {
				enabled: true,
            pointFormat: '<b>{point.y}</b>'
        },
        plotOptions: {
            pie: {
                dataLabels: {
                    enabled: false,
                    distance: -50,
                    style: {
                        fontWeight: 'bold',
                        color: 'white',
                        textShadow: '0px 1px 2px black'
                    }
                },
                startAngle: -90,
                endAngle: 90,
                center: ['50%', '55%']
            }
        },
        series: [{
            type: 'pie',
            name: '',
            innerSize: '60%',
            data:combined
        }]
    });
//});
}

});


}
function getAllianceAssemblyDetails(a)
{
var aURL = domain+fpath+"alliance/"+a+"-assembly-alliance.json";
//alert(aURL);
$.ajax({type: "GET",url: aURL,dataType: "jsonp",crossDomain: true,jsonpCallback: 'e'+a.replace("-","")+'2014',success: function (data)
{
	var tARow= '<tbody><tr style="height:50px;background-color:#f2f2f2;"><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>';

	  var combined = [];
	  var colorArray=[];
	var aName = data.loksabha.aName;
	var aNameOthers = "Others";
	var aSeats = data.loksabha.aSeats;
	var aSeatOthers = data.loksabha.aSeatOthers;

 for(var x = 0;x < data.loksabha.items.length; x++)
 {
	 if(x%2==0)
	 {
     tARow += '<tr style="background-color:#ffffff;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';

	 }else{
     tARow += '<tr style="background-color:#f2f2f2;"><td>'+data.loksabha.items[x].pName+'</td><td>'+data.loksabha.items[x].pLead+'</td><td>'+data.loksabha.items[x].pWon+'</td><td>'+(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))+'</td></tr>';
	 }

  colorArray[x]=data.loksabha.items[x].pColor;
  combined.push([data.loksabha.items[x].pName,(parseInt(data.loksabha.items[x].pLead) + parseInt(data.loksabha.items[x].pWon))])

 }

loadPieAllianceBigContainer1(aName,aSeats,aSeatOthers,combined,colorArray);
 $("#allianceTable").html(tARow+"</tbody>");
}
});

}

</script>
</head>
<body >
<div id="amlesh">
<div class="itgd_links" id="top-web">
<ul>
<li class="last"><a href="http://indiatodaygroup.com/" target="_blank" rel="nofollow">THE INDIA TODAY GROUP</a></li>
<li><a href="http://www.indiatoday.in/" target="_blank" class="mainlevel" rel="nofollow">India Today</a></li>
<li><a href="http://www.aajtak.in/" target="_blank" class="mainlevel" rel="nofollow">Aaj Tak</a></li>
<li><a href="http://www.businesstoday.in/" target="_blank" class="mainlevel" rel="nofollow">Business Today</a></li>
<li><a href="http://www.menshealthindia.in/" target="_blank" class="mainlevel" rel="nofollow">Men's Health</a></li>
<li><a href="http://www.wonderwoman.in" target="_blank" class="mainlevel" rel="nofollow">Wonder Woman</a></li>
<li><a href="http://www.cosmopolitan.in/" target="_blank" class="mainlevel" rel="nofollow">Cosmopolitan</a></li>
<li><a href="http://oyefm.in/" target="_blank" class="mainlevel" rel="nofollow">Oye! 104.8FM</a></li>
<li class="last"><a href="http://travelplus.intoday.in" target="_blank" class="mainlevel" rel="nofollow">Travel Plus</a></li>
</ul></div>
<div class="clr"></div>



<script type="text/javascript">
$(document).ready(function(e) {
$('.searc-icon').click(function(){
		$('#search-saction').slideToggle('slow');
	});
});
</script>
<div class="menues">
<nav>
<div class="app sp_bg"><a href="http://indiatoday.intoday.in/">Indiatoday</a></div>
<ul>
<li class="home-icon sp_bg home_b active"  ><a href="http://indiatoday.intoday.in/index.jsp" ></a></li>
<li class="india_b " >

<a href="http://indiatoday.intoday.in/section/114/1/india.html" >India</a>


</li>
<li class="world_b " >

<a href="http://indiatoday.intoday.in/section/113/1/world.html" >World</a>

</li>
<li class="video_b " >

<a href="http://indiatoday.intoday.in/videos" >Videos</a>

</li>
<li class="photo_b " >

<a href="http://indiatoday.intoday.in/galleries" >Photos</a>

</li>
<li class="cricket_b " >

<a href="http://indiatoday.intoday.in/section/214/1/cricket.html" >Cricket</a>

</li>
<li class="movies_b " >

<a href="http://indiatoday.intoday.in/section/67/1/movies.html" >Movies</a>

</li>
<li class="auto_b "  >

<a href="http://indiatoday.intoday.in/section/230/1/auto.html" >Auto</a>

</li>
<li class="sports_b " >

<a href="http://indiatoday.intoday.in/section/84/1/sports.html" >Sports</a>

</li>
<li class="lifestyle_b " style="padding-right:3px;"   >

<a href="http://indiatoday.intoday.in/section/103/1/lifestyle.html" >Lifestyle</a>

</li>
<li class="tech_b " style="padding-right:3px;"   >

<a href="http://indiatoday.intoday.in/section/229/1/technology.html" class="edu"   >Tech</a>

</li>
<li class="edu_b " style="padding-right:3px;" >

<a href="http://indiatoday.intoday.in/education/" class="edu"   >Education</a>

</li>

<li class="business_b"><a href="http://businesstoday.intoday.in/" target="_blank" class="edu" >Business</a></li>
</ul>
<div class="searc-icon">Search</div>
<div class="clear"></div>

</nav>

<div id="search-saction">
<div class="search-inner">
<form action="http://indiatoday.intoday.in/advanced_search.jsp" method="get" name="searchform1" onsubmit="return validate1();" style="margin:0;padding:0;">
<input name="option" value="com_search" type="hidden">
<input type="text" class="input-box" name="searchword" id="mod_search_searchword"  value="Type Your search" onblur="if(this.value=='') this.value='Type Your search';" onfocus="if(this.value=='Type Your search') this.value='';">
<input name="" type="submit" class="submit-btn" value="search" />
</form>
</div>
</div>
 </div>
 <div class="clr"></div>
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
  <img src="http://b.scorecardresearch.com/p?c1=2&c2=8549097&cv=2.0&cj=1"  />
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

<header>
<div class="logo"><a href="http://indiatoday.intoday.in/elections/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/Logo.png"></a></div>
<div class="ad">
<!-- begin ZEDO for channel:  IT Election Top nav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2131"; var zflag_sid="2"; var zflag_width="728"; var zflag_height="90"; var zflag_sz="14";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT Election Top nav LB , publisher: India Today , Ad Dimension: Super Banner - 728 x 90 -->


</div>
</header>

<div class="subnav">
	<ul>
    	<li><a href="http://indiatoday.intoday.in/category/highlights/1/799.html" target="_blank" class="active">news</a></li>
        <li><a href="http://indiatoday.intoday.in/category/diary/1/776.html" target="_blank">poll diary</a></li>
        <li><a href="http://indiatoday.intoday.in/category/ground-report/1/798.html" target="_blank">ground report</a></li>
        <li><a href="http://indiatoday.intoday.in/videos" target="_blank">videos</a></li>
        <li><a href="http://indiatoday.intoday.in/galleries" target="_blank">photos</a></li>
	<li><a href="http://indiatoday.intoday.in/voter-election/" target="_blank">Election Helpline</a></li>
    </ul>
</div>

</div>
 <div class="clr"></div>



<div class="beaking_news">
<script type="text/javascript" async>ajaxinclude("http://indiatoday.intoday.in/chunk_breakingnews.jsp")</script>
</div>
<div class="clear"></div>
<div id="main_container" style="position:relative; ">
<div id="wapper">

 <style>
.top-strip-one {overflow:hidden; width:1000px; margin:0 auto}
.top-strip-one span {

    float: left;
    height: 38px;
}
.top-strip-one h2 {
    background-color: #000000;
    color: #FFFFFF;
    float: left;
    font-family: Roboto,sans-serif;
    font-size: 18px;
    padding: 4px 12px 4px 12px;
    text-transform: uppercase;
	margin:8px 0 0 0;
	border-right:1px solid #ccc;
}
.top-strip-one h3 {
    background-color: #6E6F73;
    color: #FFFFFF;
    float: left;
    font-family: Roboto,sans-serif;
    font-size: 18px;
	margin:8px 0 0 0;
    padding: 4px 13px 4px 13px;
    text-transform: uppercase;
	border-right:1px solid #ccc; margin-bottom:10px
}
.top-strip-one h3 a, .top-strip-one h2 a { color: #FFFFFF; text-decoration:none; }


</style>
<div class="top-strip-one">
        <h3 style='margin-left:12px;'><a href="/elections/2014/fullhousecompare.html" target="_blank">Full house</a></h3>
        <h2>Alliance Tally</h2>
        <h3><a href="/elections/2014/state/delhi.html" target="_blank">State Wise Results</a></h3>
        <h3><a href="http://indiatoday.intoday.in/elections/2014/indiamaps.html" target="_blank">Overall Seat Share</a></h3>
        <h3><a href="/elections/2014/party/bjp.html" target="_blank">Party-wise Results</a></h3>
 </div>

<div class="homeleft">
<div class="topstories leftmarg">
<div class="alpha">

<style>
.highcharts-background { border:1px solid red; height:300px!Important; }

</style>
<div id="wrapper">
 <div id="pieAllianceBigContainer" style="height: 400px; margin-bottom:-150px;"></div>
		<div style="position:relative">
           <table width="100%" border="0" cellspacing="0" cellpadding="8" class="schedule" id="allianceTable">
            </table>
        </div>

        <div>

 <script type = "text/javascript">getAllianceAssemblyDetails("andhra-pradesh");
 </script>



        <ul class="meter-list">

					<li style="margin-left:70px">
	<div id="pieAllianceSmallContainer_odisha" style="min-width: 250px; height: 280px; max-width: 300px; margin: 0 auto"></div>
	<script>
	loadPieAssemblyAllianceSmallContainer("odisha");
				 </script>
				</li>

					<li style="margin-left:70px">
	<div id="pieAllianceSmallContainer_sikkim" style="min-width: 250px; height: 280px; max-width: 300px; margin: 0 auto"></div>
	<script>
	loadPieAssemblyAllianceSmallContainer("sikkim");
				 </script>
				</li>


        </ul>

        </div>

    </div>

</div>
</div>
<div class="divclear"></div>
</div>

<div class="homeright">
<div class="colum">
<div class="item stayconnected">
                <p class="blueheader">STAY CONNECTED WITH US ON</p>
                <a href="http://www.facebook.com/indiatoday" target="_blank" rel="nofollow" title="Facebook"><span class="fb-icon"></span></a>
                <a href="http://www.twitter.com/indiatoday" target="_blank" rel="nofollow" title="Twitter"><span class="tw-icon"></span></a>
                <!--<a title="Google Plus" rel="nofollow" target="_blank" href="https://plus.google.com/u/0/102138128034776070977/"><span class="plus-icon"></span></a>-->
                <a href="http://www.google.com/+indiatoday" target="_blank" rel="nofollow" title="Google Plus"><span class="plus-icon"></span></a>
                <!--<a href="http://www.rediff.com/indiatoday" target="_blank" rel="nofollow" title="Rediff"><span class="rediff-icon"></span></a>-->
                <a href="http://indiatoday.intoday.in/site/rssFeed.jsp" target="_blank" rel="nofollow" title="RSS"><span class="rss-icon"></span></a>
                <a href="http://m.indiatoday.in/" target="_blank" rel="nofollow" title="Mobile"><span class="mobile-icon"></span></a>
                <a href="http://indiatoday.intoday.in/site/livetv.jsp" target="_blank" title="Live TV"><span class="tv-icon"></span></a>
             	<div class="clear"></div>
          	</div>
<div style="width:307px; height:285px; margin-top:15px">
<!-- begin ZEDO for channel:  IT Election Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 -->
<script language="JavaScript">
var zflag_nid="821"; var zflag_cid="2132"; var zflag_sid="2"; var zflag_width="300"; var zflag_height="250"; var zflag_sz="9";
</script>
<script language="JavaScript" src="http://d2.zedo.com/jsc/d2/fo.js"></script>
<!-- end ZEDO for channel:  IT Election Rightnav MR 1 , publisher: India Today , Ad Dimension: Medium Rectangle - 300 x 250 --></div>
</div>

<script>
function myOpen(abc) {
	document.location.href= abc.value;
}
</script>


<div class="colum" style=" margin-bottom:20px;">
	<div style="width:300px">
    <div class="top-strip">
        <span style="width:99%" class="e-page"><h2>Click for State Tally</h2></span>
    </div>
    <div class="clr"></div>
    <div class="box-poll-shadow" style="width:99%">
    <div>
        <a href="/elections/2014/indiamaps.html"><img width="270" alt="" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/indiamap_delhi.gif"></a>
        </div>
    </div>
</div>
</div>



 <div class="colum">

<div class="leftspac ipdwidth"><div class="hotrightnow-head red "><h3><a href="http://indiatoday.intoday.in/videos" target="_blank">Videos</a></h3></div>

<li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/video/jayalalithaa-tamil-nadu-first-appearance-in-217-days/1/439629.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/jaya-video_179_052215024729.jpg"></a><a href="http://indiatoday.intoday.in/video/jayalalithaa-tamil-nadu-first-appearance-in-217-days/1/439629.html">Jayalalithaa makes first public appearance in 217 days</a><span class='small-play-icon1 sp_bg'></span></li><li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/video/delhi-assembly-elections-kiran-bedi-cm-candidate/1/414085.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/kiran-bedi_video_179_011915030550.jpg"></a><a href="http://indiatoday.intoday.in/video/delhi-assembly-elections-kiran-bedi-cm-candidate/1/414085.html">Bedi to be face of Delhi BJP?</a><span class='small-play-icon1 sp_bg'></span></li><li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/video/delhi-assembly-elections-bjp-candidate-list/1/414066.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/bjp_video_179_011915012251.jpg"></a><a href="http://indiatoday.intoday.in/video/delhi-assembly-elections-bjp-candidate-list/1/414066.html">BJP to release list of candidates today</a><span class='small-play-icon1 sp_bg'></span></li><div class='clr'></div><div class='more'><a href="http://indiatoday.intoday.in/videos" target="_blank">More</a></div></div>

 </div>
 <div class="colum">

<div class="leftspac ipdwidth"><div class="hotrightnow-head red "><h3><a href="http://indiatoday.intoday.in/galleries"       target="_blank">Photos</a></h3></div>

<li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/gallery/narendra-modi-cabinet-ministers-take-charge/1/11872.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/sushma-new_179_052814010833.jpg"></a><a href="http://indiatoday.intoday.in/gallery/narendra-modi-cabinet-ministers-take-charge/1/11872.html">Photos: NDA government takes charge</a><span class='small-image-icon1 sp_bg'></span></li><li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/gallery/narendra-modi-swearing-in-ceremony-celebrations-modi-cabinet/1/11871.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/pti1_210_052714023135.jpg"></a><a href="http://indiatoday.intoday.in/gallery/narendra-modi-swearing-in-ceremony-celebrations-modi-cabinet/1/11871.html">Photos: How Modi's oath ceremony was celebrated across India</a><span class='small-image-icon1 sp_bg'></span></li><li class="hotrightnow_lft"><a href="http://indiatoday.intoday.in/gallery/nawaz-sharif-mahinda-rajapaksa-hamid-karzai-narendra-modi-swearing-in/1/11862.html"><img align="left" class="imgs" width="125" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/lazyload-grey.gif" data-original="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Photo_gallery/sharif_179_052614035616.jpg"></a><a href="http://indiatoday.intoday.in/gallery/nawaz-sharif-mahinda-rajapaksa-hamid-karzai-narendra-modi-swearing-in/1/11862.html">Sharif, other SAARC leaders arrive for Modi swearing-in</a><span class='small-image-icon1 sp_bg'></span></li><div class='clr'></div><div class='more'><a href="http://indiatoday.intoday.in/galleries" target="_blank">More</a></div></div>

 </div>

</div>
 	</div>
    </div>

</div>



<div class="clear"></div>
</div>
<div class="clear"></div>
<div class="index-footer">


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
<script type='text/javascript' src='http://indiatoday.intoday.in/js/copypaste_common.js' ></script>
<script type="text/javascript" >$(document).ready(function(){insertCustomSymbols();copypasteinit();});</script>
<img height="1" width="1" src="http://s3-pixel.c1exchange.com/pubpixel/82493" style="display:none;">
<script src="http://tags.crwdcntrl.net/c/9709/cc_af.js"></script>

</div>
</div>
</body>
</html>
