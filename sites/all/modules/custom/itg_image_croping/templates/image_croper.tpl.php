<script type="text/javascript" src="<?php echo base_path() . 'sites/all/modules/custom/itg_image_croping/js/jquery.min.js'; ?>"></script>

<script type="text/javascript" src="<?php echo base_path() . 'sites/all/modules/custom/itg_image_croping/js/jquery.cropit.js'; ?>"></script>

<style>
    .cropit-preview {
        background-color: #f8f8f8;
        background-size: cover;
        border: 1px solid #ccc;
        border-radius: 3px;
        margin-top: 7px;
        width: <?php echo $image_width; ?>px;
        height:<?php echo $image_height; ?>px;
        margin:0 !important;
    }
    .cropit-preview img{
        max-width:none;
    }

    .cropit-preview2 {
        background-color: #f8f8f8;
        background-size: cover;
        border: 1px solid #ccc;
        border-radius: 3px;
        margin-top: 7px;
        width: 450px;
        height: 250px;
    }
    .cropit-preview-image-container {
        cursor: move;
        position: absolute;
        overflow: inherit;
        left: 0px;
        top: 0px;
        width: 100%;
        height: 100%;
        right: 0;
        bottom: 0;
    }
    .cropit-preview-background-container img{
        opacity: 0.2;
    }
    .image-size-label {
        margin-top: 10px;
    }

    input {
        display: block;
    }

    button[type="submit"] {
        margin-top: 10px;
    }

    #result {
        margin-top: 10px;
        width: 900px;
    }

    #result-data {
        display: block;
        overflow: hidden;
        white-space: nowrap;
        text-overflow: ellipsis;
        word-wrap: break-word;
    }
    .first-resize, .second-resize{
        width: <?php echo $image_width; ?>px;
        margin-left:100px;
    }
    .cropit-image-zoom-input{display: inline-block;}
    .cropit-image-zoom{
        z-index: 99;
        position: relative;
        margin:20px 0;
    }
    .crop-image{
        padding:6px 40px;
        cursor:pointer;
        position: relative;
        z-index: 999;
    }
    .cropit-image-zoom-input{
        -webkit-appearance: none;
        -moz-appearance: none;
        appearance: none;
        height: 5px;
        background: #a9a9a9;
        -webkit-border-radius: 5px;
        border-radius: 5px;
        outline: none;
    }
    #loader-data{
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        background: rgba(0, 0, 0, 0.38);
        height: 100%;
        z-index: 9999;
        text-align: center;
        color: #fff;
        padding-top: 150px;
        font-size: 18px;
    }
</style>

<?php
$imagedata = base64_encode(file_get_contents($data->uri));
$url = file_create_url($data->uri);
?>

<div class="croper">
    <div class="first-resize">
        <?php echo $form; ?>
    </div>
</div>
<div class="croper-action">
    <button class="crop-image add-more">Crop</button>
    <button class="original-image add-more">Use Original</button>
</div>

<!--   -->

<script>
    jQuery(function() {
        jQuery('.image-editor').cropit({
            imageState: {
                src: '<?php echo $url; ?>',
            },
            mageBackgroundBorderWidth: 10,
            initialZoom: 'image',
            maxZoom: 10,
            quality: 1,
            minZoom: 'fill',
            smallImage: 'stretch',
            imageBackground: true

        });
        jQuery('form').submit(function() {
            // Move cropped image data to hidden input
            var imageData = jQuery('.image-editor').cropit('export');
            jQuery('.hidden-image-data').val(imageData);

            // Print HTTP request params
            var formValue = $(this).serialize();
            jQuery('#result-data').text(formValue);

            // Prevent the form from actually submitting
            return false;
        });

    });



    jQuery('.crop-image').click(function() {
        showloader();
        var field_name = jQuery('#data_field_name').val();
        var image_data_first = jQuery('.image-editor').cropit('export');
        jQuery.ajax({
            url: Drupal.settings.basePath + 'savecropedimage',
            type: 'post',
            data: {'image_data': image_data_first, 'field_name': field_name},
            success: function(data) {

                var objdata = jQuery.parseJSON(data);
                var image_fiedlid = objdata.fid;
                if (image_fiedlid != "")
                {
                    // get the image tagging page
                    jQuery.ajax({
                        url: Drupal.settings.basePath + 'imagetotag',
                        type: 'post',
                        data: {'fid': image_fiedlid, 'field_name': field_name},
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
        var field_name = jQuery('#data_field_name').val();
        var image_fiedlid = '<?php echo $data->fid ?>';
        jQuery.ajax({
            url: Drupal.settings.basePath + 'imagetotag',
            type: 'post',
            data: {'fid': image_fiedlid, 'field_name': field_name},
            success: function(data) {
                jQuery('#file-preview').html(data);
                hideloader();

            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    });


</script>
