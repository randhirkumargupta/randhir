/** 
 * @file
 *   Shopping kart js.
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_loyalty_reward = {
        attach: function (context, settings) {
            // Module code start.
            //Add to cart trigger.            
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
                    success: function (code) {
                        if (code == 1) {
                            jQuery('#content').find('.autosave').remove();
                            var cus_message = '<div class="messages--status messages status autosave">Form data has been successfully auto saved</div>';
                            jQuery('#content').prepend(cus_message);
                            jQuery('#content').find('.autosave').fadeOut(10000);
                        }
                    }
                });
            });
            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


