<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
<script>
$(document).ready(function(){

$('.nav > ul > li.drop').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild').show();
});


$('.navi > ul > li.drop').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild').show();
}).mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchild').hide();
});



});
</script>
<script>
$(document).ready(function(){
$("ul.ddchild > li > a").hover(
	function () {
		$(this).stop().animate({ paddingLeft: "10px", width: "150px"  },0);
	},
	function () {
		$(this).stop().animate({ paddingLeft: "10px" , width: "150px" });
	}
);

$('.nav > ul > li.drop').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild').show();
}).mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchild').hide();
});

$('.nav > ul > li.drop1').mouseover(function() {
	//$(this).addClass("active");
    $('ul.ddchild1').show();
	})
.mouseout(function() {
	//$(this).addClass("");
    $('ul.ddchild1').hide();
});

});
</script>



<style>
.programme_bg {
    background: url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/youthsummit/2014/images/Mind-rocks-speaker-page-mast-head_for-Delhi.png") no-repeat scroll center top transparent;
}
#navi ul{ padding-top:320px;}
ul {
    list-style: disc outside none; margin-left:20px; margin-bottom:15px;
}
.navi ul li {
    margin: 0 2px !important;
}
.navi ul li {
    float: left;
    margin: 0 5px;
}
.navi ul li {
    display: inline;
    font-weight: bold;
    list-style: none outside none;
    text-transform: uppercase;
}
.navi ul li a {
    font-size: 15px !important;
    padding: 4px !important;
	color: #333;
    font-family: arial;
}

.navi ul li a {
    color: #383838;
    text-decoration: none;
	padding: 5px 9px;
	 float: left;
	 font-family:Arial, Helvetica, sans-serif;
}

.navi > ul > li > ul.ddchild {
    background-color: #5e5e5e;
    list-style-type: none;
    margin: 0;
    padding: 0;
    position: absolute;
    top: 345px;
    width: 170px;
    z-index: 999;
}

ul.ddchild > li {
    border-bottom: 1px solid #fff;
    width: 100%;
}
ul.ddchild > li a {
    color: #fff;
    font: bold 14px/30px Arial;
    text-decoration: none;
}

#top-web {
    display: block;
}
.gb-lik {
    background: url("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/band-gblink.png") no-repeat scroll 5px center rgba(0, 0, 0, 0);
}
.itgd_links {
    background-color: #d8d8d8 !important;
    color: #7a7a7a;
    font: 11px/15px arial;
    margin: 0;
    padding: 0.3%;
    text-align: center;
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
.last {
    border-right: 0 none !important;
    margin: 0;
}
.itgd_links a {
    color: #7a7a7a;
    text-decoration: none;
}

.itgd_links ul li.last {
    border-right: medium none;
}
.clr { clear:both}

</style>


<div style="width:100%; margin:auto; background:#D8D8D8 !important; border-bottom:1px solid white">
<div style="width:1000px; margin:auto;">
<div style="border-bottom:none" id="top-web" class="itgd_links gb-lik">
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
<li><a rel="nofollow" class="mainlevel" target="_blank" href="http://travelplus.intoday.in">Travel Plus</a></li>
<li class="last"><a rel="nofollow" class="mainlevel" target="_blank" href="http://www.bagittoday.com/">Bag it Today</a></li>
</ul>
<div class="clr"></div>
</div>
</div>
</div>


<div class="clr"></div>

<div class="programme_bg" style="width:1000px; margin:0 auto; height:380px;">
	<div style="width:1000px;" id="main_container">



<div class="navi" style="padding-top:300px;">
<ul>
            	<li><a href="/youthsummit/delhi/2014/index.jsp" >home</a></li>
				<li><a href="/youthsummit/delhi/2014/programme.jsp">programme</a></li>
                <li><a href="/youthsummit/delhi/2014/speakers.jsp" class="active">speakers</a></li>
              <!--  <li><a href="/youthsummit/delhi/2013/speakers-chandigarh.jsp" >speakers-chandigarh</a></li>-->
                <li><a href="http://subscriptions.intoday.in/subscriptions/youthsummit2014/registration.jsp">registration</a></li>
               <li><a href="http://specials.indiatoday.com/survey/youthsummit/participation.jsp">Band Registrations</a></li>
               <li><a href="/youthsummit/delhi/2014/sponsors.jsp">Sponsors</a></li>
            <!--    <li><a href="/youthsummit/delhi/2013/sponsors.jsp" >sponsors</a></li>
                <li><a href="#">program</a></li>
                <li><a href="#">contest</a></li>-->
                <li class="drop">
		<a href="Javascript: void(0);">Flashback</a>

		<ul class="ddchild" style="display:none;">
        <li><a style="padding-left: 10px; width: 150px;" href="/youthsummit/chandigarh/2014/index.jsp" title="Kolkata 2013" target="_blank">Chandigarh 2014</a></li>
				<li><a target="_blank" title="Delhi 2013" href="/youthsummit/delhi/2013/index.jsp" style="padding-left: 10px; width: 150px;">Delhi 2013</a></li>
                <li><a target="_blank" title="Kolkata 2013" href="/youthsummit/kolkata/2013/index.jsp" style="padding-left: 10px; width: 150px;">Kolkata 2013</a></li>
				<li><a target="_blank" title="Delhi 2012" href="/youthsummit/delhi/2012/ " style="padding-left: 10px; width: 150px;">Delhi 2012</a></li>
                <li><a target="_blank" title="Chennai 2011" href="/specials/youthsummit/chennai/index.jsp " style="padding-left: 10px; width: 150px;">Chennai 2011</a></li>
                <li><a target="_blank" title="Delhi 2011" href="/specials/youthsummit/">Delhi 2011</a></li>
                <li><a target="_blank" title="Delhi 2010" href="/special/youthsummit/index.html">Delhi 2010</a></li>
         </ul>

	</li>
              <!--  <li><a href="/youthsummit/delhi/2013/contact-us.jsp" >contact us</a></li>
				 <li><a href="http://subscriptions.intoday.in/subscriptions/youthsummit2013/contest-nominate-now.jsp" style="border-radius:0px;">Real Youth Icon</a></li>
                  <li><a href="http://specials.indiatoday.com/survey/mindrocks/feedback.jsp" >Feedback</a></li>-->


            </ul>
        	<ul style="display:none;">
            	<li><a href="/youthsummit/chandigarh/2014/index.jsp">home</a></li>
			<li><a href="/youthsummit/chandigarh/2014/programme.jsp">programme</a></li>
                <li><a href="/youthsummit/chandigarh/2014/speakers.jsp">speakers</a></li>
              <!--  <li><a href="/youthsummit/delhi/2013/speakers-chandigarh.jsp" >speakers-chandigarh</a></li>-->
                <li><a href="http://subscriptions.intoday.in/subscriptions/youthsummit2014/registration.jsp">registration</a></li>
              <!-- <li><a href="http://specials.indiatoday.com/survey/youthsummit/participation.jsp" >Band Registrations</a></li>-->
            <!--    <li><a href="/youthsummit/delhi/2013/sponsors.jsp" >sponsors</a></li>
                <li><a href="#">program</a></li>
                <li><a href="#">contest</a></li>-->
                <li class="drop">
		<a href="Javascript: void(0);">Flashback</a>

		<ul class="ddchild" style="display: none;">
				<li><a style="padding-left: 10px; width: 150px;" href="/youthsummit/kolkata/2013/index.jsp" title="Kolkata 2013" target="_blank">Kolkata 2013</a></li>
				<li><a style="padding-left: 10px; width: 150px;" href="/youthsummit/delhi/2012/ " title="Delhi 2012" target="_blank">Delhi 2012</a></li>
                <li><a style="padding-left: 10px; width: 150px;" href="/specials/youthsummit/chennai/index.jsp " title="Chennai 2011" target="_blank">Chennai 2011</a></li>
                <li><a href="/specials/youthsummit/" title="Delhi 2011" target="_blank">Delhi 2011</a></li>
                <li><a href="/special/youthsummit/index.html" title="Delhi 2010" target="_blank">Delhi 2010</a></li>
         </ul>

	</li>
              <!--  <li><a href="/youthsummit/delhi/2013/contact-us.jsp" >contact us</a></li>
				 <li><a href="http://subscriptions.intoday.in/subscriptions/youthsummit2013/contest-nominate-now.jsp" style="border-radius:0px;">Real Youth Icon</a></li>
                  <li><a href="http://specials.indiatoday.com/survey/mindrocks/feedback.jsp" >Feedback</a></li>-->


            </ul>
        </div>
		<div class="clr">&nbsp;</div>
 </div>
</div>
