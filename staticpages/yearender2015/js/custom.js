/* list slider Records */
$(document).ready(function(e) {
	$('#topnext').fadeOut();
	var len = $(".story-listall li").length;
	var tHidth = $(".story-listall li").height();	
	var sWidth = tHidth;
	var fWidth = sWidth * len;
	//alert(tHidth)
	
	//alert(sWidth)	
	$(".story-listall").css('height', fWidth)
	 var counter = 1;
	  
	 //NEXT
	 $('#topprev').click(function(){
		//alert('next');
		 if(counter < len-4){
		   $('.story-listall').animate({'top' :'-=70'})		   
		   counter +=1;
		 }
		 else{
			 $('#topprev').fadeOut();
			 $('#topnext').fadeIn();
		 }
	 });
	 
	 //PREV
	 $('#topnext').click(function(){
		 if(counter == 1){
		     $('#topprev').fadeIn();
			 $('#topnext').fadeOut();
			 
		 }else{
			 $('.story-listall').animate({'top' :'+=70'});
		     counter -=1;
		 }
	 });
	 
	 $('#ceo-search').click(function(){
		$('#searchform').slideToggle('slow');
	});
});

$(document).ready(function(e) {
						   
	 $('#search').click(function(){
		$('#search_panel').slideToggle('slow');
	});					   
						   
    var photolentop  = $('.belt-mainbanner ul li').length;
	var twidthtop = $('.belt-mainbanner ul li').width();
	var fwidthtop = (twidthtop+50)*photolentop;
	$('.belt-mainbanner ul').css('width', fwidthtop);
	var counters = 1;
	
	$('#next').click(function(){

		if(counters < photolentop)
		{
				$('.belt-mainbanner ul').animate({
					left : '-=658'
				});
				 counters += 1;
				
				$('#prev').css('opacity', '1');
		}
		else{
			$('#next').css('opacity', '0.5');
			
		}
	});	
	
	$('#prev').click(function(){
		if(counters == 1)
		{
				$('#prev').css('opacity', '0.5');
		}
		else{
			$('.belt-mainbanner ul').animate({
					left : '+=658'
				});
			counters -= 1;
			$('#next').css('opacity', '1');
		}
	});
	
	// Dont Miss slider section 
	
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
	
	
	/*home slider start*/
$(document).ready(function(e) {
	var len = $(".photoslider ul li").length;
	var tWidth = $(".photoslider ul li").width();
	var fWidth = tWidth * len;
	$(".photoslider ul").css('width', fWidth+15)
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
			 $('.photoslider ul').animate({'left' :'0'});
			 //$('.prev').fadeOut();
			 //$('.next').fadeIn();
			 counter = 1;
		 }
		 if(currentli == 1){
			 $('.photoslider ul').animate({'left' :'-305'});
			 counter = 2;
			// $('.next , .prev').fadeIn();
		 }
		 if(currentli == 2){
			 $('.photoslider ul').animate({'left' :'-610'});
			// $('.next').fadeOut();
			// $('.prev').fadeIn();
			 counter = 3;
		 }
		 
		 
	 });  
    
});
	
});


$(document).ready(function(){
	$('.belt-mainbanner ul li').mouseenter(function(){
		$(this).children('.caption').addClass('active');
		//$(this).children('.caption').children('.share-story').show();
		$(this).children('.caption').stop().animate({
			height : '75'					  
		 })									 
	});
	
	$('.belt-mainbanner ul li').mouseleave(function(){
		$(this).children('.caption').removeClass('active');
		//$(this).children('.caption').children('.share-story').hide();
		$(this).children('.caption').stop().animate({
			height : '25'					  
		 })									 
	});
});



