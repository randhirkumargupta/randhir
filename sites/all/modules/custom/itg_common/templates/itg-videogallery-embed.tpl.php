<?php
$arg = arg(3);
if (function_exists('itg_common_get_node_title') && !empty($arg)) {
  $nid = base64_decode($arg);
  global $base_url;
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];

  $videocopy_url = $base_url . '/embed-video/' . $arg;
  $title = itg_common_get_node_title($nid);
  $videoids = $data;
  $video_node = node_load($nid);
  $path_aleas = $base_url . '/' . drupal_get_path_alias('node/' . $nid);
}
?>
<style>
	#main { min-height: initial;}
  .container{max-width:100%!important; padding: 0px;}
  .itg-embed-wrapper{padding:0px!important;background-color:#fff!important;}
</style>
<div class="itg-embed-wrapper">
<!--    <h1 class="embed-title"><?php // print $title;  ?></h1>-->
    <?php
    if (!empty($videoids) && $video_node->field_story_source_type[LANGUAGE_NONE][0]['value'] != "migrated") {
      $hide_player = "";
      $newimageds = '<div class="itg-embed-photo-wrapper"><div class="itg-embed-photo-thumb"><ul class="itg-embed-photo-thumb-slider">';
      ?><div class="itg-embed-photo">
          <ul class="itg-embed-photo-slider">
              <?php
              foreach ($videoids as $keys => $video_value) {
                if ($keys != 0) {
                  $hide_player = 'hide-player';
                }
                if ($video_value->video_embedded_url != "") {
                  $vide_dm_id = $video_value->video_embedded_url;
                }
                else {
                  $vide_dm_id = $video_value->solr_video_id;
                }
                ?> <?php
                if (module_exists('itg_videogallery')) {
                  $vid = itg_videogallery_get_videoid($row['fid']);
                }
                if ($video_value->solr_video_thumb != "") {
                  $newimageds.= '<li><img class="thumb-video image_index_' . $keys . '" data-used-on ="embed" data-image-fid="' . $video_value->fid . '"  data-image-index="' . $keys . '" data-tag="video_' . $video_value->solr_video_id . '" src="' . $video_value->solr_video_thumb . '" height="66" width="88" alt="" title=""></li>';
                }
                else {
                  $newimageds.= '<li><img class="thumb-video image_index_' . $keys . '" data-used-on ="embed" data-image-fid="' . $video_value->fid . '" data-tag="video_' . $video_value->solr_video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt="" title=""></li>';
                }
                $ads_flag = 1;
                if ($video_value->field_include_ads_value == 'yes') {
                  $ads_flag = 0;
                }
                $image_url = $base_url . "/" . drupal_get_path('theme', 'itg') . '/images/itg_image370x208.jpg';
                if ($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'] != "") {
                  $image_url = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
                }
                ?>
                <?php if ($keys == 0) { ?>
                  <div class="<?php echo $hide_player; ?>" id="video_palyer_container"> <div class = "video-iframe-wrapper">
                          <div style="display:none" class="loading-video">Load.....</div>
                          <div class="video-iframe-wrapper" id="video_0">
                              <?php
                              if ($videoids[0]->video_repo_type == 'INTERNAL') {
                                print theme('internal_video_player', array("data" => $videoids[0]->fid, 'used_on' => 'embed', 'image' => $image_url, 'nid' => $nid));
                              }
                              ?>
                          </div>
                          <?php if ($videoids[0]->video_repo_type != 'INTERNAL') { ?>
                            <script src="https://api.dmcdn.net/all.js"></script>
                            <script>

                              jQuery(window).load(function () {
                                  jQuery('.video-slider-images').removeClass('pointer-event-none');
                              });
                              var player_0 = DM.player(
                                      document.querySelector('#video_0'),
                                      {
                                          video: '<?php print $vide_dm_id; ?>',
                                          width: '100%',
                                          height: '280px',
                                          params: {
                                              autoplay: 1,
                                              controls: 1,
                                              'sharing-enable': 0,
                                              'ui-start-screen-info': 0,
                                              'endscreen-enable':<?php echo $ads_flag; ?>,
                                              'ui-logo': 0,
                                          }
                                      }
                              );
                              player_0.addEventListener('video_end', function (event) {
                                  jQuery('.image_index_<?php print $keys + 1; ?>').trigger('click');
                              });
                            </script>
                          <?php } ?>
                      </div>
                  </div>
                <?php }
                ?>
              <?php } ?>
          </ul>
      </div>
      <?php
      $newimageds .= '</ul></div>  </div>';
    }
    ?>
    <?php
    if (!empty($videoids) && count($videoids) > 1) {
      print $newimageds;
    }
    ?>
    <?php
    if ($video_node->field_story_source_type[LANGUAGE_NONE][0]['value'] == "migrated") {

      if (function_exists('get_video_in_fieldcollection_by_nid_mirtaed')) {
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        $video_kicker = get_video_kicker_by_nid($nid);
      }

      $hide_player = "";
      $description_slider = "";
      $newimageds = '<div class="row"><div class="col-md-12"><div class="video-slider-images "><ul >';
      $description_slider = '<div class="video-slider-description"><ul>';
      foreach ($videoids as $keys => $video_value) {
        ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->video_id; ?>"><?php
        if (module_exists('itg_videogallery')) {
          $vid = itg_videogallery_get_videoid($row['fid']);
        }
        $image_url = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);

        if ($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'] != "") {
          $ga_data = "ga('send', 'event', 'Video_" . $nid . "Thumb', 'click','1', 1, {'nonInteraction': 1});return true;";
          $newimageds.= '<li><img class="migrate-thumb-video" data-image ="' . $image_url . '" data-used-on ="embed" data-nid = "' . $nid . '" data-video-url="' . $video_value->field_migrated_video_url_value . '" src="' . $image_url . '" height="66" width="88" alt="" title="" onclick="' . $ga_data . '"></li>';
        }
        else {
          $ga_data = "ga('send', 'event', 'Video_" . $nid . "Thumb', 'click','1', 1, {'nonInteraction': 1});return true;";
          $image_url = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image647x363.jpg');
          $newimageds.= '<li><img class="migrate-thumb-video" data-nid = "' . $nid . '" data-used-on ="embed" data-image ="' . $image_url . '" data-video-url="' . $video_value->field_migrated_video_url_value . '" src="' . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg') . '" height="66" width="88" alt="" title="" onclick="' . $ga_data . '"></li>';
        }
        ?>

            <?php if ($keys == 0) { ?>
              <div class="">
                  <div style="display:none" class="loading-video"><div class="spinner">
                          <div class="bounce1"></div>
                          <div class="bounce2"></div>
                          <div class="bounce3"></div>
                      </div></div>
                  <div  id="migrate_video_palyer_container">
                      <?php print theme('migrated_video_player', array("url" => $video_value->field_migrated_video_url_value, 'nid' => $nid, 'image' => $image_url, 'used_on' => 'embed', 'title' => $fb_title)); ?>
                  </div> 
              </div>
            <?php } ?>
        </div>

        <?php
        $description_slider.= '<li><p id="video_dec_' . $video_value->video_id . '" >' . ucfirst($video_kicker[0]->field_video_kicker_value) . '</p></li>';
      }
      $description_slider.='</ul></div>';
      $newimageds.='</ul></div></div></div>';
    }
    ?>

</div>
