/*
 * @file itg_ugc_user_block.js
 * Contains all functionality User Generated Content
 */

(function ($) {
    Drupal.behaviors.itg_ugc_user_block = {
        attach: function (context, settings) {
            var base_url = settings.itg_ugc_user_block.settings.base_url;
           
            jQuery('#comment-user-block').click(function (event) {
                var associate_id = jQuery(this).attr('id');
                var email = [];
                    jQuery.each(jQuery("input[name='block_user[]']:checked"), function () {
                        email.push(jQuery(this).val());
                    });
                    
                if (associate_id == 'comment-user-block' && email.length != 0) {
                    var msg = confirm("Are you sure you want to block users?");
                } else {
                    alert('Please select atleast one email id');
                }
                if (msg == true) {
                    
                    var post_data = "&email=" + email.join(", ");
                    jQuery.ajax({
                        'url': base_url + '/user-block-ugc',
                        'data': post_data,
                        'cache': false,
                        'type': 'POST',
                        // dataType: 'json',
                        beforeSend: function () {
                             jQuery('#widget-ajex-loader').show();
                        },
                        'success': function (result)
                        {
                            var obj = jQuery.parseJSON(result);
                            if (obj.success == 'true') {
                             jQuery('.block_success').html('Email '+email.join(", ")+ ' Blocked Sucessfully').show();
                             jQuery('#itg-user-block-api-form')[0].reset();
                             window.location.reload('true');
                            }
                        }
                    });
                    
                    return true;
                }
                return false;
            });
        }

    };
})(jQuery, Drupal, this, this.document);
