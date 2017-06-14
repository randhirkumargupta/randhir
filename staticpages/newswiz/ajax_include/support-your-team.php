

<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
<!-- Bootstrap -->
<link href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newcss/bootstrap.min.css" rel="stylesheet" type="text/css">
<link rel="stylesheet" href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newcss/reset.css" type="text/css">
<link rel="stylesheet" href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newcss/style.css" type="text/css">
<link rel="stylesheet" href="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newcss/swiper.min.css" type="text/css">
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
	url="/highlights/rating_data_budget_highlights.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&lastcount="+lastc+"&totalcount="+totalc+"&part_id="+part_id;
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse2;
	http2.send(null);
	setCookie("upcount5666"+part_id, "1");
	
		$('.upcount5665'+part_id).parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
}
</script>

              
              
              <style type="text/css">
.support-team{display:block; margin:10px 0 22px;}
.support-team h2{margin: 0px 0 10px 0; padding: 12px 0 7px 12px; background: url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/support-bg.png) no-repeat;
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
.prev-next-area a#presupport{}
.prev-next-area a#nextsupport{}
.counter-no{text-align:center; font:12px/20px 'Roboto',sans-serif; color:#666; float:left; padding:0 14px; display:none;}

.arrow_box {position: relative;background: #fff;border: 1px solid #a6b3bc; font:bold 21px/30px 'Roboto',sans-serif; color:#ce0502; text-align:center; width:58px; border-radius:2px; margin:0 auto;}
.arrow_box:after, .arrow_box:before {top: 100%;left: 50%;border: solid transparent;content: " ";height: 0;width: 0;position: absolute;pointer-events: none;}
.arrow_box:after {border-color: rgba(255, 255, 255, 0);border-top-color: #fff;border-width: 5px;margin-left: -5px;}
.arrow_box:before {border-color: rgba(166, 179, 188, 0);border-top-color: #a6b3bc;border-width: 7px;margin-left: -7px;}
.vote-btn{background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/vote-btn.png) no-repeat 0 0; width:125px; height:33px; display:block; margin:0 auto; margin-top:25px;}
.vote-done-msg{background-color:#fff; width:470px; position:absolute; top:50%; left:50%; margin-left:-235px; z-index:2; padding:15px 0; display:none;}
.vote-done-msg p{ font:15px/20px 'Roboto',sans-serif; color:#000; text-align:center; display:block; padding:0 0 0 25%; box-sizing:border-box; min-height:auto;}
.overlay{position:fixed; background-color:rgba(0,0,0,0.7); width:100%; height:100%; z-index:1; display:none;}
.sup_like_all.sup_like_all1{position:fixed; top: 30%; background: rgba(0,0,0,0.9); padding:10px 1%; width:300px; height:126px;  border-radius:10px; margin:0 auto; left:40%; margin-left:-150px; display:none; z-index:5;} .sup_like_all h4{ font-size: 17px; color: #fff;line-height: 21px;font-family: roboto; text-align: center;}
.sup_like_all .share_like ul li{ width:auto; display:inline-block} .sup_like_all .share_like ul li:nth-child(1){ color:#fff;} .sup_like_all .share_like ul li a{ display:inline-block; padding:5px 15px;}
.suplike-close{float: right; color: #fff; position: relative; right:-10px; top: -7px;}  

@media screen and (max-width:569px) {
.sup_like_all.sup_like_all1{left: 52%;}
.suplike-close{right:5px; top:-9px;}       
}
  </style>
  
              <div class="row">
  <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12" style="position:relative;">
    <div class="prev-next-area">
      <div class="prenext-cent"> <a href="javascript:void(0);" id="presupport"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/prearrow.png" alt=""></a> <span class="counter-no"> <span class="first_t">1</span> to <span class="second_t">4</span>/<span class="tot_t"></span> </span> <a href="javascript:void(0);" id="nextsupport"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/nextarrow.png" alt=""></a> </div>
    </div>
    
    <div class="support-team">
      <h2><span>Support Your Team</span></h2>
      <div class="support-slider">
        <ul class="sld_sup">
        
                      
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Bhartiya-Vidya-Bhawan" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/bhartiya-vidya-jaipur-all-logo.gif" alt="Bhartiya Vidya Bhawan"></div>
              		<p class="fullname">Bhartiya Vidya Bhawan</p>
              	</a>
             
              <div class="arrow_box" id="upcount0">1748</div>
			  <strong class="upcount56660"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','0', '1748', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext0"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56660');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56660').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Bhartiya-Vidya-Bhawan"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Bhartiya-Vidya-Bhawan&text=I support Bhartiya Vidya Bhawan&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Cambridge-Court-High-School" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/cambridge-jaipur-all-logo.gif" alt="Cambridge Court High School"></div>
              		<p class="fullname">Cambridge Court High School</p>
              	</a>
             
              <div class="arrow_box" id="upcount1">2585</div>
			  <strong class="upcount56661"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','1', '2585', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext1"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56661');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56661').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Cambridge-Court-High-School"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Cambridge-Court-High-School&text=I support Cambridge Court High School&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Cathedral-And-John-Connon-School" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/cathedral_and_john_connon_school_mumbai.gif" alt="Cathedral And John Connon School"></div>
              		<p class="fullname">Cathedral And John Connon School</p>
              	</a>
             
              <div class="arrow_box" id="upcount2">589</div>
			  <strong class="upcount56662"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','2', '589', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext2"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56662');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56662').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Cathedral-And-John-Connon-School"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Cathedral-And-John-Connon-School&text=I support Cathedral And John Connon School&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Chettinad-Vidyashram" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/chettinad_vidyashram_chennai.gif" alt="Chettinad Vidyashram"></div>
              		<p class="fullname">Chettinad Vidyashram</p>
              	</a>
             
              <div class="arrow_box" id="upcount3">526</div>
			  <strong class="upcount56663"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','3', '526', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext3"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56663');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56663').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Chettinad-Vidyashram"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Chettinad-Vidyashram&text=I support Chettinad Vidyashram&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Delhi-Public-School-Nacharam" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/dps_nacharam_hyderabad_logo.gif" alt="Delhi Public School Nacharam"></div>
              		<p class="fullname">Delhi Public School Nacharam</p>
              	</a>
             
              <div class="arrow_box" id="upcount4">220</div>
			  <strong class="upcount56664"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','4', '220', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext4"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56664');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56664').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Delhi-Public-School-Nacharam"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Delhi-Public-School-Nacharam&text=I support Delhi Public School Nacharam&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Delhi-Public-School-Rohini" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/dps_rohini_new delhi.gif" alt="Delhi Public School Rohini"></div>
              		<p class="fullname">Delhi Public School Rohini</p>
              	</a>
             
              <div class="arrow_box" id="upcount5">404</div>
			  <strong class="upcount56665"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','5', '404', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext5"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56665');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56665').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Delhi-Public-School-Rohini"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Delhi-Public-School-Rohini&text=I support Delhi Public School Rohini&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Indus-Valley-World-School-Kolkata" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/indus_valley_kolkata_all.gif" alt="Indus Valley World School Kolkata"></div>
              		<p class="fullname">Indus Valley World School Kolkata</p>
              	</a>
             
              <div class="arrow_box" id="upcount6">95</div>
			  <strong class="upcount56666"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','6', '95', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext6"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56666');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56666').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Indus-Valley-World-School-Kolkata"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Indus-Valley-World-School-Kolkata&text=I support Indus Valley World School Kolkata&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Modern-High-School-For-Girls-Kolkata" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/modern-high-school-for-girls-kolkata.gif" alt="Modern High School For Girls Kolkata"></div>
              		<p class="fullname">Modern High School For Girls Kolkata</p>
              	</a>
             
              <div class="arrow_box" id="upcount7">71</div>
			  <strong class="upcount56667"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','7', '71', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext7"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56667');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56667').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Modern-High-School-For-Girls-Kolkata"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Modern-High-School-For-Girls-Kolkata&text=I support Modern High School For Girls Kolkata&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Modern-School-Barakhamba" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/modern-school-barakhmabha-delhi.gif" alt="Modern School Barakhamba"></div>
              		<p class="fullname">Modern School Barakhamba</p>
              	</a>
             
              <div class="arrow_box" id="upcount8">828</div>
			  <strong class="upcount56668"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','8', '828', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext8"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56668');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56668').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Modern-School-Barakhamba"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Modern-School-Barakhamba&text=I support Modern School Barakhamba&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=National-Gems-Higher-Secondary-Kolkata" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/national-gems-higher-secondary-kolkata.gif" alt="National Gems Higher Secondary Kolkata"></div>
              		<p class="fullname">National Gems Higher Secondary Kolkata</p>
              	</a>
             
              <div class="arrow_box" id="upcount9">124</div>
			  <strong class="upcount56669"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','9', '124', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext9"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount56669');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount56669').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=National-Gems-Higher-Secondary-Kolkata"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=National-Gems-Higher-Secondary-Kolkata&text=I support National Gems Higher Secondary Kolkata&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=RN-Podar-School-Mumbai" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/rn-podar-mumbai.gif" alt="RN Podar School Mumbai"></div>
              		<p class="fullname">RN Podar School Mumbai</p>
              	</a>
             
              <div class="arrow_box" id="upcount10">64</div>
			  <strong class="upcount566610"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','10', '64', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext10"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566610');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566610').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=RN-Podar-School-Mumbai"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=RN-Podar-School-Mumbai&text=I support RN Podar School Mumbai&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Rajendra-Vidyalaya-Jamshedpur" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/rajendra-vidyalaya-jamshedpur.gif" alt="Rajendra Vidyalaya Jamshedpur"></div>
              		<p class="fullname">Rajendra Vidyalaya Jamshedpur</p>
              	</a>
             
              <div class="arrow_box" id="upcount11">2369</div>
			  <strong class="upcount566611"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','11', '2369', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext11"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566611');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566611').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Rajendra-Vidyalaya-Jamshedpur"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Rajendra-Vidyalaya-Jamshedpur&text=I support Rajendra Vidyalaya Jamshedpur&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Sai-International-School-Bhubaneshwar" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/sai-international-bhubaneswar.gif" alt="Sai International School Bhubaneshwar"></div>
              		<p class="fullname">Sai International School Bhubaneshwar</p>
              	</a>
             
              <div class="arrow_box" id="upcount12">161</div>
			  <strong class="upcount566612"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','12', '161', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext12"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566612');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566612').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Sai-International-School-Bhubaneshwar"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Sai-International-School-Bhubaneshwar&text=I support Sai International School Bhubaneshwar&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Springdales-School-Dhaula-Kuan" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/springdales-dhaula-kuan-delhi.gif" alt="Springdales School Dhaula Kuan"></div>
              		<p class="fullname">Springdales School Dhaula Kuan</p>
              	</a>
             
              <div class="arrow_box" id="upcount13">367</div>
			  <strong class="upcount566613"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','13', '367', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext13"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566613');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566613').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Springdales-School-Dhaula-Kuan"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Springdales-School-Dhaula-Kuan&text=I support Springdales School Dhaula Kuan&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Springdales-School-Pusa-Road" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/springdales-pusa-road-delhi.gif" alt="Springdales School Pusa Road"></div>
              		<p class="fullname">Springdales School Pusa Road</p>
              	</a>
             
              <div class="arrow_box" id="upcount14">748</div>
			  <strong class="upcount566614"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','14', '748', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext14"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566614');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566614').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Springdales-School-Pusa-Road"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Springdales-School-Pusa-Road&text=I support Springdales School Pusa Road&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=St.-Joseph's-Boys-High-School--Bangalore" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/st-joseph-boys-high-school-bangalore.gif" alt="St. Joseph's Boys High School  Bangalore"></div>
              		<p class="fullname">St. Joseph's Boys High School  Bangalore</p>
              	</a>
             
              <div class="arrow_box" id="upcount15">593</div>
			  <strong class="upcount566615"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','15', '593', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext15"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566615');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566615').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=St.-Joseph's-Boys-High-School--Bangalore"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=St.-Joseph's-Boys-High-School--Bangalore&text=I support St. Joseph's Boys High School  Bangalore&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=St.-Joseph's-School,-North-Point-Darjeeling" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/st-joseph-boys-high-school-darjeeling.gif" alt="St. Joseph's School, North Point Darjeeling"></div>
              		<p class="fullname">St. Joseph's School, North Point Darjeeling</p>
              	</a>
             
              <div class="arrow_box" id="upcount16">374</div>
			  <strong class="upcount566616"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','16', '374', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext16"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566616');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566616').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=St.-Joseph's-School,-North-Point-Darjeeling"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=St.-Joseph's-School,-North-Point-Darjeeling&text=I support St. Joseph's School, North Point Darjeeling&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=St-Marys-School-Pune" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/st-mary-pune-logo.gif" alt="St Marys School Pune"></div>
              		<p class="fullname">St Marys School Pune</p>
              	</a>
             
              <div class="arrow_box" id="upcount17">68</div>
			  <strong class="upcount566617"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','17', '68', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext17"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566617');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566617').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=St-Marys-School-Pune"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=St-Marys-School-Pune&text=I support St Marys School Pune&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=St-Patrick-Matric-School-Puducherry" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/st-patrick-matriculation-hss-puducherry.gif" alt="St Patrick Matric School Puducherry"></div>
              		<p class="fullname">St Patrick Matric School Puducherry</p>
              	</a>
             
              <div class="arrow_box" id="upcount18">156</div>
			  <strong class="upcount566618"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','18', '156', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext18"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566618');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566618').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=St-Patrick-Matric-School-Puducherry"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=St-Patrick-Matric-School-Puducherry&text=I support St Patrick Matric School Puducherry&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Sunbeam-School-Lahartara-Varanasi" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/sunbeam-school-lahartara-varanasi.gif" alt="Sunbeam School Lahartara Varanasi"></div>
              		<p class="fullname">Sunbeam School Lahartara Varanasi</p>
              	</a>
             
              <div class="arrow_box" id="upcount19">1263</div>
			  <strong class="upcount566619"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','19', '1263', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext19"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566619');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566619').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Sunbeam-School-Lahartara-Varanasi"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Sunbeam-School-Lahartara-Varanasi&text=I support Sunbeam School Lahartara Varanasi&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Tagore-International-School-Vasant-Vihar" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/tagore-international-school-vasant-vihar-delhi.gif" alt="Tagore International School Vasant Vihar"></div>
              		<p class="fullname">Tagore International School Vasant Vihar</p>
              	</a>
             
              <div class="arrow_box" id="upcount20">136</div>
			  <strong class="upcount566620"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','20', '136', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext20"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566620');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566620').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Tagore-International-School-Vasant-Vihar"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Tagore-International-School-Vasant-Vihar&text=I support Tagore International School Vasant Vihar&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=The-Choice-School-Kochi" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/Choice-School-Logo.png" alt="The Choice School Kochi"></div>
              		<p class="fullname">The Choice School Kochi</p>
              	</a>
             
              <div class="arrow_box" id="upcount21">567</div>
			  <strong class="upcount566621"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','21', '567', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext21"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566621');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566621').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=The-Choice-School-Kochi"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=The-Choice-School-Kochi&text=I support The Choice School Kochi&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Daly-College-Indore" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/daly-college-indore.gif" alt="Daly College Indore"></div>
              		<p class="fullname">Daly College Indore</p>
              	</a>
             
              <div class="arrow_box" id="upcount22">214</div>
			  <strong class="upcount566622"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','22', '214', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext22"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566622');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566622').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Daly-College-Indore"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Daly-College-Indore&text=I support Daly College Indore&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=The-Heritage-School-Kolkata" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/the-heritage-school-kolkata.gif" alt="The Heritage School Kolkata"></div>
              		<p class="fullname">The Heritage School Kolkata</p>
              	</a>
             
              <div class="arrow_box" id="upcount23">369</div>
			  <strong class="upcount566623"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','23', '369', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext23"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566623');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566623').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=The-Heritage-School-Kolkata"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=The-Heritage-School-Kolkata&text=I support The Heritage School Kolkata&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=The-Hyderabad-Public-School-Hyderabad" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/hps-school-logo.png" alt="The Hyderabad Public School Hyderabad"></div>
              		<p class="fullname">The Hyderabad Public School Hyderabad</p>
              	</a>
             
              <div class="arrow_box" id="upcount24">761</div>
			  <strong class="upcount566624"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','24', '761', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext24"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566624');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566624').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=The-Hyderabad-Public-School-Hyderabad"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=The-Hyderabad-Public-School-Hyderabad&text=I support The Hyderabad Public School Hyderabad&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Vasant-Valley-School-New-Delhi" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/vasant-valley-new-delhi.gif" alt="Vasant Valley School New Delhi"></div>
              		<p class="fullname">Vasant Valley School New Delhi</p>
              	</a>
             
              <div class="arrow_box" id="upcount25">606</div>
			  <strong class="upcount566625"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','25', '606', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext25"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566625');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566625').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Vasant-Valley-School-New-Delhi"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Vasant-Valley-School-New-Delhi&text=I support Vasant Valley School New Delhi&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
             
          <li>
            <div class="support_cont">
            	<a href="/newswiz/team.jsp?teamname=Vidya-Mandir-Senior-Mylapore-Chennai" ><div class="img-box"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/team/school-logo/vidya-mandir-secondary-school-mylapore-chennai.gif" alt="Vidya Mandir Senior Mylapore Chennai"></div>
              		<p class="fullname">Vidya Mandir Senior Mylapore Chennai</p>
              	</a>
             
              <div class="arrow_box" id="upcount26">77</div>
			  <strong class="upcount566626"></strong>
              <strong>popularity score</strong>
              
              <a href="javascript:changeRating1('5666','text','1','26', '77', '0','0')" class="vote-btn">              
              </a>  
              <div class="vote-done-msg" id="commenttext26"> </div>   
               
			  <script type="text/javascript">
			   $(document).ready(function () {
                            var json_str = getCookie('upcount566626');
							//console.log("getcookie"+json_str);
                            if (typeof json_str != 'undefined' && json_str==1) {							
                             
                                $('.upcount566626').parent().parent().find('.vote-btn').css({'pointer-events': 'none', 'opacity': '0.3'});
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
                                                	<li class="fb_icon"><a target="_blank" href="https://facebook.com/sharer.php?u=/newswiz/team.jsp?teamname=Vidya-Mandir-Senior-Mylapore-Chennai"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/fb-icon-sup.png" alt=""></a></li>
                                                	<li class="tw_icon"><a target="_blank" href="https://twitter.com/intent/tweet?url=/newswiz/team.jsp?teamname=Vidya-Mandir-Senior-Mylapore-Chennai&text=I support Vidya Mandir Senior Mylapore Chennai&via=indiatoday"><img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newimages/twi-icon-sup.png" alt=""></a></li>							
                                                </ul>
                                            </div>
                                        </div>
          </li>
 
        </ul>
      </div>
    </div>
  </div>
  
</div>


<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newjs/bootstrap.min.js"></script> 

<!-- Swiper JS --> 
<script src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newjs/swiper.min.js"></script> 
<script type="text/javascript" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/resources/newswiz/newjs/custom.js"></script> 
<script type="text/javascript" src="http://code.jquery.com/jquery.js"></script> 
    <script src="http://dotctor.github.io/jQuery.msgBox/scripts/jquery.msgBox.js" type="text/javascript"></script>
    <link href="http://dotctor.github.io/jQuery.msgBox/styles/msgBoxLight.css" rel="stylesheet" type="text/css" />
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
    
    <script>
 $(document).ready(function(e) {
    var photolen  = $('.support-slider > ul > li').length;
	var twidth = $('.support-slider ul li').width();
	var fwidth = (twidth)*photolen;
	$('.support-slider ul.sld_sup').css('width', fwidth);          
	var counters = 1;
	
	$('#nextsupport').click(function(){

		if(counters < photolen-13)
		{
				$('.support-slider ul.sld_sup').animate({
					left : '-=300'
				});
				 counters += 1;
				
				$('#presupport').css('opacity', '1');
		}
		else{
			$('#nextsupport').css('opacity', '0.5');
			
		}
	});
	
	
	$('#presupport').click(function(){
		if(counters == 1)
		{
				$('#presupport').css('opacity', '0.5');
		}
		else{
			$('.support-slider ul.sld_sup').animate({
					left : '+=300'
				});
			counters -= 1;
			$('#nextsupport').css('opacity', '1');          
		}
	});
	
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


