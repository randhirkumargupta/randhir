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

    jQuery('.view-content img').live('click', function() {
        var getimageurl = jQuery(this).attr('src');
        var altdata=jQuery(this).attr('alt');
        parent.jQuery('#img_alttext').val(altdata);
        jQuery.ajax({
            url: Drupal.settings.basePath + 'saveimage',
            type: 'post',
            beforeSend: function() {
                parent.jQuery('#loader-data').show();
            },
            data: {'imageurl': getimageurl},
            success: function(data) {
                var objdata = jQuery.parseJSON(data);
                var imageId = objdata.fid;
                var fieldname = parent.jQuery('#field_name').val();
                var height = parent.jQuery('#image_height').val();
                var width = parent.jQuery('#image_width').val();

                if (imageId != "")
                {

                    var imageName = jQuery(this).siblings('.dz-image').children('img').attr('imgname');
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'getimagetocroper',
                        type: 'post',
                        data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width},
                        success: function(data) {
                            //  itg_image_repository.processResponse
                            parent.jQuery('#file-preview').html(data);
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



})(jQuery);
