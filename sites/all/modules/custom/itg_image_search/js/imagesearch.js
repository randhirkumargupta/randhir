(function($) {

    var timer;
    jQuery('#edit-terms').live('keyup', function() {
        window.clearTimeout(timer);
        timer = window.setTimeout(function() {

            var serializeform = $("#itg-image-repository-filesearch-form").serialize();

            jQuery.ajax({
                url: Drupal.settings.basePath + 'findimage',
                type: 'post',
                beforeSend: function() {
                    showloader();

                },
                data: {'formdata': serializeform},
                success: function(data) {
                    jQuery('#search-preview').html(data);
                },
                complete: function() {
                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });

        }, 2000);
    })

    jQuery('.view-content #easyPaginate img').live('click', function() {
        var getimageurl = jQuery(this).attr('src');
        var altdata = jQuery(this).attr('alt');
        var titledata = jQuery(this).attr('title');
        var fieldname = parent.jQuery('#field_name').val();
        parent.jQuery('#img_alttext').val(altdata);
        parent.jQuery('#img_title').val(titledata);
        jQuery.ajax({
            url: Drupal.settings.basePath + 'saveimage',
            type: 'post',
            beforeSend: function() {
                parent.jQuery('#loader-data').show();
            },
            data: {'imageurl': getimageurl, 'field_name': fieldname},
            success: function(data) {
                var objdata = jQuery.parseJSON(data);
                var imageId = objdata.fid;
                var height = parent.jQuery('#image_height').val();
                var width = parent.jQuery('#image_width').val();
                var ctype = parent.jQuery('#content_type').val();

                if (imageId != "")
                {

                    var imageName = jQuery(this).siblings('.dz-image').children('img').attr('imgname');
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'getimagetocroper',
                        type: 'post',
                        data: {'imageId': imageId, 'solr': 1, 'field_id': fieldname, 'content_type': ctype, 'img_height': height, 'img_width': width},
                        success: function(data) {
                            //  itg_image_repository.processResponse
                            parent.jQuery('#search-preview').hide();
                            if (!jQuery('#itg_image_repository-content').hasClass('after-croper')) {
                                jQuery('#itg_image_repository-content').addClass('after-croper');
                            }
                            parent.jQuery('#file-preview').show().html(data);
                            parent.jQuery('#loader-data').hide();
                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
                }

            },
            complete: function() {
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });

    })


    jQuery('.view-content #easyPaginate img').live('mouseenter', function(e) {
        var timeout;
        var datathis = jQuery(this);
        var getimageurl = datathis.attr('src');
        var altdata = jQuery(this).attr('alt');
        var titledata = jQuery(this).attr('title');
        var fieldname = parent.jQuery('#field_name').val();
//        parent.jQuery('#img_alttext').val(altdata);
//        parent.jQuery('#img_title').val(titledata);
        timeout = setTimeout(function() {
            jQuery.ajax({
                url: Drupal.settings.basePath + 'get_dimension',
                type: 'post',
                beforeSend: function() {
                    datathis.after('<div class="throbbing"></div>');
                },
                data: {'imageurl': getimageurl, 'field_name': fieldname},
                success: function(data) {
                    jQuery('.image-dim').remove();
                    jQuery('.throbbing').remove();

                    datathis.after(data);
                    parent.jQuery('#loader-data').hide();

                },
                complete: function() {
                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });

        }, 2000);
        jQuery(e.target).live('mouseleave', function() {
            jQuery('.image-dim').remove();
            clearTimeout(timeout);
        });
    });


    jQuery('.imgtags img').live('click', function(e) {
        var fid = jQuery(this).parent('.imgtags').attr('img-fid');
        if (fid != "" && fid != 'undefined')
        {

            jQuery.ajax({
                url: Drupal.settings.basePath + 'front_imagetag',
                type: 'post',
                data: {'fid': fid},
                beforeSend: function() {
                    jQuery('#widget-ajex-loader').show();
                },
                success: function(data) {
                    jQuery('#widget-ajex-loader').hide();
                    $.colorbox({html: "" + data + "", onComplete: function() {
                            $(this).colorbox.resize();
                        }});


                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        }
    });


})(jQuery);
