	
<?php
global $base_url;
list($width, $height) = getimagesize($url);
?>
<link rel="stylesheet" type="text/css" href="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_image_croping') . '/css/itg_tagging.css'; ?>">
<div id="container">
    <h4 class="tag-image"><i class="fa fa-tags"></i> Tagging</h4>
    <form name="image_teg_form" id="image_teg_form" methode="post">
    <?php
    $counter=1;
    foreach ($data->fid as $key => $fids) {
  
        if ($key == 0) {
            $key = "";
        }
        $image_dim=mageimagedimesion();
       
        $explodedata = explode('#', $fids);
        $file = file_load($explodedata[0]);
        $imagename=  str_replace('field_story_','', $explodedata[1]);
         
        $imagename=  str_replace('_', ' ', $imagename);
        $url = file_create_url($file->uri);
        print '<div id="imgtag' . $key . '" class="multipal-crop-images"> 
        <img id="" src="' . $url . '" /> 
        <div id="tagbox' . $key . '">
        </div>
        <input type="hidden" name="fids[]" class="imagefid" value="' . $fids . '">
           <div id="taglist' . $key . '" class="tag-box-input"> 
        <ol> 
        </ol>';
        if($content_name!="")
        {
       print' <div class="image_info">'.$counter.' '. ucwords($imagename).' ('.$image_dim[$content_name][ $explodedata[1]]['width'].'x'.$image_dim[$content_name][ $explodedata[1]]['height'].')</div>';
        
        }
       
        print' <input type="text" name="courtesy[]" placeholder="Courtesy"  value=""></br>
                <div class="syndicate-lable"><input type="checkbox" name="syndicate_'.$explodedata[0].'" value="1"> Syndicate</div></div> </div> ';  
       
       
        $counter++;
    }
    ?>
    </form>
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