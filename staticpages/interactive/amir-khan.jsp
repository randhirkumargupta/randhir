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
.review-banner-amir { background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/Aamir-khan-banner.jpg) left top no-repeat; width:660px; height:100px; color:#333; font-family:Arial, Helvetica, sans-serif; font-size:19px; font-weight:bold; position:relative; float:left; margin-top:30px; margin-bottom:-10px;}
.carrer-graph { position:absolute; top:9px; right:32px;}
.names { position:absolute; top:50px; left:170px; font-size:29px;}

.review-banner1 { background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Priyanka-Chopra.jpg) left top no-repeat; width:660px; height:100px; color:#333; font-family:Arial, Helvetica, sans-serif; font-size:19px; font-weight:bold; position:relative; float:left; margin-top:30px; margin-bottom:-10px;}

.review-banner2 { background:url(http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/Kangna-Ranaut.jpg) left top no-repeat; width:660px; height:100px; color:#333; font-family:Arial, Helvetica, sans-serif; font-size:19px; font-weight:bold; position:relative; float:left; margin-top:30px; margin-bottom:-10px;}
.know-more { color:#333; font-family:Arial, Helvetica, sans-serif; font-size:14px; float:right; margin-bottom:-39px; margin-top:20px;}

.clear {clear:both}

</style>
<style>
#tooltip_JSChart_example_line_122_59_28.98 { margin-left:-188px!Important;}
#tooltip_JSChart_example_line_122_59_28.98_over {margin-left:-188px!Important;}
</style>

<div class="review-banner-amir">
    <div class="carrer-graph">Career Graph</div>
    <div class="names">Aamir Khan</div>
</div>
<div class="clear"></div>
<div class="know-more" style="text-align:center;">Click on the dots to know more...<br />
<b>movies from 2000 till date</b>
</div>


<div class="clear"></div>
<div style=" width:660px; position:relative; padding-bottom:10px; height:470px; padding-right:">
<div id="popin_example_line_1245" class="popin_example">
					<div id="example_line_122" class="example_canvas">Loading...</div>
				</div>

</div>

 <script>
	var myChart = new JSChart('popin_example_line_1245', 'line', 'f61b1a3df6065e242b1350f23e3df44e,c79c24b11a5fa131e5f3af9de0a95721');
					myChart.setDataArray([[1, 13.25],[2,29],[3, 15.75],[4, 28.25],[5, 50],[6, 52],[7, 62.48],[8, 114],[9, 202.47],[10, 13.77],[11,  93.40],[12, 284.27]]);
					myChart.setSize(640, 450);
					myChart.setIntervalEndY(290);
					myChart.setIntervalStartY(0);
					myChart.setAxisValuesNumberY(22);
					myChart.setTitle(' ');
					myChart.setTitleFontSize(12);
					myChart.setTitleFontFamily('arial');
					//myChart.setAxisNameFontSize(16);
					myChart.setTitleColor('#000000');
					myChart.setAxisValuesAngle(65);
					//myChart.setAxisPaddingBottom(150);
					myChart.setAxisValuesColor('#000000');
					myChart.setShowXValues(false);
					myChart.setLabelX([1,'2000']);
					myChart.setLabelX([2,'2001']);
					myChart.setLabelX([3,'2001']);
					myChart.setLabelX([4,'2005']);
					myChart.setLabelX([5,'2006']);
					myChart.setLabelX([6,'2006']);
					myChart.setLabelX([7,'2007']);
					myChart.setLabelX([8,'2008']);
					myChart.setLabelX([9,'2009']);
					myChart.setLabelX([10,'2011']);
					myChart.setLabelX([11,'2012']);
					myChart.setLabelX([12,'2013']);

					myChart.setLineColor('#D92323');
					myChart.setLineWidth(6);
					myChart.setFlagColor('#ff0000');
					//myChart.setFlagFillColor('#333333');
					myChart.setFlagRadius(10);
					myChart.setFlagWidth(10);
					myChart.setTooltipPosition('nw');
					//myChart.setTooltipPadding('40');


					myChart.setTooltip([1,'<span style="font-weight:bold; font-size:14px;">Mela</span> <br>Rs. 13.25 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/mela.jpg" width="88" height="66">']);
					myChart.setTooltip([2,'<span style="font-weight:bold; font-size:14px;">Lagaan</span> <br>Rs.  29 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/lagaan.jpg" width="88" height="66">']);
					myChart.setTooltip([3,'<span style="font-weight:bold; font-size:14px;">Dil Chahta Hai</span> <br>Rs.  15.75 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/dilchahtahai.jpg" width="88" height="66">']);
					myChart.setTooltip([4,'<span style="font-weight:bold; font-size:14px;">Mangal Pandey</span> <br>Rs.  28.25 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/mangalpandey.jpg" width="88" height="66">']);
					myChart.setTooltip([5,'<span style="font-weight:bold; font-size:14px;">Rang De Basanti</span> <br>Rs.  50 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/rang-de-basanti.jpg" width="88" height="66">']);
					myChart.setTooltip([6,'<span style="font-weight:bold; font-size:14px;">Fanaa</span> <br>Rs.  52 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/fanaa.jpg" width="88" height="66">']);
					myChart.setTooltip([7,'<span style="font-weight:bold; font-size:14px;">Taare Zameen Pe</span> <br>Rs.  62.48 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/taare-zameen-pe.jpg" width="88" height="66">']);
					myChart.setTooltip([8,'<span style="font-weight:bold; font-size:14px;">Ghajini</span> <br>Rs.  114 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/ghajini.jpg" width="88" height="66">']);
					myChart.setTooltip([9,'<span style="font-weight:bold; font-size:14px;">3 Idiots</span> <br>Rs.   202.47 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/3-idiots.jpg" width="88" height="66">']);
					myChart.setTooltip([10,'<span style="font-weight:bold; font-size:14px;">Dhobi Ghat</span> <br>Rs.  13.77 crore  <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/dhobi-ghat.jpg" width="88" height="66">']);
					myChart.setTooltip([11,'<span style="font-weight:bold; font-size:14px;">Talaash</span> <br>Rs.  93.40 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/talaash.jpg" width="88" height="66">']);
					myChart.setTooltip([12,'<span style="font-weight:bold; font-size:14px;">Dhoom 3</span> <br>Rs.  284.27 crore <img src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/images/movie-review/aamir/dhoom-new_167.jpg" width="88" height="66">']);



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
