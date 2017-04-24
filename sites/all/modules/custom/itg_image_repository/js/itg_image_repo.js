

/*
 * @file itg_image_repo.js
 * Contains all the functionality of imagerepo 
 */
(function($) {

    // Place your code here.

    jQuery('body').on('click', '.dz-details', function() {
        jQuery('#file-preview').html('');

        var imageId = jQuery(this).siblings('.dz-image').children('img').attr('imageid');
        if (imageId != "")
        {
            showloader();
            var imageName = jQuery(this).siblings('.dz-image').children('img').attr('imgname');
            jQuery.ajax({
                url: Drupal.settings.basePath + 'getimagetocroper',
                type: 'post',
                data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width, 'content_type': content_type},
                success: function(data) {
                    //  itg_image_repository.processResponse
                    hideloader();
                    if (!jQuery('#itg_image_repository-content').hasClass('after-croper')) {
                        jQuery('#itg_image_repository-content').addClass('after-croper');
                    }
                    jQuery('#file-preview').show().html(data);
                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        }

    })




    // This code use for image search and crop

    jQuery('.searched-image').live('click', function() {
        var imageId = jQuery(this).attr('imageid');
        jQuery('#file-preview').html('');
        if (imageId != "")
        {
            showloader();
            var imageName = jQuery(this).siblings('.dz-image').children('img').attr('imgname');
            jQuery.ajax({
                url: Drupal.settings.basePath + 'getimagetocroper',
                type: 'post',
                data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width, 'content_type': content_type},
                success: function(data) {
                    //  itg_image_repository.processResponse
                    hideloader();
                    if (!jQuery('#itg_image_repository-content').hasClass('after-croper')) {
                        jQuery('#itg_image_repository-content').addClass('after-croper');
                    }
                    jQuery('#file-preview').show().html(data);
                },
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        }
    })


    Dropzone.autoDiscover = false;
    jQuery("#itg-image-repository-upload-form").dropzone({
        // addRemoveLinks: true,
        maxFiles: 1, removedfile: function(file) {
            var _ref;
            if (file.previewElement.classList.contains('dz-success'))
            {
                jQuery('#file-preview').html('');
            }
            if (file.previewElement) {
                if ((_ref = file.previewElement) != null) {
                    _ref.parentNode.removeChild(file.previewElement);

                }
            }
            return this._updateMaxFilesReachedClass();
        }, maxfilesexceeded: function(file) {
            this.removeAllFiles();
            this.addFile(file);
        },
        init: function() {
            this.on("success", function(file, responseText) {
                var obj = jQuery.parseJSON(responseText);
                imageId = obj.data.added[0].id;
                if (imageId != "")
                {
                    showloader();
                    var imageName = jQuery(this).siblings('.dz-image').children('img').attr('imgname');
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'getimagetocroper',
                        type: 'post',
                        data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width, 'content_type': content_type},
                        success: function(data) {
                            //  itg_image_repository.processResponse
                            hideloader();
                            if (!jQuery('#itg_image_repository-content').hasClass('after-croper')) {
                                jQuery('#itg_image_repository-content').addClass('after-croper');
                            }
                            jQuery('#file-preview').show().html(data);
                        },
                        error: function(xhr, desc, err) {
                            console.log(xhr);
                            console.log("Details: " + desc + "\nError:" + err);
                        }
                    });
                }
            });
        }

    });

})(jQuery, Drupal, this, this.document);
function showloader()
{
    jQuery('#loader-data').show();
}
function hideloader()
{
    jQuery('#loader-data').hide();
}
