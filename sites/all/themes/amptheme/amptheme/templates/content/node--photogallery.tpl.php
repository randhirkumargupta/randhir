<?php if(!empty(variable_get('amp_photo_ad'))) { ?>
<div class="custom-amp-ad">
<?php print variable_get('amp_photo_ad'); ?> 
</div>
<?php } ?>
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
                          foreach ($node->field_gallery_image['und'] as $photo_item) {
                            //$buzz_output.= '<div class="buzz-section">';
                            $field_collection_id = $photo_item['value'];
                            $entity = entity_load('field_collection_item', array($field_collection_id));
                            $file = file_load($entity[$field_collection_id]->field_images['und'][0]['fid']);
                            $small_file = file_load($entity[$field_collection_id]->field_photo_small_image['und'][0]['fid']);
                            $caption = $entity[$field_collection_id]->field_image_caption['und'][0]['value'];
                            $amp_image = file_create_url($file->uri);
                            $small_amp_image = file_create_url($small_file->uri);
                            $data = getimagesize($amp_image);
                            $width = $data[0];
                            $height = $data[1];

                            if ($height > 363) {
                              $height = 363;
                              $width = 647;
                            }

                            if (!empty($small_file->uri)) {
                              $small_data = getimagesize($small_amp_image);
                              if ($small_data[1] > 363) {
                                $small_width = 647;
                              }
                              else {
                                $small_width = $small_data[0];
                              }
                              $small_src_set = ', ' . $small_amp_image . ' ' . $small_width . 'w';
                            }

                            $srcset = $amp_image . ' ' . $width . 'w' . $small_src_set;
                            ?>
              <figure>
                  <div class="fixed-height-container">
                      <amp-img src="<?php print image_style_url("photo_slider_753x543", $file->uri); ?>"
                               
                                layout="fill" srcset="<?php print $srcset; ?>"><div fallback>offline</div>
                      </amp-img>   
                  </div>
                  
                  <figcaption on="tap:AMP.setState({expanded: !expanded})"
                              tabindex="0"
                              role="button"
                              [class]="expanded ? 'expanded' : ''"><?php print $caption; ?>
                      <span [text]="expanded ? '&#9660;' : '&#9650;'">&#9650;</span>
                  </figcaption>
              </figure>
    <?php
  }
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
        $other_src_set = $small_image . ' ' . $small_width . 'w';
      }
      else {
        $small_image = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');
        $other_src_set = $small_image . ' ' . $small_width . 'w';
      }
      
      $alias = drupal_get_path_alias('node/'.$value['nid']);
      $path_alias = $base_url.'/amp/'.$alias;
      $dec_title = html_entity_decode($value['title']);
      $title = l($dec_title, $path_alias, array("attributes" => array("title" => $dec_title)));
      $amp_image = '<a href="' . $path_alias . '"><amp-img height="127" width="170" layout="responsive"  alt="' . $dec_title . '" title="' . $dec_title . '" src="' . $small_image . '" srcset="'.$other_src_set.'"><div fallback>offline</div></amp-img></a>';
      $other_gallery .= '<li><div class="other-img">' . $amp_image . '<div class="other-count"><i class="fa fa-camera" aria-hidden="true"></i> ' . $img_count . ' images</div></div><div class="other-date">' . date('D, d M, Y', $value['created']) . '</div><div class="other-title">' . $title . '</div></li>';
    }
    $other_gallery .= '</ul>';
    print $other_gallery;
  }
}
?>  
</div>
