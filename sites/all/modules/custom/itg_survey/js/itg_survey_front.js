/*
 * @file itg_survey_front.js
 */

(function($) {
  Drupal.behaviors.itg_survey = {
    attach: function(context, settings) {
      
      // Hide title form take survey page
      var surveyStr = $(location).attr('href');
      if (surveyStr.indexOf("itg-survey") > 0) {
        $("#page-title").hide();
      }
    }
  };
})(jQuery, Drupal, this, this.document);