	
<?php
global $base_url;
list($width, $height) = getimagesize($url);
?>
<link rel="stylesheet" type="text/css" href="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_image_croping') . '/css/itg_tagging.css'; ?>">
<div id="container">
  <h4 class="tag-image"><i class="fa fa-tags"></i> Tagging</h4>
  <form name="image_teg_form" id="image_teg_form" methode="post">
    <?php
    $counter = 1;
    foreach ($data->fid as $key => $fids) {


      $image_dim = mageimagedimesion();

      $explodedata = explode('#', $fids);
      if ($key == 0) {
        $key = "";
        $fidsformain = $explodedata[0];
      }
      $file = file_load($explodedata[0]);
      $imagename = str_replace('field_story_', '', $explodedata[1]);

      $imagename = str_replace('_', ' ', $imagename);
      $url = file_create_url($file->uri);
      print '<div id="imgtag' . $key . '" class="multipal-crop-images"> 
        <img id="" src="' . $url . '" alt="" /> 
        <div id="tagbox' . $key . '">
        </div>
        <input type="hidden" name="fids[]" class="imagefid" value="' . $fids . '">
           <div id="taglist' . $key . '" class="tag-box-input"> 
        <ol> 
        </ol>';
      if ($content_name != "") {
        $imagewidth = $image_dim[$content_name][$explodedata[1]]['width'];
        $imagehight = $image_dim[$content_name][$explodedata[1]]['height'];

        if ($imagewidth == "") {
          $imagewidth = EXTRA_LARGE_IMAGE_WIDTH;
        }
        if ($imagehight == "") {
          $imagehight = EXTRA_LARGE_IMAGE_HEIGHT;
        }
        print' <div class="image_info">' . $counter . ' ' . ucwords($imagename) . ' (' . $imagewidth . 'x' . $imagehight . ')</div>';
      }
     if($key == 0) {
                 print ' <div class="syndicate-lable"><input type="checkbox" class ="is_synd is_synd_all" name="syndicate_' . $explodedata[0] . '" value="1"> Syndicate</div>';

        print '<input type="text" name="image_alt[]" placeholder="Alt Text" class="alt_text"  value=""></br><input type="text" name="image_title[]" placeholder="Title" class="image_title"  value=""></br>';

        } else {
                print ' <div class="syndicate-lable"><input type="checkbox" class ="is_synd is_synd_all_for" name="syndicate_' . $explodedata[0] . '" value="1"> Syndicate</div>';

               print '<input type="text" name="image_alt[]" placeholder="Alt Text" class="alt_text_image"  value=""></br><input type="text" name="image_title[]" placeholder="Title" class="image_title_exta"  value=""></br>';

     }
if($key == 0) {
      print'<input type="text" name="courtesy[]" class="image_courtesy" placeholder="Courtesy"  value=""></br>'
              . '<input type="text" class="image_keyword" name="keyword[]" placeholder="Keyword"  value=""></br>'
              . '<input type="text" class="image_tags" name="tags[]" placeholder="Tags"  value=""></br>'
              . '<input type="text" class="image_place" name="place[]" placeholder="Place"  value=""></br>'
              . '<input type="text" class="image_photo_grapher" name="photo_grapher[]" placeholder="Photographer"  value=""></br>'
              . '<input type="text" class="image_date" name="image_date[]" placeholder="Date (dd/mm/yyyy)"  value=""></br>'
              . '<input type="text" class="image_description" name="image_description[]" placeholder="Description"  value=""></br>'
              . '</div> </div> ';
}else {
   print'<input type="text" class="image_courtesy_img" name="courtesy[]" placeholder="Courtesy"  value=""></br>'
              . '<input type="text" class="image_keyword_img" name="keyword[]" placeholder="Keyword"  value=""></br>'
              . '<input type="text" class="image_tags_img" name="tags[]" placeholder="Tags"  value=""></br>'
              . '<input type="text" class="image_place_img" name="place[]" placeholder="Place"  value=""></br>'
              . '<input type="text" class="image_photo_grapher_img" name="photo_grapher[]" placeholder="Photographer"  value=""></br>'
              . '<input type="text" class="image_date_img" name="image_date[]" placeholder="Date (dd/mm/yyyy)"  value=""></br>'
              . '<input type="text" class="image_description_img" name="image_description[]" placeholder="Description"  value=""></br>'
              . '</div> </div> ';
}


      $counter++;
    }
    ?>
  </form>
  <button class="add-more maptofield">Upload</button>
  <button class="cancel-image add-more">Cancel</button>
  <input type="hidden" value="<?php echo $field_name; ?>" id="field_name">
  <input type="hidden" value="<?php echo $fidsformain; ?>" id="image_fiedlid">
  <input type="hidden" value="<?php echo $url; ?>" id="imcurl">
  <input type="hidden" id="orig_image_fiedlid" value="<?php echo $original_img_id; ?>">
  <input type="hidden" id="is_solr" value="<?php echo $is_solr; ?>">
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