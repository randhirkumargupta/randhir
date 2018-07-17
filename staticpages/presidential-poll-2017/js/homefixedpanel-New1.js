var windoworientation = -90;
$(document).ready(function(){
if(navigator.userAgent.toLowerCase().match('ipad')) {
windoworientation = window.orientation;
	if(windoworientation==90) {
		windoworientation = windoworientation*-1;	
	}
$(window).on("orientationchange",function(){
	windoworientation = window.orientation;
	
			if(navigator.userAgent.toLowerCase().match('ipad')) {
	var oldstyle="";//
	if(window.orientation == 180) // Portrait
	{
		oldstyle = $('#leftpart').attr('style');
		$('#leftpart').removeAttr('style');
		$('#leftpart').attr("style",'position:relative');
						newheightad = $('#today_big_story_chunk').height()+85;
					
					$('#rightpanel').css({position:'absolute',top:newheightad,right:'20px'});
					$('#rightpanel').css({right:'20px'});
	}
	else // Landscape
	{
		$('#leftpart').removeAttr('style');
		$('#leftpart').attr('style',oldstyle);
		$('#rightpanel').attr("style",'top:580px');
		
	}
}
});
}
if ($(window).width() > 800)
{
	

	
	
	
	var toppanel = '';
 $(document).ready(function(){
			var window_wid = $(window).width();
			var window_ht = $(window).height();
			var outer_wid = $('.wrapper').width();
			var right_set = window_wid - outer_wid;
			var right_ht = $('#rightpanel').height();	
			var right_set = window_wid - outer_wid;
			
			
			right_set = right_set/2;
			var right_part = $('#rightpart').height();
			
			var totao_doc = $(document).height();
			var footer_ht = $('#footerpanel').height();

			totao_doc = totao_doc - footer_ht;
			var top_rightpanel = 472+right_ht;
			toppanel = $('#toppanel').height();
			breakingnews = $('#breakingnews').height();
			toppanel = toppanel + breakingnews
	
	$(window).scroll(function(){
		if(windoworientation==90) {
			windoworientation = windoworientation*-1;	
		}
			var toplocation = $(window).scrollTop();			
              
				if ( (toplocation) >= ($(document).height() - window_ht-1100)  )
				{					
					$('#rightpanel').attr('style',$('#rightpanel').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'-10px',right:'0px',top:'auto'});
				
				//$('.logo').html("firdt---"+toplocation +'>'+ ($(document).height() - window_ht-900));
				
				/*} else  {
					 if(toplocation<=(toppanel+right_ht-window_ht)) {
						$('#rightpanel').css({position:'absolute',top:'1px',right:'0px'});
						$('#leftpart').css({position:'absolute',top:'525px',left:'0px'});
						$('.logo').html("thrdr---"+toplocation +'>'+ ($(document).height() - window_ht-900));
					 } else if ( (toplocation) >= (toppanel+right_ht-window_ht) ) {
						
						$('#rightpanel').css('position', 'fixed');
						//$('#rightpanel').css('overflow', 'hidden');
						$('#rightpanel,#leftpart').css('right', right_set);
						$('#rightpanel').css('bottom', 0);
						$('#rightpanel').css('top', none);
						$('#leftpart').css('top', '0px!Important');
						
						$('.logo').html("sec---"+toplocation +'>'+ (top_rightpanel - window_ht));
					}*/
				}
				
				if(toplocation<=(toppanel+right_ht-window_ht)) {
					if(windoworientation != -90) {
						newheightad = $('#today_big_story_chunk').height()+85;
					} else {
						newheightad = '1px';	
					}
					//manager according to new design
					$('#rightpanel').css({position:'absolute',top:'800px',right:'0px'});
						if(windoworientation == -90) {
							$('#leftpart').css({position:'absolute',top:'780px',left:'0px'});
							$('#rightpanel').css({position:'absolute',top:'0px',right:'0px'})

						}
				}
				
				if(toplocation>=(toppanel+right_ht-window_ht)) {
					$('#rightpanel').css({position:'fixed',top:'-2710px', right: right_set});
					if(windoworientation == -90) {
						$('#leftpart').css({position:'fixed',top:'-990px', left: right_set, border:'1px solid red;'});
					}
				}
				
				
				if ( (toplocation) >= ($(document).height() - window_ht-700)  )
				{					
					$('#rightpanel').attr('style',$('#rightpanel').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'-10px',right:'0px',top:'auto'});
					if(windoworientation == -90) {
						$('#leftpart').attr('style',$('#leftpart').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'13px',left:'0px',top:'auto'});
						//$('.logo').html("firdt---"+toplocation +'>'+ ($(document).height() - window_ht-900));
					}
				}
				
				
				
				
				
				
			});
});
}
						   });




if ($(window).width() < 801){
	
//window.addEventListener('scroll', function() { alert("Scrolled"); });
// or
//$(window).scroll(function() { alert("Scrolled"); });
// or
//window.onscroll = function() { alert("Scrolled"); };
	
	var toppanel = '';
	
 $(document).ready(function(){
			var window_wid = $(window).width();
			var window_ht = $(window).height();
			var outer_wid = $('.wrapper').width();
			var right_set = window_wid - outer_wid;
			var right_ht = $('#rightpanel').height();	
			var right_set = window_wid - outer_wid;
			
			
			var right_set = right_set/2;
			var right_part = $('#rightpart').height();
			
			var totao_doc = $(document).height();
			var footer_ht = $('#footerpanel').height();

			var totao_doc = totao_doc - footer_ht;
			var top_rightpanel = right_ht;
			var toppanel = $('#toppanel').height();
			var breakingnews = $('#breakingnews').height();
			var toppanel = toppanel + breakingnews;
	
	window.addEventListener('scroll', function() {
				//alert("Scrolled");
			    var toplocation = $(window).scrollTop();
				
                
				if ( (toplocation) >= ($(document).height() - window_ht-1100)  )
				{					
					$('#rightpanel').attr('style',$('#rightpanel').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'-10px',right:'20px',top:'auto'});
				
				//$('.logo').html("firdt---"+toplocation +'>'+ ($(document).height() - window_ht-900));
				
				/*} else  {
					 if(toplocation<=(toppanel+right_ht-window_ht)) {
						$('#rightpanel').css({position:'absolute',top:'1px',right:'0px'});
						$('#leftpart').css({position:'absolute',top:'525px',left:'0px'});
						$('.logo').html("thrdr---"+toplocation +'>'+ ($(document).height() - window_ht-900));
					 } else if ( (toplocation) >= (toppanel+right_ht-window_ht) ) {
						
						$('#rightpanel').css('position', 'fixed');
						//$('#rightpanel').css('overflow', 'hidden');
						$('#rightpanel,#leftpart').css('right', right_set);
						$('#rightpanel').css('bottom', 0);
						$('#rightpanel').css('top', none);
						$('#leftpart').css('top', '0px!Important');
						
						$('.logo').html("sec---"+toplocation +'>'+ (top_rightpanel - window_ht));
					}*/
				}
				
				if(toplocation<=(toppanel+right_ht-window_ht)) {
					$('#rightpanel').css({position:'absolute',top:'780px',right:'20px'});
					//$('#leftpart').css({position:'absolute',top:'1025px',left:'0px'});
				}
				
				if(toplocation>=(toppanel+right_ht-window_ht)) {
					$('#rightpanel').css({position:'fixed',top:'-2000px', right:'20px'});
					//$('#leftpart').css({position:'fixed',top:'-1125px', left: right_set});
				}
				
				
				if ( (toplocation) >= ($(document).height() - window_ht-700)  )
				{					
					$('#rightpanel').attr('style',$('#rightpanel').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'-10px',right:'20px',top:'auto'});
					//$('#leftpart').attr('style',$('#leftpart').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'13px',left:'0px'});
					//$('.logo').html("firdt---"+toplocation +'>'+ ($(document).height() - window_ht-900));
				}
				
				
				
				
				
				
			});
});
}






(function($){
$(window).load(function(){	
$(".l_cnt_t").css("height", "570px");
$(".l_cnt_t").mCustomScrollbar({
			horizontalScroll: false,
            autoDraggerLength: true,
            autoHideScrollbar: true,
            advanced:{
                autoScrollOnFocus: false,
                updateOnContentResize: true,
                updateOnBrowserResize: true
            }
							   
});				
});
})(jQuery);

$(document).ready(function(e) {
 //$('#topnext01').hide();
	var len = $(".box-cont2 ul li").length;
	var tHidth = $(".box-cont2 ul li").height();	
	var sWidth = tHidth;
	var fWidth = sWidth * len;
	//$(".box-cont2").css('height', fWidth)
	 var counter = 1;
	 //NEXT
	 $('#topprev_h01').click(function(){
		//alert('next');
		 if(counter < len){
		   $('.box-cont2 ul').animate({'top' :'-=155'})		   
		   counter +=1;
		     //$('#topprev_h01').css('opacity','0.5');
			 $('#topnext_h01').css('opacity','1');
		 }
		 else{
			 $('#topprev_h01').css('opacity','0.5');
		 }
	 });
	 //PREV
	 $('#topnext_h01').click(function(){
		 if(counter == 1){
			 $('#topnext_h01').css('opacity','0.5');
		 }else{$('#topprev_h01').css('opacity','1');
			   
			 $('.box-cont2 ul').animate({'top' :'+=155'});
		     counter -=1;
		 }
	 });

	
	
	
	 
});



//$(window).load( function() {
//        //SetImageSizes();
//        $(".l_cnt_t").css("height", "570px");
//        $(".l_cnt_t").css("overflow-y", "hidden");
//
//        $.getScript("http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/speed-test/jquery.mCustomScrollbar.concat.min.js", function () {
//             $('.l_cnt_t').mCustomScrollbar({
//                   horizontalScroll: false,
//            autoDraggerLength: true,
//            autoHideScrollbar: true,
//            advanced:{
//                autoScrollOnFocus: false,
//                updateOnContentResize: true,
//                updateOnBrowserResize: true
//            }
//                  });
//           });
//    });





/*(function($){
$(window).load( function() {
     $(".l_cnt_t").css("height", "570px");
        //$(".l_cnt_t").css("overflow-y", "hidden");

    $.getScript("http://cdn.jsdelivr.net/jquery.mcustomscrollbar/3.0.7/jquery.mCustomScrollbar.concat.min.js", function () {
        $('.l_cnt_t').mCustomScrollbar();
    });
});
})(jQuery);*/