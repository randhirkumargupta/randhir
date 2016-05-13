/*
 * @file itg_event_registration.js
 */

(function($) {
  Drupal.behaviors.itg_event_registration = {
    attach: function(context, settings) {
      
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_event_registration.settings.uid;
      var nid = settings.itg_event_registration.settings.nid;

      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
      }
      
      //Hide skip button
      $('#edit-skip').hide();
      $('#edit-skip-1').hide();

      if(nid == '' || nid == null){
        if($('input[name="field_erf_registration[und][0][field_first_name][und][0][value]"]').val() == '' || $('input[name="field_erf_registration[und][0][field_first_name][und][0][value]"]').val() == 'undefined') {
          $('input[name="field_erf_registration_und_0_remove_button"]').hide();
        }
      }
      
      //Validation of event registration fields
      $('#edit-field-last-name-und-0-value, #edit-title').keyup(function() {
        this.value = this.value.replace(/[^a-zA-Z\s.]/g, '');
      });
      
      $('#edit-field-erf-mobile-und-0-value, #edit-field-erf-postal-code-und-0-value').keyup(function() {
        this.value = this.value.replace(/[^0-9]/g, '');
      });
    }
  };
})(jQuery, Drupal, this, this.document);