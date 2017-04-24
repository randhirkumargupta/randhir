/*
 * @file itg_associate_story_ckeditor.js
 */

(function($) {
  Drupal.behaviors.itg_associate_story_ckeditor = {
    attach: function() {

      // Only one id can be attached to a story
      $('input.pqs-listing-options').on('change', function() {
        $('input.pqs-listing-options').not(this).prop('checked', false);
      });

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