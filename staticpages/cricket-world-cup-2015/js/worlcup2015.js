
// bigstory slider
$(document).ready(function(e) {
	var len = $(".belt li").length;
	var tWidth = $(".belt li").width();	
	var fWidth = tWidth * len;
	$(".belt").css('width', fWidth)
	 var counter = 1;
	 var liheight;
	 $('.left-arrow').css('opacity', '0.5');
		$('.right-arrow').click(function(){
     // alert('right');
		if(counter < len)
		{
				$('ul.belt').animate({
					left : '-=638'
				});
				counter +=1;
				var liheight = $('#_'+counter).height();
		        $('.belt').height(liheight);
				
				$('.left-arrow').css('opacity', '1');
		}
		else{
			$('.right-arrow').css('opacity', '0.5');
			
		}
	});	
	
	$('.left-arrow').click(function(){
	// alert('left');
		if(counter == 1)
		{
				$('.left-arrow').css('opacity', '0.5');
		}
		else{
			$('.belt').animate({
					left : '+=638'
				});
			counter -= 1;
			var liheight = $('#_'+counter).height();
		  	 $('.belt').height(liheight);
			$('.right-arrow').css('opacity', '1');
		}
	});
});



// Key Player slider section 
$(document).ready(function() {
	var keyplayerlen  = $('.keyplayer_box ul li').length;
	var twidthkeyplayer = $('.keyplayer_box ul li').width();
	var kpwidth = (twidthkeyplayer+5)*keyplayerlen;
	$('.keyplayer_box ul').css('width', kpwidth);
	var counters = 1;
	
	$('#keyplayer-next').click(function(){

		if(counters < keyplayerlen)
		{
				$('.keyplayer_box ul').animate({
					left : '-=305'
				});
				counters +=1;
				
				$('#keyplayer-prev').css('opacity', '1');
		}
		else{
			$('#keyplayer-next').css('opacity', '0.5');
			
		}
	});	
	
	$('#keyplayer-prev').click(function(){
		if(counters == 1)
		{
				$('#keyplayer-prev').css('opacity', '0.5');
		}
		else{
			$('.keyplayer_box ul').animate({
					left : '+=305'
				});
			counters -= 1;
			$('#keyplayer-next').css('opacity', '1');
		}
	});
	});


/// Footer saction script
 $(document).ready(function(e) {
    var photolen  = $('.belts-one ul li').length;
	var twidth = $('.belts-one ul li').width();
	var fwidth = (twidth+10)*photolen;
	$('.belts-one ul').css('width', fwidth);
	var counters = 1;
	
	$('.next-ipl').click(function(){

		if(counters < photolen-2)
		{
				$('.belts-one ul').animate({
					left : '-=190'
				});
				 counters += 1;
				
				$('.back').css('opacity', '1');
		}
		else{
			$('.next-ipl').css('opacity', '0.5');
			
		}
	});
	
	
	$('.back').click(function(){
		if(counters == 1)
		{
				$('.back').css('opacity', '0.5');
		}
		else{
			$('.belts-one ul').animate({
					left : '+=190'
				});
			counters -= 1;
			$('.next-ipl').css('opacity', '1');
		}
	});
	
	$('.select-team-player select option').click(function(){
		$('.players').hide();
		var current_option = $(this).index();
		$('#player_' + current_option).show();
	});
	
});
 
 
//Footer 2

$(document).ready(function(e) {
    var photolen  = $('.belts-two ul li').length;
	var twidth = $('.belts-two ul li').width();
	var fwidth = (twidth+10)*photolen;
	$('.belts-two ul').css('width', fwidth);
	var counters = 1;
	
	$('.next-two').click(function(){

		if(counters < photolen-2)
		{
				$('.belts-two ul').animate({
					left : '-=190'
				});
				 counters += 1;
				
				$('.back-two').css('opacity', '1');
		}
		else{
			$('.next-two').css('opacity', '0.5');
			
		}
	});
	
	
	$('.back-two').click(function(){
		if(counters == 1)
		{
				$('.back-two').css('opacity', '0.5');
		}
		else{
			$('.belts-two ul').animate({
					left : '+=190'
				});
			counters -= 1;
			$('.next-two').css('opacity', '1');
		}
	});
	
	$('.select-team-player select option').click(function(){
		$('.players').hide();
		var current_option = $(this).index();
		$('#player_' + current_option).show();
	});
	
});


//Footer 3

$(document).ready(function(e) {
    var photolen  = $('.slider-year ul li').length;
	var twidth = $('.slider-year ul li').width();
	var fwidth = (twidth)*photolen;
	$('.slider-year ul').css('width', fwidth);
	var counters = 1;
	
	$('#next').click(function(){

		if(counters < photolen-4)
		{
				$('.slider-year ul').animate({
					left : '-=140'
				});
				 counters += 1;
				
				$('#pre').css('opacity', '1');
		}
		else{
			$('#next').css('opacity', '0.5');
			
		}
	});
	
	
	$('#pre').click(function(){
		if(counters == 1)
		{
				$('#pre').css('opacity', '0.5');
		}
		else{
			$('.slider-year ul').animate({
					left : '+=140'
				});
			counters -= 1;
			$('#next').css('opacity', '1');
		}
	});
	
});


$(document).ready(function(){
	$('.popup-inner ul li').click(function(){
	$('.popup-inner ul li').removeClass('active');
	$('.tooltip').fadeOut(300);
		$(this).addClass('active').children('.tooltip').fadeIn(300);
	});
	$('.popup-inner ul li').mouseout(function(){
		$('.tooltip').hide();
	});
});


//Footer 4
 $(document).ready(function(e) {
    var photoleng  = $('.bt-slider ul li').length;

	var twidth = $('.bt-slider ul li').width();
	twidth = twidth+44;
	var fwidth = twidth*photoleng;
	$('.bt-slider ul').css('width', fwidth);
	var counters = 1;
	
	$('#bt-next').click(function(){
		if(counters < photoleng-3)
		{
				$('.bt-slider ul').animate({
					left : '-=120'
				});
				 counters += 1;
				
				$('#bt-pre').css('opacity', '1');
		}
		else{
			$('#bt-next').css('opacity', '0.5');
			
		}
	});
	
	
	$('#bt-pre').click(function(){
		if(counters == 1)
		{
				$('#bt-pre').css('opacity', '0.5');
		}
		else{
			$('.bt-slider ul').animate({
					left : '+=120'
				});
			counters -= 1;
			$('#bt-next').css('opacity', '1');
		}
	});
	
});