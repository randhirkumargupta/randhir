<div class="amp-video-black-box">
  <div class="video-title"><h1><?php print $node->title; ?></h1></div>

</div>
<?php
$source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
if (function_exists('get_video_in_fieldcollection_by_nid')) {
  $videoids = get_video_in_fieldcollection_by_nid($node->nid);
}
$video_id = array();
?>
<amp-carousel width="300"
              height="300"
              layout="responsive"
              type="slides">
                <?php
                if (!empty($videoids)) {
                  foreach ($videoids as $keys => $video_value) {
                    ?>

      <amp-dailymotion data-videoid=<?php print $video_value->solr_video_id; ?>
                       layout="responsive"
                       data-ui-logo="false"
                       data-info="false"
                       width="300"
                       height="300"></amp-dailymotion>

      <?php
    }
  }
  ?>

</amp-carousel>
<div class="amp-photo-ad">
  <amp-ad type="a9"
  width="300"
  height="250"
  data-aax_size="300x250"
  data-aax_pubname="test123"
data-aax_src="302">
  </amp-ad></div>
<div class="amp-other-video-gallery">
  <?php
// get all node id related to current node primary category
  if (function_exists('get_other_gallery_amp')) {
    $primary_category = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
    //$entity_arr = get_other_gallery_amp($primary_category, $node->nid, $node->type, 4);
    $other_video_gallery = '';
    $other_video_gallery .= '<h2><span>OTHER VIDEO</span></h2>';
    $other_video_gallery .= '<ul>';
// foreach($entity_arr as $key => $value) {
//   // get image count
//  if(function_exists('.')) { 
//  $img_count = get_image_count_entity_id($value['entity_id'], 'photogallery', 'field_gallery_image');
//  }
//  $entity_id = $value['entity_id'];
//  $title = l($value['title'], $base_url.'/node/'.$value['nid'], array("attributes" => array("title" => $value['title'])));
//  if(!empty($value['field_story_small_image_fid'])) {
//  $file = file_load($value['field_story_small_image_fid']);
//  $small_image = file_create_url($file->uri);
//  } else {
//  $small_image = $base_url .'/'. path_to_theme().'/images/itg_image170x127.jpg';
//  }
//  $amp_image = '<amp-img height="127" width="170" layout="responsive"  alt="'.$value['title'].'" title="'.$value['title'].'" src="' . $small_image . '"></amp-img>';
//  $other_galley .= '<li><div class="other-img">'.$amp_image.'<div class="other-count"><i class="fa fa-camera" aria-hidden="true"></i> '.$img_count.' images</div></div><div class="other-date">'.date('D, d M, Y', $value['created']).'</div><div class="other-title">'.$title.'</div></li>';
// }
    $other_video_gallery .= '</ul>';
    print $other_video_gallery;
  }
  ?>  
</div>