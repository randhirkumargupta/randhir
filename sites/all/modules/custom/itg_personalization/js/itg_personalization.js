/**
 * @file
 * A javascript file for itg_personalization module.
 */
jQuery(document).ready(function () {
    // Hide my content listing 
    var ctype = jQuery("select[name='field_ugc_ctype[und]']").find('option:selected').val();
   
     if (ctype != '_none') {
        jQuery('#_none').removeClass('active');
        jQuery('#' + ctype).addClass('active');
        jQuery('#block-formblock-ugc .captcha').show();
    }
    if (ctype == '_none') {
        jQuery('#block-views-c3b0c328c45542af0b403435a6097179').show();
        jQuery('#block-itg-personalization-personalization-all-content').show();
        jQuery('.form-field-name-field-user-message').hide();
        jQuery('#block-formblock-ugc .captcha').hide();
    } else {
        jQuery('#block-views-c3b0c328c45542af0b403435a6097179').hide();
        jQuery('#block-itg-personalization-personalization-all-content').hide();
    }
    if (ctype == 'blog') {
        jQuery('.form-field-name-field-user-message').show();
    }
    
    jQuery("select[name='field_ugc_ctype[und]']").on('change', function () {
        var ctype = jQuery(this).find('option:selected').val();
        // Show hide content listing block.
        if (ctype == '_none') {
            jQuery('#block-views-c3b0c328c45542af0b403435a6097179').show();
            jQuery('#block-itg-personalization-personalization-all-content').show();
            jQuery('#block-formblock-ugc .captcha').hide();
        } else {
            jQuery('#block-views-c3b0c328c45542af0b403435a6097179').hide();
            jQuery('#block-itg-personalization-personalization-all-content').hide();
            jQuery('#block-formblock-ugc .captcha').show();
        }

        switch (ctype) {
            case 'story':
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'blog':
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'photogallery':
                jQuery('.form-field-name-field-user-message').hide();
                break;
            case 'recipe':
                jQuery('.form-field-name-field-user-message').show();
                break;
            case 'videogallery':
                jQuery('.form-field-name-field-user-message').show();
                break;
            default:
                jQuery('.form-field-name-field-user-message').hide();
        }

    });
    
    //Trigger select box by icon
    jQuery('.perchange').on('click',function(){
        jQuery('#ugc-node-form')[0].reset();
        jQuery('.perchange').removeClass('active');
         jQuery(this).addClass('active');
       var getid=jQuery(this).attr('id');
       jQuery('#edit-field-ugc-ctype-und').val(getid).trigger('change');
    })
    
    // code for follwing 
    jQuery('.tobe-follow').click(function (event) {
        var tid = jQuery(this).attr('data-value');
        var dtag = jQuery(this).attr('data-tag');
        var post_data = "&tid=" + tid + "&dtag=" + dtag;

        jQuery.ajax({
            'url': Drupal.settings.baseUrl.baseUrl + '/following-details-ajax',
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


                if (obj.success) {
                    jQuery('#widget-ajex-loader').hide();
                    window.location.reload('true');
                }

            }
        });

    });
    
    // Change text of select option.
    jQuery("#edit-field-ugc-ctype-und option[value='photogallery']").text('Photogallery');
    jQuery("#edit-field-ugc-ctype-und option[value='videogallery']").text('Videogallery');

    jQuery("#views-form-personalization-my-preferences-block #edit-reset")
            .appendTo("#views-form-personalization-my-preferences-block #edit-actions");

    // Hide remove button
    jQuery('input[name="field_ugc_personalization_photo_und_0_remove_button"]').hide();
    var base_url = '';
    // Validate refer a friend form.    
    if (jQuery('body').hasClass('page-personalization-edit-profile-refer-a-friend')) {
        jQuery("#itg-personalization-refer-a-friend-form").validate({
            onfocusout: function (element) {
                jQuery(element).valid();
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
                'name_0': {
                    required: true,
                    lettersonly: true
                },
                'name_1': {
                    required: true,
                    lettersonly: true
                },
                'name_2': {
                    required: true,
                    lettersonly: true
                },
                'name_3': {
                    required: true,
                    lettersonly: true
                },
                'name_4': {
                    required: true,
                    lettersonly: true
                },
                'mail_0': {
                    required: true,                    
                    fullemail: true,
                    remote: {
                        url: base_url + "/itg-validate-by-usermail",
                        type: "post",
                        data: {
                            usermail: function () {
                                return jQuery('input[name="mail_0"]').val()
                            }
                        }
                    }
                },
                'mail_1': {
                    required: true,
                    fullemail: true,
                    remote: {
                        url: base_url + "/itg-validate-by-usermail",
                        type: "post",
                        data: {
                            usermail: function () {
                                return jQuery('input[name="mail_0"]').val()
                            }
                        }
                    }
                },
                'mail_2': {
                    required: true,
                    fullemail: true,
                    remote: {
                        url: base_url + "/itg-validate-by-usermail",
                        type: "post",
                        data: {
                            usermail: function () {
                                return jQuery('input[name="mail_0"]').val()
                            }
                        }
                    }
                },
                'mail_3': {
                    required: true,
                    fullemail: true,
                    remote: {
                        url: base_url + "/itg-validate-by-usermail",
                        type: "post",
                        data: {
                            usermail: function () {
                                return jQuery('input[name="mail_0"]').val()
                            }
                        }
                    }
                },
                'mail_4': {
                    required: true,
                    fullemail: true,
                    remote: {
                        url: base_url + "/itg-validate-by-usermail",
                        type: "post",
                        data: {
                            usermail: function () {
                                return jQuery('input[name="mail_0"]').val()
                            }
                        }
                    }
                }
            },
            messages: {
                'name_0': {
                    required: 'Name field is required.',
                },
                'name_1': {
                    required: 'Name field is required.',
                },
                'name_2': {
                    required: 'Name field is required.',
                },
                'name_3': {
                    required: 'Name field is required.',
                },
                'name_4': {
                    required: 'Name field is required.',
                },
                'mail_0': {
                    required: 'Email field is required.',
                    fullemail: 'Please enter a valid Email Address.',
                    remote: 'User is already registered.'
                },
                'mail_1': {
                    required: 'Email field is required.',
                    fullemail: 'Please enter a valid Email Address.'
                },
                'mail_2': {
                    required: 'Email field is required.',
                    fullemail: 'Please enter a valid Email Address.'
                },
                'mail_3': {
                    required: 'Email field is required.',
                    fullemail: 'Please enter a valid Email Address.'
                },
                'mail_4': {
                    required: 'Email field is required.',
                    fullemail: 'Please enter a valid Email Address.'
                }
            }
        });
        jQuery.validator.addMethod("lettersonly", function (value, element) {
            return this.optional(element) || /^[a-z\s]+$/i.test(value.trim());
        }, "Please enter letters only.");
        jQuery.validator.addMethod("fullemail", function (value, element) {
            return this.optional(element) || /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(value);
        }, "Please enter a valid email address.");
    }
    
    // cod to show ugc tab on personalization
    var url = window.location.href;
    var ugc_value = url.substring(url.lastIndexOf('/') + 1);
    var ugc_value_id = ugc_value.toLowerCase();
    ugc_arr = ['story', 'videogallery', 'photogallery'];
    if(jQuery.inArray(ugc_value_id, ugc_arr) != -1) {
        jQuery('#'+ugc_value_id).trigger('click');
    }
    
    jQuery('#edit-zip-code').keyup(function() {
                this.value = this.value.replace(/[^\d\.\-]/g,'');
            });
});
