/*
 * @file itg_newsletter.js
 */

(function($) {
  Drupal.behaviors.itg_newsletter = {
    attach: function(context, settings) {
      
        //Collect required variables
        var uid = settings.itg_newsletter.settings.uid;
        var base_url = settings.itg_newsletter.settings.base_url;
        var type = settings.itg_newsletter.settings.type;
        var nid = settings.itg_newsletter.settings.nid;
        if(nid) {
          $('#edit-field-newsl-add-news-und-0-remove-button').show();
        }
        
       //Hide left side vertical tabs in case of simple users
       if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
       }

      
      //Collect values assigned in settings array 

    }
 };
})(jQuery, Drupal, this, this.document);