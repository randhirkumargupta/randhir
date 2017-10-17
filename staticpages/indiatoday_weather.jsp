
<!--<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />
<title>Weather New</title>
<script src="http:/images.dailyo.in/js/jquery-1.11.0.min.js"></script>-->
<script>
$(document).ready(function(){
	var kr_len = $('.st_belt ul li').length;

	var kr_height = $('.st_belt ul li').height();

	var kr_counter = 1;
	$('#top_highlight .st_belt').css('height', kr_height );
	$('#top_highlight .st_belt ul li').css('height', kr_height );
		
	var autoslides = setInterval(autoslide, 6000);
	var runslide = 'f'; // or b
	function autoslide() {

		if(runslide == 'b') {//kr_counter == kr_len) {
			kr_counter -= 1;
			$(".st_belt ul").animate({
				top: '+=' + kr_height
			});
				
			if(kr_counter == 1) {
				runslide = 'f';
			}
		} else {
			$(".st_belt ul").animate({
				top: '-=' + kr_height
			})

			kr_counter += 1;
			if(kr_counter == kr_len) {
				runslide = 'b';
			}
		}
	}
	
	$('.st_belt').mouseenter(function(){
		clearInterval(autoslides);
	});
	
	$('.st_belt').mouseleave(function(){
		autoslides = setInterval(autoslide, 6000);
	});
});
</script>
<style>
* {
	margin: 0;
	padding: 0;
}


#weatherforecost-section {
	background: #FFF;
	padding: 0;
}
.title-head {
	float: left;
	margin-right: 15px;
	margin-top:-2px;
}
.title-head h3 {
	font-size: 20px;
	color: #929292;
	font-family: roboto;
	line-height: 22px;
    margin: 1px 0 0;
	padding: 0;
	text-transform: uppercase;
}
.title-head h4 {
	color: #929292;
	font-size: 15px;
	font-weight: normal;
	font-family: roboto;
	padding: 0;
	margin: 0;
	text-transform: uppercase;
}
#wapper-section {
	margin:0 auto;
	overflow: hidden;
	padding: 5px 5px;
	height: 43px;
	-moz-box-shadow: 0px 0px 5px #ccc;
	-webkit-box-shadow: 0px 0px 5px #cccc;
	box-shadow: 0px 0px 5px #ccc;
	background:#fff;
	margin-bottom:20px;
}
.wapper-section a{ color:#fff;}

.date-city {
	font-size: 17px;
	color: #FFF;
	font-family: roboto;
	width: 165px;
	float: left;
	text-transform: uppercase;
	text-align: center;
	line-height: 19px;
	padding: 2px 6px;
	}

.temp-info {
	width: auto;
	float: left;
	height:42px;
}
.date-city span {
	font-size: 13px;
	display: block;
}
.temp-info .temp-img {
	background: #234f7c;
	padding: 6px 11px;
	width: 42px;
	text-align: center;
	float: left;
}

.temp-info .max-temp {
	background: #163a5e;
	text-align: center;
	float: left;
	font-family: roboto;
	font-size: 16px;
	font-weight: normal;
	color: #fff;
	width:55px;
	height:41px;
	line-height: 41px;

}

.temp-info .thistime-temp {
	background: #0a2946;
	line-height: 32px;
	text-align: center;
	float: left;
	font-family: roboto;
	font-size: 16px;
	font-weight: normal;
	color: #FFF;
	width:55px;
	height:41px;
	line-height: 41px;
}
.temp-info .min-temp {
	background: #5EA7DA;
	width: 28px;
	height: 28px;
	line-height: 26px;
	border-radius: 3px;
	text-align: center;
	float: left;
	font-family: roboto;
	font-size: 11px;
	font-weight: bold;
	color: #665237;
	-webkit-box-shadow: 0 3px 3px 0 #666666;
	-moz-box-shadow: 0 3px 3px 0 #666666;
	box-shadow: 0 3px 3px 0 #666666;
	margin: 5px 5px 0 0;
}
.temp-info .min-temp span {
	background: url(images/min-tempbg.png) no-repeat 0 4px;
	font-size: 10px;
	padding: 5px 6px;
}
.right-weather {
	width: 197px;
	float: left;
	background: #061b30;
	color: #fff;
	height: 42px;
}
.right-weather h3 {
	font-family: roboto;
	font-size: 19px;
	width: auto;
	float: left;
	margin: 0;
	line-height: 40px
}
.ad-weather {
	font-family: roboto;
	float: right;
	margin-right: 2px;
}
.ad-weather p span{
	font-size: 12px;
	margin-top:11px;
	float:left;
	color:#fff;
}
.ad-weather img {
	width: 81px;
	margin-top: 1px;
}

.st_belt {
	overflow: hidden;
	width: 351px;
	float: left;
	background: #306295;
	margin-right: -1px
}
.st_belt ul {
	color: #cacbcc;
	font-size: 14px;
	margin: 0 auto;
	padding: 0;
	position: relative;
}
.st_belt ul li {
	clear: both;
	font-family: "Bitter", serif;
	line-height: 42px;
	list-style: outside none none;
	text-align: center;
	width: 100%;
	height: 42px;
	color: #fff;
}
@media screen and (max-width:768px){
	#wapper-section{margin:15px auto 72px}
	.right-weather {width: 235px !important;}
	.ad-weather p span {font-size: 14px;margin-right: 15px;}
}
@media screen and (max-width:800px){
	#wapper-section{margin:20px auto 72px}
	.right-weather {width: 265px;}
	.ad-weather p span {font-size: 14px;margin-right: 28px;}
}
</style>
</head>
<body>


<div id="wapper-section">
<a href="http://www.asianpaints.com/apexultima/ApexUltimaProtek/index.aspx?utm_source=IndiaToday&utm_medium=Homepage&utm_campaign=UltimaProtek&campaignID=CE-0000035-PRT-DIG" rel="nofollow" target="_blank">
  <div class="title-head">
    <h3>Weather</h3>
    <h4>FOR The DAY</h4>
  </div>
  <div id="weatherforecost-section">
    <div class="st_belt" style="height: 42px;">
      <ul>
                  
        
      </ul>
    </div>
  </div>
  <div class="right-weather">
    <div class="ad-weather">
      <p><span>Brought to you by &nbsp;&nbsp;</span><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/weather/logo.jpg" border="0" /></p>
       </div>
  </div></a>
</div>

