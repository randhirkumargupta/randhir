/*
 * @file itg_story.js
 * Contains all functionality related to Blog
 */

(function($) {
    Drupal.behaviors.itg_blog = {
       attach: function(context, settings) {
         $('.tabledrag-toggle-weight-wrapper a.tabledrag-toggle-weight').hide();
         // Code for client Title field value set Null
            $('#edit-field-blog-configuration-und-commentbox').click(function() {
                if ($("#edit-field-blog-configuration-und-commentbox").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });
       }
    };
})(jQuery, Drupal, this, this.document);
