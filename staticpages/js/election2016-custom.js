$(function(){
		$(".trigger ").click(function () {    
			var effect = 'slide';
			var options = { direction: 'right' };
			var duration = 700;
			$('#flickerthumbs').toggle(effect, options, duration);
			$(this).toggleClass("triggerActive");
		});
	});
$(document).ready(function(){
	$('.tabData').not(':first').hide();
	$('.electionStateListSec ul li').click(function(){
		var count = $(this).index();
		$(this).addClass('actives').siblings().removeClass('actives');
		$('.tabData:eq('+count+')').slideDown().siblings().slideUp();
	});
	
	
	
	
//============slider1 js=============	
try {
		var photo_ga_len = $('#election_result_gallery .belt_slide ul li').length;
		var photo_ga_width = $('#election_result_gallery .belt_slide ul li').width();
		
		
		//alert("Length: " + photo_ga_len + " Width1 "+ photo_ga_width); 
		var photo_ga_ulwidth = photo_ga_width * photo_ga_len;  
		$('#election_result_gallery .belt_slide ul').css('width', photo_ga_ulwidth);
		var photo_ga_counter = 0;

		$('.election_right_arrow').click(function(){
		//alert('asd' + photo_ga_counter);
		
			if (photo_ga_counter < photo_ga_len-3 )  
			{
				$('#election_result_gallery .belt_slide ul').animate({
					left : '-='+ photo_ga_width
				});
				
				photo_ga_counter+=1;
				$('.election_left_arrow').show();
			}
			
			else
			{
				$(this).hide();
			}
		});
		
		
		$('.election_left_arrow').click(function(){
			if (photo_ga_counter == 0 )
			{
				$(this).hide();
			}
			
			else
			{
				$('#election_result_gallery .belt_slide ul').animate({
					left : '+='+ photo_ga_width
				});
				
				photo_ga_counter-=1;
				$('.election_right_arrow').show();
			}
		});
}catch(e1)
{
alert("Issue " + e1);
}
//============slider2 js=============	
		var photo_ga_len1 = $('#election_result_gallery1 .belt_slide1 ul li').length;
		var photo_ga_width1 = $('#election_result_gallery1 .belt_slide1 ul li').width();
	
		
		//alert("Length: " + photo_ga_len + " Width1 "+ photo_ga_width); 
		var photo_ga_ulwidth1 = photo_ga_width1 * photo_ga_len1;  
		$('#election_result_gallery1 .belt_slide1 ul').css('width', photo_ga_ulwidth1);
		var photo_ga_counter2 = 0;

		$('.election_right_arrow1').click(function(){
		
			if (photo_ga_counter2 <= photo_ga_len1-4 )
			{
				$('#election_result_gallery1 .belt_slide1 ul').animate({
					left : '-='+ photo_ga_width1
				});
				
				photo_ga_counter2+=1;
				$('.election_left_arrow1').show();
			}
			
			else
			{
				$(this).hide();
			}
		});
		
		
		$('.election_left_arrow1').click(function(){
			if (photo_ga_counter2 == 0 )
			{
				$(this).hide();
			}
			
			else
			{
				$('#election_result_gallery1 .belt_slide1 ul').animate({
					left : '+='+ photo_ga_width1
				});
				
				photo_ga_counter2-=1;
				$('.election_right_arrow1').show();
			}
		});	
	
//============slider3 js=============	
		var photo_ga_len2 = $('#election_result_gallery2 .belt_slide2 ul li').length;
		var photo_ga_width2 = $('#election_result_gallery2 .belt_slide2 ul li').width();
		
		
		//alert("Length: " + photo_ga_len + " Width1 "+ photo_ga_width); 
		var photo_ga_ulwidth2 = photo_ga_width1 * photo_ga_len2;  
		$('#election_result_gallery2 .belt_slide2 ul').css('width', photo_ga_ulwidth2);
		var photo_ga_counter3 = 0;

		$('.election_right_arrow2').click(function(){
		
			if (photo_ga_counter3 <= photo_ga_len2-4 )
			{
				$('#election_result_gallery2 .belt_slide2 ul').animate({
					left : '-='+ photo_ga_width2
				});
				
				photo_ga_counter3+=1;
				$('.election_left_arrow2').show();
			}
			
			else
			{
				$(this).hide();
			}
		});
		
		
		$('.election_left_arrow2').click(function(){
			if (photo_ga_counter3 == 0 )
			{
				$(this).hide();
			}
			
			else
			{
				$('#election_result_gallery2 .belt_slide2 ul').animate({
					left : '+='+ photo_ga_width2
				});
				
				photo_ga_counter3-=1;
				$('.election_right_arrow2').show();
			}
		});	
//============slider4 js=============	
		var photo_ga_len3 = $('#election_result_gallery3 .belt_slide3 ul li').length;
		var photo_ga_width3 = $('#election_result_gallery3 .belt_slide3 ul li').width();
		
		
		//alert("Length: " + photo_ga_len + " Width1 "+ photo_ga_width); 
		var photo_ga_ulwidth3 = photo_ga_width3 * photo_ga_len3;  
		$('#election_result_gallery3 .belt_slide3 ul').css('width', photo_ga_ulwidth3);
		var photo_ga_counter4 = 0;

		$('.election_right_arrow3').click(function(){
		
			if (photo_ga_counter4 <= photo_ga_len3-4 )
			{
				$('#election_result_gallery3 .belt_slide3 ul').animate({
					left : '-='+ photo_ga_width3
				});
				
				photo_ga_counter4+=1;
				$('.election_left_arrow3').show();
			}
			
			else
			{
				$(this).hide();
			}
		});
		
		
		$('.election_left_arrow3').click(function(){
			if (photo_ga_counter4 == 0 )
			{
				$(this).hide();
			}
			
			else
			{
				$('#election_result_gallery3 .belt_slide3 ul').animate({
					left : '+='+ photo_ga_width3
				});
				
				photo_ga_counter4-=1;
				$('.election_right_arrow3').show();
			}
		});			
//============slider5 js=============	
    
		var photo_ga_len4 = $('#election_result_gallery4 .belt_slide4 ul li').length;
		var photo_ga_width4 = $('#election_result_gallery4 .belt_slide4 ul li').width();
		
		
		//alert("Length: " + photo_ga_len + " Width1 "+ photo_ga_width); 
		var photo_ga_ulwidth4 = photo_ga_width4 * photo_ga_len4;  
		$('#election_result_gallery4 .belt_slide4 ul').css('width', photo_ga_ulwidth4);
		var photo_ga_counter5 = 0;

		$('.election_right_arrow4').click(function(){
		
			if (photo_ga_counter5 <= photo_ga_len4-4)
			{
				$('#election_result_gallery4 .belt_slide4 ul').animate({
					left : '-='+ photo_ga_width4
				});
				
				photo_ga_counter5+=1;
				$('.election_left_arrow4').show();
			}
			
			else
			{
				$(this).hide();
			}
		});
		
		
		$('.election_left_arrow4').click(function(){
			if (photo_ga_counter5 == 0 )
			{
				$(this).hide();
			}
			
			else
			{
				$('#election_result_gallery4 .belt_slide4 ul').animate({
					left : '+='+ photo_ga_width4
				});
				
				photo_ga_counter5-=1;
				$('.election_right_arrow4').show();
			}
		});			
	
	
	
});