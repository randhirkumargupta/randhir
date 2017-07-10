<div class="black-box">
  <div class="photo-title"><h1><?php print $node->title; ?></h1></div>
<div class="amp-photo-slider">

        <?php
    $source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
    if (function_exists('get_video_in_fieldcollection_by_nid')) {
      $videoids = get_video_in_fieldcollection_by_nid($node->nid);
    }
    $video_id = array();
    ?>
    <amp-carousel width="300"
                  height="280"
                  layout="responsive"
                  type="slides">
    <?php
    if (!empty($videoids)) {
      foreach ($videoids as $keys => $video_value) {
        if (function_exists('get_amp_video_time')) {
        $video_time = get_amp_video_time($node->nid, 'videogallery', 'field_video_duration');
        } 
    ?>

            <div class="slide"> <div class="photo-slide"><amp-dailymotion data-videoid=<?php print $video_value->solr_video_id; ?>
                             layout="responsive"
                             data-ui-logo="false"
                             data-info="false"
                             width="300"
                             height="200">
            </amp-dailymotion>
                    <div class="video-caption"><span><?php print date('F d, Y, H:i A', $node->created);?></span><p><?php print $video_value->field_video_title_value;?></p></div>
                </div>
            </div>        

    <?php
      }
    }
    ?>

    </amp-carousel>
    </div>
  </div>
  <div class="amp-photo-ad">
      <amp-ad type="a9"
      width="300"
      height="250"
      data-aax_size="300x250"
      data-aax_pubname="test123"
    data-aax_src="302">
    </amp-ad>
  </div>

<div class="amp-other-gallery">
  <?php
// get all node id related to current node primary category
if (function_exists('get_other_gallery_amp')) {
  $primary_category = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
  $entity_arr = get_other_gallery_amp($primary_category, $node->nid, $node->type, 4);
  if (!empty($entity_arr)) {
    $other_video_gallery = '';
    $other_video_gallery .= '<h2><span>OTHER VIDEO</span></h2>';
    $other_video_gallery .= '<ul>';
    foreach ($entity_arr as $key => $value) {
      // get video time
      if (function_exists('get_amp_video_time')) {
        $video_time = get_amp_video_time($value['entity_id'], 'videogallery', 'field_video_duration');
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
      $other_video_gallery .= '<li><div class="other-img">' . $amp_image . '<div class="other-count"><i class="fa fa-play" aria-hidden="true"></i> ' . $video_time[0]['field_video_duration_value'] . '</div></div><div class="other-date">' . date('D, d M, Y', $value['created']) . '</div><div class="other-title">' . $title . '</div></li>';
    }
    $other_video_gallery .= '</ul>';
    print $other_video_gallery;
  }
}
?>  
</div>