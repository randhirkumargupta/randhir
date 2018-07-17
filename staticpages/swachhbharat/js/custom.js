$(document).ready(function(e) { 

		var len = $('.inner-belts  > div').length;
		var wd = $('.inner-belts  > div').width();
		
		var counter = 1;
		$('#_1').addClass('active');
	$('.thumb ul li').click(function(){
		var current = $(this).index();
		$('.thumb ul li').removeClass('active');
		$(this).addClass('active');
		switch(current){
			case 0 :{
				$(".inner-belts").animate({left:0});
				counter = 1;
				}
				 break;
				
			case 1 :{
				$(".inner-belts").animate({left: -wd*1});
				counter = 2;
				}
				 break;
			case 2 :{
				$(".inner-belts").animate({left: -wd*2});
				counter = 3;
				}
			   break;			
			   
			 case 3 :{
				$(".inner-belts").animate({left: -wd*3});
				counter = 4;
				}
			   break;			
			 
			 case 4 :{
				$(".inner-belts").animate({left:-wd*4});
				counter = 5;
				}
		}
		_gaq.push(['_trackEvent', 'BT-Bigstory-Slider', 'CLICK', counter]);
	});
	
	
	var autoslides = setInterval(autoslide, 5000);
	
	function autoslide(){
	
		if (counter == len)
			{	
			
				counter = 1;
				$(".inner-belts").animate({
						left: '0px'
					});
					$('.thumb ul li').removeClass('active');
					$('#_' + counter).addClass('active');
			
			}else
			{
				$(".inner-belts").animate({
						left: '-='+wd
					}, 1000)
				counter += 1;
				$('.thumb ul li').removeClass('active');
				$('#_' + counter).addClass('active');
			}
	} 

	$('.belt').mouseenter(function(){
		clearInterval(autoslides);
	});
	
	$('.belt').mouseleave(function(){
		autoslides = setInterval(autoslide, 5000);
	});
});



$(document).ready(function(){

var photolendntmiss  = $('.dontmiss_box ul li').length;
	var twidthdntmiss = $('.dontmiss_box ul li').width();
	var fwidth = (twidthdntmiss+5)*photolendntmiss;
	$('.dontmiss_box ul').css('width', fwidth);
	var counters = 1;
	
	$('#dontmiss-next').click(function(){

		if(counters < photolendntmiss)
		{
				$('.dontmiss_box ul').animate({
					left : '-=305'
				});
				counters +=1;
				
				$('#dontmiss-prev').css('opacity', '1');
		}
		else{
			$('#dontmiss-next').css('opacity', '0.5');
			
		}
	});	
	
	$('#dontmiss-prev').click(function(){
		if(counters == 1)
		{
				$('#dontmiss-prev').css('opacity', '0.5');
		}
		else{
			$('.dontmiss_box ul').animate({
					left : '+=305'
				});
			counters -= 1;
			$('#dontmiss-next').css('opacity', '1');
		}
	});
});