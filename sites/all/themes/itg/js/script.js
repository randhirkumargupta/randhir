/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // Place your code here.
    $('input.rating').hover(function(){
    $(this).parent().addClass('rating-hover').prevAll().addClass('rating-hover');
    $(this).parent().nextAll().removeClass('rating-hover');
  }, function(){
    $('.form-checkboxes.rating .form-type-checkbox').removeClass('rating-hover');
  });
  
  $('input.rating').click(function(){
    $(this).parent().addClass('rated-div current-rating').prevAll().addClass('rated-div');
    $(this).parent().nextAll().removeClass('rated-div current-rating').find('input[type="checkbox"]').attr('checked', false);
    $('.rated-div').find('input[type="checkbox"]').attr('checked', true);
  });
  
  $('.survey-submit, .survey-submit-skip').mousedown(function(){
    var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
    var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
    var textValue = $(this).parents('.question-container').find('.form-text').val();
    var skipValue = $(this).parents('.question-container').find('.question-skip').val();
    var surveyTaken = $('body').find('input[name="survey_taken"]').val();
    
    if(checkValue && skipValue == 'no' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
    if(radioValue && skipValue == 'no' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
    if(textValue  && skipValue == 'no' && textValue != 'undefined' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes' && surveyTaken == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
  });
  
  var loader = '<div class="ajax-loader"><img src="sites/all/themes/rubik/images/loader.svg" alt=""/></div>';
  
  $('#itg-survey-survey-form .button-yes').mousedown(function(){
    var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
    var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
    var textValue = $(this).parents('.question-container').find('.form-text').val();
    var skipValue = $(this).parents('.question-container').find('.question-skip').val();
    
    if(checkValue && skipValue == 'no'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
      
    } else if(skipValue == 'yes'){
     $('.question-container').hide();
     $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
    
    if(radioValue && skipValue == 'no'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    } else if(skipValue == 'yes'){
     $('.question-container').hide();
     $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
    
    if(textValue  && skipValue == 'no' && textValue != 'undefined'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    } else if(skipValue == 'yes'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
  });
  
  
  $('.image-widget').each(function () {
      var filename = $(this).find('.file').html();
      var filesize = $(this).find('.file-size').html();
      var fullname = filename + filesize;
      if (!($(this).find('.image-preview').children().hasClass('image-fullname'))) {
        $(this).find('.image-preview').append('<div class="image-fullname">' + fullname + '</div>');
      }
      $(this).find('.image-widget-data .file, .image-widget-data .file-size').remove();
    });
    $('.image-widget-data').find('.form-text').each(function () {
      var plaholderText = $(this).prev().text();
      $(this).attr('placeholder', plaholderText);
      $(this).prev('label').hide();
    });
    
    headerMain();
    function headerMain(){
        $('.search-icon').click(function(){
            $('.globle-search').css('right','40px');
        });
        $('.main-nav ul').prepend('<li class="desktop-hide"><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></li>');
        $('.mobile-nav').click(function(){
            $('.navigation').stop().slideToggle();
        });        
    }
    
    footerMain();
    function footerMain(){
    //footer toggal script
    $('.footer-expand-icon').click(function(){
        $('.footer-toggle').slideToggle();
        $("html, body").animate({ scrollTop: $(document).height() }, 800);
        $('.footer-expand-icon').toggleClass('footer-open-icon');
    });
    //footer add more link
    $('.footer-bottom .cell ul').each( function(){
        var countList = $(this).children('li').length;        
        if(countList > 8){
           $(this).find('li:gt(7)').hide().addClass('hidelist');
           $(this).append("<li><span class='more-link'>More</span></li>");
        }
    });
    $('.more-link').click(function(){
        $(this).parents('ul').find('li.hidelist').slideToggle();
        $("html, body").animate({ scrollTop: $(document).height() }, 800);
        $('.more-link').text('Less');
    });
    }
  }
};


})(jQuery, Drupal, this, this.document);
