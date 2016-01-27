/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
        Drupal.behaviors.itg_story = {
             attach: function(context, settings) {
                   var uid = settings.itg_story.settings.uid;
                   if (uid != 1) {
                     $('#edit-field-story-select-magazine').hide();
                     $('#edit-field-story-select-supplement').hide();
                     $('#edit-field-story-comment-question').hide();
                     $('#edit-field-story-client-title').hide();
                     $('#edit-field-story-facebook-narrative').hide();
                     $('#edit-field-story-tweet').hide();
                     $('.field-edit-link').hide();
                     $('#edit-body-und-0-format').hide();
                     $('.vertical-tabs-list').hide();
                     $('#edit-metatags').show();
                     $('#edit-metatags-und-advanced').hide();
                     $('.form-item-metatags-und-abstract-value').hide();
                     $('#edit-field-story-facebook-image').hide();
                     
                   }
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
                 
                 // code for Magazine and Supplement field hide and show
                 $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function() {
                     
                     if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(':checked')) {                         
                         $('#edit-field-story-select-magazine').show();
                         $('#edit-field-story-select-supplement').show();
                     }else{
                       $("#edit-field-story-select-magazine-und").val('_none');
                       $('#edit-field-story-select-supplement-und').val('_none'); 
                       $('#edit-field-story-select-magazine').hide();
                       $('#edit-field-story-select-supplement').hide();  
                     }
                     
                 });
                 
                 // code for Comment Question field hide and show
                 $('#edit-field-story-configurations-und-comment').click(function() {                     
                     if ($("#edit-field-story-configurations-und-comment").is(':checked')) {                         
                         $('#edit-field-story-comment-question').show();                         
                     }else{
                       $("#edit-field-story-comment-question-und-0-value").val('');                       
                       $('#edit-field-story-comment-question').hide();                       
                     }                     
                 });
                 
                 // code for client Title field show and hide
                 $('#edit-field-story-configurations-und-syndication').click(function() {                     
                     if ($("#edit-field-story-configurations-und-syndication").is(':checked')) {                         
                         $('#edit-field-story-client-title').show();                         
                     }else{
                       $("#edit-field-story-client-title-und-0-value").val('');                       
                       $('#edit-field-story-client-title').hide();                       
                     }                     
                 });
                 
                 // code for facebook field show and hide
                 $('#edit-field-story-social-media-integ-und-facebook').click(function() {                     
                     if ($("#edit-field-story-social-media-integ-und-facebook").is(':checked')) {                         
                         $('#edit-field-story-facebook-narrative').show();
                         $('#edit-field-story-facebook-image').show();
                     }else{
                       $("#edit-field-story-facebook-narrative-und-0-value").val('');                       
                       $('#edit-field-story-facebook-narrative').hide();
                       $('#edit-field-story-facebook-image').hide();
                     }                     
                 });                 
                 
                 // code for tweet field show and hide
                 $('#edit-field-story-social-media-integ-und-twitter').click(function() {                     
                     if ($("#edit-field-story-social-media-integ-und-twitter").is(':checked')) {                         
                         $('#edit-field-story-tweet').show();                         
                     }else{
                       $("#edit-field-story-tweet-und-0-value").val('');                       
                       $('#edit-field-story-tweet').hide();                       
                     }                     
                 });
                 
                 /*$('#edit-field-story-select-magazine-und').change(function() {
                     var base_url = settings.itg_story.settings.base_url;                     
                     $.ajax({
                         url: base_url + "/supplement-list-ajax",
                         method: 'post',
                         data: {'reporter_id': $('#edit-field-story-select-magazine-und').val()},
                         success: function(data) {
                               $('#reporter-details').html(data);
                         }
                     });
                 });*/
             }

 };
})(jQuery, Drupal, this, this.document);