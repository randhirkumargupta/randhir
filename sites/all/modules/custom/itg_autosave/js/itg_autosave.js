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
        autosave_for_settings: function () {
          var form_ids = Drupal.settings.itg_autosave.auto_settings;          
          var formName = $('.page-node input[name="form_id"]').val();
          if (formName != undefined && formName.length != 0) {
            for (var property in form_ids) {
              if (formName === property) {
                var formId = formName.replace(/_/g, '-');
                var time_int = form_ids[formName][1];
                FormValidation.autosave_set_interval(formName, formId, time_int);                
              }
            }
          }
        },
        autosave_set_interval: function (formName, formId, time_int) {          
          // Auto save function                    
          setInterval(function () {
            var base_url = Drupal.settings.itg_autosave.base_url;
            var node_id = Drupal.settings.itg_autosave.nid;
            var ctype = Drupal.settings.itg_autosave.c_type;
            if ($('textarea').hasClass('ckeditor-mod')) {
              for (instance in CKEDITOR.instances) {
                CKEDITOR.instances[instance].updateElement();
              }
            }            
            $.ajax({
              url: base_url + '/itg-autosave/nodeform/' + node_id + '/' + ctype,
              type: "post",
              data: $("#" + formId).serialize(),
              success: function (d) {
                $('#console').find('.autosave').remove();
                var cus_message1 = '<div class="messages status autosave">Form data have been successfully auto saved</div>';
                $('#console').append(cus_message1);
                $('#console').find('.autosave').fadeOut(10000);
              }
            });

            
          }, time_int * 1000);
        }
      };
      
      if ($('body').hasClass('page-node-edit') || $('body').hasClass('page-node-add')) {
        
        FormValidation.autosave_for_settings();
      }
      
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