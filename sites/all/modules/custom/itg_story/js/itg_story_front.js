/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
  Drupal.behaviors.itg_story_front = {
      attach: function(context, settings) {
        //var uid = settings.itg_story.settings.uid;
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
        var maxValueInArray = $('.multiple-photo-disc .photo-slider').length;         
        $('.multiple-photo-disc').on('afterChange', function(event, slick, currentSlide){               
            if(currentSlide === maxValueInArray-1){
                window.location.href = 'http://www.google.com';
            }
        });             
        var maxValueInArray = $('.multiple-photo .photo-slider').length;         
        $('.multiple-photo').on('afterChange', function(event, slick, currentSlide) {               
            if(currentSlide === maxValueInArray-1){
                window.location.href = 'https://in.yahoo.com/';
            }
        });  
        $('.multiple-photo .slick-prev').text("Prev");
      }
  };
  
})(jQuery, Drupal, this, this.document);

     
