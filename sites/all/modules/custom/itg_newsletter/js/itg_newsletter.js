/*
 * @file itg_newsletter.js
 */

(function($) {
  Drupal.behaviors.itg_newsletter = {
    attach: function(context, settings) {
      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_newsletter.settings.uid;
       if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
       }
      
      //Collect values assigned in settings array 
      var base_url = settings.itg_newsletter.settings.base_url;
      var type = settings.itg_newsletter.settings.type;
      var nid = settings.itg_newsletter.settings.nid; 
    }
 };
})(jQuery, Drupal, this, this.document);