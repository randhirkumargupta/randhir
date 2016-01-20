/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function($) {
        Drupal.behaviors.itg_story = {
             attach: function(context, settings) {
                   $('#edit-field-story-select-magazine').hide();
                   $('#edit-field-story-select-supplement').hide();
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
                 
                 //code for Magazine and Supplement field hide and show
                 $('#edit-field-story-magazine-story-issue-und-magazine-issue-story').click(function() {
                     if ($(this).attr("checked")) {
                         $('#edit-field-story-select-magazine').show();
                         $('#edit-field-story-select-supplement').show();
                     }else{
                       $('#edit-field-story-select-magazine').hide();
                       $('#edit-field-story-select-supplement').hide();  
                     }
                     
                 });
                 
                 $('#edit-field-story-select-magazine-und').change(function() {
                     var base_url = settings.itg_story.settings.base_url;                     
                     $.ajax({
                         url: base_url + "/supplement-list-ajax",
                         method: 'post',
                         data: {'reporter_id': $('#edit-field-story-select-magazine-und').val()},
                         success: function(data) {
                               $('#reporter-details').html(data);
                         }
                     });
                 });
             }

 };
})(jQuery, Drupal, this, this.document);