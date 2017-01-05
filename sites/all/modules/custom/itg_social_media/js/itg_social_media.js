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
          'itg_twitter_narrative': {
            required: true
          },
          },
        messages: {
          'itg_twitter_narrative': {
            required: 'This field is required.'
          }
        }
      });
      jQuery.validator.addMethod("validateRange", function (value, element) {
        return validate_date_range(value, element);
      }, "Please enter valid date.");
      jQuery.validator.addMethod("validateSignName", function (value, element) {
        return validate_sign_name_value(value, element);
      }, "This field is required.");
      jQuery.validator.addMethod("validate_astro_category", function (value, element) {
        return validate_astro_category_name(value, element);
      }, "This field is required.");      
      // Moduel code end.      
    }
  };
})(jQuery, Drupal, this, this.document);