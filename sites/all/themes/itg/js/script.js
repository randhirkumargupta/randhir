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
    attach: function (context, settings) {

      jQuery('.add-more-block-front').live('click', function () {
        var section_ids = "";
        var elementobj = jQuery(this);
        jQuery(this).parent('.load-more-wrapper-front').addClass('new-load').html('<img src="./sites/all/themes/itg/images/tab-loading.gif" alt="" />')
        //jQuery(this).remove();
        jQuery('.sectioncart').each(function () {
          section_ids = jQuery(this).attr('id');
        });

        jQuery.ajax({
          url: Drupal.settings.basePath + 'gethomecarddata',
          type: 'post',
          beforeSend: function () {
            // jQuery('#widget-ajex-loader').show();
          },
          data: {'section_ids': section_ids, },
          success: function (data) {
            if (data == "")
            {
              jQuery('.no-more-card').show();
              jQuery('.new-load').hide();
            } else {
              jQuery('.new-load').hide();

              jQuery('#second-section-card').append(data);

            }
            elementobj.remove();
            //  alert(data);  

          },
          complete: function () {
          },
          error: function (xhr, desc, err) {
            console.log(xhr);
            console.log("Details: " + desc + "\nError:" + err);
          }
        });

      });
      jQuery('.add-more-block-front-section').live('click', function () {
        var section_ids = "";
        var elementobj = jQuery(this);
        jQuery(this).parent('.load-more-wrapper-front').addClass('new-load').html('<img src="./sites/all/themes/itg/images/tab-loading.gif" alt="" />')
        //jQuery(this).remove();
        jQuery('.sectioncart').each(function () {
          section_ids = jQuery(this).attr('id');
        });
        var getsectionid = jQuery(this).attr('section_id');
        jQuery.ajax({
          url: Drupal.settings.basePath + 'getsecttioncarddata',
          type: 'post',
          beforeSend: function () {
            // jQuery('#widget-ajex-loader').show();
          },
          data: {'section_ids': section_ids, getsectionid: getsectionid},
          success: function (data) {
            if (data == "")
            {
              jQuery('.no-more-card').show();
              jQuery('.new-load').hide();
            } else {
              jQuery('.new-load').hide();

              jQuery('#second-section-card').append(data);

            }
            elementobj.remove();
            //  alert(data);  

          },
          complete: function () {
          },
          error: function (xhr, desc, err) {
            console.log(xhr);
            console.log("Details: " + desc + "\nError:" + err);
          }
        });

      });
      jQuery('#question textarea.charcount').keyup(function () {
        if (jQuery(this).val().length > 160) {
          jQuery(this).val(jQuery(this).val().substring(0, 160));
          return false;
        } else {
          var value = 160 - jQuery(this).val().length;
          jQuery('#rest-char').html(value);
        }
      });
      // Place your code here.
      // Make unflag link unclickable
      if ($('a').hasClass('unflag-action')) {
        $('.page-node .unflag-action').attr('title', '');
        $('.page-node .unflag-action').css('pointer-events', 'none');
      }
      // Place average ratings to top of the page.
      if ($('body').hasClass('node-type-mega-review-critic')) {
        var average_ratings = $('#average-ratings').text();
        $('.movie-rating').attr('data-star-value', average_ratings);
        // Place internal and external review on black area.
        var internal_review = $('#internal-review').html();
        var external_review = $('#external-review').html();
        if (external_review != null) {
          $('.movie-reviewer-other').html('<h3>OTHER REVIEWERS</h3>' + external_review);
        } else {
          $('.movie-reviewer-other').remove();
        }
        if (internal_review != null) {
          $('.our-review').html('<h3>OUR REVIEWERS</h3>' + internal_review);
        } else {
          $('.our-review').remove();
        }
      }
      $('input.rating').hover(function () {
        $(this).parent().addClass('rating-hover').prevAll().addClass('rating-hover');
        $(this).parent().nextAll().removeClass('rating-hover');
      }, function () {
        $('.form-checkboxes.rating .form-type-checkbox').removeClass('rating-hover');
      });

      $('input.rating').click(function () {
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


      // jQuery Code for tabbing
      $('.tab-buttons').on('click', 'span', function () {
        var dataID = '.' + $(this).attr('data-id');
        $(this).addClass('active').siblings().removeClass('active');
        $(this).parent().parent().find(dataID).show().siblings('.tab-data').hide();
      });
      $('.tab-buttons').on('click', 'span a', function (e) {
        e.preventDefault();
      });
      // jQuery Code for tabbing End

      //ITG Listing top spacing          
      $('.tab-data').find('ul.itg-listing').css('padding-top', '0');

      //search page result
      var winWidth;
      $(".view-front-end-global-search").find("[class*='views-widget-filter-tm_vid'], #edit-tm-vid-14-names-wrapper, #edit-tm-vid-4-names-wrapper, #edit-sm-field-itg-common-by-line-name-wrapper, #edit-bundle-name-wrapper, #edit-hash-wrapper, .views-submit-button, .views-reset-button").wrapAll("<div class='searh-all-filters'></div>");
      $('.itg-search-list').each(function () {
        $(this).find('.search-pic').each(function () {
          var current = $(this);
          if (current.children().length == 0) {
            $(current).addClass("hide");
          }
        });
        winWidth = $(window).width();
        var currentSocial = $(this).children('.social-share');
        var currentInfo = $(this).children(".search-detail").children(".other-info");
        currentSocial.appendTo(currentInfo);
        if (winWidth < 768) {
          $(currentInfo).appendTo(this);
        }
      });

      //pagination
      $('.pager .pager-previous a').html('<i class="fa fa-chevron-left"></i>');
      $('.pager .pager-next a').html('<i class="fa fa-chevron-right"></i>');

      //video landing page UL width
      var videoNumber = $('#block-views-video-landing-header-block-1 .item-list ul li').length;
      $('#block-views-video-landing-header-block-1 .item-list ul').css('width', videoNumber * 170 + 'px');
      // Global function to set lable as input placeholder
      function placeHolder(element, parent) {
        $(element).each(function () {
          el = $(this);                                                                     //make a variable for this label
          el_for = el.attr('for');                                                          //get the value of the label attr for
          label_value = el.text();                                                          //get the value of the label
          el.hide();                                                                        //hide the label
          el_input = 'input[id=' + el_for + ']';                                                //get input element
          $(parent).find(el_input).attr('placeholder', $.trim(label_value));                //fill it with the label's value
        });
      }
      placeHolder('#edit-keyword-wrapper > label', '#edit-keyword-wrapper');


      // Open and Close popup jQuery on Order Summary page
      $('body').on('click', '#change-address', function () {
        $('body').find('#change-address-popup').show();
      });
      $('#change-address-popup').on('click', '.close-popup', function () {
        $(this).closest('#change-address-popup').hide();
      });

      // jQuery code to close cart dropdown popup
      $('body').on('click', '.cart-dropdown-close', function () {
        $(this).parent().hide();
      });
      // jQuery code to close activate message popup
      $('.activate-message').on('click', '.close-popup', function () {
        $(this).parent().parent().hide();
        window.location = window.location.href.split('?')[0];
      });

      // jQuery code to get url parameters
      var getUrlParameter = function getUrlParameter(sParam) {
        var sPageURL = decodeURIComponent(window.location.search.substring(1)),
                sURLVariables = sPageURL.split('&'),
                sParameterName,
                i;

        for (i = 0; i < sURLVariables.length; i++) {
          sParameterName = sURLVariables[i].split('=');

          if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : sParameterName[1];
          }
        }
      };
      var activate_account = getUrlParameter('active');
      if (activate_account) {
        $('.activate-message').show();
      }

      /* code to show change password popup */
      var change_password = getUrlParameter('pass');
      if (change_password) {
        $('.activate-message').show();
      }

      /* code to show change email mobile popup */
      var change_email_mobile = getUrlParameter('email');
      if (change_email_mobile) {
        $('.activate-message').show();
      }
      //jQuery('#main').find('img').parent().addClass('zoom-image');

      // jQuery code to set message error on my content page
      var my_content_error = jQuery('.page-personalization-my-content').find('.messages--error');
      if (my_content_error) {
        jQuery('.page-personalization-my-content #block-formblock-ugc').prepend(my_content_error);
      }
    }
  };


})(jQuery, Drupal, this, this.document);

//common function for mobile
function mobilecheck() {
  var check = false;
  (function (a) {
    if (/(android|ipad|playbook|silk|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(a) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0, 4)))
      check = true
  })(navigator.userAgent || navigator.vendor || window.opera);
  return check;
}
var is_mobile = mobilecheck() ? true : false;
//common function for mobile end


jQuery(document).ready(function () {
  
  var numLatestVideo = jQuery("#block-views-video-landing-header-block-1 ul.photo-list li").length;
  var winWidth = window.innerWidth;
  if (winWidth > 680) {
    var getLength = jQuery("#block-views-video-landing-header-block-1 ul.photo-list li").length;
    jQuery("#block-views-video-landing-header-block-1 ul.photo-list").css("width", getLength * 190 + "px");
    jQuery(".defalt-bar").mCustomScrollbar({
      axis: "x",
    });
  } else {
    if (numLatestVideo > 4) {
      jQuery("#block-views-video-landing-header-block-1 ul.photo-list").slick({
        vertical: true,
        infinite: false,
        slidesToShow: 4,
        dots: false,
        nextArrow: "<i class='fa fa-chevron-down'></i>",
        prevArrow: "<i class='fa fa-chevron-up'></i>"
      });
    } else {
      return false;
    }
  }

//  jQuery(".top_stories_ordering .block-itg-widget, .special-top-news").mousemove(function (e) {
//    var h = jQuery(this).height() + 13;
//    var offset = jQuery(this).offset();
//    var position = (e.pageY - offset.top) / jQuery(this).height();
//    if (position < 0.20) {
//      jQuery(this).stop().animate({scrollTop: 0}, 1000);
//    } else if (position > 0.70) {
//      jQuery(this).stop().animate({scrollTop: h}, 1000);
//    }
//  });

jQuery(".top_stories_ordering .data-holder").mCustomScrollbar();
jQuery(".special-top-news .itg-listing-wrapper").mCustomScrollbar();

//header menu add icon for mobile
  jQuery('.main-nav ul').prepend('<li class="desktop-hide"><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></li>');



//ITG footer
  footerMain();
  function footerMain() {
    //footer toggal script
    jQuery('.footer-expand-icon').click(function () {
      jQuery('.footer-toggle').slideToggle();
      jQuery("html, body").animate({scrollTop: jQuery(document).height()}, 800);
      jQuery('.footer-expand-icon').toggleClass('footer-open-icon');
    });
    //footer add more link
//        jQuery('.footer-bottom .cell ul').each(function () {
//            var countList = jQuery(this).children('li').length;
//            if (countList > 8) {
//                jQuery(this).find('li:gt(7)').hide().addClass('hidelist');
//                jQuery(this).append("<li><span class='more-link'>More</span></li>");
//            }
//        });
//        jQuery('.footer-bottom .more-link').click(function () {
//            jQuery(this).parents('ul').find('li.hidelist').slideToggle();
//            jQuery(this).toggleClass('active');
//            jQuery("html, body").animate({scrollTop: jQuery(document).height()}, 800);
//            if (jQuery(this).hasClass('active')) {
//                jQuery('.footer-bottom .more-link').text('Less');
//            } else {
//                jQuery('.footer-bottom .more-link').text('More');
//            }
//        });
  }
  jQuery('body').on('click', '.personal-share', function () {
    jQuery('.personal-social-share-links').slideToggle();
  });
});

jQuery(document).ready(function(){ 
  var getLength = 0;
  var defaultWidth  = jQuery(".anchor-detail-menu").outerWidth(true);
  jQuery(".anchor-detail-menu .tab-buttons span").each(function(){
      getLength += jQuery(this).outerWidth(true);                
  });                
  if(getLength > defaultWidth){
      jQuery(".anchor-detail-menu .tab-buttons").css("width", getLength +"px"); 
      jQuery(".anchor-detail-menu").mCustomScrollbar({
          axis:"x",                    
      });
  }
});

jQuery(document).ready(function () {
  var programData = ".view-live-tv-programs .program_data";
  var iconMinus = ".toggle-icon .minus";
  var iconPluse = ".toggle-icon .plus";
  if (jQuery(programData).is(":visible")) {
    jQuery(iconMinus).show();
  } else {
    jQuery(iconPluse).show();
  }
  jQuery(".toggle-icon").click(function () {
    var programRow = jQuery(this).parents(".program-row").next();
    if (programRow.is(":visible")) {
      programRow.slideUp();
      jQuery(this).find(".minus").hide();
      jQuery(this).find(".plus").show();
    } else {
      programRow.slideDown();
      jQuery(this).find(".minus").show();
      jQuery(this).find(".plus").hide();
    }
  });

  var winWidth = window.innerWidth;
  if (winWidth > 680) {
    var getLength = jQuery(".view-programme-content-live-tv .defalt-bar .photo-list li").length;
    jQuery(".view-programme-content-live-tv .defalt-bar .photo-list").css("width", getLength * 190 + "px");
    jQuery(".view-programme-content-live-tv .defalt-bar").mCustomScrollbar({
      axis: "x",
    });
  } else {
    jQuery(".view-programme-content-live-tv .defalt-bar .photo-list").slick({
      vertical: true,
      slidesToShow: 2,
      dots: false,
      nextArrow: "<i class=\'fa fa-chevron-down\'></i>",
      prevArrow: "<i class=\'fa fa-chevron-up\'></i>"
    });
  }
});


// code to copy serach text into search page
jQuery(document).ready(function () {

  var elmt = jQuery('.search-text');
  jQuery('.search-text').keypress(function (e) {
    el = jQuery(this);
    value = el.val();
    var code = e.keyCode || e.which;
    if ((value.length === 0 && code == 32)) {
      e.preventDefault();
    }
  });

  jQuery('.search-text').keyup(function (e) {
    el = jQuery(this);
    value = el.val();
    var code = e.keyCode || e.which;
    if (code == 13 && value.length != 0) { //Enter keycode
      //Do something
      //var urldata = Drupal.settings.basePath + 'topic?keyword=' + jQuery(this).val();
      var urldata = Drupal.settings.basePath + 'topic/' + jQuery(this).val();
      window.location.href = urldata;
    }
    if (value.length != 0) {
      el.closest('.search-icon-parent').find('.search-icon-search').show().prev().hide();

    } else {
      el.closest('.search-icon-parent').find('.search-icon-default').show().next().hide();
    }
  });
  jQuery('.search-icon-search').click(function () {
    search_value = jQuery(this).parent().find('.search-text').val();
    if (search_value.length != 0) {
      //var urldata = Drupal.settings.basePath + 'topic?keyword=' + search_value;
      var urldata = Drupal.settings.basePath + 'topic/' + search_value;
      window.location.href = urldata;
    }
  });

  headerMain();
  function headerMain() {
    //var logotxt = $('.container.header-logo').html();
    jQuery('.container.header-logo').prependTo('.itg-logo-container');

    var mouse_is_inside = false;
    jQuery('#header .search-icon-parent, #footer .search-icon-parent').hover(function () {
      mouse_is_inside = true;
    }, function () {
      mouse_is_inside = false;
    });

    jQuery("body").mouseup(function () {
      if (!mouse_is_inside) {
        jQuery('.search-icon-search').hide().prev().show();
        jQuery('.globle-search').removeClass('active');
      }
    });

    jQuery('.search-icon-default').click(function () {
      search_value = jQuery(this).parent().find('.search-text').val();
      if (search_value.length != 0) {
        jQuery(this).hide().next().show();
      }
      jQuery(this).parent().find('.globle-search').toggleClass('active');
    });

    jQuery('#block-itg-layout-manager-header-block .menu-login .user-menu').hover(function () {
      jQuery('#newlist').hide();
    });

    jQuery('.head-live-tv .mobile-user').click(function () {
      jQuery(this).next('ul.menu').toggle();
    });
  }

  //Add header for so-sorry page
  jQuery('#block-views-so-sorry-you-will-love-these ul.photo-list').before("<h2>YOU'LL <span>LOVE THESE</span></h2>");
  jQuery('#auto-new-block .widget-title, #tech-new-block .widget-title, #education-new-block .widget-title, #movie-new-block .widget-title, #defalt-section-top-block .widget-title').prependTo('.auto-block-2 .special-top-news');


  jQuery('.factoids-slider ul').slick({
    slidesToShow: 3,
    slidesToScroll: 1,
    infinite: false,
    centerPadding: '25px',
    prevArrow: "<button class = 'slick-prev'><i class = 'fa fa-angle-left'></i></button>",
    nextArrow: "<button class = 'slick-next'><i class = 'fa fa-angle-right'></i></button>",
    responsive: [
      {
        breakpoint: 768,
        settings: {
          slidesToShow: 2,
          centerPadding: '10px'
        }
      },
      {
        breakpoint: 480,
        settings: {
          slidesToShow: 1,
          centerPadding: '10px'
        }
      }
    ]
  });

  //jQuery code to set slider for story photo list
  jQuery('.story-photo-list').slick({
    slidesToShow: 3,
    slidesToScroll: 1,
    infinite: false,
    variableWidth: true,
    prevArrow: "<button class = 'slick-prev'><i class = 'fa fa-angle-left'></i></button>",
    nextArrow: "<button class = 'slick-next'><i class = 'fa fa-angle-right'></i></button>",
    responsive: [
      {
        breakpoint: 768,
        settings: {
          slidesToShow: 2,
          centerPadding: '10px'
        }
      },
      {
        breakpoint: 480,
        settings: {
          slidesToShow: 1,
          centerPadding: '10px'
        }
      }
    ]
  });

  var arrayOne = [];
  jQuery('.factoids-slider li').each(function () {
    var getHEight = jQuery(this).outerHeight(true);
    arrayOne.push(getHEight);
  });
  var largest = Math.max.apply(Math, arrayOne);
  jQuery(".factoids-slider li").css('height', largest + "px");

});

jQuery(window).load(function () {
  // jQuery code to set offset of photo section page
  var menuOffset = jQuery('.itg-region').offset();
  if (jQuery('.video_landing_menu li').children().hasClass('set-offset')) {
    jQuery("body,html").animate({scrollTop: menuOffset.top - 100}, 300);
  }
});

jQuery(document).ready(function () {
  //breaking news hide
  jQuery(".breaking-new-close").click(function () {
    jQuery(".breakingnew-home").slideUp();
  });

  var getmsgsaves = jQuery('.saved-photogallery').text();
  if (getmsgsaves != "")
  {
    jQuery('.saved-photogallery').remove();
    jQuery(".view-photo-landing-slider .slickslide li").append('<div class="saved-photogallery">Saved</div>');
    jQuery('.stryimg').prepend('<div class="saved-photogallery">Saved</div>');
    setTimeout(function () {
      jQuery('.saved-photogallery').remove();
    }, 3000);
  }
  jQuery('.block-itg-ads').each(function () {

    if (jQuery(this).html().trim().length == 0)
    {
      jQuery(this).remove();
    }

  })
  jQuery('#map-state').change(function () {
    jQuery('#consTable').hide();
    var getstate_id = jQuery(this).val();

    jQuery.ajax({
      url: Drupal.settings.basePath + 'get_map_data',
      type: 'post',
      beforeSend: function () {
        jQuery('#widget-ajex-loader').show();
      },
      data: {'state_id': getstate_id, },
      success: function (data) {
        var obj = jQuery.parseJSON(data);
        jQuery('#widget-ajex-loader').hide();
        if (obj.mapjson == '')
        {
          jQuery("#conssvg").html('Content Not Found');

        } else {
          getconssvg(obj, '0');
        }

      },
      complete: function () {
      },
      error: function (xhr, desc, err) {
        console.log(xhr);
        console.log("Details: " + desc + "\nError:" + err);
      }
    });
  });

//    //saved message
//    var getmsgsaves = jQuery('.saved-photogallery').text();
//    if (getmsgsaves != "") {
//        jQuery('.saved-photogallery').remove();
//        jQuery(".view-photo-landing-slider .slickslide li").append('<div class="saved-photogallery">' + getmsgsaves + '</div>');
//    }
//    setTimeout(function () {
//        jQuery('.saved-photogallery').remove();
//    }, 3000);

  //movie review more less
  jQuery('.other-reviews-desc .read-more').click(function () {
    jQuery(this).parents('.other-reviews-desc').find('.less-content').hide();
    jQuery(this).parents('.other-reviews-desc').find('.full-content').show();
  });

  jQuery('.other-reviews-desc .read-less').click(function () {
    jQuery(this).parents('.other-reviews-desc').find('.full-content').hide();
    jQuery(this).parents('.other-reviews-desc').find('.less-content').show();
  });

});



jQuery(document).ready(function () {
  var winWidth;
  jQuery('.mobile-nav i.fa').click(function () {
    if (jQuery(this).hasClass('fa-bars')) {
      jQuery(this).addClass('fa-times').removeClass('fa-bars');
      jQuery('.navigation').slideDown();

    } else {
      jQuery(this).addClass('fa-bars').removeClass('fa-times');
      jQuery('.navigation').slideUp();
    }
  });


  jQuery(document).on('click', '.all-menu', function () {
    jQuery('#newlist').slideToggle();
    jQuery('.third-level-menu #overflow').hide();
  });

  jQuery(document).on('click', function () {
    jQuery('#newlist').slideUp();
  });
  jQuery(document).on('click', '.all-menu', function (e) {
    e.stopPropagation();
  });

  //social share animation effects   
  jQuery('.social-share ul').each(function () {
    jQuery(this).children().not(":first").hide();
  });
  jQuery('.social-share li').click(function () {
    jQuery(this).find('.share').parent('li').nextAll('li').toggle();
  });

  //vertical menu position      
  /*var getNumberMenu = jQuery('.vertical-menu li').length;
   if (getNumberMenu > 6) {
   jQuery('.vertical-menu').slick({
   vertical: true,
   slidesToShow: 6,
   slidesToScroll: 2,
   infinite: false,
   nextArrow: '<span class="more"><i class="fa fa-chevron-down"></i> More</span>',
   prevArrow: '<span class="less"><i class="fa fa-chevron-up"></i> Less</span>',
   });
   jQuery(document).find('.vertical-menu span.less').hide();
   jQuery('.vertical-menu span.more').click(function () {
   jQuery('.vertical-menu span.less').show();
   });
   } else {
   return false;
   }*/

  var menuLength;
  jQuery(".vertical-menu").each(function () {
    menuLength = jQuery(this).find('li').length;
    if (menuLength > 5) {
      jQuery('.vertical-more').show();
    }
  });
  var calcNum = menuLength % 5;
  var divNum = parseInt(menuLength / 5);
  var count = 0;
  jQuery('.vertical-more a.more').click(function () {
    count++;
    if (count < divNum && calcNum != 0) {
      jQuery('.vertical-menu').css('margin-top', -375 * count + 'px');
    } else if (calcNum > 0 && count == divNum) {
      jQuery('.vertical-menu').css('margin-top', -(375 * (count - 1) + calcNum * 75) + 'px');
      jQuery('.vertical-more a.less').show();
      jQuery(this).hide();
    } else if (count < divNum && calcNum == 0) {
      jQuery('.vertical-menu').css('margin-top', -375 * count + 'px');
      jQuery('.vertical-more a.less').show();
      jQuery(this).hide();
    }
  });
  jQuery('.vertical-more a.less').click(function () {
    count = 0;
    jQuery('.vertical-menu').css('margin-top', '0px');
    jQuery('.vertical-more a.more').show();
    jQuery(this).hide();
  });
  jQuery('.page-user .form-submit').wrap('<div class="ripple-effect dib vtop"></div>');
  jQuery('.second-level-menu li, .itg-listing li, .tab-buttons span, .agbutton button').addClass('ripple-effect');
  jQuery(".ripple-effect").click(function (e) {

    // Remove any old one
    jQuery(".ripple").remove();

    // Setup
    var posX = jQuery(this).offset().left,
            posY = jQuery(this).offset().top,
            buttonWidth = jQuery(this).width(),
            buttonHeight = jQuery(this).height();

    // Add the element
    jQuery(this).prepend("<span class='ripple'></span>");

    // Make it round!
    if (buttonWidth >= buttonHeight) {
      buttonHeight = buttonWidth;
    } else {
      buttonWidth = buttonHeight;
    }

    // Get the center of the element
    var x = e.pageX - posX - buttonWidth / 2;
    var y = e.pageY - posY - buttonHeight / 2;

    // Add the ripples CSS and start the animation
    jQuery(".ripple").css({
      width: buttonWidth,
      height: buttonHeight,
      top: y + 'px',
      left: x + 'px'
    }).addClass("rippleEffect");
  });


  if (is_mobile) {
    // third-level-menu on mobile
    var tlmenu = jQuery('#block-itg-menu-manager-third-level-menu .select-menu');
    tlmenu.click(function () {
      jQuery('.mobile-nav .fa-times').trigger('click');
      jQuery(this).next('ul').stop().slideToggle();
    });
    jQuery(document).on('click', function () {
      jQuery('#block-itg-menu-manager-third-level-menu ul.third-level-menu').slideUp();
      ;
    });
    tlmenu.click(function (e) {
      e.stopPropagation();
    });

    // jQuery code to set personalization tab in mobile
    jQuery('body').on('click', '.personal-menu-tab-mobile', function () {
      jQuery(this).next().slideToggle();
    });
    jQuery('.personal-menu-tab').on('click', 'li', function () {
      var el = $(this);
      var get_class = el.attr('class'), get_text = el.find('a').text();
      el.closest('.personal-menu-tab-wrapper').find('.tab-text').attr('data-tab', get_class).text(get_text);
      el.parent().slideUp('fast');
    });

    // jQuery code for personalization saved item on mobile
    jQuery('body').on('touchend', '.personal-action', function () {
      jQuery(this).parent().parent().siblings().find('.personal-action').css('opacity', '0');
      jQuery(this).css('opacity', '1');
    });

    //event page navigation
    jQuery('#block-menu-menu-event-menu a.mobile-nav').click(function () {
      jQuery('#block-menu-menu-event-menu ul.menu').slideToggle();
    });
    jQuery('.event-search-icon').click(function () {
      jQuery('.event-search input').css('width', '180px');
    });
    jQuery(document).on('click touchstart', function () {
      jQuery('.event-search input').css('width', '0px');
    });
    jQuery('.event-search-icon, .event-search input').click(function (e) {
      e.stopPropagation();
    });

    //for iphone zoom page
    document.addEventListener('gesturestart', function (e) {
      e.preventDefault();
    });
  }

  //story page social share for mobile
  var getclick;
  jQuery('.comment-mobile .share-icon').toggle(function () {
    getclick = jQuery(this).parents('.comment-mobile').find('.social-share');
    getclick.css({'display': 'inline-block'});
  }, function () {
    getclick.css({'display': 'none'});
  });

  // jQuery code to add Light off/on effect 
  jQuery('body').on('click', '.light-off-on-tab', function () {
    jQuery('body').toggleClass('light-off-overlay');
    jQuery('.program-livetv').toggleClass('effect-added');
  });

  //footer css slider start
  jQuery('.multiple-items-footer').slick({
    infinite: false,
    slidesToShow: 6,
    slidesToScroll: 1,
    variableWidth: true,
    prevArrow: '<i class="fa fa-chevron-left slick-prev" aria-hidden="true"></i>',
    nextArrow: '<i class="fa fa-chevron-right slick-next" aria-hidden="true"></i>',
    responsive: [
      {
        breakpoint: 1024,
        settings: {
          slidesToShow: 4
        }
      },
      {
        breakpoint: 680,
        settings: {
          slidesToShow: 3
        }
      },
      {
        breakpoint: 480,
        settings: {
          slidesToShow: 2
        }
      }
    ]
  });
  //footer css slider end
  jQuery('.emoji-container a').click(function () {
    var datavalue = jQuery(this).attr('data-click');
    if (datavalue === 'nice') {
      smilyanimation('smily');
    } else if (datavalue === 'no') {
      smilyanimation('smilysad');
    } else if (datavalue === 'whatever') {
      smilyanimation('wgmf');
    }
  });
  // jQuery code to show embed code popup
  jQuery('.show-embed-code-link').on('click', '.embed-link', function () {
    jQuery(this).toggleClass('active');
    jQuery(this).next('.show-embed-code-div').stop().fadeToggle();
  });
});

//emoji animation     
function smilyanimation(facetype) {
  var faceone = jQuery('#' + facetype + ' .face1');
  var facetwo = jQuery('#' + facetype + ' .face2');
  var facethree = jQuery('#' + facetype + ' .face3');
  var facefour = jQuery('#' + facetype + ' .face4');
  jQuery('#' + facetype).fadeIn(function () {
    faceone.animate({top: '100px', left: '800px'}, 3000);
    facetwo.animate({top: '300px', left: '600px'}, 3000);
    facethree.animate({top: '600px', right: '800px'}, 3000);
    facefour.animate({top: '400px', right: '400px'}, 3000, function () {
      jQuery('#' + facetype).fadeOut(500, function () {
        faceone.css({top: '500px', left: '400px'});
        facetwo.css({top: '0px', left: '200px'});
        facethree.css({top: '0px', right: '200px'});
        facefour.css({top: '100px', right: '600px'});
      });
    });
  });
}

var menuBuilder = function () {
  var menuWidth, Totalwidth, liLength, clickHere;
  menuWidth = jQuery('.second-level-menu.menu').width() - 46;
  Totalwidth = jQuery('.all-menu').outerWidth(true);
  clickHere = 0;
  if (jQuery('#newlist').length > 0) {
    jQuery('#newlist').html('');
  }
  jQuery('.all-menu').remove();
  jQuery('.second-level-menu.menu li').each(function () {
    liLength = jQuery(this).outerWidth(true);
    Totalwidth = Totalwidth + liLength;
    if (Totalwidth <= menuWidth) {
      jQuery(this).removeClass('hide');
    } else {
      if (jQuery('.all-menu').length === 0) {
        jQuery(this).after('<li class="all-menu"><a class="" href="javascript:void(0)"><i class="fa fa-circle"></i> <i class="fa fa-circle"></i> <i class="fa fa-circle"></i></li>');
        clickHere = 1;
      }
      if (jQuery('#newlist').length === 0) {
        jQuery('.navigation .container').append('<ul id="newlist" class="menu"></ul>');
      }
      var html = '<li>' + jQuery(this).html() + '</li>';
      jQuery('#newlist').append(html);
      jQuery(this).addClass('hide');
      //postion
      var posAllmenu = jQuery('.all-menu').position();
      jQuery('body').find('#newlist').css('left', posAllmenu.left - 39 + 'px');
    }
  });

};

jQuery(window).load(function () {
  winWidth = jQuery(window).width();
  if (winWidth > 770) {
    jQuery('body').find('.second-level-menu').removeClass('before-load');
    menuBuilder();
    jQuery(window).resize(menuBuilder);
  }
});

jQuery(document).ready(function () {

  jQuery("#mn_img a").click(function (e) {
    e.preventDefault();
  });

  jQuery("#mn_img .thumbnail").click(function (e) {
    e.preventDefault();
    var idx = jQuery(this).parents('div').index();
    var id = parseInt(idx);
    jQuery('.modal_embed').modal('show');
    jQuery('#modalCarousel').carousel(id);
  });

  jQuery('.pos_rel .seemore').click(function () {
    jQuery(this).remove();
    jQuery('.glr').removeClass('hd1');

  });

  jQuery('#modalCarousel').carousel({interval: false});

  jQuery('#modalCarousel').on('slid.bs.carousel', function () {
    jQuery('.modal-title').html(jQuery(this).find('.active').attr("title"));
    jQuery('.modal-content .seemore').remove();
  });

  jQuery('.dtv ul li').click(function () {
    var at = jQuery(this).children('img').attr("pr");
    var img_src = jQuery(this).children('img').attr('src');
    jQuery('.active > a > img').attr({'src': img_src});
  });

  jQuery(window).bind({
    'load': setSidebarHeight,
    'scroll': setSidebarHeight,
    'resize': setSidebarHeight
  });

  jQuery(window).load(function () {
    var sticky = jQuery('.region-vertical-menu');
    var sticky_sidebar = jQuery('.region-sidebar-second');
    sticky.stickyMojo({footerID: '#footer', contentID: '#main'});
    sticky_sidebar.stickyMojo({footerID: '#footer', contentID: '#main'});
  });
});

jQuery(document).ready(function (e) {
  jQuery('.itg-embed-photo-slider').slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    adaptiveHeight: true,
    arrows: true,
    fade: false,
    asNavFor: '.itg-embed-photo-thumb-slider'
  });
  jQuery('.itg-embed-photo-thumb-slider').slick({
    slidesToShow: 7,
    slidesToScroll: 1,
    asNavFor: '.itg-embed-photo-slider',
    dots: false,
    centerMode: false,
    arrows: true,
    focusOnSelect: true,
    responsive: [
      {
        breakpoint: 1024,
        settings: {
          slidesToShow: 7,
          slidesToScroll: 1,
          arrows: false
        }
      },
      {
        breakpoint: 600,
        settings: {
          slidesToShow: 4,
          arrows: false,
          slidesToScroll: 1
        }
      },
      {
        breakpoint: 480,
        settings: {
          slidesToShow: 3,
          arrows: false,
          slidesToScroll: 1
        }
      }
    ]
  });
});
function setSidebarHeight() {
  var sticky_sidebar = jQuery('.region-sidebar-second');
  var sticky_sidebar_height = sticky_sidebar.outerHeight(true);
  sticky_sidebar.closest('.sidebars').css('height', sticky_sidebar_height);
}


jQuery(window).load(function () {

  $navWidth = jQuery('.third-level-menu').width();
  navItemWidth = 0;
  $navItems = jQuery('.third-level-menu > li:not(.more)');
  $navItems.each(function () {
    navItemWidth += jQuery(this).width();
  });
  if (navItemWidth > $navWidth) {
    jQuery('.third-level-menu').append('<li class="more"> <span><i class="fa fa-circle"></i><i class="fa fa-circle"></i><i class="fa fa-circle"></i></span><ul id="overflow"></ul></li>');
    navigationResize();
  }

  jQuery('.third-level-menu li.more span').click(function (e) {
    jQuery(this).next().stop().slideToggle();
    e.stopPropagation();
  });
  jQuery(document).on('click', function () {
    jQuery('.third-level-menu #overflow').hide();
  });

});
window.onresize = navigationResize;

function navigationResize() {
  jQuery('.third-level-menu li.more').before(jQuery('#overflow > li'));

  var $navItemMore = jQuery('.third-level-menu > li.more'),
          $navItems = jQuery('.third-level-menu > li:not(.more)'),
          navItemMoreWidth = navItemWidth = $navItemMore.width(),
          windowWidth = jQuery('.third-level-menu').width(),
          navItemMoreLeft, offset, navOverflowWidth;

  $navItems.each(function () {
    navItemWidth += jQuery(this).width();
  });

  navItemWidth > windowWidth ? $navItemMore.show() : $navItemMore.hide();

  while (navItemWidth > windowWidth) {
    navItemWidth -= $navItems.last().width();
    $navItems.last().prependTo('#overflow');
    $navItems.splice(-1, 1);
  }

}
