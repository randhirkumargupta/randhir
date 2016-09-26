/*
 * @file itg_quiz_questions.js
 */

(function($) {
  Drupal.behaviors.itg_quiz_questions = {
    attach: function(context, settings) {

      // JS for quiz, if one question at a time
      $('#itg-quiz-quiz-form .quiz-submit').mousedown(function() {
        $(this).ajaxSuccess(function() {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      });
    }
  };
})(jQuery, Drupal, this, this.document);