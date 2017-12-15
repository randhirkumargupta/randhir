/*/***************************Category Swiper Slider************************************/
$(document).ready(function(){
    //Top Nav
	var swiper = new Swiper('#navSwipeSlider .swiper-container', {
        paginationClickable: true,
        slidesPerView: 6,
        spaceBetween:0,
       
         breakpoints: {
            1024: {
                slidesPerView: 5,
                spaceBetween: 0
            },
            768: {
                slidesPerView: 5,
                spaceBetween: 0
            },
            640: {
                slidesPerView:  3,
                spaceBetween: 0
            },
			
			
			
			
            320: {
                slidesPerView:2,
                spaceBetween: 0
            }
         }
        
     });


    //Sponsor area
	var swiper = new Swiper('#sponSwipeSlider .swiper-container', {
        paginationClickable: true,
        slidesPerView: 5,
        spaceBetween:0,
       
         breakpoints: {
            1024: {
                slidesPerView: 4,
                spaceBetween: 0
            },
            768: {
                slidesPerView: 3,
                spaceBetween: 0
            },
            640: {
                slidesPerView: 3,
                spaceBetween: 0
            },
			
			  481: {
                slidesPerView: 2,
                spaceBetween: 0
            },
			
            320: {
                slidesPerView:1,
                spaceBetween: 0
            }
         }
        
     });




//Top Slider
    var swiper3 = new Swiper('#topStorySlider .swiper-container', {
        paginationClickable: true,
        slidesPerView:'auto',
        centeredSlides: true,
        spaceBetween:5,
        loop:'true',
        nextButton: '#topStorySlider .swiper-button-next',
        prevButton: '#topStorySlider .swiper-button-prev',
         breakpoints: {
            1024: {
                slidesPerView: 'auto',
                spaceBetween: 0
            },
            768: {
                slidesPerView: 'auto',
                spaceBetween: 0
            },
            640: {
                slidesPerView: 'auto',
                spaceBetween: 0
            },
            320: {
                slidesPerView:'auto',
                spaceBetween: 0
            }
         }
        
     }); 
//Speaker Slider
    var swiper = new Swiper('#speakerSlider .swiper-container', {
        paginationClickable: true,
        slidesPerView:'auto',
        spaceBetween:0,
         nextButton: '#speakerSlider .swiper-button-next',
        prevButton: '#speakerSlider .swiper-button-prev',
       
         breakpoints: {
            1024: {
                slidesPerView: 1,
                spaceBetween: 20
            },
            768: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            640: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            320: {
                slidesPerView:1,
                spaceBetween: 10
            }
         }
        
     });


//Speaker page Slider
    var swiper = new Swiper('#speakerPageSlider .swiper-container', {
        paginationClickable: true,
        slidesPerView:'auto',
        spaceBetween:0,
         nextButton: '#speakerPageSlider .swiper-button-next',
        prevButton: '#speakerPageSlider .swiper-button-prev',
       
         breakpoints: {
            1024: {
                slidesPerView: 1,
                spaceBetween: 0
            },
            768: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            640: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            320: {
                slidesPerView:1,
                spaceBetween: 10
            }
         }
        
     });
	 
//video Slider
    var swiper = new Swiper('#VideoSlider .swiper-container', {
        paginationClickable: true,
        slidesPerView:'auto',
        spaceBetween:0,
        nextButton: '#VideoSlider .swiper-button-next',
        prevButton: '#VideoSlider .swiper-button-prev',
       
         breakpoints: {
            1024: {
                slidesPerView: 1,
                spaceBetween: 20
            },
            768: {
                slidesPerView: 1,
                spaceBetween: 0
            },
            640: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            320: {
                slidesPerView:1,
                spaceBetween: 10
            }
         }
        
     });
	 
	 
//video page Slider
    var swiper = new Swiper('#VideoSliderPage .swiper-container', {
        paginationClickable: true,
        slidesPerView:'auto',
        spaceBetween:0,
        nextButton: '#VideoSliderPage .swiper-button-next',
        prevButton: '#VideoSliderPage .swiper-button-prev',
       
         breakpoints: {
            1024: {
                slidesPerView: 1,
                spaceBetween: 20
            },
            768: {
                slidesPerView: 1,
                spaceBetween: 0
            },
            640: {
                slidesPerView: 1,
                spaceBetween: 10
            },
            320: {
                slidesPerView:1,
                spaceBetween: 10
            }
         }
        
     });


//Accodian
    $(".accodianSec li").click(function(){
            if($(this).hasClass("active")){
                $(this).removeClass("active");
                $(this).find($(".accodianData")).slideUp(); 
            }else{
                $(".accodianSec li").removeClass("active");
                $(".accodianSec li").find($(".accodianData")).slideUp();
                $(this).addClass("active");
                $(this).find($(".accodianData")).slideDown();   
            }
            
        });


});