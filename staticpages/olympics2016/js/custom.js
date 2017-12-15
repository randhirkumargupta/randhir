$(document).ready(function(){
						   
var swiper = new Swiper('.swiper-container', {
        pagination: '.swiper-pagination',
		preventClicks: false,
        slidesPerView: 'auto',
        paginationClickable: true,
        spaceBetween: 0
    });

						   
	$(".thumb").click(function(){
	$(".thumb").removeClass("activethumb")
	$(this).addClass("activethumb");
	
	})
})
// end active thumb slide


      $(document).ready(function(){
$('.fa-search').click(function(){

$('.search_cont').slideToggle(); 
}) 

$('#embed_ky').click(function(){

$('#embed_code').slideToggle(); 
}) 


})





/*** SIDEBAR FIXED ***/
$(document).ready(function(){
	var len = $(".fixed_sp ul li").length;
	var li_height =$(".fixed_sp ul li").height()+31;
	//alert(li_height);
	var li_heighta=len*li_height;
	$(".fixed_sp ul").css("height",li_heighta);
	var cont_h = 1;
	
	$('.fixed_more').click(function(){
	if(cont_h < len-6)
	{
	$('.fixed_more_2').css('display','block')
	$(".fixed_sp ul").animate({'top':'-='+li_height});
	cont_h++;	
	}
	else
	{
		$('.fixed_more_2').css('display','block');
		$('.fixed_more').css('display','none')
	}
	
	})
	
	$('.fixed_more_2').click(function(){
	if(cont_h ==1)
	{
		$('.fixed_more').css('display','block');
		$('.fixed_more_2').css('display','none');
	}
	else
	{
	$(".fixed_sp ul").animate({'top':'+='+li_height});
	cont_h--;	
	$('.fixed_more').css('display','block')
	}
	})

});

/*** end SIDEBAR FIXED ***/

/***  FIXED WINDOW MOVE ***/
function sticky_relocate() {
    var window_top = $(window).scrollTop();
    var div_top = $('#sticky-anchor').offset().top;
    if (window_top > div_top) {
        $('#sticky').addClass('stick');
        $('#sticky-anchor').height($('#sticky').outerHeight());
    } else {
        $('#sticky').removeClass('stick');
        $('#sticky-anchor').height(0);
    }
}

$(function() {
    $(window).scroll(sticky_relocate);
    sticky_relocate();
});

var dir = 1;
var MIN_TOP = 200;
var MAX_TOP = 350;

function autoscroll() {
    var window_top = $(window).scrollTop() + dir;
    if (window_top >= MAX_TOP) {
        window_top = MAX_TOP;
        dir = -1;
    } else if (window_top <= MIN_TOP) {
        window_top = MIN_TOP;
        dir = 1;
    }
    $(window).scrollTop(window_top);
    window.setTimeout(autoscroll, 100);
}
/***  end FIXED WINDOW MOVE ***/
var rootdomain = "http://" + window.location.hostname

function ajaxinclude(url) {
    var page_request = false
    if (window.XMLHttpRequest)
        page_request = new XMLHttpRequest()
    else if (window.ActiveXObject) {
        try {
            page_request = new ActiveXObject("Msxml2.XMLHTTP")
        } catch (e) {
            try {
                page_request = new ActiveXObject("Microsoft.XMLHTTP")
            } catch (e) {}
        }
    } else
        return false
    page_request.open('GET', url, false)
    page_request.setRequestHeader("If-Modified-Since", "Thu, 1 Jan 1970 00:00:00 GMT");
    page_request.send(null)
    writecontent(page_request)
}

function writecontent(page_request) {
    if (window.location.href.indexOf("http") == -1 || page_request.status == 200)
        document.write(page_request.responseText)
}




