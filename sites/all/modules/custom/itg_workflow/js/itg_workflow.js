/*
 * @file itg_story.js
 * Contains all functionality related to itg workflow
 */

(function($) {
    Drupal.behaviors.itg_workflow = {
         attach: function(context, settings) {
             /*var uid = settings.itg_story.settings.uid;
             // code for moderation value change on click of dropdown and save story            
             $('#story_submit_link').click(function() {
                var story_state = $('#story_submit_link').attr('class').split(' ')[1];                     
                $("#edit-workbench-moderation-state-new").val(story_state);
                $("#edit-submit").click();                                 
             });
             
             $('#edit-submit').click(function() {                 
                 var moderation_state = $("#edit-workbench-moderation-state-new").val();
                 if (moderation_state == 'published' || moderation_state == 'needs_review') {                   
                    var msg = confirm("Hope you have Previewed the story before submitting. Do you want to continue to submit?");
                    if (msg == true) {
                        return true;
                    }
                    return false; 
                 }
                 return true;                     
             });*/

        }

    };
})(jQuery, Drupal, this, this.document);

// code for moderation value change on click of dropdown and save story 
jQuery(document).ready(function() {               
    jQuery('#story_submit_link').click(function() {
       var story_state = jQuery('#story_submit_link').attr('class').split(' ')[1];                     
       jQuery("#edit-workbench-moderation-state-new").val(story_state);
       jQuery("#edit-submit").click();                                    
    });

    jQuery('#edit-submit').click(function() {                 
        var moderation_state = jQuery("#edit-workbench-moderation-state-new").val();
        if (moderation_state == 'published' || moderation_state == 'needs_review') {                   
           var msg = confirm("Hope you have Previewed the story before submitting. Do you want to continue to submit?");
           if (msg == true) {
               return true;
           }
           return false; 
        }
        return true;                     
    });                  
});
