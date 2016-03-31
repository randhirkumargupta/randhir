/*
 * @file itg_quiz.js
 */

(function($) {
  Drupal.behaviors.itg_quiz = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_quiz.settings.uid;
      var nid = settings.itg_quiz.settings.nid;
      
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        
      }
   
      if(nid == ''){
        $('#edit-field-quiz-add-questions-und-0-remove-button').hide();
      }

      //Collect values assigned in settings array 
      var base_url = settings.itg_quiz.settings.base_url;
      var type = settings.itg_quiz.settings.type;
      var nid = settings.itg_quiz.settings.nid;

      //Restrict print issue date to select previous date in magazine form 
      if (type === 'Survey') {
        $('#edit-field-quiz-start-date-und-0-value-datepicker-popup-0, #edit-field-quiz-start-date-und-0-value-datepicker-popup-1, #edit-field-quiz-end-date-und-0-value-datepicker-popup-0, #edit-field-quiz-end-date-und-0-value-datepicker-popup-1').datepicker({
          changeYear: true,
          minDate: '0',
        });
        $('#edit-field-quiz-start-date-und-0-value-datepicker-popup-0, #edit-field-quiz-start-date-und-0-value-datepicker-popup-1, #edit-field-quiz-end-date-und-0-value-datepicker-popup-0, #edit-field-quiz-end-date-und-0-value-datepicker-popup-1').prop("readonly", true);
      }
    }
  };
})(jQuery, Drupal, this, this.document);