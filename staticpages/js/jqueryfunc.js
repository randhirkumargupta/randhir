$(document).ready(function() {
	var wd= $(window).width();
	if (wd >= 1250)
	{
		$(".leftAd").css("display", "block"); 
		$(".rightAd").css("display", "block");
	}
});
$(document).ready(function(){setTimeout(function(){$('#loading').hide();$('#loading2').hide();$('#loading3').hide();$('#loading4').hide();$('#content').fadeIn();$('#content2').fadeIn();$('#content3').fadeIn();$('#content4').fadeIn();},1000);})
$("#toogle_arrow").click(function(){$("#browseitmorelinks").fadeToggle("slow");if($(this).find("img").attr("src")=='images/toogle_arrow.jpg')
{$(this).find('img').attr({src:'images/toogle_arrow_down.jpg'});}
else{$(this).find('img').attr({src:'images/toogle_arrow.jpg'});}});$(".breakclose").click(function(){$("#breaking").fadeToggle("slow");});$(function(){$("#example-one").organicTabs();$("#example-two").organicTabs();$("#example-three").organicTabs();$("#example-four").organicTabs();});(function($){$.organicTabs=function(el,options){var base=this;base.$el=$(el);base.$nav=base.$el.find(".tabnav");base.init=function(){base.options=$.extend({},$.organicTabs.defaultOptions,options);$(".hide").css({"position":"relative","top":0,"left":0,"display":"none"});base.$nav.delegate("div > a","click",function(){var curList=base.$el.find("a.current").attr("href").substring(1),$newList=$(this),listID=$newList.attr("href").substring(1),$allListWrap=base.$el.find(".list-wrap"),curListHeight=$allListWrap.height();$allListWrap.height(curListHeight);if((listID!=curList)&&(base.$el.find(":animated").length==0)){base.$el.find("#"+curList).fadeOut(base.options.speed,function(){base.$el.find("#"+listID).fadeIn(base.options.speed);var newHeight=base.$el.find("#"+listID).height();$allListWrap.animate({height:newHeight});base.$el.find(".tabnav div a").removeClass("current");$newList.addClass("current");});}
return false;});};base.init();};$.organicTabs.defaultOptions={"speed":300};$.fn.organicTabs=function(options){return this.each(function(){(new $.organicTabs(this,options));});};})(jQuery);(function($){var nav=$("#navigation");nav.find("li").hover(function(){$(this).addClass("hover");},function(){$(this).removeClass("hover");});nav.find("li").each(function(){if($(this).find("ul").length>0){$(this).mouseenter(function(){$(this).find("ul").stop(true,true).slideDown();});$(this).mouseleave(function(){$(this).find("ul").stop(true,true).slideUp();});}});})(jQuery);$(document).ready(function(){var buttons={previous:$('#lofslidecontent45 .lof-previous'),next:$('#lofslidecontent45 .lof-next')};$obj=$('#lofslidecontent45').lofJSidernews({interval:4000,direction:'opacitys',easing:'easeInOutExpo',duration:1200,auto:false,maxItemDisplay:3,navPosition:'horizontal',navigatorHeight:30,navigatorWidth:105,startItem:1,mainWidth:366,buttons:buttons});});


//************ONTHESTAND*************//
$(document).ready(function(){
	$(".imgicoverpop").mouseover(function(){
		$("#imgicoverpop").show('slow');
	}).mouseout(function(){
		$("#imgicoverpop").hide('slow');
	});	
});

//************THIS WEEK*************//
$(document).ready(function(){
	$(".imgicoverpops123").mouseover(function(){
		$("#imgicoverpops123").slideDown('slow');
	}).mouseout(function(){
		$("#imgicoverpops123").slideUp('slow');
	});	
});
