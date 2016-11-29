	
<?php
global $base_url;
list($width, $height) = getimagesize($url);
?>
<link rel="stylesheet" type="text/css" href="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_image_croping') . '/css/itg_tagging.css'; ?>">
<div id="container">
    <h4 class="tag-image"><i class="fa fa-tags"></i> Tagging</h4>
    <?php
    foreach ($data->fid as $key => $fids) {
        if ($key == 0) {
            $key = "";
        }
        $explodedata = explode('#', $fids);
        $file = file_load($explodedata[0]);
        $url = file_create_url($file->uri);
        print '<div id="imgtag' . $key . '"> 
        <img id="" src="' . $url . '" /> 
        <div id="tagbox' . $key . '">
        </div>
        <input type="hidden" class="imagefid" value="' . $fids . '">
        </div> 
        <div id="taglist' . $key . '"> 
        <ol> 
        </ol> 
        </div> ';
    }
    ?>
    <button class="add-more maptofield">Upload</button>
    <button class="cancel-image add-more">Cancel</button>
    <input type="hidden" value="<?php echo $field_name; ?>" id="field_name">
    <input type="hidden" value="<?php echo $file->fid; ?>" id="image_fiedlid">
    <input type="hidden" value="<?php echo $url; ?>" id="imcurl">
    <input type="hidden" value="<?php echo $height; ?>" id="imcheigth">
    <input type="hidden" value="<?php echo $width; ?>" id="imcwidth">
</div>
<?php drupal_add_js(drupal_get_path('module', 'itg_image_croping') . '/js/itg_fieldmapping.js', array('
  type' => 'file', 'scope' => 'content'));
?>
<?php
print $js = drupal_get_css('content');
print $js = drupal_get_js('content');
?>