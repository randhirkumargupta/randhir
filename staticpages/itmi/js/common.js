// JavaScript Document
		$(document).ready(function(e) {
			var wd = 1000;
			var len = $('.belt > ul > li').length;
			var ulwidth = 1000 * len;
			$(".belt ul").css('width', ulwidth);
			//$(".belt ul li").css('width', wd);
			var counter = 1;
			var autoslides = setInterval(autoslide, 5000);
			function autoslide(){
			if (counter == len)
				{	
					counter = 1;
					$(".belt ul").animate({ right: '0px'},1000);
				   counter += 1;
				}else
				{
					$(".belt ul").animate({ right:'+=1000'},1000);
					counter += 1;
				}
		}
		
		 $('.search').click(function(){
				$('.searchBoxs').slideToggle('slow');
			});
		 
	});


$(function (){
	createMarquee({
		duration:30000, 
	padding:20,
	hover: true
	});
	//example of overwriting defaults: 
	
	// createMarquee({
	// 		duration:30000, 
	// 		padding:20, 
	// 		marquee_class:'.example-marquee', 
	// 		container_class: '.example-container', 
	// 		sibling_class: '.example-sibling', 
	// 		hover: false});
	// });
});
