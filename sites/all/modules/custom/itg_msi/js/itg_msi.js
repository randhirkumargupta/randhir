/*
 * @file itg_msi.js
 */

(function($) {
  Drupal.behaviors.itg_msi = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_msi.settings.uid;
       if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
       }
      
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
              $(".form-item-title").append($('<span class="error">Magazine title '+trimmed_title+' already exist.</span>'));
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