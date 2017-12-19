// menu navigation code with Ajax
var menu_arr = new Array();	
function getmenu(secid,catid,ctype,thiss){
		$(thiss).addClass('active')		
		$('.drop-box-left a').parent('li').removeClass('active');
		$(thiss).parent('li').addClass('active');
		
		var idd = 0;
		if(parseInt(secid)==0 && parseInt(secid)>0) {
			var type = 'cat';
			var idd = catid;
		} else if(parseInt(secid)>0) {
			var type = 'sec';
			var idd = secid;
		}
		if(parseInt(catid)==0 && parseInt(secid)>0) {
			var type = 'sec';
			var idd = secid;
		} else if(parseInt(catid)>0) {
			var type = 'cat';
			var idd = catid;
		}
		var tyyyy = $(thiss).parent('li').parent('ul').parent('div').next('div.drop-box-right');
		
		if(idd>0) {
			var arrkey = type+'_'+idd;
			if(menu_arr[arrkey]!=undefined && menu_arr[arrkey]!=null) {
				tyyyy.html(menu_arr[arrkey]);
				return;
			}
			
			tyyyy.html('<div class="load_data">LOADING....</div>');
			$.ajax({
				url:siteurl+'/navigation_topnav_menu_ajax_2015.jsp',
				type:'GET',
				data:'id='+idd+'&ctype='+ctype+'&type='+type,
				success:function(backdata){
						//alert(backdata);
						if(!backdata.match('Error')) {
							tyyyy.html(backdata);
							var arrkey = type+'_'+idd;
							menu_arr[arrkey] = backdata;
						} else {
							$(this).click();
						}
					},
				error:function(backdata){
						//alert(backdata);
						//alert('Please try again');
					}
			});
		}
	}
	
	//Auto home slider Function
	var box1_len = $('.catlist.active span').length;
	var btm_counter = 0;
	var btm_len = $('.btm_belt ul li').length;
    var btm_width = $('.btm_belt ul li').width();
 function auto(){
                        if (btm_counter >= btm_len-4){
							$('.btm_belt ul li.current_'+ btm_counter).removeClass('active');
							//alert(btm_counter);

							
						
							$('.btm_belt ul li').removeClass('active');
							
							//$('.btm_belt ul').animate({'left' :'0'});
							//$('.next').css('visibility', 'hidden');
							//btm_counter = 0;
							$('.catlist').removeClass('active').css({'display':'none'});
							$('.box'+ btm_counter).addClass('active').css({'display': 'block'});
							$('.btm_belt ul li.current_'+ btm_counter).addClass('active');
							//alert(btm_counter + "troe conditon")
							btm_counter += 1;
							}else
							{
							$('.btm_belt ul').animate({'left' :'-=100'})
							$('.btm_belt ul li').removeClass('active');
								$('.btm_right').hide();
							btm_counter += 1;
							//	alert(btm_counter + "false conditon")
							
							$('.catlist').removeClass('active').css({'display':'none'});
							$('.btm_left').show();
							//$('.btm_belt ul li').removeClass('active');
							$('.btm_belt ul li.current_'+ btm_counter).addClass('active')
							$('.box'+ btm_counter).addClass('active').css({'display': 'block'});
							//$('.next').css('visibility', 'visible');
							
							}							
							if (btm_counter > btm_len){
								btm_counter = 0;
							$('.btm_belt ul').animate({'left' :'0'});
							
							$('.btm_right').show();
							$('.btm_left').show();
							$('.box'+ btm_counter).addClass('active').css({'display': 'block'});
							$('.btm_belt ul li.current_'+ btm_counter).addClass('active');
							}
							
							
							
				   }	
	
$(document).ready(function(){
function sleep(milliseconds) {
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++) {
    if ((new Date().getTime() - start) > milliseconds){
      break;
    }
  }
   // alert("woke up!");
}
					   
sleep(10000);						   
setInterval (auto, 10000)					   
						   
});	
	
	
	
	
	
	
	
	
	
$(document).ready(function(){
						   
$('.trending_box_cont .see_more_btn').click(function(){
$(this).toggleClass('down_more_btn');
$('ul#moretraend0list').slideToggle(600);												
													
});

$('h1.section-heading').click(function(){
	$('#section-nav').slideToggle(600);										
})

$('.homeleft .see_more_btn').click(function(){
	 
$(this).toggleClass('down_more_btn');
$('#sectionlistmore').slideToggle(600);
					 
					 
});





	$('.top-menu > ul > li.news h1').click(function(){
		
		
													
		$('.sub_topnav').slideUp(300);
         $('a#menu').show();
        $('a#menuclose').hide();
		
		//$(this).addClass('active')
		$('.close').hide(200);
		//$('.top-menu > ul > li.news').removeClass('active');
		$(this).parent('li.news').addClass('active');
		//$('.top-menu > ul > li.news > ul').hide(10);
		$(this).next('div').next('ul').slideToggle(300);
		//$(this).next('div').next('ul').slideDown(300);		
		$(this).next('div.close').show(10);
		$('.drop-box-left a').parent('li').removeClass('active');
		if($(this).attr('class')!=null && $(this).attr('class').match('photo')) {
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(3)').addClass('active');
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(3)').children('a').click();
		} else {
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(0)').addClass('active');
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(0)').children('a').click();
		}
	});
	
	
	    $('.top-menu > ul > li.news > ul').mouseleave(function(){
		$(this).slideUp(300);
		$('.top-menu > ul > li.news').removeClass('active');
		})
	
	$('.top-menu > ul > li').mouseleave(function(){
		$(this).children('ul').slideUp(300);
	});
	
	
	
	$('.top-menu > ul > li.news a').click(function(){
		$('.sub_topnav').slideUp(300);
         $('a#menu').show();
        $('a#menuclose').hide();
		
		//$(this).addClass('active')
		$('.close').hide(200);
		//$('.top-menu > ul > li.news').removeClass('active');
		$(this).parent('li.news').addClass('active');
		//$('.top-menu > ul > li.news > ul').hide(10);
		$(this).next('div').next('ul').slideToggle(300);
		$(this).next('div.close').show(10);
		$('.drop-box-left a').parent('li').removeClass('active');
		if($(this).attr('class')!=null && $(this).attr('class').match('photo')) {
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(3)').addClass('active');
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(3)').children('a').click();
		} else {
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(0)').addClass('active');
			$(this).next('div').next('ul').children('li:eq(0)').children('div').children('ul').children('li:eq(0)').children('a').click();
		}
	});
	
	
	   // $('.top-menu > ul > li.news > ul').mouseleave(function(){
//		$(this).slideUp(300);
//		$('.top-menu > ul > li.news').removeClass('active');
//		})
//	
//	$('.top-menu > ul > li').mouseleave(function(){
//		$(this).children('ul').slideUp(300);
//	});
	
	
	
	if($(window).width() > 800){
$('.top-menu > ul > li.news > ul').mouseleave(function(){$(this).slideUp(300);$('.top-menu > ul > li.news').removeClass('active');})
$('.top-menu > ul > li').mouseleave(function(){$(this).children('ul').slideUp(300);});$('.closeslider h2').click(function(){$(this).parent('div').removeClass('closeslider');$(this).next('.slider-cover').slideDown(200);$(this).children('a').removeClass('not-active');})
}
	
	
	
	$('.belt-outer').children('.catlist:last').addClass('active').css({'display': 'block'});
			$('.belt-outer').children('.heading:last').addClass('active').css({'display': 'block'});
			  $('.btm_belt ul li').eq(0).addClass('active');
			  var boxnew_counter = 0;
			//var box1_len = $('.catlist.active span').length;

	          $('.btm_belt ul li').click(function(){ 
			
			  $('.slide-next').show();
				$('.slide-back').show();
			// box1_counter = 1;
			 $('.catlist').css('left', '0');		 
			  $('.btm_belt ul li').removeClass('active');
			     $(this).addClass('active'); 
               var index = $('.btm_belt ul li').index($(this));
			  $('.catlist').removeClass('active').css({'display':'none'});			   
			  $('.box'+ index).addClass('active').css({'display': 'block'});
			  
			  $('.heading').removeClass('active').css({'display':'none'});
			  $('.slider_heading' + index).addClass('active').css({'display': 'block'});;
			  
			 	  box1_len = $('.catlist.active span').length;
					var boxnew_widt = $('.catlist.active span').width();
					var boxnew_widt = boxnew_widt * box1_len;
					$('.catlist.active').css('width', boxnew_widt);
	});				
		       var box1_widt = $('.catlist.active span').width();
		       var box1_widt = box1_widt * box1_len;
			   $('.catlist.active').css('width', box1_widt);		
		       var box1_counter = 0;	
		$('.slide-next').click(function(){
		$('.slide-back').show();
			if (box1_counter < box1_len)
				{
				$('.catlist.active').animate({
					left :'-=605',
				})
			box1_counter += 1;
			
		}else
		{
			$('.slide-next').show();
		}
		});
		
		
		$('.slide-back').click(function(){
		$('.slide-next').show();
			if (box1_counter >= 2)
				{
				$('.catlist.active').animate({
					left :'+=605',
				})
			box1_counter -= 1;
		}else
		{
			$('.slide-back').show();
		}
		});
		
		//var btm_len = $('.btm_belt ul li').length;
		//var btm_width = $('.btm_belt ul li').width();

		btm_width = btm_width * btm_len+5;
		//$('.btm_belt ul').css('width', btm_width+5);
		var ul_left_margin = $('.btm_belt ul').css("left");
		//var btm_counter = 0;
		$('.btm_right').click(function(){
			$('.btm_left').show();
			
			ul_left_margin = $('.btm_belt ul').css("left").replace('px').trim();
			ul_left_margin = parseInt(ul_left_margin);
			if(ul_left_margin==0)
			{
				$('.btm_belt ul').animate({
					left :'-=100',
				});
				$('.btm_right').hide();
			}else {
				//$('.btm_right').hide();
			}
		});		
		
		
		$('.btm_left').click(function(){
			$('.btm_right').show();
			ul_left_margin = $('.btm_belt ul').css("left").replace('px').trim();
			ul_left_margin = parseInt(ul_left_margin);
			if (ul_left_margin< 0)
			{
				$('.btm_belt ul').animate({
					left :'+=100',
				})
				$('.btm_left').hide();
			}else
			{
				//$('.btm_left').hide();
			}
		});
		
		
		//Auto Scroll BIG Slider Code Start
		
		       // var btm_counter = 0;
               // setInterval (auto, 10000)
                  
							//auto();
		
		//setTimeout(function(){ 
							//auto(); 
							//alert('nnn');
							
						//	}, 90000);
		
		
		//Auto Scroll BIG Silder Code End
		
		//var value = 0;
//		$('.btm_belt ul li').each(function(){
//			value += 1;
//			$(this).addClass('current_'+ value);
//		})
	//$(".rightprtscrl").mCustomScrollbar({
//					axis:"x",
//					theme:"light-3",
//					advanced:{autoExpandHorizontalScroll:true}
//				});
//$('.content ul li:first-child').addClass('activethumb');
//
//$('.content ul li').click(function(){
//    $(this).parent('ul').children('li').removeClass('activethumb');
//    $(this).addClass('activethumb');	
//    for(var i=0;i<=15;i++){
//	$(this).parent('ul').parent('div').parent('div').parent('div').parent('div').parent('div.slider-cover').children('.content_area'+i).hide()}
//    $(this).parent('ul').parent('div').parent('div').parent('div').parent('div').parent('div.slider-cover').children('.content_are'+$(this).children('a').attr('rel')).show();
//    return false;
//  });				

/*$('.content ul li a').click(function(){
	
	$('.content ul li a span').show();
	$('.activethumb a span').hide();
	$(this).children('span').hide()
	
	$(this).parent('li').parent('ul').children('li:first-child').children('a').children('span').show()
});*/
	
// menu dropdown strat
$('li.navtog').click(function(){		 
		$(this).children('a#menu').hide();
	    $(this).children('a#menuclose').show();
		$('.sub_topnav').slideDown(300);
				
});
$('#navnext').click(function(){
		   $('.mainnavigation-slider ul').animate({top : '-=304'});
		   $(this).hide()
		   $('#navprev').show()
		})
$('#navprev').click(function(){
		   $('.mainnavigation-slider ul').animate({top : '+=304'});
		   $(this).hide()
		   $('#navnext').show()
		})

$('a#menuclose').click(function(){
		$('.sub_topnav').slideUp(300);
		$('a#menu').show();
	    $(this).hide();		
		return false;
});

// menu dropdown END
// Trending JS






//group link js
$('li.grouplinks a#menu_h').click(function() {
	$('.sub_topnav').slideUp(300);
    $('a#menu').show();
    $('a#menuclose').hide();									     
	$(this).parent('li.grouplinks').toggleClass('active')
	$('.right_t_menu').slideToggle(300);
});	


$('.right_t_menu').mouseleave(function(){
	$(this).slideUp(300);
	$('.top-menu li.grouplinks').removeClass('active');
});
});






// Key Player slider section 
$(document).ready(function() {
	var listshowlen  = $('.hotshowing #listhot .list-showing').length;
	var listshowidth = $('.hotshowing #listhot .list-showing').height();
	var showwidth = listshowlen*(listshowidth+3);
	$('.hotshowing #listhot').css('height', showwidth);
	var counters = 1;
	
	$('.rigthnext-arrow').click(function(){

		if(counters < listshowlen)
		{
				$('.hotshowing #listhot').animate({
					top : '-=186'
				});
				counters +=1;
				
				//$('#keyplayer-prev').css('opacity', '1');
		}
		else{
			//$('.rigthnext-arrow').css('display', 'none');
			$('.rigthpre-arrow').css('display', 'block');
		}
	});	
	
	$('.rigthpre-arrow').click(function(){
		if(counters == 1)
		{
				//$('.rigthpre-arrow').css('display', 'none');
				$('.rigthnext-arrow').css('display', 'block');
		}
		else{
			$('.hotshowing #listhot').animate({
					top : '+=186'
				});
			counters -= 1;
			//$('.rigthpre-arrow').css('display', 'none');
			//$('.rigthnext-arrow').css('display', 'block');
		}
	});
	});


// Anchors slider section 
$(document).ready(function() {
	var listshowlen  = $('.anchores #listanchores .list-showing').length;
	var listshowidth = $('.anchores #listanchores .list-showing').height();
	var showwidth = listshowlen*(listshowidth+3);
	$('.anchores #listhot').css('height', showwidth);
	var counters = 1;
	
	$('.rigthnext-arrow-anchors').click(function(){

		if(counters < listshowlen)
		{
				$('.anchores #listanchores').animate({
					top : '-=186'
				});
				counters +=1;
				
				//$('#keyplayer-prev').css('opacity', '1');
		}
		else{
			$('.rigthnext-arrow-anchors').css('display', 'none');
			$('.rigthpre-arrow-anchors').css('display', 'block');
			
		}
	});	
	
	$('.rigthpre-arrow-anchors').click(function(){
		if(counters == 1)
		{
				$('.rigthpre-arrow-anchors').css('display', 'none');
				$('.rigthnext-arrow-anchors').css('display', 'block');
		}
		else{
			$('.anchores #listanchores').animate({
					top : '+=186'
				});
			counters -= 1;
			//$('.rigthnext-arrow').css('opacity', '1');
		}
	});
	});

// news slider section 
$(document).ready(function() {
	var listshowlen  = $('.newsshowing #listnews > .list-showing').length;
	var listshowidth = $('.newsshowing #listnews > .list-showing').height();
	var showwidth = listshowlen*listshowidth;
	$('.newsshowing #listnews').css('height', showwidth);
	var counters = 1;
	
	$('.rigthnext-arrow-news').click(function(){

		if(counters < listshowlen)
		{
				$('.newsshowing #listnews').animate({
					top : '-=186'
				});
				counters +=1;
				
				//$('#keyplayer-prev').css('opacity', '1');
		}
		else{
			$('.rigthnext-arrow-news').css('display', 'none');
			$('.rigthpre-arrow-news').css('display', 'block');
			
		}
	});	
	
	$('.rigthpre-arrow-news').click(function(){
		if(counters == 1)
		{
				$('.rigthpre-arrow-news').css('display', 'none');
				$('.rigthnext-arrow-news').css('display', 'block');
		}
		else{
			$('.newsshowing #listnews').animate({
					top : '+=186'
				});
			counters -= 1;
			//$('.rigthnext-arrow').css('opacity', '1');
		}
	});
	});

// Big Story chunk 
// Anchors slider section 
$(document).ready(function() {
	var bigstorylen  = $('.story_thumb_container ul li').length;
	var bigstorywidth = $('.story_thumb_container ul li').height();
	var bigstoryfinal = bigstorylen*bigstorywidth;
	$('.story_thumb_container ul').css('height', bigstoryfinal);
	var bigstoycounters = 1;
	if(bigstoycounters > 3){ $('.bidstory-navslider').hide()};
	
	
	$('#next-bigstory').click(function(){

		if(bigstoycounters < bigstorylen-2)
		{
				$('.story_thumb_container ul').animate({
					top : '-=78'
				});
				bigstoycounters +=1;
				
				$('#prev-bigstory').css('opacity', '1');
		}
		else{
			$('#next-bigstory').css('opacity', '0.5');
			//$('#prev-bigstory').css('display', 'block');
			
		}
	});	
	
	$('#prev-bigstory').click(function(){
									   //alert('prev');
		if(bigstoycounters == 1)
		{
				$('#prev-bigstory').css('opacity', '0.5');
				//$('#next-bigstory').css('display', 'block');
		}
		else{
			$('.story_thumb_container ul').animate({
					top : '+=78'
				});
			bigstoycounters -= 1;
			$('#next-bigstory').css('opacity', '1');
		}
	});
	});

// Big story chunk end

// Photo slider section 
$(document).ready(function() {
	var photolen  = $('.photo-slider .photobelt .photo-list').length;
	var photolistwidth = $('.photo-slider .photobelt .photo-list').width();
	var photowidth = photolen*(photolistwidth+3);
	$('.photo-slider .photobelt').css('width', photowidth);
	var photocounters = 1;
	
	$('#photonext').click(function(){

		if(photocounters < photolen)
		{
				$('.photo-slider .photobelt').animate({
					left : '-=308'
				});
				photocounters +=1;
				
				$('#photoprev').css('display', 'block');
		}
		else{
			$('#photonext').css('display', 'none');
			
		}
	});	
	
	$('#photoprev').click(function(){
		if(photocounters == 1)
		{
				//$('#photoprev').css('display', 'none');
				$('#photonext').css('display', 'block');
		}
		else{
			$('.photo-slider .photobelt').animate({
					left : '+=308'
				});
			photocounters -= 1;
			//$('.rigthpre-arrow').css('display', 'none');
			
		}
	});
	});




// Photo slider homepage for ipad section 
$(document).ready(function() {
	var photolen  = $('#photoipad ul li').length;
	var photolistwidth = $('#photoipad ul li').width();
	var photowidth = photolen*photolistwidth;
	$('#photoipad ul').css('width', photowidth);
	var photocountersipad = 1;
	
	$('#ipadphoto-next').click(function(){

		if(photocountersipad < photolen)
		{
				$('#photoipad ul').animate({
					left : '-='+photolistwidth
				});
				photocountersipad +=1;
				
				$('#ipadphoto-prev').css('display', 'block');
		}
		else{
			$('#ipadphoto-next').css('display', 'none');
			
		}
	});	
	
	$('#ipadphoto-prev').click(function(){
		if(photocountersipad == 1)
		{
				//$('#photoprev').css('display', 'none');
				$('#ipadphoto-prev').css('display', 'none');
				$('#ipadphoto-next').css('display', 'block');
		}
		else{
			$('#photoipad ul').animate({
					left : '+='+photolistwidth
				});
			photocountersipad -= 1;
			$('#ipadphoto-next').css('display', 'none');
			//$('#ipadphoto-next').css('display', 'block');
			
		}
	});
	});



















// Show slider section 
$(document).ready(function() {
	var listshowlen  = $('.hotshow #listshow .list-show').length;
	var listshowidth = $('.hotshow #listshow .list-show').height();
	var showwidth = listshowlen*listshowidth;
	$('.hotshow #listshow').css('height', showwidth);
	var counters = 1;
	
	$('.show-showmore a#progdown').click(function(){

		if(counters < listshowlen-1)
		{
				$('.hotshow #listshow').animate({
					top : '-=249'
				});
				counters +=1;
				
				$('.show-showmore a#progup').css('opacity', '1');
		}
		else{
			$('.show-showmore a#progdown').css('opacity', '0.5');
			//$('.show-showmore a#progup').css('display', 'block');
			
		}
	});	
	
	$('.show-showmore a#progup').click(function(){
		if(counters == 1)
		{
				$('.show-showmore a#progup').css('opacity', '0.5');
				//$('.show-showmore a#progdown').css('display', 'block');
		}
		else{
			$('.hotshow #listshow').animate({
					top : '+=249'
				});
			counters -= 1;
			$('.show-showmore a#progdown').css('opacity', '1');
		}
	});
	
	});


// News Tiker Javascript 

	
$(document).ready(function(e) {
 //$('#topnext01').hide();
	var len = $(".story-listall li").length;
	var tHidth = $(".story-listall li").height();	
	var sWidth = tHidth;
	var fWidth = sWidth * len;
	//$(".story-listall li").css('height', fWidth)
	 var counter = 1;
	 //NEXT
	 $('#topprev01').click(function(){
		//alert('next');
		 if(counter < len){
		   $('.story-listall').animate({'top' :'-=368'})		   
		   counter +=1;
		     $('#topprev01').css('opacity','0.5');
			 $('#topnext01').css('opacity','1');
		 }
		 else{
		 }
	 });
	 //PREV
	 $('#topnext01').click(function(){
		 if(counter == 1){
		 }else{$('#topprev01').css('opacity','1');
			   $('#topnext01').css('opacity','0.5');
			 $('.story-listall').animate({'top' :'+=368'});
		     counter -=1;
		 }
	 });

	
	 
});


$(document).ready(function(e) {
 //$('#topnext01').hide();
	var lenS = $("#sectionpage .story-listall li").length;

	var tHidthS = $("#sectionpage .story-listall li").height();	
	var sWidth = tHidthS;
	var fWidth = sWidth * lenS;
	//$(".story-listall li").css('height', fWidth)
	 var counterS = 1;
	 //NEXT
	 $('#sectionpage #sectopprev01').click(function(){
		//alert('next');
		 if(counterS < lenS-10){
		   $('.story-listall').animate({'top' :'-=308'})		   
		   counterS +=1;
		     $('#sectionpage #sectopprev01').css('opacity','0.5');
			 $('#sectionpage #sectopnext01').css('opacity','1');
		 }
		 else{

		 }
	 });
	 //PREV
	 $('#sectionpage #sectopnext01').click(function(){
		 if(counterS == 1){
			 
			 
			 
		 }else{$('#sectionpage #sectopprev01').css('opacity','1');
			   $('#sectionpage #sectopnext01').css('opacity','0.5');
			 $('.story-listall').animate({'top' :'+=308'});
		     counterS -=1;
		 }
	 });

	$('#scrolltop').click(function(){
$('html, body').animate({scrollTop: 0}, 1000);
});
	 
});







var num = 150; //number of pixels before modifying styles


//alert(footerlap);


$(window).bind('scroll', function () {
    if ($(window).scrollTop() > num) {
        $('.nav_bar').addClass('navfixed');
    } else {
        $('.nav_bar').removeClass('navfixed');
    }
});







$(document).ready(function(){
						   
var scrolltop = 400;
$(window).bind('scroll', function () {
    if ($(window).scrollTop() > scrolltop) {
        $('#scrolltop').css('opacity','1');
    } else {
        $('#scrolltop').css('opacity','0');
    }
});
						   
						   

var footerlap = $(document).height()- $(window).height()-500;
$(window).bind('scroll', function () {
    if ($(window).scrollTop() > footerlap) {
		$('#scrolltop').css('opacity','0');
    } 
});

						   
});



// Right Panel Fixed Jquery

/*$(document).ready(function(){
			var window_wid = $(window).width();
			var window_ht = $(window).height();
			var outer_wid = $('.wrapper').width();
			var right_set = window_wid - outer_wid;
			var right_ht = $('#rightpanel').height();
			var leftpart_ht = $('#leftpart').height();
			//alert(leftpart_ht);
			var top_fixed = right_ht - window_ht;
			top_fixed = top_fixed*-1;
			//var breaknews = $('#breakingnews').height();
			var breaknews = 510;
			//alert(breaknews);

			var top_fixedleftpart = leftpart_ht - window_ht;
			top_fixedleftpart = top_fixedleftpart - breaknews;
			top_fixedleftpart = top_fixedleftpart*-1;
			
			
			var left_ht = $('#leftpanel').height();
			var totao_doc = $(document).height();
			var newtotao_doc = $(document).height();
			//alert(totao_doc);
			var footer_ht = $('#footerpanel').height();
			//alert(footer_ht);
			totao_doc = totao_doc - footer_ht-380;
			newtotao_doc = newtotao_doc - footer_ht-380;
			
			
			//var ft_height = 400;
			right_set = right_set/2;

			
			$(window).scroll(function(){
				var toplocation = $(window).scrollTop();
				//toplocation = toplocation-breaknews;

				if (toplocation > window_ht && toplocation < (newtotao_doc -window_ht) )
				{
					$('#leftpart').addClass('left_fixed');					
					$('#leftpart').css('left', right_set);
					//$('#leftpart').css('top', top_fixedleftpart);
				} else if (toplocation >= (newtotao_doc-window_ht) )
				{	
					//alert('nn')
					$('#leftpart').removeClass('left_fixed');
				} else if(toplocation <=window_ht) {
					$('#leftpart').removeClass('left_fixed');
				}
				
				
			});
			
			$(window).scroll(function(){
				var toplocation = $(window).scrollTop();
				if (toplocation > window_ht && toplocation < (totao_doc -window_ht) )
				{
					$('#rightpanel').addClass('right_fixed');					
					$('#rightpanel').css('right', right_set);
					$('#rightpanel').css('top', top_fixed);
				} else if (toplocation >= (totao_doc-window_ht) )
				{	
					//alert('nn')
					$('#rightpanel').removeClass('right_fixed');
				} else if(toplocation <=window_ht) {
					$('#rightpanel').removeClass('right_fixed');
				}
				
				
			})
			
});
*/

//if ($(window).width() > 800)
//{
//	var toppanel = '';
// $(document).ready(function(){
//							
//			var window_wid = $(window).width();
//			var window_ht = $(window).height();
//			var outer_wid = $('.wrapper').width();
//			var right_set = window_wid - outer_wid;
//			var right_ht = $('#rightpanel').height();	
//			var right_set = window_wid - outer_wid;
//			
//			
//			right_set = right_set/2;
//			var right_part = $('#rightpart').height();
//			
//			var totao_doc = $(document).height();
//			var footer_ht = $('#footerpanel').height();
//
//			totao_doc = totao_doc - footer_ht;
//			var top_rightpanel = 472+right_ht;
//			toppanel = $('#toppanel').height();
//	
//	
//	$(window).scroll(function(){
//			var toplocation = $(window).scrollTop();			
//              
//				if ( (toplocation) >= ($(document).height() - window_ht-1100)  )
//				{					
//					$('#rightpanel').attr('style',$('#rightpanel').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'-10px',right:'0px'});
//					$('#leftpart').attr('style',$('#leftpart').attr('style').replace('top:','bottom:')).css({position:'absolute',bottom:'13px',left:'0px'});
//					//$('.logo').html("firdt---"+toplocation +'>'+ ($(document).height() - window_ht-900));
//				} else  {
//					 if(toplocation<=(toppanel+right_ht-window_ht)) {
//						$('#rightpanel').css({position:'absolute',top:'1px',right:'0px'});
//						$('#leftpart').css({position:'absolute',top:'525px',left:'0px'});
//						//$('.logo').html("thrdr---"+toplocation +'>'+ ($(document).height() - window_ht-900));
//					 } else if ( (toplocation) >= (toppanel+right_ht-window_ht) ) {
//						
//						$('#rightpanel').css('position', 'fixed');
//						//$('#rightpanel').css('overflow', 'hidden');
//						$('#rightpanel,#leftpart').css('right', right_set);
//						$('#rightpanel').css('left', right_set);
//						$('#leftpart').css('top', '0px!Important');
//						
//						//$('.logo').html("sec---"+toplocation +'>'+ (top_rightpanel - window_ht));
//					}
//				}
//				
//				
//				
//				
//				
//			});
//});
//}



 $(document).ready(function(){
		$('.share-icon').click(function(){
			$('.share-icon').show();
			if(!$(this).next('ul').html().match('facebook')) {		
				contentURL = $(this).attr('url');
				
				if(!contentURL.match('http')) {
					contentURL = 'http://indiatoday.intoday.in/'+contentURL;
				}
				
				contentTitle = $(this).attr('ctitle');
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href="+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=84&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:84px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer="+contentURL+"&amp;size=m&amp;text="+escape(contentTitle)+"%20-%20India%20Today&amp;url="+contentURL+"&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url="+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
				var thisss = $(this);	
				$('.open').css({display:'none'});	
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'}).html(contenttotwrite);
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			} else {
				var thisss = $(this);	
				$('.share-story ul').css({display:'none'});	
				$(this).css({display:'none'}).next('ul,ul li,.frame').css({display:'block'});
				$(this).next('ul,ul li,.frame').mouseleave(function(){thisss.css({display:'block'});$('.share-story ul').css({display:'none'}); });
			}
		});
	});


<!--
function popup(mylink, windowname)
{
if (! window.focus)return true;
var href;
if (typeof(mylink) == 'string')
   href=mylink;
else
   href=mylink.href;
window.open(href, windowname, 'width=400,height=200,scrollbars=yes');
return false;
}
//-->

$(document).ready(function(){
	$('.adt_s').click(function(){		
		$(this).toggleClass('lesssocial');
		$('#more_social').fadeToggle('fast');					   
	});					   
});

$(document).ready(function(){
	
	$('.mediumcontent p a').mouseenter( function(){
		$(this).children('img').show();
		
	});
	
	$('.mediumcontent p a').mouseleave( function(){
		$(this).children('img').hide();
	});


	
});


var sec_counter = 0;
function sectionslider(){
	  // alert(sec_counter);
	    $('.alpha > .left-column1').css('display','none');
		$('.thumb ul li').removeClass('active');
		$('.thumb ul li').eq(sec_counter).addClass('active');
		$('.alpha > .left-column1').eq(sec_counter).css('display','block');
	    sec_counter +=1;
		
		if(sec_counter > 3){		
		sec_counter = 0;		
     }
	}


$(document).ready(function(e) {
	$('.thumb ul li').eq(0).addClass('active');						   
	setInterval (sectionslider, 10000)
	
        //$('.alpha > .left-column1').css('display','none');
//		$('.alpha > .left-column1').eq(0).css('display','block');
//		
//		var len = $('.alpha  > div.left-column1').length;
//		var wd = $('.alpha  > div.left-column1').height();
//		wd= wd+5;
		
		
	$('.thumb ul li').click(function(){
		var current = $(this).index();
		sec_counter = current;
		$('.thumb ul li').removeClass('active');
		$(this).addClass('active');
		$('.alpha > .left-column1').css('display','none');
		$('.alpha > .left-column1').eq(sec_counter).css('display','block');
	
	if(sec_counter > 3){		
		sec_counter = 0;		
     }
		
	//	switch(current){
//			case 0 :{
//				$(".alpha").animate({top:0});
//				counter = 1;
//				}
//				 break;
//				
//			case 1 :{
//				$(".alpha").animate({top: -wd*1});
//				counter = 2;
//				}
//				 break;
//			case 2 :{
//				$(".alpha").animate({top: -wd*2});
//				counter = 3;
//				}
//			   break;			
//			   
//			 case 3 :{
//				$(".alpha").animate({top: -wd*3});
//				counter = 4;
//				}
//			   break;			
//			 
//			 case 4 :{
//				$(".alpha").animate({top:-wd*4});
//				counter = 5;
//				}
//		}
		
	});
	
						   });



$(document).ready(function(){
						   
$('#topstories').click(function(){
	$('#top_story_cont').show();
	$('#mail_today_cont').hide();
	$('#breaking > .arr_down').css({'display':'none'});
	$('#topstories > .arr_down').css({'display':'inline-block'});
	$('#topstories').addClass('active');
	$('#breaking').removeClass('active');
	});
	
	$('#breaking').click(function(){
								  //alert('breaking news');
	$('#top_story_cont').hide();
	$('#mail_today_cont').show();
	$('#topstories').removeClass('active');
	$('#breaking > .arr_down').css({'display':'inline-block'});
	$('#topstories > .arr_down').css({'display':'none'});
	$('#breaking').addClass('active');
	});						   
						   
});



$(document).ready(function(){
  var relstorylg = $('.relatestory-container > .strinnerbox').length;
 // alert(relstorylg);
  if( relstorylg > 3){
   $('.relatestory-container').css('height', '595px');
   $(".relatestory-container").mCustomScrollbar({
			horizontalScroll: false,
            autoDraggerLength: true,
            autoHideScrollbar: true,
            advanced:{
                autoScrollOnFocus: false,
                updateOnContentResize: true,
                updateOnBrowserResize: true
            }
							   
});	
  }
 
});


$(document).ready(function(){

if($(window).width() < 800){
	
	
	var footerlen  = $('.footer_lnk_m .ft_lnks_h').length;
	var footerwidth = $('.footer_lnk_m .ft_lnks_h').width();
	var footerwidth = footerlen*(footerwidth+6);
	$('.footer_lnk_m').css('width', footerwidth);
	
	//alert(footerlen);
	
	var footercountersipad = 1;
	
	$('#footernext').click(function(){

		if(footercountersipad < footerlen-4)
		{
				$('.footer_lnk_m').animate({
					left : '-=144'
				});
				footercountersipad +=1;
				
				$('#footerprev').css('display', 'block');
		}
		else{
			$('#footernext').css('display', 'none');
			
		}
	});	
	
	$('#footerprev').click(function(){
		if(footercountersipad == 1)
		{
				//$('#photoprev').css('display', 'none');
				$('#footerprev').css('display', 'none');
				$('#footernext').css('display', 'block');
		}
		else{
			$('.footer_lnk_m').animate({
					left : '+=144'
				});
			footercountersipad -= 1;
			$('#footernext').css('display', 'none');
			//$('#ipadphoto-next').css('display', 'block');
			
		}
	});

	}	  
			  
});


$(document).ready(function(){
	if($(window).width() > 800){
	$(".top-menu > ul > li.news > ul").mouseleave(function() {
        $(this).slideUp(300), $(".top-menu > ul > li.news").removeClass("active")
    });
	$(".top-menu > ul > li").mouseleave(function() {
        $(this).children("ul").slideUp(300)
    });
	
	}

$("#vd2").on('click',function(){$("#vd1").show(1000);
$("#vd2").hide(1000);});
$(".storyimgclose").on('click',function(){$("#vd1").hide(1000);$("#vd2").show(1000);})


	});


$(document).ready(function() {
    $(".tabs a").click(function(event) {
        event.preventDefault();
        $(this).parent().addClass("active");
        $(this).parent().siblings().removeClass("active");
        var tab = $(this).attr("href");
        $(".tabcontent").not(tab).css("display", "none");
        $(tab).fadeIn(300);
    });
});


