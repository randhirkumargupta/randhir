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

            uploader.bind('FilesAdded', function() {
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
                //  var uploader = $('.plupload-element').plupload('getUploader');
                //uploader.destroy();

                uploader.splice();
                //uploader.clearQueue();
                //uploader.init();

                uploader.refresh();
                
                $('#edit-field-gallery-image-add-more-number').val(1);

            }, 500);
            $('.plupload_filelist_footer .plupload_buttons').show();
            $('.plupload_file_name span.plupload_upload_status').hide();
        }
    };

})(jQuery);