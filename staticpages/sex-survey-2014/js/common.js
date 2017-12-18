// JavaScript Document

$(document).ready(function(){
		$('.share-icon').click(function(){
			$('.share-icon').show();
			if(!$(this).next('ul').html().match('facebook')) {		
				contentURL = $(this).attr('url');
				contentTitle = $(this).attr('ctitle');
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=http://indiatoday.intoday.in/"+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=80&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:80px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1346833764.html#_=1346847881207&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http://indiatoday.intoday.in/"+contentURL+"&amp;size=m&amp;text="+escape(contentTitle)+"%20-%20India%20Today&amp;url=http://indiatoday.intoday.in/"+contentURL+"&amp;via=indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 20px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=http://indiatoday.intoday.in/"+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
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




/*photographs*/

$(document).ready(function(e) {
	var len = $(".previous-yearslider ul li").length;
	var tWidth = $(".previous-yearslider ul li").width();
	var tpWidth = tWidth+15;
	var fWidth = tpWidth * len;
	$(".previous-yearslider ul").css({'width': fWidth, 'left': '0px'});
	 var counter = 1;
	 //NEXT
	 $('#next').click(function(){		
		 if(counter < len-2){
		   $('.previous-yearslider ul').animate({'left' :'-=201'})
		   $('#pre').fadeIn();
		   counter +=1;
		 }
		 else{
			 $('#next').fadeOut();			 
		 }
	 });
	 
	 //PREV
	 $('#pre').click(function(){
		 if(counter == 1){
		     $('#pre').fadeOut();
			 
		 }else{
			 $('.previous-yearslider ul').animate({'left' :'+=201'});
			 $('#next').fadeIn();
		     counter -=1;
		 }
	 });
    
});
