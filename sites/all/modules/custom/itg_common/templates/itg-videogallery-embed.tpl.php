<?php if(function_exists('itg_common_get_node_title') && !empty($_GET['gid'])) {
  $title = itg_common_get_node_title($_GET['gid']);
} ?>
<h1><?php print $title; ?></h1>
<?php
    if (!empty($videoids)) {
        $hide_player = "";
        $description_slider="";
        $newimageds = '<div class="row"><div class="col-md-12"><div class="video-slider-images"><ul>';
        $description_slider = '<div class="video-slider-description"><ul>';
        foreach ($videoids as $keys => $video_value) {
            if ($keys != 0) {
                $hide_player = 'hide-player';
            }
            ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->video_id; ?>"><?php

                                if (module_exists('itg_videogallery')) {
                                    $vid = itg_videogallery_get_videoid($row['fid']);
                                }
                                if ($video_value->dailymotion_thumb_url != "") {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $video_value->dailymotion_thumb_url . '" height="66" width="88" alt=""></li>';
                                }
                                else {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
                                }
                                $ads_flag = 0;
                                if ($video_value->field_include_ads_value == 'yes') {
                                    $ads_flag = 1;
                                }
                                ?>
                                    <div class="iframe-video">
                                        <iframe frameborder="0" scrolling="no"
                                                src="https://www.dailymotion.com/embed/video/<?php print $video_value->video_id; ?>?autoplay=0&ui-logo=1&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info"
                                                allowfullscreen></iframe></div>

                                </div>

            <?php
            $description_slider.= '<li><p id="video_dec_' . $video_value->video_id . '" >'.  ucfirst($video_value->field_videogallery_description_value).'</p></li>';
        }
        $description_slider.='</ul></div>';
        $newimageds.='</ul></div></div></div>';
    }
    ?>