<div class="row">
    <div class="col-md-8">
        <div class="auto-block-1">
            <div class="featured-news">
                <?php
                global $base_url;
                foreach ($data as $index => $row) {
                  $desc = $row['title'];
                  if (function_exists('itg_common_remove_extra_html')) {
                    $desc = itg_common_remove_extra_html($desc);
                  }
                  $video_class = "";
                  if (strtolower($row['type']) == 'videogallery') {
                    $video_class = 'video-icon';
                  }
                  if ($index == 0) {
                    ?>
                    <div class="featured-post featured-post-first">
                        <?php if ($row['uri'] != "") { ?>
                          <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>">
                              <img src="<?php print image_style_url("magazine_top_story_483x271", $row['uri']); ?>" alt="<?php echo $row['field_story_extra_large_image_alt']; ?>" title="<?php echo $row['field_story_extra_large_image_title']; ?>" />
                          </a>
                        <?php
                        }
                        else {
                          print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image483x271.jpg' />";
                        }
                        ?> 

                        <h2 title="<?php echo strip_tags($desc); ?>">
                            <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($row['node_obj'], 0, 68), "node/" . $row['nid'], array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), "node/" . $row['nid']);
                            }
                            ?>
                        </h2>           
                    </div>
                      <?php }
                      else if ($index > 0 && $index <= 2) { ?>
                    <div class="featured-post">
                    <?php if ($row['mi_file_uri'] != "") { ?>
                          <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>">
                              <img src="<?php print image_style_url("home_page_feature_small", $row['mi_file_uri']); ?>" alt="<?php echo $row['field_story_medium_image_alt']; ?>" title="<?php echo $row['field_story_medium_image_title']; ?>" />
                          </a>
                        <?php
                        }
                        else {
                          print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image237x133.jpg' />";
                        }
                        ?>
                        <h3 title="<?php echo strip_tags($desc); ?>">
                            <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($row['node_obj'], 0, 80), "node/" . $row['nid'], array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), "node/" . $row['nid']);
                            }
                            ?>
                        </h3>
                    </div>

                  <?php } ?>

                <?php } ?>
            </div>
        </div>    
    </div>
    <div class="col-md-4">
        <div class="auto-block-2">
            <div class="special-top-news">
                <div class="itg-listing-wrapper">
                    <ul class="itg-listing">   
                        <?php
                        foreach ($data as $index => $row) {
                          $desc = $row['title'];
                          if ($index > 2) {
                            ?>
                            <li title="<?php echo strip_tags($desc); ?>">
                            <?php if ($entity['is_spnoser']): ?>
                              <span class="itg-sponsor-section-title"><?php print t('IMPACT FEATURE'); ?></span>
                            <?php endif; ?>
                                <?php
                                if (function_exists('itg_common_get_smiley_title')) {
                                  echo l(itg_common_get_smiley_title($row['node_obj'], 0, 80), "node/" . $row['nid'], array("html" => TRUE));
                                }
                                else {
                                  echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), "node/" . $row['nid']);
                                }
                                ?>
                            </li>
                          <?php } ?>

                       <?php } ?>

                    </ul>
                </div>
            </div>
        </div>
    </div>
</div>
