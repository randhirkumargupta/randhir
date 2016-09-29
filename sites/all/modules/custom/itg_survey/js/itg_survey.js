/*
 * @file itg_survey.js
 */

(function($) {
  Drupal.behaviors.itg_survey = {
    attach: function(context, settings) {
      
      var uid = settings.itg_survey.settings.uid;
      var nid = settings.itg_survey.settings.nid;
      
      //Hide left side vertical tabs in case of simple users
      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        
      }

      if(nid == '' || nid == null){
        if($('input[name="field_survey_add_questions[und][0][field_survey_question][und][0][value]"]').val() == '' || $('input[name="field_survey_add_questions[und][0][field_survey_question][und][0][value]"]').val() == 'undefined') {
          $('input[name="field_survey_add_questions_und_0_remove_button"]').hide();
        }
      }

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

      //Collect values assigned in settings array 
      var type = settings.itg_survey.settings.type;

      // Make date fields readonly
      if (type === 'Survey') {
        $('#edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-start-date-und-0-value-datepicker-popup-2, #edit-field-survey-start-date-und-0-value-datepicker-popup-3, #edit-field-survey-end-date-und-0-value-datepicker-popup-0, #edit-field-survey-end-date-und-0-value-datepicker-popup-1, #edit-field-survey-end-date-und-0-value-datepicker-popup-2, #edit-field-survey-end-date-und-0-value-datepicker-popup-3').prop("readonly", true);
      }

      $("#survey-node-form").validate({ 
        submitHandler: function (form) {
          $('input:submit').attr('disabled', 'disabled');
          form.submit();
        },
        onfocusout: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
        errorPlacement: function (error, element) {
          var elementName = element.attr('name');
          var errorPlaceHolder = '';
          switch (elementName) {
            
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {
          'field_survey_add_questions[und][0][field_survey_answer_option_1][und][0][value]': {
            required: {
              depends: function() {
                var answerType = $('select[name="field_survey_add_questions[und][0][field_survey_answer_type][und]"]').find('option:selected').val();
                if (answerType != 'rating') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
          },
          'field_survey_add_questions[und][1][field_survey_answer_option_1][und][0][value]': {
            required: {
              depends: function() {
                var answerType = $('select[name="field_survey_add_questions[und][1][field_survey_answer_type][und]"]').find('option:selected').val();
                if (answerType != 'rating') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
          },
          'field_survey_add_questions[und][2][field_survey_answer_option_1][und][0][value]': {
            required: {
              depends: function() {
                var answerType = $('select[name="field_survey_add_questions[und][2][field_survey_answer_type][und]"]').find('option:selected').val();
                if (answerType != 'rating') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
          },
          'field_survey_add_questions[und][3][field_survey_answer_option_1][und][0][value]': {
            required: {
              depends: function() {
                var answerType = $('select[name="field_survey_add_questions[und][3][field_survey_answer_type][und]"]').find('option:selected').val();
                if (answerType != 'rating') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
          },
          'field_survey_add_questions[und][4][field_survey_answer_option_1][und][0][value]': {
            required: {
              depends: function() {
                var answerType = $('select[name="field_survey_add_questions[und][4][field_survey_answer_type][und]"]').find('option:selected').val();
                if (answerType != 'rating') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
          }

        },
                
        messages: {
          'field_survey_add_questions[und][0][field_survey_answer_option_1][und][0][value]': {
            required: 'Answer choices field is required.'
          },
          'field_survey_add_questions[und][1][field_survey_answer_option_1][und][0][value]': {
            required: 'Answer choices field is required.'
          },
          'field_survey_add_questions[und][2][field_survey_answer_option_1][und][0][value]': {
            required: 'Answer choices field is required.'
          },
          'field_survey_add_questions[und][3][field_survey_answer_option_1][und][0][value]': {
            required: 'Answer choices field is required.'
          },
          'field_survey_add_questions[und][4][field_survey_answer_option_1][und][0][value]': {
            required: 'Answer choices field is required.'
          }
        }
      });
      
    }
  };
})(jQuery, Drupal, this, this.document);