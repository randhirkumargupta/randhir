/*
 * @file itg_story.js
 * Contains all functionality related to Blog
 */

(function($) {
    Drupal.behaviors.itg_blog = {
       attach: function(context, settings) {
         $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();                    
       }
    };
})(jQuery, Drupal, this, this.document);
