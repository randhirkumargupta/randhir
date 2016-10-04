/** 
 * @file
 *   Shopping kart js.
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_loyalty_reward = {
        attach: function (context, settings) {
            // Module code start.
            // Code to show detail popup
            $('.product-wrapper').on('click', '.product-pic', function () {
                var pic = $(this).html();
                var added_on = $(this).children('span').html();
                var title = $(this).siblings('.product-title').html();
                var desc = $(this).siblings('.product-description').html();
                var redeem_points = $(this).siblings('.redeem-points').html();
                var actions = $(this).siblings('.product-actions').html();
                var popup_html = '<div class="cart-popup-wrapper">\n\
                                <div class="cart-popup"><a class="cart-close" href="javascript:;"><i class="fa fa-times" aria-hidden="true"></i></a>\n\
                                <div class="col-md-4 pic">' + pic + '<span>' + added_on + '</span></div>\n\
                                <div class="col-md-8"><h2>' + title + '</h2><p>' + desc + '</p>\n\
                                <div class="redeem-points"><strong>You can claim this product for:</strong><span>' + redeem_points + '</span></div>\n\
                                <div class="cart-actions">' + actions + '</div></div></div></div>';
                $('body').addClass('has-cart-popup').remove('.cart-popup-wrapper');
                $('body').append(popup_html);
            });
            $('body').on('click', '.cart-close', function () {
                $(this).closest('.cart-popup-wrapper').fadeOut();
                $('body').removeClass('has-cart-popup');
            });
            // Checkout page script.
            // validateJobSearch validation function.
            if ($('body').hasClass('page-checkout')) {
                $("#itg-loyalty-reward-checkout-form").validate({
                    onfocusout: function (element) {
                        $(element).valid();
                    },
                    ignore: '',
                    errorElement: 'span',
                    errorPlacement: function (error, element) {
                        var elementName = element.attr('name');
                        var errorPlaceHolder = '';
                        switch (elementName) {
                            case 'field_astro_frequency[und]':
                                errorPlaceHolder = $('#edit-title').parent();
                                break;
                            case 'field_astro_date_range[und][0][value2][date]':
                                errorPlaceHolder = element.parent().parent();
                                break;
                            default:
                                errorPlaceHolder = element.parent();
                        }
                        error.appendTo(errorPlaceHolder);
                    },
                    rules: {
                        'name': {
                            required: true
                        },
                        'email': {
                            required: true,
                            email: true,
                        },
                        'phone': {
                            required: true,
                        },
                        'address': {
                            required: true,
                        },
                        'city': {
                            required: true,
                        },
                        'zip_code': {
                            required: true,
                        }
                    },
                    messages: {
                        'name': {
                            required: 'Name field is required.'
                        },
                        'email': {
                            required: 'Email field is required.',
                            email: 'Please enter a valid email address.'
                        },
                        'phone': {
                            required: 'Phone field is required.'
                        },
                        'address': {
                            required: 'Address field is required.'
                        },
                        'city': {
                            required: 'City field is required.'
                        },
                        'zip_code': {
                            required: 'City field is required.'
                        }
                    }
                });
            }

            // Code for points earning callbacks.
            $('.share, .like, .visit').on('click', function () {
                //console.log(Drupal.settings.itg_loyalty_reward);
                var base_url = Drupal.settings.itg_loyalty_reward.base_url;
                var event_type = $(this).attr('class');
                $.ajax({
                    url: base_url + '/earn-loyalty-point',
                    type: 'POST',
                    dataType: 'JSON',
                    data: {'type': event_type},
                    success: function (itg) {
                        
                    }
                });
            });
            // Code end for points earning callbacks.

            // Code for product page.
            if ($('body').hasClass('page-product')) {
                $("#edit-itg-points").appendTo("#edit-field-lrp-loyalty-points-value-wrapper");
                $('#edit-itg-points').on('change', function () {
                    var points = $(this).find('option:selected').val();
                    var spliteed_points = points.split("-");
                    $('#edit-field-lrp-loyalty-points-value-min').val(spliteed_points[0]);
                    $('#edit-field-lrp-loyalty-points-value-max').val(spliteed_points[1]);
                });
            }
            $('#views-exposed-form-product-page').on('submit', function (event) {
                var points = $('#edit-itg-points').find('option:selected').val();
                var spliteed_points = points.split("-");
                $('#edit-field-lrp-loyalty-points-value-min').val(spliteed_points[0]);
                $('#edit-field-lrp-loyalty-points-value-max').val(spliteed_points[1]);

            });

            // Code end for product page.

            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


