/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function($) {
    Drupal.behaviors.itg_videogallery = {
        attach: function(context, settings) {
            var uid = settings.itg_videogallery.settings.uid;
            jQuery('input[name="field_story_schedule_date_time[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);
            if (uid != 1) {
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();
                $('.fieldset-description').hide();
                $('#edit-metatags p').hide();
            }

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

            $('#edit-title').blur(function() {
                $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());
            });
            $('.plupload_container').removeAttr("title"); 
            // Display Byline details
            $('#edit-field-story-reporter-und-0-target-id').blur(function() {
                var base_url = Drupal.settings.basePath;
                $.ajax({
                    url: base_url + "/reporter-details-ajax",
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
