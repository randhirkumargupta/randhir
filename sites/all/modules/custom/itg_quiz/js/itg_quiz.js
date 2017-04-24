/*
 * @file itg_quiz.js
 */

(function($) {
  Drupal.behaviors.itg_quiz = {
    attach: function(context, settings) {
      
      // Collect variables
      var uid = settings.itg_quiz.settings.uid;
      var nid = settings.itg_quiz.settings.nid;
      var type = settings.itg_quiz.settings.type;
      
      // If user is not drupal admin
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
      }
   
     // Hide "Remove" button initially which comes after clicking of "Add More"
      if(nid == '' || nid == null) {
       if($('input[name="field_quiz_add_questions[und][0][field_survey_question][und][0][value]"]').val() == '' || $('input[name="field_quiz_add_questions[und][0][field_survey_question][und][0][value]"]').val() == 'undefined') {
          $('input[name="field_quiz_add_questions_und_0_remove_button"]').hide();
        }
      }
         
      // JS for date fields 
      if (type === 'Quiz') {
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-start-date-und-0-value-datepicker-popup-2, #edit-field-survey-start-date-und-0-value-datepicker-popup-3, #edit-field-survey-end-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup, #edit-field-survey-end-date-und-0-value-datepicker-popup-2, #edit-field-survey-end-date-und-0-value-datepicker-popup-3').prop("readonly", true);
      }
      
      // JS for immediate and contest type radio buttons
      if ($("input[name='field_quiz_type[und]']:checked").val() === 'immediate') {
        $('#edit-field-quiz-immediate-result').show();
        $('#edit-field-quiz-winners').hide();
      } else {
        $('#edit-field-quiz-immediate-result').hide();
        $('#edit-field-quiz-winners').show();
      }

      $("input[name='field_quiz_type[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name == 'immediate') {
          $('#edit-field-quiz-immediate-result').show();
          $('#edit-field-quiz-winners').hide();
        } else {
          $('#edit-field-quiz-immediate-result').hide();
          $('#edit-field-quiz-winners').show();
        }
      });
      
      // JS for scoring type treatment (Normal | Weightage)
      if ($("input[name='field_quiz_scoring_type[und]']:checked'").val() === 'weight') {
        $('.field-name-field-quiz-weightage').show();
      } else {
        $('.field-name-field-quiz-weightage').hide();
      }

      $("input[name='field_quiz_scoring_type[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name == 'normal') {
          $('.field-name-field-quiz-weightage').hide();
        } else {
          $('.field-name-field-quiz-weightage').show();
        }
      });
      
      // JS for expiry date
      if($('input[name="field_survey_expity_date[und][1]"]').prop("checked") == true){
        $('#edit-field-survey-end-date').show();
      } else {
        $('#edit-field-survey-end-date').hide();
      }
      
      $('input[name="field_survey_expity_date[und][1]"]').click(function (){
        if($(this).prop("checked") == true){
          $('#edit-field-survey-end-date').show();
        } else {
          $('#edit-field-survey-end-date').hide();
        }
      });
    
    }
  };
})(jQuery, Drupal, this, this.document);

