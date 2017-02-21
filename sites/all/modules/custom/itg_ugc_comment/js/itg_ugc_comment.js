/*
 * @file itg_ugc_comment.js
 * Contains all functionality User Generated Content
 */

(function ($) {
    Drupal.behaviors.itg_ugc_comment = {
        attach: function (context, settings) {
            var uid = settings.itg_ugc_comment.settings.uid;
            var bad_word = settings.itg_ugc_comment.settings.bad_word;
            if (bad_word) {
                var result = bad_word.split(',');
            }
            var block_email = settings.itg_ugc_comment.settings.block_email;
            if (block_email) {
                var email_result = block_email.split(',');
            }
            
            

            $(function () {
                $("a.reply").click(function () {
                    var id = $(this).attr("id");
                    $('body').find('.ugc-comment-popup').addClass('comment-popup').parent().addClass('comment-popup-wrapper');
                    $("#parent_id").attr("value", id);
                    $("#edit-fname").focus();
                });
                $('body').on('click', '.close-comment-popup', function () {
                    $('body').find('.ugc-comment-popup').removeClass('comment-popup').parent().removeClass('comment-popup-wrapper');
                });
                
                $('body').on('click', '.comment-social-share', function () {
                   $('.sso-click').trigger('click');
                });
            });

            // custom validation for comment form

            $("#ugc-comment-form").validate({
                submitHandler: function (form) {
                    $('input:submit').attr('disabled', 'disabled');
                    form.submit();
                },
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
                    'fname': {
                        required: true

                    },
                    'femail': {
                        required: true,
                        email: true,
                        validateblockemail: true,
                    },
                    'fmessage': {
                        required: true,
                        validatebadword: true,
                    },
                },
                messages: {
                    'fname': {
                        required: 'Name field is required.'
                    },
                    'femail': {
                        required: 'Email field is required.'

                    },
                    'fmessage': {
                        required: 'Comment field is required.'
                    }

                }
            });

            jQuery.validator.addMethod("validatebadword", function (value, element) {
                return validate_bad_word(value, element);
            }, "You cannot post this comment, please remove abusive word and try again.");
            
            jQuery.validator.addMethod("validateblockemail", function (value, element) {
                return validate_email_block(value, element);
            }, "You cannot post this comment, your email is blocked.");

            // Validate date difference.
            function validate_bad_word(value, element) {
                var description = $('#edit-fmessage').val();
                var f_description = description.toLowerCase();
                var final = containsAny(f_description, result);
                if (final) {
                    return false;
                }

                return true;
            }
            
            // Validate email block.
            function validate_email_block(value, element) {
                var email_to = $('#edit-femail').val();
                if (email_result.indexOf(email_to) !== -1) {
                    return false;
                }

                return true;
            }
        }

    };
})(jQuery, Drupal, this, this.document);

// check for bad word exist or not
function containsAny(str, substrings) {
    for (var i = 0; i != substrings.length; i++) {
       var substring = substrings[i];
       if (str.indexOf(substring) != - 1) {
         return substring;
       }
    }
    return null; 
}