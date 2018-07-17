<div class="row">
    <div class="col-md-6">
        <div class="auto-block-1">
            <div class="featured-news">

                <?php
                    global $base_url;
                foreach ($rows as $index => $row) {
                    $desc = $row['title'];

                    $video_class = "";
                    if (strtolower($row['type']) == 'videogallery') {
                        $video_class = 'video-icon';
                    }
                    if ($index == 0) {
                        ?>
                        <div class="featured-post featured-post-first">
                            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>">

                                <?php
                                if ($row['field_story_medium_image'] != "") {
                                    print $row['field_story_medium_image'];
                                }
                                else {
                                    print "<img  src='" .  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg') ."' alt='' title=''/>";
                                }
                                ?>    


                            </a>
                            <h3 title="<?php echo strip_tags($desc);?>">
                              
                            <?php
                              if (function_exists('itg_common_get_smiley_title')) {
                                echo l(itg_common_get_smiley_title($row['nid'], 0, 60), "node/" . $row['nid'], array("html" => TRUE));
                              }
                              else {
                                echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 70, ".."), "node/" . $row['nid']);
                              }
                            ?>
                            </h3>           
                        </div>

    <?php }
    else if ($index > 0 && $index <= 2) {
        ?>
                        <div class="featured-post"> <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>">
                             <?php
                                if ($row['field_story_small_image'] != "") {
                                    print $row['field_story_small_image'];
                                }
                                else {
                                    print "<img  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
                                }
                                ?>   
                          </a>
                            <p title="<?php echo strip_tags($desc);?>">
                              <?php // echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>
                              <?php
                              if (function_exists('itg_common_get_smiley_title')) {
                                echo l(itg_common_get_smiley_title($row['nid'], 0, 60), "node/" . $row['nid'], array("html" => TRUE));
                              }
                              else {
                                echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 70, ".."), "node/" . $row['nid']);
                              }
                              ?>
                            </p>
                        </div>

    <?php } ?>

<?php } ?>
            </div>
        </div>    
    </div>
    <div class="col-md-6 other-news">
        <h4 class="heading desktop-hide"><?php print t('OTHER NEWS'); ?></h4>
        <div class="auto-block-2">
            <div class="special-top-news special-top-bg">
              <div class="itg-listing-wrapper">
                <ul class="itg-listing">   
                    <?php
                    foreach ($rows as $index => $row) {

                        $desc = $row['title'];

                        if ($index > 2) {
                            ?>
                            <li title="<?php echo strip_tags($desc);?>">
                              
                            <?php
                              if (function_exists('itg_common_get_smiley_title')) {
                                echo l(itg_common_get_smiley_title($row['nid'], 0, 75), "node/" . $row['nid'], array("html" => TRUE));
                              }
                              else {
                                echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 85, ".."), "node/" . $row['nid']);
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