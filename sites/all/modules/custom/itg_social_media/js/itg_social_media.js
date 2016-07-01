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
        }
      };

      // Custom validator function for social media start
      $("#itg-social-media-form").validate({          
        onfocusout: function (element) {
          $(element).valid();
        },
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
          'itg_twitter_narrative': {
            itg_maxlength: {
              depends: function() {
                var twitter = $('input[name="itg_smi[twitter]"]').is(':checked');
                if (twitter) {
                  return true;
                }
              } 
            }
          },
          'field_story_twitter_video_desc': {
            itg_maxlength: {
              depends: function() {
                var twitter = $('input[name="itg_smi[twitter]"]').is(':checked');
                if (twitter) {
                  return true;
                }
              } 
            }
          },
          'itg_facebook_narrative': {
            required: {
              depends: function () {
                var fid = jQuery('body').find('input[name="itg_fb_img[fid]"]').val();                
                if (fid > 0) {
                  return true;                  
                }                
              }
            }
          },
          'itg_facebook_video_text': {
            required: {
              depends: function () {
                var fid = jQuery('body').find('input[name="itg_fb_video[fid]"]').val();                
                if (fid > 0) {
                  return true;                  
                }                
              }
            }
          }
        },
        messages: {
          'itg_smi[facebook]': {
            required: 'This field is required.'
          },
          'itg_facebook_video_text': {
            required: 'This field is required.'
          },
          'itg_facebook_narrative': {
            required: 'This field is required.'
          }
        }
      });
      jQuery.validator.addMethod('validateSmi', function (value, element) {
        return FormValidation.validate_smi(value, element);
      }, 'Please choose at least one social media platform.');
      jQuery.validator.addMethod("itg_maxlength", function (value, element) {
        return value == "" || value.length <= 126;
      }, 'This field can not exceed 126 characters.');
      // custom validator function end here.
       
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
      
      // Moduel code end.      
    }
  };
})(jQuery, Drupal, this, this.document);