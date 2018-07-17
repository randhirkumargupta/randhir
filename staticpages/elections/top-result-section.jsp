<script>
$(document).ready(function(e) {
    $('.minus').click(function(){
			$(this).toggleClass('plus');
			$('#box-poll-shadow').toggle('hide');
			$(this).parent('span').toggleClass('b-border');
		});
});
</script>
    <div class="top-strip">
        <span style="width:976px; padding-left:21px;" class="e-top"> <h2>Tally</h2><h3>Full house</h3> <h3><a href = "/elections/2014/alliance/nda.html" target = "_blank">Alliance</a></h3>  <h3><a href = "/elections/2014/state/delhi.html" target = "_blank">STATE</a></h3> <h3><a href = "/elections/2014/party/bjp.html" target = "_blank">PARTY</a></h3>  <h3><a href = "/elections/2014/fullhousecompare.html" target = "_blank">PREVIOUS RESULTS</a></h3>  <div class="minus"></div></span>
    </div>
    <div class="clr"></div>
<div class="box-poll-shadow e-shadow" id="box-poll-shadow">

<span id = "hmelect"></span>
<span id = "fhs"></span>
<script>
hmelection1();
</script>
   <div class="clr"></div> 
</div>