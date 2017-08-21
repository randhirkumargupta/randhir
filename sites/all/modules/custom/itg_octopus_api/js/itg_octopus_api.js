/*
 * @file itg_octopus_api.js
 * Contains all functionality related to octopus
 */

(function($) {
    Drupal.behaviors.itg_octopus_api = {
        attach: function(context, settings) {
        }

    };
})(jQuery, Drupal, this, this.document);


jQuery('document').ready(function() {
     jQuery('#itg-octopus-api-form #edit-start-date-timeEntry-popup-1').attr('placeholder', 'Time');
     jQuery('#itg-octopus-api-form #edit-end-date-timeEntry-popup-1').attr('placeholder', 'Time');
            
    jQuery(".octopus-slug-data").click(function() {
        var current_object = jQuery(this);
        var base_url = Drupal.settings.baseUrl.baseUrl;
        var slug_id = jQuery(this).attr('data');
        jQuery.ajax({
            url: base_url + '/slug-details/' + slug_id,
            type: 'post',
            data: {'id': slug_id},
            beforeSend: function() {
                current_object.closest('tr').siblings('.octopus-slug-data-row').remove();
                current_object.closest('tr').after('<tr class="octopus-slug-data-row" style="text-align: center;"><td colspan="10"><img width="50" src="' + Drupal.settings.itg_octopus_holder.settings.loader_url + '" alt=""/></td></tr>');
            },
            success: function(data) {
                current_object.closest('tr').siblings('.octopus-slug-data-row').remove();
                current_object.closest('tr').after('<tr class="octopus-slug-data-row"><td colspan="10">' + data + '</td></tr>');
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });


    });


    // Copying data from Octopus to dumping machine

    jQuery("body").on('click', '.get-video', function() {
        var current_object = jQuery(this);
        var base_url = Drupal.settings.baseUrl.baseUrl;
        var slug_id = jQuery(this).attr('data');
        var attr_id = jQuery(this).attr('attribute_id');
        var s3_video_success = false;
        jQuery('.video-process-bar-' + attr_id).show();
        jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Preparing request for getting high resolution video</p></div>');
        jQuery.ajax({
            url: base_url + '/get-video/' + slug_id,
            type: 'post',
            data: {'id': slug_id},
            beforeSend: function() {
                setTimeout(function() {
                    jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Request for high resolution video sent to TV team</p></div>');
                }, 2000);
            },
            success: function(data) {
                setTimeout(function() {
                    jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Getting response for high resolution video from TV team</p></div>');

                }, 5000);
                var dumping_video_status = setInterval(function() {
                    jQuery.ajax({
                        url: base_url + '/itg-octopus-dumping-video-status/' + data,
                        type: 'post',
                        data: {'id': data},
                        beforeSend: function() {
                            jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Video download in progress..</p></div>');

                        },
                        success: function(datafinal) {
                            var datafinal_json = JSON.parse(datafinal);
                            console.log(datafinal_json);
                            if (datafinal_json.IS_COPIED == "YES") {
                                setTimeout(function() {
                                    jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Octopus high resolution Video received at local</p></div>');

                                    clearInterval(dumping_video_status);
                                    setTimeout(function() {
                                        jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Preparing data for sending dumped video file to S3 bucket</p></div>');

                                        s3_video_success = true;
                                        // Code end for sending dumping machine video to s3 bucket
                                        if (s3_video_success == true) {

                                            setTimeout(function() {
                                                jQuery.ajax({
                                                    url: base_url + '/itg-octopus-sending-video-s3',
                                                    type: 'post',
                                                    data: {'id': slug_id},
                                                    beforeSend: function() {
                                                        jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Started  sending video to S3</p></div>');

                                                    },
                                                    success: function(datafinal) {
                                                        var s3_response_data = JSON.parse(datafinal);
                                                        console.log("jsahhdjsahdjaahdjahdahd");
                                                        console.log(s3_response_data);
                                                        if (s3_response_data.success == 'yes') {
                                                            jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Video uploaded to S3</p></div>');

                                                            setTimeout(function() {
                                                                jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Preparing data for sending s3 video to Daily montion</p></div>');

                                                            }, 5000);


                                                            // Start code  Sending Video from s3 to DM 

                                                            setTimeout(function() {
                                                                jQuery.ajax({
                                                                    url: base_url + '/itg-octopus-video-s3-to-dm',
                                                                    type: 'post',
                                                                    data: {'s3_video_uri': s3_response_data.s3_url, 'slug_id': attr_id, 'file_size': s3_response_data.file_size},
                                                                    beforeSend: function() {
                                                                        jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Processing to DM..</p></div>');

                                                                    },
                                                                    success: function(datafinals3todm) {
                                                                        console.log(datafinals3todm);
                                                                        console.log(attr_id);
                                                                        datafinals3todm_s = JSON.parse(datafinals3todm);
                                                                        if (datafinals3todm_s.success == 'yes') {
                                                                            jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><i class="fa fa-check-circle" aria-hidden="true"></i><p>Ready to use</p></div>');
                                                                            setTimeout(function() {
                                                                                jQuery('.video-process-bar-' + attr_id).hide();
                                                                                jQuery('#file-video-article-' + attr_id).show();
                                                                                jQuery('#get-video-' + attr_id).hide();
                                                                            }, 5000);
                                                                            return;
                                                                        }
                                                                    },
                                                                    error: function(xhr, desc, err) {
                                                                        console.log(xhr);
                                                                        console.log("Details: " + desc + "\nError:" + err);
                                                                    }
                                                                });
                                                            }, 5000);

                                                            // End code for sending video from s3 to DM





                                                        }
                                                    },
                                                    error: function(xhr, desc, err) {
                                                        console.log(xhr);
                                                        console.log("Details: " + desc + "\nError:" + err);
                                                    }
                                                });
                                            }, 5000);
                                        }
                                        // Code end for sending dumping machine video to s3 bucket
                                    }, 5000);
                                }, 5000);
                            } else {
                                jQuery('.video-process-bar-' + attr_id).html('<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Still Checking dumping video status</p></div>');


                            }
                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });

                }, 8000); // Execute every 8 seconds.

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });




    });

    // Handler for file video
    jQuery("body").on('click', '.file-video', function() {
        var o_current_object = jQuery(this);
        var o_base_url = Drupal.settings.baseUrl.baseUrl;
        var o_slug_id = jQuery(this).attr('data');
        var o_attr_id = jQuery(this).attr('attribute_id');
        jQuery.ajax({
            url: o_base_url + '/itg-octopus-file-video',
            type: 'post',
            data: {'slug_id': o_attr_id},
            beforeSend: function() {
            },
            success: function(fdata) {
                window.location.href = fdata;
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });

    });


    jQuery("body").on('click', '.remove-data', function() {
        jQuery(this).parent().parent().remove();
    });


});