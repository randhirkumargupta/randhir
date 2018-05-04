
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
<!-- Bootstrap -->
<!--<link href="http://media2.intoday.in/indiatoday/resources/newswiz-2017/newcss/bootstrap.min.css" rel="stylesheet" type="text/css">
<link rel="stylesheet" href="http://media2.intoday.in/indiatoday/resources/newswiz-2017/newcss/reset.css" type="text/css">
<link rel="stylesheet" href="http://media2.intoday.in/indiatoday/resources/newswiz-2017/newcss/style.css" type="text/css">
<link rel="stylesheet" href="http://media2.intoday.in/indiatoday/resources/newswiz-2017/newcss/responsive.css" type="text/css">
<link rel="stylesheet" href="http://media2.intoday.in/indiatoday/resources/newswiz/newcss/swiper.min.css" type="text/css">-->
<link href="http://dotctor.github.io/jQuery.msgBox/styles/msgBoxLight.css" rel="stylesheet" type="text/css" />
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script> 


<script>
function trim(field)
{
while(field.charAt(field.length-1)==" "){
		field=field.substring(0,field.length-1);
	}
	while(field.charAt(0)==" "){
		field=field.substring(1,field.length);
	}
	return field;
}

function handleHttpResponse2()
{
	var urltoPass = "test";
	//console.log("urltoPass ----------->" + urltoPass);
	urltoPass=trim(urltoPass);
	if(urltoPass.length==0){
		urltoPass = url;
	}
	//console.log("http2.readyState ----------->" + http2.readyState);
	if (http2.readyState == 4) {
		//console.log("http2.responseText ----------->" + http2.responseText);
		var results = http2.responseText;
		var arry = results.split('|'); 
		var upcnt=	(arry[0]);
		var dncnt=(arry[1]);
		var lastcnt=(arry[2]);
		var cmnt=(arry[3]);
		var cid=(arry[4]);
		//alert(cid);
		if (http2.status == 200) {
		ga('send', 'event', 'LIKE', 'click',urltoPass, 1, {'nonInteraction': 1});
			document.getElementById("upcount"+cid).innerHTML = upcnt;
			//document.getElementById("downcount"+cid).innerHTML = dncnt;
			//document.getElementById("lastcount"+cid).innerHTML = lastcnt;
			//document.getElementById("commenttext"+cid).innerHTML = cmnt;
			
		} else {                 
			//alert('There was a problem retrieving the data');
		} 
	}
}
function getHTTPObject()
{
	var xmlhttp;
	if(window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
	} else if (window.ActiveXObject) {
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		if (!xmlhttp) {
			xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
	}
	return xmlhttp;
}

var http2 = getHTTPObject();
function changeRating1(contentId,content_type,action,part_id, upc, dwnc,lastc)
{ 
	upc =document.getElementById('upcount'+part_id).firstChild.nodeValue;
	downc = '0';
	lastc = '0';
	totalc =upc;
	url="http://indiatoday.intoday.in/highlights/rating_data_budget_highlights.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&lastcount="+lastc+"&totalcount="+totalc+"&part_id="+part_id;
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
	setCookie("upcount5671"+part_id, "1");
	
		$('.upcount5665'+part_id).parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
}
</script>

              
              
              <style type="text/css">
.support-team{display:block; margin:10px 0 22px;}
.support-team h2{margin: 0px 0 10px 0; padding: 12px 0 7px 12px; background: url(http://media2.intoday.in/indiatoday/resources/newswiz/newimages/support-bg.png) no-repeat;
font-size: 20px;line-height:52px; color: #fff; text-transform: uppercase;}
.support-team .support-slider{float:left; width:100%; background-color:#fff; padding:12px 0 0 0; overflow:hidden; position:relative; margin-bottom:30px;}
.support-team .support-slider ul{list-style:none; margin:0; padding:0; position:relative; overflow:hidden} 
.support-team .support-slider ul li{width:150px; float:left; padding-bottom:18px; position:relative;}
.support_cont{ display:block;padding:0 11px;border-right:1px solid #ededed;}
.support_cont p{font:13px/18px 'Roboto',sans-serif; color:#7a7a7a; display:block; text-align:center; min-height:83px;}
.support-team .support-slider ul li:last-child{border:0;}
.support-team .support-slider ul li .img-box{width:125px; height:145px; text-align:center; display:inline-block; padding:13px 0 0;}
.support-team .support-slider ul li > span{display:inline-block; margin-top:10px; width:125px;}
.support-team .support-slider ul li  em{font-style:normal; font:13px/16px 'Roboto',sans-serif; color:#999; padding:7px 0 0 12px; float:left;}
.support-team .support-slider ul li strong{text-transform:uppercase; color:#000; font:normal 12px/34px 'Roboto',sans-serif; display:block; text-align:center;}
.prev-next-area{position:absolute; right:14px; top:9%;}
.prev-next-area a#pre{}
.prev-next-area a#next{}
.counter-no{text-align:center; font:12px/20px 'Roboto',sans-serif; color:#666; float:left; padding:0 14px; display:none;}

.arrow_box {position: relative;background: #fff;border: 1px solid #a6b3bc; font:bold 21px/30px 'Roboto',sans-serif; color:#ce0502; text-align:center; width:58px; border-radius:2px; margin:0 auto;}
.arrow_box:after, .arrow_box:before {top: 100%;left: 50%;border: solid transparent;content: " ";height: 0;width: 0;position: absolute;pointer-events: none;}
.arrow_box:after {border-color: rgba(255, 255, 255, 0);border-top-color: #fff;border-width: 5px;margin-left: -5px;}
.arrow_box:before {border-color: rgba(166, 179, 188, 0);border-top-color: #a6b3bc;border-width: 7px;margin-left: -7px;}
.vote-btn{background:url(http://media2.intoday.in/indiatoday/resources/newswiz/newimages/vote-btn.png) no-repeat 0 0; width:125px; height:33px; display:block; margin:0 auto; margin-top:25px;}
.vote-done-msg{background-color:#fff; width:470px; position:absolute; top:50%; left:50%; margin-left:-235px; z-index:2; padding:15px 0; display:none;}
.vote-done-msg p{ font:15px/20px 'Roboto',sans-serif; color:#000; text-align:center; display:block; padding:0 0 0 25%; box-sizing:border-box; min-height:auto;}
.overlay{position:fixed; background-color:rgba(0,0,0,0.7); width:100%; height:100%; z-index:1; display:none;}
.sup_like_all.sup_like_all1{position:fixed; top: 30%; background: rgba(0,0,0,0.9); padding:10px 1%; width:300px; height:126px;  border-radius:10px; margin:0 auto; left:40%; margin-left:-150px; display:none; z-index:5;} .sup_like_all h4{ font-size: 17px; color: #fff;line-height: 21px;font-family: roboto; text-align: center;}
.sup_like_all .share_like ul li{ width:auto; display:inline-block} .sup_like_all .share_like ul li:nth-child(1){ color:#fff;} .sup_like_all .share_like ul li a{ display:inline-block; padding:5px 15px;}
.suplike-close{float: right; color: #fff; position: relative; right:-10px; top: -7px;}  
@media screen and (max-width:767px){
	.support-team h2{margin-bottom: 42px;}
}
  </style>
  
              <div class="row">
  <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12" style="position:relative;">
    <div class="prev-next-area">
      <div class="prenext-cent"> <a href="javascript:void(0);" id="presupport"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/prearrow.png" alt=""></a>

      <span class="counter-no"> <span class="first_t">1</span> to <span class="second_t">4</span>/<span class="tot_t"></span> </span> <a href="javascript:void(0);" id="nextsupport"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/nextarrow.png" alt=""></a> </div>
    </div>
    
    <div class="support-team">
      <h2><span>Support Your Team</span></h2>
      <div class="support-slider">
        <ul class="sld_sup">
        
                      
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=convent-of-jesus-and-mary" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/convent-of-jesus-and-mary-new-delhi.png
    " alt="Convent of Jesus and Mary"></div>
              		<p class="fullname">Convent of Jesus and Mary</p>
              	</a>
             
              <div class="arrow_box" id="upcount0">220</div>
			  <strong class="upcount56710"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','0', '220', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext0"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56710');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56710').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Convent of Jesus and Mary"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Convent of Jesus and Mary&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=cathedral-and-john-connon-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/cathedral-and-john-connon-school-mumbai.png
    " alt="Cathedral and John Connon School"></div>
              		<p class="fullname">Cathedral and John Connon School</p>
              	</a>
             
              <div class="arrow_box" id="upcount1">131</div>
			  <strong class="upcount56711"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','1', '131', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext1"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56711');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56711').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Cathedral and John Connon School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Cathedral and John Connon School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=vidya-mandir-sr.-sec.-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/vidya-mandir-chennai.png
    " alt="Vidya Mandir Sr. Sec. School"></div>
              		<p class="fullname">Vidya Mandir Sr. Sec. School</p>
              	</a>
             
              <div class="arrow_box" id="upcount2">276</div>
			  <strong class="upcount56712"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','2', '276', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext2"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56712');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56712').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Vidya Mandir Sr. Sec. School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Vidya Mandir Sr. Sec. School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=krishna-public-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/krishna-public-school-raipur.png
    " alt="Krishna Public School"></div>
              		<p class="fullname">Krishna Public School</p>
              	</a>
             
              <div class="arrow_box" id="upcount3">114</div>
			  <strong class="upcount56713"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','3', '114', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext3"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56713');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56713').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Krishna Public School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Krishna Public School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=bhavan-vidyalaya" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/bvb-chandigarh.png
    " alt="Bhavan Vidyalaya"></div>
              		<p class="fullname">Bhavan Vidyalaya</p>
              	</a>
             
              <div class="arrow_box" id="upcount4">232</div>
			  <strong class="upcount56714"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','4', '232', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext4"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56714');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56714').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Bhavan Vidyalaya"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Bhavan Vidyalaya&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=delhi-public-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/dps-vishakapatnam.png
    " alt="DELHI PUBLIC SCHOOL"></div>
              		<p class="fullname">DELHI PUBLIC SCHOOL</p>
              	</a>
             
              <div class="arrow_box" id="upcount5">199</div>
			  <strong class="upcount56715"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','5', '199', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext5"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56715');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56715').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=DELHI PUBLIC SCHOOL"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=DELHI PUBLIC SCHOOL&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=the-shri-ram-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/the-shri-ram-school-moulsari-gurgaon.png
    " alt="The Shri Ram School"></div>
              		<p class="fullname">The Shri Ram School</p>
              	</a>
             
              <div class="arrow_box" id="upcount6">40</div>
			  <strong class="upcount56716"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','6', '40', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext6"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56716');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56716').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Shri Ram School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Shri Ram School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=g.d.-somani-memorial-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/gd-somani-mumbai.png
    " alt="G.D. Somani Memorial School"></div>
              		<p class="fullname">G.D. Somani Memorial School</p>
              	</a>
             
              <div class="arrow_box" id="upcount7">30</div>
			  <strong class="upcount56717"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','7', '30', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext7"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56717');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56717').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=G.D. Somani Memorial School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=G.D. Somani Memorial School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=sai-international-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/sai-international-school-bhubaneswar.png
    " alt="Sai International School"></div>
              		<p class="fullname">Sai International School</p>
              	</a>
             
              <div class="arrow_box" id="upcount8">57</div>
			  <strong class="upcount56718"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','8', '57', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext8"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56718');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56718').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Sai International School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Sai International School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=sdsm-school-for-excellence" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/sdsm-jamshedpur.png
    " alt="SDSM School For Excellence"></div>
              		<p class="fullname">SDSM School For Excellence</p>
              	</a>
             
              <div class="arrow_box" id="upcount9">309</div>
			  <strong class="upcount56719"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','9', '309', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext9"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56719');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56719').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=SDSM School For Excellence"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=SDSM School For Excellence&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=vibgyor-high" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/vibgyor-school-logo.png
    " alt="Vibgyor High"></div>
              		<p class="fullname">Vibgyor High</p>
              	</a>
             
              <div class="arrow_box" id="upcount10">360</div>
			  <strong class="upcount567110"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','10', '360', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext10"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567110');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567110').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Vibgyor High"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Vibgyor High&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=st.-anthony's-public-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/saps-kerela.png
    " alt="St. Anthony's Public School"></div>
              		<p class="fullname">St. Anthony's Public School</p>
              	</a>
             
              <div class="arrow_box" id="upcount11">34</div>
			  <strong class="upcount567111"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','11', '34', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext11"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567111');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567111').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Anthony's Public School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Anthony's Public School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=sunbeam-lahartara" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/sunbeam-lahartara-varanasi.png
    " alt="Sunbeam Lahartara"></div>
              		<p class="fullname">Sunbeam Lahartara</p>
              	</a>
             
              <div class="arrow_box" id="upcount12">229</div>
			  <strong class="upcount567112"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','12', '229', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext12"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567112');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567112').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Sunbeam Lahartara"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Sunbeam Lahartara&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=st.-joseph's-boys'-high-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/st-josephs-bangalore.png
    " alt="St. Joseph's Boys' High School"></div>
              		<p class="fullname">St. Joseph's Boys' High School</p>
              	</a>
             
              <div class="arrow_box" id="upcount13">69</div>
			  <strong class="upcount567113"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','13', '69', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext13"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567113');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567113').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Joseph's Boys' High School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Joseph's Boys' High School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=delhi-public-school-nagpur" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/dps-nagpur-logo.png
    " alt="Delhi Public School Nagpur"></div>
              		<p class="fullname">Delhi Public School Nagpur</p>
              	</a>
             
              <div class="arrow_box" id="upcount14">367</div>
			  <strong class="upcount567114"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','14', '367', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext14"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567114');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567114').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School Nagpur"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School Nagpur&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=delhi-public-school-rajnagar" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/dps-rajnagar-ghaziabad.png
    " alt="Delhi Public School Rajnagar"></div>
              		<p class="fullname">Delhi Public School Rajnagar</p>
              	</a>
             
              <div class="arrow_box" id="upcount15">22</div>
			  <strong class="upcount567115"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','15', '22', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext15"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567115');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567115').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School Rajnagar"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School Rajnagar&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=the-assam-valley-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/assam-valley-tezpur.png
    " alt="The Assam Valley School"></div>
              		<p class="fullname">The Assam Valley School</p>
              	</a>
             
              <div class="arrow_box" id="upcount16">32</div>
			  <strong class="upcount567116"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','16', '32', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext16"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567116');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567116').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Assam Valley School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Assam Valley School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=the-choice-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/the-choice-school-kochi.png
    " alt="The Choice School"></div>
              		<p class="fullname">The Choice School</p>
              	</a>
             
              <div class="arrow_box" id="upcount17">270</div>
			  <strong class="upcount567117"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','17', '270', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext17"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567117');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567117').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Choice School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Choice School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=springdales-pusa-road" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/springdales-logo-imprvd.png
    " alt="Springdales Pusa Road"></div>
              		<p class="fullname">Springdales Pusa Road</p>
              	</a>
             
              <div class="arrow_box" id="upcount18">512</div>
			  <strong class="upcount567118"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','18', '512', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext18"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567118');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567118').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Springdales Pusa Road"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Springdales Pusa Road&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=the-heritage-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/heritage-school-kolkata-logo.png
    " alt="The Heritage School"></div>
              		<p class="fullname">The Heritage School</p>
              	</a>
             
              <div class="arrow_box" id="upcount19">102</div>
			  <strong class="upcount567119"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','19', '102', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext19"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567119');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567119').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Heritage School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=The Heritage School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=st.-mary's-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/st-marys-pune.png
    " alt="St. Mary's School"></div>
              		<p class="fullname">St. Mary's School</p>
              	</a>
             
              <div class="arrow_box" id="upcount20">270</div>
			  <strong class="upcount567120"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','20', '270', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext20"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567120');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567120').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Mary's School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Mary's School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=gitanjali-devshala" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/gitanjali-devshala-hyderabad.png
    " alt="Gitanjali Devshala"></div>
              		<p class="fullname">Gitanjali Devshala</p>
              	</a>
             
              <div class="arrow_box" id="upcount21">28</div>
			  <strong class="upcount567121"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','21', '28', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext21"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567121');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567121').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Gitanjali Devshala"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Gitanjali Devshala&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=delhi-public-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/dps-guwahati.png
    " alt="Delhi Public School"></div>
              		<p class="fullname">Delhi Public School</p>
              	</a>
             
              <div class="arrow_box" id="upcount22">30</div>
			  <strong class="upcount567122"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','22', '30', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext22"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567122');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567122').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=navrachana-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/navrachana-vadodara-logo.png
    " alt="Navrachana School"></div>
              		<p class="fullname">Navrachana School</p>
              	</a>
             
              <div class="arrow_box" id="upcount23">107</div>
			  <strong class="upcount567123"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','23', '107', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext23"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567123');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567123').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Navrachana School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Navrachana School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=cambridge-court-high-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/cambridge-school-jaipur.png
    " alt="Cambridge Court High School"></div>
              		<p class="fullname">Cambridge Court High School</p>
              	</a>
             
              <div class="arrow_box" id="upcount24">62</div>
			  <strong class="upcount567124"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','24', '62', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext24"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567124');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567124').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Cambridge Court High School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Cambridge Court High School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=st.-xavier's-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/st-xaviers-ranchi.png
    " alt="St. Xavier's School"></div>
              		<p class="fullname">St. Xavier's School</p>
              	</a>
             
              <div class="arrow_box" id="upcount25">88</div>
			  <strong class="upcount567125"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','25', '88', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext25"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567125');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567125').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Xavier's School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=St. Xavier's School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>   
            <div class="support_cont">
            	<a href="http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=delhi-public-school" ><div class="img-box"><img src="
      http://media2.intoday.in/indiatoday/resources/newswiz/team/school-logo/2017/logo/dps-srinagar.png
    " alt="Delhi Public School"></div>
              		<p class="fullname">Delhi Public School</p>
              	</a>
             
              <div class="arrow_box" id="upcount26">32</div>
			  <strong class="upcount567126"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5671','text','1','26', '32', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext26"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount567126');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount567126').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
                            }

                        })
			   </script>
			   
			  
              
            </div>
<div class="sup_like_all sup_like_all1">
  <a href="javascript:void(0);" class="suplike-close"> X </a>
                                        	<h4>I support <span id="schoolname"></span> team</h4>
                                            <div class="share_like">
                                            	<ul>
                                                	<li>SHARE ON</li>
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/newswiz/2017/team.jsp?teamname=Delhi Public School&text=&via=@indiatoday"><img src="http://media2.intoday.in/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>
                                                </ul>
                                            </div>
                                        </div>
          </li>
 
        </ul>
      </div>
    </div>
  </div>
  
</div>


<!--<script src="http://media2.intoday.in/indiatoday/resources/newswiz/newjs/bootstrap.min.js"></script> 
<script src="http://media2.intoday.in/indiatoday/resources/newswiz/newjs/swiper.min.js"></script> 
<script type="text/javascript" src="http://media2.intoday.in/indiatoday/resources/newswiz/newjs/custom.js"></script> --> 

    <script src="http://dotctor.github.io/jQuery.msgBox/scripts/jquery.msgBox.js" type="text/javascript"></script>

    <script type="text/javascript">
	$(document).ready(function(){
	$('.vote-btn').on('click', (function(){
	$(this).css({'pointer-events': 'none', 'opacity': '0.3'});
	var schoolfullname = $(this).parent().find('p.fullname').text();
	//alert(schoolfullname);
	$('h4 span#schoolname').html(schoolfullname);
	$(this).parent('.support_cont').next('.sup_like_all1').css('display','block');
	
	
	}));
	$('.suplike-close').click(function(){
	$('.sup_like_all1').css('display','none');
	
	})
	})
	
	</script>
<script type="text/javascript">
    $(document).ready(function(){
        $("select").change(function(){
            $(this).find("option:selected").each(function(){
                if($(this).attr("value")=="group-a"){
                    $(".box").not(".group-a").hide();
                    $(".group-a").show();
                }
                else if($(this).attr("value")=="group-b"){
                    $(".box").not(".group-b").hide();
                    $(".group-b").show();
                }
                else if($(this).attr("value")=="group-c"){
                    $(".box").not(".group-c").hide();
                    $(".group-c").show();
                }
                else{
                    $(".box").hide();
                }
            });
        }).change();
    });
    </script> 
   
<script type="text/javascript">
$(document).ready(function(e) {
   var n_support_slider_width = $('.support-team .support-slider').width();	
	var nlength = $('ul.sld_sup li').length;
	var nwidth = $('ul.sld_sup li').width();	
	var ntotwidth=nlength*nwidth;
	var n_ul_width = $('ul.sld_sup');
	var presupport = $('#presupport');
	var nextsupport = $('#nextsupport');
    //var ndevice_width = deviceWidth_sld(n_support_slider_width,nwidth);
    var count_len;
    var ndevice_width;
    var nwindow_wdth = $(window).width();
    if(nwindow_wdth>800){
    count_len = Math.floor(n_support_slider_width/nwidth);
    ndevice_width = count_len*nwidth;
    }
    else
    {
    count_len = nlength-1;	
    ndevice_width = nwidth;
    }
    console.log(count_len + " - " + ndevice_width);
	var ncounter=1;
	n_ul_width.css('width',ntotwidth);


	nextsupport.click(function(){
   
    if(ncounter<=count_len){
    	n_ul_width.animate({
    		left:'-='+ndevice_width
    	})
    	ncounter++;
    	presupport.css('opacity', '1');
    }
    else
    {
    	nextsupport.css('opacity', '0.5');

    }

	})


presupport.click(function(){

    if(ncounter==1){
    	
    	presupport.css('opacity', '0.5');
    }
    else
    {
    	n_ul_width.animate({
    		left:'+='+ndevice_width
    	})
    	ncounter--; 

    	nextsupport.css('opacity', '1');

    }

	})

	
});
    </script> 
<script type="text/javascript">
  function getCookie(cname) {
        var name = cname + "=";
        var ca = document.cookie.split(';');
        for (var i = 0; i < ca.length; i++) {
            var c = ca[i];
            while (c.charAt(0) == ' ')
                c = c.substring(1);
            if (c.indexOf(name) == 0)
                return c.substring(name.length, c.length);
        }
        return "";
    }

    function setCookie(cname, cvalue, exdays) {
        var d = new Date();
        d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
        var expires = "expires=" + d.toUTCString();
        document.cookie = cname + "=" + cvalue + "; " + expires;
		//console.log("setcookie");
    }

</script>


