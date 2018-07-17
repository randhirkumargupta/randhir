// JavaScript Document


$(document).ready(function(){
if(navigator.userAgent.match(/Windows Phone/i)){
    //alert('Is a windows phone!');
	
	var swiper = new Swiper('#sldtop', {
        pagination: '.pg2', 
        paginationClickable: true,
        spaceBetween: 0,
		 
		loop: true
      
    });
	 var swiper = new Swiper('#sldphoto', {
        pagination: '.pgphoto', 
        paginationClickable: true,
        spaceBetween: 0,
	
		loop: true
      
    });
	
		 var swiper = new Swiper('#ph3', {
        pagination: '.p23', 
        paginationClickable: true,
        spaceBetween: 0,
		
		loop: true
      
    });
	
		 var swiper = new Swiper('#sldvideo', {
        pagination: '.vdphoto', 
        paginationClickable: true,
        spaceBetween: 0,
		
		loop: true
       
    });
		 
		 
	widthm = $(window).width();
	if(widthm>360){
	var swiper = new Swiper('#top_menu', {
		slidesPerView: 5,
		loop: true,
        spaceBetween: 30,
        freeMode: true
    })
	}
	else
	{
	var swiper = new Swiper('#top_menu', {
		slidesPerView: 'auto',
		loop: true,
        spaceBetween: 30,
        freeMode: true
    })	
	}
	
	
	
}
else {
 var swiper = new Swiper('#sldtop', {
        pagination: '.pg2', 
        paginationClickable: true,
        spaceBetween: 0,
		effect: 'cube',  
		loop: true,
        cube: {
            shadow: false,
            slideShadows: true,
            shadowOffset: 20,
            shadowScale: 0.94
        }
    });
	 var swiper = new Swiper('#sldphoto', {
        pagination: '.pgphoto', 
        paginationClickable: true,
        spaceBetween: 0,
		effect: 'cube',  
		loop: true,
        cube: {
            shadow: false,
            slideShadows: true,
            shadowOffset: 20,
            shadowScale: 0.94
        }
    });
	
		 var swiper = new Swiper('#ph3', {
        pagination: '.p23', 
        paginationClickable: true,
        spaceBetween: 0,
		effect: 'cube',  
		loop: true,
        cube: {
            shadow: false,
            slideShadows: true,
            shadowOffset: 20,
            shadowScale: 0.94
        }
    });
	
		 var swiper = new Swiper('#sldvideo', {
        pagination: '.vdphoto', 
        paginationClickable: true,
        spaceBetween: 0,
		effect: 'cube',  
		loop: true,
        cube: {
            shadow: false,
            slideShadows: true,
            shadowOffset: 20,
            shadowScale: 0.94
        }
    });
		 
		 
	widthm = $(window).width();
	if(widthm>360){
	var swiper = new Swiper('#top_menu', {
		slidesPerView: 'auto', 
		loop: true,
        spaceBetween: 30,
        freeMode: false
    })
	}
	else
	{
	var swiper = new Swiper('#top_menu', {
		slidesPerView: 'auto',
		loop: true,
        spaceBetween: 30,
        freeMode: false
    })	
	}
	
}
});

$(document).ready(function(){
	$('.col-hd').children('span').removeClass('plus');
	//$('.col-cont').hide();
	$('.col-hd').click(function(){
		$(this).children('span').toggleClass('plus');
	$(this).siblings('.col-cont').slideToggle();
	$(this).siblings('.photo_cent').slideToggle();
	});
	
/************************Aajtak Top Menu ***************************/
aajtak = window.aajtak || {};
aajtak.mobile = window.aajtak.mobile || {};
aajtak.mobile.navigation = {
    constants: {
        navSel: "#menu",
        menuCont: ".aajtak-menu",
        menuSel: "#mainMenu",
        subMenuCont: "#subMenu",
        subMenuSel: ".submenu-icon",
        subMenuBackSel: ".back-menu",
        whichMenuSel: "data-submenu",
        activeCls: "active",
        hide: "hide",
        overflow: "bodyoverflow",
        closemenu: "#closemenu"
    },
    mainMenu: function(a) {
        a.toggleClass(this.constants.activeCls);
        $(this.constants.menuCont).toggleClass(this.constants.hide);
        $(this.constants.menuSel).toggleClass(this.constants.hide);
        $("body").toggleClass(this.constants.overflow)
    },
    subMenu: function() {
        $(this.constants.menuSel).toggleClass(this.constants.hide);
        $(this.constants.subMenuCont).toggleClass(this.constants.hide)
    },
    attachMainMenuClick: function() {
        $(this.constants.navSel).click(function(a) {
            aajtak.mobile.navigation.mainMenu($(this))
        });
    },
    attachMainCloseClick: function() {
        $(this.constants.closemenu).click(function(a) {
            $("body").toggleClass("bodyoverflow");
            $(".aajtak-menu").toggleClass("hide");
            $("#mainMenu").toggleClass("hide")
        })
    },
    attachSubMenuClick: function() {
        $(this.constants.subMenuSel).click(function(c) {
            var a = $(this).attr(aajtak.mobile.navigation.constants.whichMenuSel);
            var b = $("div[" + aajtak.mobile.navigation.constants.whichMenuSel + "=" + a + "]");
            var d = b.siblings("div");
            d.hide();
            b.show();
            b.parent("ul").show();
            b.parent("ul").siblings("ul").hide()
        })
    },
    attachBackMenuClick: function() {
        $(this.constants.subMenuBackSel).click(function(b) {
            var c = $(this).parent("ul");
            var a = c.prev();
            c.hide();
            a.show()
        })
    },

    init: function() {
        this.attachMainMenuClick();
        this.attachSubMenuClick();
        this.attachBackMenuClick();
        this.fixL2NavWidth();
        this.adjustNavScroll();
        this.backtotop();
        this.attachMainCloseClick()
    }
};
aajtak.mobile.navigation.init();
});
$(document).ready(function() {
    aajtak.mobile.navigation.adjustNavScroll()
	
});

