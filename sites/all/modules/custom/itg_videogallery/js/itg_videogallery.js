/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function($) {
    Drupal.behaviors.itg_videogallery = {
        attach: function(context, settings) {
            var uid = settings.itg_videogallery.settings.uid;
            jQuery('#edit-path').show();
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
//            $('#edit-field-story-reporter-und-0-target-id').blur(function() {
//                var base_url = settings.itg_videogallery.settings.base_url;
//                $.ajax({
//                    url: base_url + "/reporter-details-ajax",
//                    method: 'post',
//                    data: {'reporter_id': $('#edit-field-story-reporter-und-0-target-id').val()},
//                    success: function(data) {
//                        $('#reporter-details').html(data);
//                    }
//                });
//            });
            // FTP browse js
            $('document').ready(function() {
                var old_vid = $("input[name='field_upload_video[und][0][fid]']").val();
                if (old_vid == 0) {
                    $("#edit-field-upload-video-und-0-upload").hide();
                    $("#edit-field-upload-video-und-0-upload-button").hide();
                    $('#edit-field-upload-video label').hide();
                } else {
                    $(".browse-ftp-click").hide();
                    $('.browse-video-form label').hide();
                    $('#edit-field-upload-video label:first').show();
                }
            });


            $('.browse-ftp').hide();

            $('.ftp-server a').click(function() {
                var vid = $('#edit-video-browse-select .form-radio:checked').val();
                if (vid !== "" && !$.isNumeric(vid)) {
                    alert('Please select video file.');
                } else {
                    $("input[name='field_upload_video[und][0][fid]']").val(vid);
                    $("#edit-field-upload-video-und-0-upload-button").mousedown();
                    $.colorbox.close();
                    setTimeout(function() {
                        $('#edit-video-browse-select .form-radio').prop('checked', false);
                    }, 1000);
                }
            });
            // popup show hide
            $(".video-local").click(function() {
                $(".local_browse").show();
                $(".ftp-server").hide();
                $(".video_filters").hide();
                $('.video-ftp').removeClass('active');
                $(this).addClass('active');
            });
            $(".video-ftp").click(function() {
                $(".local_browse").hide();
                $(".ftp-server").show();
                $(".video_filters").show();
                $(this).addClass('active');
                $('.video-local').removeClass('active');
                $('.used-unused-select').val('unused');
                $('.used-unused-select').trigger('change');

            });
            $(".browse-local").click(function() {
                $("#edit-field-upload-video-und-0-upload").show();
                $("#edit-field-upload-video-und-0-upload-button").show();
                $("#edit-field-upload-video-und-0-upload").trigger('click');
                $("#edit-field-upload-video-und-0-upload").change(function() {
                    $("#edit-field-upload-video-und-0-upload-button").mousedown();
                    $.colorbox.close();
                });
            });
            // check ajax upload button

            $('#videogallery-node-form').ajaxComplete(function(event, request, settings) {
                if (form_build_id = settings.url.match(/file\/ajax\/field_upload_video\d*\/(.*)$/)) {

                    if ($('#videogallery-node-form').find("input[name='field_upload_video_und_0_remove_button']").val() == 'Remove') {
                        $(".browse-ftp-click").hide();
                        $('.browse-video-form label').hide();
                        $('#edit-field-upload-video label:first').show();

                    } else {

                        $(".browse-ftp-click").show();
                        $("input[name='field_video_duration[und][0][value]']").val('');

                        $('.browse-video-form label').show();
                        $('#edit-field-upload-video label:first').hide();
                    }
                }

            });

           // This code is written for restricting past date access for expiry date in video gallery content type   
            try {
                jQuery('#videogallery-node-form #edit-field-story-expiry-date-und-0-value-datepicker-popup-1').datepicker({
                    minDate: 0
                });
            } catch (e) {

            }

        }

    };
})(jQuery, Drupal, this, this.document);

jQuery('document').ready(function() {
    jQuery('.browse-ftp-click').click(function() {
        var old_vid = jQuery("input[name='field_upload_video[und][0][fid]']").val();
        if (old_vid != 0) {

        } else {
            jQuery('.video-ftp').trigger('click');
            jQuery('.video-local').removeClass('active');
            jQuery('.used-unused-select').val('unused');
            jQuery('.used-unused-select').trigger('change');
            jQuery('.time-filter').hide();
            var data = jQuery('.browse-ftp').html();
            //  jQuery.colorbox({width: "80%", height: "80%",fixed: true});
            jQuery.colorbox({html: "" + data + "", width: "80%", height: "80%", fixed: true, onComplete: function() {

                }});
        }
    });
});

// new code
jQuery('document').ready(function() {
    jQuery('.used-unused-select').live('change', function() {
        jQuery('#loader-data img').show().parent().addClass('loader_overlay');
        var select_value = jQuery(this).val();
        if (select_value == 'used') {
            jQuery('.time-filter').show();
            jQuery('.time-filter-select').val('-all-');
        } else {
            jQuery('.time-filter').hide();
        }
        var base_url = settings.itg_videogallery.settings.base_url;
        jQuery.ajax({
            url: base_url + '/dailymotion-ftp-videos-post',
            type: 'post',
            data: {'case': select_value},
            success: function(data) {
                jQuery('#loader-data img').hide().parent().removeClass('loader_overlay');
                jQuery('.video-options-wrapper').html(data);

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });

    });
});

// Time filter ajax
jQuery('document').ready(function() {
    jQuery('.time-filter-select').live('change', function() {
        jQuery('#loader-data img').show();
        var select_value = jQuery(this).val();
        var base_url = settings.itg_videogallery.settings.base_url;
        jQuery.ajax({
            url: base_url + '/dailymotion-video-time-filter',
            type: 'post',
            data: {'back_time': select_value},
            success: function(data) {
                jQuery('#loader-data img').hide();
                jQuery('.video-options-wrapper').html(data);

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });

    });
});
