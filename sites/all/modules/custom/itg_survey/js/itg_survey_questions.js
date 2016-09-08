/*
 * @file itg_survey_questions.js
 */

(function($) {
  Drupal.behaviors.itg_survey_questions = {
    attach: function(context, settings) {
      // JS for survey, if one question at a time
      
      $('.survey-submit, .survey-submit-skip').mousedown(function () {
      var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
      var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
      var textValue = $(this).parents('.question-container').find('.form-text').val();
      var skipValue = $(this).parents('.question-container').find('.question-skip').val();
      var surveyTaken = $('body').find('input[name="survey_taken"]').val();

      if (checkValue && skipValue == 'no' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

      if (radioValue && skipValue == 'no' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

      if (textValue && skipValue == 'no' && textValue != 'undefined' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

    });

    var loader = '<div class="ajax-loader"><img src="sites/all/themes/itgadmin/images/loader.svg" alt=""/></div>';

    $('#itg-survey-survey-form .button-yes').mousedown(function () {
      var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
      var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
      var textValue = $(this).parents('.question-container').find('.form-text').val();
      var skipValue = $(this).parents('.question-container').find('.question-skip').val();

      if (checkValue && skipValue == 'no') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });

      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }

      if (radioValue && skipValue == 'no') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }

      if (textValue && skipValue == 'no' && textValue != 'undefined') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }
    });
    }
  };
})(jQuery, Drupal, this, this.document);