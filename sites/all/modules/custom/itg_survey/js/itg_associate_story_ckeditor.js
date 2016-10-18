/*
 * @file itg_associate_story_ckeditor.js
 */

(function($) {
  Drupal.behaviors.itg_associate_story_ckeditor = {
    attach: function() {
      
      $('#add-pqs').on('click', function() {
        
        var appendText = "";
        $('.form-checkbox').each(function() {
          if ($(this).is(':checked'))
          {
            appendText = appendText + $(this).val() + ',';
          }

        });
        appendText = appendText.slice(0,-1);
        var curr_url = window.location.href;
        var type = curr_url.split('/').pop();

//        if(type == 'poll') {
//          var element_id = window.opener.document.getElementsByClassName("cke_dialog_ui_input_text")[1].getAttribute("id");
//        }
//        if(type == 'quiz') {
//          var element_id = window.opener.document.getElementsByClassName("cke_dialog_ui_input_text")[3].getAttribute("id");
//        }
//        if(type == 'survey') {
//          var element_id = window.opener.document.getElementsByClassName("cke_dialog_ui_input_text")[5].getAttribute("id");
//        }

        var items = window.opener.document.getElementsByClassName("cke_dialog_ui_input_text");
        for (var i = 0; i < items.length; i++) {
          if (items[i].id) {
            var element_id = items[i].id;
          }
        }
        window.opener.document.getElementById(element_id).value = appendText;
        window.close();
      });
    }
  };
})(jQuery, Drupal, this, this.document);