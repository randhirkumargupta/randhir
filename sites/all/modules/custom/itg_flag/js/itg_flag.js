/*
 * @file itg_flag.js
 * Contains all functionality related to Flag Management
 */

(function ($) {
    Drupal.behaviors.itg_flag = {
        attach: function (context, settings) {
            var uid = settings.itg_flag.settings.uid;
            var base_url = settings.itg_flag.settings.base_url;
            //alert(base_url);
            $('#like_count,#dislike_count').click(function (event) {
                
                var nd_id = jQuery(this).attr('rel');
                var typ = jQuery(this).attr('id');
                var post_data = "&nd_id="+ nd_id + "&typ=" + typ;

                    $.ajax({
                        'url': base_url + '/flag-details-ajax',
                        'data': post_data,
                        'cache': false,
                        'type': 'POST',
                        // dataType: 'json',
                        beforeSend: function () {
                           
                        },
                        'success': function (result)
                        {
                            var obj = jQuery.parseJSON(result);
                             
                            $('#widget-ajex-loader').hide();
                            if (obj.type == 'like_count') {
                            $("#no-of-likes_"+obj.nd_id).html("(" + obj.count + ")");
                        }
                        if (obj.type == 'dislike_count') {
                            $("#no-of-dislikes_"+obj.nd_id).html("(" + obj.count + ")");
                        }
                        if (obj.error == 'error') {
                           
                            $("#voted_"+obj.nd_id).html('You have already voted').show(0).delay(2000).hide(1000);
                        }
                        }
                    });
               
            });
        }

    };
})(jQuery, Drupal, this, this.document);