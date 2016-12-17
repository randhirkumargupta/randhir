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
                jQuery(this).parent('.load-more-wrapper-front').addClass('new-load').html('<img src="./sites/all/themes/itg/images/tab-loading.gif"/>')
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
                }
                else {
                    $('.movie-reviewer-other').remove();
                }
                if (internal_review != null) {
                    $('.our-review').html('<h3>OUR REVIEWERS</h3>' + internal_review);
                }
                else {
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

            headerMain();
            function headerMain() {

                //var logotxt = $('.container.header-logo').html();
                $('.container.header-logo').prependTo('.itg-logo-container');
                $('.search-icon').click(function () {
                    $(this).parents('div').find('.globle-search').css('width', '255px');
                });


                $(document).on('click', function () {
                    $('.globle-search').css('width', '0px');
                });
                $('.search-icon, .globle-search').click(function (e) {
                    e.stopPropagation();
                });
                
                $('#block-itg-layout-manager-header-block .menu-login .user-menu').hover(function(){                    
                    $('#newlist').hide();
                });
                
            }

            // jQuery Code for tabbing
            $('.tab-buttons').on('click', 'span', function () {
                var dataID = '.' + $(this).attr('data-id');
                $(this).addClass('active').siblings().removeClass('active');
                $(this).parent().parent().find(dataID).show().siblings('.tab-data').hide();
            });
            // jQuery Code for tabbing End

            //ITG Listing top spacing          
            $('.tab-data').find('ul.itg-listing').css('padding-top', '0');

            //search page result
            var winWidth;
            $(".view-front-end-global-search").find("#edit-tm-vid-4-names-wrapper, #edit-sm-field-itg-common-by-line-name-wrapper, #edit-bundle-name-wrapper, #edit-hash-wrapper, .views-submit-button, .views-reset-button").wrapAll("<div class='searh-all-filters'></div>");
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
        }
    };


})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function () {
    jQuery('#main').find('img').parent().addClass('zoom-image');
    jQuery(".top_stories_ordering .block-itg-widget, .special-top-news").mousemove(function (e) {
        var h = jQuery(this).height() + 13;
//        alert(h);
        var offset = jQuery(this).offset();
        var position = (e.pageY - offset.top) / jQuery(this).height();
        if (position < 0.20) {
            jQuery(this).stop().animate({scrollTop: 0}, 1000);
        } else if (position > 0.70) {
            jQuery(this).stop().animate({scrollTop: h}, 1000);
        }
    });

//header menu add icon for mobile
    jQuery('.main-nav ul').prepend('<li class="desktop-hide"><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></li>');
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
        jQuery('.footer-bottom .cell ul').each(function () {
            var countList = jQuery(this).children('li').length;
            if (countList > 8) {
                jQuery(this).find('li:gt(7)').hide().addClass('hidelist');
                jQuery(this).append("<li><span class='more-link'>More</span></li>");
            }
        });
        jQuery('.footer-bottom .more-link').click(function () {
            jQuery(this).parents('ul').find('li.hidelist').slideToggle();
            jQuery(this).toggleClass('active');
            jQuery("html, body").animate({scrollTop: jQuery(document).height()}, 800);
            if (jQuery(this).hasClass('active')) {
                jQuery('.footer-bottom .more-link').text('Less');
            } else {
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
   jQuery('.block-itg-ads').each(function(){
       
       if(jQuery(this).html().trim().length==0)
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
    jQuery('.mobile-nav').click(function () {
        jQuery('.navigation').slideToggle();
    });
    jQuery(document).on('click', '.all-menu', function () {
        jQuery('#newlist').slideToggle();
    });
    var menuBuilder = function () {
        var menuWidth, Totalwidth, liLength, clickHere;
        menuWidth = jQuery('.second-level-menu.menu').width() - 10;
        Totalwidth = jQuery('.all-menu').outerWidth();
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
    winWidth = jQuery(window).width();
    if (winWidth > 770) {
        jQuery(window).resize(menuBuilder);
        menuBuilder();
    }    
    jQuery(document).on('click', function () {
        jQuery('#newlist').slideUp();
    });
    jQuery(document).on('click', '.all-menu', function (e) {
         e.stopPropagation();
    });
    

    var eventMenu = function () {
        winWidth = jQuery(window).width();
        if (winWidth < 1024) {
            jQuery('#block-menu-menu-event-menu').prepend('<div><a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a></div>');
            jQuery('#block-menu-menu-event-menu a.mobile-nav').click(function () {
                jQuery('#block-menu-menu-event-menu ul.menu').slideToggle();
            });
        }
    };
    eventMenu();

    //social share animation effects   
    jQuery('.social-share ul').each(function () {
        jQuery(this).children().not(":first").hide();
    })
    jQuery('.social-share li').click(function () {
        jQuery(this).nextAll('li').show();
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
   var el = jQuery('#block-itg-menu-manager-vertical-menu');
    var totlWidth = jQuery(window).width();
    var finalWidth = (totlWidth - 1170) / 2 ;
    el.css('left', finalWidth - 70 + 'px');        
     if (el.length) { 
      //var stickyTop = el.offset().top; 
      var stickyHeight = el.height();

      jQuery(window).scroll(function(){ 
          var limit = jQuery('footer').offset().top - stickyHeight - 20;
          var flimit = limit - 375;          
          var windowTop = jQuery(window).scrollTop();           
        if(windowTop > flimit){            
               el.css({
                   'position': 'absolute',
                   'left': -55 + 'px',
                   'top': flimit - 175 + 'px'
               })   
        }
        else{
            el.css({
                   'position': 'fixed',
                   'left': finalWidth - 70 + 'px',
                   'top': 270 + 'px'
               })
        }
        });
   }
    
    
    var menuLength  = jQuery('.vertical-menu li').length;
    if (menuLength > 5) {
        jQuery('.vertical-more').show();
    }   
    var calcNum = menuLength % 5;
    var divNum = parseInt(menuLength/5);    
    var count = 0;
    jQuery('.vertical-more a.more').click(function () {
        count ++;        
        if(count < divNum && calcNum !=0) {
            jQuery('.vertical-menu').css('margin-top', - 375 * count + 'px');
        }else if(calcNum > 0 && count == divNum){
            jQuery('.vertical-menu').css('margin-top', - (375 * (count-1) + calcNum * 75) + 'px');
            jQuery('.vertical-more a.less').show();
            jQuery(this).hide(); 
        }else if(count < divNum && calcNum == 0){
            jQuery('.vertical-menu').css('margin-top', - 375 * count + 'px');
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
});





