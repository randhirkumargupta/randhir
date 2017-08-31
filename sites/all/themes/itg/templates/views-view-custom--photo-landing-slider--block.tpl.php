<?php
global $base_url;
// configuration for social sharing
$photo_node = node_load(arg(1));
$tid = $photo_node->field_primary_category[LANGUAGE_NONE][0]['value'];
$term = taxonomy_term_load($tid);
$primary_category_name = itg_common_custompath_insert_val($term->name);
$f_collection = entity_load('field_collection_item', array($photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']));
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$share_title = addslashes($photo_node->title);
$share_desc = '';
$image = file_create_url($f_collection[$photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']]->field_images[LANGUAGE_NONE][0]['uri']);
$uri = base64_encode($actual_link);
$argum = base64_encode(arg(1));
?>
<div class="row">
    <div class="col-md-12">
        <h1 class="photo-heading" title="<?php print strip_tags($rows[0]['title']); ?>"><?php print $rows[0]['title']; ?></h1>    <?php
        global $user;
        if(in_array('Social Media', $user->roles)) {
            ?>
            <a class="def-cur-pointer colorbox-load promote-btn" title="promote" href="<?php print $base_url; ?>/itg-social-media-promote/<?php echo $photo_node->nid; ?>?width=850&height=850&iframe=true&type=<?php print $video_node->type; ?>"><span>promote</span></a>   
        <?php } ?>
        <div class="social-icon desktop-hide">
            <ul>
                <li><a title="share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $photo_node->nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on google+" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                <li><a title="share on twitter" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
                <?php
                if(function_exists(global_comment_last_record)) {
                    $last_record = $global_comment_last_record;
                    $config_name = trim($last_record[0]->config_name);
                }
                if($config_name == 'vukkul') {
                    ?>
                    <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                <?php } if($config_name == 'other') { ?> 
                    <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                <?php } ?>
                <li class="show-embed-code-link">
                    <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
                    <div class="show-embed-code-div">
                        <div class="copy-sample-code">
                            <textarea readonly><iframe src=<?php print $base_url . '/photo/' . $primary_category_name . '/embed/' . $argum; ?> allowfullscreen  width='648' height='480' frameborder='0' scrolling='no' /></textarea> 
                        </div>
                    </div>
                </li>
                <?php global $user; ?>
                <?php
                if($user->uid > 0) {
                    if(function_exists(itg_get_front_activity_info)) {
                        $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
                    }

                    if(empty($opt['status']) || $opt['status'] == 0) {
                        ?> 
                        <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
                        <?php
                    } else {
                        ?>
                        <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
                        <?php
                    }
                } else {
                    ?>
                    <li><a href="http://<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>
                    <?php
                }
                ?>
                <?php if($user->uid > 0): ?>
                    <li><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i></a></li>
                <?php else: ?>
                    <li><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                <?php endif; ?>
            </ul>
        </div>
    </div>
    <div class="col-md-8">
        <ul class="slickslide">

            <?php foreach($rows as $index => $row):
                ?>
                <li data-slide-number="<?php echo $index ?>">
                    <figure class="photo-landing-slider-pic" data-img-fid=" <?php print $row['fid']; ?>">


                        <?php print $row['field_images']; ?>                    
                    </figure>
                </li>
            <?php endforeach; ?>
        </ul>
        <div class="slick-thumbs">
            <ul class="slick-thumbs-slider">
                <?php foreach($rows as $index => $row): ?>
                    <li data-slide-number="<?php echo $index ?>">
                        <?php
                        if(!empty($row['field_photo_small_image'])) {
                            print $row['field_photo_small_image'];
                        } else {
                            print '<img  height="66" width="88" src="' . $base_url . "/" . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" alt="" />';
                        }
                        ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>
        <div class="photo-by-slider">
            <?php foreach($rows as $index => $row): ?>
                <?php if(!empty($row['field_photo_byline'])) { ?>
                    <p class="photo-by"><?php print t('PHOTO:'); ?> <?php print $row['field_photo_byline']; ?></p>
                    <?php
                } elseif(!empty($row['field_photo_by'])) {
                    ?>
                    <p class="photo-by"><?php print t('PHOTO:'); ?> <?php print $row['field_photo_by']; ?></p>
                <?php } ?>
            <?php endforeach; ?>
        </div>
    </div>
    <div class="col-md-4">
        <div class="other-details-main">
            <ul class="counterslide">
                <?php $like_id = 1000; ?>
                <?php foreach($rows as $index => $row): ?>
                    <li>
                        <div class="other-details">
                            <div class="counter">
                                <i class="fa fa-camera" aria-hidden="true"></i>
                                <?php print $row['counter']; ?>
                            </div>
                            <div class="caption"><?php print mb_strimwidth(html_entity_decode(strip_tags($row['field_image_caption'])), 0, 125, ".."); ?>

                                <div class="section-like-dislike">
                                    <!--<div id="btn-div">-->
                                    <div class="btn-div">
                                        <?php
                                        if(function_exists(itg_event_backend_highlights_like_dislike)) {
                                            //$val = $row['item_id'];
                                            $val = arg(1) . $like_id;
                                            if(function_exists('itg_common_get_node_type')) {
                                                $datatype = itg_common_get_node_type(arg(1));
                                            }
                                            print itg_event_backend_highlights_like_dislike($val, $datatype);
                                        }
                                        ?>
                                    </div>
                                </div>

                            </div>
                        </div>
                    </li>
                    <?php
                    $like_id++;
                endforeach;
                ?>
            </ul>

            <div class="social-icon mhide">
                <ul>
                    <li><a title="share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $photo_node->nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                    <li><a title="share on google+" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                    <li><a title="share on twitter" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                    <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
                    <?php
                    if(function_exists(global_comment_last_record)) {
                        $last_record = global_comment_last_record();
                        $config_name = trim($last_record[0]->config_name);
                    }
                    if($config_name == 'vukkul') {
                        ?>
                        <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                    <?php } if($config_name == 'other') { ?> 
                        <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                    <?php } ?>
                    <li class="show-embed-code-link">
                        <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
                        <div class="show-embed-code-div">
                            <div class="copy-sample-code">
                                <textarea readonly><iframe src="<?php print $base_url . '/photo/' . $primary_category_name . '/embed/' . $argum; ?>" allowfullscreen  width='648' height='480' frameborder='0' scrolling='no' /></textarea>
                            </div>
                        </div>
                    </li>
                    <?php if($user->uid > 0): ?>
                        <li class="mhide"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/personalization/my-content/<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                    <?php else: ?>
                        <li class="mhide"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                    <?php endif; ?>
                    <?php global $user; ?>
                    <?php
                    if($user->uid > 0) {
                        if(function_exists(itg_get_front_activity_info)) {
                            $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
                        }

                        if(empty($opt['status']) || $opt['status'] == 0) {
                            ?> 
                            <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
                            <?php
                        } else {
                            ?>
                            <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
                            <?php
                        }
                    } else {
                        ?>
                        <li><a href="http://<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>
                        <?php
                    }
                    ?>
                </ul>
            </div>


            <div class="photo-ad">
                <?php
                $block = block_load('itg_ads', ADS_RHS1);
                $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                print render($render_array);
                ?>
            </div>

        </div>
    </div>
</div>

<?php
    $explode = explode("?", $_SERVER['REQUEST_URI']);
    $initial_slide = 0;
    if(count($explode) > 1) {
        $initial_slide = end($explode);
    }
?>
<script>
    jQuery(document).ready(function (e) {
        jQuery('.slickslide').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: true,
            fade: false,
            asNavFor: '.slick-thumbs-slider, .counterslide, .photo-by-slider',
            // For active slide
            initialSlide: <?php echo $initial_slide; ?>, 
        });
        jQuery('.slick-thumbs-slider').slick({
            slidesToShow: 7,
            slidesToScroll: 1,
            asNavFor: '.slickslide, .counterslide, .photo-by-slider',
            dots: false,
            centerMode: false,
            arrows: true,
            variableWidth: true,
            focusOnSelect: true,
            responsive: [{
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

        jQuery('.counterslide').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: true,
            fade: true,
            asNavFor: '.slick-thumbs-slider, .slickslide, .photo-by-slider'
        });
        jQuery('.photo-by-slider').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: false,
            fade: true,
            asNavFor: '.slick-thumbs-slider, .slickslide, .counterslide'
        });

        jQuery(document).ready(function () {
            jQuery(".slick-arrow , li.slick-slide").on("click", function () {
                var active_slide = jQuery(".slick-active").attr("data-slick-index");
                var current_url = window.location.href.split('?')[0];
                if (active_slide > 0) {
                    window.history.pushState("", "", current_url + "?" + active_slide);
                } else {
                    // If frist slide then put pull without query string.
                    window.history.pushState("", "", current_url);
                }
            });
        });
    });
    // Handle Thumb for active set class
    jQuery(window).load(function() {
        var active_slide = jQuery(".slick-active").attr("data-slick-index");
        jQuery( '.slick-thumbs li' ).removeClass('slick-current');
        jQuery( '.slick-thumbs li' ).each( function(key , item) {
            if(key == active_slide) {
                jQuery( this).addClass("slick-current");
            }
        });
    });
</script>













