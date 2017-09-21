/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function ($) {
    Drupal.behaviors.itg_videogallery = {
        attach: function (context, settings) {
            var uid = settings.itg_videogallery.settings.uid;
            jQuery('input[name="field_story_schedule_date_time[und][0][value][date]"]').keydown(false);
            jQuery('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);
            // Code for client Title field value set Null
            $('#edit-field-story-configurations-und-syndication').click(function () {
                if ($("#edit-field-story-configurations-und-syndication").is(":not(:checked)")) {
                    $("#edit-field-story-client-title-und-0-value").val('');
                    $('#edit-field-story-media-files-syndicat-und-yes').attr('checked', false);
                }
            });

            $('#edit-field-story-social-media-integ-und-facebook').click(function () {
                if ($("#edit-field-story-social-media-integ-und-facebook").is(":not(:checked)")) {
                    $("#edit-field-story-facebook-narrative-und-0-value").val('');
                }
            });

            // Code for tweet field value set Null
            $('#edit-field-story-social-media-integ-und-twitter').click(function () {
                if ($("#edit-field-story-social-media-integ-und-twitter").is(":not(:checked)")) {
                    $("#edit-field-story-tweet-und-0-value").val('');
                }
            });

            // Code for story expiry date field value set Null
            $('#edit-field-story-expires-und-yes').click(function () {
                if ($("#edit-field-story-expires-und-yes").is(":not(:checked)")) {
                    $("#edit-field-story-expiry-date").val('');
                }
            });

            // Code for comment question field hide and show
            $('#edit-field-video-configurations-und-comment-box').click(function () {
                if ($("#edit-field-video-configurations-und-comment-box").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });

            $('#edit-title').blur(function () {
                $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());
            });
            $('.plupload_container').removeAttr("title");

            // FTP browse js
            $('document').ready(function () {
                var old_vid = $("input[name='field_upload_video[und][0][fid]']").val();
            });

            $('.browse-ftp').hide();

            $('.ftp-server a').click(function () {
                var vid = $('#edit-video-browse-select .form-radio:checked').val();
                if (vid !== "" && !$.isNumeric(vid)) {
                    alert('Please select video file.');
                } else {
                    $("input[name='field_upload_video[und][0][fid]']").val(vid);
                    $("#edit-field-upload-video-und-0-upload-button").mousedown();
                    $.colorbox.close();
                    setTimeout(function () {
                        $('#edit-video-browse-select .form-radio').prop('checked', false);
                    }, 1000);
                }
            });

            $('#videogallery-node-form').ajaxComplete(function (event, request, settings) {
                for (i = 0; i < 10; i++) {
                    var valuefiled = $("input[name='field_video_upload[und][" + i + "][field_videogallery_video_upload][und][0][fid]']").val();
                    if (valuefiled == 0) {
                        $("input[name='field_video_upload[und][" + i + "][field_videogallery_video_upload][und][0][fid]']").parents(".draggable").hide();
                    }
                }
                $('.draggable td:nth-child(3)').each(function () {
                    if ($(this).html() == "") {
                        $(this).parent('.draggable').remove();
                    }
                })

            });

            // This code is written for restricting past date access for expiry date in video gallery content type   
            try {
                jQuery('#videogallery-node-form #edit-field-story-expiry-date-und-0-value-datepicker-popup-1').datepicker({
                    minDate: 0
                });
            } catch (e) {

            }

            try {
                jQuery("[name='field_video_upload_add_more']").css('visibility', 'hidden');
            } catch (e) {

            }

        }

    };
})(jQuery, Drupal, this, this.document);

jQuery('document').ready(function () {
    var first_fid = jQuery("input[name='field_video_upload[und][0][field_videogallery_video_upload][und][0][fid]").val();
    if (first_fid != "" && first_fid != 0)
    {
        jQuery('#field-video-upload-values tbody tr:first').show();
    }
    jQuery('.file-icon').next('a').attr("href", 'javascript:void(0)').removeAttr('target');

});
