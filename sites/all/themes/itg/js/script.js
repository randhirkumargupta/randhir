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
    // Make unflag link unclickable
    if ($('a').hasClass('unflag-action')) {
        $('.page-node .unflag-action').attr('title', '');
        $('.page-node .unflag-action').css('pointer-events', 'none');
    }    
    
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
        $('.container.header-logo').prependTo('.itg-logo-container');
        $('.search-icon').click(function(){
            $(this).parents('div').find('.globle-search').css('width','255px');
        });
        
        
        $(document).on('click', function(){            
            $('.globle-search').css('width','0px');
        });
        $('.search-icon, .globle-search').click(function(e){
            e.stopPropagation();
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

     //search page result
     var winWidth;
    $(".view-front-end-global-search").find("#edit-tm-vid-4-names-wrapper, #edit-sm-field-itg-common-by-line-name-wrapper, #edit-bundle-name-wrapper, #edit-hash-wrapper, .views-submit-button, .views-reset-button").wrapAll("<div class='searh-all-filters'></div>");
    $('.itg-search-list').each(function(){
        $(this).find('.search-pic').each(function(){
            var current = $(this);        
            if(current.children().length == 0){          
              $(current).addClass("hide"); 
            }
        });      
        winWidth = $(window).width();
        var currentSocial = $(this).children('.social-share');
        var currentInfo = $(this).children(".search-detail").children(".other-info"); 
        currentSocial.appendTo(currentInfo);
        if(winWidth < 768){
            $(currentInfo).appendTo(this);
        }
    });
        
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
    
    
    // Open and Close popup jQuery on Order Summary page
    $('body').on('click', '#change-address', function(){
      $('body').find('#change-address-popup').show();
    });
    $('#change-address-popup').on('click', '.close-popup', function(){
      $(this).closest('#change-address-popup').hide();
    });
    
    // jQuery code to close cart dropdown popup
    $('body').on('click', '.cart-dropdown-close', function(){
      $(this).parent().hide();
    });
  }
};


})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function () {
    jQuery(".top_stories_ordering .block-itg-widget, .special-top-news").mousemove(function (e) {        
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
    });
    
//header menu add icon for mobile
//jQuery('.main-nav ul').prepend('<li class="desktop-hide"><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></li>');
//    var navValue = jQuery('.navigation .menu li').length;
//    if (navValue > 13) {
//        jQuery('.navigation .menu li').eq(12).after('<li class="all-menu"><a class="" href="javascript:void(0)"><i class="fa fa-ellipsis-h"></i></li>');
//        var count_li = 0;
//        var i = 1;
//        jQuery('.navigation .menu li').each(function () {
//            count_li++;            
//            if (count_li > 14 && i == 1) {
//                jQuery('.navigation .container').append('<ul id="newlist"></ul>');
//                jQuery('#newlist').append(jQuery(this).nextUntil(jQuery(this).last()).andSelf());
//                i++;
//            }
//        });
//    }
    
    jQuery(document).on('click','.all-menu', function(){
        jQuery('#newlist').slideToggle();
    });
    jQuery('.mobile-nav').click(function(){              
        jQuery('.navigation').slideToggle();
    });
    
//ITG footer
footerMain();
    function footerMain(){
    //footer toggal script
    jQuery('.footer-expand-icon').click(function(){
        jQuery('.footer-toggle').slideToggle();
        jQuery("html, body").animate({ scrollTop: jQuery(document).height() }, 800);
        jQuery('.footer-expand-icon').toggleClass('footer-open-icon');
    });
    //footer add more link
    jQuery('.footer-bottom .cell ul').each( function(){
        var countList = jQuery(this).children('li').length;        
        if(countList > 8){
           jQuery(this).find('li:gt(7)').hide().addClass('hidelist');
           jQuery(this).append("<li><span class='more-link'>More</span></li>");
        }
    });
   jQuery('.footer-bottom .more-link').click(function(){
        jQuery(this).parents('ul').find('li.hidelist').slideToggle();
        jQuery(this).toggleClass('active');
        jQuery("html, body").animate({ scrollTop: jQuery(document).height() }, 800);
        if(jQuery(this).hasClass('active')){
            jQuery('.footer-bottom .more-link').text('Less');
        } else{
            jQuery('.footer-bottom .more-link').text('More');
        }
    });
    }
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

    });
    
//    jQuery(window).scroll(function () {
//      var winH = jQuery(window).height() + jQuery('#footer').height() + 40;
//      var docH = jQuery(document).height();
//      var targetH = docH - winH;
//      var scrollH = jQuery(window).scrollTop();
//      if(scrollH >= targetH) {
//        console.log(scrollH + "==" + targetH);
//           jQuery('.load-more').show();
//      }
//    });
    
    //Add header for so-sorry page
    jQuery('#block-views-so-sorry-you-will-love-these ul.photo-list').before("<h2>YOU'LL <span>LOVE THESE</span></h2>");
   jQuery('#auto-new-block .widget-title, #tech-new-block .widget-title, #education-new-block .widget-title, #movie-new-block .widget-title').prependTo('.auto-block-2 .special-top-news');
    
    
    
    
  });

jQuery(window).load(function () {
    // jQuery code to set offset of photo section page
    var menuOffset = jQuery('.itg-region').offset();
    if (jQuery('.video_landing_menu li').children().hasClass('set-offset')) {
        jQuery("body,html").animate({scrollTop: menuOffset.top - 100}, 300);
    }      
});



jQuery(document).ready(function () {    
    jQuery('.mobile-nav').click(function () {
        jQuery('.navigation').slideToggle();
    });    
    jQuery(document).on('click', '.all-menu', function () {
        if(jQuery('#newlist').is(':visible')){
            jQuery('#newlist').stop().slideDown();
        }else{
            jQuery('#newlist').stop().slideUp();
        }        
    });
    
    var menuBuilder = function(){        
        var menuWidth, Totalwidth, liLength, clickHere;
	menuWidth = jQuery('.second-level-menu.menu').width();	        
	Totalwidth = jQuery('.all-menu').outerWidth();
	clickHere = 0;
	if(jQuery('#newlist').length > 0){
            jQuery('#newlist').html('');
	}
	jQuery('.all-menu').remove();
	jQuery( '.second-level-menu.menu li' ).each(function(){
		liLength = jQuery(this).outerWidth(true);            
		Totalwidth = Totalwidth + liLength;	                
		if(Totalwidth <= menuWidth){                    
                    jQuery(this).removeClass('hide');                    
		}else{                    
                    if(jQuery('.all-menu').length===0){
                        jQuery(this).after('<li class="all-menu"><a class="" href="javascript:void(0)"><i class="fa fa-circle"></i> <i class="fa fa-circle"></i> <i class="fa fa-circle"></i></li>');
                        clickHere=1;
                    }
                    if(jQuery('#newlist').length===0){
                        jQuery('.navigation .container').append('<ul id="newlist" class="menu"></ul>');
                    }
                    var html='<li>'+jQuery(this).html()+'</li>';
                    jQuery('#newlist').append(html);
                    jQuery(this).addClass('hide');
		}
	});        
    };
    jQuery(window).resize(menuBuilder);
    menuBuilder();    
});





