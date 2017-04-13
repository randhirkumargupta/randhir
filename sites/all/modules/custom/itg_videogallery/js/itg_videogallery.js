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
            
            // Code for comment question field hide and show
            $('#edit-field-video-configurations-und-comment-box').click(function() {
                if ($("#edit-field-video-configurations-und-comment-box").is(":not(:checked)")) {
                    $("#edit-field-story-comment-question-und-0-value").val('');
                }
            });

            // code to copy story longheadline to story title
//            $('#edit-title').blur(function() {
//                $('#edit-field-story-long-head-line-und-0-value').val($('#edit-title').val());
//            });

            $('#edit-title').blur(function() {
                $('#edit-field-story-short-headline-und-0-value').val($('#edit-title').val());
            });
            $('.plupload_container').removeAttr("title");

            // FTP browse js
            $('document').ready(function() {
                var old_vid = $("input[name='field_upload_video[und][0][fid]']").val();
//                if (old_vid == 0) {
//                    $("#edit-field-upload-video-und-0-upload").hide();
//                    $("#edit-field-upload-video-und-0-upload-button").hide();
//                    $('#edit-field-upload-video label').hide();
//                } else {
//                    $(".browse-ftp-click").hide();
//                    $('.browse-video-form label').hide();
//                    $('#edit-field-upload-video label:first').show();
//                }
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
//            $(".video-local").click(function() {
//                $(".local_browse").show();
//                $(".ftp-server").hide();
//                $(".video_filters").hide();
//                $('.video-ftp').removeClass('active');
//                $(this).addClass('active');
//            });
//            $(".video-ftp").click(function() {
//                $(".local_browse").hide();
//                $(".ftp-server").show();
//                $(".video_filters").show();
//                $(this).addClass('active');
//                $('.video-local').removeClass('active');
//                $('.used-unused-select').val('unused');
//                $('.used-unused-select').trigger('change');
//
//            });
//            $(".browse-local").click(function() {
//                $("#edit-field-upload-video-und-0-upload").show();
//                $("#edit-field-upload-video-und-0-upload-button").show();
//                $("#edit-field-upload-video-und-0-upload").trigger('click');
//                $("#edit-field-upload-video-und-0-upload").change(function() {
//                    $("#edit-field-upload-video-und-0-upload-button").mousedown();
//                    $.colorbox.close();
//                });
//            });
            // check ajax upload button

            $('#videogallery-node-form').ajaxComplete(function(event, request, settings) {
                if (form_build_id = settings.url.match(/file\/ajax\/field_upload_video\d*\/(.*)$/)) {

//                    if ($('#videogallery-node-form').find("input[name='field_upload_video_und_0_remove_button']").val() == 'Remove') {
//                        $(".browse-ftp-click").hide();
//                        $('.browse-video-form label').hide();
//                        $('#edit-field-upload-video label:first').show();
//
//                    } else {
//
//                        $(".browse-ftp-click").show();
//                        $("input[name='field_video_duration[und][0][value]']").val('');
//
//                        $('.browse-video-form label').show();
//                        $('#edit-field-upload-video label:first').hide();
//                    }
                }

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
jQuery('document').ready(function() {
    var first_fid = jQuery("input[name='field_video_upload[und][0][field_videogallery_video_upload][und][0][fid]").val();
    if (first_fid != "" && first_fid != 0)
    {
        jQuery('#field-video-upload-values tbody tr:first').show();
    }
    jQuery('.file-icon').next('a').attr("href", 'javascript:void(0)').removeAttr('target');

});
