<?php
// config for sharing
global $base_url;
$nid = check_plain(arg(1));
$video_node = node_load(arg(1));
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$fb_title = addslashes($video_node->title);
$share_desc = '';
$image = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
$videoids = "";
if (function_exists('get_video_in_fieldcollection_by_nid')) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
}
?>
<?php foreach ($rows as $row): ?>
    <div class="container">
        <div class ="video-landing-header">
            <div class="row">
                <div class="col-md-12">
                    <h2><?php print $row['title']; ?></h2>
                </div>
                <div class="col-md-8 video-header-left">
                    <div class="video">
    <?php
    if (!empty($videoids)) {
        $hide_player = "";
        $newimageds = '<div class="row"><div class="col-md-12"><div class="video-slider-images"><ul>';
        foreach ($videoids as $keys => $video_value) {
            if ($keys != 0) {
                $hide_player = 'hide-player';
            }
            ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->video_id; ?>"><?php
                                if (module_exists('itg_videogallery')) {
                                    $vid = itg_videogallery_get_videoid($row['fid']);
                                }
                                if ($video_value->dailymotion_thumb_url != "") {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $video_value->dailymotion_thumb_url . '" height="66" width="88"></li>';
                                }
                                else {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/default_for_all.png" height="66" width="88"></li>';
                                }
                                $ads_flag = 0;
                                if ($video_value->field_include_ads_value == 'yes') {
                                    $ads_flag = 1;
                                }
                                ?>
                                    <div class="iframe-video">
                                        <iframe frameborder="0"
                                                src="https://www.dailymotion.com/embed/video/<?php print $video_value->video_id; ?>?autoplay=0&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info"
                                                allowfullscreen></iframe></div>

                                </div>

            <?php
        }
        $newimageds.='</ul></div></div></div>';
    }
    ?>
                    </div>

                    <div class="social-likes mhide">
                        <ul>
                            <li><a href="#" title ="Like"><i class="fa fa-heart"></i> <span><?php
                    if (function_exists(itg_flag_get_count)) {
                        print $like_count = itg_flag_get_count(arg(1), 'like_count');
                    }
                    ?></span></a></li>
                            <li><?php print $row['ops']; ?></li>
                            <li><a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
                            <li><a class="def-cur-pointer" title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($video_node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Twitter</span></a></li>
                            <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i> <span>Email</span></a></li>
                            <li><a href="#" title="Embed"><i class="fa fa-link"></i> <span>Embed</span></a></li>
    <?php
    if (function_exists(global_comment_last_record)) {
        $last_record = global_comment_last_record();
        $config_name = trim($last_record[0]->config_name);
    }
    if ($config_name == 'vukkul') {
        ?>
                                <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                            <?php } if ($config_name == 'other') { ?> 
                                <li><a href="javascript:void(0)" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                            <?php } ?>
                            <?php if ($user->uid > 0): ?>
                                <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/personalization/my-content/<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                            <?php else: ?>
                                <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                            <?php endif; ?>
                <!--<li class="mhide"><a href="#" title="Submit Video"><i class="fa fa-share"></i> <span>Submit Video</span></a></li>-->
                        </ul>
                    </div>
                    <div class="clearfix"></div>
                            <?php
                            if (!empty($videoids) && count($videoids) > 1) {
                                print $newimageds;
                            }
                            ?>

                    <div class="social-likes desktop-hide">
                        <ul>
                            <li><a href="#" title ="Like"><i class="fa fa-heart"></i> <span><?php
                            if (function_exists(itg_flag_get_count)) {
                                print $like_count = itg_flag_get_count(arg(1), 'like_count');
                            }
                            ?></span></a></li>
                            <li><?php print $row['ops']; ?></li>
                            <li><a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
                            <li><a class="def-cur-pointer" title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($video_node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Twitter</span></a></li>
                            <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i> <span>Email</span></a></li>
                            <li><a href="#" title="Embed"><i class="fa fa-link"></i> <span>Embed</span></a></li>
    <?php
    if (function_exists(global_comment_last_record)) {
        $last_record = global_comment_last_record();
        $config_name = trim($last_record[0]->config_name);
    }
    if ($config_name == 'vukkul') {
        ?>
                                <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                            <?php } if ($config_name == 'other') { ?> 
                                <li><a href="javascript:void(0)" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
                            <?php } ?>
                            <?php if ($user->uid > 0): ?>
                                <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/personalization/my-content/<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                            <?php else: ?>
                                <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                            <?php endif; ?>
                <!--<li class="mhide"><a href="#" title="Submit Video"><i class="fa fa-share"></i> <span>Submit Video</span></a></li>-->
                        </ul>
                    </div>


                </div>
                <div class="col-md-4 video-header-right"><p><?php print $row['field_story_expert_description']; ?></p>
                    <p class="upload-date"><?php print $row['timestamp']; ?></p>
                    <div class="section-like-dislike">
                        <div id="btn-div">
    <?php
    if (function_exists(itg_event_backend_highlights_like_dislike)) {
        $val = arg(1);
        print itg_event_backend_highlights_like_dislike($val);
    }
    ?>
                        </div>

                    </div>
                    <div class="ads mhide"></div>
                </div>
            </div>
        </div>
    </div>
<?php endforeach; ?>

<script>
    jQuery(document).ready(function() {
        jQuery('.video-header-left .video').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: true,
            fade: false,
            asNavFor: '.video-header-left .video-slider-images ul'
        });
        jQuery('.video-header-left .video-slider-images ul').slick({
            slidesToShow: 7,
            slidesToScroll: 1,
            asNavFor: '.video-header-left .video',
            dots: false,
            centerMode: false,
            arrows: true,
            variableWidth: true,
            focusOnSelect: true,
            responsive: [
                {
                    breakpoint: 1024,
                    settings: {
                        slidesToShow: 7,
                        slidesToScroll: 1,
                        arrows: false
                    }
                },
                {
                    breakpoint: 600,
                    settings: {
                        slidesToShow: 4,
                        arrows: false,
                        slidesToScroll: 1
                    }
                },
                {
                    breakpoint: 480,
                    settings: {
                        slidesToShow: 3,
                        arrows: false,
                        slidesToScroll: 1
                    }
                }
            ]
        });
    });
</script>