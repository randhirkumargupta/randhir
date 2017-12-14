 <script type="text/javascript" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/js/jscharts.js"></script>
  
<style>
popin_example1, .popin_select_template {
    background-image: url("http://www.jscharts.com/images/ex_popin_bg.jpg");
    text-align: center;
	border:1px solid red;
	width:600px;
	overflow:scroll
	
	
}

#example_line_5, #example_line_5 * {
    animation: 0s ease 0s normal none 1 none;
    background: none no-repeat fixed left top transparent;
    border: medium none;
    border-radius: 0 0 0 0;
    bottom: auto;
    box-shadow: none;
    clear: none;
    cursor: auto;
    direction: ltr;
    display: block;
    float: none;
    font-family: "Lucida Grande","Lucida Sans Unicode","Lucida Sans",Verdana,Arial,Helvetica,sans-serif;
    font-size: 10px;
    font-size-adjust: none;
    font-stretch: normal;
    font-style: normal;
    font-variant: normal;
    font-weight: normal;
    height: auto;
    left: 0;
    letter-spacing: normal;
    line-height: normal;
    list-style: disc outside none;
    margin: 0;
    max-height: none;
    max-width: none;
    min-height: 0;
    min-width: 0;
    opacity: 1;
    outline-style: none;
    outline-width: medium;
    overflow: visible;
    padding: 0;
    position: static;
    right: auto;
    text-align: left;
    text-decoration: none;
    text-indent: 0;
    text-shadow: none;
    text-transform: none;
    top: 0;
    vertical-align: baseline;
    visibility: visible;
    width: auto;
    word-spacing: normal;
    z-index: 1;
}
.review-banner { background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/arjunkapoor/ARJUN-KAPOOR.jpg) left top no-repeat; width:660px; height:100px; color:#333; font-family:Arial, Helvetica, sans-serif; font-size:19px; font-weight:bold; position:relative; float:left; margin-top:30px; margin-bottom:-10px;}
.carrer-graph { position:absolute; top:4px; right:34px; color:#fff; font-size:16px;}
.names {
	position: absolute;
	top: 50px;
	left: 170px;
	font-size: 29px;
	width: 206px;
}
.know-more { color:#333; font-family:Arial, Helvetica, sans-serif; font-size:14px; float:right; margin-bottom:-39px; margin-top:20px;}
.clear {clear:both}

</style>
<style>
#tooltip_JSChart_example_line_122_59_28.98 { margin-left:-188px!Important;}
#tooltip_JSChart_example_line_122_59_28.98_over {margin-left:-188px!Important;}
</style>

<div class="review-banner">
   <div class="carrer-graph">Career Graph</div>
    <div class="names">Arjun Kapoor</div>
</div>
<div class="clear"></div>
<div class="know-more">Click on the dots to know more...</div>


<div class="clear"></div>
<div style=" width:660px; position:relative; padding-bottom:10px; height:470px; padding-right:">
<div id="arjunkapoor_122" class="popin_example"> 
					<div id="popin_example_line_1804" class="example_canvas">Loading...</div>
				</div>
				
</div>			
 
 <script>
	var myChart = new JSChart('popin_example_line_1804', 'line', 'f61b1a3df6065e242b1350f23e3df44e,c79c24b11a5fa131e5f3af9de0a95721');
					myChart.setDataArray([[1, 45.73],[2, 22.35],[3, 78.60],[4, 102.13 ],[5, 35.91]]);
					myChart.setSize(650, 400);
					myChart.setIntervalEndY(120);
					myChart.setIntervalStartY(0);
					myChart.setAxisValuesNumberY(13);
					myChart.setTitle(' ');
					myChart.setTitleFontSize(12);
					myChart.setTitleFontFamily('arial');
					//myChart.setAxisNameFontSize(16);
					myChart.setTitleColor('#000000');
					myChart.setAxisValuesAngle(65);
					//myChart.setAxisPaddingBottom(150);
					myChart.setAxisValuesColor('#000000');
					myChart.setShowXValues(false);
					myChart.setLabelX([1,'2012']);
					myChart.setLabelX([2,'2013']);
					myChart.setLabelX([3,'2014']);
					myChart.setLabelX([4,'2014']);
					myChart.setLabelX([5,'2014']);
					
					
					myChart.setLineColor('#D92323');
					myChart.setLineWidth(6);
					myChart.setFlagColor('#ff0000');
					//myChart.setFlagFillColor('#333333');
					myChart.setFlagRadius(10);
					myChart.setFlagWidth(10);
					myChart.setTooltipPosition('ne');
					//myChart.setTooltipPadding('40');
					



					myChart.setTooltip([1,'<span style="font-weight:bold; font-size:14px;">Ishaqzaade!!</span> <br>Rs. 45.73 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/arjunkapoor/ishaqzaade_167.jpg" width="88" height="66">']);
					myChart.setTooltip([2,'<span style="font-weight:bold; font-size:14px;">Aurangzeb</span> <br>Rs.  22.35 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/arjunkapoor/aurangzeb_167.jpg" width="88" height="66">']);
					myChart.setTooltip([3,'<span style="font-weight:bold; font-size:14px;">Gunday</span> <br>Rs.  78.60 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/arjunkapoor/gunday_167.jpg" width="88" height="66">']);
					myChart.setTooltip([4,'<span style="font-weight:bold; font-size:14px;">2 States</span> <br>Rs.  102.13 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/deepika/2-states.jpg" width="88" height="66">']);
					myChart.setTooltip([5,'<span style="font-weight:bold; font-size:14px;">Finding Fanny</span> <br>Rs.  35.91 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/arjunkapoor/finding-fanny.jpg" width="88" height="66">']);
					
					
			
					
					//myChart.setTooltip([11,'175']);
					myChart.setFlagRadius(4);
					myChart.setGridOpacityY(0);
					myChart.draw();
					
 
 </script>

     <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script>


$(document).ready(function(){
	$('#tooltip_JSChart_example_line_122_1_10').css('margin-left', '150px')
	$('#tooltip_JSChart_example_line_122_2_3').css('margin-left', '160px')
	$('#tooltip_JSChart_example_line_122_3_3').css('margin-left', '170px')
	$('#tooltip_JSChart_example_line_122_4_11').css('margin-left', '180px')
	$('#tooltip_JSChart_example_line_122_5_11').css('margin-left', '190px')
	$('#tooltip_JSChart_example_line_122_6_4').css('margin-left', '180px')
	$('#tooltip_JSChart_example_line_122_7_4').css('margin-left', '190px')
	$('#tooltip_JSChart_example_line_122_8_8').css('margin-left', '220px')
	
$("img").each(function(){
                  if($(this).attr("width")==77 && $(this).attr("height")==19)
                                  {
                                  $(this).hide();
                                  }
                                  
                });

});


$(window).load(function(){
	
	
	

	
});
</script>   
<style>


</style>
<div style="height:25px; clear:both"></div>