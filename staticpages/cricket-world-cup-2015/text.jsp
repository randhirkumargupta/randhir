<script src="js/ajaxinclude.js"></script>
<link rel="stylesheet" type="text/css" href="/cricket-world-cup-2015/css/custom-scroll.css" />
<script type="text/javascript" src="/cricket-world-cup-2015/js/jquery.mCustomScrollbar.concat.min.js"></script>
<script type="text/javascript">
	$(window).load(function(){
		$("#points").mCustomScrollbar({});
		$("#rightschdule").mCustomScrollbar({});
		$("#content1").mCustomScrollbar({});
		$("#content2").mCustomScrollbar({});
	});
</script>
<script type="text/javascript">
	$(document).ready(function(){
		$('ul.pool li').click(function(){
	    $('ul.pool li a').removeClass('active');
	    $(this).children('a').addClass('active');

	    for(var i=1;i<=5;i++){
			$('#content'+i).hide()}
	    $('#conten'+$(this).children('a').attr('rel')).show();
	    return false;
  		});
	});
</script>




<div style="margin:20px 0 10px 0">

    <div class="right-box" style="float:left; overflow:hidden;">
        <div class="heading">SCHEDULE <span class="readmore"><a href="/cricket-world-cup-2015/schedule.jsp">More</a></span></div>
        <script type="text/javascript">ajaxinclude("/staticcontent_chunk.jsp?contentTitle=RIGHTNAVWCSCHEDULE")</script>
    </div>

    <div class="right-box" style="float:right; overflow:hidden;">
        <div class="heading">POINTS TALLY <span class="readmore"><a href="/cricket-world-cup-2015/pointstally.jsp">More</a></span></div>
        <script type="text/javascript">ajaxinclude("/staticcontent_chunk.jsp?contentTitle=RIGHTNAVPOINTSTALLY")</script>
    </div>

</div>
