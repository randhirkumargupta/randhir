$(document).ready(function(e) {

var swiper = new Swiper('.swiper-container#sponsor_striph', {
	preventClicks: false,
	preventClicksPropagation:false,
	paginationClickable:true, 
	slidesPerView: 'auto',
	spaceBetween: 40,
	pagination: '.swiper-container#sponsor_striph .swiper-pagination',
	nextButton: '.swiper-container#sponsor_striph .swiper-button-next',
	prevButton: '.swiper-container#sponsor_striph .swiper-button-prev'
});	

var swiper = new Swiper('#quoteMain .swiper-container', {
	pagination: '#quoteMain .swiper-pagination',
	paginationClickable: true,
	nextButton: '#quoteMain .swiper-button-next',
	prevButton: '#quoteMain .swiper-button-prev',
	spaceBetween: 30
});


$('img[usemap]').rwdImageMaps();
	$('area').on('click', function() {
});


});



$(document).ready(function(){


   var moretext = "More[+]";
    var lesstext = "Less[-]";
  $(".more_less").click(function(){
        if($(this).hasClass("more")) {
			
            $(this).removeClass("more");
            $(this).html(lesstext);
			$('.about_the_lallantop .cont_lt p,.speaker_box_cont p').css('display','block');
			
			
        } else {
			   $(this).addClass("more");
            $(this).html(moretext);
			$('.about_the_lallantop .cont_lt p,.speaker_box_cont p').css('display','none');	
			$('.about_the_lallantop .cont_lt p,.speaker_box_cont p').first().css('display','inline');

         
        }
    });
			
$(".flashBtnLink").click(function(){
	
	$(".subMenu").slideToggle("fast");
});
	   
})

$(document).ready(function() {
	$('.nav-bar-toggle').click(function(){
		$('ul#subnav').slideToggle();
		})
})

$(document).ready(function() {
	$('.expanderdown').click(function(){ 
		$(this).hide();
		$(this).parent().next().slideDown();
		})
		$('.expanderup').click(function(){ 
		$('.expanderdown').show()
		$(this).parent().slideUp();
		})
});

$(document).ready(function(){
		$('#subnav li').mouseenter(function(){
			$(this).children('ul').fadeIn();
		});
		
		$('#subnav li').mouseleave(function(){
			$(this).children('ul').fadeOut();
		});
	});



