<div class="row">    
    <?php
    foreach ($rows as $index => $row) {
        $desc = $row['title'];
        $video_class = "";
        if (strtolower($row['type']) == 'videogallery') {
            $video_class = 'video-icon';
        }
        ?>
        <div class="col-md-3">
            <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>"><?php print $row['field_story_extra_large_image']; ?>    </a>
            <p><?php echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></p>            
        </div>         
    <?php } ?>    
</div>
