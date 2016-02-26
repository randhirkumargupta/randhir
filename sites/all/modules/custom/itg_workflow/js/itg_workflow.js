/*
 * @file itg_story.js
 * Contains all functionality related to itg workflow
 */

(function($) {
    Drupal.behaviors.itg_workflow = {
         attach: function(context, settings) {
               var uid = settings.itg_story.settings.uid;

            // code for moderation value change on click of dropdown and save story 
             $('#story_submit_link').click(function() {
                 var story_state = $('#story_submit_link').attr('class').split(' ')[1];                     
                 $("#edit-workbench-moderation-state-new").val(story_state);
                 $("#edit-submit").click();
                 return false;                     
             });

        }

    };
})(jQuery, Drupal, this, this.document);
