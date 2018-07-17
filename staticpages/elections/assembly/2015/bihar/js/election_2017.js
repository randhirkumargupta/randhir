// JavaScript Document  <script>
$(document).ready(function(){
						   
						   
try {
var width_od = $('.assembly_cont ul.odd_slider li').width();
var length_od = $('.assembly_cont ul.odd_slider li').length;
var tot_width_od = width_od*length_od;
$('.assembly_cont ul.odd_slider').css({'width':tot_width_od});
var counter_od = 1;
$('.assembly_nav .odd_right_arrow').click(function(){
if(counter_od < length_od)
{
	$('.assembly_nav .odd_left_arrow').css('opacity','1');
	$('.assembly_cont ul.odd_slider').animate({'left':'-='+width_od})
	counter_od++; 

}else{
	/*counter_od=1;
	$('.assembly_cont ul.odd_slider').animate({'left':'0'});*/
}
})  

	$('.assembly_nav .odd_left_arrow').click(function(){
	
		if(counter_od==1)
		{
			/*$('.assembly_nav .odd_left_arrow').css('opacity','0.4');*/
		}else{
			$('.assembly_cont ul.odd_slider').animate({'left':'+='+width_od})
			counter_od--;
		}
	})
} catch(e)
{
console.log("Exception : " + e);
}

$('ul.cov_assem li').click(function(){
	try {
	var cl_id = $(this).attr('id');   
	$('ul.cov_assem li').removeClass('active_assm');
	$(this).addClass('active_assm');
	$('.data_assem').css('display','none');
	$('.'+cl_id).css('display','block');
	} catch(e)
{
console.log("Exception UL li : " + e);
}
})
});
/****************Menu *************************/
$(document).ready(function() {

    intoday = window.intoday || {}, intoday.mobile = window.intoday.mobile || {}, intoday.mobile.navigation = {
        constants: {
            navSel: "#menu_btn_main",
            menuCont: ".indiatoday_menu",
            menuSel: "#mainMenu",
            subMenuCont: "#subMenu",
            subMenuSel: ".submenu-icon",
            subMenuBackSel: ".back-menu",
            whichMenuSel: "data-submenu",
            activeCls: "fa-close",
            hide: "hide",
            hideclass: "fa-align-justify",
            overflow: "bodyoverflow",
            closemenu: "#closemenu"
        },
        mainMenu: function(e) {
            e.toggleClass(this.constants.activeCls), e.toggleClass(this.constants.hideclass), $(this.constants.menuCont).toggleClass(this.constants.hide), $(this.constants.menuSel).toggleClass(this.constants.hide), $("body").toggleClass(this.constants.overflow)
        },
        subMenu: function() {
            $(this.constants.menuSel).toggleClass(this.constants.hide), $(this.constants.subMenuCont).toggleClass(this.constants.hide)
        },
        attachMainMenuClick: function() {
            $(this.constants.navSel).click(function(e) {
                intoday.mobile.navigation.mainMenu($(this))
            })
        },
        attachMainCloseClick: function() {
            $(this.constants.closemenu).click(function(e) {
                $("body").toggleClass("bodyoverflow"), $(".indiatoday_menu").toggleClass("hide"), $("#mainMenu").toggleClass("hide")
            })
        },
        attachSubMenuClick: function() {
            $(this.constants.subMenuSel).click(function(e) {
                var i = $(this).attr(intoday.mobile.navigation.constants.whichMenuSel),
                    s = $("div[" + intoday.mobile.navigation.constants.whichMenuSel + "=" + i + "]"),
                    a = s.siblings("div");
                a.hide(), s.show(), s.parent("ul").show(), s.parent("ul").siblings("ul").hide()
            })
        },
        attachBackMenuClick: function() {
            $(this.constants.subMenuBackSel).click(function(e) {
                var i = $(this).parent("ul"),
                    s = i.prev();
                i.hide(), s.show()
            })   
        },      
		fixL2NavWidth: function(){
		},
		adjustNavScroll: function(){
		},
		backtotop: function(){
		},
		attachMainCloseClick: function(){
		},
        init: function() {
            this.attachMainMenuClick(), this.attachSubMenuClick(), this.attachBackMenuClick(), this.fixL2NavWidth(), this.adjustNavScroll(), this.backtotop(), this.attachMainCloseClick()
        }
    }, intoday.mobile.navigation.init()

}), $(document).ready(function() {
	
    intoday.mobile.navigation.adjustNavScroll();
    setTimeout(function() {
        $(".moveicon").css('display', 'block');

    }, 5000);
	
});
/****************Menu *************************/




$(document).ready(function() {
   try{

     var photolen1  = $('.photobelt .photo-list').length;
    var photolistwidth1 = $('.photobelt .photo-list').width();
    var photowidth1 = photolen1*(photolistwidth1+5);
    //alert(photowidth);
    $('.photobelt').css('width', photowidth1);
    var photocounters = 1;
    //$('#photoprev-elec16').css('display', 'none');
   
    $('#photonext-elec16').click(function(){

        if(photocounters < photolen1)
        {
                $('.photobelt').animate({
                    left : '-=310'
                });
                photocounters +=1;
                
                //$('#photoprev-elec16').css('display', 'block');
        }
        else{
        //  $('#photonext-elec16').css('display', 'none');
            
        }
        
       // console.log(photocounters);
    }); 
       
    $('#photoprev-elec16').click(function(){
        if(photocounters == 1)
        {
            //  $('#photoprev-elec16').css('display', 'none');
            //  $('#photonext-elec16').css('display', 'block');
        }
        else{
            $('.photobelt').animate({    
                    left : '+=310'
                });
            photocounters -= 1;
        //  $('#photonext-elec16').css('display', 'block');
            
            
        }
               // console.log(photocounters);
    });
    }catch(e)
    {
    console.log("Exception E:" + e);
    }
    });
       
(function($){
    try {
  $.fn.isVisibleOnScreen = function(partial){ 
  $(document)   
      var $t        = $(this),
        $w        = $(window),
        viewT     = $w.scrollTop(),
        viewB    = viewT + $w.height(),
        _top      = $t.offset().top,
        _bottom     = _top + $t.height() - 115,
        compareT    = partial === true ? _bottom : _top,
        compareB = partial === true ? _top : _bottom;
    
    return ((compareB <= viewB) && (compareT >= viewT));
    };
    }catch(e)
{
    console.log("---> l" + e);
}
    
})(jQuery);


    $(document).ready(function(){

            try {
    var win_wids = $(window).width();
    if (win_wids > 900){        
        $(window).scroll(function(){        
            
            var right_wd = $('#right-section').height();
            var ft_height = $('.footerSection').height();
            var win_wid = $(window).width();
            var cont_wid = $('#wapper').width();
            win_wid = win_wid - cont_wid;
            win_wid = win_wid/2;
            
            
            var curr_sroll_pos = $(window).scrollTop();
            
            if (curr_sroll_pos >= right_wd-100){
                $('#right-section').addClass('right_fixed');
                $('#right-section').css('right', win_wid);
            }else{
                $('#right-section').removeClass('right_fixed');
            }
                          
        }); 
    }
   }catch(e)
{
    console.log("---> l" + e);
} 
    
});


$(document).ready(function(){
    try {
    
    if ($(window).width() < 1000) {
   
}
else {
$(window).scroll(function(){
          if($(window).scrollTop() == $(document).height() - $(window).height()){
            lastAddedLiveFunc();
          }else{            
            $('.right_fixed').css({'bottom': '10px','z-index':-7});   
            
          }
          
    });
}
    
    
        
    
    function lastAddedLiveFunc(){
        $('.right_fixed').css('bottom', '450px');
    }

}catch(e)
{
    console.log("---> l" + e);
}
});



$(document).ready(function() {
    $("#tabs2").hide();
    $("#tabs3").hide();
    $("#tabas a").click(function(){
        $("#tabs1").show().slideDown(300);
        $("#tabs2").hide().slideUp(300);
        $("#tabs3").hide().slideUp(300);
        $("#tabas").removeClass("grey");
        $("#tabbbs").addClass("grey");
        $("#tabbs").addClass("grey");
    });
    
    $("#tabbs a").click(function(){
        $("#tabs2").show().slideDown(300);
        $("#tabs1").hide().slideUp(300);
        $("#tabs3").hide().slideUp(300);
        $("#tabbbs").addClass("grey");
        $("#tabbs").removeClass("grey");
        $("#tabas").addClass("grey");
    });
    
    
    $("#tabbbs a").click(function(){
        $("#tabs2").hide().slideUp(300);
        $("#tabs1").hide().slideUp(300);
        $("#tabs3").show().slideDown(300);
        $("#tabbbs").removeClass("grey");
        $("#tabbs").addClass("grey");
        $("#tabas").addClass("grey");
    });
    
    
});
