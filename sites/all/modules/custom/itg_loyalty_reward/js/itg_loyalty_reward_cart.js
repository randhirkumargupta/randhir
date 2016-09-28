/** 
 * @file
 *   Shopping kart js.
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_loyalty_reward = {
        attach: function (context, settings) {
            // Module code start.
            // Code for redeem points page.
            if ($('body').hasClass('page-redeem-points')) {
                var mid = Drupal.settings.itg_loyalty_reward.mid;
                var base_url = Drupal.settings.itg_loyalty_reward.base_url;
                $.each(mid, function (index, value) {
                    $('.' + value).parent().html('<div class="' + value + '" ><a href="' + base_url + '/cart">GO TO CART</a></div');
                    $('.' + value).parent().parent().find('.redeem-point a').attr('href', 'cart');
                });
            }
            
            // Code to show detail popup
            $('.view-redeem-points').on('click', '.product-pic', function(){
              var pic = $(this).html();
              var added_on = "April 25, 216";
              var title = $(this).siblings('.product-title').html();
              var desc = "Cras ex mauris; euismod vitae hendrerit ac, molestie nec mi. Vestibulum felis nisl; volutpat eget nisl nec, accumsan ultricies turpis. Donec et lectus ut ex maximus aliquam vel non nulla.";
              var redeem_points = $(this).siblings('.redeem-points').html();
              var actions = $(this).siblings('.product-actions').html();
              var popup_html = '<div class="cart-popup-wrapper">\n\
                                <div class="cart-popup"><a class="cart-close" href="javascript:;"><i class="fa fa-times" aria-hidden="true"></i></a>\n\
                                <div class="col-md-3">' + pic + '</div>\n\
                                <div class="col-md-9"><h2>' + title + '</h2><p>' + desc + '</p>\n\
                                <div class="redeem-points"><strong>You can claim this product for:</strong><span>'+ redeem_points +'</span></div>\n\
                                <div class="cart-actions">'+ actions +'</div></div></div></div>';
              $('body').addClass('has-cart-popup').remove('.cart-popup-wrapper');
              $('body').append(popup_html);
            });
            $('.view-redeem-points').on('click', '.cart-close', function(){
              $(this).closest('.cart-popup-wrapper').fadeOut();
            });
            // Checkout page script.

            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


