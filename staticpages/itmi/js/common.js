// JavaScript Document
		jQuery(document).ready(function(e) {
			var wd = 1000;
			var len = $('.belt > ul > li').length;
			var ulwidth = 1000 * len;
			jQuery(".belt ul").css('width', ulwidth);
			//$(".belt ul li").css('width', wd);
			var counter = 1;
			var autoslides = setInterval(autoslide, 5000);
			function autoslide(){
			if (counter == len)
				{	
					counter = 1;
					jQuery(".belt ul").animate({ right: '0px'},1000);
				   counter += 1;
				}else
				{
					jQuery(".belt ul").animate({ right:'+=1000'},1000);
					counter += 1;
				}
		}
		
		 jQuery('.search').click(function(){
				jQuery('.searchBoxs').slideToggle('slow');
			});
		 
	});


jQuery(function (){
	createMarquee({
		duration:30000, 
	padding:20,
	hover: true
	});
	
});
