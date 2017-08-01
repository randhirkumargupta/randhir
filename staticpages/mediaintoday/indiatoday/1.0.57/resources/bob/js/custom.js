$(function(){
                var ink, d, x, y;
                $(".ripplelink").click(function(e){
    if($(this).find(".ink").length === 0){
        $(this).prepend("<span class='ink'></span>");
    }
         
    ink = $(this).find(".ink");
    ink.removeClass("animate");
     
    if(!ink.height() && !ink.width()){
        d = Math.max($(this).outerWidth(), $(this).outerHeight());
        ink.css({height: d, width: d});
    }
     
    x = e.pageX - $(this).offset().left - ink.width()/2;
    y = e.pageY - $(this).offset().top - ink.height()/2;
     
    ink.css({top: y+'px', left: x+'px'}).addClass("animate");
});
});

/**** end link effect ***/

/*** Product Active ***/
$(document).ready(function(){
	$(".swiper-slide").click(function(){
		$(this).addClass("swiperActiveLink");
		var slideValue=$(this).attr("data-product");
		//alert(slideValue);
		var data=slideValue.split("_");
		if(data[1]=='2')
		{
			 $("#firstone_1").val(data[0]);
			 $("#swipSlides").load("slider-2.jsp");
		}
		else if(data[1]=='3')
		{
			$("#firstone_2").val(data[0]);
			$("#swipSlides").load("slider-3.jsp");
		}
		else if(data[1]=='4')
		{
			$("#firstone_3").val(data[0]);
			$("#swipSlides").load("slider-4.jsp");
		}
		else if(data[1]=='5')
		{
			$("#firstone_4").val(data[0]);
			$("#swipSlides").load("slider-5.jsp");
		}
		else if(data[1]=='6')
		{
			$("#firstone_5").val(data[0]);
			$("#swipSlides").load("slider-6.jsp");
		}
		else if(data[1]=='7')
		{
			$("#firstone_6").val(data[0]);
			$("#swipSlides").load("slider-7.jsp");
		}
		else if(data[1]=='8')
		{
			$("#firstone_7").val(data[0]);
			$("#swipSlides").load("slider-8.jsp");
		}
		else if(data[1]=='9')
		{
			$("#firstone_8").val(data[0]);
			$("#swipSlides").load("slider-9.jsp");
		}
		else if(data[1]=='10')
		{
			$("#firstone_9").val(data[0]);
			$("#swipSlides").load("slider-10.jsp");
		}
		else if(data[1]=='11')
		{
			$("#firstone_10").val(data[0]);
			$("#swipSlides").load("slider-11.jsp");
		}
		else if(data[1]=='12')
		{
			$("#firstone_11").val(data[0]);
			$("#swipSlides").load("slider-12.jsp");
		}
		else if(data[1]=='13')
		{
			$("#firstone_12").val(data[0]);
			$("#swipSlides").load("slider-13.jsp");
		}
		else if(data[1]=='14')
		{
			$("#firstone_13").val(data[0]);
			$("#swipSlides").load("slider-14.jsp");
		}
		else if(data[1]=='15')
		{
			$("#firstone_14").val(data[0]);
			$("#swipSlides").load("slider-15.jsp");
		}
		else 
		{
			//document.frm.action="slider-thanks.jsp";
			//document.frm.submit();
			$("#firstone_15").val(data[0]);
			
			 $.ajax({url: "slider-thanks.jsp",type: "POST",data: $("#frm").serialize(), 
			success: function(result)
			{
			$("#swipSlides").html(result);
			}
	});
			 
		//	$("#swipSlides").load("slider-thanks.jsp");
			
		}
		/*else if(slideValue=="avene1" || slideValue=="avene2" || slideValue=="avene3" || slideValue=="avene4" || slideValue=="avene5" || slideValue=="avene6" || slideValue=="avene7")
		{
			$("#swipSlides").load("slider-3.jsp");
		}*/
		
	});
});
/*** End Product Active ***/

/*** Main slider ***/
    var swiper = new Swiper('#swipSlides .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlides .swiper-button-next',
        prevButton: '#swipSlides .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** end Main slider ***/
	
/*** 1 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro1 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro1 .swiper-button-next',
        prevButton: '#swipSlidesPro1 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 1 Product slider ***/
	
	/*** 2 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro2 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro2 .swiper-button-next',
        prevButton: '#swipSlidesPro2 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 2 Product slider ***/
	
	/*** 3 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro3 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro3 .swiper-button-next',
        prevButton: '#swipSlidesPro3 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 3 Product slider ***/
	
	
	/*** 4 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro4 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro4 .swiper-button-next',
        prevButton: '#swipSlidesPro4 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End  4 Product slider ***/
	
	/*** 5 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro1 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro5 .swiper-button-next',
        prevButton: '#swipSlidesPro5 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End  5 Product slider ***/
	
	/*** 6 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro6 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro6 .swiper-button-next',
        prevButton: '#swipSlidesPro6 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End  6 Product slider ***/
	
	/*** 7 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro7 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro7 .swiper-button-next',
        prevButton: '#swipSlidesPro7 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 7 Product slider ***/
	
	/*** 8 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro8 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro8 .swiper-button-next',
        prevButton: '#swipSlidesPro8 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 8 Product slider ***/
	
/*** 8 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro9 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro9 .swiper-button-next',
        prevButton: '#swipSlidesPro9 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 9 Product slider ***/
	
/*** 10 Product slider ***/ 
   var swiper = new Swiper('#swipSlidesPro10 .swiper-container', {
        pagination: '.swiper-pagination',
        paginationClickable: true,
        nextButton: '#swipSlidesPro10 .swiper-button-next',
        prevButton: '#swipSlidesPro10 .swiper-button-prev',
        spaceBetween: 30,
		slidesPerView: 5,
		breakpoints: {
			1024: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			768: {
				slidesPerView: 4,
				spaceBetween: 10
			},
			640: {
				slidesPerView: 3,
				spaceBetween: 10
			},
			320: {
				slidesPerView: 2,
				spaceBetween: 10
			}
		}

    });
	
	/*** End 10 Product slider ***/