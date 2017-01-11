/*
 * @file itg_ugc.js
 * Contains all functionality User Generated Content
 */

(function($) {
    Drupal.behaviors.itg_ugc = {
        attach: function(context, settings) {
            var uid = settings.itg_ugc.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                
                $('#edit-field-user-message-und-0-format').hide();
                
            }


            $('#edit-field-ugc-ctype-und').change(function() {
                var contenttypevalue = $('#edit-field-ugc-ctype-und').val();
                // alert(contenttypevalue);
                if (contenttypevalue == 'photogallery'
                        || contenttypevalue == 'blog'
                        || contenttypevalue == 'audio'
                        || contenttypevalue == 'video'
                        || contenttypevalue == 'recipe'
                        || contenttypevalue == 'story'
                        || contenttypevalue == '_none') { // Image question
                    $('#edit-title').val('');
                    if (typeof CKEDITOR != "undefined") {
                        CKEDITOR.instances['edit-field-user-message-und-0-value'].setData('');
                    }
                    else
                    {
                        $('#edit-field-user-message-und-0-value').val('');
                    }
                    $('#edit-field-ugc-upload-photo-und-0-remove-button').mousedown();
                    $('#edit-field-astro-video-und-0-remove-button').mousedown();
                }

            });

            if ($('.form-field-name-field-ugc-ctype .form-select').val() == 'photogallery') {

                $('.form-field-name-field-ugc-ctype').siblings('.form-field-name-field-ugc-upload-photo').find('.form-item > label').html('Upload Photo <span class="form-required" title="This field is required.">*</span>');
            }
            $('.form-field-name-field-ugc-ctype').on('change', '.form-select', function() {

                var selectedVal = $(this).val();
                if (selectedVal == 'photogallery') {
                    $(this).parent().parent().siblings('.form-field-name-field-ugc-upload-photo').find('.form-item > label').html('Upload Photo <span class="form-required" title="This field is required.">*</span>');
                }
            });


            // restrict user to enter special charecter and number               
            $('#edit-field-user-name-und-0-value').keyup(function() {
                this.value = this.value.replace(/[^a-zA-Z\s.,]/g, '');
            });

            // client side validation

            // Custom validator function for social media start
            $("#ugc-node-form").validate({
                submitHandler: function(form) {
                    $('input:submit').attr('disabled', 'disabled');
                    form.submit();
                },
                onfocusout: function(element) {
                    $(element).valid();
                },
                ignore: '',
                errorElement: 'span',
                errorPlacement: function(error, element) {
                    var elementName = element.attr('name');
                    var errorPlaceHolder = '';
                    switch (elementName) {

                        default:
                            errorPlaceHolder = element.parent();
                    }
                    error.appendTo(errorPlaceHolder);
                },
                rules: {
                    'field_user_name[und][0][value]': {
                        required: true

                    },
                    'field_user_email[und][0][value]': {
                        required: true,
                        email: true
                    },
                    'field_user_message[und][0][value]': {
                        required: function (element) {
                            return $("#edit-field-ugc-ctype-und").val() == 'story';
                        }
                    },
                    'title': {
                        required: true

                    },
                    'field_ugc_ctype[und]': {
                        required: true,
                        validateSignName: true

                    },
                    'captcha_response': {
                        required: true

                    },
                },
                messages: {
                    'field_user_name[und][0][value]': {
                        required: 'Name field is required.'
                    },
                    'field_user_email[und][0][value]': {
                        required: 'Email field is required.'

                    },
                    'field_user_message[und][0][value]': {
                        required: 'Description field is required.'

                    },
                    'title': {
                        required: 'Title field is required.'
                    },
                    'field_ugc_ctype[und]': {
                        required: 'Content Type field is required.'
                    },
                    'captcha_response': {
                        required: 'Captcha field is required.'
                    }
                }
            });

            // validate content type drop down
            jQuery.validator.addMethod("validateSignName", function(value, element) {
                return validateSignNameValue(value, element);
            }, "Content Type field is required.");


            // validate content type drop down
            function validateSignNameValue(event, element) {
                if ($(element).val() == '_none') {
                    return false;
                }
                else {
                    return true;
                }
            }

            // Written code for handling repeating error message
            $('.form-field-name-field-ugc-upload-photo').find('.form-submit').on('mousedown', function(e) {
                $('.form-field-name-field-ugc-upload-photo').find('.messages.error').remove();
            });

            $('.form-field-name-field-astro-video').find('.form-submit').on('mousedown', function(e) {
                $('.form-field-name-field-astro-video').find('.messages.error').remove();
            });


            $('.form-field-name-field-ugc-upload-photo').find('.form-submit').on('mousedown', function(e) {
                $('.form-field-name-field-ugc-upload-photo').find('.messages.status').remove();
            });

            $('.form-field-name-field-astro-video').find('.form-submit').on('mousedown', function(e) {
                $('.form-field-name-field-astro-video').find('.messages.status').remove();
            });

        }

    };
})(jQuery, Drupal, this, this.document);
