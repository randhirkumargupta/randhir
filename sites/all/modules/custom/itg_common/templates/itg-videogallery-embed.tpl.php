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
<div class="itg-embed-wrapper">
  <h1 class="embed-title"><?php print $title; ?></h1>
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
              $newimageds .= '<li><img data-tag="video_' . $vide_dm_id . '" src="' . $video_value->solr_video_thumb . '" height="66" width="88" alt=""></li>';
            }
            else {
              $newimageds .= '<li><img data-tag="video_' . $vide_dm_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
            }
            $ads_flag = 1;
            if ($video_value->field_include_ads_value == 'yes') {
              $ads_flag = 0;
            }
            ?>
            <li>
              <div class="<?php echo $hide_player; ?>" id="video_<?php echo $vide_dm_id; ?>">
                <div class="iframe-video">
                  <iframe frameborder="0" scrolling="no" src="https://www.dailymotion.com/embed/video/<?php print $vide_dm_id; ?>?autoplay=0&ui-logo=1&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info" allowfullscreen></iframe>
                </div>
              </div>  
              <div class="embed-desc"><?php print ucfirst($video_value->field_videogallery_description_value); ?></div>
            </li>
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
      }
      drupal_add_js('http://content.jwplatform.com/libraries/V30NJ3Gt.js', 'external');
      $hide_player = "";
      $description_slider = "";
      $newimageds = '<div class="row"><div class="col-md-12"><div class="video-slider-images"><ul>';
      $description_slider = '<div class="video-slider-description"><ul>';
      foreach ($videoids as $keys => $video_value) {
        if ($keys != 0) {
          $hide_player = 'hide-player';
          $autoplay = 0;
        }
        else {
          $autoplay = 1;
        }
        ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->video_id; ?>"><?php
        if (module_exists('itg_videogallery')) {
          $vid = itg_videogallery_get_videoid($row['fid']);
        }
        $image_url = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
        if ($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'] != "") {
          $newimageds .= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $image_url . '" height="66" width="88" alt=""></li>';
        }
        else {
          $newimageds .= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
        }
        $ads_flag = 0;
        if ($video_value->field_include_ads_value == 'yes') {
          $ads_flag = 1;
        }
        $allbitrates = array();
        foreach ($video_node->field_multi_bitrate[LANGUAGE_NONE] as $bitratevalue) {
          $allbitrates[] = end(explode('@', $bitratevalue['value']));
        }
        $usebitrates = implode(',', $allbitrates);
        $getvideo_bitrate_url = itg_videogallery_make_bitrate_url($video_value->field_migrated_video_url_value, $usebitrates);
        ?>
          <div class="iframe-video-embed">
            <div id="videoplayer_<?php echo $keys; ?>"></div> 
            <script type="text/javascript">
              jwplayer('videoplayer_<?php echo $keys; ?>').setup({
                playlist: [{
                    title: "<?php print $row['title']; ?>",
                    image: "<?php echo $image_url; ?>",
                    sources: [
//                      {
    //                        file: "<?php echo $getvideo_bitrate_url; ?>"
    //                      },
                      {
                        file: "<?php print $video_value->field_migrated_video_url_value; ?>"
                      }]
                  }],
                primary: "flash",
                width: "100%",
                aspectratio: "16:9",
                "stretching": "exactfit",
                androidhls: "true",
                fallback: "false",
                hlslabels: {"156": "lowest", "364": "low", "512": "medium", "864": "high", "996": "Highest"},
                sharing: {
                  code: encodeURI("<iframe src='<?php echo $videocopy_url; ?>' width='648' height='396' frameborder='0' scrolling='no' />"),
                  link: "<?php echo $path_aleas; ?>",
                  heading: "Share video"
                },
                advertising: {
                  client: "vast",
                  skipoffset: 5,
                  schedule: {"myAds": {"offset": "pre", "tag": "<?php print $ads_url; ?>"}}

                },
                ga: {
                  idstring: "<?php print $row['title']; ?>",
                }
              });
            </script>
          </div>
        </div>
        <?php
        $description_slider .= '<li><p id="video_dec_' . $video_value->video_id . '" >' . ucfirst($video_value->field_videogallery_description_value) . '</p></li>';
      }
      $description_slider .= '</ul></div>';
      $newimageds .= '</ul></div></div></div>';
    }
    ?>

</div>
