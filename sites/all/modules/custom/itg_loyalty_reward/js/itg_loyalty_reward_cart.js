/** 
 * @file
 *   Shopping kart js.
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_loyalty_reward = {
        attach: function (context, settings) {
            // Module code start.
            /*Add to cart trigger.            
            $('.add-to-cart').click(function () {
                var magzine_id = $(this).parent().parent().find('.views-field-nid').text();
                var title = $(this).parent().parent().find('.views-field-title').text();
                var points = $(this).parent().parent().find('.views-field-field-lrp-loyalty-points').text();
                points = parseInt(points);
                var base_url = Drupal.settings.itg_loyalty_reward.base_url;                
                $.ajax({
                    url: base_url + '/add-to-cart',
                    type: "post",
                    data: {'mid' : magzine_id, 'title' : title, 'points' : points},
                    dataType: 'json',
                    success: function (res) {                        
                        if (res.code === 1) {
                            var cart_item = $('#my-cart-items span').text();
                            cart_item = parseInt(cart_item);
                            ++cart_item;
                            $('#my-cart-items span').html(cart_item);                            
                            //$('.' + res.mid).parent().html('<div class="' + res.mid +'" ><a href="' + base_url + '/cart">GO TO CART</a></div');
                            //$('.' + res.mid).parent().parent().clone().appendTo('#my-cart-items');              
                            
                        }                        
                    }
                });
            });
            */
            var mid = Drupal.settings.itg_loyalty_reward.mid;            
            var base_url = Drupal.settings.itg_loyalty_reward.base_url;
            $.each(mid, function(index, value) {
                $('.' + value).parent().html('<div class="' + value +'" ><a href="' + base_url + '/cart">GO TO CART</a></div');
                $('.' + value).parent().parent().find('.redeem-point a').attr('href', 'cart');
            });            
            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


