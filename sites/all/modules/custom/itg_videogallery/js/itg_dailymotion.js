/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */

(function($) {
    Drupal.behaviors.itg_dailymotion = {
        attach: function(context, settings) {

            // GET field id
//            var video_field_id = settings.itg_dailymotion.settings.video_field_id;
//            var video_field_file = settings.itg_dailymotion.settings.video_field_file;
            // FTP browse

            var base_url = Drupal.settings.baseUrl.baseUrl;


            $(".ftp-server .asso-filed_single").click(function(e) {
                jQuery('#loader-data img').show().parent().addClass('loader_overlay');
                var video_fids = [];
                var selected_check_boxes_values = new Array();
                var selected_check_boxes_index = 0;
                $("#video_iframe").contents().find("input:radio[class=form-radio]:checked").each(function() {
                    selected_check_boxes_values[selected_check_boxes_index++] = $(this).val();
                });
                if (selected_check_boxes_index == 0) {
                    alert("Please select video file.");
                } else {
                    jQuery('#loader-data img').show().parent().addClass('loader_overlay');
                    var getbtnmane = $(this).attr('btn_name');

                    jQuery.ajax({
                        url: base_url + '/solr-video-make-fid',
                        type: 'post',
                        data: {'checkvalue': selected_check_boxes_values},
                        success: function(data) {
                            var as = JSON.parse(data);
                            var parsed = JSON.parse(data);

                            for (var x in parsed) {
                                video_fids.push(parsed[x]);
                            }

                            parent.jQuery('[name="' + getbtnmane + '[fid]"]').val(parsed[0]);
                            parent.jQuery("body").find("input[name='" + getbtnmane + "[filefield_itg_image_video][button]").trigger('mousedown');

                            //parent.jQuery("#" + video_field_id + "-button").mousedown();
                            parent.jQuery('form').ajaxComplete(function(event, request, settings) {
                                try {
                                    parent.jQuery.colorbox.close();
                                } catch (err) {

                                }


                            });

                        }

                    });

                }
            });

            $(window).load(function() {
                if ($('#single_add').val() == 1) {
                    $("#video_iframe").contents().find("input:checkbox[class=form-radio]").each(function() {
                        $(this).attr('type', 'radio');
                    });
                }
            });

            $(".ftp-server .asso-filed").click(function(e) {

                // Getting selected videos from checkboxes        
                var video_fids = [];
                var selected_check_boxes_values = new Array();
                var selected_check_boxes_index = 0;
                $("#video_iframe").contents().find("input:checkbox[class=form-radio]:checked").each(function() {
                    selected_check_boxes_values[selected_check_boxes_index++] = $(this).val();
                });
                if (selected_check_boxes_index == 0) {
                    alert("Please select video file.");
                } else {
                  jQuery('#loader-data img').show().parent().addClass('loader_overlay');
                    jQuery.ajax({
                        url: base_url + '/solr-video-make-fid',
                        type: 'post',
                        data: {'checkvalue': selected_check_boxes_values},
                        success: function(data) {
                            var as = JSON.parse(data);
                            var parsed = JSON.parse(data);

                            for (var x in parsed) {
                                video_fids.push(parsed[x]);
                            }

                            parent.jQuery('#edit-field-video-upload-add-more-number').val(video_fids.length);
                            parent.jQuery('#edit-field-video-upload-file-entity-holder-nums').val(video_fids.join());
                            jQuery('#loader-data img').show().parent().addClass('loader_overlay');
                            //  parent.jQuery("input[name='" + video_field_file + "'").val(vid);
                            parent.jQuery("[name='field_video_upload_add_more']").mousedown();
                            parent.jQuery('#videogallery-node-form').ajaxComplete(function(event, request, settings) {
                                try {
                                    parent.jQuery.colorbox.close();
                                } catch (err) {

                                }


                            });

                        }
                        //var vid = $("#edit-video-browse-select .form-radio:checked").val();


                    });
                }
            });



            $(".ftp-server .asso-with-ckeditor").click(function(e) {

                // Getting selected videos from checkboxes        


                var selected_check_boxes_values = new Array();
                var selected_check_boxes_index = 0;
                $("#video_iframe").contents().find("input:checkbox[class=form-radio]:checked").each(function() {
                    selected_check_boxes_values[selected_check_boxes_index++] = $(this).val();
                });
                if (selected_check_boxes_index == 0) {
                    alert("Please select video file.");
                } else {
                    jQuery('#loader-data img').show().parent().addClass('loader_overlay');
                    //var base_url = Drupal.settings.basePath;
                    var base_url = Drupal.settings.baseUrl.baseUrl;
                    jQuery.ajax({
                        url: base_url + '/get-file-details',
                        type: 'post',
                        data: {'checkvalue': selected_check_boxes_values},
                        success: function(data) {
                            parent.jQuery("body", parent.document).find('input.cke_dialog_ui_input_text').val(data);
                            parent.jQuery.colorbox.close();
                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
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
                $('#video_text_search').val('');
                $(".ftp-server").show();
                $(".video_filters").show();
                $(this).addClass('active');
                $('.video-local').removeClass('active');
                $('.used-unused-select').val('unused');
                $('.used-unused-select').trigger('change');

            });

          
            //Reset video form
            $('.reset_video_filters').click(function() {
                var unused_value = $('.used-unused-select').val();
                if (unused_value == 'unused') {
                    $(".video-ftp").trigger('click');
                    $('#video_text_search').val('');
                }
                else if (unused_value == 'used') {
                    $('#video_text_search').val('');
                    $('.used-unused-select').val('used');
                    $(".used-unused-select").trigger('change');
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
        //var base_url = Drupal.settings.basePath;
        var base_url = Drupal.settings.baseUrl.baseUrl;
        jQuery.ajax({
            url: base_url + '/dailymotion-ftp-videos-post',
            type: 'post',
            data: {'case': select_value, 'value_type': jQuery('#single_add').val()},
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


    //Time filter
    jQuery('.time-filter-select').live('change', function() {
        jQuery('#loader-data img').show().parent().addClass('loader_overlay');
        var select_value = jQuery(this).val();
        var search_val = jQuery('#video_text_search').val();
        var base_url = Drupal.settings.baseUrl.baseUrl;
        jQuery.ajax({
            url: base_url + '/dailymotion-video-time-filter',
            type: 'post',
            data: {'back_time': select_value + '@' + search_val},
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


    jQuery(".browse-local").click(function(e) {
        var videogallery_new_file_hold = parseInt(jQuery('input[name="videogallery_new_file[fid]"]').val());
        if (parseInt(jQuery('input[name="videogallery_new_file[fid]"]').val()) != 0) {
            parent.jQuery('#edit-field-video-upload-add-more-number').val(1);
            parent.jQuery("[name='field_video_upload[file_entity_holder_nums]']").val(videogallery_new_file_hold);
            var getbtnmane = jQuery(this).attr('btn_name');
            if (getbtnmane != "") {
                parent.jQuery('[name="' + getbtnmane + '[fid]"]').val(videogallery_new_file_hold);
                parent.jQuery("body").find("input[name='" + getbtnmane + "[filefield_itg_image_video][button]").trigger('mousedown');
                parent.jQuery('form').ajaxComplete(function(event, request, settings) {

                    try {

                        parent.jQuery.colorbox.close();
                    } catch (err) {

                        parent.jQuery.colorbox.close();
                    }
                });
            }
            else {
                parent.jQuery("[name='field_video_upload_add_more']").mousedown();
                parent.jQuery('#videogallery-node-form').ajaxComplete(function(event, request, settings) {

                    try {

                        parent.jQuery.colorbox.close();
                    } catch (err) {

                        parent.jQuery.colorbox.close();
                    }


                });
            }
        } else {
            alert("Select video file and upload");
        }
    });

    jQuery(".add-in-single-filed").click(function(e) {
        var videogallery_new_file_hold = parseInt(jQuery('input[name="videogallery_new_file[fid]"]').val());
        if (parseInt(jQuery('input[name="videogallery_new_file[fid]"]').val()) != 0) {
            var getbtnmane = $(this).attr('btn_name');
            parent.jQuery('[name="' + getbtnmane + '[fid]"]').val(videogallery_new_file_hold);
            parent.jQuery("body").find("input[name='" + getbtnmane + "[filefield_itg_image_video][button]").trigger('mousedown');
            $('#form').ajaxComplete(function(event, request, settings) {

                parent.jQuery.colorbox.close();
            });
        } else {
            alert("Select video file and upload");
        }
    });
    jQuery('.apply_video_filters').click(function() {
        var select_val = jQuery('.used-unused-select').val();
        var search_val = jQuery('#video_text_search').val();
        var time_val = jQuery('.time-filter-select').val();
        jQuery('#loader-data img').show().parent().addClass('loader_overlay');
        var base_url = Drupal.settings.baseUrl.baseUrl;
        jQuery.ajax({
            url: base_url + '/dailymotion-video-search-filter',
            type: 'post',
            data: {'back_time': select_val + '@' + search_val + '@' + time_val, 'value_type': jQuery('#single_add').val()},
            success: function(data) {
                jQuery('#loader-data img').hide().parent().removeClass('loader_overlay');
                jQuery('.video-options-wrapper').html(data);

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    })

    setTimeout(function() {
        jQuery(".video-ftp").trigger("click");
    }, 1000);
});

// Implement function for video search by title
function videosearch() {

}
