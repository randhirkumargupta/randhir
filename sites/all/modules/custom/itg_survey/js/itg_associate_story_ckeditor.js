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
        window.opener.document.getElementById("cke_199_textInput").value = appendText;
        window.close();
      });
    }
  };
})(jQuery, Drupal, this, this.document);