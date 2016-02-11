/*
 * @file itg_msi.js
 */

(function($) {
  Drupal.behaviors.itg_msi = {
    attach: function(context, settings) {
      
      var base_url = settings.itg_msi.settings.base_url;
    
      //Restrict print issue date to select previous date in magazine form 
      $('#edit-field-print-magazine-issue-date-und-0-value-datepicker-popup-0').datepicker({
        changeYear: true,
        minDate: '0',
        readonly: true
      });

      //Check duplicacy on title for magazine
      $('.page-node-add-magazine #edit-title').blur(function() {
        
        var pageUrl = window.location.href;
        var type = pageUrl.split(/[/ ]+/).pop();

        $(".form-item-title .title-exist-error").remove();
        var title = $('#edit-title').val();
        var trimmed_title = $.trim(title);
        
        //Call Ajax
        $.ajax({
          url: base_url + "/check-duplicate-title/" + type,
          type: 'post',
          data: {'title': trimmed_title},
          dataType: "JSON",
          success: function(data) {
            if (data.Code === 1) {
              $(".form-item-title").append($('<label class="title-exist-error error">' + type + ' title already exist.</label>'));
              $("#edit-submit").hide();
            }
            else {
              $("#edit-submit").show();
            }
          }
        });
      });
      
    }
 };
})(jQuery, Drupal, this, this.document);