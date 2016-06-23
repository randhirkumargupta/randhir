(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.it_autosave = {
    attach: function (context, settings) {
      // Place your code here.
      var autoSaveFormObj = Drupal.settings.autoSave;             
      var formName = $('.page-node input[name="form_id"]').val();
      if (formName != undefined && formName.length != 0) {
        for (var property in autoSaveFormObj) {          
          if (formName === property) {
            var formId =  formName.replace(/_/g, '-');
            auto_save(formName, formId);
          }
        }
      }
      
      // Auto save function
      function auto_save(formName, formId) {
        setInterval(function () {
          for (instance in CKEDITOR.instances) {
            CKEDITOR.instances[instance].updateElement();
          }
          $.ajax({
            url: autoSaveFormObj.baseUrl + '/autosave/nodeform',
            type: "post",
            data: $("#" + formId).serialize(),
            success: function (d) {
              var cus_message1 = '<div class="messages status">Sports Lifex Box score form data have been successfully auto saved</div>';
              $('.sportslifexbox-message-global').html(cus_message1);
              $('.sportslifexbox-message-global .messages').fadeIn(10000).delay(10000).fadeTo("slow", 0.6).delay(3000).fadeOut("slow");
              $('#sportslifex-boxscore-form').fadeTo(300, 1.0);

            }
          });

        //}, autoSaveFormObj[formName]["autoSave"] * 1000);
      }, 5000);
      }
      
      
    // End module code  
    }
  };
})(jQuery, Drupal, this, this.document);
