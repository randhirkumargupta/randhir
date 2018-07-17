$(document).ready(function(e) {
	
	$('.searc-icon1').click(function(){
		$('#footer1').slideToggle('slow');
	});
	
	/*ALTERNATE ROW*/
    $(".points-content table tr:even").css("background-color", "#f2f2f2");
	$(".points-content table tr:odd").css("background-color", "#e7e7e7");
	$(".key-players table tr:even").css("background-color", "#ffffff");
	$(".key-players table tr:odd").css("background-color", "#f2f2f2");

});

/*TOP SLIDER*/
$(document).ready(function(e) {
        var left1 = 0;
		var left2 = -650;
		var left3 = -1300;
		var left4 = -1950;
		var len = $('.img-border ul li').length;
		var f_width = 650 *len
		$('.img-border ul, .cap-area ul').css('width', f_width);
		$('.thumb ul li').click(function(){
			var current = $(this).attr('id');
			$('.thumb ul li').removeClass('active');
			$(this).addClass('active');
			
			if (current == 1)
			{
				$('.img-border ul, .cap-area ul').animate({left : left1});
			}
			if (current == 2)
			{
				$('.img-border ul, .cap-area ul').animate({left : left2});

				
			}
			if (current == 3)
			{
				$('.img-border ul, .cap-area ul').animate({left : left3});
			}
			if (current == 4)
			{
				$('.img-border ul, .cap-area ul').animate({left : left4});
			}
			ga('send', 'event', 'IPL2015-Bigstory-Slider', 'click',"indiatoday", current, {'nonInteraction': 1});
		});
   });
   


/*BLAST FROM THE PAS*/
$(document).ready(function(e) {
        $('.blast-from-the-past-years ul li').click(function(){
			$('.year-content').slideUp();
			$('.year-content').css('top', '35px')
			$(this).next('div').slideDown('fast');
			$('.blast-from-the-past-years ul li').removeClass('yearcor');
			$(this).addClass('yearcor');
		});
		
		$('.close').click(function(){
			$(this).parent('div').fadeOut();
			$('.blast-from-the-past-years ul li').removeClass('yearcor');
		});
		
		$('.2nd').click(function(){
			$('.year-content').css('top', '66px')
		})
    });
	
	/*VIDEO SLIDER */
$(document).ready(function(e) {
       
		var videoLen = $('.img-border ul li').length;
		var videof_width = 323 *videoLen
		$('.video-border ul').css('width', videof_width);
		$('.thumblist li').click(function(){
			var vcurrent = $(this).attr('id');
			$('.thumblist li').removeClass('video_active');
			$(this).addClass('video_active');
			if (vcurrent == 11)
			{
				$('.video-border ul').animate({left : 0});
			}
			if (vcurrent == 12)
			{
				$('.video-border ul').animate({left : -323});
			}
			if (vcurrent == 13)
			{
				$('.video-border ul').animate({left : -646});
			}
ga('send', 'event', 'IPL2015-video-Slider', 'click',"indiatoday", vcurrent, {'nonInteraction': 1});
		});
   });
   
   
   
   
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
					left : '-=220'
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
					left : '+=220'
				});
			counters -= 1;
			$('.next-ipl').show();
		}
	});
	
	$('.select-team-player select option').click(function(){
		$('.players').hide();
		var current_option = $(this).index();
		$('#player_' + current_option).show();
	});
	
});


$(document).ready(function() {
	$(".team").mouseenter(function(){
    	$('#teamdrop').slideDown("slow");
    }); 
	
	$(".team").mouseleave(function(){
    	$('#teamdrop').slideUp("slow");
    }); 
	
	
	$(".venu").mouseenter(function(){
    	$('#venudrop').slideDown("slow");
    }); 
	
	$(".venu").mouseleave(function(){
    	$('#venudrop').slideUp("slow");
    });
});
   
 
 
   