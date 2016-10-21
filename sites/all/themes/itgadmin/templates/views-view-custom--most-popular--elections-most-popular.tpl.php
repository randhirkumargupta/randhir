<div class="row">
    <div class="col-md-3">
        <div class="auto-block-1">
            <div class="featured-news">

                <?php
                foreach ($rows as $index => $row) {
                    $desc = $row['title'];

                    $video_class = "";
                    if (strtolower($row['type']) == 'videogallery') {
                        $video_class = 'video-icon';
                    }
                   
                        ?>
                        <div class="featured-post featured-post-first">
                            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>"><?php print $row['field_story_extra_large_image']; ?>    </a>
                            <h2><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h2>           
                        </div>

                    
<?php } ?>
            </div>
        </div>    
    </div>
</div>
    