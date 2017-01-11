/*
 * @file itg_ugc.js
 * Contains all functionality User Generated Content
 */

(function ($) {
  Drupal.behaviors.itg_ugc_comment = {
    attach: function (context, settings) {
             var uid = settings.itg_ugc_comment.settings.uid;


             jQuery(function () {
                jQuery("a.reply").click(function () {
                    var id = $(this).attr("id");
                    $('body').find('.ugc-comment-popup').addClass('comment-popup').parent().addClass('comment-popup-wrapper');
                    jQuery("#parent_id").attr("value", id);
                    jQuery("#edit-fname").focus();
                });
                $('body').on('click', '.close-comment-popup', function(){
                    $('body').find('.ugc-comment-popup').removeClass('comment-popup').parent().removeClass('comment-popup-wrapper');
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
            email: true
          },
          'fmessage': {
            required: true

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
    }

  };
})(jQuery, Drupal, this, this.document);
