/*
 * @file itg_ask_expert.js
 * Contains all functionality related to Ask an Expert
 */

(function ($) {
  Drupal.behaviors.itg_ask_expert = {
    attach: function (context, settings) {
      var uid = settings.itg_ask_expert.settings.uid;
           // code to hide body text format filter 
      if (uid != 1) {        
        $('#edit-field-user-message-und-0-format').hide();        
      }
    }

  };
})(jQuery, Drupal, this, this.document);

