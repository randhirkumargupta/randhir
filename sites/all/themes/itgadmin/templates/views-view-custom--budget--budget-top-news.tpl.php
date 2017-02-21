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
                                    print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/ditg_image370x208.jpg' />";
                                }
                                ?>    


                            </a>
                            <h3><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h3>           
                        </div>

                    <?php
                    }
                    else if ($index > 0 && $index <= 2) {
                        ?>
                        <div class="featured-post"> <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>">
                                <?php
                                if ($row['field_story_small_image'] != "") {
                                    print $row['field_story_small_image'];
                                }
                                else {
                                    print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' />";
                                }
                                ?>   
       </a>
                            <p><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></p>
                        </div>

                    <?php } ?>

<?php } ?>
            </div>
        </div>    
    </div>
    <div class="col-md-6">
        <h4 class="heading desktop-hide">OTHER NEWS</h4>
        <div class="auto-block-2">
            <div class="special-top-news special-top-bg">

                <ul class="itg-listing">   
                    <?php
                    foreach ($rows as $index => $row) {

                        $desc = $row['title'];

                        if ($index > 2) {
                            ?>
                            <li><?php echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></li>


                        <?php } ?>

<?php } ?>

                </ul>

            </div>
        </div>
    </div>
</div>