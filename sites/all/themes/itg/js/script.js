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
        //var logotxt = $('.container.header-logo').html();
        $('.container.header-logo').prependTo('#block-itg-layout-manager-header-block');
        $('.search-icon').click(function(){
            $('.globle-search').css('width','255px');
        });
        $('.main-nav ul').prepend('<li class="desktop-hide"><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></li>');
        $('.mobile-nav').click(function(){
            $('.navigation').stop().slideToggle();
        });
        $(document).on('click', function(){            
            $('.globle-search').css('width','0px');
        });
        $('.search-icon, .globle-search').click(function(e){
            e.stopPropagation();
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
        $(this).toggleClass('active');
        $("html, body").animate({ scrollTop: $(document).height() }, 800);
        if($(this).hasClass('active')){
            $('.more-link').text('Less');
        } else{
            $('.more-link').text('More');
        }
    });
    }
    // jQuery Code for tabbing
    $('.tab-buttons').on('click', 'span', function(){
      var dataID = '.' + $(this).attr('data-id');
      $(this).addClass('active').siblings().removeClass('active');
      $(this).parent().parent().find(dataID).show().siblings('.tab-data').hide();
    });
    // jQuery Code for tabbing End
    
    //ITG Listing top spacing          
    $('.tab-data').find('ul.itg-listing').css('padding-top','0');
        
    //pagination
    $('.pager .pager-previous a').html('<i class="fa fa-chevron-left"></i>');
    $('.pager .pager-next a').html('<i class="fa fa-chevron-right"></i>');
    
    //video landing page UL width
    var videoNumber = $('#block-views-video-landing-header-block-1 .item-list ul li').length;    
    $('#block-views-video-landing-header-block-1 .item-list ul').css('width', videoNumber*170+'px');
    // Global function to set lable as input placeholder
    function placeHolder(element, parent){
      $(element).each(function(){
        el = $(this);                                                                     //make a variable for this label
        el_for = el.attr('for');                                                          //get the value of the label attr for
        label_value = el.text();                                                          //get the value of the label
        el.hide();                                                                        //hide the label
        el_input = 'input[id='+el_for+']';                                                //get input element
        $(parent).find(el_input).attr('placeholder', $.trim(label_value));                //fill it with the label's value
      });
    }
    placeHolder('#edit-keyword-wrapper > label', '#edit-keyword-wrapper');
    
  }
};


})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function () {
    jQuery(".top_stories_ordering .block-itg-widget").mousemove(function (e) {
        var h = jQuery(this).height() + 13;
//        alert(h);
        var offset = jQuery(this).offset();
        var position = (e.pageY - offset.top) / jQuery(this).height();
        if (position < 0.20) {

            jQuery(this).stop().animate({scrollTop: 0}, 1000);
        }
        else if (position > 0.70) {

            jQuery(this).stop().animate({scrollTop: h}, 1000);
        }
        else
        {
//            jQuery(this).stop();
        }
    });


});


// code to copy serach text into search page
jQuery(document).ready(function () {

    jQuery('.search-text').keyup(function (e) {

        var code = e.keyCode || e.which;

        if (code == 13) { //Enter keycode
            //Do something
            var urldata = Drupal.settings.basePath + 'site-search?keyword=' + jQuery(this).val();
            window.location.href = urldata;
        }

    })


});
