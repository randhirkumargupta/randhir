<?php
global $base_url;
if ($widget_style == 'auto-road-trip') {
    ?>
    <div class="auto-road-trip">
        <ul class="trending-videos">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }

                $desc = $entity->title;
                ?>
                <li class="trending-videos-list">
                    <?php
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

                    <?php if (!empty($extra_large_image_url)) { ?>
                        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <div class="pic  <?php echo $video_class; ?>">  <img  src="<?php print $extra_large_image_url ?>" /></div>
                        </a>
                    <?php }
                    ?>

                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 55, ".."); ?></span></a>
                </li>
            <?php } ?>
        </ul>
    </div>
<?php }
else if ($widget_style == 'auto-tips-and-tricks' || $widget_style == 'edu-tips-and-trick') {
    ?>
    <div class="auto-tips-n-tricks">
        <ul>
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                if (!empty($entity->field_story_kicker_text)) {
                    $desc = $entity->field_story_kicker_text['und'][0]['value'];
                }
                else if (empty($entity->field_story_kicker_text) && $entity->body['und'][0]['value'] != "") {
                    $desc = $entity->body['und'][0]['value'];
                }
                ?><li>
                    <p class="title"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo ucfirst($entity->title); ?></a></p>

                    <p><?php echo mb_strimwidth(strip_tags($desc), 0, 150, ".."); ?></p>
                </li>


            <?php }; ?>
        </ul>
    </div>


<?php }
else if ($widget_style == 'buying-guid') {
    ?>
    <div class="row buying-guides">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {

                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;

                if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                }


                if ($count == 0) {
                    ?>

                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>">  </a>

                    <h3><?php echo l(mb_strimwidth(ucfirst($desc), 0, 75, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                }
                else if ($count == 1) {
                    $title = $entity->title;
                    if ($entity->field_story_short_headline['und'][0]['value'] != "") {
                        $title = strip_tags($entity->field_story_short_headline['und'][0]['value']);
                    }
                    ?>
                    <ul>
                        <li>
                            <span class="title"><?php echo l(mb_strimwidth(ucfirst($title), 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></span>
                            <p><?php echo l(mb_strimwidth(ucfirst($desc), 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>            
                    </ul>
                    <?php
                }
            }
            ?>

        </div>

        <div class="col-md-6">

            <ul>

                <?php
                foreach ($data as $count => $entity) {
                    $desc = $entity->title;
                    $title = $entity->title;
                    if ($entity->field_story_short_headline['und'][0]['value'] != "") {
                        $title = strip_tags($entity->field_story_short_headline['und'][0]['value']);
                    }

                    if ($count > 1) {
                        ?>

                        <li>
                            <span class="title"><?php echo l(mb_strimwidth(ucfirst($title), 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></span>
                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
                        <?php
                    }
                }
                ?>


            </ul>

        </div>

    </div>


<?php }
else if ($widget_style == 'in-depth') {
    ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;

                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>

                    <h3><?php echo l(mb_strimwidth(ucfirst($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                }
                else if ($count == 1) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                    <ul>
                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>

                            <p><?php echo l(mb_strimwidth(ucfirst($desc), 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>            
                    </ul>
                    <?php
                }
            }
            ?>

        </div>

        <div class="col-md-6">

            <ul>

                <?php
                foreach ($data as $count => $entity) {
                    $desc = $entity->title;

                    if ($count > 1) {
                        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                        }
                        ?>

                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>  

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
                        <?php
                    }
                }
                ?>


            </ul>

        </div>

    </div>


<?php }
else if ($widget_style == 'movies-celebrities') {
    ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6 section-ordering">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;


                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>

                    <h3><?php echo l(mb_strimwidth($desc, 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                }
                else if ($count == 1 || $count == 2) {
                    ?>
                    <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                    <?php
                }
            }
            ?>

        </div>

        <div class="col-md-6">

            <ul>

                <?php
                foreach ($data as $count => $entity) {
                    $desc = $entity->title;

                    if ($count > 2) {
                        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                        }
                        ?>

                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>  

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
                        <?php
                    }
                }
                ?>


            </ul>

        </div>

    </div>


        <?php }
        else if ($widget_style == 'movies-lifestyle') {
            ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6 section-ordering">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;


                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

                    <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>

                    <h3><?php echo l(mb_strimwidth($desc, 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
            <?php
        }
        else if ($count == 1 || $count == 2) {
            ?>

                    <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>

            <?php
        }
    }
    ?>

        </div>

        <div class="col-md-6">

            <ul>

                <?php
                foreach ($data as $count => $entity) {
                    $desc = $entity->title;

                    if ($count > 2) {
                        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                        }
                        ?>

                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>  

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
            <?php
        }
    }
    ?>


            </ul>

        </div>

    </div>


        <?php }
        else if ($widget_style == 'oscar-news') {
            ?>
    <div class="oscar-news">
        <div class="row">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;

                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                    <div class="col-md-12">
                        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <span class="pic  <?php echo $video_class; ?>"><img src="<?php echo $extra_large_image_url; ?>"></span>
                        </a>
                        <h3><?php echo l(mb_strimwidth($desc, 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    </div>
                    <?php
                }
                else if ($count > 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                    <div class="col-md-6 col-sm-6 col-xs-6">                   
                        <span class="pic  <?php echo $video_class; ?>"> <a class="pic  <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                <img src="<?php echo $extra_large_image_url; ?>">
                            </a></span>

                        <p><?php echo l(mb_strimwidth($desc, 0, 60, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>                      
                    </div>
            <?php
        }
    }
    ?>

        </div>



    </div>


    <?php }
    else if ($widget_style == 'oscar-features') {
        ?>
    <div class="row oscar-features">

        <?php
        $coun = 1;
        foreach ($data as $count => $entity) {
            $video_class = "pic-no-icon";
            if (strtolower($entity->type) == 'videogallery') {
                $video_class = 'video-icon';
            }
            $desc = $entity->title;


            if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
            }
            ?>
            <div class="col-md-6">
                <span> <a <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                        <img src="<?php echo $extra_large_image_url; ?>">
                    </a></span>

                <p><?php echo l(mb_strimwidth($desc, 0, 80, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
            </div>
        <?php
        $coun++;
    }
    ?>


    </div>


        <?php }
        else if ($widget_style == 'tech-tips' || $widget_style == 'india-inc-on-budget' || $widget_style == 'budget-reactions' || $widget_style == 'election-other-story' ) {
            ?>

    <div class="tech-trip">
        <ul class="trending-videos">

            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }

                $desc = $entity->title;
                ?>
                <li class="trending-videos-list">
        <?php
        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
        }
        ?>

        <?php if (!empty($extra_large_image_url)) { ?>

                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  src="<?php print $extra_large_image_url ?>" /> </a></span>

        <?php }
        ?>

                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 100, ".."); ?></span></a>
                </li>
    <?php } ?>
        </ul>
    </div>

            <?php }
            else if ($widget_style == 'home-shows') {
            ?>

    <div class="tech-trip home-shows">
        <ul class="trending-videos">

            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }

                $desc = $entity->title;
                ?>
                <li class="trending-videos-list">
        <?php
        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
        }
        ?>

        <?php if (!empty($extra_large_image_url)) { ?>

                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  src="<?php print $extra_large_image_url ?>" /> </a></span>

        <?php }
        ?>

                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 100, ".."); ?></span></a>
                </li>
    <?php } ?>
        </ul>
    </div>

            <?php }
            else if ($widget_style == 'home-watch') {
                ?>

    <div class="tech-trip osscar-video">
        <div class="home-watch-new">
            <ul class="">
                <?php
                foreach ($data as $count => $entity) {
                    $video_class = "pic-no-icon";
                    if (strtolower($entity->type) == 'videogallery') {
                        $video_class = 'video-icon';
                    }

                    $desc = $entity->title;
                    ?>
                    <li class="dont-miss-listing">
        <?php
        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
            $extra_large_image_url = image_style_url("video_landing_page_170_x_127", $entity->field_story_extra_large_image['und'][0]['uri']);
        }
        ?>

        <?php if (!empty($extra_large_image_url)) { ?>

                            <span class="dm-pic"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  src="<?php print $extra_large_image_url ?>" /> </a> <span><i class="fa fa-play-circle"></i> <?php echo $entity->field_video_duration['und'][0]['value']; ?></span></span>

        <?php }
        ?>

                        <span class="dm-detail"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 100, ".."); ?></a></span>
                    </li>
    <?php } ?>
            </ul>
        </div></div>

        <?php }
        else if ($widget_style == 'budget-decoded') {
            ?>

    <div class="tech-trip">
        <ul class="slider-budget">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }

                $desc = $entity->title;
                ?>
                <li>
        <?php
        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
            $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
        }
        ?>

                <?php if (!empty($extra_large_image_url)) { ?>

                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  src="<?php print $extra_large_image_url ?>" /></a>

        <?php }
        ?>

                    <h3><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 65, ".."); ?></a></h3>
                </li>
    <?php } ?>
        </ul>
    </div>        

        <?php }
        else if ($widget_style == 'sport-column') {
            ?>

    <div class="tech-trip">
        <ul class="trending-videos">

                <?php
                foreach ($data as $count => $entity) {
                    $video_class = "pic-no-icon";
                    if (strtolower($entity->type) == 'videogallery') {
                        $video_class = 'video-icon';
                    }

                    $desc = $entity->title;
                    ?>
                <li class="trending-videos-list">
                    <?php
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                    } 
                    ?>

                <?php if (!empty($extra_large_image_url)) { ?>

                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  src="<?php print $extra_large_image_url ?>" /> </a></span>

        <?php } else { ?>
     <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">  <img  height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png"  /> </a></span>

       <?php }
        ?>
                        

                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 100, ".."); ?></span></a>
                </li>
        <?php } ?>
        </ul>
    </div>

    <?php }
    else if ($widget_style == 'election-so-sorry') { ?>

        <?php if (!empty($data)) : global $base_url; ?>
        <div class="section-ordering">
            <?php
            $extra_large_image_url = "";
            foreach ($data as $count => $entity) {
                $video_class = "pic-no-icon";
                if (strtolower($entity->type) == 'videogallery') {
                    $video_class = 'video-icon';
                }
                if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
                }
                ?>
            <?php if ($count == 0) : ?>
                    <?php if (!empty($extra_large_image_url)) { ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  src="<?php print $extra_large_image_url ?>" />
                        </a>
                        <?php
                    }
                    else {
                        ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  height="208" width="370" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                        </a>
                <?php } ?>
                    <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
                <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </h3>
            <?php endif; ?>

        <?php } ?>
        </div>
            <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
            <?php endif; ?>

        <?php }
        else if ($widget_style == 'talking-point') {
            ?>

    <div class="tech-trip">
        <ul class="trending-videos">

                <?php
                foreach ($data as $count => $entity) {
                    $reporter = "";
                    $extra_large_image_url = "";
                    $video_class = "pic-no-icon";
                    if (strtolower($entity->type) == 'videogallery') {
                        $video_class = 'video-icon';
                    }

                    $desc = $entity->title;
                    ?>
                <li class="trending-videos-list">
                    <?php
                    if ((!empty($reporter->field_story_extra_large_image['und'][0]['uri']) && isset($reporter->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $reporter->field_story_extra_large_image['und'][0]['uri']);
                    }
                    if ($entity->field_common_by_line_reporter_id['und'][0]['value'] != "") {
                        $reporter = node_load($entity->field_common_by_line_reporter_id['und'][0]['value']);
                    }

                    if ((!empty($reporter->field_story_extra_large_image['und'][0]['uri']) && isset($reporter->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $reporter->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

                    <?php if (!empty($extra_large_image_url)) { ?>

                        <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"> <img  src="<?php print $extra_large_image_url ?>" /> </a></span>

        <?php }
        else {
            ?>
                        <span class="pic <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">   <img width="88" height="66" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" /></a></span>

        <?php }
        ?>
        <?php
        if ($reporter->title != "") {
            print '<h4>' . ucfirst(mb_strimwidth($reporter->title, 0, 50, "..")) . '</h4>';
        }
        ?>
                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 70, ".."); ?></span></a>
                </li>
        <?php } ?>
        </ul>
    </div>

    <?php }
    else if ($widget_style == 'edu-exam' || $widget_style == 'edu-gov-jobs') {
        ?>

        <?php if (!empty($data)) : global $base_url; ?>
        <div class="section-ordering">
        <?php
        $extra_large_image_url = "";
        foreach ($data as $count => $entity) {
            if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                $extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
            }
            $video_class = "pic-no-icon";
            if (strtolower($entity->type) == 'videogallery') {
                $video_class = 'video-icon';
            }
            ?>
                    <?php if ($count == 0) : ?>
                        <?php if (!empty($extra_large_image_url)) { ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  src="<?php print $extra_large_image_url ?>" />
                        </a>
                            <?php
                        }
                        else {
                            ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img height="208" width="370" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                        </a>
                <?php } ?>
                    <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
                <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </h3>
            <?php endif; ?>
            <?php if ($count != 0) : ?>
                    <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
                    <?php echo l(mb_strimwidth($entity->title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </p>
                <?php endif; ?>
            <?php } ?>
        </div>
    <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
            <?php endif; ?>

    <?php } else if ($widget_style == 'edu-notification' || $widget_style == 'edu-featurefilia' || $widget_style == 'edu-jobs-and-career' || $widget_style == 'edu-sample-paper') { ?>

    <?php if (!empty($data)) : global $base_url; ?>
        <div class="section-ordering">
        <?php
        $extra_large_image_url = "";
        foreach ($data as $count => $entity) {
            ?>


                <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
                <?php echo l(mb_strimwidth($entity->title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                </p>

            <?php } ?>
        </div>
        <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
        <?php endif; ?>

    <?php } else if ($widget_style == 'edu-from-the-magazine') { ?>

        <?php if (!empty($data)) : global $base_url; ?>
        <div class="from-the-magazine">

            <?php
            $extra_large_image_url = "";
            foreach ($data as $count => $entity) {
                $desc = "";

                if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("magazine_rhs_100x140", $entity->field_story_extra_large_image['und'][0]['uri']);
                    if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                    }
                    if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                    }
                    $video_class = "pic-no-icon";
                    if (strtolower($entity->type) == 'videogallery') {
                        $video_class = 'video-icon';
                    }
                }
                ?>
                    <?php if ($count == 0) : ?>
                    <div class="magazine-detail">

                                <?php if (!empty($extra_large_image_url)) { ?>
                            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                <img  src="<?php print $extra_large_image_url ?>" />
                            </a>
                    <?php
                }
                else {
                    ?>
                            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                <img class="defalt-placeholder-magazin"  height="140" width="100" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                            </a>
                    <?php } ?>
                        <div class="small-detail">
                            <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
                    <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                            </h3>
                            <p><?php echo mb_strimwidth($desc, 0, 55, ".."); ?> </p>



                        </div>
                    </div>

            <?php endif; ?>
            <?php if ($count != 0) : ?>
                    <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
                    <?php echo l(mb_strimwidth($entity->title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </p>
                <?php endif; ?>
            <?php } ?>
        </div>
        <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
        <?php endif; ?>

    <?php } else {
        ?>
        <?php if (!empty($data)) : global $base_url; ?>
        <div class="section-ordering">
        <?php
        $extra_large_image_url = "";
        foreach ($data as $count => $entity) {
            $video_class = "pic-no-icon";
            if (strtolower($entity->type) == 'videogallery') {
                $video_class = 'video-icon';
            }
            if ($count == 0 && (!empty($entity->field_story_medium_image['und'][0]['uri']) && isset($entity->field_story_medium_image['und'][0]['uri']))) {
                //$extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
            $extra_large_image_url = file_create_url($entity->field_story_medium_image['und'][0]['uri']);
                
            }
            ?>
                    <?php if ($count == 0) : ?>
                        <?php if (!empty($extra_large_image_url)) { ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  src="<?php print $extra_large_image_url ?>" />
                        </a>
                            <?php
                        }
                        else {
                            ?>
                        <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  height="208" width="370" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
                        </a>
                <?php } ?>
                    <h3 class="frist-heading heading-<?php echo $entity->nid ?> <?php echo $entity->type ?> ">
                <?php echo l(mb_strimwidth($entity->title, 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </h3>
            <?php endif; ?>
            <?php if ($count != 0) : ?>
                    <p class="<?php print $entity->type ?> section-order-<?php print $entity->nid ?>">
                <?php echo l(mb_strimwidth($entity->title, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?>
                    </p>
            <?php endif; ?>
        <?php } ?>
        </div>
    <?php else : ?>
        <span class="no-result-found"><?php print t("Content Not Found") ?></span>
    <?php endif; ?>
<?php } ?>






