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
                var msg = confirm("Hope you have Previewed the story before submitting. Do you want to continue to submit?");
                
                if (msg == true) {
                    $("#edit-submit").click();
                }
                
                return false;                     
             });
             
             $('#edit-submit').click(function() {                 
                 var moderation_state = $("#edit-workbench-moderation-state-new").val();
                 if (moderation_state == 'published') {                   
                    var msg = confirm("Hope you have Previewed the story before submitting. Do you want to continue to submit?");
                    if (msg == true) {
                        return true;
                    }
                    return false; 
                 }
                 return true;                     
             });

        }

    };
})(jQuery, Drupal, this, this.document);
