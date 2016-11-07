<div class="page-sports-video">
    <div class="view-content">
        <ul class="photo-list row">
            <?php
            foreach ($rows as $index => $row) {
                $desc = $row['title'];
                ?>
                <li class="col-md-3">
                    <span class="tile">
                        <figure>
                            <?php print $row['field_story_extra_large_image']; ?> <figcaption><i class="fa fa-play-circle"></i><?php echo $row['field_video_duration']; ?></figcaption>
                        </figure>            
                <?php echo l(mb_strimwidth(strip_tags($desc), 0, 60, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>   </span>
                </li>
<?php }; ?>
        </ul>
    </div>
</div>