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
                var added_on = $(this).siblings('.post-date').html();
                var title = $(this).siblings('.product-title').html();
                var desc = $(this).siblings('.product-description').html();
                var redeem_points = $(this).siblings('.redeem-points').html();
                redeem_points = parseInt(redeem_points);
                var actions = $(this).siblings('.product-actions').html();
                var popup_html = '<div class="cart-popup-wrapper">\n\
                                <div class="cart-popup"><a class="cart-close" href="javascript:;"><i class="fa fa-times" aria-hidden="true"></i></a>\n\
                                <div class="col-md-4 pic">' + pic + '<span>' + added_on + '</span></div>\n\
                                <div class="col-md-8"><h2>' + title + '</h2><p>' + desc + '</p>\n\
                                <div class="redeem-points"><strong>You can claim this product for:</strong><span>' + redeem_points + ' Reward Points only</span></div>\n\
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
            if ($('body').hasClass('page-order-summary')) {
                $("#itg-loyalty-reward-address-form").validate({
                    onfocusout: function (element) {
                        $(element).valid();
                    },
                    ignore: '',
                    errorElement: 'span',
                    errorPlacement: function (error, element) {
                        var elementName = element.attr('name');
                        var errorPlaceHolder = '';
                        switch (elementName) {
                            default:
                                errorPlaceHolder = element.parent();
                        }
                        error.appendTo(errorPlaceHolder);
                    },
                    rules: {                        
                        'address': {
                            required: true,
                            alphanumeric: true
                        },                        
                        'zip_code': {
                            required: true,
                            minlength: 6,
                            maxlength: 6,
                            number: true
                        }
                    },
                    messages: {                        
                        'address': {
                            required: 'Address field is required.'
                        },                        
                        'zip_code': {
                            required: 'Zip Code field is required.',
                            maxlength: 'Please enter valid Zip Code.',
                            minlength: 'Please enter valid Zip Code.',
                            number: 'Please enter valid Zip Code.'
                        }
                    }
                });
                jQuery.validator.addMethod("lettersonly", function (value, element) {
                    return this.optional(element) || /^[a-z\s]+$/i.test(value.trim());
                }, "Please enter letters only.");
                $.validator.addMethod("alphanumeric", function (value, element) {
                    return this.optional(element) || /^[a-z0-9\-\s]+$/i.test(value);
                }, "Address must contain only letters, numbers, or dashes.");
                $.validator.addMethod("fullemail", function (value, element) {
                    return this.optional(element) || /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(value);
                }, "Address must contain only letters, numbers, or dashes.");
            }
            
            // Redirect user to redeem points page after clicking on reset button.
            if ($('body').hasClass('page-product')) {
              var base_url = Drupal.settings.itg_loyalty_reward.base_url;  
              $('#product-reset').on('click', function(event) {
                  event.preventDefault();
                  test_loader_show();
                  window.location.href = base_url + '/redeem-points';
              });
            }

            // Code for points earning callbacks.
            $('.share, .like, .visit, .follow, .ns, .ugc, .ol-register, .participate, .raf').on('click', function () {
                //console.log(Drupal.settings.itg_loyalty_reward);
                var base_url = Drupal.settings.itg_loyalty_reward.base_url;
                var event_type = $(this).attr('class');
                $.ajax({
                    url: base_url + '/earn-loyalty-point',
                    type: 'POST',
                    dataType: 'JSON',
                    data: {'type': event_type},
                    beforeSend: function (xhr) {
                        test_loader_show();
                    },
                    success: function (itg) {
                        test_loader_hide();
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
            // Display loader onclick of add to cart link.
            $('.btn-add-cart, .itg-remove-product, .btn-redeem-points').on('click', function () {
                if (!$(this).hasClass('no-loader')) {
                  test_loader_show();                  
                }
                
            });

            function test_loader_show() {
                $('#widget-ajex-loader').show();
            }
            function test_loader_hide() {
                $('#widget-ajex-loader').hide();
            }


            // Code end for product page.

            // Module code ends.
        }
    };
})(jQuery, Drupal, this, this.document);


