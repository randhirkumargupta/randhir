$(document).ready(function(){
		$('.loadingad').each(function() {
        	setTimeout(function(){$('.loadingad').slideDown();},1000);    
        });
		$('.popoutwindows').click(function() {
			window.open('/staticpages/mediaintoday/indiatoday/high-lowes-large.html','window','status=no,resize=yes,toolbar=no,scrollbars=yes,width=1221,height=597');
		});
	});

function validate1()
{
	if(document.searchform1.searchword.value=="")
	{
		alert("Please Enter A Search Keyword");
		document.searchform1.searchword.focus();
		return false;
	}
	if(document.searchform1.searchword.value!="")
	{
		if(document.searchform1.searchword.value=="Search..." || document.searchform1.searchword.value=="Search.." || document.searchform1.searchword.value=="Search." || document.searchform1.searchword.value=="Search")
		{
			alert("Please Enter A Valid Search Keyword");
			document.searchform1.searchword.focus();
			return false;
		}
		if(document.searchform1.searchword.value=="null") 
		{
			alert("Please Enter A Search Keyword");
			document.searchform1.searchword.focus();
			return false;
		}
		if(document.searchform1.searchword.value.length < 3) 
		{
			alert("Please Enter Atleast 3 characters");
			document.searchform1.searchword.focus();
			return false;
		}
	}
   if(document.searchform1.fromdate.value!="")
	{
		var fdt=document.searchform1.fromdate.value;
		if(isDate1(fdt)== false){
		document.searchform1.fromdate.focus();
		return false;
		}
	}
	if(document.searchform1.fromdate.value!="")
	{
				if(document.searchform1.todate.value=="")
				{           alert("Please Select To Date");
							document.searchform1.todate.focus();
							return false;
				}
	}
	if(document.searchform1.todate.value!=""){
		var fdt=document.searchform1.fromdate.value;
				var tdt=document.searchform1.todate.value;
				if(isDate1(tdt)== false){
				document.searchform1.todate.focus();
				return false;
				}
				if(datefun1(fdt,tdt,'To Date Should Be Greater Than From Date')==0){
				document.searchform1.todate.focus();
				return false;
				}
	}
}

function serchpagevalidate()
{
	if(document.searchform.searchword.value=="")
	{
		alert("Please Enter A Search Keyword");
		document.searchform.searchword.focus();
		return false;
	}
	if(document.searchform.searchword.value!="")
	{
		if(document.searchform.searchword.value=="Search..." || document.searchform.searchword.value=="Search.." || document.searchform.searchword.value=="Search." || document.searchform.searchword.value=="Search")
		{
			alert("Please Enter A Valid Search Keyword");
			document.searchform.searchword.focus();
			return false;
		}
		if(document.searchform.searchword.value=="null") 
		{
			alert("Please Enter A Search Keyword");
			document.searchform.searchword.focus();
			return false;
		}
		if(document.searchform.searchword.value.length < 3) 
		{
			alert("Please Enter Atleast 3 characters");
			document.searchform.searchword.focus();
			return false;
		}
	}
   if(document.searchform.fromdate.value!="")
	{
		var fdt=document.searchform.fromdate.value;
		if(isDate1(fdt)== false){
		document.searchform.fromdate.focus();
		return false;
		}
	}
	if(document.searchform.fromdate.value!="")
	{
				if(document.searchform.todate.value=="")
				{           alert("Please Select To Date");
							document.searchform.todate.focus();
							return false;
				}
	}
	if(document.searchform.todate.value!=""){
		var fdt=document.searchform.fromdate.value;
				var tdt=document.searchform.todate.value;
				if(isDate1(tdt)== false){
				document.searchform.todate.focus();
				return false;
				}
				if(datefun1(fdt,tdt,'To Date Should Be Greater Than From Date')==0){
				document.searchform.todate.focus();
				return false;
				}
	}
}

function getUrlVars(pageurl)
{
	//alert(pageurl);
    var vars = [], hash;
    var hashes = pageurl.slice(pageurl.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
}
$(document).ready(function($){$('.slideshow').live('mouseover mouseout',function(event){if(event.type=='mouseover'){$(this).children('.left-button, .right-button').stop(true,true).fadeIn();}
else{$(this).children('.left-button, .right-button').stop(true,true).fadeOut();}});var loadlinkk=window.location.hash+"";if(loadlinkk)
{var server_name=top.location.host;var newlinkid=loadlinkk.replace("#","");$('#show').load('http://'+server_name+'/gallery_data.jsp?galleryId='+galleryId+'&totalPhotoCount='+totalPhotoCount+'&currentPhotoNo='+newlinkid,function(){simpleSlide({'swipe':'true'});addNotranslate();});}
$('.right-button, .left-button').live('click',function(){var action=$(this).attr('class');pageTracker._trackEvent('Slide Interactions','Clicks',action);});$('#bigboy, #mini').live('click',function(){var version=$(this).attr('id');pageTracker._trackEvent('simpleSlide Downloads','Downloaded',version);});});function navColors(color_name){$('ul#nav_links li').removeAttr('class');$('ul#nav_links li span').each(function(){if($(this).attr('class')==color_name){$(this).parent().addClass(color_name);}});}
function loadLink(load_link){$('#show').html("<div style='width:675px;height:300px;margin-top:280px; '></div>");$('#show').css('position','relative');$('#show').animate({'left':'0px'},100,"swing",function(){$.ajax({url:''+load_link,dataType:'html',success:function(html){$('#show').html(html);simpleSlide({'swipe':'true','callback':function(){$('#show').animate({'left':'0px','opacity':'1'},300,"swing",function(){$('#show').css('position','static');});}});
var pagenextnumber=parseInt(getUrlVars(load_link)["currentPhotoNo"]);
var pagetotalnumber=parseInt(getUrlVars(load_link)["totalPhotoCount"]);
//alert(load_link + " -- pagenextnumber->"+pagenextnumber+" -- pagetotalnumber" +pagetotalnumber);
if(pagenextnumber==pagetotalnumber)
{
	//$('#photooverlay').delay(7200).fadeIn(500);
	setTimeout(function() {
		$('#photooverlay').fadeIn(500);
	}, 7200);
	//alert(load_link);
}

$('.auto-slider').each(function(){var related_group=$(this).attr('rel');clearInterval($.autoslide);$.autoslide=setInterval("simpleSlideAction('.right-button', "+related_group+");",4000);});}});});}
function addNotranslate(){$('.codeblock').addClass('notranslate');$('code').addClass('notranslate');}

function Open_win(uv,utwidth,utheight){var remoteWin=null;var params;params="toolbar=0,location=0,directories=0,status=0,scrollbars=1,scrolling=1,resizable=0,menubar=0,width="+utwidth+",height="+utheight+" ";remoteWin=window.open("","colorpicker",params);remoteWin.location.href=uv;}
var min=8;var max=17;function increaseFontSize(){var p=document.getElementsByTagName('p');for(i=0;i<p.length;i++){if(p[i].style.fontSize){var s=parseInt(p[i].style.fontSize.replace("px",""));}else{var s=14;}
if(s!=max){s+=1;}
p[i].style.fontSize=s+"px"}}
function decreaseFontSize(){var p=document.getElementsByTagName('p');for(i=0;i<p.length;i++){if(p[i].style.fontSize){var s=parseInt(p[i].style.fontSize.replace("px",""));}else{var s=14;}
if(s!=min){s-=1;}
p[i].style.fontSize=s+"px"}}
function resetFontSize(){var p=document.getElementsByTagName('p');for(i=0;i<p.length;i++){p[i].style.fontSize="14px"}}
function cemail(val){if(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(val.value)){return(true)}
return false;}
function ajaxFunction(){var frm=document.feedback;if(frm.FNAME.value=="")
{alert("Please enter First Name");frm.FNAME.focus();return false;}
if(frm.FNAME.value!=""){var alp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";for(var i=0;i<frm.FNAME.value.length;i++){temp=frm.FNAME.value.substring(i,i+1);if(alp.indexOf(temp)==-1){alert("First name should accept only alphabets[a-z,A-Z]");frm.FNAME.focus();return false;}}}
if(frm.LNAME.value!=""){var alp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";for(var i=0;i<frm.LNAME.value.length;i++){temp=frm.LNAME.value.substring(i,i+1);if(alp.indexOf(temp)==-1){alert("Last name should accept only alphabets[a-z,A-Z]");frm.LNAME.focus();return false;}}}
if(frm.EMAIL.value=="")
{alert("Please enter Email Id");frm.EMAIL.focus();return false;}
if(cemail(frm.EMAIL)==false)
{alert("Please enter valid email ID");frm.EMAIL.focus();return false;}
if((frm.dob_date.value!=-1&&frm.dob_month.value==-1))
{alert("Please select Month")
frm.dob_month.focus();return false;}
if(frm.dob_month.value!=-1&&frm.dob_year.value==-1)
{alert("Please select Year")
frm.dob_year.focus();return false;}
if(frm.Location.value=="")
{alert("Please enter city");frm.Location.focus();return false;}
if(frm.Location.value!=""){var alp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";for(var i=0;i<frm.Location.value.length;i++){temp=frm.Location.value.substring(i,i+1);if(alp.indexOf(temp)==-1){alert("City should accept only alphabets[a-z,A-Z]");frm.Location.focus();return false;}}}
if(frm.country.value!=""){var alp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";for(var i=0;i<frm.country.value.length;i++){temp=frm.country.value.substring(i,i+1);if(alp.indexOf(temp)==-1){alert("Country should accept only alphabets[a-z,A-Z]");frm.country.focus();return false;}}}
if(frm.number.value=="")
{alert("Please Enter the  Code");frm.number.focus();return false;}
frm.submit();}
function Open(id){document.getElementById(id).style.display="block";}
function Close(id){document.getElementById(id).style.display="none";}
function myOpen(abc){document.location.href=abc.value;}



$(document).ready(function(){setTimeout(function(){$('#loading').hide();$('#loading2').hide();$('#loading3').hide();$('#loading4').hide();$('#content').fadeIn();$('#content2').fadeIn();$('#content3').fadeIn();$('#content4').fadeIn();},1000);})
$("#toogle_arrow").click(function(){$("#browseitmorelinks").fadeToggle("slow");if($(this).find("img").attr("src")=='images/toogle_arrow.jpg')
{$(this).find('img').attr({src:'images/toogle_arrow_down.jpg'});}
else{$(this).find('img').attr({src:'images/toogle_arrow.jpg'});}});

$(".breakclose").click(function(){$("#breaking").fadeToggle("slow");});$(function(){$("#example-one").organicTabs();$("#example-two").organicTabs();$("#example-three").organicTabs();});(function($){$.organicTabs=function(el,options){var base=this;base.$el=$(el);base.$nav=base.$el.find(".tabnav");base.init=function(){base.options=$.extend({},$.organicTabs.defaultOptions,options);$(".hide").css({"position":"relative","top":0,"left":0,"display":"none"});base.$nav.delegate("div > a","click",function(){var curList=base.$el.find("a.current").attr("href").substring(1),$newList=$(this),listID=$newList.attr("href").substring(1),$allListWrap=base.$el.find(".list-wrap"),curListHeight=$allListWrap.height();$allListWrap.height(curListHeight);if((listID!=curList)&&(base.$el.find(":animated").length==0)){base.$el.find("#"+curList).fadeOut(base.options.speed,function(){base.$el.find("#"+listID).fadeIn(base.options.speed);var newHeight=base.$el.find("#"+listID).height();$allListWrap.animate({height:newHeight});base.$el.find(".tabnav div a").removeClass("current");$newList.addClass("current");});}
return false;});};base.init();};$.organicTabs.defaultOptions={"speed":300};$.fn.organicTabs=function(options){return this.each(function(){(new $.organicTabs(this,options));});};})(jQuery);(function($){var nav=$("#navigation");nav.find("li").hover(function(){$(this).addClass("hover");},function(){$(this).removeClass("hover");});nav.find("li").each(function(){if($(this).find("ul").length>0){$(this).mouseenter(function(){$(this).find("ul").stop(true,true).slideDown();});$(this).mouseleave(function(){$(this).find("ul").stop(true,true).slideUp();});}});})(jQuery);$(document).ready(function(){var buttons={previous:$('#lofslidecontent45 .lof-previous'),next:$('#lofslidecontent45 .lof-next')};$obj=$('#lofslidecontent45').lofJSidernews({interval:4000,direction:'opacitys',easing:'easeInOutExpo',duration:1200,auto:false,maxItemDisplay:3,navPosition:'horizontal',navigatorHeight:30,navigatorWidth:105,startItem:1,mainWidth:366,buttons:buttons});});


$(document).ready(function() {
    $(".tabLink").each(function(){
      $(this).click(function(){
        tabeId = $(this).attr('id');
        $(".tabLink").removeClass("activeLink");
        $(this).addClass("activeLink");
        $(".tabcontent").addClass("hide");
        $("#"+tabeId+"-1").removeClass("hide")   
        return false;	  
      });
    });  
  });

//************ Hide the Breaking News *************//
function closeBreaking(){
	$(".breaking").slideUp();
}

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
//************THIS WEEK*************//
$(document).ready(function(){
	$(".magazine-cover > img").mouseover(function(){
		$(".largecover").show('slow');
	}).mouseout(function(){
		$(".largecover").hide('slow');
	});	
});

//************Article Share*************//
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


$(function(){

    $("ul.dropdown li").hover(function(){
    
        $(this).addClass("hover");
        $('ul:first',this).css('visibility', 'visible');
    
    }, function(){
    
        $(this).removeClass("hover");
        $('ul:first',this).css('visibility', 'hidden');
    
    });
    
    $("ul.dropdown li ul li:has(ul)").find("a:first").append(" &raquo; ");

});

//for back to top
$(function() {
	$(window).scroll(function() {
		if($(this).scrollTop() != 0) {
			$('#toTop').fadeIn();
		} else {
			$('#toTop').fadeOut();
		}
	});
	$('#toTop').click(function() {
		$('body,html').animate({scrollTop:0},800);
	});
});
//Home Slider (Don't Miss)
$(document).ready(function(){
	var largeLi1 = $('.carousel-holder ul.large li.large1');  var largeLi2 = $('.carousel-holder ul.large li.large2');  var largeLi3 = $('.carousel-holder ul.large li.large3');
	largeLi1.show(); largeLi2.hide(); largeLi3.hide();
	$('.carousel-holder ul.small li img').hover( function(){
		if($(this).parents("li").hasClass('thumb-small1')){ largeLi1.show(); largeLi2.hide(); largeLi3.hide();}
		if($(this).parents("li").hasClass('thumb-small2')){ largeLi1.hide(); largeLi2.show(); largeLi3.hide();}
		if($(this).parents("li").hasClass('thumb-small3')){largeLi1.hide(); largeLi2.hide(); largeLi3.show();}
	});
});

//Photos color Box
$(document).ready(function(){
	$('.boxgrid.captionfull').hover(function(){
	$(".cover", this).stop().animate({top:'0px'},{queue:false,duration:160});
	}, function() {
		$(".cover", this).stop().animate({top:'134px'},{queue:false,duration:160});
	});
});

$(document).ready(function () {
	
	$('#cancelpopup2').click(function(){
		$('#enrollfrm').html('');
		$('#videopopup').hide(10);
	});
});

$(document).ready(function () {

$('#cancelpopup').click(function(){
	$('#enrollfrm').html('');
	$('#videopopup').hide(10);
});
});


$(document).ready(function () {
//AE
$(".states .state-tabs > div > a").click(function(){
	$(".states .state-tabs > div").removeClass("active");
	$(".states .state-tabs > div").addClass("deactive");
	$(this).parent("div").addClass("active");
	$(this).parent("div").removeClass("deactive");
});

$(".g-state .state-tabs > div > a").click(function(){
	$(".g-state .state-tabs > div").removeClass("active");
	$(".g-state .state-tabs > div").addClass("deactive");
	$(this).parent("div").addClass("active");
	$(this).parent("div").removeClass("deactive");
});

});