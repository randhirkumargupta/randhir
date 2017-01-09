(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_social_media = {
        attach: function (context, settings) {

            // Module code start

            // Callback function for custom methods.
            var FormValidation = {
                // Validate Social Media Integration checkboxes.
                validate_smi: function (value, element) {
                    var smi_fb = $('input[name="itg_smi[facebook]"]').is(':checked');
                    var smi_instant_article = $('input[name="itg_smi[facebook_instant_article]"]').is(':checked');
                    var smi_twitter = $('input[name="itg_smi[twitter]"]').is(':checked');
                    var smi_instagram = $('input[name="itg_smi[instagram]"]').is(':checked');
                    if (smi_fb || smi_instant_article || smi_twitter || smi_instagram) {
                        return true;
                    }
                    else {
                        return false;
                    }
                },
                // Common function to reset all values
                clear_form_elements: function (class_name) {
                    jQuery("." + class_name).find(':input').each(function () {
                        switch (this.type) {
                            case 'text':
                            case 'textarea':
                                $(this).val('');
                                break;
                            case 'select-one':
                                $(this).val('_none');
                                break;
                        }
                    });
                },
                fb_image: function (value, element) {
                    // Validate for facebook.
                    var facebook_condition = $('input[name="itg_facebook_condition"]:checked').val();                    
                    
                    // Validate Image condion.
                    if (facebook_condition == 0 && value == 0) {                        
                        return false;                     
                    }
                    else {
                        return true;
                    }                    
                },
                fb_video: function (value, element) {
                    // Validate for facebook.
                    var facebook_condition = $('input[name="itg_facebook_condition"]:checked').val();                    
                    
                    // Validate video condition.
                    if (facebook_condition == 1 && value == 0) {                        
                        return false;                                                
                    }
                    else {
                        return true;
                    }
                },
                twitter_video: function (value, element) {
                    // Validate for facebook.
                    var twitter_condition = $('input[name="itg_twitter_condition"]:checked').val();                    
                    
                    // Validate video condition.
                    if (twitter_condition == 1 && value == 0) {
                        console.log('video case');
                        console.log('video fid: ' + value);
                        return false;                                                
                    }
                    else {
                        return true;
                    }
                },
                twitter_image: function (value, element) {
                    // Validate for facebook.
                    var twitter_condition = $('input[name="itg_twitter_condition"]:checked').val();                    
                    
                    // Validate video condition.
                    if (twitter_condition == 0 && value == 0) {                        
                        return false;                                                
                    }
                    else {
                        return true;
                    }
                }
            };

            // Clear fb fields based on checkbox.
            $('input[name="itg_smi[facebook]"]').click(function () {
                if (!$(this).is(':checked')) {
                    FormValidation.clear_form_elements('social-fb-block');
                    jQuery('.form-item-itg-fb-img .ajax-processed').mousedown();
                    jQuery('.form-item-itg-fb-video .ajax-processed').mousedown();
                }
            });

            // Clear twitter fields
            $('input[name="itg_smi[twitter]"]').click(function () {
                if (!$(this).is(':checked')) {
                    FormValidation.clear_form_elements('social-twitter-block');
                    jQuery('.form-item-itg-twitter-img .ajax-processed').mousedown();
                    jQuery('.form-item-itg-twit-video .ajax-processed').mousedown();
                }
            });
            // clear form end here.

            // Add placeholder to scheduler fields
            var date_holder = moment().format('DD/MM/YYYY');
            var time_holder = moment().format('H:mm');
            jQuery('input[name="img_schedule_time[date]"]').attr('placeholder', date_holder);
            jQuery('input[name="img_schedule_time[time]"]').attr('placeholder', time_holder);

            jQuery('input[name="video_schedule_time[date]"]').attr('placeholder', date_holder);
            jQuery('input[name="video_schedule_time[time]"]').attr('placeholder', time_holder);

            jQuery('input[name="tw_img_schedule_time[date]"]').attr('placeholder', date_holder);
            jQuery('input[name="tw_img_schedule_time[time]"]').attr('placeholder', time_holder);

            jQuery('input[name="tw_vid_schedule_time[date]"]').attr('placeholder', date_holder);
            jQuery('input[name="tw_vid_schedule_time[time]"]').attr('placeholder', time_holder);

            // Twitter field validation.
            $("#itg-social-media-form").validate({
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
                    'itg_facebook_narrative': {
                        required: {
                            depends: function () {
                                if ($('#edit-itg-smi-facebook').is(":checked")) {
                                    return true;
                                }
                            }
                        }
                    },
                    'itg_fb_img[fid]': {
                        fb_image: true,
                    },
                    'itg_fb_video[fid]': {
                        fb_video: true
                    },
                    'itg_twitter_narrative': {
                        required: {
                            depends: function () {
                                if ($('#edit-itg-smi-twitter').is(':checked')) {
                                    return true;
                                }
                            }
                        },
                        maxlength: 126
                    },
                    'itg_twitter_img[fid]': {
                        twitter_image: true
                    },
                    'itg_twit_video[fid]': {
                        twitter_video: true
                    }
                },
                messages: {
                    'itg_facebook_narrative': {
                        required: 'Narrative field is required.'
                    },
                    'itg_fb_img[fid]': {
                        required: 'Facebook image field is required.'
                    },
                    'itg_fb_video[fid]': {
                        required: 'Facebook video field is required.'
                    },
                    'itg_twitter_narrative': {
                        required: 'Narrative field is required.'
                    },
                    'itg_twitter_img[fid]': {
                        required: 'Twitter image field is required.'
                    },
                    'itg_twit_video[fid]': {
                        required: 'Twitter video field is required.'
                    }
                }
            });
            jQuery.validator.addMethod("fb_image", function (value, element) {
                return FormValidation.fb_image(value, element);
            }, "Facebook image is required.");
            jQuery.validator.addMethod("fb_video", function (value, element) {
                return FormValidation.fb_video(value, element);
            }, "Facebook video is required.");
            jQuery.validator.addMethod("twitter_image", function (value, element) {
                return FormValidation.twitter_image(value, element);
            }, "Twitter image is required.");
            jQuery.validator.addMethod("twitter_video", function (value, element) {
                return FormValidation.twitter_video(value, element);
            }, "Twitter video is required.");
            // Moduel code end.      
        }
    };
})(jQuery, Drupal, this, this.document);