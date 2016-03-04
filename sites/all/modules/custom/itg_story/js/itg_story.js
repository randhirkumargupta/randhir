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
                     $('#edit-field-story-issue-date').hide();                     
                     $('#edit-field-story-comment-question').hide();
                     $('#edit-field-story-client-title').hide();
                     $('#edit-field-story-media-files-syndicat').hide();
                     $('#edit-field-story-facebook-narrative').hide();
                     $('#edit-field-story-tweet').hide();
                     $('.field-edit-link').hide();
                     $('#edit-body-und-0-format').hide();
                     $('.vertical-tabs-list').hide();
                     $('#edit-metatags').show();
                     $('#edit-metatags-und-advanced').hide();
                     $('.form-item-metatags-und-abstract-value').hide();
                     $('#edit-field-story-facebook-image').hide();
                     $('#edit-field-story-expiry-date').hide();
                     $('#edit-field-story-archive').hide();
                     $('#edit-path').show();
                     
                     
                     // code for Magazine and Supplement field show on edit story form
                     if ($("#edit-field-story-magazine-story-issue-und-magazine-issue-story").is(':checked')) {                         
                         $('#edit-field-story-select-magazine').show();
                         $('#edit-field-story-select-supplement').show();
                         $('#edit-field-story-issue-date').show();
                     }
                     
                                          
                     // code for Comment Question field show on edit story form
                     if ($("#edit-field-story-configurations-und-comment").is(':checked')) {                         
                         $('#edit-field-story-comment-question').show();                         
                     }
                     
                     // code for client Title field show on edit story form
                     if ($("#edit-field-story-configurations-und-syndication").is(':checked')) {                         
                         $('#edit-field-story-client-title').show();
                         $('#edit-field-story-media-files-syndicat').show();                         
                     }
                     
                     // code for facebook field show on edit story form
                     if ($("#edit-field-story-social-media-integ-und-facebook").is(':checked')) {                         
                         $('#edit-field-story-facebook-narrative').show();
                         $('#edit-field-story-facebook-image').show();
                     }
                     // code for expiry date field show on edit story form
                     if ($("#edit-field-story-expires-und-yes").is(':checked')) {                         
                         $('#edit-field-story-expiry-date').show();                         
                     }
                     
                     // code to copy story longheadline to story title
                     $('#edit-title').blur(function() {
                        $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
                     });
                     

                     // code for tweet field show on edit story form
                     if ($("#edit-field-story-social-media-integ-und-twitter").is(':checked')) {                         
                         $('#edit-field-story-tweet').show();                         
                     }
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
                         $('#edit-field-story-issue-date').show();
                     }else{
                       $("#edit-field-story-select-magazine-und").val('_none');
                       $('#edit-field-story-select-supplement-und').val('_none'); 
                       $('#edit-field-story-select-magazine').hide();
                       $('#edit-field-story-select-supplement').hide();
                       $('#edit-field-story-issue-date').hide();
                       $("#edit-field-story-issue-date-und-0-value-datepicker-popup-0").val('');
                       //
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
                         $('#edit-field-story-media-files-syndicat').show();
                     }else{
                       $("#edit-field-story-client-title-und-0-value").val('');                       
                       $('#edit-field-story-client-title').hide(); 
                       $('#edit-field-story-media-files-syndicat').hide();
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
                 
                 // code for story expiry date field show and hide
                 $('#edit-field-story-expires-und-yes').click(function() {                     
                     if ($("#edit-field-story-expires-und-yes").is(':checked')) { 
                       $('#edit-field-story-expiry-date').show();                         
                     }else{
                       $("#edit-field-story-expiry-date").val('');                       
                       $('#edit-field-story-expiry-date').hide();                       
                     }                     
                 });
                 
                 
                 // code to estrict user to select previous date
                 $('#edit-field-story-schedule-date-time-und-0-value-datepicker-popup-0').datepicker({
                    changeYear: true,
                    readonly: true,
                    minDate: '0',
                    //maxDate: '+1M',
                 });
                
                // code to estrict user to select previous date
                 $('#edit-field-story-expiry-date-und-0-value-datepicker-popup-0').datepicker({
                    changeYear: true,
                    readonly: true,
                    minDate: '0',
                    //maxDate: '+1M',
                });
                
                // code issue date exit or not.
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
