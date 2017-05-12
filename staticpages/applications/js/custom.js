/*home slider start*/
$(document).ready(function(e) {
	var len = $(".belt li").length;
	var tWidth = $(".belt li").width();
	var fWidth = tWidth * len;
	$(".belt").css('width', fWidth)
	 var counter = 1;
	 if(counter == 1){
		 $('.nav-area li a').removeClass('active')
		 $('.nav-area li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 2){
		 $('.nav-area li a').removeClass('active')
		 $('.nav-area li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 3){
		 $('.nav-area li a').removeClass('active')
		 $('.nav-area li:nth-child(1) a').addClass('active');
	 }
	 
	 
	 
	 //NAV
	 $('.nav-area li a').click(function(){
		 $('.nav-area li a').removeClass('active')
		 $(this).addClass('active');
	 });
		 
	   //NAVIGATION
	 $('.nav-area li').click(function(){
		 var currentli = $(this).index();
		 if(currentli == 0){
			 $('.belt').animate({'left' :'0'});
			 $('.prev').fadeOut();
			 $('.next').fadeIn();
			 counter = 1;
		 }
		 if(currentli == 1){
			 $('.belt').animate({'left' :'-944'});
			 counter = 2;
			 $('.next , .prev').fadeIn();
		 }
		 if(currentli == 2){
			 $('.belt').animate({'left' :'-1884'});
			 $('.next').fadeOut();
			 $('.prev').fadeIn();
			 counter = 3;
		 }
		 if(currentli == 3){
			 $('.belt').animate({'left' :'-2828'});
			 $('.prev').fadeOut();
			 $('.next').fadeIn();
			 counter = 4;
		 }
		 if(currentli == 4){
			 $('.belt').animate({'left' :'-3772'});
			 counter = 5;
			 $('.next , .prev').fadeIn();
		 }
		 if(currentli == 5){
			 $('.belt').animate({'left' :'-4716'});
			 $('.next').fadeOut();
			 $('.prev').fadeIn();
			 counter = 6;
		 }
	 });  
    
});
/*home slider end*/

/*chunk slider start*/
$(document).ready(function(e) {
	$('.aphome-slider').hover(function(){
		$('.apprev, .apnext').fadeIn();
	});
	$('.aphome-slider').mouseleave(function(){
		$('.apprev, .apnext').fadeOut();
	});
	$('.apprev, .apnext').hover(function(){
		$(this).css('opacity', '1')
	});
	$('.apprev, .apnext').mouseleave(function(){
		$(this).css('opacity', '1')
	});

	var aplen = $(".apbelt li").length;
	var aptWidth = $(".apbelt li").width();
	var apsWidth = aptWidth+15;
	var apfWidth = apsWidth * aplen;
	$(".apbelt").css('width', apfWidth)
	 var counter = 1;
	 if(counter == 1){
		 $('.apnav-area li a').removeClass('active')
		 $('.apnav-area li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 2){
		 $('.apnav-area li a').removeClass('active')
		 $('.apnav-area li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 3){
		 $('.apnav-area li a').removeClass('active')
		 $('.apnav-area li:nth-child(1) a').addClass('active');
	 }
	  //NEXT
	 $('.apnext').click(function(){
		 if(counter < aplen-4){
		   $('.apbelt').animate({'left' :'-=203'})
		   $('.apprev').fadeIn();
		   counter +=1;
		 }
		 else {
			 $('.apnext').fadeOut();
			 
		 }
	 });
	 
	 //PREV
	 $('.apprev').click(function(){
		 if(counter == 1){
		     $('.apprev').fadeOut();
			 
		 }else{
			 $('.apbelt').animate({'left' :'+=203'});
			 $('.apnext').fadeIn();
		     counter -=1;
		 }
	 });
	 
	 
	 //NAV
	 $('.apnav-area li a').click(function(){
		 $('.apnav-area li a').removeClass('active')
		 $(this).addClass('active');
	 });
    
});
/*chunk slider ends*/


/*chunk slider #2# start*/
$(document).ready(function(e) {
	$('.aphome-slider_two').hover(function(){
		$('.apprev_two, .apnext_two').fadeIn();
	});
	$('.aphome-slider_two').mouseleave(function(){
		$('.apprev_two, .apnext_two').fadeOut();
	});
	$('.apprev_two, .apnext_two').hover(function(){
		$(this).css('opacity', '1')
	});
	$('.apprev_two, .apnext_two').mouseleave(function(){
		$(this).css('opacity', '0.5')
	});

	var aplen = $(".apbelt_two li").length;
	var aptWidth = $(".apbelt_two li").width();
	var apsWidth = aptWidth+15;
	
	var apfWidth = apsWidth * aplen;
	$(".apbelt_two").css('width', apfWidth)
	 var counter = 1;
	 if(counter == 1){
		 $('.apnav-area_two li a').removeClass('active')
		 $('.apnav-area_two li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 2){
		 $('.apnav-area_two li a').removeClass('active')
		 $('.apnav-area_two li:nth-child(1) a').addClass('active');
	 }
	 if(counter == 3){
		 $('.apnav-area_two li a').removeClass('active')
		 $('.apnav-area_two li:nth-child(1) a').addClass('active');
	 }
	  //NEXT
	 $('.apnext_two').click(function(){
		 if(counter < aplen-4){
		   $('.apbelt_two').animate({'left' :'-=203'})
		   $('.apprev_two').fadeIn();
		   counter +=1;
		 }
		 else {
			 $('.apnext_two').fadeOut();
			 
		 }
	 });
	 
	 //PREV
	 $('.apprev_two').click(function(){
		 if(counter == 1){
		     $('.apprev_two').fadeOut();
			 
		 }else{
			 $('.apbelt_two').animate({'left' :'+=203'});
			 $('.apnext_two').fadeIn();
		     counter -=1;
		 }
	 });
	 
	 
	 //NAV
	 $('.apnav-area_two li a').click(function(){
		 $('.apnav-area_two li a').removeClass('active')
		 $(this).addClass('active');
	 });
    
});
/*chunk slider ends*/



/*chunk slider #3# start*/
$(document).ready(function(e) {
	$('.aphome-slider_three').hover(function(){
		$('.apprev_three, .apnext_three').fadeIn();
	});
	$('.aphome-slider_two').mouseleave(function(){
		$('.apprev_three, .apnext_three').fadeOut();
	});
	$('.apprev_three, .apnext_three').hover(function(){
		$(this).css('opacity', '1')
	});
	$('.apprev_three, .apnext_three').mouseleave(function(){
		$(this).css('opacity', '0.5')
	});

	var aplen = $(".apbelt_three li").length;
	var aptWidth = $(".apbelt_three li").outerWidth();
	//alert(aptWidth);
	var apsWidth = aptWidth;
	var apfWidth = apsWidth * aplen;
	$(".apbelt_three").css('width', apfWidth)
	 var counter = 1;
	 //if(counter == 1){
//		 $('.apnav-area_three li a').removeClass('active')
//		 $('.apnav-area_three li:nth-child(1) a').addClass('active');
//	 }
//	 if(counter == 2){
//		 $('.apnav-area_three li a').removeClass('active')
//		 $('.apnav-area_three li:nth-child(1) a').addClass('active');
//	 }
//	 if(counter == 3){
//		 $('.apnav-area_three li a').removeClass('active')
//		 $('.apnav-area_three li:nth-child(1) a').addClass('active');
//	 }
	  //NEXT
	 $('.apnext_three').click(function(){
		 if(counter < aplen-4){
		   $('.apbelt_three').animate({'left' :'-=171'})
		   $('.apprev_three').fadeIn();
		   counter +=1;
		 }
		 else {
			 $('.apnext_three').fadeOut();
			 
		 }
	 });
	 
	 //PREV
	 $('.apprev_three').click(function(){
		 if(counter == 1){
		     $('.apprev_three').fadeOut();
			 
		 }else{
			 $('.apbelt_three').animate({'left' :'+=171'});
			 $('.apnext_three').fadeIn();
		     counter -=1;
		 }
	 });
	 
	 
	 //NAV
	 $('.apnav-area_three li a').click(function(){
		 $('.apnav-area_three li a').removeClass('active')
		 $(this).addClass('active');
	 });
    
});
/*chunk slider  #3# ends*/



$(document).ready(function(e){
	$('.app-box').hover(function(){
		$(this).children('.layover').show();
	});
	$('.app-box').mouseleave(function(){
		$(this).children('.layover').hide();
	});
});


/*os icons start*/
$(document).ready(function(e) {
	$('.category').hover(function(){
		$(this).children('.cat').show();
	});
	$('.category').mouseleave(function(){
		$(this).children('.cat').hide();
	});
	
    $('.android').hover(function(){
		$(this).css('right','0px')
	});
	$('.android').mouseleave(function(){
		$(this).css('right','-67px')
	});
	$('.apple').hover(function(){
		$(this).css('right','0px')
	});
	$('.apple').mouseleave(function(){
		$(this).css('right','-67px')
	});
	$('.blackb').hover(function(){
		$(this).css('right','0px')
	});
	$('.blackb').mouseleave(function(){
		$(this).css('right','-67px')
	});
	$('.windows').hover(function(){
		$(this).css('right','0px')
	});
	$('.windows').mouseleave(function(){
		$(this).css('right','-67px')
	});
	$('.ovi').hover(function(){
		$(this).css('right','0px')
	});
	$('.ovi').mouseleave(function(){
		$(this).css('right','-67px')
	});
});
/*os icons end*/

$(document).ready(function(e) {
	$('#download').click(function(){
		$('.popup-mobile, .trans').show();
	});
	$('.mobile-close').click(function(){
		$('.popup-mobile, .trans').hide();
	});
    $('.android').click (function(){
		var dheight  = $(document).height();
		$('.popup').css('visibility', 'visible');
		$('.trans').show();
		$('.trans').height(dheight);
		
	});
	$('.apple').click (function(){
		var dheight  = $(document).height();
		$('.popup-ios').css('visibility', 'visible');
		$('.trans').show();
		$('.trans').height(dheight);
		
	});
	$('.blackb').click (function(){
		var dheight  = $(document).height();
		$('.popup-bb').css('visibility', 'visible');
		$('.trans').show();
		$('.trans').height(dheight);
		
	});
	$('.windows').click (function(){
		var dheight  = $(document).height();
		$('.popup-windows').css('visibility', 'visible');
		$('.trans').show();
		$('.trans').height(dheight);
		
	});
	
	$('.ovi').click (function(){
		var dheight  = $(document).height();
		$('.popup-ovi').css('visibility', 'visible');
		$('.trans').show();
		$('.trans').height(dheight);
		
	});
	
	$('.close, .close-ios, .close-bb, .close-windows, .close-ovi').click(function(){
		$('.popup, .popup-ios, .popup-bb, .popup-windows, .popup-ovi').css('visibility', 'hidden');
		$('.trans').hide();
	});
	
	var lenpopup = $(".belt-popup li").length;
	var tWidthpopup = $(".belt-popup li").width();
	var sWidthpopup = tWidthpopup+30;
	var fWidthpopup = sWidthpopup * lenpopup;
	$(".belt-popup").css('width', fWidthpopup);
	 var counter = 1;

	 
	 //NEXT
	 $('.next-popup').click(function(){
		
		 if(counter < lenpopup-3){
		   $('.belt-popup').animate({'left' :'-=174'})
		   $('.prev-popup').fadeIn();
		   
		   counter +=1;
		 }
		 else {
			 $('.next-popup').fadeOut();
			 
		 }
	 });
	 
	 //PREV
	 $('.prev-popup').click(function(){
		 if(counter == 1){
		     $('.prev-popup').fadeOut();
			 
		 }else{
			 $('.belt-popup').animate({'left' :'+=174'});
			 $('.next-popup').fadeIn();
		     counter -=1;
		 }
	 });
	 
	 //NAV
	 $('.nav-area li a').click(function(){
		 $('.nav-area li a').removeClass('active')
		 $(this).addClass('active');
	 });
		 
    
});

