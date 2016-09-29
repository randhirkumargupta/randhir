/*
 * @file itg_quiz_front.js
 */

(function($) {
  Drupal.behaviors.itg_quiz_front = {
    attach: function() {

      // Hide title form take quiz page
      var quizStr = $(location).attr('href');
      if (quizStr.indexOf("itg-quiz") > 0) {
        $("#page-title").hide();
      }

      // Scroll at top to show result in case of all question at a time
      if ($("input[name=question_format]").val() == 'All questions at a time') {
        $('#itg-quiz-quiz-form .quiz-submit').mousedown(function() {
          $(this).ajaxSuccess(function() {
            $('html, body').animate({
              scrollTop: $(".survey-form-main-container").offset().top
            }, 1000);
          });
        });
      }
    }
  };
})(jQuery, Drupal, this, this.document);