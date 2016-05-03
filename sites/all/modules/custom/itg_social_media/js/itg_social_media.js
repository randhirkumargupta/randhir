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
          if (smi_fb || smi_instant_article || smi_twitter) {
            return true;
          }
          else {
            return false;
          }
        }
      };
      
      // Custom validator function for social media start
      $("#itg-social-media-form").validate({
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
            case 'itg_smi[facebook]':
              errorPlaceHolder = element.parent().parent().parent();
              break;
            case 'itg_twitter_img[fid]':  
            case 'itg_fb_img[fid]':  
              errorPlaceHolder = element.parent().parent();
              break;              
              
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {
          'itg_smi[facebook]': {
            validateSmi: true
          },
          'itg_facebook_narrative': {
            required: {
              depends: function() {
                var smi_fb = $('input[name="itg_smi[facebook]"]').is(':checked');
                if (smi_fb) {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          },
          'itg_fb_img[fid]': {
            required: {
              depends: function () {
                var smi_fb = $('input[name="itg_smi[facebook]"]').is(':checked');                
                var fid = $('input[name="itg_fb_img[fid]"]').val();
                if (smi_fb && fid === '0') {
                  $(this).removeAttr('value');                  
                }
                return true;
              }
            }
          },
          'itg_twitter_narrative': {
            required: {
              depends: function() {
                var smi_fb = $('input[name="itg_smi[twitter]"]').is(':checked');
                if (smi_fb) {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          },
          'itg_twitter_img[fid]': {
            required: {
              depends: function () {
                var smi_fb = $('input[name="itg_smi[twitter]"]').is(':checked');                
                var fid = $('input[name="itg_twitter_img[fid]"]').val();
                if (smi_fb && fid === '0') {
                  $(this).removeAttr('value');                  
                }
                return true;
              }
            }
          }
        },
        messages: {
          'itg_smi[facebook]': {
            required: 'This field is required.'
          },
          'itg_facebook_narrative': {
            required: 'This field is required.'
          },
          'itg_fb_img[fid]': {
            required: 'This field is required.'
          },
          'itg_twitter_narrative': {
            required: 'This field is required.'
          },
          'itg_twitter_img[fid]': {
            required: 'This field is required.'
          }
        }
      });
      jQuery.validator.addMethod('validateSmi', function(value, element) {
        return FormValidation.validate_smi(value, element);
      }, 'This field is required.');
      // custom validator function end here.
      // Moduel code end.      
    }
  };
})(jQuery, Drupal, this, this.document);