/*
 * @file itg_quiz_questions.js
 */

(function($) {
  Drupal.behaviors.itg_quiz_questions = {
    attach: function(context, settings) {

      // If one question at a time
      $('#itg-quiz-quiz-form .quiz-submit').mousedown(function() {
        var quizTaken = $('body').find('input[name="quiz_taken"]').val();
        $(this).ajaxSuccess(function() {
          if (quizTaken == 'no') {
            $('.question-container').hide();
            $('.answer-container-actual').empty();
            $(this).parents('.question-container').next().show();
          }
        });
      });
    }
  };
})(jQuery, Drupal, this, this.document);