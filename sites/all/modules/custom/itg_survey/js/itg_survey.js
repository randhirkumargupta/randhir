/*
 * @file itg_survey.js
 */

(function($) {
  Drupal.behaviors.itg_msi = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_survey.settings.uid;
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
      }

      //Collect values assigned in settings array 
      var base_url = settings.itg_survey.settings.base_url;
      var type = settings.itg_survey.settings.type;
      var nid = settings.itg_survey.settings.nid;

      //Restrict print issue date to select previous date in magazine form 
      if (type === 'Survey') {
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-end-date-und-0-value-datepicker-popup-0').datepicker({
          changeYear: true,
          minDate: '0',
          readonly: true
        });
      }
    }
  };
})(jQuery, Drupal, this, this.document);