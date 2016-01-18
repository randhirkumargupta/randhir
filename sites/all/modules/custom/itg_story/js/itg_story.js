 (function($) {
        Drupal.behaviors.itg_story = {
             attach: function(context, settings) {
                   $('#edit-field-story-reporter-und-0-target-id').blur(function() {
                     var base_url = settings.itg_story.settings.base_url;                     
                     $.ajax({
                         url: base_url + "/reporter-details",
                         method: 'post',
                         data: {'reporter_id': $('#edit-field-story-reporter-und-0-target-id').val()},
                         success: function(data) {
                               $('#reporter-details').html(data);
                         }
                     });
                 });
             }

 };
})(jQuery, Drupal, this, this.document);