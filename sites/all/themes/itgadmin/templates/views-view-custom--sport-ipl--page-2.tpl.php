<div class="page-sports-video">
    <div class="view-content">
        <ul class="photo-list">  
            <?php
            foreach ($rows as $index => $row) {
                $desc = $row['title'];
                 if (!empty($row['field_story_small_image'])) {
                $img = $row['field_story_small_image'];
            }
            else {
                global $base_url;
                $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' />";
            }
                ?>
                <li class="col-md-3">
                    <div class="tile">
                        <figure><?php print $img; ?>
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