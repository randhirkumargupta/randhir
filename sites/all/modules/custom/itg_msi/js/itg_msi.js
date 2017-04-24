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
      
      //Collect values assigned in settings array 
      var base_url = settings.itg_msi.settings.base_url;
      var type = settings.itg_msi.settings.type;
      var nid = settings.itg_msi.settings.nid;

      //Restrict print issue date to select previous date in magazine form 
      if(type === 'Magazine'){
        $('#edit-field-print-magazine-issue-date-und-0-value-datepicker-popup-0, #edit-field-print-magazine-issue-date-und-0-value-datepicker-popup-1, #edit-field-print-magazine-issue-date-und-0-value-datepicker-popup-3').prop("readonly", true);
      }
      
      if(type === 'Supplement'){
        $('#edit-field-supp-issue-und-0-value-datepicker-popup-0, #edit-field-supp-issue-und-0-value-datepicker-popup-1, #edit-field-supp-issue-und-0-value-datepicker-popup-3').prop("readonly", true);
      }
      
      if(type === 'Issue'){
//        $('#edit-field-issue-title-und-0-value-datepicker-popup-0, #edit-field-issue-title-und-0-value-datepicker-popup-1').datepicker({
//          changeYear: true,
//          minDate: '0',
//          readonly: true
//        });
        $('#edit-field-issue-title-und-0-value-datepicker-popup-0, #edit-field-issue-title-und-0-value-datepicker-popup-1, #edit-field-issue-title-und-0-value-datepicker-popup-3').prop("readonly", true);
      } 
      
      //Check duplicacy on title for magazine
      $('#magazine-node-form #edit-title, #supplement-node-form #edit-title').blur(function() {
        $(".form-item-title .error").html('');
        var title = $('#edit-title').val();
        var trimmed_title = $.trim(title);
        
        //Call Ajax
        $.ajax({
          url: base_url + "/check-duplicate-title/" + type + '/'+nid,
          type: 'post',
          data: {'title': trimmed_title},
          dataType: "JSON",
          success: function(data) {
            if (data.Code === 1) {
              $(".form-item-title").append($('<span class="error">'+type+' title '+trimmed_title+' already exist.</span>'));
              //$('#magazine-node-form').submit(function () { return false; }); 
              //$("#edit-submit").prop('disabled', true);
            }
            else {
              $(".form-item-title .error").html('');
              //$("#edit-submit").prop('disabled', false);
            }
          }
        });
      });
    }
 };
})(jQuery, Drupal, this, this.document);