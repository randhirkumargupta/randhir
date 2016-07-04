/**
 * @file
 * A javascript file for itg_autosave module. *
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_autosave = {
    attach: function (context, settings) {
      // Place your code here.
      // Callback function for custom methods.      
      var FormValidation = {
        // Validate Social Media Integration checkboxes.
        base_url: function () {
          return Drupal.settings.itg_autosave.base_url;
        },
        autosave_for_settings: function() {          
          var form_ids = Drupal.settings.itg_autosave.auto_settings;
        } 
      };
      
      FormValidation.autosave_for_settings();
      // Custom validator function for social media start
      $("#itg-autosave-form").validate({
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
          'itg_form_id': {
            required: true,
            validate_form_id: true,
          },
          'time_interval': {
            required: true,
            number: true
          }
        },
        messages: {
          'itg_form_id': {
            required: 'This field is required.',            
          },
          'time_interval': {
            required: 'This field is required.'
          }
        }
      });
      jQuery.validator.addMethod("validate_form_id", function (value, element) {
        return this.optional(element) || /^[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*$/.test(value);
      }, 'Please enter valid form id.');
      // Custom validator function end here.

      // Custom code ends here
    }
  };


})(jQuery, Drupal, this, this.document);