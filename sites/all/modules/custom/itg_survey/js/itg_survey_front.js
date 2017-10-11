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

// Unable to press First space bar on survey page
jQuery(document).ready(function () {
    if (jQuery("body").hasClass("node-type-survey")) {
        jQuery( ".answer-container" ).on('keypress', 'input[type="text"]', function(event) {
          var inputVal = jQuery(this).val();
          if (inputVal.length <= 0 && event.which === 32) {
              event.preventDefault();
          }
        });
    }
});