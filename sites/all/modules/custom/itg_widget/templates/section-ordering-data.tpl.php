<?php global $base_url;
if ($widget_style == 'auto-road-trip') {
    ?>
    <div class="auto-road-trip">
        <ul class="trending-videos">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }

                $desc = $entity->title;

                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }
                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }
                // p($entity);
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
<?php } else if ($widget_style == 'auto-tips-and-tricks') { ?>
    <div class="auto-tips-n-tricks">
        <ul>
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }


                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }
                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }
                // p($entity);
                ?><li>
                    <p class="title"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo ucfirst($entity->title); ?></a></p>

                    <p><?php echo mb_strimwidth(strip_tags($desc), 0, 55, ".."); ?></p>
                </li>


    <?php }; ?>
        </ul>
    </div>


<?php } else if ($widget_style == 'buying-guid') { ?>
    <div class="row buying-guides">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }
                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }
                if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                }


                if ($count == 0) {
                    ?>
                    
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>">  </a>
                  
                    <h3><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                <?php } else if ($count == 1) {
                    ?>
                    <ul>
                        <li>
                            <span class="title"><?php echo l(mb_strimwidth(ucfirst($entity->title), 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></span>
                            <p><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
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
                    if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                    }
                    if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                    }
                    if ($count > 1) {
                        ?>

                        <li>
                            <span class="title"><?php echo l(mb_strimwidth(ucfirst($entity->title), 0, 55, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></span>
                            <p><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
                        <?php
                    }
                }
                ?>


            </ul>

        </div>

    </div>


<?php } else if ($widget_style == 'in-depth') { ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }




                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                   
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>
                   
                    <h3><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                } else if ($count == 1) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                    <ul>
                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>

                            <p><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
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
                    if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                    }
                    if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                    }
                    if ($count > 1) {
                        if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                            $extra_large_image_url = image_style_url("widget_very_small", $entity->field_story_extra_large_image['und'][0]['uri']);
                        }
                        ?>

                        <li>
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>  
                            
                            <p><?php echo l(mb_strimwidth($desc, 0, 145, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                        </li>   
                        <?php
                    }
                }
                ?>


            </ul>

        </div>

    </div>


<?php }else if ($widget_style == 'movies-celebrities') { ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }




                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                   
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>
                   
                    <h3><?php echo l(mb_strimwidth($desc, 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                } else if ($count == 1 || $count == 2) {
                   
                    ?>
                    <ul>
                        <li>
                            

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
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
                    if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                    }
                    if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                    }
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


<?php }else if ($widget_style == 'movies-lifestyle') { ?>
    <div class="row buying-guides tech-in-depth">
        <div class="col-md-6">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-icon';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }




                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                   
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><img src="<?php echo $extra_large_image_url; ?>"> </a></span>
                   
                    <h3><?php echo l(mb_strimwidth($desc, 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
                    <?php
                } else if ($count == 1 || $count == 2) {
                   
                    ?>
                    <ul>
                        <li>
                           

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
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
                    if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                    }
                    if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                        $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                    }
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


<?php } else if ($widget_style == 'oscar-news') { ?>
    <div class="oscar-news">
        <div class="row">
            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }




                if ($count == 0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("anchors_landing", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
            <div class="col-md-12">
                    <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                        <span class="pic  <?php echo $video_class; ?>"><img src="<?php echo $extra_large_image_url; ?>"></span>
                    </a>
                    <h3><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></h3>
            </div>
                    <?php
                } else if ($count >0) {
                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("video_landing_page_170_x_127", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
            <div class="col-md-6">                   
                <span class="pic  <?php echo $video_class; ?>"> <a class="pic  <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                        <img src="<?php echo $extra_large_image_url; ?>">
                    </a></span>

                <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>                      
            </div>
                    <?php
                }
            }
            ?>

        </div>

        

    </div>


<?php } else if ($widget_style == 'oscar-features') { ?>
    <div class="row oscar-features">
        
            <?php
            $coun=1;
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }
                $desc = $entity->title;
                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }

                    if ((!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("video_landing_page_170_x_127", $entity->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>
                    <div class="col-md-6">
                            <span> <a <?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                                    <img src="<?php echo $extra_large_image_url; ?>">
                                </a></span>

                            <p><?php echo l(mb_strimwidth($desc, 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/$entity->nid")); ?></p>
                      </div>
                    <?php
               $coun++;
            }
            ?>
     

    </div>


<?php } else if ($widget_style == 'tech-tips') { ?>

    <div class="tech-trip">
        <ul class="trending-videos">

            <?php
            foreach ($data as $count => $entity) {
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }

                $desc = $entity->title;

                if ($entity->field_gallery_kicer['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_gallery_kicer['und'][0]['value']);
                }
                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }
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

<?php } else if ($widget_style == 'talking-point') { ?>

    <div class="tech-trip">
        <ul class="trending-videos">

            <?php
            foreach ($data as $count => $entity) {
                $reporter = "";
                $extra_large_image_url = "";
                $video_class = "";
                if (strtolower($entity->type) != 'videogallery') {
                    $video_class = 'video-none';
                }

                $desc = $entity->title;

                if ($entity->field_story_kicker_text['und'][0]['value'] != "") {
                    $desc = strip_tags($entity->field_story_kicker_text['und'][0]['value']);
                }
                if ($entity->field_common_by_line_reporter_id['und'][0]['value'] != "") {
                    $reporter = node_load($entity->field_common_by_line_reporter_id['und'][0]['value']);
                }
                ?>
                <li class="trending-videos-list">
                    <?php
                    if ((!empty($reporter->field_story_extra_large_image['und'][0]['uri']) && isset($reporter->field_story_extra_large_image['und'][0]['uri']))) {
                        $extra_large_image_url = image_style_url("widget_very_small", $reporter->field_story_extra_large_image['und'][0]['uri']);
                    }
                    ?>

        <?php if (!empty($extra_large_image_url)) { ?>
                        
                            <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"> <img  src="<?php print $extra_large_image_url ?>" /> </a></span>
                       
        <?php } else { ?>
                      <span class="pic  <?php echo $video_class; ?>"> <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">   <img width="88" height="66" src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" /></a></span>

                    <?php }
                    ?>
                    <?php
                    if ($reporter->title != "") {
                        print '<h3>' . ucfirst($reporter->title) . '</h3>';
                    }
                    ?>
                    <span><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>"><?php echo mb_strimwidth(strip_tags($desc), 0, 100, ".."); ?></span></a>
                </li>
    <?php } ?>
        </ul>
    </div>

<?php } else {
    ?>

        <?php if (!empty($data)) : global $base_url; ?>
        <div class="section-ordering">
            <?php
            $extra_large_image_url = "";
            foreach ($data as $count => $entity) {
                if ($count == 0 && (!empty($entity->field_story_extra_large_image['und'][0]['uri']) && isset($entity->field_story_extra_large_image['und'][0]['uri']))) {
                    $extra_large_image_url = image_style_url("section_ordering_widget", $entity->field_story_extra_large_image['und'][0]['uri']);
                }
                ?>
            <?php if ($count == 0) : ?>
                    <?php if (!empty($extra_large_image_url)) { ?>
                        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  src="<?php print $extra_large_image_url ?>" />
                        </a>
                    <?php
                } else {
                    ?>
                        <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/$entity->nid"); ?>">
                            <img  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
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






