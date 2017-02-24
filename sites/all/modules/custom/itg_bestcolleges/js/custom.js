
jQuery(document).ready(function($) {
    $('.list').click(function(event){event.preventDefault();$('.item').addClass('list-group-item');});
    $('.grid').click(function(event){event.preventDefault();$('.item').removeClass('list-group-item');$('.item').addClass('grid-group-item');});

	$(".list").click(function(){
	 $('.grid').removeClass("active_btn");
	 $(this).addClass("active_btn");

		});

		$(".grid").click(function(){
	 $('.list').removeClass("active_btn");
	 $(this).addClass("active_btn");

		});



});
