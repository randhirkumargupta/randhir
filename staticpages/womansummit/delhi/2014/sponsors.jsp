
<?php include('header.php');?>






<div class="menudiv">
<div class="cont-area">



<div class="clr"></div>
</div>
</div>
<div class="clr"></div>
<div class="cont-area margtop">
<div id="left">
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
<link rel="stylesheet" href="http://conclave.intoday.in/conclave2012/includes/sponsors/css/sponsor.css" type="text/css" />
<style>
.innerul li.redli{background:none !important; border:1px solid #F57921 !important; background-color:#F57921 !important; border-top:none; font:bold 12px Arial; padding:3px 0 3px 10px; color:#FFFFFF; width:188px;}
.innerul li.innerli a:hover{text-decoration:none; background:none !important;  border:1px solid #F57921 !important; background-color:#F57921 !important; border-top:none; color:#FFFFFF;}
.compName {
    color: #F57921 !important;
    font-family: arial;
    font-size: 22px;
    font-weight: normal;
    padding: 5px 0 0;
}
strong {
    color: #F57921 !important;
    display: block;
}
</style>
<script>
function changeColor(colo) {
	//alert(colo);
	var col = document.getElementById(colo);
	var col1 = document.getElementById("id_1");
	var col2 = document.getElementById("id_2");
	//var col3 = document.getElementById("id_3");
	//var col4 = document.getElementById("id_4");
	//var col5 = document.getElementById("id_5");
	var col6 = document.getElementById("id_6");
	//var col7 = document.getElementById("id_7");
	var col8 = document.getElementById("id_8");
	var col9 = document.getElementById("id_9");
	
	
	col1.className="innerli";
	col2.className="innerli";
	//col3.className="innerli";
	//col4.className="innerli";
	//col5.className="innerli";
	col6.className="innerli";
	//col7.className="innerli";
	col8.className="innerli";
	col9.className="innerli";

	col.className = 'redli';

	if($('#'+colo).attr('frameheight')!='' && $('#'+colo).attr('frameheight')!=undefined) {
		$('#sponser').height($('#'+colo).attr('frameheight'));
	}

}
</script>
	    <table width="670" border="0" cellspacing="0" cellpadding="0">
      <tr>
      <td align="left" class="event-headline" colspan="5">EVENT SPONSORS</td>
      </tr>
      <tr>
        <td height="10"></td>
      </tr>        	
      <tr>
        <td>
            <div id="sponsorspage">
            	<div id="leftsponsors">
                	<ul class="mainul">
                    	<li class="mainli">
                        	<div class="mainlitop">Presenting Sponsor</div>
                            <ul class="innerul">
                            	<li class="redli" id="id_1" frameheight="2800"><a href="/womansummit/delhi/2013/pcj.html" target="sponser" onClick="javascript:changeColor('id_1')">PC Jeweller Limited</a></li>
                            </ul>
                        </li>
                        <li class="mainli">
                        	<div class="mainlitop">Associate Sponsor</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_2' frameheight="850"><a href="/womansummit/delhi/2013/necc.html" target="sponser" onClick="javascript:changeColor('id_2')" >NECC</a></li>
                            </ul>
                        </li>
                         <!--<li class="mainli">
                        	<div class="mainlitop">Time Partner</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_3' frameheight="1200"><a href="/womansummit/delhi/2013/omega-2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_3')" >OMEGA</a></li>
                            </ul>
                        </li> 
                         <li class="mainli">
                        	<div class="mainlitop">Writing Instrument</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_4' frameheight="500"><a href="/womansummit/delhi/2013/parker-2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_4')" >PARKER</a></li>
                            </ul>
                        </li> 
                        <li class="mainli">
                        	<div class="mainlitop">Hospitality</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_5' frameheight="700"><a href="/womansummit/delhi/2013/hyatt_2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_5')" >HYATT REGENCY</a></li>
                            </ul>
                        </li>-->
                        <li class="mainli">
                        	<div class="mainlitop">Media Partner</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_6' frameheight="600"><a href="/womansummit/delhi/2013/MailToday_2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_6')" >MAIL TODAY</a></li>
                                
                            </ul>
                        </li>
                        <li class="mainli">
                        	<div class="mainlitop">TV Partner</div>
                            <ul class="innerul">
                            	<!--<li class="innerli" id='id_7' frameheight="500"><a href="http://conclave.intoday.in/conclave2012/includes/sponsors/aajtak_2012.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_7')" >AAJ TAK </a></li>-->
                               
								<li class="innerli" id='id_8' frameheight="500"><a href="/womansummit/delhi/2013/headlinestoday_2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_8')" >HEADLINES TODAY</a></li>
                               
                            </ul>
                        </li>
                        <li class="mainli">
                        	<div class="mainlitop">Online Partner</div>
                            <ul class="innerul">
                            	<li class="innerli" id='id_9' frameheight="800"><a href="/womansummit/delhi/2013/india_today_2013.html#ANCHOR" target="sponser" onClick="javascript:changeColor('id_9')" >INDIA TODAY</a></li>
                            </ul>
                        </li>
                        
                    </ul>
                </div>
                <div id="sponsorsdetails">
                	<iframe id="sponser" style="height: 2800px;" name="sponser" src="/womansummit/delhi/2014/pcj.html" width="450" marginheight="0" marginwidth="0" scrolling="No" frameborder="0"></iframe>
                </div>
                <div class="clear"></div>
            </div>
        </td>
      </tr>
    </table>

</div>
<div id="right"> 
<link href="/staticpages/womansummit/delhi/2014/woman-reg.css" rel="stylesheet" type="text/css" />
<div class="navigation_right">
  <div style="margin-bottom: 20px;">
    <a class="twitter-timeline"  height="350" width="300"  href="https://twitter.com/hashtag/womenpower"  data-widget-id="497621150097104896">#womenpower Tweets</a>
    <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>


  </div>
  <!--<div style="margin-bottom: 20px; float:left; width:100%;">
<iframe src="/highlights/chunk_womansummit_static.jsp" height="370" width="300" scrolling="no" frameborder="0" allowtransparency="true"></iframe>
</div>-->
  <!-- Backstage action Start -->
  <div style="margin-bottom: 20px; float:left; width:100%;">
    <div style="font: bold 20px/24px Arial-Black; color: #F57921; text-transform:uppercase">Backstage action </div>
    <div><a href="#"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday//images/stories/2014August/imran-khan_300x300_080914064335.jpg" border="0" /></a></div>
    <div class="clr"></div>
  </div>
  <!-- Backstage action End -->
  <div class="clr"></div>
  <div class="side_chunk">
    <div class="side_chunk_title" style="height:52px; font: bold 20px/24px Arial-Black; color: #F57921; text-transform:uppercase; margin-top:10px"> Six-second video snapshots </div>
    <div style="clear:both"></div>
    <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-harsimrat-kaur-poses-backstage/1/376314.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/harsimrat-vine_100x85_080914055143.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a><a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-manisha-koirala-takes-the-stage/1/376330.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/manisha--vine_100x85_080914055142.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-imran-khan-live-vine/1/376331.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday//images/stories/2014August/imran-vine_100x85_080914055143.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
    <div style="clear:both"></div>
    <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-jwala-gutta-manisha-koirala-what-a-racket-the-string-quintet/1/376333.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/jwallagutta-vine_100x85_080914062943.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-dipika-pallikal-squash/1/376337.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/dipika-vine_100x85_080914062943.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/story/tabu-poses-at-india-today-woman-summit-2014/1/376341.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday//images/stories/2014August/tabu-vine-100x85_080914070234.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
    <div style="clear:both"></div>
  </div>
  <!--<div class="side_chunk">
    <div class="side_chunk_title" style="height:30px; font: bold 20px/24px Arial-Black; color: #F57921; text-transform:uppercase; margin-top:10px">Vine videos</div>
    <div style="clear:both"></div>
    <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-harsimrat-kaur-poses-backstage/1/376314.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/harsimrat-vine_100x85_080914055143.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a><a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-manisha-koirala-takes-the-stage/1/376330.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/stories/2014August/manisha--vine_100x85_080914055142.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/story/india-today-woman-summit-2014-imran-khan-live-vine/1/376331.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday//images/stories/2014August/imran-vine_100x85_080914055143.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
    <div style="clear:both"></div>
    <a href="http://indiatoday.intoday.in/video/sridevi-revisits-her-famous-dialogue-from-chaalbaaz/1/266677.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_4.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/video/india-today-cover-a-reflection-of-society-says-kalli-purie/1/266592.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_5.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a> <a href="http://indiatoday.intoday.in/video/models-showcase-exquisite-jewellery-at-india-today-woman-summit-2013/1/266674.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_6.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>-->
    <!--<div class="side_chunk">
    <div class="side_chunk_title" style="height:30px; font: bold 20px/24px Arial-Black; color: #F57921; text-transform:uppercase; margin-top:10px">
        Short & Crisp Videos
    </div>
     <div style="clear:both"></div>
	   <a href="http://indiatoday.intoday.in/video/shashi-tharoor-unveils-woman-magazine-cover/1/266669.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/CRISP-1.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
		<a href="http://indiatoday.intoday.in/video/sridevi-and-boney-kapoors-love-story/1/266632.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/CRISP-3.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
   
		<a href="http://indiatoday.intoday.in/video/smriti-irani-jayanthi-natarajan-unveil-india-todays--high-and-mighty-cover/1/266579.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/CRISP-2.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
 <div style="clear:both"></div>
 
 <a href="http://indiatoday.intoday.in/video/sridevi-revisits-her-famous-dialogue-from-chaalbaaz/1/266677.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_4.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
		<a href="http://indiatoday.intoday.in/video/india-today-cover-a-reflection-of-society-says-kalli-purie/1/266592.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_5.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
   
		<a href="http://indiatoday.intoday.in/video/models-showcase-exquisite-jewellery-at-india-today-woman-summit-2013/1/266674.html" target="_blank"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/crisp_6.jpg" border="0" align="left" width="98" style="margin-right:2px; margin-top:2px;" /></a>
 <div style="clear:both"></div>
 </div>-->
    <div style="clear:both"></div>
  </div>
  <!-- past coverage (Start) -->
  <div class="past-coverage">
    <div style="font: bold 20px/24px Arial-Black; color: #fef200;">PAST COVERAGE</div>
    <div class="coverage">
      <div style="float:left; margin:4px 10px 0 0;"><a href="http://indiatoday.intoday.in/video/marian-pearl-and-her-tale-of-courage/1/126879.html"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/images/post1.jpg" alt="Mariane Pearl at the Dinner Keynote Address" title="Mariane Pearl at the Dinner Keynote Address" /> </a></div>
      <div style="float:left; width:175px;margin-top: 3px;"> <a class="ciker" href="http://indiatoday.intoday.in/video/marian-pearl-and-her-tale-of-courage/1/126879.html">Mariane Pearl at the Dinner Keynote Address</a> </div>
    </div>
    <div class="clr"></div>
    <div class="coverage">
      <div style="float:left; margin:4px 10px 0 0;"><a href="http://indiatoday.intoday.in/gallery/india-today-woman-summit-2011/1/4087.html"> <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2013/images/psot2.jpg" alt="Padma on career, relationship and more" title="Padma on career, relationship and more" /></a></div>
      <div style="float:left; width:175px;margin-top: 3px;"> <a class="ciker" href="http://indiatoday.intoday.in/gallery/india-today-woman-summit-2011/1/4087.html">Padma on career, relationship and more</a> </div>
    </div>
  </div>
  <!-- past coverage (Close) -->
  <div class="clr"></div>
  <!-- Venue (Start) -->
  <div class="venue" style="float: left; margin-top:20px">
    <div class="venuetitle"></div>
    <div class="venueaddredd">
      <div itemtype="http://data-vocabulary.org/Event" itemscope="">
        <div style="font: bold 20px/24px Arial-Black; color: #fef200;">VENUE DETAILS</div>
        <!-- <a itemprop="http://indiatoday.in/womansummit/index.php" href="http://indiatoday.in/womansummit/index.php" style=" text-decoration:none;">-->
        <span itemprop="summary" style="font:bold 17px/17px arial; text-transform:uppercase;color: #000;">India Today Woman Summit & Awards 2014</span>
        <!--</a>-->
        <br>
        <span style="color: #000; font-weight: normal; display: block; margin-bottom: 5px;" itemprop="description"></span>
        <!-- <time datetime="2012-09-7T03:00+05:30" itemprop="startDate">Sep 07, 8:30AM</time> - <time datetime="2012-09-7T14:10+05:30" itemprop="endDate">Sep 07, 7:40PM</time><br> -->
        <span itemtype="http://data-vocabulary.org/ Organization" itemscope="" itemprop="location"> <span itemprop="region"> ITC Maurya Hotel, Diplomatic Enclave, Sardar Patel Marg, New Delhi, Delhi 110021 </span> <br>
        </span>
        <!-- <span itemtype="http://data-vocabulary.org/?Geo" itemscope="" itemprop="geo"><meta content="28.554189" itemprop="latitude"><meta content="77.212807" itemprop="longitude"></span> -->
        </span> </div>
    </div>
  </div>
  <div class="clr"></div>
  <!-- Venue (Close) -->
</div>
<style>
.navigation_right{margin-top: 0px!important;}
</style>


           </div>
            </div>
            <div class="clr"></div>
            <div class="cont-area">
<style>
.sponsor-type {
    color: #000000;
    font: bold 14px/20px Arial;
}
.subsponsor-type21 {
    float: left;
    font: bold 12px/18px Arial;
    height: 50px;
    text-align: center;
    width: 100%;
}
</style>



<table width="1003" cellspacing="0" cellpadding="10" border="0"> 
<tbody>
<tr> 
  <td align="center" colspan="3" class="event-headline">SPONSORS</td>
</tr>
<tr> 
  <td width="100%" valign="top" align="center" style="border:solid 1px #cccccc; border-width: 1px 0px 0px 0;" colspan="3">
  <span class="sponsor-type">PRESENTING SPONSOR</span><br>
  <a target="_blank" href="http://www.pcjeweller.com/"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2014/images/PCJ_logo1.gif" alt="PcJeweller" border="0" usemap="#Map" title="PcJeweller"></a>  </td>
</tr>
<tr>
  <td valign="top" align="center" style="border:solid 1px #cccccc; padding:0; border-width: 1px 0px 1px 0; width:1000px">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td align="center"><span class="sponsor-type">ASSOCIATE SPONSOR</span><br>
          <a target="_blank" href="http://www.e2necc.com/"><img border="0" title="e2necc" alt="e2necc" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2014/images/NECC_logo.jpg"></a> </td>
        <td align="center" valign="top" style="border-left:2px solid #cccccc"><span class="sponsor-type">TIME PARTNER</span><br>
          <a href="#"><img border="0" title="Omega" alt="Time Patner" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2014/speakers/omega_logo.jpg"></a> </td>
        <td align="center" valign="top" style="border-left:2px solid #cccccc"><span class="sponsor-type">BESPOKE PARTNER</span><br><br/>
          <a href="#"><img border="0" title="Bespoke Patner" alt="Bespoke Patner" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2014/images/miilano-logo.jpg"></a> </td>
        </tr>
      </table>
    
    </td>
</tr>
<tr>
<td colspan="3"><table width="100%" cellspacing="0" cellpadding="10" border="0" align="center">
  <tbody>
    <tr>
      <td height="25" colspan="3" align="center" valign="top" style="padding-bottom:0px; "><span class="sponsor-type"><strong>PARTNERS</strong></span></td>
    </tr>
    <tr>
      <td align="center" style="border:solid 1px #cccccc; border-width: 1px 1px 1px 0; border-right:none;border-left:none;border-top:none">
      <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/womansummit/2014/speakers/Sponsor_strip.jpg">
        </td>
        
    </tr>
  </tbody>
</table></td>

</tr>

</tbody></table>







 
            </div>
 <iframe src="/staticpages/main/it-footer2015.html" frameborder="0" scrolling="no" width="100%" height="455"></iframe>           
           <script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-795349-17', 'auto');
  ga('send', 'pageview');

</script>
 <!-- Begin comScore Tag -->
<script >
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
<map name="Map" id="Map"><area shape="rect" coords="4,166,144,216" href="https://www.facebook.com/PCJINDIA" target="_blank" /></map>
</body>
</html>


