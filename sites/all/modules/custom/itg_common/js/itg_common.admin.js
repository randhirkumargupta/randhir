/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
  Drupal.behaviors.itg_common_admin = {
    attach: function (context, settings) {     

      var uid = settings.itg_common.settings.uid;  
      // checkbox hide for all user of Provide a menu link on all form
      if (uid != 1) {
        jQuery(".form-item-menu-enabled").hide();  
      }
      jQuery("#edit-field-highlights-und-0-remove-button").hide(); 

    }

  };
})(jQuery, Drupal, this, this.document);