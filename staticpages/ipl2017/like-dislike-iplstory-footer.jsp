
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
var likedislikeaction = '0';
function handleHttpResponse_likedislike()
{
	var urltoPass = "";
	urltoPass=trim(urltoPass);
	if(urltoPass.length==0){
		urltoPass = url;
	}
	
	if (http2.readyState == 4)
	{
		var results = http2.responseText;
		var arry = results.split('|'); 
		var upcnt=	(arry[0]);
		var dncnt=(arry[1]);
		var cmnt=(arry[2]);
		if (http2.status == 200) {
			
			if(!results.match('already')) {
				if(likedislikeaction==1) {					
					ga('send', 'event', 'LIKE', 'click',urltoPass, 1, {'nonInteraction': 1});
				}
				if(likedislikeaction==2) {					
					ga('send', 'event', 'DISLIKE', 'click',urltoPass, 1, {'nonInteraction': 1});
				} 
			}			
			document.getElementById("upcount").innerHTML = upcnt;
			document.getElementById("downcount").innerHTML = dncnt;
			document.getElementById("commenttext").innerHTML = cmnt;			
		} else {                 
			alert('There was a problem retrieving the data');
		} 
	}
}
function getHTTPObject_2()
{
	var xmlhttp;
	if(window.XMLHttpRequest)
	{
		xmlhttp = new XMLHttpRequest();
	}
		else if (window.ActiveXObject)
	{
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		if (!xmlhttp)
		{
			xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
	}
	return xmlhttp;
}

var http2 = getHTTPObject_2();
function changeRating_story(contentId,content_type,action)
{ 
	//alert("aa");
	upc = document.getElementById('upcount').firstChild.nodeValue;
	downc = document.getElementById('downcount').firstChild.nodeValue;
	totalc = upc+downc;
	
	likedislikeaction = action;
	url="http://indiatoday.intoday.in/rating_data.jsp?content_id="+contentId+"&content_type="+content_type+"&action="+action+"&upcount="+upc+"&downcount="+downc+"&totalcount="+totalc;
	//alert(url);
	http2.open("GET", url, true);
	http2.onreadystatechange = handleHttpResponse_likedislike;
	http2.send(null);
	clickDissable();
}

function clickDissable (){
	$('#upClick').removeAttr('onclick');
	$('#dwClick').removeAttr('onclick');
}

</script>
<script>
function popuplike(mylink, windowname)
{
if (! window.focus)return true;
var href;
if (typeof(mylink) == 'string')
   href=mylink;
else
   href=mylink.href;
window.open(href, windowname, 'width=400,height=200,scrollbars=yes');
return false;
}
</script>



<div class="likedisdiv">

<style>.st_social ul li a{ width:40px; height:40px; display:block}</style>
	<div class="st_social">
    <ul style="display:inline-block; margin-top:17px;">
      <li>
      
             <a onClick="javascript:window.open(this.href,'', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=600,width=600');return false;" href="https://facebook.com/sharer.php?u=http://indiatoday.intoday.in/technology/" data-value-share="Facebook"><span class="icon_f"></span></a>
            </li>
			<li>
                
                <a onClick="javascript:window.open(this.href,'', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=600,width=600');return false;"
							href="https://plus.google.com/share?url=http://indiatoday.intoday.in/technology/"
							data-value-share="Google"><span class="icon_gp"></span></a>            
            </li>			            
            <li>
                
                
                <a href="/technology/#comment"><span class="icon_c"></span></a>
            </li>
			<li>
              
              <a onClick="javascript:window.open(this.href,'', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=600,width=600');return false;" href="https://twitter.com/intent/tweet?url=http://indiatoday.intoday.in/technology/&amp;text=&amp;via=indiatoday" data-value-share="Twitter" ><span class="icon_t"></span></a> 
            	
            </li>
        
        </ul>
        <a href="#" class="st_more" style="display:none">
        	MORE
        </a>
    </div>

<div class="like_dislike_area" style="width:350px;">
   <div class="lkedislake-text" style="line-height:25px;">Do you <br />like this ?</div>
<div class="likedislike-action">
   <a id="upClick" onClick="javascript:changeRating_story('0','','1')"><span class="likeimg"></span></a>
   <span class="likecount" style="margin-right:10px;" id="upcount">5 </span> 
   <a  id="dwClick" onClick="javascript:changeRating_story('0','','2')"><span class="dislikeimg"></span></a>
   <span class="dislcount" id="downcount">3</span>
</div>
</div>
</div>





<style>
#embed a  { color:#625e5f; padding-top:22px; display:block; background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/embedded_icon1.png) center top no-repeat }
#embed_code { margin-bottom:20px; margin-top:0;}
</style>