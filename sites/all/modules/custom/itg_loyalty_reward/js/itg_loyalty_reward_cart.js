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
            // Checkout page script.

            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


