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
	
	var wdth_h =  $('.img-border ul li').width();
	console.log(wdth_h);
	
      /*  var left1 = 0;
		var left2 = -650;
		var left3 = -1300;
		var left4 = -1950;*/
		
		  var left1 = 0;
		var left2 = - wdth_h;
		var left3 = - (2*wdth_h);
		var left4 = -(3*wdth_h);
		
		var len = $('.img-border ul li').length;
		var f_width = wdth_h *len
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
   var widh_h2 = $('.video-border ul li').width();
	console.log(widh_h2);
	var win_width = $(window).width();   
	if(win_width<=640)
	{
		widh_h2 = widh_h2;
	}
	else
	{
	widh_h2 = widh_h2 +12;	 
	}
		var videoLen = $('.img-border ul li').length;
		
		var videof_width = widh_h2 *videoLen
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
				$('.video-border ul').animate({left : -(widh_h2)});
			}
			if (vcurrent == 13)
			{
				$('.video-border ul').animate({left : -(2*widh_h2)});
			}
ga('send', 'event', 'IPL2015-video-Slider', 'click',"indiatoday", vcurrent, {'nonInteraction': 2});
		});
   });
   
   
   
   
   $(document).ready(function(e) {
	var widh_h1 = $(window).width();
	console.log(widh_h1);
	
	
    var photolen  = $('.belts ul li').length;
	var twidth = $('.belts ul li').width();
	var fwidth = (twidth+10)*photolen;
	$('.belts ul').css('width', fwidth);
	twidth = twidth + 10;
	var counters = 1;
	
	$('.next-ipl').click(function(){

		if(counters < photolen-2)
		{
				$('.belts ul').animate({
					left : '-=' + twidth
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
					left : '+=' + twidth
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
   
 /***************************************************DropDown Menu**************************************/
 $(document).ready(function(){
		$('.mob_nav').click(function(){
			$('.navigation_h').slideToggle();
		});
		/*$('.navigation_h').click(function(){
			$(this).slideUp();
		});*/
		
		$('li.sm_t').click(function(){
								
						$('ul.tp_tg').slideToggle();
							 })
	})
	
	$(function() {
	var Accordion = function(el, multiple) {
		this.el = el || {};
		this.multiple = multiple || false;

		// Variables privadas
		var links = this.el.find('.link');
		// Evento
		links.on('click', {el: this.el, multiple: this.multiple}, this.dropdown)
	}

	Accordion.prototype.dropdown = function(e) {
		var $el = e.data.el;
			$this = $(this),
			$next = $this.next();

		$next.slideToggle();
		$this.parent().toggleClass('open');

		if (!e.data.multiple) {
			$el.find('.submenu').not($next).slideUp().parent().removeClass('open');
		};
	}	

	var accordion = new Accordion($('#accordion'), false);
});

	
 
 
   