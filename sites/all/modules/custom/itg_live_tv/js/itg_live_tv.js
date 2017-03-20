/*
 * @file itg_live_tv.js
 * Contains all functionality related to Live tv Integration
 */

(function ($) {
    Drupal.behaviors.itg_live_tv = {
        attach: function (context, settings) {
            var uid = settings.itg_live_tv.settings.uid;
            var base_url = settings.itg_live_tv.settings.base_url;            

            $('.live-tv-button', context).click(function (event) {
                if (jQuery(this).is(':checked'))
                {
                    var device = jQuery(this).val();
                    var company = jQuery(this).attr('rel');
                    var post = "&device=" + device + "&company=" + company;

                    $.ajax({
                        'url': base_url + '/live-tv-details-ajax',
                        'data': post,
                        'type': 'POST',
                        // dataType: 'json',
                        beforeSend: function () {
                           
                            $('#widget-ajex-loader').show();


                        },
                        'success': function (data)
                        {

                            $('#widget-ajex-loader').hide();
                            //$("#successMessage").html("Saved Sucessfully");
                            window.location.reload('true');
                        }
                    });
                }
            });


        }

    };
})(jQuery, Drupal, this, this.document);