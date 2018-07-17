// JavaScript Document

$(document).ready(function(){

	var v_len = $('.belt ul li').length;
	var v_wd = $('.belt ul li').width();
	var v_ulwd = v_wd * v_len;
	v_ulwd = v_ulwd+150;
	$('.belt ul').css('width', v_ulwd);
	v_wd = v_wd+30;
	
	var v_counter = 1;
	$('.v_left').click(function(){
		if (v_counter == 1)
		{
			$(this).hide();
		}else
		{
			$('.belt ul').animate({
				left : '+='+v_wd
			},1000);
			v_counter -=1;
			$('.v_right').show();
		}
	});
	
	$('.v_right').click(function(){
		if (v_counter <= v_len-2)
		{
			$('.belt ul').animate({
				left : '-='+v_wd
			},1000);
			v_counter +=1;
			$('.v_left').show();
		}else
		{
			$(this).hide();
		}
	});
});
