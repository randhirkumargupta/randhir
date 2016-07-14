/*
 * @file itg_podcast.js
 * Contains all functionality related to podcast
 */

(function($) {
        Drupal.behaviors.itg_podcast = {
             attach: function(context, settings) {
                   var uid = settings.itg_podcast.settings.uid;
                   if (uid != 1) {
                        $('.vertical-tabs-list').hide();
                        $('#edit-metatags').show();
                        $('#edit-metatags-und-advanced').hide();
                        $('.fieldset-description').hide();
                        $('#edit-metatags p').hide();
                   }
             }

 };
})(jQuery, Drupal, this, this.document);
