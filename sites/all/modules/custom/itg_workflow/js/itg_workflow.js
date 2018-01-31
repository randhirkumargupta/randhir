/*
 * @file itg_story.js
 * Contains all functionality related to itg workflow
 */
// hide workbench dropdown
//jQuery(document).ready(function() {
//    alert('@@@@');
//                  
//});

(function($) {
    Drupal.behaviors.itg_workflow = {
         attach: function(context, settings) {
             var workflowState = settings.itg_workflow.settings.mstate;
             
             jQuery("#edit-revision-information").show();
             jQuery(".form-item-workbench-moderation-state-new").hide();
             jQuery("#edit-field-story-archive").hide();
             
             if (workflowState == 'needs_review') {
                jQuery(".form-item-workbench-moderation-state-new").show();
                jQuery(".reasons-form").hide();              
                jQuery("#edit-log").val("");

                 /*jQuery("#edit-workbench-moderation-state-new").change(function() {
                  jQuery("#edit-log").val("");
                  if(jQuery("#edit-workbench-moderation-state-new").val() == "rejected") {                  
                    jQuery(".form-item-log").hide();
                    jQuery("#edit-log").val(jQuery(".reasons-form-msg").val());
                    jQuery(".reasons-form").show();

                    jQuery(".reasons-form-msg").change(function() {
                      jQuery("#edit-log").val(jQuery(".reasons-form-msg").val());
                    });
                  } else {
                    jQuery(".form-item-log").show();
                    jQuery(".reasons-form").hide();
                  }
                });*/
             }
             if (workflowState == 'needs_modification') {
                jQuery("#edit-workbench-moderation-state-new").val("needs_modification");
             }
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
    jQuery(".preview-btn").on("click", function(){
        jQuery("#story_submit_link").addClass("clicked-previewed");
    });
    jQuery('#story_submit_link').click(function() {       
       var previwed = jQuery( "#story_submit_link" ).hasClass( "clicked-previewed" );
       var story_state = jQuery('#story_submit_link').attr('class').split(' ')[1];
       var title = jQuery('#edit-title').val();
       var ndtype = jQuery('[name="ndtype"]').val();
       
       if ((story_state == 'published' || story_state == 'needs_review') && (!previwed)) {           
           if(ndtype) {
           var msg = confirm("Hope you have Previewed the " + ndtype + " before submitting. Do you want to continue to submit?");
       }
       
        if (msg == true) {
            if(title != '') {
                jQuery("#edit-workbench-moderation-state-new").val(story_state);
            }
             jQuery("#edit-submit").click();
             return true;
        }
        setTimeout($.proxy(function () {
            jQuery(this).parent().children().css('pointer-events', 'auto');
            jQuery(this).parent().children().css('background-color', '');
            jQuery(this).parent().children().css('border-color', '');
            jQuery(this).parent().children().last().css('background-color', '#ee4d4d');
            jQuery(this).parent().children().last().css('border-color', '#ee4d4d');
            jQuery('.top-actions').children().css('pointer-events', 'auto');
            jQuery('.top-actions').children().css('background-color', '');
            jQuery('.top-actions').children().css('border-color', '');
            jQuery('.top-actions').children().last().css('background-color', '#ee4d4d');
            jQuery('.top-actions').children().last().css('border-color', '#ee4d4d');
        }, this), 500);
        return false; 
       } else {
            if(title != '') {
                jQuery("#edit-workbench-moderation-state-new").val(story_state);
            }
            jQuery("#edit-submit").click();
       }
        
    });

    jQuery('.edit-submit-class').click(function() {
        var previwed = jQuery( "#story_submit_link" ).hasClass( "clicked-previewed" );
       
        if(jQuery(this).hasClass('btn-trigger') == true) {
           return false; 
        }
        else {
            var ndtype = jQuery('[name="ndtype"]').val();
            var moderation_state = jQuery("#edit-workbench-moderation-state-new").val();
            if (moderation_state == 'published') { 
                if (ndtype) {
                    var msg = confirm("Hope you have Previewed the " + ndtype + " before submitting. Do you want to continue to submit?");
                }
                if (msg == true) {
                    return true;
                }
                setTimeout($.proxy(function () {
                    jQuery(this).parent().children().css('pointer-events', 'auto');
                    jQuery(this).parent().children().css('background-color', '');
                    jQuery(this).parent().children().css('border-color', '');
                    jQuery(this).parent().children().last().css('background-color', '#ee4d4d');
                    jQuery(this).parent().children().last().css('border-color', '#ee4d4d');
                    jQuery('.top-actions').children().css('pointer-events', 'auto');
                    jQuery('.top-actions').children().css('background-color', '');
                    jQuery('.top-actions').children().css('border-color', '');
                    jQuery('.top-actions').children().last().css('background-color', '#ee4d4d');
                    jQuery('.top-actions').children().last().css('border-color', '#ee4d4d');
                }, this), 500);
                return false; 
            }
            return true;  
        }
    
    });                  
});



            
