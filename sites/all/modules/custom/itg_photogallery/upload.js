/*
 * @file upload.js
 * Contains all functionality related to upload 
 */
(function($) {

    Drupal.behaviors.itg_photogallery = {
        context: null,
        attach: function(context) {
            var that = this,
            uploader = $('.plupload-element', context).pluploadQueue();
            
            this.context = context;
            
            if (!uploader) {
                return false;
            }
            
            uploader.bind('FilesAdded', function (up, files) {
                var i = 0,
                maxCountError = false;
                plupload.each(files, function (file) {                        
                    if (uploader.settings.max_file_count && i >= uploader.settings.max_file_count) {
                        maxCountError = true;
                        setTimeout(function () {
                            up.removeFile(file);
                        }, 50);
                    }
                    i++;
                });
                if (maxCountError) {
                    alert("You can upload only "+uploader.settings.max_file_count+" images at once");
                }
                
                for (var j = 0; j < uploader.files.length; j++) {
                    if (uploader.files[j].name.indexOf("_IT_") !== undefined && uploader.files[j].name.indexOf("_IT_") < 0) {
                        org_filename = uploader.files[j].name;
                        extention = org_filename.substr((org_filename.lastIndexOf('.') + 1));
                        filename = org_filename.substr(0, (org_filename.lastIndexOf('.')));
                        file_timestamp = new Date().getTime();
                        uploader.files[j].name = filename + "_IT_" + file_timestamp + '.' + extention;
                    }
                }
                // start upload automatically once files have been added to queue
                that.start();
            });

            uploader.bind('UploadComplete', function() {
                var filenumber = uploader.files.length;
                $('#edit-field-gallery-image-add-more-number').val(filenumber);
                // trigger click on submit button to submit form once upload completed
                that.complete();

            });

            return this;
        },
        start: function() {
            $('.file-upload-submit', this.context)
                    .attr('disabled', 'disabled');
        },
        complete: function() {
            $('input[name=field_gallery_image_add_more]').mousedown();

            $('.file-upload-submit', this.context)
                    .removeAttr('disabled')
                    .click();
            setTimeout(function() {
                var uploader = jQuery(".plupload-element").pluploadQueue();
                
                uploader.splice();
                
                uploader.refresh();
                
                $('#edit-field-gallery-image-add-more-number').val(1);

            }, 500);
            
            $('.plupload_filelist_footer .plupload_buttons').show();
            $('.plupload_file_name span.plupload_upload_status').hide();
        }
    };

})(jQuery);
