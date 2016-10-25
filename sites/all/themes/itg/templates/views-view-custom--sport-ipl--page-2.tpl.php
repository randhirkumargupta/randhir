<div class="page-sports-video">
    <div class="view-content">
        <ul class="photo-list">  
            <?php
            foreach ($rows as $index => $row) {
                $desc = $row['title'];
                ?>
                <li class="col-md-3">
                    <div class="tile">
                        <figure><?php print $row['field_story_extra_large_image']; ?>
                            <figcaption><i class="fa fa-play-circle"></i> <?php echo $row['field_video_duration']; ?></figcaption>
                        </figure>
                        <span class="posted-on"><?php echo $row['created']; ?></span>
                        <?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>
                    </div>           
                </li>
            <?php }; ?>
        </ul>
    </div>
</div>