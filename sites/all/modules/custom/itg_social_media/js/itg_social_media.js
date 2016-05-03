(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_social_media = {
    attach: function (context, settings) {
      
      // Module code start
      var FormValidation = {
        current_date: function () {
          return true;
        }
      };
      // Moduel code end

      // Custom validator function for social media start
      $("#astro-node-form").validate({
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
            case 'field_astro_frequency[und]':
              errorPlaceHolder = $('#edit-title').parent();
              break;            
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {},
        messages: {}
      });
      // custom validator function end here.
      
    }
  };
})(jQuery, Drupal, this, this.document);