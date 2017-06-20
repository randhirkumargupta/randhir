/*
 * @file itg_sso_validate.js
 * Contains all functionality related to login validation
 */

(function ($) {
    Drupal.behaviors.itg_sso_validate = {
        attach: function (context, settings) {
            
            $("#user-login").validate({
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
                    'name': {
                        required: true

                    },
                    'pass': {
                        required: true

                    },
                },
                messages: {
                    'name': {
                        required: 'Enter your email/mobile number field is required.'
                    },
                    'pass': {
                        required: 'Password field is required.'
                    }
                }
            });
        }

    };
})(jQuery, Drupal, this, this.document);
