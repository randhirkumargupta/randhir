<?php
$byline_title = '';
if(!empty($node->field_story_reporter)){
	$target_nid = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];	
	$byline_title = itg_common_get_node_title($target_nid);
	$byline_title = trim($byline_title);
}
?>
<div class="black-box">
  <div class="photo-title"><h1><?php print $node->title; ?></h1></div>
  <div class="byline_date">
      <?php if (!empty($byline_title)) { ?>
      <span class="video-byline"><?php print $byline_title; ?></span>
      <?php } ?>
      <span class="video-ppdate"><?php print date('F j, Y', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'])); ?></span>  
  </div>
   <?php
    $source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
    if($source_type != 'migrated') { ?>
    <div class="amp-photo-slider">
    <?php
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
      if(isset($node->field_story_expert_description[LANGUAGE_NONE])) {
        $description = $node->field_story_expert_description[LANGUAGE_NONE][0]['value'];
      }
      else {
        $description = $node->field_video_kicker[LANGUAGE_NONE][0]['value'];
      }
      if (function_exists('itg_custom_amp_body_filter')) {
        $description = itg_custom_amp_body_filter($description);
      }
      $description = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $description);

    foreach ($videoids as $keys => $video_value) {
        if (function_exists('get_amp_video_time')) {
        $video_time = get_amp_video_time($node->nid, 'videogallery', 'field_video_duration');
        } 
    ?>

            <div class="slide"> <div class="photo-slide">
            <?php if($video_value->video_repo_type != 'INTERNAL') { ?> 
              <amp-dailymotion data-videoid=<?php print $video_value->solr_video_id; ?>
                               layout="responsive"
                               data-ui-logo="false"
                               data-info="false"
                               width="300"
                               height="200">
              </amp-dailymotion>
            <?php }
            if($video_value->video_repo_type == 'INTERNAL') {
              if(function_exists('itg_videogallery_get_video_xml_data_by_fid')) {
               $data_video = itg_videogallery_get_video_xml_data_by_fid($video_value->fid);
              }
              $video_all_data = json_decode($data_video[0]->video_xml_data, TRUE);
              if(function_exists('itg_videogallery_make_parm_for_jwpalyer')) {
               $player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data, 'video', 0);
              }
              if(strpos($player_content['file_url'], 'https') === FALSE) {
                $video_urls = str_replace("http","https",$player_content['file_url']);
             } else {
                $video_urls = $player_content['file_url'];
             }
            ?>
              <amp-video width="300"
                       height="200"
                       src="<?php print $video_urls;?>"  
                       layout="responsive"
                       controls>
                       <source type="video/webm" src="<?php print $video_urls;?>">
              </amp-video>
            <?php
            }
            ?>
                    <div class="video-caption"><p><?php print $video_value->field_video_title_value;?></p></div>
                    <div class="video_dec_amp video_dec_<?php print $video_value->video_id; ?>" ><?php print ucfirst($description); ?></div>
                    
                </div>
            </div>        

    <?php
      }
    }
    ?>
</amp-carousel>
    </div>
   <?php }
    ?>
  <!-- code for migrated video -->
  <?php
            if ($node->field_story_source_type[LANGUAGE_NONE][0]['value'] == "migrated") { ?>
              <div class="amp-photo-slider">
              <?php    
              if (function_exists('get_video_in_fieldcollection_by_nid_mirtaed')) {
                $videoids = get_video_in_fieldcollection_by_nid_mirtaed($node->nid);
                $video_kicker = get_video_kicker_by_nid($node->nid);
              } 
              
                        
              if(isset($node->field_story_expert_description[LANGUAGE_NONE])) {
                $description = $node->field_story_expert_description[LANGUAGE_NONE][0]['value'];
                  } else {
                $description = $video_kicker[0]->field_video_kicker_value;
              }
              if (function_exists('itg_custom_amp_body_filter')) {
                $description = itg_custom_amp_body_filter($description);
              }
		      $description = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $description);
  ?>
        <amp-carousel width="300"
                  height="280"
                  layout="responsive"
                  type="slides">
              <?php foreach ($videoids as $keys => $video_value) {
                
                if(strpos($video_value->field_migrated_video_url_value, 'https') === FALSE) {
                 $video_id = str_replace("http","https",$video_value->field_migrated_video_url_value);
                 $video_id = str_replace("medias3d.intoday.in","indiatoday-pdelivery.akamaized.net", $video_id);
                } else {
                 $video_id = $video_value->field_migrated_video_url_value;
                 $video_id = str_replace("medias3d.intoday.in","indiatoday-pdelivery.akamaized.net", $video_id);
                }
                ?> 
              <div class="slide"> <div class="photo-slide">
                      <amp-video width="300"
                       height="200"
                       src="<?php print $video_id;?>"  
                       layout="responsive"
                       controls>
                       <source type="video/webm" src="<?php print $video_id;?>">
                      </amp-video>
                    <div class="video-caption"><p><?php print $video_value->field_video_title_value;?></p></div>
                    <div class="video_dec_amp video_dec_<?php print $video_value->video_id; ?>" ><?php print ucfirst($description); ?></div>
                    
                </div>
            </div>    
        
                <?php
              }
            
            ?>
        
        
    </amp-carousel>
  </div>
            <?php } ?>
  </div>
<?php if(!empty(variable_get('amp_taboola_ad_script'))) { ?>
  <div class="amp-taboola">
	<?php print variable_get('amp_taboola_ad_script'); ?>
  </div>
<?php } ?>
<?php if(!empty(variable_get('amp_video_second_ad'))) { ?>
<div class="custom-amp-ad ad-btf">
<?php print variable_get('amp_video_second_ad'); ?>     
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
    $other_video_gallery = '';
    $other_video_gallery .= '<h2><span>'.t('OTHER VIDEOS').'</span></h2>';
    $other_video_gallery .= '<ul>';
    foreach ($entity_arr as $key => $value) {
      // get video time
      if (function_exists('get_amp_video_time')) {
        $video_time = get_amp_video_time($value['entity_id'], 'videogallery', 'field_video_duration');
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
      $other_video_gallery .= '<li><div class="other-img">' . $amp_image . '<div class="other-count"><i class="fa fa-play-circle" aria-hidden="true"></i> ' . $video_time[0]['field_video_duration_value'] . '</div></div><div class="other-date">' . date('D, d M, Y', $value['created']) . '</div><div class="other-title">' . $title . '</div></li>';
    }
    $other_video_gallery .= '</ul>';
    print $other_video_gallery;
  }
}
?>  
</div>
