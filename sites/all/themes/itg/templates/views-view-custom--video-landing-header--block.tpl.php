<?php
// config for sharing
global $base_url;
$nid = check_plain(arg(1));
$video_node = node_load(arg(1));
//pr($video_node);
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$fb_title = addslashes($video_node->title);
$share_desc = '';
$image = file_create_url($video_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
$videoids = "";
if (function_exists('get_video_in_fieldcollection_by_nid')) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
}
$useragent = $_SERVER['HTTP_USER_AGENT'];
 if (preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i', $useragent) || preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i', substr($useragent, 0, 4)))
                {
                  $ads_url = 'https://pubads.g.doubleclick.net/gampad/ads?sz=640x480|400x300&iu=/1007232/m.intoday.in_pre_roll&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&url=[referrer_url]&description_url=[description_url]&correlator=[timestamp]';
                }
                else
                {
                  $ads_url = 'https://pubads.g.doubleclick.net/gampad/ads?sz=400x300|640x480&iu=/1007232/Indiatoday_VOD_Pre_Roll_WEB&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&url=[referrer_url]&description_url=[description_url]&correlator=[timestamp]';
                }
                
                
?>
<?php foreach ($rows as $row): ?>
    <div class="container">
        <div class="ad-blocker"></div>
        <div class ="video-landing-header">
            <div class="row">
                <div class="col-md-12">
                    <h1 class="video-heading"><?php print $row['title']; ?></h1><?php
                    global $user;
                    if (in_array('Social Media', $user->roles)) {
                        ?>
                        <a class="def-cur-pointer colorbox-load promote-btn" title="promote" href="<?php print $base_url; ?>/itg-social-media-promote/<?php echo $video_node->nid; ?>?width=850&height=850&iframe=true&type=<?php print $video_node->type; ?>"><span>promote</span></a>   
                    <?php } ?>

                </div>
                <div class="col-md-8 video-header-left">
                    <div class="video">

                        <?php
                        if (!empty($videoids) && $video_node->field_story_source_type[LANGUAGE_NONE][0]['value'] != "migrated") {
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
                                ?> <div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->solr_video_id; ?>"><?php
                                if (module_exists('itg_videogallery')) {
                                    $vid = itg_videogallery_get_videoid($row['fid']);
                                }
                                if ($video_value->solr_video_thumb != "") {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->solr_video_id . '" src="' . $video_value->solr_video_thumb . '" height="66" width="88" alt=""></li>';
                                }
                                else {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->solr_video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
                                }
                                $ads_flag = 1;
                                if ($video_value->field_include_ads_value == 'yes') {
                                    $ads_flag = 0;
                                }
                                if($video_value->video_embedded_url !="") {
                                   $vide_dm_id = $video_value->video_embedded_url;
                                }else {
                                   $vide_dm_id = $video_value->solr_video_id;
                                }
                               
                                ?>
                                    <div class="iframe-video">
                                        <iframe frameborder="0" scrolling="no"
                                                src="https://www.dailymotion.com/embed/video/<?php print $vide_dm_id; ?>?autoplay=<?php echo $autoplay; ?>&player_next_video=x5d9tu3&ui-logo=1&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info"
                                                allowfullscreen></iframe></div>

                                </div>

                                <?php
                                $description_slider.= '<li><p id="video_dec_' . $video_value->video_id . '" >' . ucfirst($video_value->field_videogallery_description_value) . '</p></li>';
                            }
                            $description_slider.='</ul></div>';
                            $newimageds.='</ul></div></div></div>';
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
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $image_url . '" height="66" width="88" alt=""></li>';
                                }
                                else {
                                    $newimageds.= '<li><img data-tag="video_' . $video_value->video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
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
                                    <div class="iframe-video">

                                        <div style="margin:0 auto; width:622px;"><div align="center" id="videoplayer_<?php echo $keys; ?>"></div></div> 
                                        <script type="text/javascript">

                                            jwplayer('videoplayer_<?php echo $keys; ?>').setup({
                                                playlist: [{
                                                        title: "<?php print $row['title']; ?>",
                                                        image: "<?php echo $image_url; ?>",
                                                        sources: [
                                                            {
                                                                file: "<?php echo $getvideo_bitrate_url; ?>"
                                                            }, {
                                                                file: "<?php print $video_value->field_migrated_video_url_value; ?>"
                                                            }]
                                                    }],
                                                primary: "flash",
                                                width: "622",
                                                height: "446",
                                                aspectratio: "4:3",
                                                "stretching": "exactfit",
                                                androidhls: "true",
                                                fallback: "false",
                                                hlslabels: {"156": "lowest", "364": "low", "512": "medium", "864": "high", "996": "Highest"},
                                                advertising: {
                                                    client: "vast",
                                                    skipoffset: 5,
                                                    schedule: {"myAds": {"offset": "pre", "tag": "<?php print $ads_url;?>"}}

                                                },
                                                ga: {
                                                    idstring: "<?php print $row['title']; ?>",
                                                }
                                            });
                                        </script></div>

                                </div>

                                <?php
                                $description_slider.= '<li><p id="video_dec_' . $video_value->video_id . '" >' . ucfirst($video_value->field_videogallery_description_value) . '</p></li>';
                            }
                            $description_slider.='</ul></div>';
                            $newimageds.='</ul></div></div></div>';
                        }
                        ?>

                    </div>

                    <div class="social-likes mhide">
                        <ul>
                            <li><a href="#" title ="Like"><i class="fa fa-heart"></i> <span id="vno-of-likes_<?php print arg(1);?>"><?php
                                            if (function_exists(itg_flag_get_count)) {
                                                $like_count = itg_flag_get_count(arg(1), 'like_count');
                                            }
                                            // get migrated count 
                                            if(function_exists('itg_get_migrated_like_count')) {
                                                $migrated_count = itg_get_migrated_like_count(arg(1));
                                            }
                                            print $like_count['like_count'] + $migrated_count[0]['like_count'];
                                        ?></span></a></li>
                            <?php
                            if ($user->uid > 0) {
                                if (function_exists(itg_get_front_activity_info)) {
                                    $opt = itg_get_front_activity_info($video_node->nid, $video_node->type, $user->uid, 'read_later', $status = '');
                                }

                                if (empty($opt['status']) || $opt['status'] == 0) {
                                    ?> 
                                    <li class="later"><a title = "Save" href="javascript:void(0)" class="user-activity" rel="<?php print $video_node->nid; ?>" data-tag="<?php print $video_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-clock-o"></i><span><?php print t('Watch Later'); ?></span></a></li>
                                    <?php
                                }
                                else {
                                    ?>
                                    <li><a title = "Save" href="javascript:" class="def-cur-pointer active"><i class="fa fa-clock-o"></i><span><?php print t('Watch Later'); ?></span></a></li>
                                    <?php
                                }
                            }
                            else {
                                if (function_exists(itg_sso_url)) {
                                    print '<li>' . itg_sso_url('<i class="fa fa-clock-o"></i> <span>' . t('Watch Later') . '</span>', t('Save')) . '</li>';
                                }
                            }
                            ?>
                            <li><a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i> <span><?php print t('Share'); ?></span></a></li>
                            <li><a class="user-activity def-cur-pointer" rel="<?php print $video_node->nid; ?>" data-tag="<?php print $video_node->type; ?>" data-activity="twitter_share" data-status="1" title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($video_node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span><?php print t('Twitter'); ?></span></a></li>
                            <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i> <span><?php print t('Email'); ?></span></a></li>
                            <li class="show-embed-code-link"><a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i> <span><?php print t('Embed'); ?></span></a>
                                <div class="show-embed-code-div">
                                    <div class="copy-sample-code">
                                    <textarea readonly="true"><div id='IndiaToday_gallery' data-type='UAT'></div><script src='<?php print $base_url; ?>/sites/all/themes/itg/js/video_iframeResizer.js'></script><script><?php echo "iFrameResize({galleryid: $video_node->nid})"; ?></script></textarea>    
                                    </div>
                                </div>
                            </li>
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
                                <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
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
                </div>
                <?php //$row['field_story_expert_description'];  ?>
                <div class="col-md-4 video-header-right">
                    <div class="top-section">
                        <div class="social-likes desktop-hide">
                            <ul>
                                <li><a href="#" title ="Like"><i class="fa fa-heart"></i> <span id="vno-of-likes_<?php print arg(1);?>"><?php
                                            if (function_exists(itg_flag_get_count)) {
                                                $like_count = itg_flag_get_count(arg(1), 'like_count');
                                            }
                                            // get migrated count 
                                            if(function_exists('itg_get_migrated_like_count')) {
                                                $migrated_count = itg_get_migrated_like_count(arg(1));
                                            }
                                                print $like_count['like_count'] + $migrated_count[0]['like_count'];
                                            
                                            ?></span></a></li>
                                <li><?php print $row['ops']; ?></li>
                                <li><a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
                                <li><a class="user-activity def-cur-pointer" rel="<?php print $video_node->nid; ?>" data-tag="<?php print $video_node->type; ?>" data-activity="twitter_share" data-status="1" title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($video_node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i> <span>Twitter</span></a></li>
                                <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i> <span>Email</span></a></li>
                                <li class="show-embed-code-link"><a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i> <span><?php print t('Embed'); ?></span></a>
                                    <div class="show-embed-code-div">
                                        <div class="copy-sample-code">
                                        <textarea readonly="true"><div id='IndiaToday_gallery' data-type='UAT'></div><script src='<?php print $base_url; ?>/sites/all/themes/itg/js/video_iframeResizer.js'></script><script><?php echo "iFrameResize({galleryid: $video_node->nid})"; ?></script></textarea>    
                                        </div>
                                    </div>
                                </li>
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
                                    <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                                <?php else: ?>
                                    <li><a class="def-cur-pointer colorbox-load" title="Submit Video" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $video_node->type; ?>"><i class="fa fa-share"></i><span>Submit Video</span></a></li>
                                <?php endif; ?>
    <!--<li class="mhide"><a href="#" title="Submit Video"><i class="fa fa-share"></i> <span>Submit Video</span></a></li>-->
                            </ul>
                        </div>
                        <?php print $description_slider; ?>
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
                    </div>

                    <div class="ads">
                        <?php
                        $block = block_load('itg_ads', ADS_RHS1);
                        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                        print render($render_array);
                        ?>
                    </div>
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
            arrows: false,
            fade: false,
            asNavFor: '.video-header-left .video-slider-images ul, .video-slider-description ul'
        });
        jQuery('.video-slider-description ul').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: false,
            fade: true,
            asNavFor: '.video-header-left .video-slider-images ul, .video-header-left .video'
        });
        jQuery('.video-header-left .video-slider-images ul').slick({
            slidesToShow: 7,
            slidesToScroll: 1,
            asNavFor: '.video-header-left .video, .video-slider-description ul',
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