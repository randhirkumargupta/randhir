/*
 * @file itg_quiz_front.js
 */

(function($) {
  Drupal.behaviors.itg_quiz_front = {
    attach: function(context, settings) {
      
      // Hide title form take quiz page
      var quizStr = $(location).attr('href');
      if (quizStr.indexOf("itg-quiz") > 0) {
        $("#page-title").hide();
      }
    }
  };
})(jQuery, Drupal, this, this.document);