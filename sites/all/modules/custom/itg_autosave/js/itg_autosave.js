/**
 * @file
 * A javascript file for itg_autosave module.
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
          var form_name = $('.page-node input[name="form_id"]').val();
          if (form_name != undefined && form_name.length != 0) {
            for (var property in form_ids) {
              if (form_name === property) {
                var form_id = form_name.replace(/_/g, '-');
                var time_int = form_ids[form_name][1];
                FormValidation.autosave_set_interval(form_name, form_id, time_int);
              }
            }
          }
        },
        autosave_set_interval: function (form_name, form_id, time_int) {
          // Auto save function.
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
              data: $("#" + form_id).serialize(),
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

      // Custom code ends here.
    }
  };
})(jQuery, Drupal, this, this.document);
