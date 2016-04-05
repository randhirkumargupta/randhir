/*
 * @file itg_quiz.js
 */

(function($) {
  Drupal.behaviors.itg_quiz = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_quiz.settings.uid;
      var nid = settings.itg_quiz.settings.nid;
      
      //Code by shravan
      //$('#edit-field-quiz-add-questions-und-0-field-quiz-options-answer-und-0-field-quiz-answer-text-und-0-value').hide();
//      $('#edit-field-quiz-add-questions-und-0-field-quiz-options-answer-und-0-field-quiz-answer-image-und-0-ajax-wrapper').hide();
//      $('#edit-field-quiz-add-questions-und-0-field-quiz-options-answer-und-0-field-quiz-answer-video-und-0-ajax-wrapper').hide();
//       $('#selectMe').change(function () {
//        //$('.group').hide();
//        //$('#'+$(this).val()).show();
//        })
//        
//        jQuery(this).attr("id");
      
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        
      }
   
      if(nid == ''){
        $('#edit-field-quiz-add-questions-und-0-remove-button').hide();
        $('#edit-field-quiz-add-questions-und-0-field-quiz-options-answer-und-0-remove-button').hide();
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
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup-1').prop("readonly", true);
      }
      
      //Number of answer option select functionality
      $('.field-name-field-quiz-option-1, .field-name-field-quiz-option-2, .field-name-field-quiz-option-3, .field-name-field-quiz-option-4, .field-name-field-quiz-option-5').hide();
      var ans_op_val = $('#edit-field-quiz-options-und').val();
      for(var ans_op_ini = 1; ans_op_ini <= ans_op_val; ans_op_ini++){
         $('.field-name-field-quiz-option-'+ans_op_ini).show();
       }
       
      $('#edit-field-quiz-options-und').change(function (){
       $('.field-name-field-quiz-option-1, .field-name-field-quiz-option-2, .field-name-field-quiz-option-3, .field-name-field-quiz-option-4, .field-name-field-quiz-option-5').hide();
       for(var ans_op = 1; ans_op <= $(this).val(); ans_op++){
         $('.field-name-field-quiz-option-'+ans_op).show();
       }
      });
      
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