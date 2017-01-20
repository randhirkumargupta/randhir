<div class="techwatch osscar-video">
    <ul class="">  
        <?php
       
        foreach ($rows as $index => $row) {
            $desc = $row['title'];
             $video_class = '';
            if (strtolower($row['type']) == 'videogallery') {
                $video_class = 'video-icon';
            }
            ?>
            <li class="dont-miss-listing">
                <div class="dm-pic"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}");?>" class="pic <?php echo $video_class;?>">
                    <?php
                                if ($row['field_story_extra_small_image'] != "") {
                                    print $row['field_story_extra_small_image'];
                                }
                                else {
                                    print "<img width='88' height='66' src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image88x66.jpg' alt='' />";
                                }
                                ?>   
                  
                    
                    </a></div>

                <div class="dm-detail"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")); ?></div>       
            </li>


<?php } ?>
    </ul>
</div>