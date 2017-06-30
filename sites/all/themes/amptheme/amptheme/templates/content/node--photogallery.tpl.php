<div class="black-box">
  <div class="photo-title"><h1><?php print $node->title; ?></h1></div>
  <div class="amp-photo-slider">
  <?php
  global $base_url;
   if (!empty($node->field_gallery_image[LANGUAGE_NONE])) {
      $html = '';
      $html .='<amp-carousel id="carousel-with-preview"
      width="753"
      height="600"
      layout="responsive"
      type="slides">';
      $i= 1;
    foreach ($node->field_gallery_image['und'] as $photo_item) {
     //$buzz_output.= '<div class="buzz-section">';
      $field_collection_id = $photo_item['value'];
      $entity = entity_load('field_collection_item', array($field_collection_id));
      $file = file_load($entity[$field_collection_id]->field_images['und'][0]['fid']);
      $caption = $entity[$field_collection_id]->field_image_caption['und'][0]['value'];
      $amp_image = file_create_url($file->uri);
      //print '<amp-img height="363" width="647" layout="responsive"  alt="" title="" src="' . $amp_image . '"></amp-img>';
      $html .='<div class="slide"><div class="photo-slide"><amp-img layout="responsive" src="'.image_style_url("photgallery_landing_slider_753x543", $file->uri).'"
        width="753"
        height="543"></amp-img><div class="caption"><i class="fa fa-camera" aria-hidden="true"></i> '.$i.' of '.count($node->field_gallery_image['und']).'</div></div>
        <amp-fit-text><p>'.$caption.'</p></amp-fit-text></div>';
        $i++;
    }
    $html .= '</amp-carousel>';
    print $html;
  }
  ?>
  </div>
</div>
<div class="amp-photo-ad"><amp-ad type="a9"
    width="300"
    height="250"
    data-aax_size="300x250"
    data-aax_pubname="test123"
    data-aax_src="302">
  </amp-ad></div>
<div class="amp-other-gallery">
<?php
// get all node id related to current node primary category
if (function_exists('get_other_gallery_amp')) {
  global $base_url;
  $primary_category = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
  $entity_arr = get_other_gallery_amp($primary_category, $node->nid, $node->type, 4);
  if (!empty($entity_arr)) {
    $other_gallery = '';
    $other_gallery .= '<h2><span>OTHER GALLERY</span></h2>';
    $other_gallery .= '<ul>';
    foreach ($entity_arr as $key => $value) {
      // get image count
      if (function_exists('get_image_count_entity_id')) {
        $img_count = get_image_count_entity_id($value['entity_id'], 'photogallery', 'field_gallery_image');
      }
      $entity_id = $value['entity_id'];
      $title = l($value['title'], $base_url . '/node/' . $value['nid'].'?amp', array("attributes" => array("title" => $value['title'])));
      if (!empty($value['field_story_small_image_fid'])) {
        $file = file_load($value['field_story_small_image_fid']);
        $small_image = file_create_url($file->uri);
      }
      else {
        $small_image = $base_url . '/' . path_to_theme() . '/images/itg_image170x127.jpg';
      }

      $path_alias = $baseUrl . '/node/' . $value['nid'];

      $amp_image = '<a href="' . $path_alias . '?amp"><amp-img height="127" width="170" layout="responsive"  alt="' . $value['title'] . '" title="' . $value['title'] . '" src="' . $small_image . '"></amp-img></a>';
      $other_gallery .= '<li><div class="other-img">' . $amp_image . '<div class="other-count"><i class="fa fa-camera" aria-hidden="true"></i> ' . $img_count . ' images</div></div><div class="other-date">' . date('D, d M, Y', $value['created']) . '</div><div class="other-title">' . $title . '</div></li>';
    }
    $other_gallery .= '</ul>';
    print $other_gallery;
  }
}
?>  
</div>