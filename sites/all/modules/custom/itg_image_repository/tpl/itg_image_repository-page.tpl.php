<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $GLOBALS['language']->language; ?>" xml:lang="<?php print $GLOBALS['language']->language; ?>" class="itg_image_repository">

    <head>
        <title><?php print t('File Browser'); ?></title>
        <meta name="robots" content="noindex,nofollow" />
        <?php
        if (isset($_GET['app'])): drupal_add_js(drupal_get_path('module', 'itg_image_repository') . '/js/itg_image_repository_set_app.js');
        endif;
        ?>
        <?php print drupal_get_html_head(); ?>
        <?php print drupal_get_css(); ?>
        <?php print drupal_get_js('header'); ?>
        <style media="all" type="text/css">/*Quick-override*/</style>
    </head>

    <body class="itg_image_repository">
        <div id="itg_image_repository-messages"><?php print theme('status_messages'); ?></div>
        <?php print $content; ?>
        <input type="hidden" id="field_name" value="<?php echo $_GET['field_name']; ?>" >
            <input type="hidden" id="image_height" value="<?php echo $_GET['height']; ?>" >
                <input type="hidden" id="image_width" value="<?php echo $_GET['width']; ?>" >
                  <input type="hidden" id="btn_name" value="<?php echo $_GET['btn_name']; ?>" >

                    <script type="text/javascript">
                        var fieldname = '<?php echo $_GET['field_name']; ?>';
                        var height = '<?php echo $_GET['height']; ?>';
                        var width = '<?php echo $_GET['width']; ?>';
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
                                    data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width},
                                    success: function(data) {
                                        //  itg_image_repository.processResponse
                                        hideloader();
                                        jQuery('#file-preview').html(data);
                                    },
                                    error: function(xhr, desc, err) {
                                        console.log(xhr);
                                        console.log("Details: " + desc + "\nError:" + err);
                                    }
                                });
                            }

                        })

                        jQuery('body').on('click', '.dz-remove', function() {
                            jQuery('#file-preview').html('');

                            var imageId = jQuery(this).siblings('.dz-image').children('img').attr('imageid');
                            alert(imageId);

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
                                    data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width},
                                    success: function(data) {
                                        //  itg_image_repository.processResponse
                                        hideloader();
                                        jQuery('#file-preview').html(data);
                                    },
                                    error: function(xhr, desc, err) {
                                        console.log(xhr);
                                        console.log("Details: " + desc + "\nError:" + err);
                                    }
                                });
                            }
                        })

                        function showloader()
                        {
                            jQuery('#loader-data').show();
                        }
                        function hideloader()
                        {
                            jQuery('#loader-data').hide();
                        }

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
                                            data: {'imageId': imageId, 'field_id': fieldname, 'img_height': height, 'img_width': width},
                                            success: function(data) {
                                                //  itg_image_repository.processResponse
                                                hideloader();
                                                jQuery('#file-preview').html(data);
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
                    </script>

                    <?php print drupal_get_js('footer'); ?>
                    </body>

                    </html>
