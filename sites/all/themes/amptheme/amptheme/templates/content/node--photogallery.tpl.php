<div class="black-box">
  <div class="photo-title"><h1><?php print $node->title; ?></h1></div>
  <div class="amp-photo-slider">
      <?php
      global $base_url;
      if (!empty($node->field_gallery_image[LANGUAGE_NONE])) {
        $html = '';
        ?>
        <amp-carousel class="collapsible-captions"
                      height="363"
                      layout="fixed-height"
                      type="slides">
                          <?php
                          $i = 1;
                          $srcset = '';
                          
  ?>

        </amp-carousel>
  <?php
}
?>
  </div>
</div>
<?php if(!empty(variable_get('amp_taboola_ad_script'))) { ?>
  <div class="amp-taboola">
	<?php print variable_get('amp_taboola_ad_script'); ?>
  </div>
<?php } ?>
<?php if(!empty(variable_get('amp_photo_second_ad'))) { ?>
  <div class="custom-amp-ad ad-btf">
    <?php print variable_get('amp_photo_second_ad'); ?> 
  </div>
<?php } ?>
<div class="amp-other-gallery">
<?php
// get all node id related to current node primary category
if (function_exists('get_other_gallery_amp')) {
  global $base_url;
  $primary_category = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
  $entity_arr = get_other_gallery_amp($primary_category, $node->nid, $node->type, 4);
  if (!empty($entity_arr)) {
    $other_gallery = '';
    $other_gallery .= '<h2><span>'.t('OTHER GALLERIES').'</span></h2>';
    $other_gallery .= '<ul>';
    foreach ($entity_arr as $key => $value) {
      // get image count
      if (function_exists('get_image_count_entity_id')) {
        $img_count = get_image_count_entity_id($value['entity_id'], 'photogallery', 'field_gallery_image');
      }
      $small_width = 170;
      $entity_id = $value['entity_id'];
      if (!empty($value['field_story_small_image_fid'])) {
        $file = file_load($value['field_story_small_image_fid']);
        $small_image = file_create_url($file->uri);
        //$other_src_set = $small_image . ' ' . $small_width . 'w';
      }
      else {
        $small_image = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');
        //$other_src_set = $small_image . ' ' . $small_width . 'w';
      }
      
      $alias = drupal_get_path_alias('node/'.$value['nid']);
      $path_alias = $base_url.'/amp/'.$alias;
      $dec_title = html_entity_decode($value['title']);
      $title = l($dec_title, $path_alias, array("attributes" => array("title" => $dec_title)));
      $amp_image = '<a href="' . $path_alias . '"><amp-img height="127" width="170" layout="responsive"  alt="' . $dec_title . '" title="' . $dec_title . '" src="' . $small_image . '"><div fallback>offline</div></amp-img></a>';
      $other_gallery .= '<li><div class="other-img">' . $amp_image . '<div class="other-count"><i class="fa fa-camera" aria-hidden="true"></i> ' . $img_count . ' images</div></div><div class="other-date">' . date('D, d M, Y', $value['created']) . '</div><div class="other-title">' . $title . '</div></li>';
    }
    $other_gallery .= '</ul>';
    print $other_gallery;
  }
}
?>  
</div>
