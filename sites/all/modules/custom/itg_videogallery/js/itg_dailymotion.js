/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function($) {
    Drupal.behaviors.itg_dailymotion = {
        attach: function(context, settings) {
            // GET field id
            var video_field_id = settings.itg_dailymotion.settings.video_field_id;
            var video_field_file = settings.itg_dailymotion.settings.video_field_file;
            // FTP browse
            setTimeout(function() {
                jQuery(".video-ftp").trigger("click");
            }, 1000);
            $(".ftp-server a").click(function() {
                var vid = $("#edit-video-browse-select .form-radio:checked").val();
                if (vid !== "" && !$.isNumeric(vid)) {
                    alert("Please select video file.");
                } else {

                    parent.jQuery("input[name='" + video_field_file + "'").val(vid);

                    parent.jQuery("#" + video_field_id + "-button").mousedown();
                    setTimeout(function() {
                        parent.jQuery.colorbox.close();
                        $("#edit-video-browse-select .form-radio").prop("checked", false);
                    }, 2000);
                }
            });
            // Browse Local
            $(".browse-local").click(function() {
                parent.jQuery("#" + video_field_id + "").show();
                parent.jQuery("#" + video_field_id + "-button").show();
                parent.jQuery("#" + video_field_id + "").trigger('click');
                parent.jQuery("#" + video_field_id + "").change(function() {
                    parent.jQuery("#" + video_field_id + "-button").mousedown();
                    parent.jQuery.colorbox.close();
                });
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

            // check ajax upload button

            $('#videogallery-node-form').ajaxComplete(function(event, request, settings) {
                if (form_build_id = settings.url.match(/file\/ajax\/field_upload_video\d*\/(.*)$/)) {

                    if ($('#videogallery-node-form').find("input[name='" + video_field_id + "_button']").val() == 'Remove') {
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
        }
        // This code is written for restricting past date access for expiry date in video gallery content type


    };
})(jQuery, Drupal, this, this.document);

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
        var base_url = Drupal.settings.basePath;
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



    jQuery('.time-filter-select').live('change', function() {
        jQuery('#loader-data img').show();
        var select_value = jQuery(this).val();
        var base_url = Drupal.settings.basePath;
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

