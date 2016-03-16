/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
        Drupal.behaviors.itg_story = {
             attach: function(context, settings) {
                   var uid = settings.itg_story.settings.uid;
                   
                   if (uid != 1) {
                     $('.field-edit-link').hide();
                     $('#edit-body-und-0-format').hide();                     
                     $('#edit-field-story-archive').hide();
                     $('#edit-path').show();
                   }
                 
                 // Code for Magazine, Supplement and date field value set Null
                 $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function() {                     
                    if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(":not(:checked)")) {                         
                      $("#edit-field-story-select-magazine-und").val('_none');
                      $('[name="field_story_select_supplement[und]"]').val('_none');                      
                      $("#edit-field-story-issue-date-und-0-value-datepicker-popup-1").val('');
                    }                     
                 });
                 
                 // Code for client Title field value set Null
                 $('#edit-field-story-configurations-und-syndication').click(function() {                     
                    if ($("#edit-field-story-configurations-und-syndication").is(":not(:checked)")) {                         
                      $("#edit-field-story-client-title-und-0-value").val('');
                      $('#edit-field-story-media-files-syndicat-und-yes').attr('checked', false);
                    }                   
                 });
                 
                 // Code for client Title field value set Null
                 $('#edit-field-story-configurations-und-comment').click(function() {                     
                    if ($("#edit-field-story-configurations-und-comment").is(":not(:checked)")) {                         
                      $("#edit-field-story-comment-question-und-0-value").val('');   
                    }                   
                 });
                 
                 // Code for facebook field value set Null
                 $('#edit-field-story-social-media-integ-und-facebook').click(function() {                     
                    if ($("#edit-field-story-social-media-integ-und-facebook").is(":not(:checked)")) {                         
                      $("#edit-field-story-facebook-narrative-und-0-value").val('');  
                    }                    
                 });                 
                 
                 // Code for tweet field value set Null
                 $('#edit-field-story-social-media-integ-und-twitter').click(function() {                     
                    if ($("#edit-field-story-social-media-integ-und-twitter").is(":not(:checked)")) {                         
                      $("#edit-field-story-tweet-und-0-value").val('');                          
                    }                    
                 });
                 
                 // Code for story expiry date field value set Null
                 $('#edit-field-story-expires-und-yes').click(function() {                     
                    if ($("#edit-field-story-expires-und-yes").is(":not(:checked)")) { 
                      $("#edit-field-story-expiry-date").val('');                        
                    }                    
                 });
                
                // code to copy story longheadline to story title
                $('#edit-title').blur(function() {
                  $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
                });

                // Display Byline details
                $('#edit-field-story-reporter-und-0-target-id').blur(function() {                       
                 var base_url = settings.itg_story.settings.base_url;
                 $.ajax({
                       url: base_url + "/reporter-details-ajax",
                       method: 'post',
                       data: {'reporter_id': $('#edit-field-story-reporter-und-0-target-id').val()},
                       success: function(data) {                              
                             $('#reporter-details').html(data);
                       }
                 });
                });
                   
                // Code issue date exit or not.
                $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').blur(function() {                       
                    var base_url = settings.itg_story.settings.base_url;
                    $.ajax({
                          url: base_url + "/issue-date-check-ajax",
                          method: 'post',
                          data: {'issue': $('#edit-field-story-issue-date-und-0-value-datepicker-popup-0').val()},
                          success: function(data) {
                                $("#idIssue").remove();
                                $(".form-item-field-story-issue-date-und-0-value-date").append(data);                               
                          }
                    });
                 });
                                 
                 
             }

 };
})(jQuery, Drupal, this, this.document);
