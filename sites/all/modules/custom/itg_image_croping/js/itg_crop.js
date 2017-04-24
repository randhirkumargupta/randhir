

/*
 * @file itg_crop.js
 * Contains all the functionality of image crop set image to croper tool
 */
(function($) {

    // Place your code here.

    jQuery('.image-editor').cropit({
        imageState: {
            src: jQuery('#crop_image_url').val(),
        },
        mageBackgroundBorderWidth: 10,
        initialZoom: 'image',
        maxZoom: 10,
        quality: 1,
         crossDomain:true,
        minZoom: 'fill',
        smallImage: 'stretch',
        imageBackground: true,

    });
    jQuery('form').submit(function() {
        // Move cropped image data to hidden input
        var image_exten = jQuery('#image_exten').val();
        if (image_exten == "") {
            image_exten = 'png';
        }
        alert(image_exten);
        var imageData = jQuery('.image-editor').cropit('export', {
            type: 'image/' + image_exten,
        });
        jQuery('.hidden-image-data').val(imageData);

        // Print HTTP request params
        var formValue = $(this).serialize();
        jQuery('#result-data').text(formValue);

        return false;
    });



//  cancel image
    jQuery('.cancel-image').click(function() {
        if (jQuery('.div-upload-img').hasClass('active'))
        {
            jQuery('#file-preview').hide();
        } else {
            jQuery('#file-preview').hide();
            jQuery('#search-preview').show();
        }
    });
    jQuery('.generate-Image').click(function() {

        jQuery('.image-fiels-style').show();

    });

    jQuery('.crop-image').click(function() {
        showloader();
        var original_img_id = jQuery('#orig_image_fiedlid').val();
        var is_solr = jQuery('#is_solr').val();
        var image_exten = jQuery('#image_exten').val();
        if (image_exten == "") {
            image_exten = 'png';
        }
        if (image_exten == 'jpg')
        {
            image_exten = 'jpeg';
        }
        var content_type = jQuery('#data_content_name').val();
        var field_name = jQuery('#data_field_name').val();
        var image_data_first = jQuery('.image-editor').cropit('export', {
            type: 'image/' + image_exten,
        });
        var imagefield = []; // more efficient than new Array()
        jQuery(".checkbox-image-size").each(function() {
            if (jQuery(this).is(':checked'))
            {
                imagefield.push(jQuery(this).val());

            }
        });

        jQuery.ajax({
            url: Drupal.settings.basePath + 'savecropedimage',
            type: 'post',
            data: {'image_data': image_data_first, 'content_name': content_type, 'field_name': field_name, 'image_fields': imagefield,'original_img_id': original_img_id,},
            success: function(data) {

                var image_fiedlid = data;
                if (image_fiedlid != "")
                {
                    var image_id = jQuery('#image_fiedlid').val();

                    // get the image tagging page
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'imagetotag',
                        type: 'post',
                        data: {'fid': image_fiedlid, 'is_solr': is_solr, 'original_img_id': original_img_id, 'field_name': field_name, 'image_fields': imagefield, 'content_name': content_type},
                        success: function(data) {

                            jQuery('#file-preview').html(data);
                            hideloader();

                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
                }


            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        }); // end ajax call

    });



    jQuery('.original-image').click(function() {
        showloader();
        var content_type = jQuery('#data_content_name').val();
        var field_name = jQuery('#data_field_name').val();
        var image_fiedlid = jQuery('#image_fiedlid').val();
      var original_img_id = jQuery('#orig_image_fiedlid').val();
        var is_solr = jQuery('#is_solr').val();
        var imagefield = []; // more efficient than new Array()
        jQuery(".checkbox-image-size").each(function() {
            if (jQuery(this).is(':checked'))
            {
                imagefield.push(jQuery(this).val());

            }
        });
        var resize_image_height = jQuery('#image_original_hight').val();
        var resize_image_width = jQuery('#image_original_width').val();
        jQuery.ajax({
            url: Drupal.settings.basePath + 'savecropedimage_orignal',
            type: 'post',
            data: {'image_fiedlid': image_fiedlid, 'resize_image_width': resize_image_width, 'resize_image_height': resize_image_height, 'content_name': content_type, 'field_name': field_name, 'image_fields': imagefield},
            success: function(data) {

                var image_fiedlid = data;
                if (image_fiedlid != "")
                {
                    // get the image tagging page
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'imagetotag',
                        type: 'post',
                        data: {'fid': image_fiedlid, 'is_solr': is_solr, 'original_img_id': original_img_id,'field_name': field_name, 'image_fields': imagefield},
                        success: function(data) {

                            jQuery('#file-preview').html(data);
                            hideloader();

                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
                }


            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        }); // end ajax call

    });

//    jQuery('.original-image').click(function() {
//        showloader();
//        var field_name = jQuery('#data_field_name').val();
//        var image_fiedlid = jQuery('#image_fiedlid').val();jQuery(".checkbox-image-size").each(function() {
//            if (jQuery(this).is(':checked'))
//            {
//                imagefield.push(jQuery(this).val());
//
//            }
//        });
//        
//        jQuery.ajax({
//            url: Drupal.settings.basePath + 'imagetotag',
//            type: 'post',
//            data: {'fid': image_fiedlid, 'field_name': field_name},
//            success: function(data) {
//                jQuery('#file-preview').html(data);
//                hideloader();
//
//            },
//            error: function(xhr, desc, err) {
//                console.log(xhr);
//                console.log("Details: " + desc + "\nError:" + err);
//            }
//        });
//    });
    jQuery('#select-aspect-ratio').change(function() {
        var get_aspect_ratio = jQuery(this).val();
        var field_name = jQuery('#data_field_name').val();
        var image_fiedlid = jQuery('#image_fiedlid').val();
        var get_original_height = jQuery('#image_original_hight').val();
        var get_original_width = jQuery('#image_original_width').val();
        jQuery.ajax({
            url: Drupal.settings.basePath + 'change_image_aspect_ratio',
            type: 'post',
            data: {'imageId': image_fiedlid, 'field_name': field_name, 'original_height': get_original_height, 'origninal_width': get_original_width, 'aspect_ratio': get_aspect_ratio},
            beforeSend: function() {
                showloader();
            },
            success: function(data) {
                hideloader();
                jQuery('#file-preview').show().html(data);

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    })

})(jQuery, Drupal, this, this.document);
