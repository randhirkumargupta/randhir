// JavaScript Document
$(document).ready(function(e) {
$('.search').click(function(){
		$('#search-saction').slideToggle('slow');
		return false;
	});
$('a.close_btn').click(function(){
	$(this).closest('div').hide();
	})
	
$('a.mobnav').click(function(){
	
	$(this).next().slideToggle('slow')
	
	})


});
(function($){
		$(window).load(function(){
			$("#sosorry_scroll").mCustomScrollbar({});
			$("#video_scroll").mCustomScrollbar({});
			$("#quotes_scroll").mCustomScrollbar({});			
		});
	})(jQuery);