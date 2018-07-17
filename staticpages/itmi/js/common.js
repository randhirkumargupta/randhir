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
$(document).ready(function(e) {
    $('.months_term').hover(function(){
		$('.aboutsubboxtop').show();
		})
	$('.aboutsubboxtop').mouseleave(function(){
		$(this).hide();
		})
		$('.months_term01').hover(function(){
		$('.about_subbox01').show();
		})
	$('.about_subbox01').mouseleave(function(){
		$(this).hide();
		})
});
$(document).ready(function(){
			$("#tab1").click(function(){
				$(this).next('.down').slideToggle();
				$("#dif").slideDown();
				$("#down2, #down3").slideUp();
			});
			$("#tab2").click(function(){
				$(this).next('.down').slideToggle();
				$("#dif2").slideDown();
				$("#down1, #down3").slideUp();
			});
			$("#tab3").click(function(){
				$(this).next('.down').slideToggle();
				$("#down2, #down4").slideUp();
			});
			$("#spec").click(function(){
				$(this).next('.down').slideToggle();
				$("#dif").slideUp()
		
			});
			$("#course").click(function(){
				$(this).next('.down').slideToggle();
				$("#dif2").slideUp()
				
			});
			
		});
$(document).ready(function() {
            $('.search').click(function(){
                $('.searchBoxs').slideToggle('slow');
            });
        });
$(document).ready(function(){
		$('#testimonials').addClass('current');
	});

