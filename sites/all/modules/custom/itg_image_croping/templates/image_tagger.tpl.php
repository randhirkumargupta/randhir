	
<?php
$url = file_create_url($data->uri);
global $base_url;
list($width, $height) = getimagesize($url);
?>
<link rel="stylesheet" type="text/css" href="<?php echo $base_url.'/'.drupal_get_path('module', 'itg_image_croping') . '/css/itg_tagging.css';?>">
<div id="container">
    <h4 class="tag-image"><i class="fa fa-tags"></i> Tagging</h4>
    <div id="imgtag"> 

        <img id="" src="<?php echo $url; ?>" /> 
        <div id="tagbox">
        </div>
    </div> 
    <div id="taglist"> 
        <ol> 
        </ol> 
    </div> 
    <button class="add-more maptofield">Upload</button
    <input type="hidden" value="<?php echo $field_name; ?>" id="field_name">
    <input type="hidden" value="<?php echo $data->fid; ?>" id="image_fiedlid">
    <input type="hidden" value="<?php echo $url; ?>" id="imcurl">
    <input type="hidden" value="<?php echo $height; ?>" id="imcheigth">
    <input type="hidden" value="<?php echo $width; ?>" id="imcwidth">
</div>
<script type="text/javascript" src="<?php echo base_path() . 'sites/all/modules/custom/itg_image_croping/js/jquery.min.js'; ?>"></script>
<?php drupal_add_js(drupal_get_path('module', 'itg_image_croping') . '/js/itg_fieldmapping.js', array('
  type' => 'file', 'scope' => 'content'));  
  
?>
<?php 
print $js = drupal_get_css('content');
print $js = drupal_get_js('content');
?>