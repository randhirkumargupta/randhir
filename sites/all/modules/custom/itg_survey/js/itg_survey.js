/*
 * @file itg_survey.js
 */

(function($) {
  Drupal.behaviors.itg_survey = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_survey.settings.uid;
      var nid = settings.itg_survey.settings.nid;
      
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        
      }
   
      if(nid == ''){
        $('#edit-field-survey-add-questions-und-0-remove-button').hide();
      }

      //Collect values assigned in settings array 
      var base_url = settings.itg_survey.settings.base_url;
      var type = settings.itg_survey.settings.type;
      var nid = settings.itg_survey.settings.nid;

      //Restrict print issue date to select previous date in magazine form 
      if (type === 'Survey') {
        $('edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup-0, edit-field-survey-end-date-und-0-value-datepicker-popup-1').datepicker({
          changeYear: true,
          minDate: '0',
          readonly: true
        });
        $('edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup-0, edit-field-survey-end-date-und-0-value-datepicker-popup-1').prop("readonly", true);
      }
    }
  };
})(jQuery, Drupal, this, this.document);