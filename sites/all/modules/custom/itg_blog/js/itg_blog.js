/*
 * @file itg_story.js
 * Contains all functionality related to Blog
 */

(function($) {

    Drupal.behaviors.itg_blog = {
       attach: function(context, settings) {
         $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
               var uid = settings.itg_blog.settings.uid;
                        // code to hide body text format filter 
                        if (uid != 1) {
                          $('#edit-path').show();
                        }        
        }
    };
})(jQuery, Drupal, this, this.document);
