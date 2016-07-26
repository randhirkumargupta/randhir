/*
 * @file itg_loyalty_reward.js
 */

(function($) {
  Drupal.behaviors.itg_loyalty_reward = {
    attach: function(context, settings) {

      var uid = settings.itg_loyalty_reward.settings.uid;
      var nid = settings.itg_loyalty_reward.settings.nid;

     
      // If user is not drupal admin
      if (uid !== 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        
      }
    }
  };
})(jQuery, Drupal, this, this.document);