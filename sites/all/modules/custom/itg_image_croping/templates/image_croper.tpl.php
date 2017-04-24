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

drupal_add_js(drupal_get_path('module', 'itg_image_croping') . '/js/itg_crop.js', array('
  type' => 'file', 'scope' => 'content'));
$imagedata = base64_encode(file_get_contents($data->uri));
$url = file_create_url($data->uri);
$image_exten = end(explode('.', $data->uri));
?>
<input type="hidden" id="crop_image_url" value="<?php echo $url; ?>">
<input type="hidden" id="image_fiedlid" value="<?php echo $data->fid; ?>">

<input type="hidden" id="orig_image_fiedlid" value="<?php echo $data->fid; ?>">
<input type="hidden" id="image_exten" value="<?php echo $image_exten; ?>">

<div class="croper">
    <div class="first-resize">
        <?php echo $form; ?>
    </div>
</div>
<div class="croper-action">
    <button class=" add-more <?php echo ($extra_crop == 1) ? 'crop-all' : 'crop-image'; ?>">Crop</button>
    <button class="original-image add-more">Use Original</button>
    <button class="cancel-image add-more">Cancel</button>
    <?php
//    if ($genrate == 1) {
//        print' <button class="generate-Image add-more">Generate Image</button>';
//    }
    ?>
</div>

<!--   -->
<?php print $js = drupal_get_js('content');
?>