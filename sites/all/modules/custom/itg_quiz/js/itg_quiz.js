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
   
     //Hide "Remove" button initially which comes after clicking of "Add More"
      if(nid == '' || nid == null){
       if($('input[name="field_quiz_add_questions[und][0][field_survey_question][und][0][value]"]').val() == '' || $('input[name="field_quiz_add_questions[und][0][field_survey_question][und][0][value]"]').val() == 'undefined') {
          $('input[name="field_quiz_add_questions_und_0_remove_button"]').hide();
        }
      }
     
      //Collect values assigned in settings array 
      var base_url = settings.itg_quiz.settings.base_url;
      var type = settings.itg_quiz.settings.type;
      var nid = settings.itg_quiz.settings.nid;
      


      //Restrict print issue date to select previous date in magazine form 
      if (type === 'Quiz') {
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup-1').datepicker({
          changeYear: true,
          minDate: '0',
        });
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-start-date-und-0-value-datepicker-popup-2, #edit-field-survey-start-date-und-0-value-datepicker-popup-3, #edit-field-survey-end-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup, #edit-field-survey-end-date-und-0-value-datepicker-popup-2, #edit-field-survey-end-date-und-0-value-datepicker-popup-3').prop("readonly", true);
      }
      
      //Immediate and contest type radio button treatment
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
      
      //Scoring type treatment(Normal|Weightage)
      if ($("input[name='field_quiz_scoring_type[und]']:checked'").val() === 'weight') {
        $('.field-name-field-quiz-weightage').show();
        //$('.quiz-weightage-backup').remove();

      } else {
        $('.field-name-field-quiz-weightage').hide();
        //$('.field-name-field-quiz-answer-type').after("<div class='quiz-weightage-backup'>&nbsp;</div>");

      }

      $("input[name='field_quiz_scoring_type[und]']").on("click", function() {
        var check_radio_name = $(this).val();
        if (check_radio_name == 'normal') {
          $('.field-name-field-quiz-weightage').hide();
          //$('.field-name-field-quiz-answer-type').after("<div class='quiz-weightage-backup'>&nbsp;</div>");
        } else {
          $('.field-name-field-quiz-weightage').show();
          //$('.quiz-weightage-backup').remove();
        }
      });
      
      //Expiry date treatment
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
      
      //Remove "quiz-weightage-backup" dic on click of Add more answer option button
      $('.field-name-field-quiz-options-answer .field-add-more-submit, .field-name-field-quiz-options-answer .button-remove').mousedown(function(){
        //$('.quiz-weightage-backup').remove();
      })
     
      
      //Answer Option
      $('.field-name-field-quiz-option-1-text, .field-name-field-quiz-option-1-media, .field-name-field-quiz-option-2-text, .field-name-field-quiz-option-2-media').hide();
      var ans_op_def1 = $('#edit-field-quiz-add-questions-und-0-field-quiz-option-1-und').val();
      var ans_op_def2 = $('#edit-field-quiz-add-questions-und-0-field-quiz-option-2-und').val();
      if (ans_op_def1 == 'text') {
        $('.field-name-field-quiz-option-1-text').show();
      } else {
        $('.field-name-field-quiz-option-1-media').show();
      }

      if (ans_op_def2 == 'text') {

        $('.field-name-field-quiz-option-2-text').show();
      } else {
        $('.field-name-field-quiz-option-2-media').show();
      }

      $('#edit-field-quiz-add-questions-und-0-field-quiz-option-1-und').change(function() {
        $('.field-name-field-quiz-option-1-text, .field-name-field-quiz-option-1-media').hide();
        if ($(this).val() == 'text') {
          $('.field-name-field-quiz-option-1-text').show();
        } else {
          $('.field-name-field-quiz-option-1-media').show();
        }
      });

      $('#edit-field-quiz-add-questions-und-0-field-quiz-option-2-und').change(function() {
        $('.field-name-field-quiz-option-2-text, .field-name-field-quiz-option-2-media').hide();
        if ($(this).val() == 'text') {
          $('.field-name-field-quiz-option-2-text').show();
        } else {
          $('.field-name-field-quiz-option-2-media').show();
        }
      });
      
    }
  };
})(jQuery, Drupal, this, this.document);