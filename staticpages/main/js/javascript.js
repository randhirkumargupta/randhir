$(document).ready(function(e) {
		 $('.last').click(function(){
		$('#dr').fadeIn();
		$('#drr').fadeIn();

		
	});
	$('.last').mouseleave(function(){
		$('#dr').fadeOut();
		$('#drr').fadeOut();
	});
	
	
	$('.section').click(function(){
		$('#navigation').fadeIn();
	});
	
	$('.section').mouseleave(function(){
		$('#navigation').fadeOut();
	});
	
	 $('nav ul li').mouseenter(function(){
		$(this).find('div').fadeIn();
		$(this).find('a').addClass('wht');
$("nav ul li img[data-ak]").each(function(){
	   $(this).attr('src',$(this).attr('data-ak'));
	  });
		
	});
	$('nav ul li').mouseleave(function(){
		$(this).find('div').fadeOut();
		$(this).find('a').removeClass('wht');
		
	});
	
	//$('.searc-icon').click(function(){
		//$('#search-saction').slideToggle('slow');
	//});

       /* $('.share-story').mouseover(function(){
				$(this).children('ul').show();
				$(this).children('.share-icon').hide();
			})
		
		$('.share-story').mouseout(function(){
				$(this).children('ul').hide();
				$(this).children('.share-icon').show();
			})*/

		var len  = $('.top_right div').length;
		var counter = 0;
		$('#id1').show();
		for (i = 1 ; i<=len ; i++)
		{
			setInterval(function(){
				if (counter != 5)
					{
						$('#id1, #id2, #id3, #id4, #id5').hide();
						counter += 1;
						$('#id' + counter).fadeIn();
					}
					else
					{
						counter = 0;
					}
			},2000);
		}

		 $('.bclose').click(function(){
		$('.beaking_news').slideUp();
	});


	$('.last').click(function(){
		$('#dr').fadeIn();
		$('#drr').fadeIn();

		
	});
	$('.last').mouseleave(function(){
		$('#dr').fadeOut();
		$('#drr').fadeOut();
	});
	
	
	$('.section').click(function(){
		$('#navigation').fadeIn();
	});
	
	$('.section').mouseleave(function(){
		$('#navigation').fadeOut();
	});


	


	
	$('.app').hide();

	
	$(window).scroll(function () {
                    var height = $('body').height();
                    var scrollTop = $(window).scrollTop();
					
                      if(scrollTop > 100){
                          $('.menues').css({ 'position': 'fixed', 'top' : '0', 'width' : '100%', 'z-index' : '999999', 'border-bottom' : '1px solid rgb(136, 136, 136)', 'box-shadow':'0px 0px 5px rgb(0, 0, 0)'  });
						$('nav ul li.home-icon').css({'padding':'5px 5px 11px', 'background-position':'-344px -98px'});
						$('nav .searc-icon').css('width', '40px');
                        $('.app').show();
						  
						
                    }
                      else{
                         $('.menues').css({ 'position': 'relative', 'top': '0', 'box-shadow':'none'});
						   $('.app').hide();
						 $('nav ul li.home-icon').css({'padding':'5px 14px 11px', 'background-position':'-338px -98px'});
						$('nav .searc-icon').css('width', '45px');
													 
                       }

                });
    });
	



$(document).ready(function(e) {
 $('.section-btm').click(function(){
		$('.footerdrop').fadeIn();
		 
	});
	$('.section-btm').mouseleave(function(){
		$('.footerdrop').fadeOut();
	});
	
	 
	$('.searc-icon1').click(function(){
		$('#footer1').slideToggle('slow');
	});
});

setTimeout(function() {
    //$('#show').slideUp(300).fadeIn(100);
}, 800);

setTimeout(function() {
    $('#photooverlay').fadeIn(500);
}, 2200);
function divshow()
{
	$('#photooverlay').toggle();
}
$(document).ready(function(){
		$('.share-link').click(function(){
			$('.sharer_div').hide();
			$(this).next('.sharer_div').css({display:'block'});
		});
		$('.close').click(function(){
			$(this).parent('div').css({display:'none'});
		});
	});

function setVisibility(id, visibility) {
	document.getElementById(id).style.display = visibility;
}


$(document).ready(function() {
	$("#tab2").hide();
	$("#tab3").hide();
	$("#taba a").click(function(){
		$("#tab1").show().slideDown(300);
		$("#tab2").hide().slideUp(300);
		$("#tab3").hide().slideUp(300);
		$("#taba").removeClass("grey");
		$("#tabbb").addClass("grey");
		$("#tabb").addClass("grey");
	});
	
	$("#tabb a").click(function(){
		$("#tab2").show().slideDown(300);
		$("#tab1").hide().slideUp(300);
		$("#tab3").hide().slideUp(300);
		$("#tabbb").addClass("grey");
		$("#tabb").removeClass("grey");
		$("#taba").addClass("grey");
	});
	
	
	$("#tabbb a").click(function(){
		$("#tab2").hide().slideUp(300);
		$("#tab1").hide().slideUp(300);
		$("#tab3").show().slideDown(300);
		$("#tabbb").removeClass("grey");
		$("#tabb").addClass("grey");
		$("#taba").addClass("grey");
	});
	
	
});

function trim(field) {
	while(field.charAt(field.length-1)==" ") {
			field=field.substring(0,field.length-1);
	}
	while(field.charAt(0)==" ") {
		field=field.substring(1,field.length);
	}
	return field;
}

function handleHttpResponse3()
{
	if (http3.readyState == 4)
	{
		var results = http3.responseText;
		var contentArray = results.split('~'); 
		var categoryid = (contentArray[0]);
		var content=(contentArray[1]);
		if (http3.status == 200) {
			document.getElementById(categoryid).innerHTML = content;
			//runScripts(document.getElementById(categoryid));
		} else {                 
			//alert('There was a problem retrieving the data');
		} 
	}
}
function getHTTPObject()
{
	var xmlhttp;
	if(window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
	} else if (window.ActiveXObject) {
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
		if (!xmlhttp) {
			xmlhttp=new ActiveXObject("Msxml2.XMLHTTP");
		}
	}
	return xmlhttp;
}

var http3 = getHTTPObject();
function ajaxContentFetchPYC(categoryId,divColor,source)
{ 

	url="http://indiatoday.intoday.in/navigation_topnav_menu_ajax.jsp?id="+categoryId+"&color="+divColor;
//alert(url)
	http3.open("GET", url, true);
	http3.onreadystatechange = handleHttpResponse3;
	http3.send(null);
}
$('.bxslider').bxSlider({
	  mode: 'fade',
	  captions: true,
	  auto: true
	});
	$('.bxslider2').bxSlider({
	  mode: 'fade',
	  captions: true,
	});

	$(document).ready(function(e) {
	 $('.section-btm').click(function(){
			$('.footerdrop').fadeIn();
			 
		});
		$('.section-btm').mouseleave(function(){
			$('.footerdrop').fadeOut();
		});
		
	});
	$(function() {
		$(document).find("img[data-original]").lazyload({
		  threshold : 200,
	      failure_limit : 20 
	    });});	
$(document).ready(function(){
		$('.share-icon').click(function(){
			$('.share-icon').show();
			if(!$(this).next('ul').html().match('facebook')) {		
				contentURL = $(this).attr('url');
				contentTitle = $(this).attr('ctitle');
				var contenttotwrite = "<li><iframe class='frame' scrolling='no' frameborder='0' src='http://www.facebook.com/plugins/like.php?href=http://indiatoday.intoday.in/"+contentURL+"&amp;layout=button_count&amp;show_faces=true&amp;&amp;width=80&amp;action=like&amp;font&amp;colorscheme=light&amp;height=25' style='border:none; overflow:hidden; width:80px; height:25px;' allowtransparency='true'></iframe></li><li><iframe class='frame' scrolling='no' frameborder='0' allowtransparency='true' src='http://platform.twitter.com/widgets/tweet_button.1370380126.html#_=1370419460110&amp;count=horizontal&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http://indiatoday.intoday.in/"+contentURL+"%20via%20%40indiatoday%2F&amp;size=m&amp;text="+contentTitle+"&amp;url="+contentTitle+"%20http://indiatoday.intoday.in/"+contentURL+"%20via%20%40indiatoday' class='twitter-share-button twitter-count-horizontal' style='width: 100px; height: 25px;' title='Twitter Tweet Button' data-twttr-rendered='true'></iframe></li><li><iframe scrolling='no' class='frame' frameborder='0' src='https://apis.google.com/_/+1/fastbutton?bva&url=http://indiatoday.intoday.in/"+contentURL+"' style='border:none; overflow:hidden; width:100px; height:25px;' allowtransparency='true'></iframe></li>";
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




function redirectPage() {
				window.location.href = 'http://bttemp.intoday.in/index-slide.jsp';
				};
function redirectPage1() {
				window.location.href = 'http://10.10.25.243/dailyo2/';
				};				
				
$(document).ready(function() {
	$('#left-home').click(function(){
	   $('.skinnin-ad-container').animate({
				left: '+=2000px'
				}, 1500, function() {
					$('body').addClass('loader');
					redirectPage();
					//$('.dailyo-iframe').fadeIn('slow');
				});
	 });
	 
	 $('#right-home').click(function(){
	   $('.skinnin-ad-container').animate({
				left: '-=2000px'
				}, 1500, function() {
				$('body').addClass('loader');
					redirectPage1();
					//$('.dailyo-iframe').removeAttr('style').fadeIn('slow');
				});
	 });
	 
	 
});

$(document).ready(function(){
	var ty = setTimeout(function(){$('img').each(function(){
	if($(this).attr('src').match('0/blank.gif')) {
	$(this).remove();
	}
	});
	},3000);
	
	});


