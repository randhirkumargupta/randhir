/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
  Drupal.behaviors.itg_story_front = {
      attach: function(context, settings) {        
        
        $('.multiple-photo-disc').slick({
          infinite: false,
          slidesToShow: 1,
          slidesToScroll: 1,
          prevArrow: '<i class="fa fa-chevron-left" aria-hidden="true"></i>',
          nextArrow: '<i class="fa fa-chevron-right" aria-hidden="true"></i>',
          asNavFor: '.multiple-photo'                        
        });        
        $('.multiple-photo').slick({
          infinite: false,
          slidesToShow: 5,
          slidesToScroll: 1,    
          asNavFor: '.multiple-photo-disc',        
          focusOnSelect: true,
          centerPadding: '10px',       
        }); 
        
        
        //var maxValueInArray = $('.multiple-photo-disc .photo-slider').length;         
        $('.multiple-photo-disc').on('afterChange', function(event, slick, currentSlide){
            var hash_text = $(this).find('.slick-current img').attr('title');
            window.location.hash = "?PhotoStory=" + hash_text;
//            if(currentSlide === maxValueInArray) {
//                if (Drupal.settings.itg_story_front.next) {
//                    $(".multiple-photo-disc i.fa-chevron-right").css("visibility","visible").removeClass("hide")
//                    var next = Drupal.settings.itg_story_front.next;
//                    window.location.href = next;
//                  } else {
//                    $(".multiple-photo-disc i.fa-chevron-right").css("visibility","hidden").addClass("hide");
//                }
//            }
//            if (currentSlide === 0) {
//                if (Drupal.settings.itg_story_front.previous) {
//                    $(".multiple-photo-disc i.fa-chevron-left").css("visibility","visible").removeClass("hide");
//                    var previous = Drupal.settings.itg_story_front.previous;
//                    window.location.href = previous;
//                  } else {
//                    $(".multiple-photo-disc i.fa-chevron-left").css("visibility","hidden").addClass("hide");
//                }
//            }
        });             
//        var maxValueInArray = $('.multiple-photo .photo-slider').length;         
////        $('.multiple-photo').on('afterChange', function(event, slick, currentSlide) {               
////            if(currentSlide === maxValueInArray-1){
////              if (Drupal.settings.itg_story_front.next) {
////                  $(".multiple-photo-disc i.fa-chevron-right").css("visibility","visible").removeClass("hide");
////                    var next = Drupal.settings.itg_story_front.next;
////                    window.location.href = next;
////                  } else {
////                    $(".multiple-photo-disc i.fa-chevron-right").css("visibility","hidden").addClass("hide");
////                }
////            }
////        });  
//        $('.multiple-photo .slick-prev').text("Prev");
      }
  };
  
})(jQuery, Drupal, this, this.document);

     
