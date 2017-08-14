<div class="latest">
    <div class="row">
        <?php
        global $base_url;
        foreach ($rows as $index => $row) {
            $desc = $row['title'];

            $video_class = "";
            if (strtolower($row['type']) == 'videogallery') {
                $video_class = 'video-icon';
            }
            ?>
            <div class="col-md-3 col-sm-3 col-xs-6">
                <a class="<?php echo $video_class; ?>" href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>">
                    <?php
                    if ($row['field_story_small_image'] != "") {
                        print $row['field_story_small_image'];
                    }
                    else {
                        print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />";
                    }
                    ?>   </a>
                <p title="<?php echo html_entity_decode(strip_tags($desc));?>>
                  <?php //echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>
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


    </div>
</div>