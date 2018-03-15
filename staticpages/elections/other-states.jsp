<script>
$(document).ready(function(e) {
    var photolen  = $('.belts ul li').length;
	var twidth = $('.belts ul li').width();
	var fwidth = (twidth+10)*photolen;
	$('.belts ul').css('width', fwidth);
	var counters = 1;
	
	$('.next-ipl').click(function(){

		if(counters < photolen-2)
		{
				$('.belts ul').animate({
					left : '-=207'
				});
				 counters += 1;
				
				$('.back').show();
		}
		else{
			$('.next-ipl').hide();
			
		}
	});
	
	
	$('.back').click(function(){
		if(counters == 1)
		{
				$('.back').hide();
		}
		else{
			$('.belts ul').animate({
					left : '+=207'
				});
			counters -= 1;
			$('.next-ipl').show();
		}
	});
});
</script>

<div class="con-chunk">
    <div class="top-strip" style="width:658px;">
        <span ><h2>Other States</h2></span>
    </div>
    <div class="clr"></div>
    <div class="box-poll-shadow" >
        <div class="photos-slider">
          <div class="next-ipl"></div>
          <div class="back"></div>
          <div class="belts">
            <ul class="cf" style="width: 1320px;">
            
              <li>
   <a href="/elections/2014/state/andhra-pradesh.html"><img align="left" class="imgs" width="200" height="200" alt="Andhra Pradesh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Andhra-Pradesh.png"></a>
   <div class="caption"><a href="/elections/2014/state/andhra-pradesh.html">Andhra Pradesh</a></div>
</li>
<li>
   <a href="/elections/2014/state/arunachal-pradesh.html"><img align="left" class="imgs" width="200" height="200" alt="Arunachal Pradesh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Arunachal-Pradesh.png"></a>
   <div class="caption"><a href = "/elections/2014/state/arunachal-pradesh.html">Arunachal Pradesh</a></div>
</li>
<li>
   <a href="/elections/2014/state/assam.html"><img align="left" class="imgs" width="200" height="200" alt="Assam"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Assam.png"></a>
   <div class="caption"><a href = "/elections/2014/state/assam.html">Assam</a></div>
</li>
<li>
   <a href="/elections/2014/state/bihar.html"><img align="left" class="imgs" width="200" height="200" alt="Bihar"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Bihar.png"></a>
   <div class="caption"><a href = "/elections/2014/state/bihar.html">Bihar</a></div>
</li>
<li>
   <a href="/elections/2014/state/chhattisgarh.html"><img align="left" class="imgs" width="200" height="200" alt="Chhattisgarh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Chattisghar.png"></a>
   <div class="caption"><a href = "/elections/2014/state/chhattisgarh.html">Chhattisgarh</a></div>
</li>
<li>
   <a href="/elections/2014/state/delhi.html"><img align="left" class="imgs" width="200" height="200" alt="Delhi"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Delhi.png"></a>
   <div class="caption"><a href = "/elections/2014/state/delhi.html">Delhi</a></div>
</li>
<li>
   <a href="/elections/2014/state/goa.html"><img align="left" class="imgs" width="200" height="200" alt="Goa"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Goa.png"></a>
   <div class="caption"><a href = "/elections/2014/state/goa.html">Goa</a></div>
</li>
<li>
   <a href="/elections/2014/state/gujarat.html"><img align="left" class="imgs" width="200" height="200" alt="Gujarat"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Gujrath.png"></a>
   <div class="caption"><a href = "/elections/2014/state/gujarat.html">Gujrat</a></div>
</li>
<li>
   <a href="/elections/2014/state/haryana.html"><img align="left" class="imgs" width="200" height="200" alt="Haryana"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Haryana.png"></a>
   <div class="caption"><a href = "/elections/2014/state/haryana.html">Haryana</a></div>
</li>
<li>
   <a href="/elections/2014/state/himachal-pradesh.html"><img align="left" class="imgs" width="200" height="200" alt="Himachal Pradesh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Himachal-Pradesh.png"></a>
   <div class="caption"><a href = "/elections/2014/state/himachal-pradesh.html">Himachal Pradesh</a></div>
</li>
<li>
   <a href="/elections/2014/state/jammu-and-kashmir.html"><img align="left" class="imgs" width="200" height="200" alt="Jammu and Kashmir"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Jammu-and-Kashmir.png"></a>
     <div class="caption"><a href = "/elections/2014/state/jammu-and-kashmir.html">Jammu and Kashmir</a></div>
</li>
<li>
   <a href="/elections/2014/state/jharkhand.html"><img align="left" class="imgs" width="200" height="200" alt="Jharkhand"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Jharkhand.png"></a>
   <div class="caption"><a href = "/elections/2014/state/jharkhand.html">Jharkhand</a></div>
</li>
<li>
   <a href="/elections/2014/state/karnataka.html"><img align="left" class="imgs" width="200" height="200" alt="Karnataka"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Karnataka.png"></a>
   <div class="caption"><a href = "/elections/2014/state/karnataka.html">Karnataka</a></div>
</li>
<li>
   <a href="/elections/2014/state/kerala.html"><img align="left" class="imgs" width="200" height="200" alt="Kerala"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Kerala.png"></a>
   <div class="caption"><a href = "/elections/2014/state/kerala.html">Kerala</a></div>
</li>
<li>
   <a href="/elections/2014/state/madhya-pradesh.html"><img align="left" class="imgs" width="200" height="200" alt="Madhya Pradesh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Madhya-Pradesh.png"></a>
   <div class="caption"><a href = "/elections/2014/state/madhya-pradesh.html">Madhya Pradesh</a></div>
</li>
<li>
   <a href="/elections/2014/state/maharashtra.html"><img align="left" class="imgs" width="200" height="200" alt="Maharashtra"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Maharashtra.png"></a>
    <div class="caption"><a href = "/elections/2014/state/maharashtra.html">Maharashtra</a></div>
</li>
<li>
   <div class="s_text">Manipur</div>
   <a href="/elections/2014/state/manipur.html"><img align="left" class="imgs" width="200" height="200" alt="Manipur"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Manipur.png"></a>
   <div class="caption"><a href = "/elections/2014/state/manipur.html">Manipur</a></div>
</li>
<li>
   <a href="/elections/2014/state/meghalaya.html"><img align="left" class="imgs" width="200" height="200" alt="Meghalaya"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Meghalaya.png"></a>
      <div class="caption"><a href = "/elections/2014/state/meghalaya.html">Meghalaya</a></div>

</li>
<li>
   <a href="/elections/2014/state/mizoram.html"><img align="left" class="imgs" width="200" height="200" alt="Mizoram"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Mizoram.png"></a>
      <div class="caption"><a href = "/elections/2014/state/mizoram.html">Mizoram</a></div>
</li>
<li>
   <a href="/elections/2014/state/odisha.html"><img align="left" class="imgs" width="200" height="200" alt="Odisha"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Odisha.png"></a>
      <div class="caption"><a href = "/elections/2014/state/odisha.html">Odisha</a></div>
</li>
<li>
   <a href="/elections/2014/state/punjab.html"><img align="left" class="imgs" width="200" height="200" alt="Punjab"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Punjab.png"></a>
      <div class="caption"><a href = "/elections/2014/state/punjab.html">Punjab</a></div>
</li>
<li>
   <a href="/elections/2014/state/rajasthan.html"><img align="left" class="imgs" width="200" height="200" alt="Rajasthan"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Rajasthan.png"></a>
        <div class="caption"><a href = "/elections/2014/state/rajasthan.html">Rajasthan</a></div>
</li>
<li>
   <a href="/elections/2014/state/sikkim.html"><img align="left" class="imgs" width="200" height="200" alt="Sikkim"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Sikkam.png"></a>
    <div class="caption"><a href = "/elections/2014/state/sikkim.html">Sikkim</a></div>
</li>
<li>
   <a href="/elections/2014/state/tamil-nadu.html"><img align="left" class="imgs" width="200" height="200" alt="Tamil Nadu"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Tamil-Nadu.png"></a>
   <div class="caption"><a href = "/elections/2014/state/tamil-nadu.html">Tamil Nadu</a></div>
</li>
<li>
   <a href="/elections/2014/state/tripura.html"><img align="left" class="imgs" width="200" height="200" alt="Tripura"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Tirpura.png"></a>
   <div class="caption"><a href = "/elections/2014/state/tripura.html">Tripura</a></div>
</li>
<li>
   <a href="/elections/2014/state/uttar-pradesh.html"><img align="left" class="imgs" width="200" height="200" alt="Uttar Pradesh"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Uttar-Pradesh.png"></a>
   <div class="caption"><a href = "/elections/2014/state/uttar-pradesh.html">Uttar Pradesh</a></div>
</li>
<li>
   <a href="/elections/2014/state/uttarakhand.html"><img align="left" class="imgs" width="200" height="200" alt="Uttarakhand"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Uttranchal.png"></a>
   <div class="caption"><a href = "/elections/2014/state/uttarakhand.html">Uttarakhand</a></div>
</li>
<li>
   <a href="/elections/2014/state/west-bengal.html"><img align="left" class="imgs" width="200" height="200" alt="West Bengal"  src="https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/mpreport/images/Westbengal.png"></a>
   <div class="caption"><a href = "/elections/2014/state/west-bengal.html">West Bengal</a></div>
</li>

              
            </ul>
          </div>
        </div>
      
      
    	
    </div>
    <!--box-poll-shadow end-->
</div>